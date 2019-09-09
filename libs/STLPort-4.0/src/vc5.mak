#
# Tools
#

CXX=cl.exe
CC=cl.exe
RC=rc

LIB_BASENAME=stlport_vc5
COMP=VC5

EXTRA_COMMON_FLAGS=/D "_MBCS" /D "__STL_NO_FORCE_INSTANTIATE"

all: all_static

!INCLUDE vc_common.mak

#
#



