# Microsoft Developer Studio Project File - Name="LibXBox_Lith" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 60000
# ** DO NOT EDIT **

# TARGTYPE "Xbox Static Library" 0x0b04

CFG=LibXBox_Lith - Xbox Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "LibXBox_Lith.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "LibXBox_Lith.mak" CFG="LibXBox_Lith - Xbox Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "LibXBox_Lith - Xbox Release" (based on "Xbox Static Library")
!MESSAGE "LibXBox_Lith - Xbox Debug" (based on "Xbox Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe

!IF  "$(CFG)" == "LibXBox_Lith - Xbox Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\..\..\proj_xbox\Release\Runtime\LibXBox_Lith"
# PROP Intermediate_Dir "..\..\..\..\..\proj_xbox\Release\Runtime\LibXBox_Lith"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "_XBOX" /D "NDEBUG" /YX /FD /G6 /Zvc6 /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "_XBOX" /D "__XBOX" /D "NDEBUG" /YX /FD /G6 /Zvc6 /c
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=xilink6.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "LibXBox_Lith - Xbox Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\..\..\proj_xbox\Debug\Runtime\LibXBox_Lith"
# PROP Intermediate_Dir "..\..\..\..\..\proj_xbox\Debug\Runtime\LibXBox_Lith"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_XBOX" /D "_DEBUG" /YX /FD /G6 /Zvc6 /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_XBOX" /D "__XBOX" /D "_DEBUG" /D "__FLATMODEL__" /YX /FD /G6 /Zvc6 /c
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=xilink6.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "LibXBox_Lith - Xbox Release"
# Name "LibXBox_Lith - Xbox Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\basehash.cpp
# End Source File
# Begin Source File

SOURCE=..\baselist.cpp
# End Source File
# Begin Source File

SOURCE=..\baselistcounter.cpp
# End Source File
# Begin Source File

SOURCE=..\lith.cpp
# End Source File
# Begin Source File

SOURCE=..\lithbaselist.cpp
# End Source File
# Begin Source File

SOURCE=..\lithchunkallocator.cpp
# End Source File
# Begin Source File

SOURCE=..\lithsimpary.cpp
# End Source File
# Begin Source File

SOURCE=..\lithsimparystat.cpp
# End Source File
# Begin Source File

SOURCE=..\virtlist.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\basehash.h
# End Source File
# Begin Source File

SOURCE=..\baselist.h
# End Source File
# Begin Source File

SOURCE=..\baselistcounter.h
# End Source File
# Begin Source File

SOURCE=..\lith.h
# End Source File
# Begin Source File

SOURCE=..\lithbaselist.h
# End Source File
# Begin Source File

SOURCE=..\lithchunkallocator.h
# End Source File
# Begin Source File

SOURCE=..\lithsimpary.h
# End Source File
# Begin Source File

SOURCE=..\lithsimparystat.h
# End Source File
# Begin Source File

SOURCE=..\lithtmpl.h
# End Source File
# Begin Source File

SOURCE=..\lithtypes.h
# End Source File
# Begin Source File

SOURCE=..\virtlist.h
# End Source File
# End Group
# End Target
# End Project
