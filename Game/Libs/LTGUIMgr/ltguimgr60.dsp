# Microsoft Developer Studio Project File - Name="LTGUIMgr" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=LTGUIMgr - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ltguimgr60.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ltguimgr60.mak" CFG="LTGUIMgr - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "LTGUIMgr - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "LTGUIMgr - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "LTGUIMgr - Win32 Final" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "ltguimgr60"
# PROP Scc_LocalPath "."
CPP=xicl6.exe
RSC=rc.exe

!IF  "$(CFG)" == "LTGUIMgr - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "LTGUIMgr___Win32_Debug"
# PROP BASE Intermediate_Dir "LTGUIMgr___Win32_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\built\Debug\libs\LTGuiMgr"
# PROP Intermediate_Dir "..\..\built\Debug\libs\LTGuiMgr"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /GX /Z7 /Od /I "..\..\sdk\inc" /I "..\..\sdk\inc\compat" /I "..\incs" /I "..\..\lithshared\incs" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_LITHTECH2" /D "NO_PRAGMA_LIBS" /D "LT15_COMPAT" /YX /FD /c
# ADD CPP /nologo /MDd /W3 /GX /ZI /Od /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\Engine\sdk\inc\compat" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_LITHTECH2" /D "LT15_COMPAT" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=xilink6.exe -lib
# ADD BASE LIB32 /nologo /out:"Debug_LT2\ltguimgr_LT2.lib"
# ADD LIB32 /nologo /out:"..\..\built\Debug\libs\LTGuiMgr\ltguimgr.lib"

!ELSEIF  "$(CFG)" == "LTGUIMgr - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "LTGUIMgr___Win32_Release"
# PROP BASE Intermediate_Dir "LTGUIMgr___Win32_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\built\Release\libs\LTGuiMgr"
# PROP Intermediate_Dir "..\..\built\Release\libs\LTGuiMgr"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "..\..\sdk\inc" /I "..\..\sdk\inc\compat" /I "..\incs" /I "..\..\lithshared\incs" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_LITHTECH2" /D "NO_PRAGMA_LIBS" /D "LT15_COMPAT" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /Zi /O2 /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\Engine\sdk\inc\compat" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_LITHTECH2" /D "LT15_COMPAT" /YX /FD /Zm1000 /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=xilink6.exe -lib
# ADD BASE LIB32 /nologo /out:"Release_LT2\ltguimgr_LT2.lib"
# ADD LIB32 /nologo /out:"..\..\built\Release\libs\LTGuiMgr\ltguimgr.lib"

!ELSEIF  "$(CFG)" == "LTGUIMgr - Win32 Final"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "LTGUIMgr___Win32_Final"
# PROP BASE Intermediate_Dir "LTGUIMgr___Win32_Final"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\built\Final\libs\LTGuiMgr"
# PROP Intermediate_Dir "..\..\built\Final\libs\LTGuiMgr"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /Zi /O2 /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\Engine\sdk\inc\compat" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_LITHTECH2" /D "LT15_COMPAT" /D "_FINAL" /YX /FD /Zm1000 /c
# ADD CPP /nologo /MD /W3 /GX /Zi /O2 /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\Engine\sdk\inc\compat" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_LITHTECH2" /D "LT15_COMPAT" /D "_FINAL" /YX /FD /Zm1000 /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=xilink6.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\built\Final\libs\LTGuiMgr\ltguimgr.lib"
# ADD LIB32 /nologo /out:"..\..\built\Final\libs\LTGuiMgr\ltguimgr.lib"

!ENDIF 

# Begin Target

# Name "LTGUIMgr - Win32 Debug"
# Name "LTGUIMgr - Win32 Release"
# Name "LTGUIMgr - Win32 Final"
# Begin Group "Source"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ltguibutton.cpp
# End Source File
# Begin Source File

SOURCE=.\ltguicolumnctrl.cpp
# End Source File
# Begin Source File

SOURCE=.\ltguicommandhandler.cpp
# End Source File
# Begin Source File

SOURCE=.\ltguictrl.cpp
# End Source File
# Begin Source File

SOURCE=.\ltguicyclectrl.cpp
# End Source File
# Begin Source File

SOURCE=.\ltguieditctrl.cpp
# End Source File
# Begin Source File

SOURCE=.\ltguiframe.cpp
# End Source File
# Begin Source File

SOURCE=.\ltguilistctrl.cpp
# End Source File
# Begin Source File

SOURCE=.\ltguislider.cpp
# End Source File
# Begin Source File

SOURCE=.\ltguitextitemctrl.cpp
# End Source File
# Begin Source File

SOURCE=.\ltguitoggle.cpp
# End Source File
# Begin Source File

SOURCE=.\ltguiwindow.cpp
# End Source File
# End Group
# Begin Group "Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ltguibutton.h
# End Source File
# Begin Source File

SOURCE=.\ltguicolumnctrl.h
# End Source File
# Begin Source File

SOURCE=.\LTGUICommandHandler.h
# End Source File
# Begin Source File

SOURCE=.\LTGUICtrl.h
# End Source File
# Begin Source File

SOURCE=.\ltguicyclectrl.h
# End Source File
# Begin Source File

SOURCE=.\ltguieditctrl.h
# End Source File
# Begin Source File

SOURCE=.\ltguiframe.h
# End Source File
# Begin Source File

SOURCE=.\ltguilistctrl.h
# End Source File
# Begin Source File

SOURCE=.\ltguimgr.h
# End Source File
# Begin Source File

SOURCE=.\ltguislider.h
# End Source File
# Begin Source File

SOURCE=.\LTGUITextItemCtrl.h
# End Source File
# Begin Source File

SOURCE=.\ltguitoggle.h
# End Source File
# Begin Source File

SOURCE=.\ltguiwindow.h
# End Source File
# Begin Source File

SOURCE=.\ltquaduvutils.h
# End Source File
# Begin Source File

SOURCE=.\vkdefs.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\ltguilargetext.cpp
# End Source File
# Begin Source File

SOURCE=.\ltguilargetext.h
# End Source File
# End Target
# End Project
