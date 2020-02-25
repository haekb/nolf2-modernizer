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
#include "HUDMgr.h"
#include "ConsoleMgr.h"

extern ConsoleMgr *g_pConsoleMgr;

//******************************************************************************************
//**
//** HUD Show Framerate
//**
//******************************************************************************************

CHUDConsoleLines::CHUDConsoleLines()
{
	m_UpdateFlags = kHUDConsoleLines;// | kHUDFrame;
}


LTBOOL CHUDConsoleLines::Init()
{
	//uint8 nFont = g_pLayoutMgr->GetHUDFont();
	CUIFont* pFont = g_pInterfaceResMgr->GetFont(4);

	m_pStr = g_pFontManager->CreateFormattedPolyString(pFont, "", 0.0f, 0.0f);

	UpdateLayout();

	m_pStr->SetColors(argbWhite, argbWhite, argbWhite, argbWhite);

	return LTTRUE;
}

void CHUDConsoleLines::Term()
{
	if (m_pStr)
	{
		g_pFontManager->DestroyPolyString(m_pStr);
		m_pStr = LTNULL;
	}
}

void CHUDConsoleLines::Render()
{
	if (!m_pStr) {
		return;
	}

	SetRenderState();

	m_pStr->Render();
}

void CHUDConsoleLines::Update()
{
	int nNumConsoleLines = GetConsoleInt("NumConsoleLines", 0);
	if (!m_pStr || !nNumConsoleLines) {
		return;
	}

	std::string sLines = g_pConsoleMgr->GetConsoleLines();

	uint8 h = (uint8)((float)m_nTextHeight * g_pInterfaceResMgr->GetYRatio());

	float x = (float)(m_BasePos.x + m_TextOffset.x) * g_pInterfaceResMgr->GetXRatio();
	float y = (float)(m_BasePos.y + m_TextOffset.y) * g_pInterfaceResMgr->GetYRatio();

	m_pStr->SetText(sLines.c_str());
	m_pStr->SetPosition(x, y);
	m_pStr->SetCharScreenHeight(h);

}

void CHUDConsoleLines::UpdateLayout()
{
	int nCurrentLayout = GetConsoleInt("HUDLayout", 0);

	m_BasePos = LTIntPt(2, 2);
	m_nTextHeight = 8;
	m_TextOffset = LTIntPt(0, 0);

}



