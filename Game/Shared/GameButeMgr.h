// ----------------------------------------------------------------------- //
//
// MODULE  : GameButeMgr.h
//
// PURPOSE : GameButeMgr definition - Base class for all bute mgrs
//
// CREATED : 3/30/99
//
// ----------------------------------------------------------------------- //

#ifndef __GAME_BUTE_MGR_H__
#define __GAME_BUTE_MGR_H__

#include "ButeMgr.h"

#pragma warning( disable : 4786 )
#include <hash_map>


void GBM_DisplayError(const char* szMsg);


// ----------------------------------------------------------------------- //
//
// Character pointer hash map definition...
//
// ----------------------------------------------------------------------- //

class GameButeMgr_Hasher {
public:
	enum { bucket_size = 10 };

	GameButeMgr_Hasher() {}

	size_t operator()(const char* key) const {
		return hash(key);
	}

	bool operator()(const char* left, const char* right) const {
		return compare(left, right);
	}
private:
	// Was `equal_str_nocase`, need to left side.
	bool compare(const char* s1, const char* s2) const
	{
		return stricmp(s1, s2) < 0;
	}
	// Was hash_str_nocase, still kinda is!
	// Copied for stl-port's std::hash<const char*>.
	// Added tolower function on the string.
	unsigned long hash(const char* str) const
	{
		unsigned long hash = 0;
		for (; *str; ++str)
			hash = 5 * hash + tolower(*str);

		return hash;
	}
};

typedef stdext::hash_map<const char *,int, GameButeMgr_Hasher> IndexTable;



class CGameButeMgr
{
	public :

        virtual LTBOOL Init(const char* szAttributeFile="") = 0;
		virtual void Term( ) { m_buteMgr.Term( ); m_strAttributeFile.Empty( ); }

		CGameButeMgr()
		{
			m_buteMgr.Init(GBM_DisplayError);
            m_pCryptKey = LTNULL;
            m_bInRezFile = LTTRUE;
		}

		virtual ~CGameButeMgr() { Term( ); }

        inline void SetInRezFile(LTBOOL bInRezFile) { m_bInRezFile = bInRezFile; }

		char const* GetAttributeFile( ) { return m_strAttributeFile; }

		virtual void Save();

	protected :

		CString		m_strAttributeFile;
		CButeMgr	m_buteMgr;

		char*		m_pCryptKey;
        LTBOOL       m_bInRezFile;

        LTBOOL       Parse(const char* sButeFile);
};


#endif // __GAME_BUTE_MGR_H__