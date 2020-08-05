#include "stdafx.h"
#include "GameInputMgr.h"
#include "GameClientShell.h"
#include <SDL.h>
#include <algorithm>
#include <dinput.h>
	
GameInputMgr* g_pGameInputMgr = nullptr;


#define _DIK_TO_SDL2

#ifdef _DIK_TO_SDL2
typedef uint32_t DInputKey;

const std::map <DInputKey, int> g_mSDLMouseToDInputMouse = {
	/*
	{ SDL_BUTTON_LEFT	 , DIMOFS_BUTTON0  },
	{ SDL_BUTTON_RIGHT	 , DIMOFS_BUTTON1  },
	{ SDL_BUTTON_MIDDLE	 , DIMOFS_BUTTON2  },
	{ SDL_BUTTON_X1		 , DIMOFS_BUTTON3  },
	*/
	// They overlap with DIK, but they're tracked differently.
	{ SDL_BUTTON_LEFT	 , 3  },
	{ SDL_BUTTON_RIGHT	 , 4  },
	{ SDL_BUTTON_MIDDLE	 , 5  },
};

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

// Jake: This is generated at construction from the above map
std::map < SDL_Scancode, DInputKey > g_mSDLToDInput;
#endif


#define BIND_FUNC(x) m_pInputMgr->x = GameInputMgr::x
constexpr auto ENGINE_INPUT_MGR_PTR = 0x0059abc8;

GameInputMgr::GameInputMgr()
{
	g_pGameInputMgr = this;
	m_pBindings = nullptr;
	m_pActions = nullptr;
	
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

	bool bEnd = true;
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



}

bool GameInputMgr::IsInitted(InputMgr* pInputMgr)
{
	return false;
}

void GameInputMgr::ListDevices(InputMgr* pInputMgr)
{
}

uint32_t GameInputMgr::PlayJoystickEffect(InputMgr* pInputMgr, const char* szEffectName, float x, float y)
{
	return 0;
}

void GameInputMgr::ReadInput(InputMgr* pInputMgr, uint8_t* pActionsOn, float fAxisOffsets[3])
{
	auto pBinding = g_pGameInputMgr->m_pBindings;
	int nDeltaX, nDeltaY = 0;

	// Only track mouse if relative mode is enabled
	if (g_pGameInputMgr->GetRelativeMode())
	{
		SDL_GetRelativeMouseState(&nDeltaX, &nDeltaY);
	}

	auto pKeys = SDL_GetKeyboardState(0);

	while (pBinding)
	{
		// Only track mouse if relative mode is enabled
		if (g_pGameInputMgr->GetRelativeMode())
		{
			static int nCurrentMouseX = 0;
			static int nCurrentMouseY = 0;
			static int nPreviousMouseX = 0;
			static int nPreviousMouseY = 0;

			// TODO: Clean up, Code is from GameSettings.
			float nMouseSensitivity = GetConsoleFloat("MouseSensitivity", 1.0f);
			float nScale = 0.00125f + ((float)nMouseSensitivity * 0.001125f);
			nScale *= 0.50f;

			// X-Axis
			if (pBinding->pActionHead->nActionCode == -1)
			{
				nCurrentMouseX += nDeltaX;
				fAxisOffsets[0] = (float)(nCurrentMouseX - nPreviousMouseX) * nScale;
				nPreviousMouseX = nCurrentMouseX;
			}

			// Y-Axis
			if (pBinding->pActionHead->nActionCode == -2)
			{
				nCurrentMouseY += nDeltaY;
				fAxisOffsets[1] = (float)(nCurrentMouseY - nPreviousMouseY) * nScale;
				nPreviousMouseY = nCurrentMouseY;
			}

			// Z-Axis ???
			fAxisOffsets[2] = 0.0f;
		}

		if (pBinding->pActionHead->nActionCode == 0)
		{
			//continue;
		}

		std::string sDIK = pBinding->strTriggerName;
		int nDIK = 0;
		try {
			nDIK = std::stoi(sDIK.substr(2));
		}
		catch (std::invalid_argument e)
		{
			pBinding = pBinding->pNext;

			continue;
		}

		auto nScanCode = g_mDInputToSDL.at(nDIK);
		pActionsOn[pBinding->pActionHead->nActionCode] = (uint8)pKeys[nScanCode];

		pBinding = pBinding->pNext;
	}
}

bool GameInputMgr::FlushInputBuffers(InputMgr* pInputMgr)
{
	return false;
}

