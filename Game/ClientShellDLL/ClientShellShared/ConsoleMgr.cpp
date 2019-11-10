#include "stdafx.h"
#include "ConsoleMgr.h"

#include "LTGUIMgr.h"
#include "LTPoly.h"
#include "InterfaceResMgr.h"

ConsoleMgr* g_pConsoleMgr = NULL;
extern CInterfaceResMgr* g_pInterfaceResMgr;

ConsoleMgr::ConsoleMgr()
{
	g_pConsoleMgr = this;

	m_bVisible = true;
	m_hConsoleSurface = NULL;
}

ConsoleMgr::~ConsoleMgr()
{
	if (g_pConsoleMgr) {
		g_pConsoleMgr = NULL;
	}

	if (m_hConsoleSurface) {
		g_pInterfaceResMgr->FreeSharedSurface(m_hConsoleSurface);
		m_hConsoleSurface = NULL;
	}
}

void ConsoleMgr::Init()
{
	//m_Frame.Create(g_pInterfaceResMgr->GetTexture("interface\\menu\\sprtex\\frame.dtx"), 200, 320, LTTRUE);

	for (int i = 0; i < 15; i++) {

		CLTGUITextCtrl* pText = debug_new(CLTGUITextCtrl);
		if (!pText->Create("", LTNULL, LTNULL, g_pInterfaceResMgr->GetFont(4), 14, NULL))
		{
			debug_delete(pText);
			pText = LTNULL;
		}

		m_pLineItems.push_back(pText);
		m_Window.AddControl(pText, { 0, 0 });
	}

	//m_LineItem = g_pFontManager->CreateFormattedPolyString(pFont, "", 0.0f, 0.0f);

	m_Window.Create(g_pInterfaceResMgr->GetTexture("interface\\menu\\sprtex\\frame.dtx"), 1280, 240);

	if (!m_hConsoleSurface) {
		m_hConsoleSurface = g_pInterfaceResMgr->GetSharedSurface("interface\\console.pcx");
	}
}

void ConsoleMgr::Read(CConsolePrintData* pData)
{
	HistoryData data;

	data.iColour = SETRGB(pData->m_Color.r, pData->m_Color.g, pData->m_Color.b);
	data.sMessage = pData->m_pMessage;
	data.iLevel = pData->m_nFilterLevel;

	m_HistorySlice.push_back(data);

	if (m_HistorySlice.size() > 15) {
		m_HistorySlice.erase(m_HistorySlice.begin());
	}
	
	m_History.push_back(data);
}

void ConsoleMgr::Draw()
{
	if (!m_bVisible) {
		return;
	}

	LTRect dest = { 0, 0, (int)g_pInterfaceResMgr->GetScreenWidth(), 240 };
	HLTCOLOR hTransColor = g_pLTClient->SetupColor1(1.0f, 1.0f, 1.0f, LTTRUE);
	g_pLTClient->ScaleSurfaceToSurfaceTransparent(g_pLTClient->GetScreenSurface(), m_hConsoleSurface, &dest, LTNULL, hTransColor);
	
	LTIntPt pos = { 8, 0 };

#if 0
	std::string buffer = "";

	for (auto item : m_History) {
		buffer += item.sMessage;

		
	}

	m_LineItem->SetText(buffer.c_str());
	m_LineItem->Render();
#else
	m_Window.SetScale(1.0f);

	int index = 0;
	for (auto item : m_HistorySlice) {
		if (index >= m_pLineItems.size()) {
			break;
		}

		CLTGUITextCtrl* pText = m_pLineItems.at(index);

		pText->SetBasePos(pos);
		pText->SetString(item.sMessage.c_str());
		//pText->SetColors(item.iColour, item.iColour, item.iColour);
		/*
		m_Text.SetBasePos(pos);
		m_Text.SetString(item.sMessage.c_str());
		m_Text.SetColors(item.iColour, item.iColour, item.iColour);
		m_Text.Show(LTTRUE);


		m_Text.Render();
		*/

		index++;
		pos.y += 16;
	}
	
	//m_Text.SetString("HELLO WORLD");
	m_Window.Render();
#endif

#if 0
	CUIFont* pFont = g_pInterfaceResMgr->GetFont(0);
	LTIntPt pos(640, 480);
	CUIFormattedPolyString* Text = g_pFontManager->CreateFormattedPolyString(pFont, "", 0.0f, 0.0f);

	//Text->SetScale(1.0f);

	Text->SetFont(pFont);

	//Text.SetFixedWidth(pPopup->nTextWidth);

	//Text.SetScale(g_pInterfaceResMgr->GetXRatio());

	for (auto item : m_History) {
		Text->SetPosition(pos.x, pos.y);
		//auto colour = SETRGB(item.m_Color.r, item.m_Color.g, item.m_Color.b);//, item.m_Color.a);
		Text->SetText(item.sMessage.c_str());
		//Text->SetColors(item.iColour, item.iColour, item.iColour);

		

		Text->Render();

		pos.y += 14;

	}
#endif

}
