# Microsoft Developer Studio Project File - Name="Launcher" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=LAUNCHER - WIN32 FINAL
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Launcher.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Launcher.mak" CFG="LAUNCHER - WIN32 FINAL"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Launcher - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Launcher - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "Launcher - Win32 Final" (based on "Win32 (x86) Application")
!MESSAGE "Launcher - Win32 Final DE" (based on "Win32 (x86) Application")
!MESSAGE "Launcher - Win32 Final ES" (based on "Win32 (x86) Application")
!MESSAGE "Launcher - Win32 Final IT" (based on "Win32 (x86) Application")
!MESSAGE "Launcher - Win32 Final FR" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "Launcher"
# PROP Scc_LocalPath "..\..\.."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Built\Release\Launcher"
# PROP Intermediate_Dir "..\..\Built\Release\Launcher"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "..\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\regmgr32" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /i "res\lang\en\\" /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /incremental:yes /machine:I386 /out:"..\..\Built\Release\Launcher/NOLF2.exe"
# Begin Custom Build
TargetPath=\Work\TO2\Source\Game\Built\Release\Launcher\NOLF2.exe
InputPath=\Work\TO2\Source\Game\Built\Release\Launcher\NOLF2.exe
SOURCE="$(InputPath)"

"$(GAME_MAIN_DIR)\NOLF2.exe" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_MAIN_DIR) 
	copy $(TargetPath) $(GAME_MAIN_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\Built\Debug\Launcher"
# PROP Intermediate_Dir "..\..\Built\Debug\Launcher"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\regmgr32" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /i "res\lang\en\\" /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /nodefaultlib:"nafxcw.lib" /nodefaultlib:"libcmt.lib" /out:"..\..\Built\Debug\Launcher/NOLF2.exe" /pdbtype:sept
# Begin Custom Build
TargetPath=\Work\TO2\Source\Game\Built\Debug\Launcher\NOLF2.exe
InputPath=\Work\TO2\Source\Game\Built\Debug\Launcher\NOLF2.exe
SOURCE="$(InputPath)"

"$(GAME_MAIN_DIR)\NOLF2.exe" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_MAIN_DIR) 
	copy $(TargetPath) $(GAME_MAIN_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Final"
# PROP BASE Intermediate_Dir "Final"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Built\Final\Launcher"
# PROP Intermediate_Dir "..\..\Built\Final\Launcher"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "..\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\regmgr32" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "..\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\regmgr32" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "_FINAL" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "res\lang\en\\" /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib /nologo /subsystem:windows /incremental:yes /machine:I386 /out:"..\..\Built\Release\Launcher/NOLF2.exe"
# ADD LINK32 /nologo /subsystem:windows /incremental:yes /machine:I386 /out:"..\..\Built\Final\Launcher/NOLF2.exe"
# Begin Custom Build
TargetPath=\Work\TO2\Source\Game\Built\Final\Launcher\NOLF2.exe
InputPath=\Work\TO2\Source\Game\Built\Final\Launcher\NOLF2.exe
SOURCE="$(InputPath)"

"$(GAME_MAIN_DIR)\NOLF2.exe" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_MAIN_DIR) 
	copy $(TargetPath) $(GAME_MAIN_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Launcher___Win32_Final_DE"
# PROP BASE Intermediate_Dir "Launcher___Win32_Final_DE"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Built\FinalDE\Launcher"
# PROP Intermediate_Dir "..\..\Built\FinalDE\Launcher"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "..\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\regmgr32" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "_FINAL" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "..\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\regmgr32" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "_FINAL" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /i "res\lang\en\\" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "res\lang\DE\\" /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /incremental:yes /machine:I386 /out:"..\..\Built\Final\Launcher/NOLF2.exe"
# ADD LINK32 /nologo /subsystem:windows /incremental:yes /machine:I386 /out:"..\..\Built\FinalDE\Launcher/NOLF2.exe"
# Begin Custom Build
TargetPath=\Work\TO2\Source\Game\Built\FinalDE\Launcher\NOLF2.exe
InputPath=\Work\TO2\Source\Game\Built\FinalDE\Launcher\NOLF2.exe
SOURCE="$(InputPath)"

"$(GAME_MAIN_DIR)\NOLF2.exe" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_MAIN_DIR) 
	copy $(TargetPath) $(GAME_MAIN_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Launcher___Win32_Final_ES"
# PROP BASE Intermediate_Dir "Launcher___Win32_Final_ES"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Built\FinalES\Launcher"
# PROP Intermediate_Dir "..\..\Built\FinalES\Launcher"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "..\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\regmgr32" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "_FINAL" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "..\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\regmgr32" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "_FINAL" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /i "res\lang\en\\" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "res\lang\es\\" /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /incremental:yes /machine:I386 /out:"..\..\Built\Final\Launcher/NOLF2.exe"
# ADD LINK32 /nologo /subsystem:windows /incremental:yes /machine:I386 /out:"..\..\Built\FinalES\Launcher/NOLF2.exe"
# Begin Custom Build
TargetPath=\Work\TO2\Source\Game\Built\FinalES\Launcher\NOLF2.exe
InputPath=\Work\TO2\Source\Game\Built\FinalES\Launcher\NOLF2.exe
SOURCE="$(InputPath)"

"$(GAME_MAIN_DIR)\NOLF2.exe" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_MAIN_DIR) 
	copy $(TargetPath) $(GAME_MAIN_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Launcher___Win32_Final_IT"
# PROP BASE Intermediate_Dir "Launcher___Win32_Final_IT"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Built\FinalIT\Launcher"
# PROP Intermediate_Dir "..\..\Built\FinalIT\Launcher"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "..\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\regmgr32" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "_FINAL" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "..\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\regmgr32" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "_FINAL" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /i "res\lang\en\\" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "res\lang\it\\" /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /incremental:yes /machine:I386 /out:"..\..\Built\Final\Launcher/NOLF2.exe"
# ADD LINK32 /nologo /subsystem:windows /incremental:yes /machine:I386 /out:"..\..\Built\FinalIT\Launcher/NOLF2.exe"
# Begin Custom Build
TargetPath=\Work\TO2\Source\Game\Built\FinalIT\Launcher\NOLF2.exe
InputPath=\Work\TO2\Source\Game\Built\FinalIT\Launcher\NOLF2.exe
SOURCE="$(InputPath)"

"$(GAME_MAIN_DIR)\NOLF2.exe" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_MAIN_DIR) 
	copy $(TargetPath) $(GAME_MAIN_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Launcher___Win32_Final_FR"
# PROP BASE Intermediate_Dir "Launcher___Win32_Final_FR"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Built\FinalFR\Launcher"
# PROP Intermediate_Dir "..\..\Built\FinalFR\Launcher"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "..\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\regmgr32" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "_FINAL" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "..\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\regmgr32" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "_FINAL" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /i "res\lang\en\\" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i "res\lang\fr\\" /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /incremental:yes /machine:I386 /out:"..\..\Built\Final\Launcher/NOLF2.exe"
# ADD LINK32 /nologo /subsystem:windows /incremental:yes /machine:I386 /out:"..\..\Built\FinalFR\Launcher/NOLF2.exe"
# Begin Custom Build
TargetPath=\Work\TO2\Source\Game\Built\FinalFR\Launcher\NOLF2.exe
InputPath=\Work\TO2\Source\Game\Built\FinalFR\Launcher\NOLF2.exe
SOURCE="$(InputPath)"

"$(GAME_MAIN_DIR)\NOLF2.exe" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_MAIN_DIR) 
	copy $(TargetPath) $(GAME_MAIN_DIR) 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "Launcher - Win32 Release"
