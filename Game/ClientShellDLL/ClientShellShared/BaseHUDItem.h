// ----------------------------------------------------------------------- //
//
// MODULE  : HUDPaused.h
//
// PURPOSE : Definition of CHUDPaused to display a paused message
//
// (c) 2002 Monolith Productions, Inc.  All Rights Reserved
//
// ----------------------------------------------------------------------- //

#ifndef __BASE_HUD_ITEM_H
#define __BASE_HUD_ITEM_H

#include "HUDItem.h"

//******************************************************************************************
//** Base HUD Item - Mostly handles scale cache busting
//******************************************************************************************
class CBaseHUDItem : public CHUDItem
{
public:
	CBaseHUDItem();
	~CBaseHUDItem() {};

	virtual LTBOOL      Init() { return LTTRUE; };
	virtual void		Term() {};

	virtual void        Render() {};
	virtual	void        Update();

	virtual void        UpdateLayout();

	virtual	void		Show(LTBOOL bShow) {};

protected:
	float		m_fCacheScale;

	// Check this bool to determine if we need to update UI elements
	bool		m_bUpdateScale;
};



#endif