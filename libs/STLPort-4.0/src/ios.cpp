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
# include "stlport_prefix.h"
#include <cstdlib>
#include <stl/_threads.h>
#include <string>
#include <algorithm>
#include <ios>
#include <locale>
#include <streambuf>

__STL_BEGIN_NAMESPACE

//----------------------------------------------------------------------
// Force instantiation of basic_ios
// For DLL exports, they are already instantiated.
#  if !defined(__STL_NO_FORCE_INSTANTIATE)
template class __STL_CLASS_DECLSPEC basic_ios<char, char_traits<char> >;
#  endif

__STL_END_NAMESPACE

// Local Variables:
// mode:C++
// End:
