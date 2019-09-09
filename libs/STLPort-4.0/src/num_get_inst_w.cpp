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
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cfloat>

#include <iterator>
#include <locale>
#include <limits>

__STL_BEGIN_NAMESPACE

# ifndef __STL_NO_WCHAR_T

// Similar, except return the character itself instead of the numeric
// value.  Used for floating-point input.
pair<char, bool>  __STL_CALL __get_fdigit(wchar_t c, const wchar_t* digits)
{
  const wchar_t* p = find(digits, digits + 10, c);
  if (p != digits + 10)
    return pair<char, bool>((char)('0' + (p - digits)), true);
  else
    return pair<char, bool>((char)'\0', false);
}

pair<char, bool>  __STL_CALL __get_fdigit_or_sep(wchar_t c, wchar_t sep,
                                                 const wchar_t * digits)
{
  if (c == sep)
    return pair<char, bool>(',', true);
  else
    return __get_fdigit(c, digits);
}

//----------------------------------------------------------------------
// Force instantiation of of num_get<>

#if !defined(__STL_NO_FORCE_INSTANTIATE)
template class num_get<wchar_t, istreambuf_iterator<wchar_t, char_traits<wchar_t> > >;
template class num_get<wchar_t, const wchar_t*>;
#endif

__STL_END_NAMESPACE

# endif /* INSTANTIATE_WIDE_STREAMS */

// Local Variables:
// mode:C++
// End:
