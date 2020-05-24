// ----------------------------------------------------------------------- //
//
// MODULE  : TO2GameClientShell.cpp
//
// PURPOSE : Game Client Shell - Implementation
//
// CREATED : 11/5/01
//
// (c) 1997-2001 Monolith Productions, Inc.  All Rights Reserved
//
// ----------------------------------------------------------------------- //

#include "stdafx.h"
#include "TO2GameClientShell.h"

#include "msgids.h"

#include "clientmultiplayermgr.h"
#include "iserverdir.h"

VarTrack			g_vtMaxFPS;						// MaxFramerate				<0...>
VarTrack			g_vtLockFPS;					// FramerateLock			<0-1>
VarTrack			g_vtShowFPS;					// ShowFramerate			<0-1>

// Sample rate
int g_nSampleRate = 22050;


// ----------------------------------------------------------------------- //
//
//	ROUTINE:	CTO2GameClientShell::CTO2GameClientShell()
//
//	PURPOSE:	Initialization
//
// ----------------------------------------------------------------------- //

CTO2GameClientShell::CTO2GameClientShell() : CGameClientShell()
{
	// Just some default
	m_fMaxFPS = 60.0f;
	m_lNextUpdate = 1L;
	m_lFrametime = 0L;
	m_bLockFramerate = LTTRUE;
	m_bUserWantsFramerateLock = LTTRUE;
}

// ----------------------------------------------------------------------- //
//
//	ROUTINE:	CTO2GameClientShell::~CTO2GameClientShell()
//
//	PURPOSE:	Destruction
//
// ----------------------------------------------------------------------- //

CTO2GameClientShell::~CTO2GameClientShell()
{
}

// ----------------------------------------------------------------------- //
//
//	ROUTINE:	CTO2GameClientShell::OnEngineInitialized
//
//	PURPOSE:	Wrapper for OnEngineInitialized so we can do something extra
//
// ----------------------------------------------------------------------- //

uint32 CTO2GameClientShell::OnEngineInitialized(RMode *pMode, LTGUID *pAppGuid)
{


	uint32 nResult = CGameClientShell::OnEngineInitialized(pMode, pAppGuid);

	m_VersionMgr.Update();

	//with the update of the version manager, it might have changed the gore setting,
	//so make sure that the FX managers know about the change
	UpdateGoreSettings();

	// Setup our framerate limiter
	m_bLockFramerate = LTTRUE;

	g_vtLockFPS.Init(g_pLTClient, "LockFramerate", LTNULL, 1.0f);
	g_vtShowFPS.Init(g_pLTClient, "ShowFramerate", LTNULL, 1.0f);
	g_vtMaxFPS.Init(g_pLTClient, "MaxFramerate", LTNULL, 60.0f);

	// If we can't get timer frequency, we can't limit the framerate!
	if (!QueryPerformanceFrequency(&m_lTimerFrequency)) {
		SDL_Log("Device doesn't support high resolution timer! Can't lock framerate.");
		m_bLockFramerate = LTFALSE;
	}

	// Init with a default!
	m_fMaxFPS = g_vtMaxFPS.GetFloat();
	m_lFrametime = (m_lTimerFrequency.QuadPart / m_fMaxFPS);

	return nResult;
}

// ----------------------------------------------------------------------- //
//
//	ROUTINE:	CTO2GameClientShell::ProcessPacket
//
//	PURPOSE:	Handling for connectionless networking packets
//
// ----------------------------------------------------------------------- //

LTRESULT CTO2GameClientShell::ProcessPacket(ILTMessage_Read *pMsg, uint8 senderAddr[4], uint16 senderPort)
{
	// Gotta have some data...
	if (pMsg->Size() < 16)
		return LT_OK;

	// Skip the engine-side portion of the message header
	CLTMsgRef_Read cSubMsg(pMsg->SubMsg(8));

	// Remember what address this came from
	g_pClientMultiplayerMgr->SetCurMessageSource(senderAddr, senderPort);

	// Hand it off as if it were a message
	// Note : This has to go through the parent's OnMessage so we handle the message source properly
	CGameClientShell::OnMessage(cSubMsg);

	return LT_OK;
}

// ----------------------------------------------------------------------- //
//
//	ROUTINE:	CTO2GameClientShell::OnMessage
//
//	PURPOSE:	Message from the server
//
// ----------------------------------------------------------------------- //
void CTO2GameClientShell::OnMessage(ILTMessage_Read *pMsg)
{
	// Store the server's address as where this message came from
	uint8 aAddrBuffer[4];
	uint16 nPort;
	g_pLTClient->GetServerIPAddress(aAddrBuffer, &nPort);
	g_pClientMultiplayerMgr->SetCurMessageSource(aAddrBuffer, nPort);
	
	CGameClientShell::OnMessage(pMsg);
}

void CTO2GameClientShell::LimitFramerate()
{

	// Update the max fps if they changed it!
	if (m_fMaxFPS != g_vtMaxFPS.GetFloat())
	{
		m_fMaxFPS = g_vtMaxFPS.GetFloat();
		m_lFrametime = (m_lTimerFrequency.QuadPart / m_fMaxFPS);
	}

	// Occasionally we'll need to unlock the framerate (like during loading!)
	// But we also want the user to have the option to unlock it,
	// so that's why there's two almost identical lock vars here.
	if ((m_bLockFramerate && g_vtLockFPS.GetFloat()))
	{
		// Limit our framerate so the game actually runs properly.
		LARGE_INTEGER NewTime;

		while (1) {
			QueryPerformanceCounter(&NewTime);
			unsigned long lTime = NewTime.QuadPart - m_lNextUpdate;
			if (lTime > m_lFrametime) {
				m_lNextUpdate = NewTime.QuadPart;
				break;
			}
		}
	}
}

void CTO2GameClientShell::Update()
{
	CGameClientShell::Update();

	CTO2PlayerStats* pPlayerStats = (CTO2PlayerStats*)g_pInterfaceMgr->GetPlayerStats();

	pPlayerStats->UpdateFramerate(1 / GetFrameTime());

	LimitFramerate();
}


// ----------------------------------------------------------------------- //
//
//	ROUTINE:	CTO2GameClientShell::OnEnterWorld()
//
//	PURPOSE:	Handle entering world
//
// ----------------------------------------------------------------------- //

void CTO2GameClientShell::OnEnterWorld()
{
	CGameClientShell::OnEnterWorld();

#ifndef _FINAL
	//override for debugging purposes
	float fVal = 0.0f;
    if (!g_pLTClient) return;

    HCONSOLEVAR hVar = g_pLTClient->GetConsoleVar("LowViolence");
	if(hVar)
	{
        fVal = g_pLTClient->GetVarValueFloat(hVar);
		char buf[128] = "";
		sprintf(buf, "serv LowViolence %f",fVal);
		g_pLTClient->RunConsoleString(buf);
	}


#endif
}