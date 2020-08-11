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

// Helper macro
#define BIND_FUNC(x) m_pInputMgr->x = GameInputMgr::x

// Pointer to the Input struct in the engine.
// If you're building the game code against a different engine version, 
// you may have to find this again.
constexpr auto ENGINE_INPUT_MGR_PTR = 0x0059abc8;

// Config Name, Name, DIK Code, SDL Code, Is Axis?
const TempBinding g_ControllerBindings[] = {
	// Gamepad buttons - DIK codes can't be zero!!
	{ "##1", "A", SDL_CONTROLLER_BUTTON_A + 1, SDL_CONTROLLER_BUTTON_A,  false },
	{ "##2", "B", SDL_CONTROLLER_BUTTON_B + 1, SDL_CONTROLLER_BUTTON_B,  false },
	{ "##3", "X", SDL_CONTROLLER_BUTTON_X + 1, SDL_CONTROLLER_BUTTON_X,  false },
	{ "##4", "Y", SDL_CONTROLLER_BUTTON_Y + 1, SDL_CONTROLLER_BUTTON_Y,  false },
	{ "##5", "Back", SDL_CONTROLLER_BUTTON_BACK + 1, SDL_CONTROLLER_BUTTON_BACK, false },
	{ "##6", "Guide", SDL_CONTROLLER_BUTTON_GUIDE + 1, SDL_CONTROLLER_BUTTON_GUIDE, false },
	{ "##7", "Start", SDL_CONTROLLER_BUTTON_START + 1, SDL_CONTROLLER_BUTTON_START, false },
	{ "##8", "Left Stick", SDL_CONTROLLER_BUTTON_LEFTSTICK + 1, SDL_CONTROLLER_BUTTON_LEFTSTICK, false },
	{ "##9", "Right Stick", SDL_CONTROLLER_BUTTON_RIGHTSTICK + 1, SDL_CONTROLLER_BUTTON_RIGHTSTICK, false },
	{ "##10", "Left Shoulder", SDL_CONTROLLER_BUTTON_LEFTSHOULDER + 1, SDL_CONTROLLER_BUTTON_LEFTSHOULDER, false },
	{ "##11", "Right Shoulder", SDL_CONTROLLER_BUTTON_RIGHTSHOULDER + 1, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER, false },
	{ "##12", "DPad Up", SDL_CONTROLLER_BUTTON_DPAD_UP + 1, SDL_CONTROLLER_BUTTON_DPAD_UP, false },
	{ "##13", "DPad Down", SDL_CONTROLLER_BUTTON_DPAD_DOWN + 1, SDL_CONTROLLER_BUTTON_DPAD_DOWN, false },
	{ "##14", "DPad Left", SDL_CONTROLLER_BUTTON_DPAD_LEFT + 1, SDL_CONTROLLER_BUTTON_DPAD_LEFT, false },
	{ "##15", "DPad Right", SDL_CONTROLLER_BUTTON_DPAD_RIGHT + 1, SDL_CONTROLLER_BUTTON_DPAD_RIGHT, false },
	// Gamepad axis - DIK codes still can't be zero!
	{ "##16", "Left Axis X", SDL_CONTROLLER_AXIS_LEFTX + 16, SDL_CONTROLLER_AXIS_LEFTX, true },
	{ "##17", "Left Axis Y", SDL_CONTROLLER_AXIS_LEFTY + 16, SDL_CONTROLLER_AXIS_LEFTY, true },
	{ "##18", "Right Axis X", SDL_CONTROLLER_AXIS_RIGHTX + 16, SDL_CONTROLLER_AXIS_RIGHTX, true },
	{ "##19", "Right Axis Y", SDL_CONTROLLER_AXIS_RIGHTY + 16, SDL_CONTROLLER_AXIS_RIGHTY, true },
	{ "##20", "Left Trigger", SDL_CONTROLLER_AXIS_TRIGGERLEFT + 16, SDL_CONTROLLER_AXIS_TRIGGERLEFT, true },
	{ "##21", "Right Trigger", SDL_CONTROLLER_AXIS_TRIGGERRIGHT + 16, SDL_CONTROLLER_AXIS_TRIGGERRIGHT, true },
};

