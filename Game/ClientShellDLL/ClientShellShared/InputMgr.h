#pragma once
#include "ltbasetypes.h"

class InputMgr {
public:
	bool (*Init)(InputMgr* pInputMgr, intptr_t* pState);
	void (*Term)(InputMgr* pInputMgr);
	bool (*IsInitted)(InputMgr* pInputMgr);

	void (*ListDevices)(InputMgr* pInputMgr);

	uint32_t(*PlayJoystickEffect)(InputMgr* pInputMgr, const char* szEffectName, float x, float y);

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
