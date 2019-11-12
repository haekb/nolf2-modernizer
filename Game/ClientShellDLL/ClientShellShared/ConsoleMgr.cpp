#include "stdafx.h"
#include "ConsoleMgr.h"

#include "LTGUIMgr.h"
#include "LTPoly.h"
#include "InterfaceResMgr.h"

ConsoleMgr* g_pConsoleMgr = NULL;
extern CInterfaceResMgr* g_pInterfaceResMgr;

void ShowHelpListCommand(int argc, char** argv)
{
	if (!g_pConsoleMgr) {
		return;
	}

	g_pLTClient->CPrint("Available commands:");
	for (auto item : g_pConsoleMgr->GetHelpList()) {
		g_pLTClient->CPrint(item.c_str());
	}
}

ConsoleMgr::ConsoleMgr()
{
	g_pConsoleMgr = this;

	m_bInitialized = false;
	m_bVisible = false;
	m_hConsoleSurface = NULL;
	memset(m_szEdit, 0, sizeof(m_szEdit));

	m_iHeight = 240;		// Pixels
	m_iFontSize = 14;		// Pixels?
	m_iLineSpacing = 16;	// Pixels

	g_pLTClient->RegisterConsoleProgram("help", ShowHelpListCommand);
}

ConsoleMgr::~ConsoleMgr()
{
	g_pLTClient->UnregisterConsoleProgram("help");

	Destroy();

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
	// If we're re-initializing, then destroy all the items
	if (m_bInitialized) {
		Destroy();
	}

	RMode currentMode;
	g_pLTClient->GetRenderMode(&currentMode);

	m_iHeight = (int)((float)currentMode.m_Height * 0.50f);

	// Calculate the amount of items we need to fill the space, and then minus one for our edit line.
	int iLineItemLength = (int)((float)m_iHeight / (float)m_iLineSpacing) - 1;

	m_Window.Create(g_pInterfaceResMgr->GetTexture("interface\\console.dtx"), 1280, m_iHeight);

	for (int i = 0; i < iLineItemLength; i++) {

		CLTGUITextCtrl* pText = debug_new(CLTGUITextCtrl);
		if (!pText->Create("", LTNULL, LTNULL, g_pInterfaceResMgr->GetFont(4), m_iFontSize, NULL))
		{
			debug_delete(pText);
			pText = LTNULL;
		}

		m_pLineItems.push_back(pText);
		m_Window.AddControl(pText, { 0, 0 });
	}

	m_pEditText = debug_new(CLTGUITextCtrl);
	if (!m_pEditText->Create("", LTNULL, LTNULL, g_pInterfaceResMgr->GetFont(4), m_iFontSize, NULL))
	{
		debug_delete(m_pEditText);
		m_pEditText = LTNULL;
	}

	m_pEditText->SetString(">");
	m_pEditText->SetColors(argbWhite, argbWhite, argbWhite);
	m_Window.AddControl(m_pEditText, { 0,0 });
	
	m_pEdit = debug_new(CLTGUIEditCtrl);
	if (!m_pEdit->Create(g_pLTClient, 1, g_pInterfaceResMgr->GetFont(4), m_iFontSize, 256, NULL, m_szEdit))
	{
		debug_delete(m_pEdit);
		m_pEdit = LTNULL;
	}

	m_pEdit->Show(LTTRUE);
	m_pEdit->Enable(LTTRUE);
	m_pEdit->EnableCaret(LTTRUE);
	
	// Add the edit control, and then set it as the selected control
	m_Window.AddControl(m_pEdit, { 0, 0 });
	m_Window.SetSelection(iLineItemLength + 1);

	m_bInitialized = true;
}

void ConsoleMgr::Destroy()
{
	if (!m_bInitialized) {
		return;
	}

	m_pEdit->Destroy();
	m_pEditText->Destroy();

	for (auto item : m_pLineItems) {
		item->Destroy();
	}

	m_Window.Destroy();

	m_pLineItems.clear();
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

	if (m_HistorySlice.size() > m_pLineItems.size()) {
		m_HistorySlice.erase(m_HistorySlice.begin());
	}
	
	m_History.push_back(data);
}

void ConsoleMgr::Send()
{
	// Echo it back
	g_pLTClient->CPrint(m_szEdit);

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

	LTIntPt pos = { 8, 0 };

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

		index++;
		pos.y += m_iLineSpacing;
	}

	m_pEditText->SetBasePos(pos);
	pos.x += m_iLineSpacing / 2;
	m_pEdit->SetBasePos(pos);

	m_Window.Render();
}

void ConsoleMgr::Show(bool bShow)
{
	m_bVisible = bShow;
}

void ConsoleMgr::AddToHelp(std::string command)
{
	m_HelpList.push_back(command);
}

void ConsoleMgr::RemoveFromHelp(std::string command)
{
	int index = 0;
	for (auto item : m_HelpList) {
		if (command.compare(item) == 0) {
			item.erase(item.begin() + index);
		}
		index++;
	}
}
