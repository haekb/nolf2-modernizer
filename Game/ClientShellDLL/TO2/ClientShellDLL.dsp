# Microsoft Developer Studio Project File - Name="ClientShellDLL" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=ClientShellDLL - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ClientShellDLL.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ClientShellDLL.mak" CFG="ClientShellDLL - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ClientShellDLL - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ClientShellDLL - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ClientShellDLL - Win32 Final" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/Source (TO2)/ClientShellDLL", RQRFAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Built\Release\ClientShellDll\TO2"
# PROP Intermediate_Dir "..\..\Built\Release\ClientShellDll\TO2"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\Shared\TO2" /I ".\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\ClientShellShared" /I "..\..\clientres\shared" /I "..\..\clientres\TO2" /I "..\..\shared" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\stdlith" /I "..\..\..\libs\butemgr" /I "..\..\..\libs\cryptmgr" /I "..\..\..\libs\lith" /I "..\..\..\libs\mfcstub" /I "..\..\libs\ltguimgr" /I "..\..\..\libs\regmgr" /I "..\..\libs\wonapi" /I "..\..\libs\serverdir" /D "NDEBUG" /D "_CLIENTBUILD" /D "WIN32" /D "_WINDOWS" /D "_NOLFBUILD" /D "NO_PRAGMA_LIBS" /D "NOPS2" /D "MEMTRACK_CLIENT" /Yu"stdafx.h" /FD /Zm1000 /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 winmm.lib ole32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /nodefaultlib:"LIBCMTD" /out:"..\..\Built\Release\ClientShellDll\TO2\CShell.dll"
# SUBTRACT LINK32 /pdb:none /map
# Begin Custom Build
TargetPath=\proj\to2\source\Game\Built\Release\ClientShellDll\TO2\CShell.dll
InputPath=\proj\to2\source\Game\Built\Release\ClientShellDll\TO2\CShell.dll
SOURCE="$(InputPath)"

