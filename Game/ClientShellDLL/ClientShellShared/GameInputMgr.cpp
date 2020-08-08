#include "stdafx.h"
#include "GameInputMgr.h"
#include "GameClientShell.h"
#include <SDL.h>
#include <algorithm>
#include <dinput.h>
#include "SDLDInput8Conversion.h"
	
GameInputMgr* g_pGameInputMgr = nullptr;

// Jake: This is generated at construction from the above map
std::map <int, DInputKey> g_mDInputMouseToSDLMouse;
std::map < SDL_Scancode, DInputKey > g_mSDLToDInput;


#define BIND_FUNC(x) m_pInputMgr->x = GameInputMgr::x
constexpr auto ENGINE_INPUT_MGR_PTR = 0x0059abc8;



//#define USE_OLD_INPUT

/// <summary>
/// Game Input Manager
/// DirectInput8 is funky, and provides the weirdest mouse movements ever!!
/// So we sneakily replace the struct/class/whatever pointer with our own built in SDL2.
/// 
/// Jake notes: I had to write an input manager like 3 times in 3 different ways before settling on this..
/// Sorry if it's a little sloppy in places.
/// 
/// Actually important note: Trigger name is not trigger name. A parameter called trigger name ends up being like "#31", however NOLF2 expects it to be like the actual key name "W".
/// Like what the heck guys. 
/// </summary>
GameInputMgr::GameInputMgr()
{
	g_pGameInputMgr = this;
	m_nWheelDelta = 0;
	m_bRelativeMode = false;

#ifdef USE_OLD_INPUT
	return;
#endif
	
	// Clean up the old inputmgr, and replace the bindings.
	m_pInputMgr = (InputMgr*)ENGINE_INPUT_MGR_PTR;
	if (m_pInputMgr->IsInitted(m_pInputMgr))
	{
		m_pInputMgr->Term(m_pInputMgr);

		ReplaceBindings();

		GameInputMgr::Init(m_pInputMgr, nullptr);
	}
	else
	{
		ReplaceBindings();
	}
}

GameInputMgr::~GameInputMgr()
{
	// Engine will clean up
}

void GameInputMgr::ReplaceBindings()
{
	BIND_FUNC(Init);
	BIND_FUNC(Term);
	BIND_FUNC(IsInitted);
	BIND_FUNC(ListDevices);
	BIND_FUNC(PlayJoystickEffect);
	BIND_FUNC(ReadInput);
	BIND_FUNC(FlushInputBuffers);
	BIND_FUNC(ClearInput);
	BIND_FUNC(AddAction);
	BIND_FUNC(EnableDevice);
	BIND_FUNC(ClearBindings);
	BIND_FUNC(AddBinding);
	BIND_FUNC(ScaleTrigger);
	BIND_FUNC(GetDeviceBindings);
	BIND_FUNC(FreeDeviceBindings);
	BIND_FUNC(StartDeviceTrack);
	BIND_FUNC(TrackDevice);
	BIND_FUNC(EndDeviceTrack);
	BIND_FUNC(GetDeviceObjects);
	BIND_FUNC(FreeDeviceObjects);
	BIND_FUNC(GetDeviceName);
	BIND_FUNC(GetDeviceObjectName);
	BIND_FUNC(IsDeviceEnabled);
	BIND_FUNC(ShowDeviceObjects);
	BIND_FUNC(ShowInputDevices);
}

//
// InputMgr functions
//

bool GameInputMgr::Init(InputMgr* pInputMgr, intptr_t* pState)
{
	g_pGameInputMgr->GenerateReverseMap();

	return true;
}

void GameInputMgr::Term(InputMgr* pInputMgr)
{
	if (!pInputMgr)
	{
		return;
	}

	for (auto pBinding : g_pGameInputMgr->m_pBindingList)
	{
		delete pBinding;
		pBinding = nullptr;
	}
	g_pGameInputMgr->m_pBindingList.clear();

	for (auto pAction : g_pGameInputMgr->m_pActionList)
	{
		delete pAction;
		pAction = nullptr;
	}
	g_pGameInputMgr->m_pActionList.clear();

	for (auto pAvailableObject : g_pGameInputMgr->m_pAvailableObjects)
	{
		delete pAvailableObject;
		pAvailableObject = nullptr;
	}
	g_pGameInputMgr->m_pAvailableObjects.clear();

}

bool GameInputMgr::IsInitted(InputMgr* pInputMgr)
{
	return true;
}

void GameInputMgr::ListDevices(InputMgr* pInputMgr)
{
	g_pLTClient->CPrint("[GameInputMgr::ListDevices] I'm being called!");
}

uint32_t GameInputMgr::PlayJoystickEffect(InputMgr* pInputMgr, const char* szEffectName, float x, float y)
{
	return 0;
}

