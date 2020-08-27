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
constexpr auto ENGINE_SAVE_INPUT_PTR = 0x00597a30;

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
	{ "##z-axis", "Wheel",  MOUSE_Z_AXIS, SDL_MOUSE_AXIS_WHEEL, true },
};

const std::map<LT_DeviceType, const char*> g_DeviceTypeToConfigName = {
	{ DEVICE_TYPE_MOUSE, "##mouse" },
	{ DEVICE_TYPE_KEYBOARD, "##keyboard" },
	{ DEVICE_TYPE_GAMEPAD, "##gamepad" },
	{ DEVICE_TYPE_JOYSTICK, "##joystick" },
	{ DEVICE_TYPE_UNKNOWN, "##unknown" },
};

//#define USE_OLD_INPUT

/// <summary>
/// Game Input Manager
/// DirectInput8 is funky, and provides the weirdest mouse movements ever!!
/// So we sneakily replace the struct/class/whatever pointer with our own built in SDL2.
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
	// Call Term here, because we're still in CShell scope
	g_pGameInputMgr->Term((InputMgr*)g_pGameInputMgr);
}

void GameInputMgr::ReplaceBindings()
{
	BIND_FUNC(Init);
	// Don't bind Term as CShell is no longer in scope
	//BIND_FUNC(Term);
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

	// Not sure if I'm replacing this function pointer correctly, but it works well enough!
	intptr_t** pEngineSaveInput = (intptr_t**)ENGINE_SAVE_INPUT_PTR;
	*pEngineSaveInput = (intptr_t*)&GameInputMgr::SaveBindings;
}

//
// InputMgr functions
//

bool GameInputMgr::Init(InputMgr* pInputMgr, intptr_t* pState)
{	
	// Load up our controls!
	g_pLTClient->ReadConfigFile("controls.cfg");

	return true;
}

