# Microsoft Developer Studio Project File - Name="DibMgr" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=DibMgr - Win32 Debug MFC DLL
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "dibmgr60.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "dibmgr60.mak" CFG="DibMgr - Win32 Debug MFC DLL"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DibMgr - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "DibMgr - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "DibMgr - Win32 Debug MFC DLL" (based on "Win32 (x86) Static Library")
!MESSAGE "DibMgr - Win32 Release MFC DLL" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "dibmgr60"
# PROP Scc_LocalPath "."
CPP=xicl6.exe
RSC=rc.exe

!IF  "$(CFG)" == "DibMgr - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Release"
# PROP BASE Intermediate_Dir ".\Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\built\Release\DibMgr"
# PROP Intermediate_Dir "..\built\Release\DibMgr"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "..\STLPORT-4.0\STLPORT" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "NO_PRAGMA_LIBS" /FR /YX /FD /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=xilink6.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\built\Release\DibMgr\dibmgr.lib"

!ELSEIF  "$(CFG)" == "DibMgr - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Debug"
# PROP BASE Intermediate_Dir ".\Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\built\Debug\DibMgr"
# PROP Intermediate_Dir "..\built\Debug\DibMgr"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MTd /W3 /GX /Z7 /Od /I "..\STLPORT-4.0\STLPORT" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "NO_PRAGMA_LIBS" /FR /YX /FD /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=xilink6.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\built\Debug\DibMgr\dibmgr.lib"

!ELSEIF  "$(CFG)" == "DibMgr - Win32 Debug MFC DLL"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DibMgr___Win32_Debug_MFC_DLL"
# PROP BASE Intermediate_Dir "DibMgr___Win32_Debug_MFC_DLL"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\built\Debug\dibmgr_mfcdll"
# PROP Intermediate_Dir "..\built\Debug\dibmgr_mfcdll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /GX /Z7 /Od /I "..\incs" /D "_DEBUG" /D "_AFXDLL" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "NO_PRAGMA_LIBS" /YX /FD /c
# ADD CPP /nologo /MDd /W3 /GX /Z7 /Od /I "..\STLPORT-4.0\STLPORT" /D "_DEBUG" /D "_AFXDLL" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "NO_PRAGMA_LIBS" /FR /YX /FD /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=xilink6.exe -lib
# ADD BASE LIB32 /nologo /out:"..\libs\debug\dibmgr_dll.lib"
# ADD LIB32 /nologo /out:"..\built\Debug\dibmgr_mfcdll\dibmgr_mfcdll.lib"

!ELSEIF  "$(CFG)" == "DibMgr - Win32 Release MFC DLL"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "DibMgr___Win32_Release_MFC_DLL"
# PROP BASE Intermediate_Dir "DibMgr___Win32_Release_MFC_DLL"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\built\Release\dibmgr_mfcdll"
# PROP Intermediate_Dir "..\built\Release\dibmgr_mfcdll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "..\incs" /D "NDEBUG" /D "_AFXDLL" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "NO_PRAGMA_LIBS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\STLPORT-4.0\STLPORT" /D "NDEBUG" /D "_AFXDLL" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "NO_PRAGMA_LIBS" /FR /YX /FD /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=xilink6.exe -lib
# ADD BASE LIB32 /nologo /out:"..\libs\release\dibmgr_dll.lib"
# ADD LIB32 /nologo /out:"..\built\Release\dibmgr_mfcdll\dibmgr_mfcdll.lib"

!ENDIF 

# Begin Target

# Name "DibMgr - Win32 Release"
# Name "DibMgr - Win32 Debug"
# Name "DibMgr - Win32 Debug MFC DLL"
# Name "DibMgr - Win32 Release MFC DLL"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\Dib.cpp
# End Source File
# Begin Source File

SOURCE=.\DibMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\Dibmgr.h
# End Source File
# Begin Source File

SOURCE=.\DibPal.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\dib.h
# End Source File
# Begin Source File

SOURCE=.\dibpal.h
# End Source File
# Begin Source File

SOURCE=.\Stdafx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
