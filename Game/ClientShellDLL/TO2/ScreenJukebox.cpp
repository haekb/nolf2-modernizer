
#include "Stdafx.h"
#include "ClientRes.h"
#include "GameClientShell.h"



#include "ScreenJukebox.h"




#include "ScreenCommands.h"
#include "JukeboxButeMgr.h"


namespace
{
	int kGap = 0;
	int kWidth = 0;
	LTRect rcSongListRect;
	int nListHeight = 0;
	int nListWidth = 0;
	int nArrowWidth = 0;
	int nIndent = 0;

	// CMD_CUSTOM ... CMD_CUSTOM + 500
	// are dedicated for themes

	// Just bump this up to not conflict with the attribute file
	const int PLAY_SONG = CMD_CUSTOM + 500;
}


CScreenJukebox::CScreenJukebox()
{
	m_sCurrentSong = "";

	m_CurrentSongList = nullptr;
	m_PreviousMusicState.Clear();

	m_hSoundHandle = nullptr;

	m_nWidth = 0;
}

CScreenJukebox::~CScreenJukebox()
{
	// Clean up!
	for (auto Song : m_Songs)
	{
		Song.clear();
	}

	m_Songs.clear();
	m_PreviousMusicState.Clear();
}


LTBOOL CScreenJukebox::Build()
{
	CreateTitle(IDS_TITLE_JUKEBOX);

	rcSongListRect = g_pLayoutMgr->GetScreenCustomRect((eScreenID)m_nScreenID, "SongListRect");
	nArrowWidth = g_pLayoutMgr->GetScreenCustomInt((eScreenID)m_nScreenID, "ArrowWidth");
	nIndent = g_pLayoutMgr->GetScreenCustomInt((eScreenID)m_nScreenID, "TextIndent");

	if (g_pLayoutMgr->HasCustomValue(SCREEN_ID_JUKEBOX, "ColumnWidth"))
		kGap = g_pLayoutMgr->GetScreenCustomInt(SCREEN_ID_JUKEBOX, "ColumnWidth");
	if (g_pLayoutMgr->HasCustomValue(SCREEN_ID_JUKEBOX, "SliderWidth"))
		kWidth = g_pLayoutMgr->GetScreenCustomInt(SCREEN_ID_JUKEBOX, "SliderWidth");

	LTFLOAT yr = g_pInterfaceResMgr->GetYRatio();
	kGap *= yr;

	auto pSingleText = AddTextItem(IDS_JUKEBOX_THEMES, 0, 0);
	pSingleText->SetFont(g_pInterfaceResMgr->GetFont(0), 24);

	int nThemeCount = g_pJukeboxButeMgr->GetNumThemes();

	for (int i = 0; i < nThemeCount; i++)
	{
		char szName[128] = "";
		g_pJukeboxButeMgr->GetThemeName(i, szName, 64);

		AddTextItem(szName, CMD_CUSTOM + i, 0);// 0, GetMediumFont());

		// Let's start off a map, 
		// because everything here is pretty static we can safely assume the position in the vector relates to the theme id.
		// Sorry for anyone who has to change this...(But also like why?)
		std::map<std::string, JukeboxData> SongMap;
		m_Songs.push_back(SongMap);
	}

	int nSongCount = g_pJukeboxButeMgr->GetNumSongs();

	for (int i = 0; i < nSongCount; i++)
	{
		char szName[128] = "";
		g_pJukeboxButeMgr->GetSongName(i, szName, 64);
		auto nIntensityLevel = g_pJukeboxButeMgr->GetSongIntensityLevel(i);
		auto nThemeID = g_pJukeboxButeMgr->GetSongThemeID(i);
		bool bIsMP3 = g_pJukeboxButeMgr->GetThemeIsMp3(nThemeID);

		// If the ID is in the "to skip" list, then skip this song!
		// This is needed if the player doesn't have the required files installed.
		if (std::find(m_ThemeIDsToSkip.begin(), m_ThemeIDsToSkip.end(), nThemeID) != m_ThemeIDsToSkip.end())
		{
			continue;
		}

		JukeboxData data;
		data.nIndex = i;
		data.nIntensity = nIntensityLevel;
		data.bIsMP3 = bIsMP3;

		// Insert the song into its proper theme map.
		m_Songs[nThemeID].insert(std::pair<std::string, JukeboxData>(szName, data));
	}

	// Create our beautiful frame
	LTIntPt pos;
	char szFrame[128];
	g_pLayoutMgr->GetScreenCustomString(SCREEN_ID_SINGLE, "FrameTexture", szFrame, sizeof(szFrame));
	HTEXTURE hFrame = g_pInterfaceResMgr->GetTexture(szFrame);

	auto rect = g_pLayoutMgr->GetScreenCustomRect((eScreenID)m_nScreenID, "SongListRect");
	auto nHeight = (rect.bottom - rect.top);
	auto nWidth = (rect.right - rect.left);
	pos = LTIntPt(rect.left, rect.top);

	m_pSongFrame = debug_new(CLTGUIFrame);
	m_pSongFrame->Create(hFrame, nWidth, nHeight, LTTRUE);
	m_pSongFrame->SetBasePos(pos);
	m_pSongFrame->ApplyPosition(g_pInterfaceResMgr->GetYRatio(), g_pInterfaceResMgr->Get4x3Offset());
	m_pSongFrame->Show(LTFALSE);
	AddControl(m_pSongFrame);

	nWidth -= 16;

	// This is used for our text items in the list.
	m_nWidth = nWidth;

	// Okay create the actual list.
	m_pSongListCtrl = CreateList(pos, nHeight, LTTRUE);
	m_pSongListCtrl->SetIndent(LTIntPt(8, 8));
	m_pSongListCtrl->SetFrameWidth(2);
	m_pSongListCtrl->Show(LTFALSE);
	AddControl(m_pSongListCtrl);

	// Make sure to call the base class
	if (!CBaseScreen::Build()) return LTFALSE;

	UseBack(LTTRUE, LTTRUE);

	return LTTRUE;
}

