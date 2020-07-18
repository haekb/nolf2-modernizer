#include "stdafx.h"
#include "GameInputMgr.h"
#include "GameClientShell.h"
#include <SDL.h>
#include <algorithm>
	
GameInputMgr* g_pGameInputMgr = nullptr;


#define _DIK_TO_SDL2

#ifdef _DIK_TO_VK
typedef uint32_t VirtualKey;
typedef uint32_t DInputKey;

// Jake: Man this sucks, but we need a fast way to convert DirectInput keys to VirtualKeys..
// Yes I know DInput is physical keys vs virtual keys..but much else we can do here..
const std::map< DInputKey, VirtualKey > g_mDInputToVK = {
	{ DIK_ESCAPE, VK_ESCAPE },
	{ DIK_1, VK_1 },
	{ DIK_2, VK_2 },
	{ DIK_3, VK_3 },
	{ DIK_4, VK_4 },
	{ DIK_5, VK_5 },
	{ DIK_6, VK_6 },
	{ DIK_7, VK_7 },
	{ DIK_8, VK_8 },
	{ DIK_9, VK_9 },
	{ DIK_0, VK_0 },
	{ DIK_MINUS, VK_OEM_MINUS },
	{ DIK_EQUALS, VK_OEM_NEC_EQUAL }

};
#endif

#ifdef _DIK_TO_SDL2
typedef uint32_t VirtualKey;
typedef uint32_t DInputKey;

