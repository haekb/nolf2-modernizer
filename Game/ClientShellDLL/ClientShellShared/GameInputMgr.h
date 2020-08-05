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

	static void ListDevices(InputMgr* pInputMgr);

	static uint32_t PlayJoystickEffect(InputMgr* pInputMgr, const char* szEffectName, float x, float y);

	static void ReadInput(InputMgr* pInputMgr, uint8_t* pActionsOn, float fAxisOffsets[3]);

	static bool FlushInputBuffers(InputMgr* pInputMgr);

	static LTRESULT ClearInput();

	static void AddAction(InputMgr* pInputMgr, const char* pActionName, int nActionCode);
	

	static bool EnableDevice(InputMgr* pInputMgr, const char* pDeviceName);
	

	static bool ClearBindings(InputMgr* pInputMgr, const char* pDeviceName, const char* pTriggerName);
	

	static bool AddBinding(InputMgr* pInputMgr, const char* pDeviceName, const char* pTriggerName, const char* pActionName, float fRangeLow, float fRangeHigh);
	

	static bool ScaleTrigger(InputMgr* pInputMgr, const char* pDeviceName, const char* pTriggerName, float fScale, float fRangeScaleMin, float fRangeScaleMax, float fRangeScalePreCenterOffset);
	

	static DeviceBinding* GetDeviceBindings(uint32_t nDevice);
	

	static void FreeDeviceBindings(DeviceBinding* pBindings);
	

	static bool StartDeviceTrack(InputMgr* pMgr, uint32_t nDevices, uint32_t nBufferSize);
	

	static bool TrackDevice(DeviceInput* pInputAttay, uint32_t* pInOut);
	

	static bool EndDeviceTrack();
	

	static DeviceObject* GetDeviceObjects(uint32_t nDeviceFlags);
	

	static void FreeDeviceObjects(DeviceObject* pList);
	

	static bool GetDeviceName(uint32_t nDeviceType, char* szBuffer, uint32_t nBufferSize);
	

	static bool GetDeviceObjectName(const char* szDeviceName, uint32_t nDeviceObjectID, char* szDeviceObjectName, uint32_t nDeviceObjectNameLength);
	

	static bool IsDeviceEnabled(const char* szDeviceName);

	static bool ShowDeviceObjects(const char* szDeviceName);

	static bool ShowInputDevices();

	//
	// Non-interface functions
	//

	// Public so static functions can clean them up.
	InputMgr* m_pInputMgr;
	DeviceBinding* m_pBindings;
	GameAction* m_pActions;

	bool GetRelativeMode() { return m_bRelativeMode; }
	void SetRelativeMode(bool bOn);

	GameAction* FindAction(const char* szActionName);

	void GenerateReverseMap();

private:

	bool m_bRelativeMode;

};

