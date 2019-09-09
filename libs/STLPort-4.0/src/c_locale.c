/*
 * Copyright (c) 1999
 * Silicon Graphics Computer Systems, Inc.
 *
 * Copyright (c) 1999 
 * Boris Fomitchev
 *
 * This material is provided "as is", with absolutely no warranty expressed
 * or implied. Any use is at your own risk.
 *
 * Permission to use or copy this software for any purpose is hereby granted 
 * without fee, provided the above notices are retained on all copies.
 * Permission to modify the code and to distribute modified code is granted,
 * provided the above notices are retained, and a notice that the code was
 * modified is included with the above copyright notice.
 *
 */ 
# ifdef __STL_REAL_LOCALE_IMPLEMENTED
#  define __BUILDING_STLPORT 1

#  include <stl/c_locale.h>
#  include <limits.h>

#  if defined (__STL_USE_GLIBC) && ! defined (__CYGWIN__)
#   include "c_locale_glibc/c_locale_glibc.c"
#  endif
# endif
