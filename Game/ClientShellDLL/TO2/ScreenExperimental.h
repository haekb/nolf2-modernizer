// ----------------------------------------------------------------------- //
//
// MODULE  : ScreenExperimental.h
//
// PURPOSE : Interface screen for setting experimental options
//
// (c) 1999-2001 Monolith Productions, Inc.  All Rights Reserved
//
// ----------------------------------------------------------------------- //

#ifndef _SCREEN_EXPERIMENTAL_H_
#define _SCREEN_EXPERIMENTAL_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BaseScreen.h"

class CScreenExperimental : public CBaseScreen
{
public:
	CScreenExperimental();
	virtual ~CScreenExperimental();

	// Build the folder
	LTBOOL   Build();
	void    OnFocus(LTBOOL bFocus);


protected:


	uint32  OnCommand(uint32 dwCommand, uint32 dwParam1, uint32 dwParam2);

protected:
	LTBOOL	m_bEnableRagdolls;
	LTBOOL	m_bUnlockFPS;
};

#endif // _SCREEN_GAME_H_