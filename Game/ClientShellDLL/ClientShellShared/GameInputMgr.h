#pragma once
#include <string>
#include <vector>
#include <map>
#include "ltbasetypes.h"
#include <SDL.h>

class InputMgr {
public:
	bool (*Init)(InputMgr* pInputMgr, intptr_t* pState);
	void (*Term)(InputMgr* pInputMgr);
	bool (*IsInitted)(InputMgr* pInputMgr);

	void (*ListDevices)(InputMgr* pInputMgr);
	
	uint32_t (*PlayJoystickEffect)(InputMgr* pInputMgr, const char* szEffectName, float x, float y);

	void (*ReadInput)(InputMgr* pInputMgr, uint8_t* pActionsOn, float fAxisOffsets[3]);

	bool (*FlushInputBuffers)(InputMgr* pInputMgr);

	LTRESULT(*ClearInput)();

	void (*AddAction)(InputMgr* pInputMgr, const char* pActionName, int nActionCode);

	bool (*EnableDevice)(InputMgr* pInputMgr, const char* pDeviceName);

	bool (*ClearBindings)(InputMgr* pInputMgr, const char* pDeviceName, const char* pTriggerName);

	bool (*AddBinding)(InputMgr* pInputMgr, const char* pDeviceName, const char* pTriggerName, const char* pActionName, float fRangeLow, float fRangeHigh);

	bool (*ScaleTrigger)(InputMgr* pInputMgr, const char* pDeviceName, const char* pTriggerName, float fScale, float fRangeScaleMin, float fRangeScaleMax, float fRangeScalePreCenterOffset);

	DeviceBinding* (*GetDeviceBindings)(uint32_t nDevice);

	void (*FreeDeviceBindings)(DeviceBinding* pBindings);

	bool (*StartDeviceTrack)(InputMgr* pMgr, uint32_t nDevices, uint32_t nBufferSize);

	bool (*TrackDevice)(DeviceInput* pInputAttay, uint32_t* pInOut);

	bool (*EndDeviceTrack)();

	DeviceObject* (*GetDeviceObjects)(uint32_t nDeviceFlags);

	void (*FreeDeviceObjects)(DeviceObject* pList);

	bool (*GetDeviceName)(uint32_t nDeviceType, char* szBuffer, uint32_t nBufferSize);

	bool (*GetDeviceObjectName)(const char* szDeviceName, uint32_t nDeviceObjectID, char* szDeviceObjectName, uint32_t nDeviceObjectNameLength);

	bool (*IsDeviceEnabled)(const char* szDeviceName);

	bool (*ShowDeviceObjects)(const char* szDeviceName);

	bool (*ShowInputDevices)();
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