LTRESULT GameInputMgr::ClearInput()
{
	return LTRESULT();
}

void GameInputMgr::AddAction(InputMgr* pInputMgr, const char* pActionName, int nActionCode)
{
	GameAction* pAction = new GameAction();

	if (!pAction)
	{
		return;
	}

	LTStrCpy(pAction->strActionName, pActionName, sizeof(pAction->strActionName));
	pAction->nActionCode = nActionCode;
	pAction->nRangeLow = 0;
	pAction->nRangeHigh = 0;
	pAction->pNext = g_pGameInputMgr->m_pActions;
	g_pGameInputMgr->m_pActions = pAction;
}

bool GameInputMgr::EnableDevice(InputMgr* pInputMgr, const char* pDeviceName)
{
	return false;
}

bool GameInputMgr::ClearBindings(InputMgr* pInputMgr, const char* pDeviceName, const char* pTriggerName)
{
	return false;
}

bool GameInputMgr::AddBinding(InputMgr* pInputMgr, const char* pDeviceName, const char* pTriggerName, const char* pActionName, float fRangeLow, float fRangeHigh)
{
	DeviceBinding* pBinding = new DeviceBinding();

	if (!pBinding)
	{
		return false;
	}

	GameAction* pAction = g_pGameInputMgr->FindAction(pActionName);

	if (!pAction)
	{
		g_pLTClient->CPrint("[GameInputMgr::AddBinding] Action [%s] doesn't exist!", pActionName);
		delete pBinding;
		return false;
	}

	LTStrCpy(pBinding->strDeviceName, pDeviceName, sizeof(pBinding->strDeviceName));
	LTStrCpy(pBinding->strRealName, pActionName, sizeof(pBinding->strRealName));
	LTStrCpy(pBinding->strTriggerName, pTriggerName, sizeof(pBinding->strTriggerName));
	pBinding->nRangeScaleMin = fRangeLow;
	pBinding->nRangeScaleMin = fRangeHigh;
	pBinding->pActionHead = pAction;
	pBinding->pNext = g_pGameInputMgr->m_pBindings;
	g_pGameInputMgr->m_pBindings = pBinding;

	return false;
}

bool GameInputMgr::ScaleTrigger(InputMgr* pInputMgr, const char* pDeviceName, const char* pTriggerName, float fScale, float fRangeScaleMin, float fRangeScaleMax, float fRangeScalePreCenterOffset)
{
	return false;
}

DeviceBinding* GameInputMgr::GetDeviceBindings(uint32_t nDevice)
{
	return g_pGameInputMgr->m_pBindings;
}

void GameInputMgr::FreeDeviceBindings(DeviceBinding* pBindings)
{
}

bool GameInputMgr::StartDeviceTrack(InputMgr* pMgr, uint32_t nDevices, uint32_t nBufferSize)
{
	return false;
}

bool GameInputMgr::TrackDevice(DeviceInput* pInputAttay, uint32_t* pInOut)
{
	return false;
}

bool GameInputMgr::EndDeviceTrack()
{
	return false;
}

DeviceObject* GameInputMgr::GetDeviceObjects(uint32_t nDeviceFlags)
{
	return nullptr;
}

void GameInputMgr::FreeDeviceObjects(DeviceObject* pList)
{
}

bool GameInputMgr::GetDeviceName(uint32_t nDeviceType, char* szBuffer, uint32_t nBufferSize)
{
	return false;
}

bool GameInputMgr::GetDeviceObjectName(const char* szDeviceName, uint32_t nDeviceObjectID, char* szDeviceObjectName, uint32_t nDeviceObjectNameLength)
{
	return false;
}

bool GameInputMgr::IsDeviceEnabled(const char* szDeviceName)
{
	return false;
}

bool GameInputMgr::ShowDeviceObjects(const char* szDeviceName)
{
	return false;
}

bool GameInputMgr::ShowInputDevices()
{
	return false;
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
	auto pAction = m_pActions;

	while (pAction)
	{
		if (stricmp(pAction->strActionName, szActionName) == 0)
		{
			return pAction;
		}

		pAction = pAction->pNext;
	}

	return nullptr;
}

void GameInputMgr::GenerateReverseMap()
{
	// Alreaaady filled
	if (!g_mSDLToDInput.empty())
	{
		return;
	}

	for (auto pair : g_mDInputToSDL)
	{
		g_mSDLToDInput.insert(std::make_pair(pair.second, pair.first));
	}
}