void GameInputMgr::ReadInput(InputMgr* pInputMgr, uint8_t* pActionsOn, float fAxisOffsets[3])
{
	auto pBinding = g_pGameInputMgr->m_pBindingList;
	int nDeltaX = 0, nDeltaY = 0;

	// Only track mouse if relative mode is enabled
	if (g_pGameInputMgr->GetRelativeMode())
	{
		SDL_GetRelativeMouseState(&nDeltaX, &nDeltaY);
	}

	auto pKeys = SDL_GetKeyboardState(nullptr);
	auto pButtons = SDL_GetMouseState(nullptr, nullptr);

	for (auto pBinding : g_pGameInputMgr->m_pBindingList)
	{
		auto pDeviceBinding = pBinding->pDeviceBinding;
		if (!pDeviceBinding)
		{
			continue;
		}

		// Note: This stuff is all special cases.
		// Only track mouse if relative mode is enabled
		if (pBinding->bIsAxis && pBinding->nDeviceType == DEVICE_TYPE_MOUSE && g_pGameInputMgr->GetRelativeMode())
		{
			//
			// Handle Axis
			//
			static int nCurrentMouseX = 0;
			static int nCurrentMouseY = 0;
			static int nPreviousMouseX = 0;
			static int nPreviousMouseY = 0;
			float nScale = pDeviceBinding->nScale;

			// Only thing that's not SDL2!
			if (pBinding->nMouseAxis == SDL_MOUSE_AXIS_WHEEL)
			{
				auto nWheelDelta = g_pGameInputMgr->GetWheelDelta();
				if (nWheelDelta >= WHEEL_DELTA && pDeviceBinding->pActionHead->nRangeLow > 0.0)
				{
					pActionsOn[pDeviceBinding->pActionHead->nActionCode] |= 1;
				}
				else if (nWheelDelta <= -WHEEL_DELTA && pDeviceBinding->pActionHead->nRangeLow < 0.0)
				{
					pActionsOn[pDeviceBinding->pActionHead->nActionCode] |= 1;
				}
			}

			// X-Axis
			if (pBinding->nMouseAxis == SDL_MOUSE_AXIS_X) // Action Code == -1
			{
				nCurrentMouseX += nDeltaX;
				fAxisOffsets[0] = (float)(nCurrentMouseX - nPreviousMouseX) * nScale;
				nPreviousMouseX = nCurrentMouseX;
			}

			// Y-Axis
			if (pBinding->nMouseAxis == SDL_MOUSE_AXIS_Y) // Action Code == -2
			{
				nCurrentMouseY += nDeltaY;
				fAxisOffsets[1] = (float)(nCurrentMouseY - nPreviousMouseY) * nScale;
				nPreviousMouseY = nCurrentMouseY;
			}

			// Z-Axis ???
			fAxisOffsets[2] = 0.0f;
		}

		// No special case, just direct DIK to SDL conversion!
		uint8_t nOn = 0;

		if (pBinding->nDeviceType == DEVICE_TYPE_KEYBOARD)
		{
			nOn = pKeys[pBinding->nKeyboardScancode];
		}
		else if (pBinding->nDeviceType == DEVICE_TYPE_MOUSE)
		{
			nOn = (pButtons & SDL_BUTTON(pBinding->nMouseButton));
		}
		else if (pBinding->nDeviceType == DEVICE_TYPE_GAMEPAD)
		{
			// TODO: Implement SDL_GameControllerGetButton
		}

		pActionsOn[pDeviceBinding->pActionHead->nActionCode] |= nOn;
	}
}

bool GameInputMgr::FlushInputBuffers(InputMgr* pInputMgr)
{
	return true;
}

LTRESULT GameInputMgr::ClearInput()
{
	return LT_OK;
}

void GameInputMgr::AddAction(InputMgr* pInputMgr, const char* pActionName, int nActionCode)
{
	GameAction* pAction = g_pGameInputMgr->FindAction(pActionName);

	// Update the code, if we already added this action!
	if (pAction)
	{
		pAction->nActionCode = nActionCode;
		return;
	}

	pAction = new GameAction();

	if (!pAction)
	{
		return;
	}

	LTStrCpy(pAction->strActionName, pActionName, sizeof(pAction->strActionName));
	pAction->nActionCode = nActionCode;
	pAction->nRangeLow = 0;
	pAction->nRangeHigh = 0;
	// We no longer link actions together, until we need to.
	pAction->pNext = nullptr;

	g_pGameInputMgr->m_pActionList.push_back(pAction);
}

