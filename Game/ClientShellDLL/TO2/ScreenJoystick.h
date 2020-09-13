// ----------------------------------------------------------------------- //
//
// MODULE  : ScreenJoystick.h
//
// PURPOSE : Interface screen for joystick/gamepad settings
//
// (c) 1999-2001 Monolith Productions, Inc.  All Rights Reserved
//
// ----------------------------------------------------------------------- //


#ifndef _SCREEN_JOYSTICK_H_
#define _SCREEN_JOYSTICK_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BaseScreen.h"
#include "ProfileMgr.h"

class CScreenJoystick : public CBaseScreen
{
public:
	CScreenJoystick();
	virtual ~CScreenJoystick();

	// Build the screen
    LTBOOL   Build();
    void OnFocus(LTBOOL bFocus);

protected:
    uint32  OnCommand(uint32 dwCommand, uint32 dwParam1, uint32 dwParam2);


	CLTGUICycleCtrl* m_pActiveController;

	CLTGUISlider* m_pSensitivityXCtrl;
	CLTGUISlider* m_pSensitivityYCtrl;

	CLTGUISlider* m_pAxisAccelerationCtrl;

	CLTGUISlider* m_pDeadzoneXCtrl;
	CLTGUISlider* m_pDeadzoneYCtrl;

	CLTGUISlider* m_pTriggerDeadzoneCtrl;

	int m_nSensitivityX;
	int m_nSensitivityY;

	int m_nAxisAcceleration;

	int m_nDeadzoneX;
	int m_nDeadzoneY;
	int m_nTriggerDeadzone;

	// old

	uint8	m_nAxis[kMaxDeviceAxis];
	uint8	m_nPOV[kMaxDevicePOV];
};

#endif // _SCREEN_KEYBOARD_H_