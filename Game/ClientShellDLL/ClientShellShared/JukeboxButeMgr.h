#pragma once
#include "GameButeMgr.h"
#include "ltbasetypes.h"


//
// Contains all the jukebox songs!
//
#define CJBMGR_DEFAULT_FILE "Attributes\\Jukebox.txt"

class CJukeboxButeMgr;
extern CJukeboxButeMgr* g_pJukeboxButeMgr;

class CJukeboxButeMgr :
	public CGameButeMgr
{
public:
	CJukeboxButeMgr();
	~CJukeboxButeMgr();

	LTBOOL       Init(const char* szAttributeFile = CJBMGR_DEFAULT_FILE);
	void		Term();

	int			GetNumThemes() { return m_nThemeIDCount; }
	int			GetNumSongs() { return m_nSongIDCount; }

	// Themes
	void		GetThemeName(int nThemeID, char* pBuf, uint16 nBufLen);
	void		GetThemeDirectory(int nThemeID, char* pBuf, uint16 nBufLen);
	void		GetThemeControlFile(int nThemeID, char* pBuf, uint16 nBufLen);
	bool		GetThemeRequiresGOTY(int nThemeID);
	bool		GetThemeIsMp3(int nThemeID);

	// Songs
	void		GetSongName(int nSongID, char* pBuf, uint16 nBufLen);
	int			GetSongIntensityLevel(int nSongID);
	int			GetSongThemeID(int nSongID);
	void        GetSongPath(int nSongID, char* pBuf, uint16 nBufLen);

private:

	int m_nThemeIDCount;
	int m_nSongIDCount;

};