// Jake: Man this sucks, but we need a fast way to convert DirectInput keys to SDL2 Scancodes
const std::map< DInputKey, SDL_Scancode > g_mDInputToSDL = {
{ DIK_ESCAPE        , SDL_SCANCODE_ESCAPE },
{ DIK_1             , SDL_SCANCODE_1 },
{ DIK_2             , SDL_SCANCODE_2 },
{ DIK_3             , SDL_SCANCODE_3 },
{ DIK_4             , SDL_SCANCODE_4 },
{ DIK_5             , SDL_SCANCODE_5 },
{ DIK_6             , SDL_SCANCODE_6 },
{ DIK_7             , SDL_SCANCODE_7 },
{ DIK_8             , SDL_SCANCODE_8 },
{ DIK_9             , SDL_SCANCODE_9 },
{ DIK_0             , SDL_SCANCODE_0 },
{ DIK_MINUS         , SDL_SCANCODE_MINUS },
{ DIK_EQUALS        , SDL_SCANCODE_EQUALS },
{ DIK_BACK          , SDL_SCANCODE_BACKSPACE },
{ DIK_TAB           , SDL_SCANCODE_TAB },
{ DIK_Q             , SDL_SCANCODE_Q },
{ DIK_W             , SDL_SCANCODE_W },
{ DIK_E             , SDL_SCANCODE_E },
{ DIK_R             , SDL_SCANCODE_R },
{ DIK_T             , SDL_SCANCODE_T },
{ DIK_Y             , SDL_SCANCODE_Y },
{ DIK_U             , SDL_SCANCODE_U },
{ DIK_I             , SDL_SCANCODE_I },
{ DIK_O             , SDL_SCANCODE_O },
{ DIK_P             , SDL_SCANCODE_P },
{ DIK_LBRACKET      , SDL_SCANCODE_LEFTBRACKET },
{ DIK_RBRACKET      , SDL_SCANCODE_RIGHTBRACKET },
{ DIK_RETURN        , SDL_SCANCODE_RETURN },
{ DIK_LCONTROL      , SDL_SCANCODE_LCTRL },
{ DIK_A             , SDL_SCANCODE_A },
{ DIK_S             , SDL_SCANCODE_S },
{ DIK_D             , SDL_SCANCODE_D },
{ DIK_F             , SDL_SCANCODE_F },
{ DIK_G             , SDL_SCANCODE_G },
{ DIK_H             , SDL_SCANCODE_H },
{ DIK_J             , SDL_SCANCODE_J },
{ DIK_K             , SDL_SCANCODE_K },
{ DIK_L             , SDL_SCANCODE_L },
{ DIK_SEMICOLON     , SDL_SCANCODE_SEMICOLON },
{ DIK_APOSTROPHE    , SDL_SCANCODE_APOSTROPHE },
{ DIK_GRAVE         , SDL_SCANCODE_GRAVE },
{ DIK_LSHIFT        , SDL_SCANCODE_LSHIFT },
{ DIK_BACKSLASH     , SDL_SCANCODE_BACKSLASH },
{ DIK_Z             , SDL_SCANCODE_Z },
{ DIK_X             , SDL_SCANCODE_X },
{ DIK_C             , SDL_SCANCODE_C },
{ DIK_V             , SDL_SCANCODE_V },
{ DIK_B             , SDL_SCANCODE_B },
{ DIK_N             , SDL_SCANCODE_N },
{ DIK_M             , SDL_SCANCODE_M },
{ DIK_COMMA         , SDL_SCANCODE_COMMA },
{ DIK_PERIOD        , SDL_SCANCODE_PERIOD },
{ DIK_SLASH         , SDL_SCANCODE_SLASH },
{ DIK_RSHIFT        , SDL_SCANCODE_RSHIFT },
{ DIK_MULTIPLY      , SDL_SCANCODE_KP_MULTIPLY },
{ DIK_LMENU         , SDL_SCANCODE_LALT },
{ DIK_SPACE         , SDL_SCANCODE_SPACE },
{ DIK_CAPITAL       , SDL_SCANCODE_CAPSLOCK },
{ DIK_F1            , SDL_SCANCODE_F1 },
{ DIK_F2            , SDL_SCANCODE_F2 },
{ DIK_F3            , SDL_SCANCODE_F3 },
{ DIK_F4            , SDL_SCANCODE_F4 },
{ DIK_F5            , SDL_SCANCODE_F5 },
{ DIK_F6            , SDL_SCANCODE_F6 },
{ DIK_F7            , SDL_SCANCODE_F7 },
{ DIK_F8            , SDL_SCANCODE_F8 },
{ DIK_F9            , SDL_SCANCODE_F9 },
{ DIK_F10           , SDL_SCANCODE_F10 },
{ DIK_NUMLOCK       , SDL_SCANCODE_NUMLOCKCLEAR },
{ DIK_SCROLL        , SDL_SCANCODE_SCROLLLOCK },
{ DIK_NUMPAD7       , SDL_SCANCODE_KP_7 },
{ DIK_NUMPAD8       , SDL_SCANCODE_KP_8 },
{ DIK_NUMPAD9       , SDL_SCANCODE_KP_9 },
{ DIK_SUBTRACT      , SDL_SCANCODE_KP_MINUS },
{ DIK_NUMPAD4       , SDL_SCANCODE_KP_4 },
{ DIK_NUMPAD5       , SDL_SCANCODE_KP_5 },
{ DIK_NUMPAD6       , SDL_SCANCODE_KP_6 },
{ DIK_ADD           , SDL_SCANCODE_KP_PLUS },
{ DIK_NUMPAD1       , SDL_SCANCODE_KP_1 },
{ DIK_NUMPAD2       , SDL_SCANCODE_KP_2 },
{ DIK_NUMPAD3       , SDL_SCANCODE_KP_3 },
{ DIK_NUMPAD0       , SDL_SCANCODE_KP_0 },
{ DIK_DECIMAL       , SDL_SCANCODE_KP_PERIOD },
{ DIK_OEM_102       , SDL_SCANCODE_KP_LESS }, // ???
{ DIK_F11           , SDL_SCANCODE_F11 },
{ DIK_F12           , SDL_SCANCODE_F12 },
{ DIK_F13           , SDL_SCANCODE_F13 },
{ DIK_F14           , SDL_SCANCODE_F14 },
{ DIK_F15           , SDL_SCANCODE_F15 },
{ DIK_KANA          , SDL_SCANCODE_LANG3 },
{ DIK_ABNT_C1       , SDL_SCANCODE_SLASH }, // ???
{ DIK_CONVERT       , SDL_SCANCODE_UNKNOWN },
{ DIK_NOCONVERT     , SDL_SCANCODE_UNKNOWN },
{ DIK_YEN           , SDL_SCANCODE_INTERNATIONAL3 },
{ DIK_ABNT_C2       , SDL_SCANCODE_KP_PERIOD },
{ DIK_NUMPADEQUALS  , SDL_SCANCODE_KP_EQUALS },
{ DIK_PREVTRACK     , SDL_SCANCODE_AUDIOPREV },
{ DIK_AT            , SDL_SCANCODE_KP_AT },
{ DIK_COLON         , SDL_SCANCODE_KP_COLON },
{ DIK_UNDERLINE     , SDL_SCANCODE_UNKNOWN },
{ DIK_KANJI         , SDL_SCANCODE_UNKNOWN },
{ DIK_STOP          , SDL_SCANCODE_STOP },
{ DIK_AX            , SDL_SCANCODE_UNKNOWN },
{ DIK_UNLABELED     , SDL_SCANCODE_UNKNOWN },
{ DIK_NEXTTRACK     , SDL_SCANCODE_AUDIONEXT },
{ DIK_NUMPADENTER   , SDL_SCANCODE_KP_ENTER },
{ DIK_RCONTROL      , SDL_SCANCODE_RCTRL },
{ DIK_MUTE          , SDL_SCANCODE_MUTE },
{ DIK_CALCULATOR    , SDL_SCANCODE_CALCULATOR },
{ DIK_PLAYPAUSE     , SDL_SCANCODE_AUDIOPLAY },
{ DIK_MEDIASTOP     , SDL_SCANCODE_AUDIOSTOP },
{ DIK_VOLUMEDOWN    , SDL_SCANCODE_VOLUMEDOWN },
{ DIK_VOLUMEUP      , SDL_SCANCODE_VOLUMEUP },
{ DIK_WEBHOME       , SDL_SCANCODE_WWW },
{ DIK_NUMPADCOMMA   , SDL_SCANCODE_KP_COMMA },
{ DIK_DIVIDE        , SDL_SCANCODE_KP_DIVIDE },
{ DIK_SYSRQ         , SDL_SCANCODE_SYSREQ },
{ DIK_RMENU         , SDL_SCANCODE_RALT },
{ DIK_PAUSE         , SDL_SCANCODE_PAUSE },
{ DIK_HOME          , SDL_SCANCODE_HOME },
{ DIK_UP            , SDL_SCANCODE_UP },
{ DIK_PRIOR         , SDL_SCANCODE_PAGEUP },
{ DIK_LEFT          , SDL_SCANCODE_LEFT },
{ DIK_RIGHT         , SDL_SCANCODE_RIGHT },
{ DIK_END           , SDL_SCANCODE_END },
{ DIK_DOWN          , SDL_SCANCODE_DOWN },
{ DIK_NEXT          , SDL_SCANCODE_PAGEDOWN },
{ DIK_INSERT        , SDL_SCANCODE_INSERT },
{ DIK_DELETE        , SDL_SCANCODE_DELETE },
{ DIK_LWIN          , SDL_SCANCODE_LGUI },
{ DIK_RWIN          , SDL_SCANCODE_RGUI },
{ DIK_APPS          , SDL_SCANCODE_APPLICATION },
{ DIK_POWER         , SDL_SCANCODE_POWER },
{ DIK_SLEEP         , SDL_SCANCODE_SLEEP },
{ DIK_WAKE          , SDL_SCANCODE_UNKNOWN },
{ DIK_WEBSEARCH     , SDL_SCANCODE_UNKNOWN },
{ DIK_WEBFAVORITES  , SDL_SCANCODE_UNKNOWN },
{ DIK_WEBREFRESH    , SDL_SCANCODE_UNKNOWN },
{ DIK_WEBSTOP       , SDL_SCANCODE_UNKNOWN },
{ DIK_WEBFORWARD    , SDL_SCANCODE_UNKNOWN },
{ DIK_WEBBACK       , SDL_SCANCODE_UNKNOWN },
{ DIK_MYCOMPUTER    , SDL_SCANCODE_UNKNOWN },
{ DIK_MAIL          , SDL_SCANCODE_MAIL },
{ DIK_MEDIASELECT   , SDL_SCANCODE_MEDIASELECT },
};
#endif

