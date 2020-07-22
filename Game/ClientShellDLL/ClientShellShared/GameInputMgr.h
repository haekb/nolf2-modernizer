#pragma once
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include "ltbasetypes.h"
#include <SDL.h>

#include <VKDefs.h>
#include <dinput.h>

// For now...We only care about Mouse button 1 and 2 and mousewheels
enum GameInputButton {
	GIB_LEFT_MOUSE = 0,
	GIB_RIGHT_MOUSE,
	GIB_MIDDLE_MOUSE,
	GIB_MOUSE_WHEEL_UP,
	GIB_MOUSE_WHEEL_DOWN
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

	void GenerateReverseMap();

	void Update();

	void OnMouseDown(GameInputButton button);
	void OnMouseUp(GameInputButton button);

	bool OnSDLKeyDown(SDL_KeyboardEvent keyEvent);
	bool OnSDLKeyUp(SDL_KeyboardEvent keyEvent);

	void OnMouseWheel(int nZDelta);



	void ReadDeviceBindings();

	void ProcessBinding(int nDInputDevice);
	void ReadKeyboardBindings(DeviceBinding* pBindings);
	void ReadMouseBindings(DeviceBinding* pBindings);
	//void ReadGamepadBindings();

	bool IsCommandOn(int nActionCode);

	void DeactivateCommand(int nActionCode);
	void ClearInput();

	//
	// ReadAnyKey
	// Pass it an empty DeviceInput and it'll fill it with the first key that gets pressed
	// This function should be called once per frame until it returns true
	//
	bool ReadAnyKey(DeviceInput* pDeviceInput);

private:

	
	// GameInputButton - GameInputMgr's bounded buttons
	// int - OnCommandOn action code
	std::map<GameInputButton, int> m_BindList; // Legacy - Handles mouse
	std::unordered_map <SDL_Scancode, std::vector<int>> m_KeyboardBindList;

	std::vector<int> m_ActiveCommands;


	
	// Cheaper than checking an array for our two special case buttons..
	bool m_bIsWheelingUp;
	bool m_bIsWheelingDown;

	int m_nLastZDelta;
};

