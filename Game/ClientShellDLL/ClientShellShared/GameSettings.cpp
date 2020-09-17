// ----------------------------------------------------------------------- //
//
// MODULE  : GameSettings.cpp
//
// PURPOSE : Handles implementation of various game settings
//
// (c) 1997-2002 Monolith Productions, Inc.  All Rights Reserved
//
// ----------------------------------------------------------------------- //
#include "stdafx.h"
#include "GameClientShell.h"
#include "iltclient.h"
#include "GameSettings.h"
#include "stdio.h"
#include "windows.h"
#include "GameClientShell.h"
#include "VarTrack.h"

VarTrack	g_vtMouseScaleBase;
VarTrack	g_vtMouseScaleInc;

extern CGameClientShell* g_pGameClientShell;

CGameSettings::CGameSettings()
{
    m_pClientDE = LTNULL;
    m_pClientShell = LTNULL;
}

//////////////////////////////////////////////////////////////////
//
//	INIT THE SETTINGS...
//
//////////////////////////////////////////////////////////////////

LTBOOL CGameSettings::Init (ILTClient* pClientDE, CGameClientShell* pClientShell)
{
    if (!pClientDE || !pClientShell) return LTFALSE;

	m_pClientDE = pClientDE;
	m_pClientShell = pClientShell;

	g_vtMouseScaleBase.Init(g_pLTClient, "MouseScaleBase", NULL, 0.00125f);
	g_vtMouseScaleInc.Init(g_pLTClient, "MouseScaleIncrement", NULL, 0.001125f);

	// check if gore is allowed

    uint32 dwAdvancedOptions = g_pInterfaceMgr->GetAdvancedOptions();

	if (dwAdvancedOptions & AO_MUSIC)
	{
		m_pClientDE->RunConsoleString("musicenable 1");
	}
	else
	{
		m_pClientDE->RunConsoleString("musicenable 0");
	}
	if (dwAdvancedOptions & AO_SOUND)
	{
		m_pClientDE->RunConsoleString("soundenable 1");
	}
	else
	{
		m_pClientDE->RunConsoleString("soundenable 0");
	}

	// implement settings that need implementing

    ImplementMouseSensitivity();

	// hack to keep sound volume reasonable
	if (SoundVolume() > 100.0f)
		SetFloatVar("SoundVolume",100.0f);

  	ImplementSoundVolume();
	ImplementSoundQuality();

    return LTTRUE;
}







void CGameSettings::ImplementMusicSource()
{
	if (!m_pClientDE || !m_pClientShell) return;

	ASSERT(!"Don't call this");

    LTBOOL bPlay = MusicEnabled();

	if (bPlay)
	{
		// [KLS 8/11/02] SetupMusic will handle turning on the
		// music and making sure it plays the appropriate music.
		g_pInterfaceMgr->SetupMusic();
	}
	else 
	{
		m_pClientShell->GetMusic()->Term();
	}

}

void CGameSettings::ImplementMusicVolume()
{
	if (!m_pClientDE) return;
	ASSERT(!"Don't call this");

	float nMusicVolume = MusicVolume();

	g_pGameClientShell->GetMusic()->SetMenuVolume((long)nMusicVolume);
}

void CGameSettings::ImplementSoundVolume()
{
	if (!m_pClientDE) return;

	float nSoundVolume = SoundVolume();

	((ILTClientSoundMgr*)m_pClientDE->SoundMgr())->SetVolume((short)nSoundVolume);

	// set up the sound volume classes for the game
	float fMultiplier;
	fMultiplier = WeaponsMultiplier();
	((ILTClientSoundMgr*)m_pClientDE->SoundMgr())->SetSoundClassMultiplier( WEAPONS_SOUND_CLASS, fMultiplier );
	fMultiplier = SpeechMultiplier();
	((ILTClientSoundMgr*)m_pClientDE->SoundMgr())->SetSoundClassMultiplier( SPEECH_SOUND_CLASS, fMultiplier, false );
	fMultiplier = DefaultMultiplier();
	((ILTClientSoundMgr*)m_pClientDE->SoundMgr())->SetSoundClassMultiplier( DEFAULT_SOUND_CLASS, fMultiplier );

	// now have the sound manager update any playing sounds
	((ILTClientSoundMgr*)m_pClientDE->SoundMgr())->UpdateVolumeSettings();
}

void CGameSettings::ImplementSoundQuality()
{
	if (!m_pClientShell) return;

	m_pClientShell->InitSound();
}

void CGameSettings::ImplementMouseSensitivity()
{
	ImplementSensitivity(DEVICETYPE_MOUSE, GetFloatVar("MouseSensitivity"), GetFloatVar("MouseSensitivity"), g_vtMouseScaleBase.GetFloat(), g_vtMouseScaleInc.GetFloat());
}


void CGameSettings::ImplementGamepadSensitivity()
{
	ImplementSensitivity(DEVICETYPE_GAMEPAD, GetFloatVar("GamepadSensitivityX"), GetFloatVar("GamepadSensitivityY"), g_vtMouseScaleBase.GetFloat(), g_vtMouseScaleInc.GetFloat());
}

