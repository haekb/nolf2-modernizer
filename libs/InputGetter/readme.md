# Input Getter

Note: If you're making a Lithtech source port, you can probably completely remove this dll. Do it the right way!

Problem: Lithtech will stop any raw input reading. I've tried an alternate approach with mouse warping and it doesn't work too well on other machines.

Solution: This hack.

This DLL creates a hidden window, registers raw input, and stores the latest mouse information. The application (NOLF 2) will then read the mouse information.
Because SDL2 does this pretty much automatically, I'm just using `SDL_CreateWindow`, `SDL_SetRelativeMouseMode`, and `SDL_GetRelativeMouseState`.

## API

### Init
`int InputGetter::Init()`

This function will create the hidden window, and initialize anything that requires it.

Returns: 
 - INIT_OK on success
 - INIT_ALREADY_INIT if the dll is already init
 - INIT_CANT_SDL_INIT if the SDL2 init failed
 - INIT_CANT_CREATE_WINDOW if SDL2 failed to create a window for some reason

### Set Mouse Mode
`void InputGetter::SetMouseMode(bool useRawInput)`

This function will switch on/off `SDL_SetRelativeMouseMode`. 
Note: You'll probably also want to run `SDL_SetRelativeMouseMode` on your application as well.

### Read Mouse Position
`void InputGetter::ReadMousePosition(int *x, int *y)`

This function will read the stored mouse coordinates from `SDL_GetRelativeMouseState`. 
Note: If Set Mouse Mode is false, then these values will be 0.

### Shutdown
`void InputGetter::Shutdown()`

Cleans up any SDL2 windows, and events.