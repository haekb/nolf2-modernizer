#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>

#ifndef __IGAPI
#define __IGAPI   __declspec( dllexport )
#endif

namespace InputGetter
{

	// Some return statuses
#define INIT_OK 0
#define INIT_ALREADY_INIT 1
#define INIT_CANT_SDL_INIT 2
#define INIT_CANT_CREATE_WINDOW 3

	// 
	__IGAPI int Init();
	__IGAPI void SetMouseMode(bool useRawInput);
	__IGAPI void ReadMousePosition(int* x, int* y);
	__IGAPI void Shutdown();
};

