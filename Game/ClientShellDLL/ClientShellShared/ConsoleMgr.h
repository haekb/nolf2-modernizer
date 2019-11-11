#pragma once
#include <string>
#include <vector>
#include "iclientshell.h"

struct HistoryData {
	std::string sMessage;
	unsigned int iColour;
	int iLevel;
};

class ConsoleMgr
{
public:

	ConsoleMgr();
	~ConsoleMgr();

	void Init();
	LTBOOL HandleChar(unsigned char c);
	LTBOOL HandleKeyDown(int key, int rep);
	void Read(CConsolePrintData* pData);
	void Send();
	void Draw();
	void Show(bool bShow);

	LTBOOL  IsVisible() { return m_bVisible; }

protected:
	std::vector<HistoryData> m_History;
	std::vector<HistoryData> m_HistorySlice;
	HSURFACE m_hConsoleSurface;

	bool m_bVisible;

	CLTGUIWindow	    m_Window;
	std::vector<CLTGUITextCtrl*> m_pLineItems;
	CLTGUITextCtrl* m_pEditText;
	char m_szEdit[256];
	CLTGUIEditCtrl* m_pEdit;
};