bool GameInputMgr::EnableDevice(InputMgr* pInputMgr, const char* pDeviceName)
{
	char szDeviceName[INPUTNAME_LEN];
	auto nDeviceType = DEVICE_TYPE_UNKNOWN;

	bool bMouseAlreadyInit = std::find(g_pGameInputMgr->m_EnabledDevices.begin(), g_pGameInputMgr->m_EnabledDevices.end(), DEVICE_TYPE_MOUSE) != g_pGameInputMgr->m_EnabledDevices.end();
	if (stricmp("##mouse", pDeviceName) == 0 && !bMouseAlreadyInit)
	{
		// Create our list of bindable mice objects
		nDeviceType = DEVICE_TYPE_MOUSE;
		g_pGameInputMgr->GetDeviceName(nDeviceType, szDeviceName, sizeof(szDeviceName));

		// Create a template to hold basic constant info
		GIMBinding* tempBinding = new GIMBinding();

		// Create a binding we'll be pushing into our "Available Objects" list.
		// This will be new'd on every additional object..don't worry we'll free them later.
		GIMBinding* binding = new GIMBinding();

		// These are constants
		tempBinding->bIsEnabled = true;
		tempBinding->bHasDIK = false;
		tempBinding->nDeviceType = nDeviceType;
		tempBinding->pDeviceBinding = nullptr;
		LTStrCpy(tempBinding->szDevice, szDeviceName, sizeof(tempBinding->szName));

		// Left Mouse Button
		memcpy(binding, tempBinding, sizeof(GIMBinding));
		LTStrCpy(binding->szName, "Left", sizeof(binding->szName));
		binding->nDIK = MOUSE_LEFT_BUTTON;
		binding->nMouseButton = SDL_MOUSE_BUTTON_LEFT;
		binding->bIsAxis = false;

		g_pGameInputMgr->m_pAvailableObjects.push_back(binding);

		// Right Mouse Button
		binding = new GIMBinding();
		memcpy(binding, tempBinding, sizeof(GIMBinding));
		LTStrCpy(binding->szName, "Right", sizeof(binding->szName));
		binding->nDIK = MOUSE_RIGHT_BUTTON;
		binding->nMouseButton = SDL_MOUSE_BUTTON_RIGHT;
		binding->bIsAxis = false;

		g_pGameInputMgr->m_pAvailableObjects.push_back(binding);

		// Middle Mouse Button
		binding = new GIMBinding();
		memcpy(binding, tempBinding, sizeof(GIMBinding));
		LTStrCpy(binding->szName, "Middle", sizeof(binding->szName));
		binding->nDIK = MOUSE_MIDDLE_BUTTON;
		binding->nMouseButton = SDL_MOUSE_BUTTON_MIDDLE;
		binding->bIsAxis = false;

		g_pGameInputMgr->m_pAvailableObjects.push_back(binding);

		// X-Axis
		binding = new GIMBinding();
		memcpy(binding, tempBinding, sizeof(GIMBinding));
		LTStrCpy(binding->szName, "Axis X", sizeof(binding->szName));
		binding->nDIK = MOUSE_X_AXIS;
		binding->nMouseAxis = SDL_MOUSE_AXIS_X;
		binding->bIsAxis = true;

		g_pGameInputMgr->m_pAvailableObjects.push_back(binding);

		// Y-Axis
		binding = new GIMBinding();
		memcpy(binding, tempBinding, sizeof(GIMBinding));
		LTStrCpy(binding->szName, "Axis Y", sizeof(binding->szName));
		binding->nDIK = MOUSE_Y_AXIS;
		binding->nMouseAxis = SDL_MOUSE_AXIS_Y;
		binding->bIsAxis = true;

		g_pGameInputMgr->m_pAvailableObjects.push_back(binding);

		// Mouse Wheel
		binding = new GIMBinding();
		memcpy(binding, tempBinding, sizeof(GIMBinding));
		LTStrCpy(binding->szName, "Wheel", sizeof(binding->szName));
		binding->nDIK = MOUSE_Z_AXIS;
		binding->nMouseAxis = SDL_MOUSE_AXIS_WHEEL;
		binding->bIsAxis = true;

		g_pGameInputMgr->m_pAvailableObjects.push_back(binding);

		// Clear our template pointer
		delete tempBinding;
		tempBinding = nullptr;

		g_pGameInputMgr->m_EnabledDevices.push_back(DEVICE_TYPE_MOUSE);

		return true;
	}

	bool bKeyboardAlreadyInit = std::find(g_pGameInputMgr->m_EnabledDevices.begin(), g_pGameInputMgr->m_EnabledDevices.end(), DEVICE_TYPE_KEYBOARD) != g_pGameInputMgr->m_EnabledDevices.end();
	if (stricmp("##keyboard", pDeviceName) == 0 && !bKeyboardAlreadyInit)
	{
		nDeviceType = DEVICE_TYPE_KEYBOARD;
		g_pGameInputMgr->GetDeviceName(nDeviceType, szDeviceName, sizeof(szDeviceName));


		// Create a template to hold basic constant info
		GIMBinding* tempBinding = new GIMBinding();

		// Create a binding we'll be pushing into our "Available Objects" list.
		// This will be new'd on every additional object..don't worry we'll free them later.
		GIMBinding* binding = nullptr;

		// These are constants
		tempBinding->bIsEnabled = true;
		tempBinding->bHasDIK = true;
		tempBinding->nDeviceType = nDeviceType;
		tempBinding->pDeviceBinding = nullptr;
		LTStrCpy(tempBinding->szDevice, szDeviceName, sizeof(binding->szName));

		// Loop through our giant map of possible DInput -> SDL keys to generate our the available keyboard keys!
		for (auto pItem : g_mDInputToSDL)
		{
			binding = new GIMBinding();
			memcpy(binding, tempBinding, sizeof(GIMBinding));

			auto nKeyCode = SDL_GetKeyFromScancode(pItem.second);

			LTStrCpy(binding->szName, SDL_GetKeyName(nKeyCode), sizeof(binding->szName));
			binding->nDIK = pItem.first;
			binding->nKeyboardScancode = pItem.second;
			binding->bIsAxis = false;

			g_pGameInputMgr->m_pAvailableObjects.push_back(binding);
		}

		delete tempBinding;
		tempBinding = nullptr;

		g_pGameInputMgr->m_EnabledDevices.push_back(DEVICE_TYPE_KEYBOARD);

		return true;
	}

	g_pLTClient->CPrint("[GameInputMgr::EnableDevice] Tried to enable non-supported device [%s]", pDeviceName);

	return false;
}

