#include "pch.h"
#include <SDL.h>
#include "include/InputGetter.h"

namespace InputGetter
{
	SDL_Window* g_pWindow = nullptr;
	bool g_bUseRawInput = false;

	int Init()
	{
		if (g_pWindow)
		{
			return INIT_ALREADY_INIT;
		}

		auto ret = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

		if (ret)
		{
			return INIT_CANT_SDL_INIT;
		}

		g_pWindow = SDL_CreateWindow("InputGetter - For NOLF2M!", 0, 0, 0, 0, SDL_WINDOW_HIDDEN);

		if (!g_pWindow)
		{
			return INIT_CANT_CREATE_WINDOW;
		}

		return INIT_OK;
	}

	void SetMouseMode(bool useRawInput)
	{
		g_bUseRawInput = useRawInput;

		SDL_SetRelativeMouseMode((SDL_bool)useRawInput);
	}

	void ReadMousePosition(int* x, int* y)
	{
		if (!g_bUseRawInput)
		{
			if (x)
			{
				x = 0;
			}

			if (y)
			{
				y = 0;
			}

			return;
		}

		SDL_GetRelativeMouseState(x, y);
	}

	void Shutdown()
	{
		SDL_DestroyWindow(g_pWindow);
		g_pWindow = nullptr;

		SDL_Quit();
	}

};
