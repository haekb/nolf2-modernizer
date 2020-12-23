// ----------------------------------------------------------------------- //
//
// MODULE  : HUDCarrying.cpp
//
// PURPOSE : HUDItem to display an icon while carrying a body
//
// (c) 2002 Monolith Productions, Inc.  All Rights Reserved
//
// ----------------------------------------------------------------------- //

#include "stdafx.h"
#include "TO2HUDMgr.h"
#include "TO2PlayerStats.h"
#include "TO2InterfaceMgr.h"
#include "TO2PlayerMgr.h"

extern VarTrack g_vtShowFPS;

//******************************************************************************************
//**
//** HUD Show Framerate
//**
//******************************************************************************************

CHUDFramerate::CHUDFramerate()
{
	m_UpdateFlags = kHUDCarry | kHUDFrame;
}


LTBOOL CHUDFramerate::Init()
{
	uint8 nFont = g_pLayoutMgr->GetHUDFont();
	CUIFont* pFont = g_pInterfaceResMgr->GetFont(nFont);

	m_pStr = g_pFontManager->CreatePolyString(pFont, "", 0.0f, 0.0f);

	UpdateLayout();

	m_pStr->SetColors(argbWhite, argbWhite, argbWhite, argbWhite);

	return LTTRUE;
}

void CHUDFramerate::Term()
{
	if (m_pStr)
	{
		g_pFontManager->DestroyPolyString(m_pStr);
		m_pStr = LTNULL;
	}
}

void CHUDFramerate::Render()
{
	if (!m_pStr || !g_vtShowFPS.GetFloat()) {
		return;
	}

	SetRenderState();

	m_pStr->Render();
}

void CHUDFramerate::Update()
{
	if (!m_pStr || !g_vtShowFPS.GetFloat()) {
		return;
	}

	CBaseHUDItem::Update();

	CTO2PlayerStats* pPlayerStats = (CTO2PlayerStats*)g_pPlayerStats;

	LTFLOAT fFPS = pPlayerStats->GetFramerate();

	char szStr[32] = "";
	sprintf(szStr, "Framerate: %.2f", fFPS);

	uint8 h = (uint8)((float)m_nTextHeight * g_pInterfaceResMgr->GetYRatio());

	float x = (float)(m_BasePos.x + m_TextOffset.x) * g_pInterfaceResMgr->GetXRatio();
	float y = (float)(m_BasePos.y + m_TextOffset.y) * g_pInterfaceResMgr->GetYRatio();

	m_pStr->SetText(szStr);
	m_pStr->SetPosition(x, y);
	m_pStr->SetCharScreenHeight(h);

}

void CHUDFramerate::UpdateLayout()
{
	CBaseHUDItem::UpdateLayout();

	int nCurrentLayout = GetConsoleInt("HUDLayout", 0);

	m_BasePos = LTIntPt(2, 462);
	m_nTextHeight = 16;
	m_TextOffset = LTIntPt(0, 0);

}



