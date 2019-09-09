 #
 # Basename for libraries
 #
 LIB_BASENAME = libstlport_sunpro
 
 # STL_INCL= -I. -I${PWD}/../stlport/SC5
 STL_INCL= -I. -I${PWD}/../stlport
 
 CC = CC
 CXX = CC
 
 #
 # guts for common stuff
 #
 #
 LINK=$(CC) -mt -xar -o
 DYN_LINK=$(CC) -mt -G -o
 
 OBJEXT=o
 DYNEXT=so
 STEXT=a
 RM=rm -rf
 PATH_SEP=/
 MKDIR=mkdir -p
 COMP=SUN
 
 # LINK_OUT=-xar -o  
 # DYNLINK_OUT=-o 
 
 all: all_static all_dynamic
 
 include common_macros.mak
 
 CXXFLAGS_COMMON = -mt -library=%none,Crun -template=wholeclass ${STL_INCL} -D__SGI_STL_OWN_IOSTREAMS
 
 SHCXXFLAGS = -KPIC
 
 #
 # Try those flags to see if they help to get maximum efficiency :
 # -Qoption iropt -R,-Ml30,-Ms30,-Mi1000000,-Mm1000000,-Mr1000000,-Ma1000000,-Mc1000000,-Mt1000000
 RELEASE_FLAGS = -O2 -Qoption iropt -R,-Ml30,-Ms30,-Mi1000000,-Mm1000000,-Mr1000000,-Ma1000000,-Mc1000000,-Mt1000000
 
 
 # install: $(TARGETS)
 #	cp -p $(TARGETS) ${INSTALLDIR}
 
 CXXFLAGS_RELEASE_static = $(CXXFLAGS_COMMON) ${RELEASE_FLAGS}
 CXXFLAGS_RELEASE_dynamic = $(CXXFLAGS_COMMON) ${RELEASE_FLAGS} $(SHCXXFLAGS)
 
 CXXFLAGS_DEBUG_static = $(CXXFLAGS_COMMON) -g
 CXXFLAGS_DEBUG_dynamic = $(CXXFLAGS_COMMON) -g $(SHCXXFLAGS)
 
 CXXFLAGS_STLDEBUG_static = $(CXXFLAGS_COMMON) -g -D__STL_DEBUG
 CXXFLAGS_STLDEBUG_dynamic = $(CXXFLAGS_COMMON) -g -D__STL_DEBUG $(SHCXXFLAGS)
 
 LDFLAGS_RELEASE_static = ${CXXFLAGS_RELEASE_static}
 LDFLAGS_RELEASE_dynamic = ${CXXFLAGS_RELEASE_dynamic}
 
 LDFLAGS_DEBUG_static = ${CXXFLAGS_DEBUG_static}
 LDFLAGS_DEBUG_dynamic = ${CXXFLAGS_DEBUG_dynamic}
 
 LDFLAGS_STLDEBUG_static = ${CXXFLAGS_STLDEBUG_static}
 LDFLAGS_STLDEBUG_dynamic = ${CXXFLAGS_STLDEBUG_dynamic}
 
 include common_percent_rules.mak
 include common_rules.mak
 