// Important note: pTriggerName is "RealName"
bool GameInputMgr::ClearBindings(InputMgr* pInputMgr, const char* pDeviceName, const char* pTriggerName)
{
	for (int i = 0; i < g_pGameInputMgr->m_pBindingList.size(); i++)
	{
		auto pBinding = g_pGameInputMgr->m_pBindingList.at(i);

		// Not our device!
		if (stricmp(pBinding->szDevice, pDeviceName) != 0)
		{
			continue;
		}

		// Hey it's our binding!
		if (stricmp(pBinding->pDeviceBinding->strRealName, pTriggerName) == 0)
		{
			g_pGameInputMgr->m_pBindingList.erase(g_pGameInputMgr->m_pBindingList.begin() + i);

			// Delete our Binding
			delete pBinding;
			pBinding = nullptr;
			return true;
		}
	}


	return false;
}

// Important note: pTriggerName is "RealName"
bool GameInputMgr::AddBinding(InputMgr* pInputMgr, const char* pDeviceName, const char* pTriggerName, const char* pActionName, float fRangeLow, float fRangeHigh)
{
	auto pAction = g_pGameInputMgr->FindAction(pActionName);

	if (!pAction)
	{
		g_pLTClient->CPrint("[GameInputMgr::AddBinding] Could not find action [%s] to create bind [%s] on device [%s]", pActionName, pTriggerName, pDeviceName);
		return false;
	}

	auto pDeviceBinding = new DeviceBinding();
	
	if (!pDeviceBinding)
	{
		g_pLTClient->CPrint("[GameInputMgr::AddBinding] Failed to create bind [%s] on device [%s]", pActionName, pTriggerName, pDeviceName);
		return false;
	}

	auto pBinding = new GIMBinding();

	if (!pBinding)
	{
		g_pLTClient->CPrint("[GameInputMgr::AddBinding] Failed to create bind [%s] on device [%s]", pActionName, pTriggerName, pDeviceName);

		delete pDeviceBinding;
		pDeviceBinding = nullptr;

		return false;
	}

	pBinding->bIsEnabled = true;

	pAction->nRangeHigh = fRangeHigh;
	pAction->nRangeLow  = fRangeLow;

	pDeviceBinding->pNext = nullptr;
	pDeviceBinding->pActionHead = pAction;
	pDeviceBinding->m_nObjectId = g_pGameInputMgr->GetActionCodeFromBindString(pTriggerName);
	pBinding->nDIK = pDeviceBinding->m_nObjectId;

	// These will be set if ScaleTrigger is ever called
	pDeviceBinding->nRangeScalePreCenterOffset = 0.0f;
	pDeviceBinding->nRangeScaleMin = 0.0f;
	pDeviceBinding->nRangeScaleMax = 0.0f;
	pDeviceBinding->nScale = 1.0f;

	LTStrCpy(pBinding->szDevice, pDeviceName, sizeof(pBinding->szDevice));
	LTStrCpy(pDeviceBinding->strDeviceName, pDeviceName, sizeof(pDeviceBinding->strDeviceName));
	// I will never stop cursing this betrayal.
	LTStrCpy(pDeviceBinding->strRealName, pTriggerName, sizeof(pDeviceBinding->strRealName));


	auto nDeviceType = g_pGameInputMgr->GetDeviceTypeFromName(pDeviceName);
	pBinding->nDeviceType = nDeviceType;

	if (nDeviceType == DEVICE_TYPE_KEYBOARD)
	{
		SDL_Scancode nScanCode = SDL_SCANCODE_UNKNOWN;
		try {
			nScanCode = g_mDInputToSDL.at(pDeviceBinding->m_nObjectId);
		}
		catch (...) // No scan code? Can't make a bind!
		{
			g_pLTClient->CPrint("[GameInputMgr::AddBinding] Failed to create bind [%s] on device [%s]", pActionName, pTriggerName, pDeviceName);

			delete pDeviceBinding;
			pDeviceBinding = nullptr;

			return false;
		}

		auto nKeyCode = SDL_GetKeyFromScancode(nScanCode);
		auto szKeyName = SDL_GetKeyName(nKeyCode);
		LTStrCpy(pDeviceBinding->strTriggerName, szKeyName, sizeof(pDeviceBinding->strTriggerName));
		LTStrCpy(pBinding->szName, szKeyName, sizeof(pBinding->szName));

		pBinding->bIsAxis = false;
		pBinding->bHasDIK = true;
		pBinding->nKeyboardScancode = nScanCode;
	}
	else if (nDeviceType == DEVICE_TYPE_MOUSE)
	{
		pBinding->bHasDIK = false;

		// TODO: This could be a map!
		if (stricmp("##x-axis", pTriggerName) == 0)
		{
			pBinding->bIsAxis = true;
			pBinding->nMouseAxis = SDL_MOUSE_AXIS_X;
			pBinding->nDIK = (uint32_t)MOUSE_X_AXIS;

			const char szName[] = "Axis X";
			LTStrCpy(pDeviceBinding->strTriggerName, szName, sizeof(pDeviceBinding->strTriggerName));
			LTStrCpy(pBinding->szName, szName, sizeof(pBinding->szName));
		}
		else if (stricmp("##y-axis", pTriggerName) == 0)
		{
			pBinding->bIsAxis = true;
			pBinding->nMouseAxis = SDL_MOUSE_AXIS_Y;
			pBinding->nDIK = (uint32_t)MOUSE_Y_AXIS;

			const char szName[] = "Axis Y";
			LTStrCpy(pDeviceBinding->strTriggerName, szName, sizeof(pDeviceBinding->strTriggerName));
			LTStrCpy(pBinding->szName, szName, sizeof(pBinding->szName));
		}
		else if (stricmp("##z-axis", pTriggerName) == 0)
		{
			pBinding->bIsAxis = true;
			pBinding->nMouseAxis = SDL_MOUSE_AXIS_WHEEL;
			pBinding->nDIK = (uint32_t)MOUSE_Z_AXIS;

			const char szName[] = "Wheel";
			LTStrCpy(pDeviceBinding->strTriggerName, szName, sizeof(pDeviceBinding->strTriggerName));
			LTStrCpy(pBinding->szName, szName, sizeof(pBinding->szName));
		}
		else if (stricmp("##3", pTriggerName) == 0)
		{
			pBinding->bIsAxis = false;
			pBinding->nMouseButton = SDL_MOUSE_BUTTON_LEFT;
			pBinding->nDIK = (uint32_t)MOUSE_LEFT_BUTTON;

			const char szName[] = "Left";
			LTStrCpy(pDeviceBinding->strTriggerName, szName, sizeof(pDeviceBinding->strTriggerName));
			LTStrCpy(pBinding->szName, szName, sizeof(pBinding->szName));
		}
		else if (stricmp("##4", pTriggerName) == 0)
		{
			pBinding->bIsAxis = false;
			pBinding->nMouseButton = SDL_MOUSE_BUTTON_RIGHT;
			pBinding->nDIK = (uint32_t)MOUSE_RIGHT_BUTTON;

			const char szName[] = "Right";
			LTStrCpy(pDeviceBinding->strTriggerName, szName, sizeof(pDeviceBinding->strTriggerName));
			LTStrCpy(pBinding->szName, szName, sizeof(pBinding->szName));
		}
		else if (stricmp("##5", pTriggerName) == 0)
		{
			pBinding->bIsAxis = false;
			pBinding->nMouseButton = SDL_MOUSE_BUTTON_MIDDLE;
			pBinding->nDIK = (uint32_t)MOUSE_MIDDLE_BUTTON;

			const char szName[] = "Middle";
			LTStrCpy(pDeviceBinding->strTriggerName, szName, sizeof(pDeviceBinding->strTriggerName));
			LTStrCpy(pBinding->szName, szName, sizeof(pBinding->szName));
		}

		pDeviceBinding->m_nObjectId = pBinding->nDIK;
	}
	// TODO: Gamepad!

	pBinding->pDeviceBinding = pDeviceBinding;
	g_pGameInputMgr->m_pBindingList.push_back(pBinding);

	return true;
}

