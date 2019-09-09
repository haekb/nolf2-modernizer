# Microsoft Developer Studio Project File - Name="ServerApp" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=ServerApp - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ServerApp.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ServerApp.mak" CFG="ServerApp - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ServerApp - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ServerApp - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "ServerApp - Win32 Final" (based on "Win32 (x86) Application")
!MESSAGE "ServerApp - Win32 Final DE" (based on "Win32 (x86) Application")
!MESSAGE "ServerApp - Win32 Final ES" (based on "Win32 (x86) Application")
!MESSAGE "ServerApp - Win32 Final IT" (based on "Win32 (x86) Application")
!MESSAGE "ServerApp - Win32 Final FR" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "ServerApp"
# PROP Scc_LocalPath ".."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ServerApp - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\Built\Release\ServerApp"
# PROP Intermediate_Dir "..\Built\Release\ServerApp"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I ".\\" /I "..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\Engine\sdk\inc" /I "..\shared" /I "..\shared\lang\en" /I "..\..\libs\regmgr" /I "..\..\libs\regmgr32" /I "..\..\libs\lith" /I "..\..\libs\butemgr" /I "..\..\libs\cryptmgr" /I "..\..\libs\stdlith" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i ".\\" /i "res\lang\en" /i "..\shared" /i "..\shared\lang\en" /d "NDEBUG" /d "_REG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 server.lib regmgr32.lib regmgr.lib lib_lith.lib ButeMgrMfcDll.lib cryptmgrMfcDll.lib lib_stdlith.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\Built\Release\ServerApp\NOLF2Srv.exe" /libpath:"..\..\engine\sdk\lib" /libpath:"..\..\libs\built\release\regmgr" /libpath:"..\..\libs\built\release\regmgr32" /libpath:"..\..\libs\built\release\lib_lith" /libpath:"..\..\libs\built\release\ButeMgrMFCDll" /libpath:"..\..\libs\built\release\cryptmgrmfcdll" /libpath:"..\..\libs\built\release\lib_stdlith"
# Begin Custom Build
TargetPath=\proj\to2\source_public\Game\Built\Release\ServerApp\NOLF2Srv.exe
InputPath=\proj\to2\source_public\Game\Built\Release\ServerApp\NOLF2Srv.exe
SOURCE="$(InputPath)"

