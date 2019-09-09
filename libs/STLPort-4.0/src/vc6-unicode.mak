#
# Tools
#

CXX=cl.exe
CC=cl.exe
RC=rc

LIB_BASENAME=stlport_vc6_unicode
COMP=VC6_UNICODE

EXTRA_COMMON_FLAGS=/D "_UNICODE" /D "UNICODE"

all: all_dynamic all_static

!INCLUDE vc_common.mak

#
#



