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
#include <iterator>
#include <cstring>
#include <cstdlib>
#include <locale>
#include <vector>


__STL_BEGIN_NAMESPACE

#if !defined(__STL_NO_FORCE_INSTANTIATE)
template class time_put<char, ostreambuf_iterator<char, char_traits<char> > >;
template class time_put<char, char*>;
#endif

__STL_END_NAMESPACE
