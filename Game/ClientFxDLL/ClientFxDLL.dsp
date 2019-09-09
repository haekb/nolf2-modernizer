# Microsoft Developer Studio Project File - Name="ClientFxDLL" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=ClientFxDLL - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ClientFxDLL.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ClientFxDLL.mak" CFG="ClientFxDLL - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ClientFxDLL - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ClientFxDLL - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ClientFxDLL - Win32 Final" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "ClientFxDLL"
# PROP Scc_LocalPath "..\.."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ClientFxDLL - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\built\Release\ClientFxDll"
# PROP Intermediate_Dir "..\built\Release\ClientFxDll"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "CLIENTFXDLL_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "..\..\libs\STLPORT-4.0\STLPORT" /I "..\shared" /I "..\..\Engine\sdk\inc" /I "..\..\libs\mfcstub" /I "..\..\libs\stdlith" /I "..\..\libs\butemgr" /I "..\..\libs\cryptmgr" /I "..\..\libs\lith" /I "..\libs\ltguimgr" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "NOPS2" /D "MEMTRACK_CLIENTFX" /Yu"stdafx.h" /FD /Zm1000 /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"..\built\Release\ClientFxDll\ClientFx.fxd"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build
TargetPath=\proj\to2\source_public\Game\built\Release\ClientFxDll\ClientFx.fxd
InputPath=\proj\to2\source_public\Game\built\Release\ClientFxDll\ClientFx.fxd
SOURCE="$(InputPath)"

"$(GAME_REZ_DIR)\ClientFx.fxd" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_REZ_DIR) 
	copy $(TargetPath) $(GAME_REZ_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "ClientFxDLL___Win32_Debug"
# PROP BASE Intermediate_Dir "ClientFxDLL___Win32_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\built\debug\ClientFxDll"
# PROP Intermediate_Dir "..\built\debug\ClientFxDll"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "CLIENTFXDLL_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /GX /Zi /Od /I "..\..\libs\STLPORT-4.0\STLPORT" /I "..\shared" /I "..\..\Engine\sdk\inc" /I "..\..\libs\mfcstub" /I "..\..\libs\stdlith" /I "..\..\libs\butemgr" /I "..\..\libs\cryptmgr" /I "..\..\libs\lith" /I "..\libs\ltguimgr" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "NOPS2" /D "MEMTRACK_CLIENTFX" /FR /Yu"stdafx.h" /FD /Zm1000 /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"..\built\debug\ClientFxDll\ClientFx.fxd" /pdbtype:sept
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build
TargetPath=\proj\to2\source_public\Game\built\debug\ClientFxDll\ClientFx.fxd
InputPath=\proj\to2\source_public\Game\built\debug\ClientFxDll\ClientFx.fxd
SOURCE="$(InputPath)"

"$(GAME_REZ_DIR)\ClientFx.fxd" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_REZ_DIR) 
	copy $(TargetPath) $(GAME_REZ_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Final"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Final"
# PROP BASE Intermediate_Dir "Final"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\built\Final\ClientFxDll"
# PROP Intermediate_Dir "..\built\Final\ClientFxDll"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "..\..\libs\STLPORT-4.0\STLPORT" /I "..\shared" /I "..\..\Engine\sdk\inc" /I "..\..\libs\mfcstub" /I "..\..\libs\stdlith" /I "..\..\libs\butemgr" /I "..\..\libs\cryptmgr" /I "..\..\libs\lith" /I "..\libs\ltguimgr" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "NOPS2" /D "_FINAL" /Yu"stdafx.h" /FD /Zm1000 /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "..\..\libs\STLPORT-4.0\STLPORT" /I "..\shared" /I "..\..\Engine\sdk\inc" /I "..\..\libs\mfcstub" /I "..\..\libs\stdlith" /I "..\..\libs\butemgr" /I "..\..\libs\cryptmgr" /I "..\..\libs\lith" /I "..\libs\ltguimgr" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "NOPS2" /D "_FINAL" /D "MEMTRACK_CLIENTFX" /Yu"stdafx.h" /FD /Zm1000 /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"..\built\Final\ClientFxDll\ClientFx.fxd"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"..\built\Final\ClientFxDll\ClientFx.fxd"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build
TargetPath=\proj\to2\source_public\Game\built\Final\ClientFxDll\ClientFx.fxd
InputPath=\proj\to2\source_public\Game\built\Final\ClientFxDll\ClientFx.fxd
SOURCE="$(InputPath)"

"$(GAME_REZ_DIR)\ClientFx.fxd" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_REZ_DIR) 
	copy $(TargetPath) $(GAME_REZ_DIR) 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "ClientFxDLL - Win32 Release"
# Name "ClientFxDLL - Win32 Debug"
# Name "ClientFxDLL - Win32 Final"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BaseFx.cpp
# End Source File
# Begin Source File

SOURCE=.\bouncychunkfx.cpp
# End Source File
# Begin Source File

SOURCE=.\camjitterfx.cpp
# End Source File
# Begin Source File

SOURCE=.\camwobblefx.cpp
# End Source File
# Begin Source File

SOURCE=.\clientfx.cpp
# End Source File
# Begin Source File

SOURCE=.\CreateFX.cpp
# End Source File
# Begin Source File

SOURCE=.\cycletimer.cpp
# End Source File
# Begin Source File

SOURCE=..\Shared\DebugNew.cpp
# End Source File
# Begin Source File

SOURCE=.\dynalightfx.cpp
# End Source File
# Begin Source File

SOURCE=.\fallingstufffx.cpp
# End Source File
# Begin Source File

SOURCE=.\FlareSpriteFX.cpp
# End Source File
# Begin Source File

SOURCE=.\lightningfx.cpp
# End Source File
# Begin Source File

