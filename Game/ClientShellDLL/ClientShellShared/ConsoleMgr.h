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
	void Read(CConsolePrintData* pData);
	void Draw();

	LTBOOL  IsVisible() { return m_bVisible; }

protected:
	std::vector<HistoryData> m_History;
	std::vector<HistoryData> m_HistorySlice;
	HSURFACE m_hConsoleSurface;

	bool m_bVisible;

	CLTGUIWindow	    m_Window;
	std::vector<CLTGUITextCtrl*> m_pLineItems;
};

