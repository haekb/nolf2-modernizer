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
#include <locale>

#include <algorithm>
#include <vector>

__STL_BEGIN_NAMESPACE

# ifndef __STL_NO_WCHAR_T

// collate<wchar_t>

collate<wchar_t>::collate(size_t refs)
#if !(defined(__MRC__) || defined(__SC__) )		//*TY 04/29/2000 - added workaround for mpw
  : locale::facet(refs)
#else					//*TY 04/29/2000 - 
  : _facet(refs)		//*TY 04/29/2000 - they forget to look into the nested class for the ctor
#endif					//*TY 04/29/2000 - 
{}

collate<wchar_t>::~collate()
{}

int
collate<wchar_t>::do_compare(const wchar_t* low1, const wchar_t* high1,
                             const wchar_t* low2, const wchar_t* high2) const
{
  return __lexicographical_compare_3way(low1, high1, low2, high2);
}

wstring
collate<wchar_t>::transform(const wchar_t* low, const wchar_t* high) const
{
  return do_transform(low, high);
}

wstring
collate<wchar_t>::do_transform(const wchar_t* low, const wchar_t* high) const
{
  return wstring(low, high);
}


long collate<wchar_t>::do_hash(const wchar_t* low, const wchar_t* high) const
{
  unsigned long result = 0;
  for ( ; low < high; ++low)
    result = 5 * result + *low;
  return result;
}

# endif /* WCHAR_T */

__STL_END_NAMESPACE


// Local Variables:
// mode:C++
// End:

