# No One Lives Forever 2 Modernizer

[![Build Status](https://dev.azure.com/heytherecoffee/NOLF2-Modernizer/_apis/build/status/haekb.nolf2-modernizer?branchName=master)](https://dev.azure.com/heytherecoffee/NOLF2-Modernizer/_build/latest?definitionId=4&branchName=master)

The goal of NOLF 2 Modernizer is to help fix some long standing bugs, and update some more outdated features of the game.

## Features

 - Widescreen support
 - Re-implemented several graphic effects including anti-aliasing
 - Fixed weird mouse behaviour
 - Jukebox to play some of your favourite in-game tunes
 - Several original game crashes have been fixed
 - Fixed dynamic music transitions on framerates higher than 100fps

## Building

You can now compile it using Visual Studio 2019 (Requires C++ and MFC), thanks to the NOLF2's sdk including some key files. They're all included and ready to compile.

The following build configurations are setup to build: 
 - Debug
 - Final

If you experience any issues, feel free to open an issue.

## Contributing

Simply fork and submit a PR (preferbly with a matching issue ticket!) 

Try to keep to the original coding style, with descriptive commit messages.

## Localization

There have been community efforts to localize Modernizer into other languages. And while I don't have the time to directly help in these efforts, here are some steps you can do you to localize and distribute your localization patch!

First off modify the string table located in CRes.dll (Client Resource). This can be done with the latest version of Visual Studio 2019 and this source code. You may also attempt to use other programs to modify the string table directly in the dll. 

Secondly there are some additional strings in Jukebox.txt located here: https://github.com/haekb/nolf2-modernizer/blob/master/Assets/Attributes/Jukebox.txt) 

Finally compile your new CRes.dll and the modified attribute file into its own rez using LithRez.exe (from the SDK) and make sure it loads after Modernizer.rez.

## License

This code is still bound to the original EULA found in the NOLF 2 Tools (VERSION 1.0). This can be viewed in the EULA.html file.

Additionally there's several open source licenses available to view in the osslicense.txt file.