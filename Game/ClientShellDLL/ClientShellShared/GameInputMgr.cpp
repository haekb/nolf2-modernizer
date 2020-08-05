#include "stdafx.h"
#include "GameInputMgr.h"
#include "GameClientShell.h"
#include <SDL.h>
#include <algorithm>
	
GameInputMgr* g_pGameInputMgr = nullptr;

GameInputMgr::GameInputMgr()
{
	g_pGameInputMgr = this;

	//m_pInputMgr = new InputMgr();
	
	// Clean up the old inputmgr, and replace the bindings.
	m_pInputMgr = (InputMgr*)0x0059abc8;
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
	m_pInputMgr->Init = GameInputMgr::Init;
	m_pInputMgr->Term = GameInputMgr::Term;
	m_pInputMgr->IsInitted = GameInputMgr::IsInitted;
	m_pInputMgr->ReadInput = GameInputMgr::ReadInput;
}

bool GameInputMgr::Init(InputMgr* pInputMgr, intptr_t* pState)
{
	return false;
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

void GameInputMgr::ReadInput(InputMgr* pInputMgr, uint8_t* pActionsOn, float fAxisOffsets[3])
{

	bool bBeans = true;

}
