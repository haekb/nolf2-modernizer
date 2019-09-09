# Microsoft Developer Studio Project File - Name="ClientRes" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=ClientRes - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ClientRes.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ClientRes.mak" CFG="ClientRes - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ClientRes - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ClientRes - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ClientRes - Win32 Final" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ClientRes - Win32 Final DE" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ClientRes - Win32 Final ES" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ClientRes - Win32 Final IT" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ClientRes - Win32 Final FR" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "ClientRes"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ClientRes - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\built\Release\ClientRes\TO2"
# PROP Intermediate_Dir "..\..\built\Release\ClientRes\TO2"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I ".\\" /I "..\STLPORT-4.0\STLPORT" /I "..\shared" /I "..\shared\lang\en" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /i ".\\" /i "lang\en" /i "..\shared" /i "..\shared\lang\en" /i "..\..\shared\\" /i "..\..\shared\Lang\EN" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"..\..\built\Release\ClientRes\TO2\CRes.dll"
# Begin Custom Build
TargetPath=\proj\to2\source_retail\Game\built\Release\ClientRes\TO2\CRes.dll
InputPath=\proj\to2\source_retail\Game\built\Release\ClientRes\TO2\CRes.dll
SOURCE="$(InputPath)"

"$(GAME_REZ_DIR)\cres.dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo copy $(TargetPath) $(GAME_REZ_DIR) 
	copy $(TargetPath) $(GAME_REZ_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\built\debug\ClientRes\TO2"
# PROP Intermediate_Dir "..\..\built\debug\ClientRes\TO2"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /I "..\STLPORT-4.0\STLPORT" /I "..\shared" /I "..\shared\lang\en" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /i ".\\" /i "lang\en" /i "..\shared" /i "..\shared\lang\en" /i "..\..\shared\\" /i "..\..\shared\Lang\EN" /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"..\..\built\debug\ClientRes\TO2\CRes.dll" /pdbtype:sept
# Begin Custom Build
TargetPath=\proj\to2\source_retail\Game\built\debug\ClientRes\TO2\CRes.dll
InputPath=\proj\to2\source_retail\Game\built\debug\ClientRes\TO2\CRes.dll
SOURCE="$(InputPath)"

"$(GAME_REZ_DIR)\cres.dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo copy $(TargetPath) $(GAME_REZ_DIR) 
	copy $(TargetPath) $(GAME_REZ_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Final"
# PROP BASE Intermediate_Dir "Final"
# PROP BASE Ignore_Export_Lib 1
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\built\Final\ClientRes\TO2"
# PROP Intermediate_Dir "..\..\built\Final\ClientRes\TO2"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "..\STLPORT-4.0\STLPORT" /I "..\shared" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_FINAL" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "..\STLPORT-4.0\STLPORT" /I "..\shared" /I "..\shared\lang\en" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_FINAL" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /i "..\shared" /d "NDEBUG"
# ADD RSC /l 0x409 /i ".\\" /i "lang\en" /i "..\shared" /i "..\shared\lang\en" /i "..\..\shared\\" /i "..\..\shared\Lang\EN" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"..\..\built\Final\ClientRes\TO2\CRes.dll"
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"..\..\built\Final\ClientRes\TO2\CRes.dll"
# Begin Custom Build
TargetPath=\proj\to2\source_retail\Game\built\Final\ClientRes\TO2\CRes.dll
InputPath=\proj\to2\source_retail\Game\built\Final\ClientRes\TO2\CRes.dll
SOURCE="$(InputPath)"

"$(GAME_REZ_DIR)\cres.dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo copy $(TargetPath) $(GAME_REZ_DIR) 
	copy $(TargetPath) $(GAME_REZ_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final DE"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ClientRes___Win32_Final_DE"
# PROP BASE Intermediate_Dir "ClientRes___Win32_Final_DE"
# PROP BASE Ignore_Export_Lib 1
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\built\FinalDE\ClientRes\TO2"
# PROP Intermediate_Dir "..\..\built\FinalDE\ClientRes\TO2"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "..\STLPORT-4.0\STLPORT" /I "..\shared" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_FINAL" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "..\STLPORT-4.0\STLPORT" /I "..\shared" /I "..\shared\lang\de" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_FINAL" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /i "..\shared" /d "NDEBUG"
# ADD RSC /l 0x409 /i ".\\" /i "lang\de" /i "..\shared" /i "..\shared\lang\de" /i "..\..\shared\\" /i "..\..\shared\Lang\de" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"..\..\built\Final\ClientRes\TO2\CRes.dll"
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"..\..\built\FinalDE\ClientRes\TO2\CRes.dll"
# Begin Custom Build
TargetPath=\proj\to2\source_retail\Game\built\FinalDE\ClientRes\TO2\CRes.dll
InputPath=\proj\to2\source_retail\Game\built\FinalDE\ClientRes\TO2\CRes.dll
SOURCE="$(InputPath)"

"$(GAME_REZ_DIR)\cres.dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo copy $(TargetPath) $(GAME_REZ_DIR) 
	copy $(TargetPath) $(GAME_REZ_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final ES"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ClientRes___Win32_Final_ES"
# PROP BASE Intermediate_Dir "ClientRes___Win32_Final_ES"
# PROP BASE Ignore_Export_Lib 1
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\built\FinalES\ClientRes\TO2"
# PROP Intermediate_Dir "..\..\built\FinalES\ClientRes\TO2"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "..\STLPORT-4.0\STLPORT" /I "..\shared" /I "..\shared\lang\es" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_FINAL" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "..\STLPORT-4.0\STLPORT" /I "..\shared" /I "..\shared\lang\es" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_FINAL" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /i ".\\" /i "lang\es" /i "..\shared" /i "..\shared\lang\es" /d "NDEBUG"
# ADD RSC /l 0x409 /i ".\\" /i "lang\es" /i "..\shared" /i "..\shared\lang\es" /i "..\..\shared\\" /i "..\..\shared\Lang\es" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"..\..\built\FinalDE\ClientRes\TO2\CRes.dll"
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"..\..\built\FinalES\ClientRes\TO2\CRes.dll"
# Begin Custom Build
TargetPath=\proj\to2\source_retail\Game\built\FinalES\ClientRes\TO2\CRes.dll
InputPath=\proj\to2\source_retail\Game\built\FinalES\ClientRes\TO2\CRes.dll
SOURCE="$(InputPath)"

"$(GAME_REZ_DIR)\cres.dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo copy $(TargetPath) $(GAME_REZ_DIR) 
	copy $(TargetPath) $(GAME_REZ_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final IT"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ClientRes___Win32_Final_IT"
# PROP BASE Intermediate_Dir "ClientRes___Win32_Final_IT"
# PROP BASE Ignore_Export_Lib 1
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\built\FinalIT\ClientRes\TO2"
# PROP Intermediate_Dir "..\..\built\FinalIT\ClientRes\TO2"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "..\STLPORT-4.0\STLPORT" /I "..\shared" /I "..\shared\lang\it" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_FINAL" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "..\STLPORT-4.0\STLPORT" /I "..\shared" /I "..\shared\lang\it" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_FINAL" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /i ".\\" /i "lang\it" /i "..\shared" /i "..\shared\lang\it" /d "NDEBUG"
# ADD RSC /l 0x409 /i ".\\" /i "lang\it" /i "..\shared" /i "..\shared\lang\it" /i "..\..\shared\\" /i "..\..\shared\Lang\it" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"..\..\built\FinalDE\ClientRes\TO2\CRes.dll"
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"..\..\built\FinalIT\ClientRes\TO2\CRes.dll"
# Begin Custom Build
TargetPath=\proj\to2\source_retail\Game\built\FinalIT\ClientRes\TO2\CRes.dll
InputPath=\proj\to2\source_retail\Game\built\FinalIT\ClientRes\TO2\CRes.dll
SOURCE="$(InputPath)"

"$(GAME_REZ_DIR)\cres.dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo copy $(TargetPath) $(GAME_REZ_DIR) 
	copy $(TargetPath) $(GAME_REZ_DIR) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final FR"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ClientRes___Win32_Final_FR"
# PROP BASE Intermediate_Dir "ClientRes___Win32_Final_FR"
# PROP BASE Ignore_Export_Lib 1
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\built\FinalFR\ClientRes\TO2"
# PROP Intermediate_Dir "..\..\built\FinalFR\ClientRes\TO2"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "..\STLPORT-4.0\STLPORT" /I "..\shared" /I "..\shared\lang\fr" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_FINAL" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "..\STLPORT-4.0\STLPORT" /I "..\shared" /I "..\shared\lang\fr" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_FINAL" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /i ".\\" /i "lang\fr" /i "..\shared" /i "..\shared\lang\fr" /d "NDEBUG"
# ADD RSC /l 0x409 /i ".\\" /i "lang\fr" /i "..\shared" /i "..\shared\lang\fr" /i "..\..\shared\\" /i "..\..\shared\Lang\fr" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"..\..\built\FinalDE\ClientRes\TO2\CRes.dll"
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"..\..\built\FinalFR\ClientRes\TO2\CRes.dll"
# Begin Custom Build
TargetPath=\proj\to2\source_retail\Game\built\FinalFR\ClientRes\TO2\CRes.dll
InputPath=\proj\to2\source_retail\Game\built\FinalFR\ClientRes\TO2\CRes.dll
SOURCE="$(InputPath)"

"$(GAME_REZ_DIR)\cres.dll" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo copy $(TargetPath) $(GAME_REZ_DIR) 
	copy $(TargetPath) $(GAME_REZ_DIR) 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "ClientRes - Win32 Release"
# Name "ClientRes - Win32 Debug"
# Name "ClientRes - Win32 Final"
# Name "ClientRes - Win32 Final DE"
# Name "ClientRes - Win32 Final ES"
# Name "ClientRes - Win32 Final IT"
# Name "ClientRes - Win32 Final FR"
# Begin Group "Localized Files"

# PROP Default_Filter ""
# Begin Group "DE"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Lang\DE\ClientRes.rc

!IF  "$(CFG)" == "ClientRes - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final DE"

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Lang\DE\credits.txt

!IF  "$(CFG)" == "ClientRes - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final DE"

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Lang\DE\intro.txt

!IF  "$(CFG)" == "ClientRes - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final DE"

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "EN"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Lang\EN\ClientRes.rc

!IF  "$(CFG)" == "ClientRes - Win32 Release"

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Debug"

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final"

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Lang\EN\credits.txt

!IF  "$(CFG)" == "ClientRes - Win32 Release"

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Debug"

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final"

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Lang\EN\intro.txt

!IF  "$(CFG)" == "ClientRes - Win32 Release"

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Debug"

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final"

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final ES"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final IT"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final FR"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "ES"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Lang\ES\ClientRes.rc

!IF  "$(CFG)" == "ClientRes - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final ES"

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Lang\ES\credits.txt

!IF  "$(CFG)" == "ClientRes - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final ES"

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Lang\ES\intro.txt

!IF  "$(CFG)" == "ClientRes - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final ES"

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "IT"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Lang\IT\ClientRes.rc

!IF  "$(CFG)" == "ClientRes - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final IT"

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Lang\IT\credits.txt

!IF  "$(CFG)" == "ClientRes - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final IT"

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Lang\IT\intro.txt

!IF  "$(CFG)" == "ClientRes - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final IT"

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final FR"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "FR"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Lang\FR\ClientRes.rc

!IF  "$(CFG)" == "ClientRes - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final FR"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Lang\FR\credits.txt

!IF  "$(CFG)" == "ClientRes - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final FR"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Lang\FR\intro.txt

!IF  "$(CFG)" == "ClientRes - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final DE"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final ES"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final IT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ClientRes - Win32 Final FR"

!ENDIF 

# End Source File
# End Group
# End Group
# Begin Source File

SOURCE=..\Shared\arrow.cur
# End Source File
# Begin Source File

SOURCE=.\arrow.cur
# End Source File
# Begin Source File

SOURCE=.\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\ClientRes.h
# End Source File
# Begin Source File

SOURCE=..\Shared\ClientResShared.h
# End Source File
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# End Target
# End Project
