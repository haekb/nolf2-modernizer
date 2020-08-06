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

GameInputMgr::GameInputMgr()
{
	g_pGameInputMgr = this;
	m_pBindings = nullptr;
	m_pActions = nullptr;
	m_nWheelDelta = 0;
	m_bRelativeMode = false;

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

	bool bEnd = true;
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



}

bool GameInputMgr::IsInitted(InputMgr* pInputMgr)
{
	return false;
}

void GameInputMgr::ListDevices(InputMgr* pInputMgr)
{
}

uint32_t GameInputMgr::PlayJoystickEffect(InputMgr* pInputMgr, const char* szEffectName, float x, float y)
{
	return 0;
}

void GameInputMgr::ReadInput(InputMgr* pInputMgr, uint8_t* pActionsOn, float fAxisOffsets[3])
{
	auto pBinding = g_pGameInputMgr->m_pBindings;
	int nDeltaX = 0, nDeltaY = 0;

	// Only track mouse if relative mode is enabled
	if (g_pGameInputMgr->GetRelativeMode())
	{
		SDL_GetRelativeMouseState(&nDeltaX, &nDeltaY);
	}

	auto pKeys = SDL_GetKeyboardState(0);
	auto pButtons = SDL_GetMouseState(nullptr, nullptr);

	while (pBinding)
	{
		auto pDeviceBinding = pBinding->pDeviceBinding;

		if (!pDeviceBinding)
		{
			pBinding = pBinding->pNext;

			continue;
		}

		// Note: This stuff is all special cases.
		// Only track mouse if relative mode is enabled
		if (g_pGameInputMgr->GetRelativeMode())
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
			if (pBinding->bWheel)
			{
				auto nWheelDelta = g_pGameInputMgr->GetWheelDelta();
				if (nWheelDelta >= WHEEL_DELTA && pDeviceBinding->nRangeScaleMin > 0.0)
				{
					pActionsOn[pDeviceBinding->pActionHead->nActionCode] |= 1;
				}
				else if (nWheelDelta <= -WHEEL_DELTA && pDeviceBinding->nRangeScaleMin < 0.0)
				{
					pActionsOn[pDeviceBinding->pActionHead->nActionCode] |= 1;
				}
			}

			// X-Axis
			if (pDeviceBinding->pActionHead->nActionCode == -1)
			{
				nCurrentMouseX += nDeltaX;
				fAxisOffsets[0] = (float)(nCurrentMouseX - nPreviousMouseX) * nScale;
				nPreviousMouseX = nCurrentMouseX;
			}

			// Y-Axis
			if (pDeviceBinding->pActionHead->nActionCode == -2)
			{
				nCurrentMouseY += nDeltaY;
				fAxisOffsets[1] = (float)(nCurrentMouseY - nPreviousMouseY) * nScale;
				nPreviousMouseY = nCurrentMouseY;
			}

			// Z-Axis ???
			fAxisOffsets[2] = 0.0f;
		}

		uint8_t nOn = 0;

		if (pBinding->nDeviceType == DEVICETYPE_KEYBOARD)
		{
			nOn = pKeys[pBinding->nKeyboardScancode];
		}
		else if (pBinding->nDeviceType == DEVICETYPE_MOUSE)
		{
			nOn = (pButtons & SDL_BUTTON(pBinding->nMouseButton));
		}

		pActionsOn[pDeviceBinding->pActionHead->nActionCode] |= nOn;

		pBinding = pBinding->pNext;
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
	pAction->pNext = g_pGameInputMgr->m_pActions;
	g_pGameInputMgr->m_pActions = pAction;
}

bool GameInputMgr::EnableDevice(InputMgr* pInputMgr, const char* pDeviceName)
{
	if (stricmp("##mouse", pDeviceName) == 0)
	{
		return true;
	}

	if (stricmp("##keyboard", pDeviceName) == 0)
	{
		return true;
	}

	g_pLTClient->CPrint("[GameInputMgr::EnableDevice] Tried to enable non-supported device [%s]", pDeviceName);

	return false;
}

bool GameInputMgr::ClearBindings(InputMgr* pInputMgr, const char* pDeviceName, const char* pTriggerName)
{
	return false;
}

