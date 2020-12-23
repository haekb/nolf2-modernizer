// ----------------------------------------------------------------------- //
//
// MODULE  : HUDFramerate.h
//
// PURPOSE : HUDItem to display framerate
//
// (c) 2001 Monolith Productions, Inc.  All Rights Reserved
//
// ----------------------------------------------------------------------- //

#ifndef __HUD__FRAMERATE_H
#define __HUD__FRAMERATE_H

#include "BaseHUDItem.h"
//#include "HUDHidingBar.h"

//******************************************************************************************
//** HUD showing framerate
//******************************************************************************************
class CHUDFramerate : public CBaseHUDItem
{
public:
	CHUDFramerate();

	LTBOOL      Init();
	void		Term();

	void        Render();
	void        Update();

	void        UpdateLayout();

private:

	enum eHidingPrims
	{
		kHidePrim,
		kHiddenPrim,
		kCantHidePrim,

		kNumPrims
	};

	LTIntPt		m_BasePos;
	LTIntPt		m_BaseSize;
	LTFLOAT		m_fIconSize;

	LTFLOAT		m_bDraw;

	float		m_fHideDuration;
	float		m_fHideTimer;
	float		m_fHideBarWaitTime;

	// Framerate stuff
	CUIPolyString* m_pStr;
	LTIntPt		m_TextOffset;
	uint32		m_TextColor;
	uint8		m_nTextHeight;

};

#endif