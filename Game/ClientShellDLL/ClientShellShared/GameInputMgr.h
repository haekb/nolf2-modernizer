#pragma once
#include <string>
#include <vector>
#include <map>
#include "ltbasetypes.h"
#include <SDL.h>

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

	void Update();

	void OnMouseDown(GameInputButton button);
	void OnMouseUp(GameInputButton button);

	void OnMouseWheel(int nZDelta);

	void ReadDeviceBindings();

	bool IsCommandOn(int nActionCode);

	void DeactivateCommand(int nActionCode);

private:

	// GameInputButton - GameInputMgr's bounded buttons
	// int - OnCommandOn action code
	std::map<GameInputButton, int> m_BindList;
	std::vector<int> m_ActiveCommands;
	
	// Cheaper than checking an array for our two special case buttons..
	bool m_bIsWheelingUp;
	bool m_bIsWheelingDown;

	int m_nLastZDelta;
};