SOURCE=.\LTBbouncychunkfx.cpp
# End Source File
# Begin Source File

SOURCE=.\ltbmodelfx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Engine\sdk\inc\ltmodule.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\Engine\sdk\inc\ltquatbase.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\nullfx.cpp
# End Source File
# Begin Source File

SOURCE=.\ParticleSystemFX.cpp
# End Source File
# Begin Source File

SOURCE=.\playrandomsoundfx.cpp
# End Source File
# Begin Source File

SOURCE=.\playsoundfx.cpp
# End Source File
# Begin Source File

SOURCE=.\polyfanfx.cpp
# End Source File
# Begin Source File

SOURCE=.\polytubefx.cpp
# End Source File
# Begin Source File

SOURCE=.\spritefx.cpp
# End Source File
# Begin Source File

SOURCE=.\spritesystemfx.cpp
# End Source File
# Begin Source File

SOURCE=.\stdafx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\Shared\BankedList.h
# End Source File
# Begin Source File

SOURCE=..\Shared\BankedList_impl.h
# End Source File
# Begin Source File

SOURCE=..\Shared\BaseFx.h
# End Source File
# Begin Source File

SOURCE=.\bouncychunkfx.h
# End Source File
# Begin Source File

SOURCE=.\camjitterfx.h
# End Source File
# Begin Source File

SOURCE=.\camwobblefx.h
# End Source File
# Begin Source File

SOURCE=.\clientfx.h
# End Source File
# Begin Source File

SOURCE=.\CreateFX.h
# End Source File
# Begin Source File

SOURCE=.\cycletimer.h
# End Source File
# Begin Source File

SOURCE=..\Shared\DebugNew.h
# End Source File
# Begin Source File

SOURCE=..\Shared\DebugNew_impl.h
# End Source File
# Begin Source File

SOURCE=.\dynalightfx.h
# End Source File
# Begin Source File

SOURCE=.\fallingstufffx.h
# End Source File
# Begin Source File

SOURCE=.\FlareSpriteFX.h
# End Source File
# Begin Source File

SOURCE=.\lightningfx.h
# End Source File
# Begin Source File

SOURCE=.\LTBbouncychunkfx.h
# End Source File
# Begin Source File

SOURCE=.\ltbmodelfx.h
# End Source File
# Begin Source File

SOURCE=.\memarray.h
# End Source File
# Begin Source File

SOURCE=.\nullfx.h
# End Source File
# Begin Source File

SOURCE=.\ParticleSystemFX.h
# End Source File
# Begin Source File

SOURCE=.\playrandomsoundfx.h
# End Source File
# Begin Source File

SOURCE=.\playsoundfx.h
# End Source File
# Begin Source File

SOURCE=.\polyfanfx.h
# End Source File
# Begin Source File

SOURCE=.\polytubefx.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\spritefx.h
# End Source File
# Begin Source File

SOURCE=.\spritesystemfx.h
# End Source File
# Begin Source File

SOURCE=.\stdafx.h
# End Source File
# Begin Source File

SOURCE=.\swaplist.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Group "libs_debug"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\libs\built\Debug\ButeMgr\ButeMgr.lib

!IF  "$(CFG)" == "ClientFxDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Debug"

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Final"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libs\built\Debug\MFCStub\MFCStub.lib

!IF  "$(CFG)" == "ClientFxDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Debug"

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Final"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libs\built\Debug\CryptMgr\cryptmgr.lib

!IF  "$(CFG)" == "ClientFxDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Debug"

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Final"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libs\built\Debug\Lib_StdLith\Lib_StdLith.lib

!IF  "$(CFG)" == "ClientFxDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Debug"

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Final"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libs\built\Debug\Lib_Lith\Lib_Lith.lib

!IF  "$(CFG)" == "ClientFxDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Debug"

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Final"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\built\Debug\libs\LTGuiMgr\ltguimgr.lib

!IF  "$(CFG)" == "ClientFxDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Debug"

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Final"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "libs_release"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\libs\built\Release\ButeMgr\ButeMgr.lib

!IF  "$(CFG)" == "ClientFxDLL - Win32 Release"

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libs\built\Release\MFCStub\MFCStub.lib

!IF  "$(CFG)" == "ClientFxDLL - Win32 Release"

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libs\built\Release\CryptMgr\cryptmgr.lib

!IF  "$(CFG)" == "ClientFxDLL - Win32 Release"

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libs\built\Release\Lib_StdLith\Lib_StdLith.lib

!IF  "$(CFG)" == "ClientFxDLL - Win32 Release"

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libs\built\Release\Lib_Lith\Lib_Lith.lib

!IF  "$(CFG)" == "ClientFxDLL - Win32 Release"

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\built\Release\libs\LTGuiMgr\ltguimgr.lib

!IF  "$(CFG)" == "ClientFxDLL - Win32 Release"

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Final"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "libs_final"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\libs\built\Final\ButeMgr\ButeMgr.lib

!IF  "$(CFG)" == "ClientFxDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Final"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libs\built\Final\MFCStub\MFCStub.lib

!IF  "$(CFG)" == "ClientFxDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Final"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libs\built\Final\CryptMgr\cryptmgr.lib

!IF  "$(CFG)" == "ClientFxDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Final"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libs\built\Final\Lib_StdLith\Lib_StdLith.lib

!IF  "$(CFG)" == "ClientFxDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Final"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libs\built\Final\Lib_Lith\Lib_Lith.lib

!IF  "$(CFG)" == "ClientFxDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Final"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\built\Final\libs\LTGuiMgr\ltguimgr.lib

!IF  "$(CFG)" == "ClientFxDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientFxDLL - Win32 Final"

!ENDIF 

# End Source File
# End Group
# End Target
# End Project
