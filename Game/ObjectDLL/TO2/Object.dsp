# Microsoft Developer Studio Project File - Name="Object" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=Object - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Object.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Object.mak" CFG="Object - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Object - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Object - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Object - Win32 Final" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "Object"
# PROP Scc_LocalPath "..\..\.."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Object - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Built\Release\ObjectDLL\TO2"
# PROP Intermediate_Dir "..\..\Built\Release\ObjectDLL\TO2"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "..\objectshared" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\shared" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\stdlith" /I "..\..\..\libs\butemgr" /I "..\..\..\libs\cryptmgr" /I "..\..\..\libs\lith" /I "..\..\..\libs\mfcstub" /I "..\..\..\libs\regmgr" /I "..\..\libs" /I "..\..\Shared\TO2" /I "..\..\libs\serverdir" /D "NDEBUG" /D "_NOLFBUILD" /D "USE_INTEL_COMPILER" /D "WIN32" /D "_WINDOWS" /D "NOPS2" /D "_SERVERBUILD" /D "MEMTRACK_SERVER" /Yu"stdafx.h" /FD /Zm1000 /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"..\..\Built\Release\ObjectDLL\TO2\Object.lto"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build
TargetPath=\proj\to2\source\Game\Built\Release\ObjectDLL\TO2\Object.lto
InputPath=\proj\to2\source\Game\Built\Release\ObjectDLL\TO2\Object.lto
SOURCE="$(InputPath)"

"$(GAME_REZ_DIR)\object.lto" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_REZ_DIR) 
	copy $(TargetPath) $(GAME_REZ_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\Built\Debug\ObjectDLL\TO2"
# PROP Intermediate_Dir "..\..\Built\Debug\ObjectDLL\TO2"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\Shared\TO2" /I ".\\" /I "..\objectshared" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\shared" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\stdlith" /I "..\..\..\libs\butemgr" /I "..\..\..\libs\cryptmgr" /I "..\..\..\libs\lith" /I "..\..\..\libs\mfcstub" /I "..\..\..\libs\regmgr" /I "..\..\libs" /I "..\..\libs\serverdir" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "NOPS2" /D "_SERVERBUILD" /D "MEMTRACK_SERVER" /FR /Yu"stdafx.h" /FD /Zm1000 /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"..\..\Built\Debug\ObjectDLL\TO2\Object.lto" /pdbtype:sept
# SUBTRACT LINK32 /verbose /pdb:none /incremental:no /map
# Begin Custom Build
TargetPath=\proj\to2\source\Game\Built\Debug\ObjectDLL\TO2\Object.lto
InputPath=\proj\to2\source\Game\Built\Debug\ObjectDLL\TO2\Object.lto
SOURCE="$(InputPath)"

"$(GAME_REZ_DIR)\object.lto" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_REZ_DIR) 
	copy $(TargetPath) $(GAME_REZ_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Final"
# PROP BASE Intermediate_Dir "Final"
# PROP BASE Ignore_Export_Lib 1
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Built\Final\ObjectDLL\TO2"
# PROP Intermediate_Dir "..\..\Built\Final\ObjectDLL\TO2"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "..\objectshared" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\shared" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\stdlith" /I "..\..\..\libs\butemgr" /I "..\..\..\libs\cryptmgr" /I "..\..\..\libs\lith" /I "..\..\..\libs\mfcstub" /I "..\..\..\libs\regmgr" /I "..\..\libs" /I "..\..\Shared\TO2" /I "..\..\libs\serverdir" /D "NDEBUG" /D "_NOLFBUILD" /D "USE_INTEL_COMPILER" /D "WIN32" /D "_WINDOWS" /D "NOPS2" /D "_SERVERBUILD" /D "_FINAL" /Yu"stdafx.h" /FD /Zm1000 /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "..\objectshared" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\shared" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\stdlith" /I "..\..\..\libs\butemgr" /I "..\..\..\libs\cryptmgr" /I "..\..\..\libs\lith" /I "..\..\..\libs\mfcstub" /I "..\..\..\libs\regmgr" /I "..\..\libs" /I "..\..\Shared\TO2" /I "..\..\libs\serverdir" /D "NDEBUG" /D "_NOLFBUILD" /D "USE_INTEL_COMPILER" /D "WIN32" /D "_WINDOWS" /D "NOPS2" /D "_SERVERBUILD" /D "_FINAL" /D "MEMTRACK_SERVER" /Yu"stdafx.h" /FD /Zm1000 /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"..\..\Built\Final\ObjectDLL\TO2\Object.lto"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"..\..\Built\Final\ObjectDLL\TO2\Object.lto"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build
TargetPath=\proj\to2\source\Game\Built\Final\ObjectDLL\TO2\Object.lto
InputPath=\proj\to2\source\Game\Built\Final\ObjectDLL\TO2\Object.lto
SOURCE="$(InputPath)"

"$(GAME_REZ_DIR)\object.lto" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_REZ_DIR) 
	copy $(TargetPath) $(GAME_REZ_DIR) 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "Object - Win32 Release"