# Name "Launcher - Win32 Debug"
# Name "Launcher - Win32 Final"
# Name "Launcher - Win32 Final DE"
# Name "Launcher - Win32 Final ES"
# Name "Launcher - Win32 Final IT"
# Name "Launcher - Win32 Final FR"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\BitmapCheckButton.cpp
# End Source File
# Begin Source File

SOURCE=..\ButtonEx.cpp
# End Source File
# Begin Source File

SOURCE=..\CustomizeDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\DetailSettingsDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\DisplayDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\DisplayMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\DlgEx.cpp
# End Source File
# Begin Source File

SOURCE=..\EditEx.cpp
# End Source File
# Begin Source File

SOURCE=..\Launcher.cpp
# End Source File
# Begin Source File

SOURCE=..\LauncherDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\MessageBoxDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\MoveDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\OptionsDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\RezFind.cpp
# End Source File
# Begin Source File

SOURCE=..\StaticEx.cpp
# End Source File
# Begin Source File

SOURCE=..\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=..\TextCheckBox.cpp
# End Source File
# Begin Source File

SOURCE=..\Utils.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\BitmapCheckButton.h
# End Source File
# Begin Source File

SOURCE=..\ButtonEx.h
# End Source File
# Begin Source File

SOURCE=..\CustomizeDlg.h
# End Source File
# Begin Source File

SOURCE=..\DetailSettingsDlg.h
# End Source File
# Begin Source File

SOURCE=..\DisplayDlg.h
# End Source File
# Begin Source File

SOURCE=..\DisplayMgr.h
# End Source File
# Begin Source File

SOURCE=..\DlgEx.h
# End Source File
# Begin Source File

SOURCE=..\EditEx.h
# End Source File
# Begin Source File

