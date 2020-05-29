#include "stdafx.h"
#include "GameInputMgr.h"
#include "GameClientShell.h"
#include <SDL.h>
#include <algorithm>
	
GameInputMgr* g_pGameInputMgr = nullptr;

GameInputMgr::GameInputMgr()
{
	g_pGameInputMgr = this;
	m_bIsWheelingUp = false;
	m_bIsWheelingDown = false;
	m_nLastZDelta = 0;
}

GameInputMgr::~GameInputMgr()
{
	m_ActiveCommands.clear();
	if (!m_BindList.empty()) {
		m_BindList.clear();
	}
}

void GameInputMgr::Update()
{
	
	// Properly handle sending OnWheel CommandOff calls
	// I'm not sure if the engine actually supports this properly
	// But we do!

	// OnWheel "Released"
	if (m_bIsWheelingUp && m_nLastZDelta < WHEEL_DELTA)
	{
		int nActionCode = m_BindList[GIB_MOUSE_WHEEL_UP];

		g_pGameClientShell->OnCommandOff(nActionCode);
		DeactivateCommand(nActionCode);

		m_bIsWheelingUp = false;
	}

	// OnWheel "Released"
	if (m_bIsWheelingDown && m_nLastZDelta > -WHEEL_DELTA)
	{
		int nActionCode = m_BindList[GIB_MOUSE_WHEEL_DOWN];

		g_pGameClientShell->OnCommandOff(nActionCode);
		DeactivateCommand(nActionCode);

		m_bIsWheelingDown = false;
	}

	// Empty out our last ZDelta.
	m_nLastZDelta = 0;
}

void GameInputMgr::OnMouseDown(GameInputButton button)
{
	if (!SDL_GetRelativeMouseMode())
	{
		return;
	}

	if (button == GIB_LEFT_MOUSE)
	{
		auto nActionCode = m_BindList[GIB_LEFT_MOUSE];
		g_pGameClientShell->OnCommandOn(nActionCode);
		m_ActiveCommands.push_back(nActionCode);

	}
	else if (button == GIB_RIGHT_MOUSE)
	{
		auto nActionCode = m_BindList[GIB_RIGHT_MOUSE];
		g_pGameClientShell->OnCommandOn(nActionCode);
		m_ActiveCommands.push_back(nActionCode);
	}
}

void GameInputMgr::OnMouseUp(GameInputButton button)
{
	if (!SDL_GetRelativeMouseMode())
	{
		return;
	}

	if (button == GIB_LEFT_MOUSE)
	{
		int nActionCode = m_BindList[GIB_LEFT_MOUSE];

		g_pGameClientShell->OnCommandOff(nActionCode);
		DeactivateCommand(nActionCode);
	}
	else if (button == GIB_RIGHT_MOUSE)
	{
		int nActionCode = m_BindList[GIB_RIGHT_MOUSE];

		g_pGameClientShell->OnCommandOff(nActionCode);
		DeactivateCommand(nActionCode);

	}
}

void GameInputMgr::OnMouseWheel(int nZDelta)
{
	if (!SDL_GetRelativeMouseMode())
	{
		return;
	}

	
	// OnWheel "Pressed"
	if (nZDelta >= WHEEL_DELTA)
	{
		int nActionCode = m_BindList[GIB_MOUSE_WHEEL_UP];
		g_pGameClientShell->OnCommandOn(nActionCode);
		m_ActiveCommands.push_back(nActionCode);
		m_bIsWheelingUp = true;
	}

	
	// OnWheel "Pressed"
	if (nZDelta <= -WHEEL_DELTA)
	{
		int nActionCode = m_BindList[GIB_MOUSE_WHEEL_DOWN];
		g_pGameClientShell->OnCommandOn(nActionCode);
		m_ActiveCommands.push_back(nActionCode);
		m_bIsWheelingDown = true;
	}

	// Store this for Update()
	m_nLastZDelta = nZDelta;
}

void GameInputMgr::ReadDeviceBindings()
{
	auto pBindings = g_pLTClient->GetDeviceBindings(DEVICETYPE_MOUSE);

	if (!pBindings)
	{
		return;
	}

	// Clear up the bind list, so we can re-fill it.
	if (!m_BindList.empty()) {
		m_BindList.clear();
	}

	DeviceBinding* ptr = pBindings;
	while (ptr)
	{
		GameAction* pAction = ptr->pActionHead;
		std::string sButtonName = ptr->strTriggerName;

		// Left mouse button
		if (sButtonName == "Button 0")
		{
			m_BindList.insert(std::make_pair(GIB_LEFT_MOUSE, pAction->nActionCode));
		}
		// Right mouse button
		else if (sButtonName == "Button 1")
		{
			m_BindList.insert(std::make_pair(GIB_RIGHT_MOUSE, pAction->nActionCode));
		}
		// Mouse Wheel
		else if (sButtonName == "Wheel")
		{
			m_BindList.insert(std::make_pair(GIB_MOUSE_WHEEL_UP, pAction->nActionCode));

			// If it's a range bind, which it probably will be, add our mouse wheel down action.
			GameAction* pSecondAction = pAction->pNext;
			if (pSecondAction)
			{
				m_BindList.insert(std::make_pair(GIB_MOUSE_WHEEL_DOWN, pSecondAction->nActionCode));
			}
			else
			{
				g_pLTClient->CPrint("[GameInputMgr] Warning, Mouse Wheel is not a rangebind!");
			}
		}

		ptr = ptr->pNext;
	}


	g_pLTClient->FreeDeviceBindings(pBindings);
}

bool GameInputMgr::IsCommandOn(int nActionCode)
{
	for (auto nStoredActionCode : m_ActiveCommands)
	{
		if (nActionCode == nStoredActionCode)
		{
			return true;
		}
	}

	return false;
}

// Helper function so I don't have to write out that e.erase line twice.
void GameInputMgr::DeactivateCommand(int nActionCode)
{
	auto remove = std::remove(m_ActiveCommands.begin(), m_ActiveCommands.end(), nActionCode);
	m_ActiveCommands.erase(remove, m_ActiveCommands.end());
}