# Name "Object - Win32 Debug"
# Name "Object - Win32 Final"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c"
# Begin Source File

SOURCE=.\GlobalsInit.cpp
# End Source File
# Begin Source File

SOURCE=.\Stdafx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TO2GameServerShell.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TO2\TO2MissionButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TO2\TO2VersionMgr.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp"
# Begin Source File

SOURCE=.\Stdafx.h
# End Source File
# Begin Source File

SOURCE=.\TO2GameServerShell.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TO2\TO2MissionButeMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TO2\TO2VersionMgr.h
# End Source File
# End Group
# Begin Group "libs_debug"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\built\Debug\ObjectDll\ObjectShared\ObjectShared.lib

!IF  "$(CFG)" == "Object - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Debug\ButeMgr\ButeMgr.lib

!IF  "$(CFG)" == "Object - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Debug\MFCStub\MFCStub.lib

!IF  "$(CFG)" == "Object - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Debug\CryptMgr\cryptmgr.lib

!IF  "$(CFG)" == "Object - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Debug\Lib_StdLith\Lib_StdLith.lib

!IF  "$(CFG)" == "Object - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Debug\Lib_Lith\Lib_Lith.lib

!IF  "$(CFG)" == "Object - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Debug\RegMgr\regmgr.lib

!IF  "$(CFG)" == "Object - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libs\ServerDir\debug\ServerDir.lib

!IF  "$(CFG)" == "Object - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "libs_release"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\built\Release\ObjectDll\ObjectShared\ObjectShared.lib

!IF  "$(CFG)" == "Object - Win32 Release"

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Release\ButeMgr\ButeMgr.lib

!IF  "$(CFG)" == "Object - Win32 Release"

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Release\MFCStub\MFCStub.lib

!IF  "$(CFG)" == "Object - Win32 Release"

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Release\CryptMgr\cryptmgr.lib

!IF  "$(CFG)" == "Object - Win32 Release"

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Release\Lib_StdLith\Lib_StdLith.lib

!IF  "$(CFG)" == "Object - Win32 Release"

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Release\Lib_Lith\Lib_Lith.lib

!IF  "$(CFG)" == "Object - Win32 Release"

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Release\RegMgr\regmgr.lib

!IF  "$(CFG)" == "Object - Win32 Release"

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libs\ServerDir\release\ServerDir.lib

!IF  "$(CFG)" == "Object - Win32 Release"

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "libs_final"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\built\Final\ObjectDll\ObjectShared\ObjectShared.lib

!IF  "$(CFG)" == "Object - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Final\ButeMgr\ButeMgr.lib

!IF  "$(CFG)" == "Object - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Final\MFCStub\MFCStub.lib

!IF  "$(CFG)" == "Object - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Final\CryptMgr\cryptmgr.lib

!IF  "$(CFG)" == "Object - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Final\Lib_StdLith\Lib_StdLith.lib

!IF  "$(CFG)" == "Object - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Final\Lib_Lith\Lib_Lith.lib

!IF  "$(CFG)" == "Object - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\libs\built\Final\RegMgr\regmgr.lib

!IF  "$(CFG)" == "Object - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libs\ServerDir\final\ServerDir.lib

!IF  "$(CFG)" == "Object - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Object - Win32 Final"

!ENDIF 

# End Source File
# End Group
# End Target
# End Project