void GameInputMgr::Term(InputMgr* pInputMgr)
{
	if (!pInputMgr)
	{
		return;
	}

	// Save our autoexec.cfg. This will also create a controls.cfg!
	g_pLTClient->WriteConfigFile("autoexec.cfg");

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
	// If we're reading input during loading, some funky crashes occasionally happen
	// So just ignore this until the world is good and loaded!
	if (!g_pGameClientShell->IsWorldLoaded())
	{
		return;
	}

	const int nActionMaxIterations = 255;
	int nActionIterations = 0;

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

	fAxisOffsets[0] = 0.0f;
	fAxisOffsets[1] = 0.0f;
	fAxisOffsets[2] = 0.0f;

	for (auto pBinding : g_pGameInputMgr->m_pBindingList)
	{
		// Uhhh..don't actually read non-enabled bindings!
		if (!pBinding->bIsEnabled)
		{
			continue;
		}

		auto pDeviceBinding = pBinding->pDeviceBinding;
		if (!pDeviceBinding)
		{
			continue;
		}

		nActionIterations = 0;
		GameAction* pAction = pDeviceBinding->pActionHead;

		while (pAction)
		{
			uint8_t nOn = 0;

#ifdef _DEBUG
			// I never actually needed this, but just in case...
			nActionIterations++;
			if (nActionIterations > nActionMaxIterations)
			{
				// ERROR: An infinite loop has occured!
				__debugbreak();
			}
#endif

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
					if (nWheelDelta >= WHEEL_DELTA && pAction->nRangeLow > 0.0)
					{
						pActionsOn[pAction->nActionCode] |= 1;
					}
					else if (nWheelDelta <= -WHEEL_DELTA && pAction->nRangeLow < 0.0)
					{
						pActionsOn[pAction->nActionCode] |= 1;
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

				static float fAxisXAccel = 0.0f;
				static float fAxisYAccel = 0.0f;

				auto nValue = pGamepadAxis[pBinding->nGamepadAxis].nValue;

				bool bPassesSpecialDeadzone = nValue > 4000 || nValue < -4000;
				bool bPassesDeadzone = nValue > pAction->nRangeLow;
				bool bPassesTriggerDeadzone = nValue > 100;

				// Oh, it's a negative range value? Then check it again.
				if (pAction->nRangeLow < 0)
				{
					bPassesDeadzone = nValue < pAction->nRangeLow;
				}

				// Handle axis
				if (pAction->nActionCode == -1)
				{
					if (bPassesSpecialDeadzone)
					{
						//g_pLTClient->CPrint("Axis-X RAW: %d", nValue);
						fAxisXAccel += 0.0005f * g_pLTClient->GetFrameTime();

						fAxisXAccel = Min(0.001f, fAxisXAccel);

						float fValue = (float)nValue * (0.0001f + fAxisXAccel);

						nCurrentMouseX += fValue;
						fAxisOffsets[0] = (float)(nCurrentMouseX - nPreviousMouseX) * nScale;
						nPreviousMouseX = nCurrentMouseX;
					}
					else
					{
						fAxisXAccel = 0.0f;
					}

					// Move onto the next action!
					pAction = pAction->pNext;

					// Skip regular actions
					continue;

				}
				else if (pAction->nActionCode == -2)
				{
					if (bPassesSpecialDeadzone)
					{
						//g_pLTClient->CPrint("Axis-Y RAW: %d", nValue);
						fAxisYAccel += 0.0005f * g_pLTClient->GetFrameTime();

						fAxisYAccel = Min(0.001f, fAxisYAccel);

						float fValue = (float)nValue * (0.0001f + fAxisYAccel);

						nCurrentMouseY += fValue;
						fAxisOffsets[1] = (float)(nCurrentMouseY - nPreviousMouseY) * nScale;
						nPreviousMouseY = nCurrentMouseY;
					}
					else
					{
						fAxisYAccel = 0.0f;
					}

					// Move onto the next action!
					pAction = pAction->pNext;

					// Skip regular actions
					continue;
				}
				// pActionsOn is a UNSIGNED 8-bit int. It seems to overflow and bleed into another console-related array
				// That's no good! So just eat any values below 0, and log 'em if we're in debug mode.
				else if (pAction->nActionCode < 0)
				{
#ifdef _DEBUG
					SDL_Log("Unknown special action code called! Eating it, so we don't crash!!! The action code %d. Passes trigger? %d Passes deadzone? %d", pAction->nActionCode, bPassesTriggerDeadzone, bPassesDeadzone);
#endif
					// Move onto the next action!
					pAction = pAction->pNext;

					// Skip regular actions
					continue;
				}

				if (
					(
						pBinding->nGamepadAxis == SDL_CONTROLLER_AXIS_TRIGGERLEFT || pBinding->nGamepadAxis == SDL_CONTROLLER_AXIS_TRIGGERRIGHT)
					&& bPassesTriggerDeadzone
					)
				{
					nOn = 1;
				}
				else if (bPassesDeadzone)
				{
					nOn = 1;
				}
			}

			if (pBinding->nDeviceType == DEVICE_TYPE_KEYBOARD)
			{
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

			pActionsOn[pAction->nActionCode] |= nOn;

			// Move onto the next action!
			pAction = pAction->pNext;
		}
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
	auto pAction = g_pGameInputMgr->FindAction(pActionName);

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

	g_pLTClient->CPrint("[GameInputMgr::AddAction] ActionName: [%s] ", pActionName);

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
	auto nDeviceType = g_pGameInputMgr->GetDeviceTypeFromName(pDeviceName);

	bool bAlreadyEnabled = g_pGameInputMgr->IsDeviceEnabled(pDeviceName);

	if (bAlreadyEnabled)
	{
		return true;
	}

	g_pLTClient->CPrint("[GameInputMgr::EnableDevice] Enabling device [%s]", pDeviceName);

	//
	// Mouse
	// 
	if (nDeviceType == DEVICE_TYPE_MOUSE)
	{
		// Create our list of bindable mice objects
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

		g_pGameInputMgr->m_EnabledDevices.push_back(nDeviceType);

		return true;
	}

	//
	// Keyboard
	//
	if (nDeviceType == DEVICE_TYPE_KEYBOARD)
	{
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

		g_pGameInputMgr->m_EnabledDevices.push_back(nDeviceType);

		return true;
	}

	if (nDeviceType == DEVICE_TYPE_GAMEPAD)
	{
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

		if (!pGamepad)
		{
			return false;
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

			if (g_ControllerBindings[i].bIsAxis)
			{
				pBinding->nGamepadAxis = (SDL_GameControllerAxis)g_ControllerBindings[i].nSDL;

			}
			else // Button!
			{
				pBinding->nGamepadButton = (SDL_GameControllerButton)g_ControllerBindings[i].nSDL;
			}

			g_pGameInputMgr->m_pAvailableObjects.push_back(pBinding);
		}

		// Clear our template pointer
		delete pTemplateBinding;
		pTemplateBinding = nullptr;

		// Take ownership, and add gamepad to our list of enabled devices
		g_pGameInputMgr->m_pGamepad = pGamepad;
		g_pGameInputMgr->m_EnabledDevices.push_back(nDeviceType);

		return true;
	}

	g_pLTClient->CPrint("[GameInputMgr::EnableDevice] Tried to enable non-supported device [%s]", pDeviceName);

	return false;
}

bool GameInputMgr::ClearBindings(InputMgr* pInputMgr, const char* pDeviceName, const char* pRealName)
{
	g_pLTClient->CPrint("[GameInputMgr::ClearBindings] Device: [%s] | BindName: [%s]", pDeviceName, pRealName);
	for (int i = 0; i < g_pGameInputMgr->m_pBindingList.size(); i++)
	{
		auto pBinding = g_pGameInputMgr->m_pBindingList.at(i);

		// Not our device!
		if (stricmp(pBinding->szDevice, pDeviceName) != 0)
		{
			continue;
		}

		// Hey it's our binding!
		if (stricmp(pBinding->pDeviceBinding->strRealName, pRealName) == 0)
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

bool GameInputMgr::AddBinding(InputMgr* pInputMgr, const char* pDeviceName, const char* pRealName, const char* pActionName, float fRangeLow, float fRangeHigh)
{
	// We need to check if we have an action
	auto pActionTemp = g_pGameInputMgr->FindAction(pActionName);

	if (!pActionTemp)
	{
		g_pLTClient->CPrint("[GameInputMgr::AddBinding] Could not find action [%s] to create bind [%s] on device [%s]", pActionName, pRealName, pDeviceName);
		return false;
	}

	// Copy the action, this copy will just be for us! 
	auto pAction = new GameAction();

	if (!pAction)
	{
		g_pLTClient->CPrint("[GameInputMgr::AddBinding] Could copy action [%s] to create bind [%s] on device [%s]", pActionName, pRealName, pDeviceName);
		return false;
	}

	memcpy(pAction, pActionTemp, sizeof(GameAction));

	auto nDeviceType = g_pGameInputMgr->GetDeviceTypeFromName(pDeviceName);
	auto bEnabled = IsDeviceEnabled(pDeviceName);

	DeviceBinding* pDeviceBinding = nullptr;
	GIMBinding* pBinding = nullptr;

	g_pLTClient->CPrint("[GameInputMgr::AddBinding] Device: [%s] | BindName: [%s] | ActionName: [%s] | RangeLow/RangeHigh: [%f/%f]", pDeviceName, pRealName, pActionName, fRangeLow, fRangeHigh);

	for (auto pSearchBinding : g_pGameInputMgr->m_pBindingList)
	{
		if (pSearchBinding->nDeviceType != nDeviceType)
		{
			continue;
		}

		if (stricmp(pSearchBinding->pDeviceBinding->strRealName, pRealName) != 0)
		{
			continue;
		}

		// Oh we found it! Update a values, and move on.
		g_pLTClient->CPrint("[GameInputMgr::AddBinding] Duplicate found [%s] for action [%s] | Device [%s]", pRealName, pActionName, pDeviceName);

		pBinding = pSearchBinding;
		pDeviceBinding = pBinding->pDeviceBinding;
		
		// Okay check the actions for this device binding, make sure we don't already have it in the list
		GameAction* pCheckAction = pDeviceBinding->pActionHead;
		while (pCheckAction)
		{

			if (stricmp(pCheckAction->strActionName, pActionName) == 0)
			{
				g_pLTClient->CPrint("[GameInputMgr::AddBinding] REAL duplicate found [%s] for action [%s] | Device [%s]", pRealName, pActionName, pDeviceName);
				// Ok we don't even need to update the list, just continue.
				// Clean up pAction tho..
				delete pAction;

				return true;
			}

			pCheckAction = pCheckAction->pNext;
		}

		pBinding->bIsEnabled = bEnabled;
		pAction->nRangeHigh = fRangeHigh;
		pAction->nRangeLow = fRangeLow;
		pAction->pNext = pBinding->pDeviceBinding->pActionHead;
		pBinding->pDeviceBinding->pActionHead = pAction;


		return true;
	}

	// If we couldn't find the binding, create a new one!
	if (!pBinding)
	{
		pDeviceBinding = new DeviceBinding();

		if (!pDeviceBinding)
		{
			g_pLTClient->CPrint("[GameInputMgr::AddBinding] Failed to create bind [%s] on device [%s]", pActionName, pRealName, pDeviceName);
			return false;
		}

		pDeviceBinding->pActionHead = nullptr;
		pDeviceBinding->pNext = nullptr;

		pBinding = new GIMBinding();

		if (!pBinding)
		{
			g_pLTClient->CPrint("[GameInputMgr::AddBinding] Failed to create bind [%s] on device [%s]", pActionName, pRealName, pDeviceName);

			delete pDeviceBinding;
			pDeviceBinding = nullptr;

			return false;
		}
	}

	pBinding->bIsEnabled = bEnabled;

	pAction->nRangeHigh = fRangeHigh;
	pAction->nRangeLow = fRangeLow;
	pAction->pNext = pDeviceBinding->pActionHead;

	pDeviceBinding->pNext = nullptr;
	pDeviceBinding->pActionHead = pAction;
	pDeviceBinding->m_nObjectId = g_pGameInputMgr->GetActionCodeFromBindString(pRealName);
	pBinding->nDIK = pDeviceBinding->m_nObjectId;

	// These will be set if ScaleTrigger is ever called
	pDeviceBinding->nRangeScalePreCenterOffset = 0.0f;
	pDeviceBinding->nRangeScaleMin = 0.0f;
	pDeviceBinding->nRangeScaleMax = 0.0f;
	pDeviceBinding->nScale = 1.0f;

	LTStrCpy(pBinding->szDevice, pDeviceName, sizeof(pBinding->szDevice));
	LTStrCpy(pDeviceBinding->strDeviceName, pDeviceName, sizeof(pDeviceBinding->strDeviceName));
	// I will never stop cursing this betrayal.
	LTStrCpy(pDeviceBinding->strRealName, pRealName, sizeof(pDeviceBinding->strRealName));


	pBinding->nDeviceType = nDeviceType;

	if (nDeviceType == DEVICE_TYPE_KEYBOARD)
	{
		SDL_Scancode nScanCode = SDL_SCANCODE_UNKNOWN;
		try {
			nScanCode = g_mDInputToSDL.at(pDeviceBinding->m_nObjectId);
		}
		catch (...) // No scan code? Can't make a bind!
		{
			g_pLTClient->CPrint("[GameInputMgr::AddBinding] Failed to create bind [%s] on device [%s]", pActionName, pRealName, pDeviceName);

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
			if (stricmp(g_MouseBindings[i].szCompareName, pRealName) == 0)
			{
				LTStrCpy(pDeviceBinding->strTriggerName, g_MouseBindings[i].szName, sizeof(pDeviceBinding->strTriggerName));
				LTStrCpy(pBinding->szName, g_MouseBindings[i].szName, sizeof(pBinding->szName));

				pBinding->bIsAxis = g_MouseBindings[i].bIsAxis;
				pBinding->nDIK = g_MouseBindings[i].nDIK;

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
			if (stricmp(g_ControllerBindings[i].szCompareName, pRealName) == 0)
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

bool GameInputMgr::ScaleTrigger(InputMgr* pInputMgr, const char* pDeviceName, const char* pRealName, float fScale, float fRangeScaleMin, float fRangeScaleMax, float fRangeScalePreCenterOffset)
{
	for (auto pBinding : g_pGameInputMgr->m_pBindingList)
	{
		if (pBinding->nDeviceType != g_pGameInputMgr->GetDeviceTypeFromName(pDeviceName))
		{
			continue;
		}

		if (stricmp(pBinding->pDeviceBinding->strRealName, pRealName) == 0)
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


		// Ok we also need to copy over actions
		GameAction* pAction = nullptr;
		auto pActionTemp = pDeviceBinding->pActionHead;
		while (pActionTemp)
		{
			auto pNext = new GameAction();
			memcpy(pNext, pActionTemp, sizeof(GameAction));

			pNext->pNext = pAction;
			pAction = pNext;

			pActionTemp = pActionTemp->pNext;
		}
		pDeviceBinding->pActionHead = pAction;

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
		auto pAction = pBinding->pActionHead;
		while (pAction)
		{
			auto pNextAction = pAction->pNext;
			delete pAction;

			pAction = pNextAction;
		}
		

		auto pNext = pBinding->pNext;

		delete pBinding;

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

DeviceObject* GameInputMgr::GetDeviceObjects(uint32_t nDeviceFlags)
{
	DeviceObject* pDeviceObjects = nullptr;
	char szDeviceName[INPUTNAME_LEN];
	LT_DeviceType nDeviceType = DEVICE_TYPE_UNKNOWN;

	// We need to make sure things are enabled first!
	if (nDeviceFlags & DEVICE_TYPE_KEYBOARD)
	{
		LTStrCpy(szDeviceName, g_DeviceTypeToConfigName.at(DEVICE_TYPE_KEYBOARD), sizeof(szDeviceName));
		if (!g_pGameInputMgr->IsDeviceEnabled(szDeviceName))
		{
			g_pGameInputMgr->EnableDevice((InputMgr*)g_pGameInputMgr, szDeviceName);
		}
	}
	if (nDeviceFlags & DEVICE_TYPE_MOUSE)
	{
		LTStrCpy(szDeviceName, g_DeviceTypeToConfigName.at(DEVICE_TYPE_MOUSE), sizeof(szDeviceName));
		if (!g_pGameInputMgr->IsDeviceEnabled(szDeviceName))
		{
			g_pGameInputMgr->EnableDevice((InputMgr*)g_pGameInputMgr, szDeviceName);
		}
	}
	if (nDeviceFlags & DEVICE_TYPE_GAMEPAD)
	{
		LTStrCpy(szDeviceName, g_DeviceTypeToConfigName.at(DEVICE_TYPE_GAMEPAD), sizeof(szDeviceName));
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
	auto szConfigName = g_DeviceTypeToConfigName.at((LT_DeviceType)nDeviceType);
	LTStrCpy(szBuffer, szConfigName, nBufferSize);
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
	auto nDeviceType = g_pGameInputMgr->GetDeviceTypeFromName(szDeviceName);
	return std::find(g_pGameInputMgr->m_EnabledDevices.begin(), g_pGameInputMgr->m_EnabledDevices.end(), nDeviceType) != g_pGameInputMgr->m_EnabledDevices.end();
}

bool GameInputMgr::ShowDeviceObjects(const char* szDeviceName)
{
	return true;
}

bool GameInputMgr::ShowInputDevices()
{
	return true;
}

void GameInputMgr::SaveBindings(FILE* pFileIgnore)
{
	FILE* pFile;
	long size;

	pFile = fopen("controls.cfg", "w");
	if (pFile == NULL)
	{
		// Die silently
	}
	else
	{
		for (auto pAction : g_pGameInputMgr->m_pActionList)
		{
			fprintf(pFile, "AddAction %s %d\n", pAction->strActionName, pAction->nActionCode);
		}

		// Use this map to keep track of enabled device lines
		// You should only have one enabledevice line per device!
		std::map<std::string, bool> mEnabledDevices = {};

		// This is a copy, it can't be global because of silly scope reasons
		const std::map<LT_DeviceType, const char*> mDeviceNames = {
			{ DEVICE_TYPE_MOUSE, "##mouse" },
			{ DEVICE_TYPE_KEYBOARD, "##keyboard" },
			{ DEVICE_TYPE_GAMEPAD, "##gamepad" },
			{ DEVICE_TYPE_JOYSTICK, "##joystick" },
			{ DEVICE_TYPE_UNKNOWN, "##unknown" },
		};
		// Some special DIK codes need to be translated to specific strings
		std::map<int, std::string> mSpecialKeyTranslation = {
			{-1, "x-axis"},
			{-2, "y-axis"},
			{-3, "z-axis"}
		};
		std::string sEnableDeviceFormat = "enabledevice \"%s\"\n";

		// Note a bind can have multiple actions tied!
		// You must cap this off with \n!
		std::string sBindFormat = "rangebind \"%s\" \"%s\"";
		std::string sBindActionFormat = " %f %f \"%s\"";

		// Only if scale != 1.0
		std::string sScaleFormat = "scale \"%s\" \"%s\" %f\n";
		for (auto pBinding : g_pGameInputMgr->m_pBindingList)
		{
			std::string sDeviceName = mDeviceNames.at(pBinding->nDeviceType);
			// Add enabledevice line if needed
			if (!mEnabledDevices[sDeviceName])
			{
				fprintf(pFile, sEnableDeviceFormat.c_str(), sDeviceName.c_str());
				mEnabledDevices[sDeviceName] = true;
			}

			if (!pBinding->pDeviceBinding)
			{
				continue;
			}

			// rangebind "<device>" "<DIK Code>"
			std::string nDIK = "";

			auto sBindKey = mSpecialKeyTranslation[(int)pBinding->nDIK];
			if (sBindKey.empty())
			{
				sBindKey = std::to_string((int)pBinding->nDIK);
			}
			nDIK = "##" + sBindKey;

			fprintf(pFile, sBindFormat.c_str(), sDeviceName.c_str(), nDIK.c_str());

			auto pAction = pBinding->pDeviceBinding->pActionHead;
			while (pAction)
			{
				// 0.0 0.0 "<Action>"
				fprintf(pFile, sBindActionFormat.c_str(), pAction->nRangeLow, pAction->nRangeHigh, pAction->strActionName);

				pAction = pAction->pNext;
			}
			fprintf(pFile, "\n");

			if (pBinding->pDeviceBinding->nScale != 1.0f)
			{
				fprintf(pFile, sScaleFormat.c_str(), sDeviceName.c_str(), nDIK.c_str(), pBinding->pDeviceBinding->nScale);
			}

		}

		fclose(pFile);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// Non-interface functions
//
/////////////////////////////////////////////////////////////////////////////////////////

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

LT_DeviceType GameInputMgr::GetDeviceTypeFromName(const char* szDeviceName)
{
	if (stricmp("##keyboard", szDeviceName) == 0)
	{
		return DEVICE_TYPE_KEYBOARD;
	}

	if (stricmp("##mouse", szDeviceName) == 0)
	{
		return DEVICE_TYPE_MOUSE;
	}

	if (stricmp("##gamepad", szDeviceName) == 0)
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
		// Hardcoded fun
		if (stricmp("##x-axis", szTriggerName) == 0)
		{
			return -1;
		}
		else if (stricmp("##y-axis", szTriggerName) == 0)
		{
			return -2;
		}
		else if (stricmp("##z-axis", szTriggerName) == 0)
		{
			return -3;
		}

		return -999;
	}
}