// Config Name, Name, DIK Code, SDL Code, Is Axis?
const TempBinding g_MouseBindings[] = {
	// Mouse Buttons
	{ "##3", "Left", MOUSE_LEFT_BUTTON, SDL_MOUSE_BUTTON_LEFT,  false },
	{ "##4", "Right", MOUSE_RIGHT_BUTTON, SDL_MOUSE_BUTTON_RIGHT,  false } ,
	{ "##5", "Middle", MOUSE_MIDDLE_BUTTON, SDL_MOUSE_BUTTON_MIDDLE,  false },
	// Mouse Axis
	{ "##x-axis", "Axis X", MOUSE_X_AXIS, SDL_MOUSE_AXIS_X, true },
	{ "##y-axis", "Axis Y", MOUSE_Y_AXIS, SDL_MOUSE_AXIS_Y, true },
	{ "##z-axis", "Wheel", MOUSE_Z_AXIS + 1, SDL_MOUSE_AXIS_WHEEL, true },
};

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
	m_pGamepad = nullptr;

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

	for (auto nDevice : g_pGameInputMgr->m_EnabledDevices)
	{
		if (nDevice == DEVICE_TYPE_GAMEPAD && g_pGameInputMgr->m_pGamepad)
		{
			SDL_GameControllerClose(g_pGameInputMgr->m_pGamepad);
			g_pGameInputMgr->m_pGamepad = nullptr;
		}
	}
	g_pGameInputMgr->m_EnabledDevices.clear();

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

	SDL_PumpEvents();
	auto pKeys = SDL_GetKeyboardState(nullptr);
	auto pButtons = SDL_GetMouseState(nullptr, nullptr);
	auto pGamepadButtons = g_pGameInputMgr->GetGamepadButtonValues();
	auto pGamepadAxis = g_pGameInputMgr->GetGamepadAxisValues();

	for (auto pBinding : g_pGameInputMgr->m_pBindingList)
	{
		auto pDeviceBinding = pBinding->pDeviceBinding;
		if (!pDeviceBinding)
		{
			continue;
		}

		uint8_t nOn = 0;

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
		else if (pBinding->bIsAxis && pBinding->nDeviceType == DEVICE_TYPE_GAMEPAD)
		{
			//
			// Handle Axis
			//
			static float nCurrentMouseX = 0;
			static float nCurrentMouseY = 0;
			static float nPreviousMouseX = 0;
			static float nPreviousMouseY = 0;
			float nScale = pDeviceBinding->nScale;

			auto nValue = pGamepadAxis[pBinding->nGamepadAxis].nValue;

			bool bPassesDeadzone = nValue > 5000 || nValue < -5000;
			bool bPassesTriggerDeadzone = nValue > 100;

			// Handle axis
			if (pDeviceBinding->pActionHead->nActionCode == -1 && bPassesDeadzone)
			{
				//g_pLTClient->CPrint("Axis-X RAW: %d", nValue);

				float fValue = (float)nValue * 0.0001f;

				nCurrentMouseX += fValue;
				fAxisOffsets[0] = (float)(nCurrentMouseX - nPreviousMouseX) * nScale;
				nPreviousMouseX = nCurrentMouseX;

				// Skip regular actions
				continue;
			}

			if (pDeviceBinding->pActionHead->nActionCode == -2 && bPassesDeadzone)
			{
				//g_pLTClient->CPrint("Axis-Y RAW: %d", nValue);

				float fValue = (float)nValue * 0.0001f;

				nCurrentMouseY += fValue;
				fAxisOffsets[1] = (float)(nCurrentMouseY - nPreviousMouseY) * nScale;
				nPreviousMouseY = nCurrentMouseY;

				// Skip regular actions
				continue;
			}
			
			g_pLTClient->CPrint("fAxisOffset %f/%f/%f", fAxisOffsets[0], fAxisOffsets[1], fAxisOffsets[2]);

			// Left Axis X
			if (pBinding->nGamepadAxis == SDL_CONTROLLER_AXIS_LEFTX && bPassesDeadzone)
			{
				nOn = 1;
			}

			// Left Axis Y
			if (pBinding->nGamepadAxis == SDL_CONTROLLER_AXIS_LEFTY && bPassesDeadzone)
			{
				nOn = 1;
			}

			// Right Axis X
			if (pBinding->nGamepadAxis == SDL_CONTROLLER_AXIS_RIGHTX && bPassesDeadzone)
			{
				nOn = 1;
			}

			// Right Axis Y
			if (pBinding->nGamepadAxis == SDL_CONTROLLER_AXIS_RIGHTY && bPassesDeadzone)
			{
				nOn = 1;
			}

			// Left Trigger
			if (pBinding->nGamepadAxis == SDL_CONTROLLER_AXIS_TRIGGERLEFT && bPassesTriggerDeadzone)
			{
				nOn = 1;
			}

			// Right Trigger
			if (pBinding->nGamepadAxis == SDL_CONTROLLER_AXIS_TRIGGERRIGHT && bPassesTriggerDeadzone)
			{
				nOn = 1;
			}


		}



		if (pBinding->nDeviceType == DEVICE_TYPE_KEYBOARD)
		{
			continue;
			nOn = pKeys[pBinding->nKeyboardScancode];
		}
		else if (pBinding->nDeviceType == DEVICE_TYPE_MOUSE && !pBinding->bIsAxis)
		{
			nOn = (pButtons & SDL_BUTTON(pBinding->nMouseButton));
		}
		else if (pBinding->nDeviceType == DEVICE_TYPE_GAMEPAD && !pBinding->bIsAxis)
		{
			nOn = pGamepadButtons.at((int)pBinding->nGamepadButton).nValue;
		}

		pActionsOn[pDeviceBinding->pActionHead->nActionCode] |= nOn;
	}
}