SOURCE=..\Launcher.h
# End Source File
# Begin Source File

SOURCE=..\LauncherDlg.h
# End Source File
# Begin Source File

SOURCE=..\MessageBoxDlg.h
# End Source File
# Begin Source File

SOURCE=..\MoveDlg.h
# End Source File
# Begin Source File

SOURCE=..\OptionsDlg.h
# End Source File
# Begin Source File

SOURCE=..\PlaySound.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=..\RezFind.h
# End Source File
# Begin Source File

SOURCE=..\StaticEx.h
# End Source File
# Begin Source File

SOURCE=..\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\TextCheckBox.h
# End Source File
# Begin Source File

SOURCE=..\Utils.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Group "snd"

# PROP Default_Filter ".wav"
# Begin Source File

SOURCE=.\RES\snd\AnimDlg.wav
# End Source File
# Begin Source File

SOURCE=.\RES\snd\buttondown.wav
# End Source File
# Begin Source File

SOURCE=.\RES\snd\Click.wav
# End Source File
# Begin Source File

SOURCE=.\RES\snd\Intro.wav
# End Source File
# Begin Source File

SOURCE=.\RES\snd\Select.wav
# End Source File
# Begin Source File

SOURCE=.\RES\snd\type1.WAV
# End Source File
# Begin Source File

SOURCE=.\RES\snd\type2.WAV
# End Source File
# Begin Source File

SOURCE=.\RES\snd\type3.WAV
# End Source File
# Begin Source File

SOURCE=.\RES\snd\TypeBack.wav
# End Source File
# End Group
# Begin Group "bmp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\RES\bmp\BoxBackground.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\bmp\CheckBoxC.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\bmp\CheckBoxF.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\bmp\CheckBoxN.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\bmp\closed.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\bmp\closeu.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\bmp\Error.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\bmp\Information.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\bmp\MinimizeD.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\bmp\MinimizeU.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\bmp\MultiplayerBackground.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\bmp\Warning.bmp
# End Source File
# End Group
# Begin Group "Localized Files"

