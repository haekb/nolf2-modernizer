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
#include <stl/_config.h>
#include <stl/_range_errors.h>
#include <string>
#include <stdexcept>

__STL_BEGIN_NAMESPACE

#ifdef __STL_THROW_RANGE_ERRORS

void __STL_DECLSPEC __STL_CALL
__stl_throw_range_error(const char* msg)
{
  throw range_error(string(msg));
}

void __STL_DECLSPEC __STL_CALL
__stl_throw_out_of_range(const char* msg)
{
  throw out_of_range(string(msg));
}

void  __STL_DECLSPEC __STL_CALL
__stl_throw_length_error(const char* msg)
{
  throw length_error(string(msg));
}

#endif /* __STL_THROW_RANGE_ERRORS */

__STL_END_NAMESPACE

// Local Variables:
// mode:C++
// End:
