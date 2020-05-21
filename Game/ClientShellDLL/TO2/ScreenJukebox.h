#pragma once
#include "BaseScreen.h"
#include "Music.h"

#include <vector>
#include <string>
#include <map>

class CScreenJukebox : public CBaseScreen
{
public:
	CScreenJukebox();
	virtual ~CScreenJukebox();

	// Build the folder
	LTBOOL   Build();
	uint32 OnCommand(uint32 dwCommand, uint32 dwParam1, uint32 dwParam2);
	void    OnFocus(LTBOOL bFocus);
	virtual void	UpdateHelpText();

protected:

	LTBOOL PlayScore(int scoreId);

	CMusicState m_PreviousMusicState;

	CLTGUIListCtrl* m_pSongListCtrl;
	CLTGUIFrame* m_pSongFrame;

	int m_nWidth;

	std::string m_sCurrentSong;
	std::map<std::string, int>* m_CurrentSongList;

	std::vector<int> m_ThemeIDsToSkip;

	std::vector< std::map<std::string, int> > m_Songs;

private:

};

