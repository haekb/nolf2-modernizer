No One Lives Forever 2 Modernizer
---------------------------------
The goal of NOLF 2 Modernizer is to help fix some long standing bugs, and update some more outdated features of the game.

Install Instructions:
 - Extract all files to your NOLF 2 directory
 - Run NOLF2.exe
 - Select "Custom"
 - Make sure "Modernizer" is the only item checked
 - Run the game and enjoy!

Features:
 - Widescreen support
 - Re-implemented several graphic effects including anti-aliasing
 - Rewrote the entire input system
 - Marginally better controller support
 - Jukebox to play some of your favourite in-game tunes
 - Several original game crashes have been fixed

Known Issues:
    The following might not be fixable:
     - Anti-aliasing causes a 1 pixel offset at the edges of 2d elements
     - Jukebox Singles take a full second to load

    The following can be fixed in a future patch:
     - Jukebox can occasionally crash while switching songs
     - Jukebox songs are sorted in alphabetical order
     - Some Jukebox Singles have duplicate songs
     - Some cutscenes (with 4:3 mode disabled) contain overlays that don't have black bars
     - Controller support is only supported during gameplay, it doesn't work on menus

Misc Notes:
 - Controller support is pretty bare bones, this will be touched up in a future patch
 - Most of the controller is rebindable except for the rotation/view axis (Right Stick), you'll have to do that manually in controls.cfg!

Controller Code Labels:
Below is a list of controller codes and what they are on the controller.
this is based off of the basic Xbox 360/One controller. However a PS4 or other controller should work fine!

##1 = A
##2 = B
##3 = X
##4 = Y
##5 = Back
##6 = Guide
##7 = Start
##8 = Left Stick
##9 = Right Stick
##10 = Left Shoulder
##11 = Right Shoulder
##12 = DPad Up
##13 = DPad Down
##14 = DPad Left
##15 = DPad Right
##16 = Left Axis X
##17 = Left Axis Y
##18 = Right Axis X
##19 = Right Axis Y
##20 = Left Trigger
##21 = Right Trigger

Custom Controller Mappings:
The new input system was written to take advantage of SDL2's game controller api. This enables non-xinput devices to work as if they were xinput devices. If your controller won't work you could try community bindings located [here](https://github.com/gabomdq/SDL_GameControllerDB/).
Simply drop the `gamecontrollerdb.txt` file into your NOLF 2 game folder and Modernizer will attempt to load it on start-up.

Special Thanks:
    My Partner - For putting up with quite a few late nights
    Nathan Grigg & Monolith Mark - For getting me some wonderful song title suggestions
    SPAWN - For his immense help with testing & organizing the multiplayer community
    Everyone at LithFAQ - Because they're all such a helpful bunch
    <Space Intentionally Left Blank> - To whoever actually brings NOLF back from legal hell