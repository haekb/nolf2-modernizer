// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "JServerDir.h"

JServerDir* g_pServerDir;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		g_pServerDir = NULL;
		break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
		break;
    case DLL_PROCESS_DETACH:
		if (g_pServerDir) {
			delete g_pServerDir;
			g_pServerDir = NULL;
		}
        break;
    }
    return TRUE;
}



// Create an IServerDirectory interface for the Titan API
// (delete it when you're finished)
// PARAMETER:	bClientSide			- Set to true if instantiated on the client.
// PARAMETER:	ltCSBase			- used by serverdir so it can talk to the engine directly.
// PARAMETER:	hResourceModule		- optional resource module to use with error strings.
SERVERDIR_API IServerDirectory* Factory_Create_IServerDirectory_Titan(bool bClientSide, ILTCSBase& ltCSBase, HMODULE hResourceModule)
{
	g_pServerDir = new JServerDir();
	return (IServerDirectory*)g_pServerDir;
}