bool GameInputMgr::AddBinding(InputMgr* pInputMgr, const char* pDeviceName, const char* pTriggerName, const char* pActionName, float fRangeLow, float fRangeHigh)
{
	DeviceBinding* pDeviceBinding = new DeviceBinding();

	if (!pDeviceBinding)
	{
		return false;
	}

	GameAction* pAction = g_pGameInputMgr->FindAction(pActionName);

	if (!pAction)
	{
		g_pLTClient->CPrint("[GameInputMgr::AddBinding] Action [%s] doesn't exist!", pActionName);
		delete pDeviceBinding;
		return false;
	}

	// Fill our device binding
	LTStrCpy(pDeviceBinding->strDeviceName, pDeviceName, sizeof(pDeviceBinding->strDeviceName));
	LTStrCpy(pDeviceBinding->strRealName, pActionName, sizeof(pDeviceBinding->strRealName));
	LTStrCpy(pDeviceBinding->strTriggerName, pTriggerName, sizeof(pDeviceBinding->strTriggerName));
	pDeviceBinding->nRangeScaleMin = fRangeLow;
	pDeviceBinding->nRangeScaleMin = fRangeHigh;
	pDeviceBinding->nScale = 1.0f;
	pDeviceBinding->pActionHead = pAction;
	pDeviceBinding->pNext = nullptr;

	GIMBinding* pBinding = new GIMBinding();

	if (!pBinding)
	{
		delete pDeviceBinding;
		return false;
	}

	// Ok now we fill our shell, this just holds some cached data + the actual binding
	int nActionCode = g_pGameInputMgr->GetIntFromTriggerName(pTriggerName);

	pBinding->nDIK = nActionCode;

	pBinding->nDeviceType = g_pGameInputMgr->GetDeviceTypeFromName(pDeviceName);

	switch (pBinding->nDeviceType)
	{
	case DEVICETYPE_KEYBOARD:
		pBinding->nKeyboardScancode = (SDL_Scancode)g_pGameInputMgr->GetScancodeFromActionCode(nActionCode);
		break;
	case DEVICETYPE_MOUSE:
		// Hack for mouse wheel
		if (nActionCode == -999 && stricmp("##z-axis", pTriggerName) == 0)
		{
			pBinding->bWheel = true;
			pBinding->nMouseButton = -1;
			break;
		}

		pBinding->nMouseButton = (SDL_Scancode)g_pGameInputMgr->GetMouseButtonFromActionCode(nActionCode);
		break;
	}

	LTStrCpy(pBinding->szDevice, pDeviceName, sizeof(pBinding->szDevice));
	LTStrCpy(pBinding->szName, pActionName, sizeof(pBinding->szName));

	// Hope this is okay!
	pDeviceBinding->m_nObjectId = nActionCode;
	pBinding->pDeviceBinding = pDeviceBinding;

	pBinding->pNext = g_pGameInputMgr->m_pBindings;
	g_pGameInputMgr->m_pBindings = pBinding;

	return true;
}

bool GameInputMgr::ScaleTrigger(InputMgr* pInputMgr, const char* pDeviceName, const char* pTriggerName, float fScale, float fRangeScaleMin, float fRangeScaleMax, float fRangeScalePreCenterOffset)
{
	auto pBinding = g_pGameInputMgr->m_pBindings;
	while (pBinding)
	{
		if (pBinding->nDeviceType != g_pGameInputMgr->GetDeviceTypeFromName(pDeviceName))
		{
			pBinding = pBinding->pNext;
			continue;
		}

		if (stricmp(pBinding->pDeviceBinding->strTriggerName, pTriggerName) == 0)
		{
			pBinding->pDeviceBinding->nScale = fScale;
			pBinding->pDeviceBinding->nRangeScaleMin = fRangeScaleMin;
			pBinding->pDeviceBinding->nRangeScaleMax = fRangeScaleMax;
			pBinding->pDeviceBinding->nRangeScalePreCenterOffset = fRangeScalePreCenterOffset;
		}

		pBinding = pBinding->pNext;
	}

	return true;
}

DeviceBinding* GameInputMgr::GetDeviceBindings(uint32_t nDevice)
{
	auto pBinding = g_pGameInputMgr->m_pBindings;

	DeviceBinding* pDeviceBinding = nullptr;

	while (pBinding)
	{
		if (pBinding->nDeviceType != nDevice)
		{
			pBinding = pBinding->pNext;

			continue;
		}

		pDeviceBinding = pBinding->pDeviceBinding;

		if (pDeviceBinding)
		{
			// Cycle to the next for both our fun binding pointers
			pDeviceBinding = pDeviceBinding->pNext;
		}
		pBinding = pBinding->pNext;
	}

	return pDeviceBinding;
}

