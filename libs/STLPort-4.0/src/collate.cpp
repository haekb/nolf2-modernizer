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

#include <string>

//*TY 05/01/2000 - removed unnecessary workaround
//#if defined(__MRC__)||defined(__SC__)		//*TY 03/04/2000 - added workaround for MPW compilers; to force its instantiation which the compiler forget to do so implicitly
//template void std::_String_base<wchar_t,allocator<wchar_t> >::_M_throw_length_error() const;
//#endif		//*TY 03/04/2000 - 

#include <locale>

#include <algorithm>
#include <vector>

__STL_BEGIN_NAMESPACE

// collate<char>

collate<char>::collate(size_t refs)
#if !(defined(__MRC__) || defined(__SC__) )		//*TY 04/29/2000 - added workaround for mpw
  : locale::facet(refs)
#else					//*TY 04/29/2000 - 
  : _facet(refs)		//*TY 04/29/2000 - they forget to look into the nested class for the ctor
#endif					//*TY 04/29/2000 - 
{}

collate<char>::~collate()
{}

int collate<char>::do_compare(const char* low1, const char* high1,
                              const char* low2, const char* high2) const
{
  return __lexicographical_compare_3way(low1, high1, low2, high2);
}

string collate<char>::transform(const char* low, const char* high) const
{
  return do_transform(low, high);
}

string collate<char>::do_transform(const char* low, const char* high) const
{
  return string(low, high);
}

long collate<char>::do_hash(const char* low, const char* high) const {
  unsigned long result = 0;
  for ( ; low < high; ++low)
    result = 5 * result + *low;
  return result;
}

__STL_END_NAMESPACE


// Local Variables:
// mode:C++
// End:

