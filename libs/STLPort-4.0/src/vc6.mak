#
# Tools
#

CXX=cl.exe
CC=cl.exe

LIB_BASENAME=stlport_vc6
COMP=VC6

EXTRA_COMMON_FLAGS=/D "_MBCS"

all: platform all_static all_dynamic 

!INCLUDE vc_common.mak

#
#