void GameInputMgr::FreeDeviceBindings(DeviceBinding* pBindings)
{
	// No need to free them, they're just references to our m_pBinding->DeviceBindings
	return;
}

bool GameInputMgr::StartDeviceTrack(InputMgr* pMgr, uint32_t nDevices, uint32_t nBufferSize)
{
	return false;
}

bool GameInputMgr::TrackDevice(DeviceInput* pInputAttay, uint32_t* pInOut)
{
	return false;
}

bool GameInputMgr::EndDeviceTrack()
{
	return false;
}

// Determines if joysticks/gamepads are available!!!
DeviceObject* GameInputMgr::GetDeviceObjects(uint32_t nDeviceFlags)
{
	// Only mice are supported right now!
	if (nDeviceFlags != DEVICETYPE_MOUSE)
	{
		return nullptr;
	}

	auto pBinding = g_pGameInputMgr->m_pBindings;

	DeviceObject* pDeviceObjects = nullptr;

	while (pBinding)
	{
		if (pBinding->nDeviceType != nDeviceFlags)
		{
			pBinding = pBinding->pNext;

			continue;
		}

		std::string sTriggerName = pBinding->pDeviceBinding->strTriggerName;

		DeviceObject* pDeviceObject = new DeviceObject();

		// Oh memory error? Let's break..
		if (!pDeviceObject)
		{
			break;
		}
		
		pDeviceObject->m_DeviceType = DEVICETYPE_MOUSE;
		
		int nObjectType = CONTROLTYPE_UNKNOWN;

		// TODO: This can be a map
		if (sTriggerName.compare("##x-axis") == 0)
		{
			nObjectType = CONTROLTYPE_XAXIS;
		}
		else if (sTriggerName.compare("##y-axis") == 0)
		{
			nObjectType = CONTROLTYPE_YAXIS;
		}
		else if (sTriggerName.compare("##z-axis") == 0)
		{
			nObjectType = CONTROLTYPE_ZAXIS;
		}
		pDeviceObject->m_ObjectType = nObjectType;
		pDeviceObject->m_nObjectId = pBinding->pDeviceBinding->m_nObjectId;

		// Strings!

		// Object Name (x-axis, y-axis, z-axis)
		LTStrCpy(pDeviceObject->m_ObjectName, sTriggerName.substr(2).c_str(), sizeof(pDeviceObject->m_ObjectName));

		// Device Name (mouse!)
		char szDeviceName[INPUTNAME_LEN];
		g_pGameInputMgr->GetDeviceName(DEVICETYPE_MOUSE, szDeviceName, sizeof(szDeviceName));
		LTStrCpy(pDeviceObject->m_DeviceName, szDeviceName, sizeof(pDeviceObject->m_DeviceName));

		pDeviceObject->m_RangeLow = pBinding->pDeviceBinding->nRangeScaleMin;
		pDeviceObject->m_RangeHigh = pBinding->pDeviceBinding->nRangeScaleMax;
		
		
		pDeviceObject->m_pNext = pDeviceObjects;
		pDeviceObjects = pDeviceObject;

		pBinding = pBinding->pNext;
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
	auto nDeviecID = g_pGameInputMgr->GetDeviceTypeFromName(szDeviceName);
	GameInputMgr::GetDeviceName(nDeviecID,szDeviceObjectName, nDeviceObjectNameLength);
	return true;
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
	auto pAction = m_pActions;

	while (pAction)
	{
		if (stricmp(pAction->strActionName, szActionName) == 0)
		{
			return pAction;
		}

		pAction = pAction->pNext;
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

int GameInputMgr::GetDeviceTypeFromName(const char* szDeviceName)
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
		return DEVICETYPE_KEYBOARD;
	}

	if (stricmp("mouse", szDeviceName) == 0 || stricmp("##mouse", szDeviceName) == 0)
	{
		return DEVICETYPE_MOUSE;
	}

	return DEVICETYPE_UNKNOWN;
}

int GameInputMgr::GetScancodeFromActionCode(int nActionCode)
{
	try {
		return g_mDInputToSDL.at(nActionCode);
	}
	catch (...)
	{
		return 0;
	}
}

int GameInputMgr::GetMouseButtonFromActionCode(int nActionCode)
{
	try {
		return g_mDInputMouseToSDLMouse.at(nActionCode);
	}
	catch (...)
	{
		return 0;
	}
}

int GameInputMgr::GetIntFromTriggerName(const char* szTriggerName)
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