bool GameInputMgr::FlushInputBuffers(InputMgr* pInputMgr)
{
	SDL_PumpEvents();

	return true;
}

LTRESULT GameInputMgr::ClearInput()
{
	SDL_PumpEvents();

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
	if (stricmp("##mouse", pDeviceName) == 0 || stricmp("Mouse", pDeviceName) == 0)
	{
		if (bMouseAlreadyInit)
		{
			return true;
		}

		// Create our list of bindable mice objects
		nDeviceType = DEVICE_TYPE_MOUSE;
		g_pGameInputMgr->GetDeviceName(nDeviceType, szDeviceName, sizeof(szDeviceName));

		// Create a template to hold basic constant info
		GIMBinding* pTemplateBinding = new GIMBinding();

		// These are constants
		pTemplateBinding->bIsEnabled = true;
		pTemplateBinding->bHasDIK = false;
		pTemplateBinding->nDeviceType = nDeviceType;
		pTemplateBinding->pDeviceBinding = nullptr;
		LTStrCpy(pTemplateBinding->szDevice, szDeviceName, sizeof(pTemplateBinding->szName));

		for (int i = 0; i < SDL_arraysize(g_MouseBindings); i++)
		{
			GIMBinding* pBinding = new GIMBinding();
			memcpy(pBinding, pTemplateBinding, sizeof(GIMBinding));

			LTStrCpy(pBinding->szName, g_MouseBindings[i].szName, sizeof(pBinding->szName));
			pBinding->nDIK = g_MouseBindings[i].nDIK;
			pBinding->bIsAxis = g_MouseBindings[i].bIsAxis;

			if (!g_MouseBindings[i].bIsAxis)
			{
				pBinding->nMouseButton = (SDL_MouseButton)g_MouseBindings[i].nSDL;
			}
			else // Axis!
			{
				pBinding->nMouseAxis = (SDL_MouseAxis)g_MouseBindings[i].nSDL;
			}

			g_pGameInputMgr->m_pAvailableObjects.push_back(pBinding);
		}

		// Clear our template pointer
		delete pTemplateBinding;
		pTemplateBinding = nullptr;

		g_pGameInputMgr->m_EnabledDevices.push_back(DEVICE_TYPE_MOUSE);

		return true;
	}

	bool bKeyboardAlreadyInit = std::find(g_pGameInputMgr->m_EnabledDevices.begin(), g_pGameInputMgr->m_EnabledDevices.end(), DEVICE_TYPE_KEYBOARD) != g_pGameInputMgr->m_EnabledDevices.end();
	if (stricmp("##keyboard", pDeviceName) == 0 || stricmp("Keyboard", pDeviceName) == 0)
	{
		if (bKeyboardAlreadyInit)
		{
			return true;
		}

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

	bool bGamepadAlreadyInit = std::find(g_pGameInputMgr->m_EnabledDevices.begin(), g_pGameInputMgr->m_EnabledDevices.end(), DEVICE_TYPE_GAMEPAD) != g_pGameInputMgr->m_EnabledDevices.end();
	if (stricmp("##gamepad", pDeviceName) == 0 || stricmp("Gamepad", pDeviceName) == 0)
	{
		if (bGamepadAlreadyInit)
		{
			return true;
		}

		nDeviceType = DEVICE_TYPE_GAMEPAD;
		g_pGameInputMgr->GetDeviceName(nDeviceType, szDeviceName, sizeof(szDeviceName));

		// If we haven't, init gamecontroller and haptic systems.
		if (!SDL_WasInit(SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC))
		{
			SDL_Init(SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC);
		}

		// Open it! 
		SDL_GameController* pGamepad = nullptr;
		for (int i = 0; i < SDL_NumJoysticks(); ++i) {
			if (SDL_IsGameController(i)) {
				pGamepad = SDL_GameControllerOpen(i);
				if (pGamepad) {
					break;
				}
				else {
					g_pLTClient->CPrint("[GameInputMgr::EnableDevice] Could not open gamepad [%d] due to error [%s]", i, SDL_GetError());
				}
			}
		}

		// Create a template to hold basic constant info
		GIMBinding* pTemplateBinding = new GIMBinding();

		// These are constants
		pTemplateBinding->bIsEnabled = true;
		pTemplateBinding->bHasDIK = false;
		pTemplateBinding->nDeviceType = nDeviceType;
		pTemplateBinding->pDeviceBinding = nullptr;
		LTStrCpy(pTemplateBinding->szDevice, szDeviceName, sizeof(pTemplateBinding->szName));

		for (int i = 0; i < SDL_arraysize(g_ControllerBindings); i++)
		{
			GIMBinding* pBinding = new GIMBinding();
			memcpy(pBinding, pTemplateBinding, sizeof(GIMBinding));

			LTStrCpy(pBinding->szName, g_ControllerBindings[i].szName, sizeof(pBinding->szName));
			pBinding->nDIK = g_ControllerBindings[i].nDIK;
			pBinding->bIsAxis = g_ControllerBindings[i].bIsAxis;

			if (!g_ControllerBindings[i].bIsAxis)
			{
				pBinding->nGamepadButton = (SDL_GameControllerButton)g_ControllerBindings[i].nSDL;
			}
			else // Axis!
			{
				pBinding->nGamepadAxis = (SDL_GameControllerAxis)g_ControllerBindings[i].nSDL;

			}

			g_pGameInputMgr->m_pAvailableObjects.push_back(pBinding);
		}

		// Clear our template pointer
		delete pTemplateBinding;
		pTemplateBinding = nullptr;

		// Take ownership, and add gamepad to our list of enabled devices
		g_pGameInputMgr->m_pGamepad = pGamepad;
		g_pGameInputMgr->m_EnabledDevices.push_back(DEVICE_TYPE_GAMEPAD);

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

		for (int i = 0; i < SDL_arraysize(g_MouseBindings); i++)
		{
			if (stricmp(g_MouseBindings[i].szCompareName, pTriggerName) == 0)
			{
				LTStrCpy(pDeviceBinding->strTriggerName, g_MouseBindings[i].szName, sizeof(pDeviceBinding->strTriggerName));
				LTStrCpy(pBinding->szName, g_MouseBindings[i].szName, sizeof(pBinding->szName));

				pBinding->bIsAxis = g_MouseBindings[i].bIsAxis;
				pBinding->nDIK = (uint32_t)g_MouseBindings[i].nDIK;

				if (!g_MouseBindings[i].bIsAxis)
				{
					pBinding->nMouseButton = (SDL_MouseButton)g_MouseBindings[i].nSDL;
				}
				else
				{
					pBinding->nMouseAxis = (SDL_MouseAxis)g_MouseBindings[i].nSDL;
				}
				break;
			}
		}

		pDeviceBinding->m_nObjectId = pBinding->nDIK;
	}
	else if (nDeviceType == DEVICE_TYPE_GAMEPAD)
	{
		pBinding->bHasDIK = false;

		for (int i = 0; i < SDL_arraysize(g_ControllerBindings); i++)
		{
			if (stricmp(g_ControllerBindings[i].szCompareName, pTriggerName) == 0)
			{
				LTStrCpy(pDeviceBinding->strTriggerName, g_ControllerBindings[i].szName, sizeof(pDeviceBinding->strTriggerName));
				LTStrCpy(pBinding->szName, g_ControllerBindings[i].szName, sizeof(pBinding->szName));

				pBinding->bIsAxis = g_ControllerBindings[i].bIsAxis;
				pBinding->nDIK = (uint32_t)g_ControllerBindings[i].nDIK;

				if (!g_ControllerBindings[i].bIsAxis)
				{
					pBinding->nGamepadButton = (SDL_GameControllerButton)g_ControllerBindings[i].nSDL;
				}
				else
				{
					pBinding->nGamepadAxis = (SDL_GameControllerAxis)g_ControllerBindings[i].nSDL;
				}
				break;
			}
		}

		pDeviceBinding->m_nObjectId = pBinding->nDIK;
	}

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
	if (nDevices & DEVICE_TYPE_GAMEPAD)
	{
		g_pGameInputMgr->m_DeviceTrackingList.push_back(DEVICE_TYPE_GAMEPAD);
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
	auto pGamepadButtons = g_pGameInputMgr->GetGamepadButtonValues();
	auto pGamepadAxis = g_pGameInputMgr->GetGamepadAxisValues();

	for (auto nDeviceType : g_pGameInputMgr->m_DeviceTrackingList)
	{
		if (*pInOut > nArraySize)
		{
			break;
		}

		char szDeviceName[INPUTNAME_LEN];
		g_pGameInputMgr->GetDeviceName(nDeviceType, szDeviceName, sizeof(szDeviceName));

		if (!g_pGameInputMgr->IsDeviceEnabled(szDeviceName))
		{
			g_pGameInputMgr->EnableDevice((InputMgr*)g_pGameInputMgr, szDeviceName);
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
				auto nButton = pGamepadButtons.at((int)pBinding->nGamepadButton).nValue;

				if (!pBinding->bIsAxis)
				{
					nOn = nButton;
					nControlType = CONTROLTYPE_BUTTON;
				}
				else
				{
					auto nAxis = pGamepadAxis.at((int)pBinding->nGamepadAxis).nValue;

					// FIXME: This should be a deadzone value!
					if (nAxis < 5000 && nAxis > -5000)
					{
						continue;
					}

					if (pBinding->nGamepadAxis == SDL_CONTROLLER_AXIS_TRIGGERLEFT)
					{
						nOn = nAxis;
						nControlType = CONTROLTYPE_ZAXIS;
					}
					else if (pBinding->nGamepadAxis == SDL_CONTROLLER_AXIS_TRIGGERRIGHT)
					{
						nOn = nAxis;
						nControlType = CONTROLTYPE_RZAXIS;
					}
					else if (pBinding->nGamepadAxis == SDL_CONTROLLER_AXIS_LEFTX)
					{
						nOn = nAxis;
						nControlType = CONTROLTYPE_XAXIS;
					}
					else if (pBinding->nGamepadAxis == SDL_CONTROLLER_AXIS_LEFTY)
					{
						nOn = nAxis;
						nControlType = CONTROLTYPE_YAXIS;
					}
					else if (pBinding->nGamepadAxis == SDL_CONTROLLER_AXIS_RIGHTX)
					{
						nOn = nAxis;
						nControlType = CONTROLTYPE_RXAXIS;
					}
					else if (pBinding->nGamepadAxis == SDL_CONTROLLER_AXIS_RIGHTY)
					{
						nOn = nAxis;
						nControlType = CONTROLTYPE_RYAXIS;
					}
				}
			}

			if (nOn)
			{
				pInputAttay[*pInOut].m_DeviceType = nDeviceType;

				LTStrCpy(pInputAttay[*pInOut].m_DeviceName, szDeviceName, sizeof(pInputAttay[*pInOut].m_DeviceName));

				pInputAttay[*pInOut].m_ControlType = nControlType;
				LTStrCpy(pInputAttay[*pInOut].m_ControlName, pBinding->szName, sizeof(pInputAttay[*pInOut].m_ControlName));

				pInputAttay[*pInOut].m_ControlCode = pBinding->nDIK;
				pInputAttay[*pInOut].m_nObjectId = pBinding->nDIK;

				pInputAttay[*pInOut].m_InputValue = 1;

				// Pass over wheel delta
				if (pBinding->nDeviceType == DEVICE_TYPE_MOUSE && nControlType == CONTROLTYPE_ZAXIS)
				{
					pInputAttay[*pInOut].m_InputValue = g_pGameInputMgr->GetWheelDelta();
				}
				// Pass over trigger amount
				else if (pBinding->nDeviceType == DEVICE_TYPE_GAMEPAD && (nControlType != CONTROLTYPE_UNKNOWN && nControlType <= CONTROLTYPE_SLIDER))
				{
					pInputAttay[*pInOut].m_InputValue = pGamepadAxis.at((int)pBinding->nGamepadAxis).nValue;
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

	// We need to make sure things are enabled first!
	if (nDeviceFlags & DEVICE_TYPE_KEYBOARD)
	{
		g_pGameInputMgr->GetDeviceName(DEVICE_TYPE_KEYBOARD, szDeviceName, sizeof(szDeviceName));
		if (!g_pGameInputMgr->IsDeviceEnabled(szDeviceName))
		{
			g_pGameInputMgr->EnableDevice((InputMgr*)g_pGameInputMgr, szDeviceName);
		}
	}
	if (nDeviceFlags & DEVICE_TYPE_MOUSE)
	{
		g_pGameInputMgr->GetDeviceName(DEVICE_TYPE_MOUSE, szDeviceName, sizeof(szDeviceName));
		if (!g_pGameInputMgr->IsDeviceEnabled(szDeviceName))
		{
			g_pGameInputMgr->EnableDevice((InputMgr*)g_pGameInputMgr, szDeviceName);
		}
	}
	if (nDeviceFlags & DEVICE_TYPE_GAMEPAD)
	{
		g_pGameInputMgr->GetDeviceName(DEVICE_TYPE_GAMEPAD, szDeviceName, sizeof(szDeviceName));
		if (!g_pGameInputMgr->IsDeviceEnabled(szDeviceName))
		{
			g_pGameInputMgr->EnableDevice((InputMgr*)g_pGameInputMgr, szDeviceName);
		}
	}

	for (auto pBinding : g_pGameInputMgr->m_pAvailableObjects)
	{
		DeviceObject* pDeviceObject = new DeviceObject();
		if (!pDeviceObject)
		{
			g_pLTClient->CPrint("[GameInputMgr::GetDeviceObjects] Failed to create device object.");
			break;
		}
		pDeviceObject->m_pNext = nullptr;

		//
		// Keyboard
		//
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
		
		//
		// Mouse
		//
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
		
		//
		// Gamepad
		//
		if (nDeviceFlags & DEVICE_TYPE_GAMEPAD && pBinding->nDeviceType == DEVICE_TYPE_GAMEPAD)
		{
			nDeviceType = DEVICE_TYPE_GAMEPAD;
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
				if (pBinding->nGamepadAxis == SDL_CONTROLLER_AXIS_LEFTX)
				{
					pDeviceObject->m_RangeLow = -32768.0f;
					pDeviceObject->m_RangeHigh = 32768.0f;
					pDeviceObject->m_ObjectType = CONTROLTYPE_XAXIS;
				}
				else if (pBinding->nMouseAxis == SDL_CONTROLLER_AXIS_LEFTY)
				{
					pDeviceObject->m_RangeLow = -32768.0f;
					pDeviceObject->m_RangeHigh = 32768.0f;
					pDeviceObject->m_ObjectType = CONTROLTYPE_YAXIS;
				}
				if (pBinding->nGamepadAxis == SDL_CONTROLLER_AXIS_RIGHTX)
				{
					pDeviceObject->m_RangeLow = -32768.0f;
					pDeviceObject->m_RangeHigh = 32768.0f;
					pDeviceObject->m_ObjectType = CONTROLTYPE_RXAXIS;
				}
				else if (pBinding->nMouseAxis == SDL_CONTROLLER_AXIS_RIGHTY)
				{
					pDeviceObject->m_RangeLow = -32768.0f;
					pDeviceObject->m_RangeHigh = 32768.0f;
					pDeviceObject->m_ObjectType = CONTROLTYPE_RYAXIS;
				}
				else if (pBinding->nMouseAxis == SDL_CONTROLLER_AXIS_TRIGGERLEFT)
				{
					pDeviceObject->m_RangeLow = 0.0f;
					pDeviceObject->m_RangeHigh = 32768.0f;
					pDeviceObject->m_ObjectType = CONTROLTYPE_ZAXIS;
				}
				else if (pBinding->nMouseAxis == SDL_CONTROLLER_AXIS_TRIGGERLEFT)
				{
					pDeviceObject->m_RangeLow = 0.0f;
					pDeviceObject->m_RangeHigh = 32768.0f;
					pDeviceObject->m_ObjectType = CONTROLTYPE_RZAXIS;
				}
			}
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
		LTStrCpy(szBuffer, "[Unknown]", nBufferSize);
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
	if (stricmp("##mouse", szDeviceName) == 0 || stricmp("Mouse", szDeviceName) == 0)
	{
		return true;
	}

	if (stricmp("##keyboard", szDeviceName) == 0 || stricmp("Keyboard", szDeviceName) == 0)
	{
		return true;
	}

	if (stricmp("##gamepad", szDeviceName) == 0 || stricmp("Gamepad", szDeviceName) == 0)
	{
		return std::find(g_pGameInputMgr->m_EnabledDevices.begin(), g_pGameInputMgr->m_EnabledDevices.end(), DEVICE_TYPE_GAMEPAD) != g_pGameInputMgr->m_EnabledDevices.end();
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
	if (stricmp("keyboard", szDeviceName) == 0 || stricmp("##keyboard", szDeviceName) == 0)
	{
		return DEVICE_TYPE_KEYBOARD;
	}

	if (stricmp("mouse", szDeviceName) == 0 || stricmp("##mouse", szDeviceName) == 0)
	{
		return DEVICE_TYPE_MOUSE;
	}

	if (stricmp("gamepad", szDeviceName) == 0 || stricmp("##gamepad", szDeviceName) == 0)
	{
		return DEVICE_TYPE_GAMEPAD;
	}

	return DEVICE_TYPE_UNKNOWN;
}

int GameInputMgr::GetActionCodeFromBindString(const char* szTriggerName)
{
	std::string sDIK = szTriggerName;
	try {
		return std::stoi(sDIK.substr(2));
	}
	catch (...)
	{
		return -999;
	}
}

std::vector<ButtonValue> GameInputMgr::GetGamepadButtonValues()
{
	std::vector<ButtonValue> buttonValues;

	if (!m_pGamepad)
	{
		return buttonValues;
	}

	for (int i = SDL_CONTROLLER_BUTTON_A; i < SDL_CONTROLLER_BUTTON_MAX; i++)
	{
		SDL_GameControllerButton nButton = (SDL_GameControllerButton)i;
		auto nValue = SDL_GameControllerGetButton(m_pGamepad, nButton);
		ButtonValue buttonValue = { nButton, nValue };
		buttonValues.push_back(buttonValue);
	}

	return buttonValues;
}

std::vector<AxisValue> GameInputMgr::GetGamepadAxisValues()
{
	std::vector<AxisValue> axisValues;

	if (!m_pGamepad)
	{
		return axisValues;
	}

	for (int i = SDL_CONTROLLER_AXIS_LEFTX; i < SDL_CONTROLLER_AXIS_MAX; i++)
	{
		SDL_GameControllerAxis nAxis = (SDL_GameControllerAxis)i;
		auto nValue = SDL_GameControllerGetAxis(m_pGamepad, nAxis);
		AxisValue buttonValue = { nAxis, (float)nValue };
		axisValues.push_back(buttonValue);
	}

	return axisValues;
}
