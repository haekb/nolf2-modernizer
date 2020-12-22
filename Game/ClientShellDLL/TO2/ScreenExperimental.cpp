// ----------------------------------------------------------------------- //
//
// MODULE  : ScreenGame.cpp
//
// PURPOSE : Interface screen for setting gameplay options
//
// (c) 1999-2001 Monolith Productions, Inc.  All Rights Reserved
//
// ----------------------------------------------------------------------- //

#include "stdafx.h"
#include "ScreenExperimental.h"
#include "ScreenMgr.h"
#include "ScreenCommands.h"

#include "GameClientShell.h"
#include "VersionMgr.h"
#include "ResShared.h"

namespace
{
	int kGap = 0;
	int kWidth = 0;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CScreenExperimental::CScreenExperimental()
{
	m_bEnableRagdolls = LTFALSE;
	m_bUnlockFPS = LTFALSE;
}

CScreenExperimental::~CScreenExperimental()
{

}

// Build the screen
LTBOOL CScreenExperimental::Build()
{

	CreateTitle(IDS_TITLE_EXPERIMENTAL);

	kGap = g_pLayoutMgr->GetScreenCustomInt(SCREEN_ID_EXPERIMENTAL, "ColumnWidth");
	kWidth = g_pLayoutMgr->GetScreenCustomInt(SCREEN_ID_EXPERIMENTAL, "SliderWidth");

	//background frame
	LTRect frameRect = g_pLayoutMgr->GetScreenCustomRect(SCREEN_ID_EXPERIMENTAL, "FrameRect");
	LTIntPt pos(frameRect.left, frameRect.top);
	int nHt = frameRect.bottom - frameRect.top;
	int nWd = frameRect.right - frameRect.left;

	char szFrame[128];
	g_pLayoutMgr->GetScreenCustomString(SCREEN_ID_EXPERIMENTAL, "FrameTexture", szFrame, sizeof(szFrame));
	HTEXTURE hFrame = g_pInterfaceResMgr->GetTexture(szFrame);
	CLTGUIFrame* pFrame = debug_new(CLTGUIFrame);
	pFrame->Create(hFrame, nWd, nHt + 8, LTTRUE);
	pFrame->SetBasePos(pos);
	pFrame->ApplyPosition(g_pInterfaceResMgr->GetYRatio(), g_pInterfaceResMgr->Get4x3Offset());
	pFrame->SetBorder(2, m_SelectedColor);
	AddControl(pFrame);

	char szYes[16];
	char szNo[16];
	FormatString(IDS_YES, szYes, sizeof(szYes));
	FormatString(IDS_NO, szNo, sizeof(szNo));

	//always run
	CLTGUIToggle* pToggle = AddToggle(IDS_RAGDOLLS, IDS_HELP_RAGDOLLS, kGap, &m_bEnableRagdolls);
	pToggle->SetOnString(szYes);
	pToggle->SetOffString(szNo);

	pToggle = AddToggle(IDS_UNLOCK_FPS, IDS_HELP_UNLOCK_FPS, kGap, &m_bUnlockFPS);
	pToggle->SetOnString(szYes);
	pToggle->SetOffString(szNo);

	// Make sure to call the base class
	if (!CBaseScreen::Build()) return LTFALSE;

	UseBack(LTTRUE, LTTRUE);
	return LTTRUE;
}

uint32 CScreenExperimental::OnCommand(uint32 dwCommand, uint32 dwParam1, uint32 dwParam2)
{

	switch (dwCommand)
	{
	case CMD_CROSSHAIR:
	{
		m_pScreenMgr->SetCurrentScreen(SCREEN_ID_CROSSHAIR);
		break;
	}
	default:
		return CBaseScreen::OnCommand(dwCommand, dwParam1, dwParam2);
	}
	return 1;
};

void CScreenExperimental::OnFocus(LTBOOL bFocus)
{
	CUserProfile* pProfile = g_pProfileMgr->GetCurrentProfile();
	if (bFocus)
	{
		pProfile->SetExperimentalOptions();

		m_bEnableRagdolls = pProfile->m_bEnableRagdolls;
		m_bUnlockFPS = pProfile->m_bUnlockFPS;

		UpdateData(LTFALSE);
	}
	else
	{
		UpdateData();

		pProfile->m_bEnableRagdolls = m_bEnableRagdolls;
		pProfile->m_bUnlockFPS = m_bUnlockFPS;

		pProfile->ApplyExperimentalGameOptions();
		pProfile->Save();

	}
	CBaseScreen::OnFocus(bFocus);
}


