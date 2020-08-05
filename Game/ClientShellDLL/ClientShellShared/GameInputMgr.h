#pragma once
#include <string>
#include <vector>
#include <map>
#include "ltbasetypes.h"
#include <SDL.h>
#include "InputMgr.h"

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
	void ReplaceBindings();


	// InputMgr implementations
	static bool Init(InputMgr* pInputMgr, intptr_t* pState);
	static void Term(InputMgr* pInputMgr);
	static bool IsInitted(InputMgr* pInputMgr);

	static void ReadInput(InputMgr* pInputMgr, uint8_t* pActionsOn, float fAxisOffsets[3]);


	// Public so static functions can clean them up.
	InputMgr* m_pInputMgr;
	InputMgr* m_pOldInputMgr;

private:


};