"$(GAME_MAIN_DIR)\NOLF2Srv.exe" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_MAIN_DIR) 
	copy $(TargetPath) $(GAME_MAIN_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\Built\Debug\ServerApp"
# PROP Intermediate_Dir "..\Built\Debug\ServerApp"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I ".\\" /I "..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\Engine\sdk\inc" /I "..\shared" /I "..\shared\lang\en" /I "..\..\libs\regmgr" /I "..\..\libs\regmgr32" /I "..\..\libs\lith" /I "..\..\libs\butemgr" /I "..\..\libs\cryptmgr" /I "..\..\libs\stdlith" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i ".\\" /i "res\lang\en" /i "..\shared" /i "..\shared\lang\en" /d "_DEBUG" /d "_REG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 server.lib regmgr32.lib regmgr.lib lib_lith.lib ButeMgrMfcDll.lib cryptmgrmfcdll.lib lib_stdlith.lib winmm.lib /nologo /subsystem:windows /debug /machine:I386 /out:"..\Built\Debug\ServerApp\NOLF2Srv.exe" /pdbtype:sept /libpath:"..\..\engine\sdk\lib" /libpath:"..\..\libs\built\debug\regmgr" /libpath:"..\..\libs\built\debug\regmgr32" /libpath:"..\..\libs\built\debug\lib_lith" /libpath:"..\..\libs\built\debug\ButeMgrMFCDll" /libpath:"..\..\libs\built\debug\cryptmgrmfcdll" /libpath:"..\..\libs\built\debug\lib_stdlith"
# SUBTRACT LINK32 /verbose
# Begin Custom Build
TargetPath=\proj\to2\source_public\Game\Built\Debug\ServerApp\NOLF2Srv.exe
InputPath=\proj\to2\source_public\Game\Built\Debug\ServerApp\NOLF2Srv.exe
SOURCE="$(InputPath)"

"$(GAME_MAIN_DIR)\NOLF2Srv.exe" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_MAIN_DIR) 
	copy $(TargetPath) $(GAME_MAIN_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ServerApp___Win32_Final"
# PROP BASE Intermediate_Dir "ServerApp___Win32_Final"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\Built\Final\ServerApp"
# PROP Intermediate_Dir "..\Built\Final\ServerApp"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GR /GX /O2 /I ".\\" /I "..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\Engine\sdk\inc" /I "..\shared" /I "..\..\libs\regmgr" /I "..\..\libs\regmgr32" /I "..\..\libs\lith" /I "..\..\libs\butemgr" /I "..\..\libs\cryptmgr" /I "..\..\libs\stdlith" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I ".\\" /I "..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\Engine\sdk\inc" /I "..\shared" /I "..\shared\lang\en" /I "..\..\libs\regmgr" /I "..\..\libs\regmgr32" /I "..\..\libs\lith" /I "..\..\libs\butemgr" /I "..\..\libs\cryptmgr" /I "..\..\libs\stdlith" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "_FINAL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /i "..\shared" /d "NDEBUG" /d "_REG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i ".\\" /i "res\lang\en" /i "..\shared" /i "..\shared\lang\en" /d "NDEBUG" /d "_REG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 server.lib regmgr32.lib regmgr.lib lib_lith.lib ButeMgrMfcDll.lib cryptmgrMfcDll.lib lib_stdlith.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\Built\Release\ServerApp\NOLF2Srv.exe" /libpath:"..\..\engine\built\Release\Runtime\DLL_Server" /libpath:"..\..\libs\built\release\regmgr" /libpath:"..\..\libs\built\release\regmgr32" /libpath:"..\..\libs\built\release\lib_lith" /libpath:"..\..\libs\built\release\ButeMgrMFCDll" /libpath:"..\..\libs\built\release\cryptmgrmfcdll" /libpath:"..\..\libs\built\release\lib_stdlith"
# ADD LINK32 server.lib regmgr32.lib regmgr.lib lib_lith.lib ButeMgrMfcDll.lib cryptmgrMfcDll.lib lib_stdlith.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\Built\Final\ServerApp\NOLF2Srv.exe" /libpath:"..\..\engine\sdk\lib" /libpath:"..\..\libs\built\Final\regmgr" /libpath:"..\..\libs\built\Final\regmgr32" /libpath:"..\..\libs\built\Final\lib_lith" /libpath:"..\..\libs\built\Final\ButeMgrMFCDll" /libpath:"..\..\libs\built\Final\cryptmgrmfcdll" /libpath:"..\..\libs\built\Final\lib_stdlith"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build
TargetPath=\proj\to2\source_public\Game\Built\Final\ServerApp\NOLF2Srv.exe
InputPath=\proj\to2\source_public\Game\Built\Final\ServerApp\NOLF2Srv.exe
SOURCE="$(InputPath)"

"$(GAME_MAIN_DIR)\NOLF2Srv.exe" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_MAIN_DIR) 
	copy $(TargetPath) $(GAME_MAIN_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final DE"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ServerApp___Win32_Final_DE"
# PROP BASE Intermediate_Dir "ServerApp___Win32_Final_DE"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\Built\FinalDE\ServerApp"
# PROP Intermediate_Dir "..\Built\FinalDE\ServerApp"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GR /GX /O2 /I ".\\" /I "..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\Engine\sdk\inc" /I "..\shared" /I "..\shared\lang\eng" /I "..\..\libs\regmgr" /I "..\..\libs\regmgr32" /I "..\..\libs\lith" /I "..\..\libs\butemgr" /I "..\..\libs\cryptmgr" /I "..\..\libs\stdlith" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "_FINAL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I ".\\" /I "..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\Engine\sdk\inc" /I "..\shared" /I "..\shared\lang\de" /I "..\..\libs\regmgr" /I "..\..\libs\regmgr32" /I "..\..\libs\lith" /I "..\..\libs\butemgr" /I "..\..\libs\cryptmgr" /I "..\..\libs\stdlith" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "_FINAL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /i "..\shared" /d "NDEBUG" /d "_REG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i ".\\" /i "res\lang\DE" /i "..\shared" /i "..\shared\lang\DE" /d "NDEBUG" /d "_REG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 server.lib regmgr32.lib regmgr.lib lib_lith.lib ButeMgrMfcDll.lib cryptmgrMfcDll.lib lib_stdlith.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\Built\Release\ServerApp\NOLF2Srv.exe" /libpath:"..\..\engine\built\Release\Runtime\DLL_Server" /libpath:"..\..\libs\built\release\regmgr" /libpath:"..\..\libs\built\release\regmgr32" /libpath:"..\..\libs\built\release\lib_lith" /libpath:"..\..\libs\built\release\ButeMgrMFCDll" /libpath:"..\..\libs\built\release\cryptmgrmfcdll" /libpath:"..\..\libs\built\release\lib_stdlith"
# ADD LINK32 server.lib regmgr32.lib regmgr.lib lib_lith.lib ButeMgrMfcDll.lib cryptmgrMfcDll.lib lib_stdlith.lib winmm.lib /nologo /subsystem:windows /pdb:"..\Built\Final\ServerApp/NOLF2Srv.pdb" /machine:I386 /out:"..\Built\FinalDE\ServerApp\NOLF2Srv.exe" /libpath:"..\..\engine\built\Final\Runtime\DLL_Server" /libpath:"..\..\libs\built\Final\regmgr" /libpath:"..\..\libs\built\Final\regmgr32" /libpath:"..\..\libs\built\Final\lib_lith" /libpath:"..\..\libs\built\Final\ButeMgrMFCDll" /libpath:"..\..\libs\built\Final\cryptmgrmfcdll" /libpath:"..\..\libs\built\Final\lib_stdlith"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build
TargetPath=\proj\to2\source_public\Game\Built\FinalDE\ServerApp\NOLF2Srv.exe
InputPath=\proj\to2\source_public\Game\Built\FinalDE\ServerApp\NOLF2Srv.exe
SOURCE="$(InputPath)"

"$(GAME_MAIN_DIR)\NOLF2Srv.exe" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_MAIN_DIR) 
	copy $(TargetPath) $(GAME_MAIN_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final ES"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ServerApp___Win32_Final_ES"
# PROP BASE Intermediate_Dir "ServerApp___Win32_Final_ES"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\Built\FinalES\ServerApp"
# PROP Intermediate_Dir "..\Built\FinalES\ServerApp"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GR /GX /O2 /I ".\\" /I "..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\Engine\sdk\inc" /I "..\shared" /I "..\shared\lang\eng" /I "..\..\libs\regmgr" /I "..\..\libs\regmgr32" /I "..\..\libs\lith" /I "..\..\libs\butemgr" /I "..\..\libs\cryptmgr" /I "..\..\libs\stdlith" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "_FINAL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I ".\\" /I "..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\Engine\sdk\inc" /I "..\shared" /I "..\shared\lang\es" /I "..\..\libs\regmgr" /I "..\..\libs\regmgr32" /I "..\..\libs\lith" /I "..\..\libs\butemgr" /I "..\..\libs\cryptmgr" /I "..\..\libs\stdlith" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "_FINAL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /i "..\shared" /d "NDEBUG" /d "_REG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i ".\\" /i "res\lang\ES" /i "..\shared" /i "..\shared\lang\ES" /d "NDEBUG" /d "_REG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 server.lib regmgr32.lib regmgr.lib lib_lith.lib ButeMgrMfcDll.lib cryptmgrMfcDll.lib lib_stdlith.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\Built\Release\ServerApp\NOLF2Srv.exe" /libpath:"..\..\engine\built\Release\Runtime\DLL_Server" /libpath:"..\..\libs\built\release\regmgr" /libpath:"..\..\libs\built\release\regmgr32" /libpath:"..\..\libs\built\release\lib_lith" /libpath:"..\..\libs\built\release\ButeMgrMFCDll" /libpath:"..\..\libs\built\release\cryptmgrmfcdll" /libpath:"..\..\libs\built\release\lib_stdlith"
# ADD LINK32 server.lib regmgr32.lib regmgr.lib lib_lith.lib ButeMgrMfcDll.lib cryptmgrMfcDll.lib lib_stdlith.lib winmm.lib /nologo /subsystem:windows /pdb:"..\Built\Final\ServerApp/NOLF2Srv.pdb" /machine:I386 /out:"..\Built\FinalES\ServerApp\NOLF2Srv.exe" /libpath:"..\..\engine\built\Final\Runtime\DLL_Server" /libpath:"..\..\libs\built\Final\regmgr" /libpath:"..\..\libs\built\Final\regmgr32" /libpath:"..\..\libs\built\Final\lib_lith" /libpath:"..\..\libs\built\Final\ButeMgrMFCDll" /libpath:"..\..\libs\built\Final\cryptmgrmfcdll" /libpath:"..\..\libs\built\Final\lib_stdlith"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build
TargetPath=\proj\to2\source_public\Game\Built\FinalES\ServerApp\NOLF2Srv.exe
InputPath=\proj\to2\source_public\Game\Built\FinalES\ServerApp\NOLF2Srv.exe
SOURCE="$(InputPath)"

"$(GAME_MAIN_DIR)\NOLF2Srv.exe" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_MAIN_DIR) 
	copy $(TargetPath) $(GAME_MAIN_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final IT"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ServerApp___Win32_Final_IT"
# PROP BASE Intermediate_Dir "ServerApp___Win32_Final_IT"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\Built\FinalIT\ServerApp"
# PROP Intermediate_Dir "..\Built\FinalIT\ServerApp"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GR /GX /O2 /I ".\\" /I "..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\Engine\sdk\inc" /I "..\shared" /I "..\shared\lang\eng" /I "..\..\libs\regmgr" /I "..\..\libs\regmgr32" /I "..\..\libs\lith" /I "..\..\libs\butemgr" /I "..\..\libs\cryptmgr" /I "..\..\libs\stdlith" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "_FINAL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I ".\\" /I "..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\Engine\sdk\inc" /I "..\shared" /I "..\shared\lang\it" /I "..\..\libs\regmgr" /I "..\..\libs\regmgr32" /I "..\..\libs\lith" /I "..\..\libs\butemgr" /I "..\..\libs\cryptmgr" /I "..\..\libs\stdlith" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "_FINAL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /i "..\shared" /d "NDEBUG" /d "_REG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i ".\\" /i "res\lang\IT" /i "..\shared" /i "..\shared\lang\IT" /d "NDEBUG" /d "_REG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 server.lib regmgr32.lib regmgr.lib lib_lith.lib ButeMgrMfcDll.lib cryptmgrMfcDll.lib lib_stdlith.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\Built\Release\ServerApp\NOLF2Srv.exe" /libpath:"..\..\engine\built\Release\Runtime\DLL_Server" /libpath:"..\..\libs\built\release\regmgr" /libpath:"..\..\libs\built\release\regmgr32" /libpath:"..\..\libs\built\release\lib_lith" /libpath:"..\..\libs\built\release\ButeMgrMFCDll" /libpath:"..\..\libs\built\release\cryptmgrmfcdll" /libpath:"..\..\libs\built\release\lib_stdlith"
# ADD LINK32 server.lib regmgr32.lib regmgr.lib lib_lith.lib ButeMgrMfcDll.lib cryptmgrMfcDll.lib lib_stdlith.lib winmm.lib /nologo /subsystem:windows /pdb:"..\Built\Final\ServerApp/NOLF2Srv.pdb" /machine:I386 /out:"..\Built\FinalIT\ServerApp\NOLF2Srv.exe" /libpath:"..\..\engine\built\Final\Runtime\DLL_Server" /libpath:"..\..\libs\built\Final\regmgr" /libpath:"..\..\libs\built\Final\regmgr32" /libpath:"..\..\libs\built\Final\lib_lith" /libpath:"..\..\libs\built\Final\ButeMgrMFCDll" /libpath:"..\..\libs\built\Final\cryptmgrmfcdll" /libpath:"..\..\libs\built\Final\lib_stdlith"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build
TargetPath=\proj\to2\source_public\Game\Built\FinalIT\ServerApp\NOLF2Srv.exe
InputPath=\proj\to2\source_public\Game\Built\FinalIT\ServerApp\NOLF2Srv.exe
SOURCE="$(InputPath)"

"$(GAME_MAIN_DIR)\NOLF2Srv.exe" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_MAIN_DIR) 
	copy $(TargetPath) $(GAME_MAIN_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final FR"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ServerApp___Win32_Final_FR"
# PROP BASE Intermediate_Dir "ServerApp___Win32_Final_FR"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\Built\FinalFR\ServerApp"
# PROP Intermediate_Dir "..\Built\FinalFR\ServerApp"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GR /GX /O2 /I ".\\" /I "..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\Engine\sdk\inc" /I "..\shared" /I "..\shared\lang\eng" /I "..\..\libs\regmgr" /I "..\..\libs\regmgr32" /I "..\..\libs\lith" /I "..\..\libs\butemgr" /I "..\..\libs\cryptmgr" /I "..\..\libs\stdlith" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "_FINAL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I ".\\" /I "..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\Engine\sdk\inc" /I "..\shared" /I "..\shared\lang\fr" /I "..\..\libs\regmgr" /I "..\..\libs\regmgr32" /I "..\..\libs\lith" /I "..\..\libs\butemgr" /I "..\..\libs\cryptmgr" /I "..\..\libs\stdlith" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "_FINAL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /i "..\shared" /d "NDEBUG" /d "_REG" /d "_AFXDLL"
# ADD RSC /l 0x409 /i ".\\" /i "res\lang\FR" /i "..\shared" /i "..\shared\lang\FR" /d "NDEBUG" /d "_REG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 server.lib regmgr32.lib regmgr.lib lib_lith.lib ButeMgrMfcDll.lib cryptmgrMfcDll.lib lib_stdlith.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\Built\Release\ServerApp\NOLF2Srv.exe" /libpath:"..\..\engine\built\Release\Runtime\DLL_Server" /libpath:"..\..\libs\built\release\regmgr" /libpath:"..\..\libs\built\release\regmgr32" /libpath:"..\..\libs\built\release\lib_lith" /libpath:"..\..\libs\built\release\ButeMgrMFCDll" /libpath:"..\..\libs\built\release\cryptmgrmfcdll" /libpath:"..\..\libs\built\release\lib_stdlith"
# ADD LINK32 server.lib regmgr32.lib regmgr.lib lib_lith.lib ButeMgrMfcDll.lib cryptmgrMfcDll.lib lib_stdlith.lib winmm.lib /nologo /subsystem:windows /pdb:"..\Built\Final\ServerApp/NOLF2Srv.pdb" /machine:I386 /out:"..\Built\FinalFR\ServerApp\NOLF2Srv.exe" /libpath:"..\..\engine\built\Final\Runtime\DLL_Server" /libpath:"..\..\libs\built\Final\regmgr" /libpath:"..\..\libs\built\Final\regmgr32" /libpath:"..\..\libs\built\Final\lib_lith" /libpath:"..\..\libs\built\Final\ButeMgrMFCDll" /libpath:"..\..\libs\built\Final\cryptmgrmfcdll" /libpath:"..\..\libs\built\Final\lib_stdlith"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build
TargetPath=\proj\to2\source_public\Game\Built\FinalFR\ServerApp\NOLF2Srv.exe
InputPath=\proj\to2\source_public\Game\Built\FinalFR\ServerApp\NOLF2Srv.exe
SOURCE="$(InputPath)"

"$(GAME_MAIN_DIR)\NOLF2Srv.exe" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	Rem IncrediBuild_OutputFile $(TargetPath) 
	echo copy $(TargetPath) $(GAME_MAIN_DIR) 
	copy $(TargetPath) $(GAME_MAIN_DIR) 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "ServerApp - Win32 Release"
# Name "ServerApp - Win32 Debug"
# Name "ServerApp - Win32 Final"
# Name "ServerApp - Win32 Final DE"
# Name "ServerApp - Win32 Final ES"
# Name "ServerApp - Win32 Final IT"
# Name "ServerApp - Win32 Final FR"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c"
# Begin Source File

SOURCE=..\Shared\CommonUtilities.cpp
# End Source File
# Begin Source File

SOURCE=..\Shared\DebugNew.cpp
# End Source File
# Begin Source File

SOURCE=..\Shared\GameAlloc.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Engine\sdk\inc\ltmodule.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\Shared\NetDefs.cpp
# End Source File
# Begin Source File

SOURCE=..\Shared\ParsedMsg.cpp
# End Source File
# Begin Source File

SOURCE=..\Shared\ProfileUtils.cpp
# End Source File
# Begin Source File

SOURCE=..\Shared\ScmdConsole.cpp
# End Source File
# Begin Source File

SOURCE=.\ScmdConsoleDriver_ServerApp.cpp
# End Source File
# Begin Source File

SOURCE=.\SelectConfigDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ServerApp.cpp
# End Source File
# Begin Source File

SOURCE=.\ServerDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Splash.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=..\Shared\TO2\TO2VersionMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\Shared\VersionMgr.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "hpp;h"
# Begin Source File

SOURCE=..\Shared\CommonUtilities.h
# End Source File
# Begin Source File

SOURCE=..\Shared\DebugNew.h
# End Source File
# Begin Source File

SOURCE=..\Shared\DebugNew_impl.h
# End Source File
# Begin Source File

SOURCE=..\..\Engine\sdk\inc\ltmodule.h
# End Source File
# Begin Source File

SOURCE=..\Shared\MsgIDs.h
# End Source File
# Begin Source File

SOURCE=..\Shared\ParsedMsg.h
# End Source File
# Begin Source File

SOURCE=..\Shared\ProfileUtils.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=..\Shared\ResShared.h
# End Source File
# Begin Source File

SOURCE=..\Shared\ScmdConsole.h
# End Source File
# Begin Source File

SOURCE=.\ScmdConsoleDriver_ServerApp.h
# End Source File
# Begin Source File

SOURCE=.\SelectConfigDlg.h
# End Source File
# Begin Source File

SOURCE=.\ServerApp.h
# End Source File
# Begin Source File

SOURCE=.\ServerDlg.h
# End Source File
# Begin Source File

SOURCE=.\Splash.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\Shared\TO2\TO2VersionMgr.h
# End Source File
# Begin Source File

SOURCE=..\Shared\VersionMgr.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "rc;rc2;ico"
# Begin Source File

SOURCE=.\res\selected.ico
# End Source File
# Begin Source File

SOURCE=.\res\ServerApp.ico
# End Source File
# Begin Source File

SOURCE=.\res\ServerApp.rc2
# End Source File
# End Group
# Begin Group "Localized Files"

# PROP Default_Filter ""
# Begin Group "DE"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\res\Lang\DE\ServerApp.rc

!IF  "$(CFG)" == "ServerApp - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final DE"

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\res\Lang\DE\splash.bmp

!IF  "$(CFG)" == "ServerApp - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final DE"

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "EN"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\res\Lang\EN\ServerApp.rc

!IF  "$(CFG)" == "ServerApp - Win32 Release"

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Debug"

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final"

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\res\Lang\EN\splash.bmp

!IF  "$(CFG)" == "ServerApp - Win32 Release"

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Debug"

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final"

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "ES"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\res\Lang\ES\ServerApp.rc

!IF  "$(CFG)" == "ServerApp - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final ES"

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\res\Lang\ES\splash.bmp

!IF  "$(CFG)" == "ServerApp - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final ES"

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "FR"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\res\Lang\FR\ServerApp.rc

!IF  "$(CFG)" == "ServerApp - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final FR"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\res\Lang\FR\splash.bmp

!IF  "$(CFG)" == "ServerApp - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final FR"

!ENDIF 

# End Source File
# End Group
# Begin Group "IT"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\res\Lang\IT\ServerApp.rc

!IF  "$(CFG)" == "ServerApp - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final IT"

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\res\Lang\IT\splash.bmp

!IF  "$(CFG)" == "ServerApp - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final IT"

!ELSEIF  "$(CFG)" == "ServerApp - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# End Group
# End Target
# End Project