bool GameInputMgr::ScaleTrigger(InputMgr* pInputMgr, const char* pDeviceName, const char* pTriggerName, float fScale, float fRangeScaleMin, float fRangeScaleMax, float fRangeScalePreCenterOffset)
{
	for (auto pBinding : g_pGameInputMgr->m_pBindingList)
	{
		if (pBinding->nDeviceType != g_pGameInputMgr->GetDeviceTypeFromName(pDeviceName))
		{
			continue;
		}

		// Not a typo, see every instance where I complain about pTriggerName not actually being strTriggerName
		if (stricmp(pBinding->pDeviceBinding->strRealName, pTriggerName) == 0)
		{
			pBinding->pDeviceBinding->nScale = fScale;
			pBinding->pDeviceBinding->nRangeScaleMin = fRangeScaleMin;
			pBinding->pDeviceBinding->nRangeScaleMax = fRangeScaleMax;
			pBinding->pDeviceBinding->nRangeScalePreCenterOffset = fRangeScalePreCenterOffset;
		}
	}

	return true;
}

DeviceBinding* GameInputMgr::GetDeviceBindings(uint32_t nDevice)
{
	DeviceBinding* pDeviceBindings = nullptr;

	for (auto pBinding : g_pGameInputMgr->m_pBindingList)
	{
		if (pBinding->nDeviceType != nDevice)
		{
			continue;
		}

		// Jake: I didn't realize they want to do some funky stuff between Get and Free
		// so we need copies.
		DeviceBinding* pDeviceBinding = new DeviceBinding();
		memcpy(pDeviceBinding, pBinding->pDeviceBinding, sizeof(DeviceBinding));

		if (pDeviceBindings)
		{
			pDeviceBinding->pNext = pDeviceBindings;
		}

		pDeviceBindings = pDeviceBinding;
	}

	return pDeviceBindings;
}

