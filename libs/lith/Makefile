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
FILTER_OUT = dprintf.cpp
endif

ifeq ($(TARGET_PLATFORM), __PS2)
FILTER_OUT = dprintf.cpp
endif

### Get the default targets
include		$(ROOT)/engine/Makefile.tgt