"$(GAME_REZ_DIR)\cshell.dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_REZ_DIR) 
	copy $(TargetPath) $(GAME_REZ_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\Built\Debug\ClientShellDll\TO2"
# PROP Intermediate_Dir "..\..\Built\Debug\ClientShellDll\TO2"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MDd /W3 /GX /ZI /Od /I "..\..\Shared\TO2" /I ".\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\ClientShellShared" /I "..\..\clientres\shared" /I "..\..\clientres\TO2" /I "..\..\shared" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\stdlith" /I "..\..\..\libs\butemgr" /I "..\..\..\libs\cryptmgr" /I "..\..\..\libs\lith" /I "..\..\..\libs\mfcstub" /I "..\..\libs\ltguimgr" /I "..\..\..\libs\regmgr" /I "..\..\libs\wonapi" /I "..\..\libs\serverdir" /D "_DEBUG" /D "_CLIENTBUILD" /D "WIN32" /D "_WINDOWS" /D "NOPS2" /D "MEMTRACK_CLIENT" /FR /Yu"stdafx.h" /FD /Zm1000 /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 winmm.lib ole32.lib wsock32.lib kernel32.lib user32.lib gdi32.lib advapi32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"..\..\Built\Debug\ClientShellDll\TO2\CShell.dll" /pdbtype:sept
# SUBTRACT LINK32 /verbose /pdb:none
# Begin Custom Build
TargetPath=\proj\to2\source\Game\Built\Debug\ClientShellDll\TO2\CShell.dll
InputPath=\proj\to2\source\Game\Built\Debug\ClientShellDll\TO2\CShell.dll
SOURCE="$(InputPath)"

"$(GAME_REZ_DIR)\cshell.dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_REZ_DIR) 
	copy $(TargetPath) $(GAME_REZ_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Final"
# PROP BASE Intermediate_Dir "Final"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Built\Final\ClientShellDll\TO2"
# PROP Intermediate_Dir "..\..\Built\Final\ClientShellDll\TO2"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "..\..\Shared\TO2" /I ".\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\ClientShellShared" /I "..\..\clientres\shared" /I "..\..\clientres\TO2" /I "..\..\shared" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\stdlith" /I "..\..\..\libs\butemgr" /I "..\..\..\libs\cryptmgr" /I "..\..\..\libs\lith" /I "..\..\..\libs\mfcstub" /I "..\..\libs\ltguimgr" /I "..\..\..\libs\regmgr" /I "..\..\libs\wonapi" /I "..\..\libs\serverdir" /D "NDEBUG" /D "_CLIENTBUILD" /D "WIN32" /D "_WINDOWS" /D "_NOLFBUILD" /D "NO_PRAGMA_LIBS" /D "NOPS2" /D "_FINAL" /Yu"stdafx.h" /FD /Zm1000 /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\Shared\TO2" /I ".\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\ClientShellShared" /I "..\..\clientres\shared" /I "..\..\clientres\TO2" /I "..\..\shared" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\stdlith" /I "..\..\..\libs\butemgr" /I "..\..\..\libs\cryptmgr" /I "..\..\..\libs\lith" /I "..\..\..\libs\mfcstub" /I "..\..\libs\ltguimgr" /I "..\..\..\libs\regmgr" /I "..\..\libs\wonapi" /I "..\..\libs\serverdir" /D "NDEBUG" /D "_CLIENTBUILD" /D "WIN32" /D "_WINDOWS" /D "_NOLFBUILD" /D "NO_PRAGMA_LIBS" /D "NOPS2" /D "_FINAL" /D "MEMTRACK_CLIENT" /Yu"stdafx.h" /FD /Zm1000 /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 ole32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /nodefaultlib:"LIBCMTD" /out:"..\..\Built\Final\ClientShellDll\TO2\CShell.dll"
# SUBTRACT BASE LINK32 /pdb:none /map
# ADD LINK32 winmm.lib ole32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /nodefaultlib:"LIBCMTD" /out:"..\..\Built\Final\ClientShellDll\TO2\CShell.dll"
# SUBTRACT LINK32 /pdb:none /map
# Begin Custom Build
TargetPath=\proj\to2\source\Game\Built\Final\ClientShellDll\TO2\CShell.dll
InputPath=\proj\to2\source\Game\Built\Final\ClientShellDll\TO2\CShell.dll
SOURCE="$(InputPath)"

"$(GAME_REZ_DIR)\cshell.dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_REZ_DIR) 
	copy $(TargetPath) $(GAME_REZ_DIR) 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "ClientShellDLL - Win32 Release"
# Name "ClientShellDLL - Win32 Debug"
# Name "ClientShellDLL - Win32 Final"
# Begin Group "Source"

# PROP Default_Filter "*.cpp"
# Begin Source File

SOURCE=.\GlobalsInit.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDAir.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDAmmo.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDCarrying.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDChooser.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDCompass.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDCrosshair.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDDamageDir.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDDoomsday.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDHiding.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDHidingBar.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDObjectives.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDProgressBar.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDRadio.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDRespawn.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iltbaseclass.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltmodule.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\..\engine\sdk\inc\ltobjref.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltquatbase.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\ScreenAudio.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenConfigure.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenControls.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenCrosshair.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenDisplay.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenEndCoopMission.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenEndDMMission.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenEndMission.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenFailure.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenGame.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenHost.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenHostDDOptions.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenHostDMOptions.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenHostLevels.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenHostMission.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenHostOptions.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenHostTDMOptions.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenHostWeapons.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenJoin.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenJoinLAN.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenJoystick.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenKeyboard.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenLoad.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenMain.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenMouse.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenMulti.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenOptions.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenPerformance.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenPlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenPlayerSkills.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenPlayerTeam.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenProfile.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenSave.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenSingle.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenTeam.cpp
# End Source File
# Begin Source File

SOURCE=.\Stdafx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TO2ClientWeaponAllocator.cpp
# End Source File
# Begin Source File

SOURCE=.\TO2ClientWeaponAllocator.h
# End Source File
# Begin Source File

SOURCE=.\TO2GameClientShell.cpp
# End Source File
# Begin Source File

SOURCE=.\TO2HUDMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\TO2InterfaceMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\TO2LayoutMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TO2\TO2MissionButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\TO2PlayerMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\TO2PlayerStats.cpp
# End Source File
# Begin Source File

SOURCE=.\TO2ScreenMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TO2\TO2VersionMgr.cpp
# End Source File
# End Group
# Begin Group "Headers"

# PROP Default_Filter "*.h"
# Begin Source File

SOURCE=.\HUDAir.h
# End Source File
# Begin Source File

SOURCE=.\HUDAmmo.h
# End Source File
# Begin Source File

SOURCE=.\HUDCarrying.h
# End Source File
# Begin Source File

SOURCE=.\HUDChooser.h
# End Source File
# Begin Source File

SOURCE=.\HUDCompass.h
# End Source File
# Begin Source File

SOURCE=.\HUDCrosshair.h
# End Source File
# Begin Source File

SOURCE=.\HUDDamageDir.h
# End Source File
# Begin Source File

SOURCE=.\HUDDoomsday.h
# End Source File
# Begin Source File

SOURCE=.\HUDHiding.h
# End Source File
# Begin Source File

SOURCE=.\HUDHidingBar.h
# End Source File
# Begin Source File

SOURCE=.\HUDObjectives.h
# End Source File
# Begin Source File

SOURCE=.\HUDProgressBar.h
# End Source File
# Begin Source File

SOURCE=.\HUDRadio.h
# End Source File
# Begin Source File

SOURCE=.\HUDRespawn.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iltbaseclass.h
# End Source File
# Begin Source File

SOURCE=..\..\Libs\ServerDir\IServerDir.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltmodule.h
# End Source File
# Begin Source File

SOURCE=..\..\..\engine\sdk\inc\ltobjref.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\LTPoly.h
# End Source File
# Begin Source File

SOURCE=.\ScreenAudio.h
# End Source File
# Begin Source File

SOURCE=.\ScreenConfigure.h
# End Source File
# Begin Source File

SOURCE=.\ScreenControls.h
# End Source File
# Begin Source File

SOURCE=.\ScreenCrosshair.h
# End Source File
# Begin Source File

SOURCE=.\ScreenDisplay.h
# End Source File
# Begin Source File

SOURCE=.\ScreenEndCoopMission.h
# End Source File
# Begin Source File

SOURCE=.\ScreenEndDMMission.h
# End Source File
# Begin Source File

SOURCE=.\ScreenEndMission.h
# End Source File
# Begin Source File

SOURCE=.\ScreenFailure.h
# End Source File
# Begin Source File

SOURCE=.\ScreenGame.h
# End Source File
# Begin Source File

SOURCE=.\ScreenHost.h
# End Source File
# Begin Source File

SOURCE=.\ScreenHostDDOptions.h
# End Source File
# Begin Source File

SOURCE=.\ScreenHostDMOptions.h
# End Source File
# Begin Source File

SOURCE=.\ScreenHostLevels.h
# End Source File
# Begin Source File

SOURCE=.\ScreenHostMission.h
# End Source File
# Begin Source File

SOURCE=.\ScreenHostOptions.h
# End Source File
# Begin Source File

SOURCE=.\ScreenHostTDMOptions.h
# End Source File
# Begin Source File

SOURCE=.\ScreenHostWeapons.h
# End Source File
# Begin Source File

SOURCE=.\ScreenJoin.h
# End Source File
# Begin Source File

SOURCE=.\ScreenJoinLAN.h
# End Source File
# Begin Source File

SOURCE=.\ScreenJoystick.h
# End Source File
# Begin Source File

SOURCE=.\ScreenKeyboard.h
# End Source File
# Begin Source File

SOURCE=.\ScreenLoad.h
# End Source File
# Begin Source File

SOURCE=.\ScreenMain.h
# End Source File
# Begin Source File

SOURCE=.\ScreenMouse.h
# End Source File
# Begin Source File

SOURCE=.\ScreenMulti.h
# End Source File
# Begin Source File

SOURCE=.\ScreenOptions.h
# End Source File
# Begin Source File

SOURCE=.\ScreenPerformance.h
# End Source File
# Begin Source File

SOURCE=.\ScreenPlayer.h
# End Source File
# Begin Source File

SOURCE=.\ScreenPlayerSkills.h
# End Source File
# Begin Source File

SOURCE=.\ScreenPlayerTeam.h
# End Source File
# Begin Source File

SOURCE=.\ScreenProfile.h
# End Source File
# Begin Source File

SOURCE=.\ScreenSave.h
# End Source File
# Begin Source File

SOURCE=.\ScreenSingle.h
# End Source File
# Begin Source File

SOURCE=.\ScreenTeam.h
# End Source File
# Begin Source File

SOURCE=.\Stdafx.h
# End Source File
# Begin Source File

SOURCE=.\TO2GameClientShell.h
# End Source File
# Begin Source File

SOURCE=.\TO2HUDMgr.h
# End Source File
# Begin Source File

SOURCE=.\TO2InterfaceMgr.h
# End Source File
# Begin Source File

SOURCE=.\TO2LayoutMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TO2\TO2MissionButeMgr.h
# End Source File
# Begin Source File

SOURCE=.\TO2PlayerMgr.h
# End Source File
# Begin Source File

SOURCE=.\TO2PlayerStats.h
# End Source File
# Begin Source File

SOURCE=.\TO2ScreenMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TO2\TO2VersionMgr.h
# End Source File
# End Group
# Begin Group "libs_debug"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\built\Debug\ClientShellDLL\ClientShellShared\ClientShellShared.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Debug\ButeMgr\ButeMgr.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Debug\MFCStub\MFCStub.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Debug\CryptMgr\cryptmgr.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Debug\Lib_StdLith\Lib_StdLith.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Debug\Lib_Lith\Lib_Lith.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\Built\Debug\libs\LTGuiMgr\ltguimgr.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libs\ServerDir\debug\ServerDir.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Debug\RegMgr\regmgr.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "libs_release"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\built\Release\ClientShellDll\ClientShellShared\ClientShellShared.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Release\ButeMgr\ButeMgr.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Release\MFCStub\MFCStub.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Release\CryptMgr\cryptmgr.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Release\Lib_StdLith\Lib_StdLith.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Release\Lib_Lith\Lib_Lith.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\Built\Release\libs\LTGuiMgr\ltguimgr.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libs\ServerDir\release\ServerDir.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Release\RegMgr\regmgr.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "libs_final"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\built\Final\ClientShellDll\ClientShellShared\ClientShellShared.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Final\MFCStub\MFCStub.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Final\CryptMgr\cryptmgr.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Final\Lib_StdLith\Lib_StdLith.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Final\Lib_Lith\Lib_Lith.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\Built\Final\libs\LTGuiMgr\ltguimgr.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libs\ServerDir\final\ServerDir.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Final\RegMgr\regmgr.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Final\ButeMgr\ButeMgr.lib

!IF  "$(CFG)" == "ClientShellDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientShellDLL - Win32 Final"

!ENDIF 

# End Source File
# End Group
# Begin Group "libs_finaldemo"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\built\FinalDemo\ClientShellDLL\ClientShellShared\ClientShellShared.lib
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "libs_debugfinaldemo"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\built\DebugFinalDemo\ClientShellDLL\ClientShellShared\ClientShellShared.lib
# PROP Exclude_From_Build 1
# End Source File
# End Group
# End Target
# End Project
