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

	m_bVisible = false;
	m_hConsoleSurface = NULL;
	memset(m_szEdit, 0, sizeof(m_szEdit));
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
	m_Window.Create(g_pInterfaceResMgr->GetTexture("interface\\menu\\sprtex\\frame.dtx"), 1280, 240);

	for (int i = 0; i < 14; i++) {

		CLTGUITextCtrl* pText = debug_new(CLTGUITextCtrl);
		if (!pText->Create("", LTNULL, LTNULL, g_pInterfaceResMgr->GetFont(4), 14, NULL))
		{
			debug_delete(pText);
			pText = LTNULL;
		}

		m_pLineItems.push_back(pText);
		m_Window.AddControl(pText, { 0, 0 });
	}

	m_pEditText = debug_new(CLTGUITextCtrl);
	if (!m_pEditText->Create("", LTNULL, LTNULL, g_pInterfaceResMgr->GetFont(4), 14, NULL))
	{
		debug_delete(m_pEditText);
		m_pEditText = LTNULL;
	}

	m_pEditText->SetString(">");
	m_Window.AddControl(m_pEditText, { 0,0 });
	//m_LineItem = g_pFontManager->CreateFormattedPolyString(pFont, "", 0.0f, 0.0f);
	

	m_pEdit = debug_new(CLTGUIEditCtrl);
	if (!m_pEdit->Create(g_pLTClient, 1, g_pInterfaceResMgr->GetFont(4), 14, 256, NULL, m_szEdit))
	{
		debug_delete(m_pEdit);
		m_pEdit = LTNULL;
	}
	m_pEdit->Show(LTTRUE);
	m_pEdit->Enable(LTTRUE);
	m_pEdit->EnableCaret(LTTRUE);
	

	m_Window.AddControl(m_pEdit, { 0, 0 });
	
	auto test = m_Window.GetSelectedControl();
	
	m_Window.SetSelection(15);

	test = m_Window.GetSelectedControl();

	if (!m_hConsoleSurface) {
		m_hConsoleSurface = g_pInterfaceResMgr->GetSharedSurface("interface\\console.pcx");
	}
}

LTBOOL ConsoleMgr::HandleChar(unsigned char c)
{
	if (!m_bVisible) return LTFALSE;

	// Ignore console key
	if (c == VK_OEM_3) {
		return LTFALSE;
	}

	return m_pEdit->HandleChar(c);
}


LTBOOL ConsoleMgr::HandleKeyDown(int key, int rep)
{
	if (!m_bVisible) {
		if (key == VK_OEM_3) {
			Show(true);
			return LTTRUE;
		}

		return LTFALSE;
	}

	switch (key) {
	case VK_OEM_3:
	case VK_ESCAPE:
	{
		Show(false);
		return LTTRUE;
	} break;

	case VK_RETURN:
	{
		Send();
		return LTTRUE;
	} break;
	}

	m_pEdit->HandleKeyDown(key, rep);
	return LTTRUE;
}

void ConsoleMgr::Read(CConsolePrintData* pData)
{
	HistoryData data;

	data.iColour = SET_ARGB(255, pData->m_Color.r, pData->m_Color.g, pData->m_Color.b);
	data.sMessage = pData->m_pMessage;
	data.iLevel = pData->m_nFilterLevel;

	m_HistorySlice.push_back(data);

	if (m_HistorySlice.size() > 14) {
		m_HistorySlice.erase(m_HistorySlice.begin());
	}
	
	m_History.push_back(data);
}

void ConsoleMgr::Send()
{
	// Send it off!
	g_pLTClient->RunConsoleString(m_szEdit);

	// Clear our command string
	m_pEdit->SetText("");
	memset(m_szEdit, 0, sizeof(m_szEdit));
}

void ConsoleMgr::Draw()
{
	if (!m_bVisible) {
		return;
	}

	m_pEdit->UpdateData(LTTRUE);

	int iWidth = 0;
	RMode currentMode;
	g_pLTClient->GetRenderMode(&currentMode);

	LTRect dest = { 0, 0, (int)currentMode.m_Width, 240 };
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
		pText->SetColors(item.iColour, item.iColour, item.iColour);
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


	m_pEditText->SetBasePos(pos);
	
	pos.x += 8;


	m_pEdit->SetBasePos(pos);
	
	//m_pEdit->UpdateData(LTTRUE);

	//m_Text.SetString("HELLO WORLD");
	m_pEdit->Render();
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

void ConsoleMgr::Show(bool bShow)
{
	m_bVisible = bShow;
}