void CGameSettings::ImplementGamepadDeadzones()
{
	auto pList = m_pClientDE->GetDeviceBindings(DEVICETYPE_GAMEPAD);
	auto ptr = pList;

	/*
	{ "##16", "Left Axis X", SDL_CONTROLLER_AXIS_LEFTX + 16, SDL_CONTROLLER_AXIS_LEFTX, true },
	{ "##17", "Left Axis Y", SDL_CONTROLLER_AXIS_LEFTY + 16, SDL_CONTROLLER_AXIS_LEFTY, true },
	{ "##18", "Right Axis X", SDL_CONTROLLER_AXIS_RIGHTX + 16, SDL_CONTROLLER_AXIS_RIGHTX, true },
	{ "##19", "Right Axis Y", SDL_CONTROLLER_AXIS_RIGHTY + 16, SDL_CONTROLLER_AXIS_RIGHTY, true },
	{ "##20", "Left Trigger", SDL_CONTROLLER_AXIS_TRIGGERLEFT + 16, SDL_CONTROLLER_AXIS_TRIGGERLEFT, true },
	{ "##21", "Right Trigger", SDL_CONTROLLER_AXIS_TRIGGERRIGHT + 16, SDL_CONTROLLER_AXIS_TRIGGERRIGHT, true },
	*/

	float fDeadzoneLeftAnalog = GetFloatVar("GamepadDeadzoneLeftAnalog") * 1000.0f;
	float fDeadzoneRightAnalog = GetFloatVar("GamepadDeadzoneRightAnalog") * 1000.0f;
	float fDeadzoneTriggers = GetFloatVar("GamepadDeadzoneTriggers") * 1000.0f;

	while (ptr)
	{
		// No action? Skip! (I don't think this is possible, but let's cover our butts.)
		if (!ptr->pActionHead)
		{
			continue;
		}

		float fDeadzoneAmount = -1.0f;

		if (ptr->m_nObjectId == 16 || ptr->m_nObjectId == 17) // Left
		{
			fDeadzoneAmount = fDeadzoneLeftAnalog;
		}
		else if (ptr->m_nObjectId == 18 || ptr->m_nObjectId == 19) // Right
		{
			fDeadzoneAmount = fDeadzoneRightAnalog;
		}
		else if(ptr->m_nObjectId == 20 || ptr->m_nObjectId == 21) // Triggers
		{
			fDeadzoneAmount = fDeadzoneTriggers;
		}

		// If we've been set a non-default value, let's set some DEADZONES.
		if (fDeadzoneAmount != -1.0f)
		{
			// Clear the binding
			m_pClientDE->ClearBinding("##gamepad", ptr->strRealName);
			auto pAction = ptr->pActionHead;

			while (pAction)
			{
				// Make sure we copy over the sign info
				float fSign = 1.0f;
				if (pAction->nRangeHigh < 0)
				{
					fSign = -1.0f;
				}

				m_pClientDE->AddBinding("##gamepad", ptr->strRealName, pAction->strActionName, fSign * fDeadzoneAmount, fSign * 32768.0f);

				pAction = pAction->pNext;
			}
		}
		
		ptr = ptr->pNext;
	}

	if (pList)
	{
		m_pClientDE->FreeDeviceBindings(pList);
	}
}

void CGameSettings::ImplementSensitivity(int nDeviceType, float fSensitivityX, float fSensitivityY, float fBaseScale, float fIncrements)
{
	if (!m_pClientDE) return;
	
	char strDevice[128];
	memset(strDevice, 0, 128);
	LTRESULT result = m_pClientDE->GetDeviceName(nDeviceType, strDevice, 127);
	if (result == LT_OK)
	{
		// get x- and y- axis names

		char strXAxis[32];
		memset(strXAxis, 0, 32);
		char strYAxis[32];
		memset(strYAxis, 0, 32);

		LTBOOL bFoundXAxis = LTFALSE;
		LTBOOL bFoundYAxis = LTFALSE;

		auto pList = m_pClientDE->GetDeviceBindings(nDeviceType);
		auto ptr = pList;

		while (ptr)
		{
			// No action? Skip! (I don't think this is possible, but let's cover our butts.)
			if (!ptr->pActionHead)
			{
				continue;
			}

			auto pAction = ptr->pActionHead;

			// We'll need to loop through all the actions, 
			// in case there's a multi-bind!
			while (pAction)
			{
				if (stricmp(pAction->strActionName, "Axis1") == 0)
				{
					SAFE_STRCPY(strXAxis, ptr->strRealName);
					bFoundXAxis = LTTRUE;
				}
				else if (stricmp(pAction->strActionName, "Axis2") == 0)
				{
					SAFE_STRCPY(strYAxis, ptr->strRealName);
					bFoundYAxis = LTTRUE;
				}
				pAction = pAction->pNext;
			}

			// We found everything? Cool, let's get outta here!
			if (bFoundXAxis && bFoundYAxis)
			{
				break;
			}

			ptr = ptr->pNext;
		}

		if (pList)
		{
			m_pClientDE->FreeDeviceBindings(pList);
		}

		if (bFoundXAxis && bFoundYAxis)
		{
			// run the console string

			char strConsole[64];

			sprintf(strConsole, "scale \"%s\" \"%s\" %f", strDevice, strXAxis, fBaseScale + ((float)fSensitivityX * fIncrements));
			m_pClientDE->RunConsoleString(strConsole);
			sprintf(strConsole, "scale \"%s\" \"%s\" %f", strDevice, strYAxis, fBaseScale + ((float)fSensitivityY * fIncrements));
			m_pClientDE->RunConsoleString(strConsole);
		}
	}
}