void GameInputMgr::FreeDeviceBindings(DeviceBinding* pBindings)
{
	DeviceBinding* pBinding = pBindings;
	while (pBinding)
	{
		auto pNext = pBinding->pNext;

		delete pBinding;
		pBinding = nullptr;

		pBinding = pNext;
	}

	return;
}

bool GameInputMgr::StartDeviceTrack(InputMgr* pMgr, uint32_t nDevices, uint32_t nBufferSize)
{

	if (nDevices & DEVICE_TYPE_KEYBOARD)
	{
		g_pGameInputMgr->m_DeviceTrackingList.push_back(DEVICE_TYPE_KEYBOARD);
	}
	if (nDevices & DEVICE_TYPE_MOUSE)
	{
		g_pGameInputMgr->m_DeviceTrackingList.push_back(DEVICE_TYPE_MOUSE);
	}

	return true;
}

bool GameInputMgr::TrackDevice(DeviceInput* pInputAttay, uint32_t* pInOut)
{
	int nArraySize = *pInOut;
	*pInOut = 0;

	SDL_PumpEvents();
	auto pKeys = SDL_GetKeyboardState(nullptr);
	auto pButtons = SDL_GetMouseState(nullptr, nullptr);

	for (auto nDeviceType : g_pGameInputMgr->m_DeviceTrackingList)
	{
		if (*pInOut > nArraySize)
		{
			break;
		}

		for (auto pBinding : g_pGameInputMgr->m_pAvailableObjects)
		{
			if (*pInOut > nArraySize)
			{
				break;
			}
			// We only care about this device's binds.
			if (nDeviceType != pBinding->nDeviceType)
			{
				continue;
			}

			// No special case, just direct DIK to SDL conversion!
			uint8_t nOn = 0;
			uint32_t nControlType = CONTROLTYPE_UNKNOWN;

			if (pBinding->nDeviceType == DEVICE_TYPE_KEYBOARD)
			{
				nOn = pKeys[pBinding->nKeyboardScancode];
				nControlType = CONTROLTYPE_KEY;
			}
			else if (pBinding->nDeviceType == DEVICE_TYPE_MOUSE)
			{
				nOn = (pButtons & SDL_BUTTON(pBinding->nMouseButton));
				nControlType = CONTROLTYPE_BUTTON;

				if (pBinding->bIsAxis && pBinding->nMouseAxis == SDL_MOUSE_AXIS_X)
				{
					nControlType = CONTROLTYPE_XAXIS;
				}
				else if (pBinding->bIsAxis && pBinding->nMouseAxis == SDL_MOUSE_AXIS_Y)
				{
					nControlType = CONTROLTYPE_YAXIS;
				}
				else if (pBinding->bIsAxis && pBinding->nMouseAxis == SDL_MOUSE_AXIS_WHEEL)
				{
					nOn = g_pGameInputMgr->GetWheelDelta();
					nControlType = CONTROLTYPE_ZAXIS;
				}
			}
			else if (pBinding->nDeviceType == DEVICE_TYPE_GAMEPAD)
			{
				// TODO: Implement SDL_GameControllerGetButton
			}

			if (nOn)
			{
				pInputAttay[*pInOut].m_DeviceType = nDeviceType;

				char szDeviceName[INPUTNAME_LEN];
				g_pGameInputMgr->GetDeviceName(nDeviceType, szDeviceName, sizeof(szDeviceName));
				LTStrCpy(pInputAttay[*pInOut].m_DeviceName, szDeviceName, sizeof(pInputAttay[*pInOut].m_DeviceName));

				pInputAttay[*pInOut].m_ControlType = nControlType;
				LTStrCpy(pInputAttay[*pInOut].m_ControlName, pBinding->szName, sizeof(pInputAttay[*pInOut].m_ControlName));

				pInputAttay[*pInOut].m_ControlCode = pBinding->nDIK;
				pInputAttay[*pInOut].m_nObjectId = pBinding->nDIK;

				pInputAttay[*pInOut].m_InputValue = 1;

				// ??? Maybe ???
				if (nControlType == CONTROLTYPE_ZAXIS)
				{
					pInputAttay[*pInOut].m_InputValue = g_pGameInputMgr->GetWheelDelta();
				}

				(*pInOut)++;
			}
		}
	}

	return true;
}

