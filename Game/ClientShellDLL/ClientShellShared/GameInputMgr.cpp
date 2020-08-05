#include "stdafx.h"
#include "GameInputMgr.h"
#include "GameClientShell.h"
#include <SDL.h>
#include <algorithm>
	
GameInputMgr* g_pGameInputMgr = nullptr;

GameInputMgr::GameInputMgr()
{
	g_pGameInputMgr = this;
}

GameInputMgr::~GameInputMgr()
{
}