uint32 CScreenJukebox::OnCommand(uint32 dwCommand, uint32 dwParam1, uint32 dwParam2)
{
	if (dwCommand >= CMD_CUSTOM && dwCommand < (CMD_CUSTOM + m_Songs.size()))
	{
		return PlayScore(dwCommand);
	}
	else if (dwCommand == PLAY_SONG)
	{
		UpdateData(LTTRUE);
		
		auto pCtrl = (CLTGUITextCtrl*)m_pSongListCtrl->GetSelectedControl();
		std::string key = pCtrl->GetString()->GetText();

		m_sCurrentSong = key;

		const auto& data = (*m_CurrentSongList).at(key);

		if (m_hSoundHandle)
		{
			g_pLTClient->SoundMgr()->KillSound(m_hSoundHandle);
			m_hSoundHandle = nullptr;
		}

		if (data.bIsMP3)
		{
			PlayMp3(data.nIndex);
		}
		else
		{
			g_pGameClientShell->GetMusic()->Play(data.nIntensity);
		}

		UpdateHelpText();

		return 1;
	}

	return CBaseScreen::OnCommand(dwCommand, dwParam1, dwParam2);
};

void CScreenJukebox::OnFocus(LTBOOL bFocus)
{
	// Enter
	if (bFocus) {
		UpdateData(LTFALSE);

		m_sCurrentSong = "";

		// Store the current music state, so we can restore when they leave!
		m_PreviousMusicState = *g_pGameClientShell->GetMusic()->GetMusicState();

		// Clear the list, in case they're coming in for the second time.
		m_pSongListCtrl->RemoveAll();

		CBaseScreen::OnFocus(bFocus);
		return;
	}

	// Leave
	UpdateData(LTTRUE);

	// Restore the music that was playing before they entered this menu.
	g_pGameClientShell->GetMusic()->RestoreMusicState(m_PreviousMusicState);
	// Restore the intensity!
	g_pGameClientShell->GetMusic()->ChangeIntensity(m_PreviousMusicState.nIntensity);

	// Hide the controls
	m_pSongFrame->Show(LTFALSE);
	m_pSongListCtrl->Show(LTFALSE);

	CBaseScreen::OnFocus(bFocus);
}