bool GameInputMgr::EndDeviceTrack()
{
	g_pGameInputMgr->m_DeviceTrackingList.clear();

	return true;
}

// Return a list of potential bindable keys!
// This use to be a lot neater, but now it's a mess.
DeviceObject* GameInputMgr::GetDeviceObjects(uint32_t nDeviceFlags)
{
	DeviceObject* pDeviceObjects = nullptr;
	char szDeviceName[INPUTNAME_LEN];
	LT_DeviceType nDeviceType = DEVICE_TYPE_UNKNOWN;

	for (auto pBinding : g_pGameInputMgr->m_pAvailableObjects)
	{
		DeviceObject* pDeviceObject = new DeviceObject();
		if (!pDeviceObject)
		{
			g_pLTClient->CPrint("[GameInputMgr::GetDeviceObjects] Failed to create device object.");
			break;
		}
		pDeviceObject->m_pNext = nullptr;

		char szDeviceName[INPUTNAME_LEN];
		int nDeviceType = DEVICE_TYPE_UNKNOWN;

		if (nDeviceFlags & DEVICE_TYPE_KEYBOARD && pBinding->nDeviceType == DEVICE_TYPE_KEYBOARD)
		{
			nDeviceType = DEVICE_TYPE_KEYBOARD;
			g_pGameInputMgr->GetDeviceName(nDeviceType, szDeviceName, sizeof(szDeviceName));

			LTStrCpy(pDeviceObject->m_DeviceName, szDeviceName, sizeof(pDeviceObject->m_DeviceName));
			pDeviceObject->m_DeviceType = nDeviceType;
			pDeviceObject->m_ObjectType = CONTROLTYPE_KEY;
			LTStrCpy(pDeviceObject->m_ObjectName, pBinding->szName, sizeof(pDeviceObject->m_ObjectName));
			pDeviceObject->m_nObjectId = pBinding->nDIK;
			pDeviceObject->m_RangeLow = 0.0f;
			pDeviceObject->m_RangeHigh = 0.0f;
		}
		
		if (nDeviceFlags & DEVICE_TYPE_MOUSE && pBinding->nDeviceType == DEVICE_TYPE_MOUSE)
		{
			nDeviceType = DEVICE_TYPE_MOUSE;
			g_pGameInputMgr->GetDeviceName(nDeviceType, szDeviceName, sizeof(szDeviceName));
			LTStrCpy(pDeviceObject->m_DeviceName, szDeviceName, sizeof(pDeviceObject->m_DeviceName));
			pDeviceObject->m_DeviceType = nDeviceType;
			pDeviceObject->m_ObjectType = CONTROLTYPE_BUTTON;
			LTStrCpy(pDeviceObject->m_ObjectName, pBinding->szName, sizeof(pDeviceObject->m_ObjectName));
			pDeviceObject->m_nObjectId = pBinding->nDIK;
			pDeviceObject->m_RangeLow = 0.0f;
			pDeviceObject->m_RangeHigh = 0.0f;

			// Special cases...
			if (pBinding->bIsAxis)
			{
				if (pBinding->nMouseAxis == SDL_MOUSE_AXIS_X)
				{
					pDeviceObject->m_RangeLow = -1000.0f;
					pDeviceObject->m_RangeHigh = 1000.0f;
					pDeviceObject->m_ObjectType = CONTROLTYPE_XAXIS;
				}
				else if (pBinding->nMouseAxis == SDL_MOUSE_AXIS_Y)
				{
					pDeviceObject->m_RangeLow = -1000.0f;
					pDeviceObject->m_RangeHigh = 1000.0f;
					pDeviceObject->m_ObjectType = CONTROLTYPE_YAXIS;
				}
				else if (pBinding->nMouseAxis == SDL_MOUSE_AXIS_WHEEL)
				{
					pDeviceObject->m_RangeLow = -255.0f;
					pDeviceObject->m_RangeHigh = 255.0f;
					pDeviceObject->m_ObjectType = CONTROLTYPE_ZAXIS;
				}
			}
		}
		else if (nDeviceFlags & DEVICE_TYPE_GAMEPAD && pBinding->nDeviceType == DEVICE_TYPE_GAMEPAD)
		{

		}

		// This binding isn't needed, so delete our object and continue
		// Really I shouldn't even be making the object in the first place...
		if (nDeviceType == DEVICE_TYPE_UNKNOWN)
		{
			delete pDeviceObject;
			pDeviceObject = nullptr;
			continue;
		}

		if (pDeviceObjects)
		{
			pDeviceObject->m_pNext = pDeviceObjects;
		}

		pDeviceObjects = pDeviceObject;
	}

	return pDeviceObjects;
}

