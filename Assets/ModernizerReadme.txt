No One Lives Forever 2 Modernizer - Beta 2
---------------------------------
The goal of NOLF 2 Modernizer is to help fix some long standing bugs, and update some more outdated features of the game.

The beta releases are meant to get this mod out the door sooner! 
However there's sure to be bugs, and probably bugs in the base game that I didn't catch. 
Before commenting about a crash, please check the known issues section for more information!

Requirements:
You'll need to install VC++2019 Redist before playing, if you have Windows 10 you should be good, but just in case you can check here:
https://support.microsoft.com/en-us/help/2977003/the-latest-supported-visual-c-downloads

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
 - Game updates are automatically checked in the Multiplayer Menu

Beta 2 Fixes:
 - Added a hopefully functional dedicated server
 - Fixed the server browser not displaying servers (You had one job!!)
 - Fixed scopes and most other overlays
 - Fixed view models being slightly stretched
 - Found and replanted the missing foilage
 - Lots of HUD stretching/position fixes
 - Added some experimental options

Known Issues:
    The following might not be fixable:
     - Anti-aliasing causes a ~1 pixel offset at the edges of 2d elements
     - Jukebox Singles take a full second to load
     - Due to how the input system was re-written, all controls are now saved in controls.cfg. This doesn't work with the base game so it's not compatiable with any other mods!

    The following can be fixed in a future patch:
     - Cate's missing from the main menu, we don't know where she went!
     - Jukebox can occasionally crash while switching songs
     - Jukebox songs are sorted in alphabetical order
     - Some Jukebox Singles have duplicate songs
     - Controller support is only supported during gameplay, it doesn't work on menus
     - Switching to a lower resolution from a fullscreen windowed mode can make the window get stuck in borderless mode
     - Almost certainly there's a multiplayer browser crash in there somewhere!
     - Music can sometimes be a little jumpy (I've been told the base game had this issue too, but I'm looking into it!)

Misc Notes:
 - Controller support is pretty bare bones, this will be touched up in a future patch
 - Controller support is not entirely "supported" during the beta releases
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

Dedicated Server Information:
The dedicated server will automatically load up modernizer. If you'd like to include additional .rez files you can add them with the `-rez <rez>` argument.

Server Hosting Information:
You'll need to open the port you're hosting your server on AND the port immediately above it. 

Example: If you're hosting on port 27888, you'll also need to open 27889. 

Special Thanks:
 - My Partner - For putting up with quite a few late nights
 - Nathan Grigg & Monolith Mark - For getting me some wonderful song title suggestions
 - SPAWN - For his immense help with testing & organizing the multiplayer community (Check out his site https://www.spawnsite.net)
 - Everyone at LithFAQ - Because they're all such a helpful bunch
 - <Space Intentionally Left Blank> - To whoever actually brings NOLF back from legal hell
 - And You - For enjoying such a fantastic forgotten gem