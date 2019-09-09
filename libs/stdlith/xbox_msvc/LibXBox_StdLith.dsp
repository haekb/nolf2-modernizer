# Microsoft Developer Studio Project File - Name="LibXBox_StdLith" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 60000
# ** DO NOT EDIT **

# TARGTYPE "Xbox Static Library" 0x0b04

CFG=LibXBox_StdLith - Xbox Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "LibXBox_StdLith.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "LibXBox_StdLith.mak" CFG="LibXBox_StdLith - Xbox Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "LibXBox_StdLith - Xbox Release" (based on "Xbox Static Library")
!MESSAGE "LibXBox_StdLith - Xbox Debug" (based on "Xbox Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe

!IF  "$(CFG)" == "LibXBox_StdLith - Xbox Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\..\..\proj_xbox\Release\Runtime\LibXBox_StdLith"
# PROP Intermediate_Dir "..\..\..\..\..\proj_xbox\Release\Runtime\LibXBox_StdLith"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "_XBOX" /D "NDEBUG" /YX /FD /G6 /Zvc6 /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "_XBOX" /D "NDEBUG" /YX /FD /G6 /Zvc6 /c
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=xilink6.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "LibXBox_StdLith - Xbox Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\..\..\proj_xbox\Debug\Runtime\LibXBox_StdLith"
# PROP Intermediate_Dir "..\..\..\..\..\proj_xbox\Debug\Runtime\LibXBox_StdLith"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_XBOX" /D "_DEBUG" /YX /FD /G6 /Zvc6 /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_XBOX" /D "_DEBUG" /YX /FD /G6 /Zvc6 /c
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=xilink6.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "LibXBox_StdLith - Xbox Release"
# Name "LibXBox_StdLith - Xbox Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\abstractio.cpp
# End Source File
# Begin Source File

SOURCE=..\dynarray.cpp
# End Source File
# Begin Source File

SOURCE=..\fileio.cpp
# End Source File
# Begin Source File

SOURCE=..\goodlinklist.cpp
# End Source File
# Begin Source File

SOURCE=..\helpers.cpp
# End Source File
# Begin Source File

SOURCE=..\l_allocator.cpp
# End Source File
# Begin Source File

SOURCE=..\linklist.cpp
# End Source File
# Begin Source File

SOURCE=..\lithexception.cpp
# End Source File
# Begin Source File

SOURCE=..\memory.cpp
# End Source File
# Begin Source File

SOURCE=..\memoryio.cpp
# End Source File
# Begin Source File

SOURCE=..\stringholder.cpp
# End Source File
# Begin Source File

SOURCE=..\struct_bank.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\abstractio.h
# End Source File
# Begin Source File

SOURCE=..\copy_lists.h
# End Source File
# Begin Source File

SOURCE=..\dynarray.h
# End Source File
# Begin Source File

SOURCE=..\fastlinklist.h
# End Source File
# Begin Source File

SOURCE=..\fileio.h
# End Source File
# Begin Source File

SOURCE=..\genhash.h
# End Source File
# Begin Source File

SOURCE=..\genlist.h
# End Source File
# Begin Source File

SOURCE=..\glink.h
# End Source File
# Begin Source File

SOURCE=..\goodlinklist.h
# End Source File
# Begin Source File

SOURCE=..\helpers.h
# End Source File
# Begin Source File

SOURCE=..\l_allocator.h
# End Source File
# Begin Source File

SOURCE=..\linklist.h
# End Source File
# Begin Source File

SOURCE=..\lithexception.h
# End Source File
# Begin Source File

SOURCE=..\memory.h
# End Source File
# Begin Source File

SOURCE=..\memoryio.h
# End Source File
# Begin Source File

SOURCE=..\morect.h
# End Source File
# Begin Source File

SOURCE=..\multilinklist.h
# End Source File
# Begin Source File

SOURCE=..\object_bank.h
# End Source File
# Begin Source File

SOURCE=..\stdafx.h
# End Source File
# Begin Source File

SOURCE=..\stdlith.h
# End Source File
# Begin Source File

SOURCE=..\stdlithdefs.h
# End Source File
# Begin Source File

SOURCE=..\stringholder.h
# End Source File
# Begin Source File

SOURCE=..\struct_bank.h
# End Source File
# End Group
# End Target
# End Project