# PROP Default_Filter ""
# Begin Group "EN"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\BackD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\BackF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\BackU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\CancelD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\CancelF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\CancelU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\Company1WebD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\Company1WebF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\Company1WebU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\Company2WebD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\Company2WebF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\Company2WebU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\DemoMainAppBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\DetailSettingsBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\DisplayBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\DisplayD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\DisplayF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\DisplayU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\DisplayX.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\HelpD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\HelpF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\HelpU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\HighDetailD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\HighDetailF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\HighDetailU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\InstallD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\InstallF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\InstallU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\Launcher.rc

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\LowDetailD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\LowDetailF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\LowDetailU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\MainAppBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\MediumDetailD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\MediumDetailF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\MediumDetailU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\OKD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\OkF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\OKU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\OptionsBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\optionsd.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\OptionsF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\optionsu.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\OptionsX.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\PlayD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\PlayF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\PlayU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\Publisher1WebD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\Publisher1WebF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\Publisher1WebU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\Publisher2WebD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\Publisher2WebF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\Publisher2WebU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\QuitD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\QuitF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\QuitU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\ServerD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\ServerF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\ServerU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\ServerX.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\UninstallD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\UninstallF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\UninstallU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\UninstallX.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "ES"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\BackD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\BackF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\BackU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\CancelD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\CancelF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\CancelU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\Company1WebD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\Company1WebF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\Company1WebU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\Company2WebD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\Company2WebF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\Company2WebU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\DemoMainAppBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\DetailSettingsBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\DisplayBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\DisplayD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\DisplayF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\DisplayU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\DisplayX.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\HelpD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\HelpF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\HelpU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\HighDetailD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\HighDetailF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\HighDetailU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\InstallD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\InstallF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\InstallU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\Launcher.rc

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\LowDetailD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\LowDetailF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\LowDetailU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\MainAppBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\MediumDetailD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\MediumDetailF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\MediumDetailU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\OKD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\OkF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\OKU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\OptionsBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\optionsd.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\OptionsF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\optionsu.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\OptionsX.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\PlayD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\PlayF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\PlayU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\Publisher1WebD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\Publisher1WebF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\Publisher1WebU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\Publisher2WebD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\Publisher2WebF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\Publisher2WebU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\QuitD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\QuitF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\QuitU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\ServerD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\ServerF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\ServerU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\ServerX.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\UninstallD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\UninstallF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\UninstallU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\ES\bmp\UninstallX.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "DE"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\BackD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\BackF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\BackU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\CancelD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\CancelF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\CancelU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\Company1WebD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\Company1WebF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\Company1WebU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\Company2WebD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\Company2WebF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\Company2WebU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\DemoMainAppBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\DetailSettingsBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\DisplayBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\DisplayD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\DisplayF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\DisplayU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\DisplayX.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\HelpD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\HelpF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\HelpU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\HighDetailD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\HighDetailF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\HighDetailU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\InstallD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\InstallF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\InstallU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\Launcher.rc

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\LowDetailD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\LowDetailF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\LowDetailU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\MainAppBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\MediumDetailD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\MediumDetailF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\MediumDetailU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\OKD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\OkF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\OKU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\OptionsBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\optionsd.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\OptionsF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\optionsu.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\OptionsX.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\PlayD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\PlayF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\PlayU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\Publisher1WebD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\Publisher1WebF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\Publisher1WebU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\Publisher2WebD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\Publisher2WebF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\Publisher2WebU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\QuitD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\QuitF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\QuitU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\ServerD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\ServerF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\ServerU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\ServerX.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\UninstallD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\UninstallF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\UninstallU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\DE\bmp\UninstallX.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "IT"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\BackD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\BackF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\BackU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\CancelD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\CancelF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\CancelU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\Company1WebD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\Company1WebF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\Company1WebU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\Company2WebD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\Company2WebF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\Company2WebU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\DemoMainAppBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\DetailSettingsBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\DisplayBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\DisplayD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\DisplayF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\DisplayU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\DisplayX.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\HelpD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\HelpF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\HelpU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\HighDetailD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\HighDetailF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\HighDetailU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\InstallD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\InstallF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\InstallU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\Launcher.rc

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\LowDetailD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\LowDetailF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\LowDetailU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\MainAppBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\MediumDetailD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\MediumDetailF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\MediumDetailU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\OKD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\OkF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\OKU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\OptionsBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\optionsd.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\OptionsF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\optionsu.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\OptionsX.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\PlayD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\PlayF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\PlayU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\Publisher1WebD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\Publisher1WebF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\Publisher1WebU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\Publisher2WebD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\Publisher2WebF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\Publisher2WebU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\QuitD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\QuitF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\QuitU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\ServerD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\ServerF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\ServerU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\ServerX.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\UninstallD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\UninstallF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\UninstallU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\IT\bmp\UninstallX.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "FR"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\BackD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\BackF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\BackU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\CancelD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\CancelF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\CancelU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\Company1WebD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\Company1WebF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\Company1WebU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\Company2WebD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\Company2WebF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\Company2WebU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\DemoMainAppBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\DetailSettingsBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\DisplayBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\DisplayD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\DisplayF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\DisplayU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\DisplayX.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\HelpD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\HelpF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\HelpU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\HighDetailD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\HighDetailF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\HighDetailU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\InstallD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\InstallF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\InstallU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\Launcher.rc

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\LowDetailD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\LowDetailF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\LowDetailU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\MainAppBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\MediumDetailD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\MediumDetailF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\MediumDetailU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\OKD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\OkF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\OKU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\OptionsBackground.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\optionsd.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\OptionsF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\optionsu.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\OptionsX.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\PlayD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\PlayF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\PlayU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\Publisher1WebD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\Publisher1WebF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\Publisher1WebU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\Publisher2WebD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\Publisher2WebF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\Publisher2WebU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\QuitD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\QuitF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\QuitU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\ServerD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\ServerF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\ServerU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\ServerX.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\UninstallD.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\UninstallF.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\UninstallU.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RES\Lang\FR\bmp\UninstallX.bmp

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# End Group
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\CustomBackground.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\CustomD.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\CustomF.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\CustomizeBackground.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\CustomizeD.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\CustomizeF.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\CustomizeU.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\CustomizeX.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\CustomU.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\CustomX.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\Launcher.ico
# End Source File
# Begin Source File

SOURCE=.\RES\Launcher.rc2
# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\NextF.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\NextlD.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\NextU.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\PreviousD.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\PreviousF.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\PreviousU.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\Lang\EN\bmp\PreviousX.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\WebHand.cur
# End Source File
# End Group
# Begin Group "Libs_Debug"

# PROP Default_Filter "lib"
# Begin Source File

SOURCE=..\..\..\libs\built\Debug\RegMgr32\regmgr32.lib

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "Libs_Release"

# PROP Default_Filter "lib"
# Begin Source File

SOURCE=..\..\..\libs\built\Release\RegMgr32\regmgr32.lib

!IF  "$(CFG)" == "Launcher - Win32 Release"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "Libs_Final"

# PROP Default_Filter "lib"
# Begin Source File

SOURCE=..\..\..\libs\built\Final\RegMgr32\regmgr32.lib

!IF  "$(CFG)" == "Launcher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final DE"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final ES"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final IT"

!ELSEIF  "$(CFG)" == "Launcher - Win32 Final FR"

!ENDIF 

# End Source File
# End Group
# End Target
# End Project
