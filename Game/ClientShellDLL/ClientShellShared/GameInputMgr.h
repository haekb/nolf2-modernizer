#pragma once
#include <string>
#include <vector>
#include <map>
#include "ltbasetypes.h"
#include <SDL.h>
#include "InputMgr.h"



// They didn't name the enum...
enum LT_DeviceType {
	DEVICE_TYPE_KEYBOARD = DEVICETYPE_KEYBOARD,
	DEVICE_TYPE_MOUSE = DEVICETYPE_MOUSE,
	DEVICE_TYPE_JOYSTICK = DEVICETYPE_JOYSTICK,
	DEVICE_TYPE_GAMEPAD = DEVICETYPE_GAMEPAD,
	DEVICE_TYPE_UNKNOWN = DEVICETYPE_UNKNOWN,
};

// I'm not sure why this isn't already an enum.
enum SDL_MouseButton {
	SDL_MOUSE_BUTTON_LEFT = SDL_BUTTON_LEFT,
	SDL_MOUSE_BUTTON_MIDDLE = SDL_BUTTON_MIDDLE,
	SDL_MOUSE_BUTTON_RIGHT = SDL_BUTTON_RIGHT,
};

enum SDL_MouseAxis {
	SDL_MOUSE_AXIS_X = 0,
	SDL_MOUSE_AXIS_Y,
	SDL_MOUSE_AXIS_WHEEL,
	//SDL_MOUSE_AXIS_WHEEL_UP,
	//SDL_MOUSE_AXIS_WHEEL_DOWN,
};

// These only pop up on GIMBinding
// when bHasDIK is false!
enum ExtendedDIK {
	// Mouse
	MOUSE_X_AXIS = -1,
	MOUSE_Y_AXIS = -2,
	MOUSE_Z_AXIS = -3,
	MOUSE_LEFT_BUTTON = 3,
	MOUSE_MIDDLE_BUTTON = 5,
	MOUSE_RIGHT_BUTTON = 4,
};

struct GIMBinding {
	char szName[INPUTNAME_LEN];
	char szDevice[INPUTNAME_LEN];
	bool bIsEnabled;

	// DirectInput Keycode
	uint32_t nDIK;
	// Whether or not nDIK is filled with useful info
	bool bHasDIK;

	// Based off the DEVICETYPE_* enum
	LT_DeviceType nDeviceType;
	bool bIsAxis;

	// Based off of nDeviceType + bIsAxis
	union {
		// Sorry keyboard, you're stuck in digital space
		SDL_Scancode nKeyboardScancode;

		// Mouse button / axis
		SDL_MouseButton nMouseButton;
		SDL_MouseAxis nMouseAxis;

		// Gamepad button / axis
		SDL_GameControllerButton nGamepadButton;
		SDL_GameControllerAxis nGamepadAxis;
	};

	DeviceBinding* pDeviceBinding;
};

//
// Game Input Manager
// This is a separate class from ProfileMgr so engine folks can rip this out later!
// (It'll probably be a bit more complicated than that, but hopefully it's not too hard.)
//
class GameInputMgr
{
public:
	GameInputMgr();
	~GameInputMgr();

	// Replaces DInput's bindings with our own!
	// Sneaaaky.
	void ReplaceBindings();

	// InputMgr implementations
	static bool Init(InputMgr* pInputMgr, intptr_t* pState);
	static void Term(InputMgr* pInputMgr);
	static bool IsInitted(InputMgr* pInputMgr);

	// Console print devices
	static void ListDevices(InputMgr* pInputMgr);

	// Play force feedback effect
	static uint32_t PlayJoystickEffect(InputMgr* pInputMgr, const char* szEffectName, float x, float y);

	// Read input
	static void ReadInput(InputMgr* pInputMgr, uint8_t* pActionsOn, float fAxisOffsets[3]);

	static bool FlushInputBuffers(InputMgr* pInputMgr);

	static LTRESULT ClearInput();

	// Add an action
	// Actions are things like "Fire", or "Walk Forward". They trigger things in game code.
	static void AddAction(InputMgr* pInputMgr, const char* pActionName, int nActionCode);

	// Enable a device
	static bool EnableDevice(InputMgr* pInputMgr, const char* pDeviceName);
	
	// Clear a particular binding
	static bool ClearBindings(InputMgr* pInputMgr, const char* pDeviceName, const char* pTriggerName);
	
	// Add a binding
	// Bindings are button commands that trigger actions. (Hence binding!)
	static bool AddBinding(InputMgr* pInputMgr, const char* pDeviceName, const char* pTriggerName, const char* pActionName, float fRangeLow, float fRangeHigh);
	
	// Whether or not to apply a "scale" to a binding. Mainly for axis.
	static bool ScaleTrigger(InputMgr* pInputMgr, const char* pDeviceName, const char* pTriggerName, float fScale, float fRangeScaleMin, float fRangeScaleMax, float fRangeScalePreCenterOffset);
	
	// Let the game code have a lookie at our bindings
	static DeviceBinding* GetDeviceBindings(uint32_t nDevice);
	
	// Clear any memory you allocated above
	static void FreeDeviceBindings(DeviceBinding* pBindings);
	
	// Game code wants direct access to a device
	static bool StartDeviceTrack(InputMgr* pMgr, uint32_t nDevices, uint32_t nBufferSize);
	
	// Send any key/button/axis from the device "started" above, and send it directly to the game code.
	static bool TrackDevice(DeviceInput* pInputAttay, uint32_t* pInOut);
	
	// Stop our direct access
	static bool EndDeviceTrack();
	
	// Get a list of devices that we can use
	static DeviceObject* GetDeviceObjects(uint32_t nDeviceFlags);
	
	// Clean up any memory from the above call
	static void FreeDeviceObjects(DeviceObject* pList);
	
	// Let's get the device name!
	static bool GetDeviceName(uint32_t nDeviceType, char* szBuffer, uint32_t nBufferSize);
	
	// Let's get individual key/button/axis names from a particular device! (nDeviceObjectID should refer to that key/button/axis!)
	static bool GetDeviceObjectName(const char* szDeviceName, uint32_t nDeviceObjectID, char* szDeviceObjectName, uint32_t nDeviceObjectNameLength);
	
	// Is a particular device enabled?
	static bool IsDeviceEnabled(const char* szDeviceName);

	// Console print devices
	static bool ShowDeviceObjects(const char* szDeviceName);

	// Console print devices
	static bool ShowInputDevices();

	//
	// Non-interface functions
	//

	// Public so static functions can clean them up.
	InputMgr* m_pInputMgr;
	//GIMBinding* m_pBindings;

	std::vector<GIMBinding*> m_pBindingList;
	std::vector<GameAction*> m_pActionList;
	std::vector<LT_DeviceType> m_DeviceTrackingList;

	// Bindable objects - Re-using GIMBinding, without a pDeviceBinding!
	std::vector<GIMBinding*> m_pAvailableObjects;
	std::vector< LT_DeviceType> m_EnabledDevices;


	bool GetRelativeMode() { return m_bRelativeMode; }
	void SetRelativeMode(bool bOn);

	GameAction* FindAction(const char* szActionName);

	void GenerateReverseMap();

	LT_DeviceType GetDeviceTypeFromName(const char* szDeviceName);

	// Converts "##42" to 42.
	// Returns -999 if failed.
	int GetActionCodeFromBindString(const char* szTriggerName);

	void SetWheelDelta(int nWheelDelta) { m_nWheelDelta = nWheelDelta; };
	int GetWheelDelta() { return m_nWheelDelta; }

private:


	int m_nWheelDelta;
	bool m_bRelativeMode;

};

