###############################################################################
###
### 
###
###############################################################################

ifdef LITHTECHNG_ROOT
ROOT		= $(LITHTECHNG_ROOT)
else
ROOT		= /LithTechNG
endif

###
### Include standard LithTech Makefile.inc
###
include 	$(ROOT)/engine/Makefile.inc

###############################################################################
###
### APP SPECIFIC
###
###############################################################################

TARGET      = 
TTYPE		= obj

# OVERRIDE THESE HERE
ifeq ($(BUILD_TYPE), __RELEASE)
CFLAGS     = -D$(TARGET_PLATFORM) -O -fno-common $(INCDIRS)
CXXFLAGS   = -D$(TARGET_PLATFORM) -O -fno-exceptions -fno-common $(INCDIRS)
else
CFLAGS      = -D$(TARGET_PLATFORM) -g -fno-common $(INCDIRS)
CXXFLAGS    = -D$(TARGET_PLATFORM) -g -fno-exceptions -fno-common $(INCDIRS)
endif

###############################################################################
###
### MAKE DEPEND RULES
###
###############################################################################

### Include the dep rules
-include $(CURDIR)/Makefile.dep

###############################################################################
###
### TARGETS
###
###############################################################################

ifeq ($(MAKECMDGOALS), standalone)
FILTER_OUT = ltengineobjectsclient.cpp ltrefjustserverphysics.cpp ltrefjustserverphysicsclient.cpp ltrefphysics.cpp ltrefphysicsclient.cpp ltrefphysicsclientdistr.cpp ltrefphysicsdistr.cpp ltrefphysicsdistrcommon.cpp
endif

include 	$(ROOT)/engine/Makefile.tgt
