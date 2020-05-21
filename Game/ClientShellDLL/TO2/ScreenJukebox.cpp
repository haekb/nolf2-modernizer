
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

	// FOLDER_CMD_CUSTOM ... FOLDER_CMD_CUSTOM + 500
	// are dedicated for themes

	// Just bump this up to not conflict with the attribute file
	const int PLAY_SONG = CMD_CUSTOM + 500;// (FOLDER_CMD_CUSTOM + 500);
}


CScreenJukebox::CScreenJukebox()
{
	m_sCurrentSong = "";

	m_CurrentSongList = nullptr;
	m_PreviousMusicState.Clear();
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

	AddTextItem(IDS_JUKEBOX_THEMES, 0, 0);

	int nThemeCount = g_pJukeboxButeMgr->GetNumThemes();

	for (int i = 0; i < nThemeCount; i++)
	{
		char szName[64] = "";
		g_pJukeboxButeMgr->GetThemeName(i, szName, 64);

		AddTextItem(szName, CMD_CUSTOM + i, 0);// 0, GetMediumFont());

		// Let's start off a map, 
		// because everything here is pretty static we can safely assume the position in the vector relates to the theme id.
		// Sorry for anyone who has to change this...(But also like why?)
		std::map<std::string, int> SongMap;
		m_Songs.push_back(SongMap);
	}

	int nSongCount = g_pJukeboxButeMgr->GetNumSongs();

	for (int i = 0; i < nSongCount; i++)
	{
		char szName[64] = "";
		g_pJukeboxButeMgr->GetSongName(i, szName, 64);
		auto nIntensityLevel = g_pJukeboxButeMgr->GetSongIntensityLevel(i);
		auto nThemeID = g_pJukeboxButeMgr->GetSongThemeID(i);

		// If the ID is in the "to skip" list, then skip this song!
		// This is needed if the player doesn't have the required files installed.
		if (std::find(m_ThemeIDsToSkip.begin(), m_ThemeIDsToSkip.end(), nThemeID) != m_ThemeIDsToSkip.end())
		{
			continue;
		}

		// Insert the song into its proper theme map.
		m_Songs[nThemeID].insert(std::pair<std::string, int>(szName, nIntensityLevel));
	}

	LTIntPt pos;
	int nBarHeight = g_pLayoutMgr->GetScreenFontSize(SCREEN_ID_JUKEBOX);//GetMediumFont()->GetHeight();

	//Add PlayerList Here
	pos.x = rcSongListRect.left + nIndent;
	pos.y = rcSongListRect.top + nBarHeight;
	nListHeight = (rcSongListRect.bottom - rcSongListRect.top) - nBarHeight;
	nListHeight += 24;	// [blg] tweak
	nListWidth = (rcSongListRect.right - rcSongListRect.left) - nArrowWidth;

	int nListHeight = 400;
	int nListWidth = 200;

	m_SongListCtrl = CreateList(pos, nListHeight, LTTRUE);
	AddControl(m_SongListCtrl);

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

		auto pCtrl = (CLTGUITextCtrl*)m_SongListCtrl->GetSelectedControl();
		std::string key = pCtrl->GetString()->GetText();

		m_sCurrentSong = key;

		int intensity = (*m_CurrentSongList).at(key);
		g_pGameClientShell->GetMusic()->Play(intensity);

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
		m_SongListCtrl->RemoveAll();

		CBaseScreen::OnFocus(bFocus);
		return;
	}

	// Leave
	UpdateData(LTTRUE);

	// Restore the music that was playing before they entered this menu.
	g_pGameClientShell->GetMusic()->RestoreMusicState(m_PreviousMusicState);
	// Restore the intensity!
	g_pGameClientShell->GetMusic()->ChangeIntensity(m_PreviousMusicState.nIntensity);


	CBaseScreen::OnFocus(bFocus);
}

LTBOOL CScreenJukebox::PlayScore(int scoreId)
{
	g_pGameClientShell->GetMusic()->Stop();

	// excuse my mixed naming convetion here...
	std::string directory = "Music\\";
	std::string controlFile;

	int nThemeID = scoreId - CMD_CUSTOM;

	// Make doubly sure we're not trying to access a theme we don't have the files for!
	if (std::find(m_ThemeIDsToSkip.begin(), m_ThemeIDsToSkip.end(), nThemeID) != m_ThemeIDsToSkip.end())
	{
		return LTFALSE;
	}

	char szDirectory[256] = "";
	char szControlFile[64] = "";
	g_pJukeboxButeMgr->GetThemeDirectory(nThemeID, szDirectory, 256);
	g_pJukeboxButeMgr->GetThemeControlFile(nThemeID, szControlFile, 64);

	m_CurrentSongList = &m_Songs[nThemeID];
	directory += szDirectory;
	controlFile = szControlFile;

	CMusicState MusicState;
	strcpy(MusicState.szDirectory, (char*)(LPCSTR)directory.c_str());
	strcpy(MusicState.szControlFile, (char*)(LPCSTR)controlFile.c_str());

	if (!g_pGameClientShell->GetMusic()->RestoreMusicState(MusicState))
	{
		return LTFALSE;
	}

	UpdateData(LTTRUE);

	// Update the song list based on the newly selected theme!
	m_SongListCtrl->RemoveAll();
	std::map<std::string, int>::iterator it = (*m_CurrentSongList).begin();
	while (it != (*m_CurrentSongList).end()) {

		// Add the string to the control
		HSTRING hTemp = g_pLTClient->CreateString((char*)it->first.c_str());

		CLTGUITextCtrl* pCtrl = CreateTextItem((char*)(LPCTSTR)(it->first.c_str()), PLAY_SONG, 0);

		m_SongListCtrl->AddControl(pCtrl);

		// Free the strings
		g_pLTClient->FreeString(hTemp);
		it++;
	}

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