GameInputMgr::GameInputMgr()
{
	g_pGameInputMgr = this;
	m_bIsWheelingUp = false;
	m_bIsWheelingDown = false;
	m_nLastZDelta = 0;
}

GameInputMgr::~GameInputMgr()
{
	ClearInput();

	if (!m_BindList.empty()) {
		m_BindList.clear();
	}
}

void GameInputMgr::Update()
{

	const uint8* pState = SDL_GetKeyboardState(nullptr);

	
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
		ClearInput();
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
		ClearInput();
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

bool GameInputMgr::OnKeyDown(int key, int rep)
{


	return false;
}

bool GameInputMgr::OnKeyUp(int key)
{
	return false;
}

void GameInputMgr::OnMouseWheel(int nZDelta)
{
	if (!SDL_GetRelativeMouseMode())
	{
		ClearInput();
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

	// Keyboard stuff - all temp, clean up jake!
	{
		auto pBindings = g_pLTClient->GetDeviceBindings(DEVICETYPE_KEYBOARD);

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
			std::string sDIK = ptr->strRealName;
			int nDIK = std::stoi(sDIK.substr(2));

			m_KeyboardBindList.insert(std::make_pair( g_mDInputToSDL.at(nDIK), pAction->nActionCode ));


			ptr = ptr->pNext;
		}


		g_pLTClient->FreeDeviceBindings(pBindings);
	}
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

void GameInputMgr::ClearInput()
{
	for (auto nActionCode : m_ActiveCommands)
	{
		g_pGameClientShell->OnCommandOff(nActionCode);
	}
	m_ActiveCommands.clear();
}