LTBOOL CScreenJukebox::PlayScore(int scoreId)
{
	// NOLF2 likes to crash a lot with its DirectMusic implementation, 
	// so let's make sure we're stopped before it unloads the "level" and loads our new "level" theme.
	g_pGameClientShell->GetMusic()->Stop();

	if (m_hSoundHandle)
	{
		g_pLTClient->SoundMgr()->KillSound(m_hSoundHandle);
		m_hSoundHandle = nullptr;
	}

	// excuse my mixed naming convetion here...
	std::string directory = "Music\\";
	std::string controlFile;

	int nThemeID = scoreId - CMD_CUSTOM;

	// Make doubly sure we're not trying to access a theme we don't have the files for!
	if (std::find(m_ThemeIDsToSkip.begin(), m_ThemeIDsToSkip.end(), nThemeID) != m_ThemeIDsToSkip.end())
	{
		return LTFALSE;
	}

	if (!g_pJukeboxButeMgr->GetThemeIsMp3(nThemeID))
	{
		char szDirectory[256] = "";
		char szControlFile[64] = "";
		g_pJukeboxButeMgr->GetThemeDirectory(nThemeID, szDirectory, 256);
		g_pJukeboxButeMgr->GetThemeControlFile(nThemeID, szControlFile, 64);

		directory += szDirectory;
		controlFile = szControlFile;

		CMusicState MusicState;
		strcpy(MusicState.szDirectory, (char*)(LPCSTR)directory.c_str());
		strcpy(MusicState.szControlFile, (char*)(LPCSTR)controlFile.c_str());

		if (!g_pGameClientShell->GetMusic()->RestoreMusicState(MusicState))
		{
			return LTFALSE;
		}
	}

	m_CurrentSongList = &m_Songs[nThemeID];

	UpdateData(LTTRUE);

	// Update the song list based on the newly selected theme!
	m_pSongListCtrl->RemoveAll();
	std::map<std::string, JukeboxData>::iterator it = (*m_CurrentSongList).begin();
	while (it != (*m_CurrentSongList).end()) {

		// Add the string to the control
		HSTRING hTemp = g_pLTClient->CreateString((char*)it->first.c_str());

		CLTGUITextCtrl* pCtrl = CreateTextItem((char*)(LPCTSTR)(it->first.c_str()), PLAY_SONG, 0);
		pCtrl->SetFixedWidth(m_nWidth);

		m_pSongListCtrl->AddControl(pCtrl);

		// Free the strings
		g_pLTClient->FreeString(hTemp);
		it++;
	}

	// Display the frame and list controls.
	m_pSongFrame->Show(LTTRUE);
	m_pSongListCtrl->Show(LTTRUE);

	return LTTRUE;
}

LTBOOL CScreenJukebox::PlayMp3(int scoreId)
{
	char szSongPath[256] = "";
	g_pJukeboxButeMgr->GetSongPath(scoreId, szSongPath, 256);

	m_hSoundHandle = g_pClientSoundMgr->PlaySoundLocal(szSongPath, SOUNDPRIORITYMOD_HIGH, PLAYSOUND_LOOP);

	return LTTRUE;
}

void CScreenJukebox::UpdateHelpText()
{
	// Force Help Text to render!
	m_dwCurrHelpID = 1;

	// Build out string
	HSTRING hHelpTxt = g_pLTClient->FormatString(IDS_JUKEBOX_NOW_PLAYING, m_sCurrentSong.c_str());
	auto szNowPlaying = g_pLTClient->GetStringData(hHelpTxt);
	s_pHelpStr->SetText(szNowPlaying);
	g_pLTClient->FreeString(hHelpTxt);
}