void GameInputMgr::FreeDeviceObjects(DeviceObject* pList)
{
	while (pList)
	{
		auto pNext = pList->m_pNext;

		delete pList;
		pList = nullptr;

		pList = pNext;
	}
}

bool GameInputMgr::GetDeviceName(uint32_t nDeviceType, char* szBuffer, uint32_t nBufferSize)
{
	switch (nDeviceType)
	{
	case DEVICETYPE_GAMEPAD:
		LTStrCpy(szBuffer, "Gamepad", nBufferSize);
		break;
	case DEVICETYPE_JOYSTICK:
		LTStrCpy(szBuffer, "Joystick", nBufferSize);
		break;
	case DEVICETYPE_KEYBOARD:
		LTStrCpy(szBuffer, "Keyboard", nBufferSize);
		break;
	case DEVICETYPE_MOUSE:
		LTStrCpy(szBuffer, "Mouse", nBufferSize);
		break;
	case DEVICETYPE_UNKNOWN:
		return false;
	}

	return true;
}

bool GameInputMgr::GetDeviceObjectName(const char* szDeviceName, uint32_t nDeviceObjectID, char* szDeviceObjectName, uint32_t nDeviceObjectNameLength)
{
	auto nDeviceType = g_pGameInputMgr->GetDeviceTypeFromName(szDeviceName);

	for (auto pBinding : g_pGameInputMgr->m_pAvailableObjects)
	{
		if (nDeviceType != pBinding->nDeviceType)
		{
			continue;
		}

		if (nDeviceObjectID == pBinding->nDIK)
		{
			LTStrCpy(szDeviceObjectName, pBinding->szName, nDeviceObjectNameLength);
			return true;
		}

	}

	memset(szDeviceObjectName, 0, nDeviceObjectNameLength);

	return false;
}

bool GameInputMgr::IsDeviceEnabled(const char* szDeviceName)
{
	if (stricmp("##mouse", szDeviceName) == 0)
	{
		return true;
	}

	if (stricmp("##keyboard", szDeviceName) == 0)
	{
		return true;
	}

	g_pLTClient->CPrint("[GameInputMgr::IsDeviceEnabled] Tried to enable non-supported device [%s]", szDeviceName);

	return false;
}

bool GameInputMgr::ShowDeviceObjects(const char* szDeviceName)
{
	return false;
}

bool GameInputMgr::ShowInputDevices()
{
	return true;
}

//
// Non-interface functions
//

void GameInputMgr::SetRelativeMode(bool bOn)
{
	m_bRelativeMode = bOn;

	if (bOn)
	{
		auto nSupported = SDL_SetRelativeMouseMode(SDL_TRUE);
		auto error = SDL_GetError();

		if (nSupported != 0)
		{
			g_pLTClient->CPrint("Error: %s", error);
			g_pLTClient->CPrint("!! WARNING !! Relative Mouse Mode isn't supported!");
		}

		return;
	}
	
	SDL_SetRelativeMouseMode(SDL_FALSE);
}

GameAction* GameInputMgr::FindAction(const char* szActionName)
{
	for (auto pAction : m_pActionList)
	{
		if (stricmp(pAction->strActionName, szActionName) == 0)
		{
			return pAction;
		}
	}
	return nullptr;
}

void GameInputMgr::GenerateReverseMap()
{
	// Alreaaady filled
	if (g_mSDLToDInput.empty())
	{
		for (auto pair : g_mDInputToSDL)
		{
			g_mSDLToDInput.insert(std::make_pair(pair.second, pair.first));
		}
	}

	if (g_mDInputMouseToSDLMouse.empty())
	{
		for (auto pair : g_mSDLMouseToDInputMouse)
		{
			g_mDInputMouseToSDLMouse.insert(std::make_pair(pair.second, pair.first));
		}
	}
}

LT_DeviceType GameInputMgr::GetDeviceTypeFromName(const char* szDeviceName)
{
	/*
	DEVICETYPE_KEYBOARD    = 1,
	DEVICETYPE_MOUSE       = 2,
	DEVICETYPE_JOYSTICK    = 4,
	DEVICETYPE_GAMEPAD     = 8,
	DEVICETYPE_UNKNOWN     = 16
	*/

	// We only support mouse + keyboard right now! 

	if (stricmp("keyboard", szDeviceName) == 0 || stricmp("##keyboard", szDeviceName) == 0)
	{
		return DEVICE_TYPE_KEYBOARD;
	}

	if (stricmp("mouse", szDeviceName) == 0 || stricmp("##mouse", szDeviceName) == 0)
	{
		return DEVICE_TYPE_MOUSE;
	}

	return DEVICE_TYPE_UNKNOWN;
}

int GameInputMgr::GetActionCodeFromBindString(const char* szTriggerName)
{
	std::string sDIK = szTriggerName;
	try {
		return std::stoi(sDIK.substr(2));
	}
	catch (std::invalid_argument e)
	{
		return -999;
	}
}
