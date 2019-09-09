#
#

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 


#
# Tools
#

# RSC=rc.exe
LINK=lib.exe
DYN_LINK=link.exe
OBJEXT=obj
DYNEXT=dll
STEXT=lib
RM=-rd /S /Q

PATH_SEP=\\

MKDIR=-mkdir
LINK_OUT=/out:
DYNLINK_OUT=/out:
STATIC_SUFFIX=_static
INSTALL_STEP=do_install

!include common_macros.mak

#
#
# Flags
#

FLAGS_COMMON =/Zm800 /nologo /W3 /GR /GX /FI "vc_warning_disable.h" /D "WIN32" /D "_WINDOWS" /I "$(STLPORT_DIR)" /D "__SGI_STL_OWN_IOSTREAMS" $(EXTRA_COMMON_FLAGS)

FLAGS_COMMON_static = $(FLAGS_COMMON) /D "_LIB" /FD
FLAGS_COMMON_dynamic = $(FLAGS_COMMON) /D "_USRDLL"


LDFLAGS_COMMON_static=/nologo /machine:I386
LDFLAGS_COMMON_dynamic=/nologo /dll /incremental:no /machine:I386

CXXFLAGS_DEBUG_static=$(FLAGS_COMMON_static) /MTd /Zi /Yd /Gm /Od  /D "_DEBUG"  /Fo"$(DEBUG_OBJDIR_static)\\" /Fd"$(DEBUG_OBJDIR_static)\\" /YXstlport_prefix.h /Fp$(DEBUG_OBJDIR_static)\stlport.pch /c

CXXFLAGS_DEBUG_dynamic=$(FLAGS_COMMON_dynamic) /MDd /Zi /Yd /Gm /Od  /D "_DEBUG"  /Fo"$(DEBUG_OBJDIR_dynamic)\\" /Fd"$(DEBUG_OBJDIR_dynamic)\\" /YXstlport_prefix.h /Fp$(DEBUG_OBJDIR_dynamic)\stlport.pch /c

CXXFLAGS_STLDEBUG_static=$(FLAGS_COMMON_static) /MTd /Zi /Yd /Gm /Od  /D "_DEBUG"  /D "__STL_DEBUG" /Fo"$(STLDEBUG_OBJDIR_static)\\" /Fd"$(STLDEBUG_OBJDIR_static)\\"  /YXstlport_prefix.h /Fp$(STLDEBUG_OBJDIR_static)\stlport.pch /c 

CXXFLAGS_STLDEBUG_dynamic=$(FLAGS_COMMON_dynamic) /MDd /Zi /Yd /Gm /Od  /D "_DEBUG"  /D "__STL_DEBUG" /Fo"$(STLDEBUG_OBJDIR_dynamic)\\" /Fd"$(STLDEBUG_OBJDIR_dynamic)\\"  /YXstlport_prefix.h /Fp$(STLDEBUG_OBJDIR_dynamic)\stlport.pch /c 

LDFLAGS_DEBUG_static=$(LDFLAGS_COMMON_static) /NODEFAULTLIB:MTD /DEBUGTYPE:CV
LDFLAGS_DEBUG_dynamic=$(LDFLAGS_COMMON_dynamic) /DEBUG /DEBUGTYPE:CV /implib:"$(OUTDIR)\$(DEBUG_NAME).$(STEXT)" 

LDFLAGS_STLDEBUG_static=$(LDFLAGS_COMMON_static) /NODEFAULTLIB:MTD /DEBUGTYPE:CV
LDFLAGS_STLDEBUG_dynamic=$(LDFLAGS_COMMON_dynamic) /DEBUG /DEBUGTYPE:CV /implib:"$(OUTDIR)\$(STLDEBUG_NAME).$(STEXT)" 

CXXFLAGS_RELEASE_static=$(FLAGS_COMMON_static) /O2 /MT /D "NDEBUG" /Fo"$(RELEASE_OBJDIR_static)\\" /Fd"$(RELEASE_OBJDIR_static)\\"  /YXstlport_prefix.h /Fp$(RELEASE_OBJDIR_static)\stlport.pch /c 

CXXFLAGS_RELEASE_dynamic=$(FLAGS_COMMON_dynamic) /O2 /MD /D "NDEBUG" /Fo"$(RELEASE_OBJDIR_dynamic)\\" /Fd"$(RELEASE_OBJDIR_dynamic)\\" /YXstlport_prefix.h /Fp$(RELEASE_OBJDIR_dynamic)\stlport.pch /c 

LDFLAGS_RELEASE_static=$(LDFLAGS_COMMON_static)
LDFLAGS_RELEASE_dynamic=$(LDFLAGS_COMMON_dynamic) /implib:"$(OUTDIR)\$(RELEASE_NAME).$(STEXT)" 

RESFILE=$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)stlport.res
RESFILE_debug=$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)stlport.res
RESFILE_stldebug=$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)stlport.res


#
# Rules
#

!include common_rules.mak

!include nmake_common.mak

