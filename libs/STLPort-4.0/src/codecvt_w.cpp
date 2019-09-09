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
#include <stdexcept>
#include <stl/_locale.h>
#include <stl/_codecvt.h>
#include <algorithm>

# ifndef __STL_NO_MBSTATE_T

__STL_BEGIN_NAMESPACE

# ifndef __STL_NO_WCHAR_T
//----------------------------------------------------------------------
// codecvt<wchar_t, char, mbstate_t>

codecvt<wchar_t, char, mbstate_t>::codecvt(size_t refs)
#if !(defined(__MRC__) || defined(__SC__) )		//*TY 04/29/2000 - added workaround for mpw
  : locale::facet(refs)
#else					//*TY 04/29/2000 - 
  : _facet(refs)		//*TY 04/29/2000 - they forget to look into the nested class for the ctor
#endif					//*TY 04/29/2000 - 
{}

codecvt<wchar_t, char, mbstate_t>::~codecvt() 
{}


codecvt<wchar_t, char, mbstate_t>::result
codecvt<wchar_t, char, mbstate_t>::do_out(state_type&         /* state */, 
                                          const intern_type*  from,
                                          const intern_type*  from_end,
                                          const intern_type*& from_next,
                                          extern_type*        to,
                                          extern_type*        to_limit,
                                          extern_type*&       to_next) const
{
  ptrdiff_t len = min(from_end - from, to_limit - to);
  copy(from, from + len, to);
  from_next = from + len;
  to_next   = to   + len;
  return ok;
}

codecvt<wchar_t, char, mbstate_t>::result
codecvt<wchar_t, char, mbstate_t>::do_in (state_type&       /* state */,
                                          const extern_type*  from,
                                          const extern_type*  from_end,
                                          const extern_type*& from_next,
                                          intern_type*        to,
                                          intern_type*        to_limit,
                                          intern_type*&       to_next) const
{
  ptrdiff_t len = min(from_end - from, to_limit - to);
  copy(from, from + len, to);
  from_next = from + len;
  to_next   = to   + len;
  return ok;
}

codecvt<wchar_t, char, mbstate_t>::result
codecvt<wchar_t, char, mbstate_t>::do_unshift(state_type&   /* state */,
                                              extern_type*  to, 
                                              extern_type*  ,
                                              extern_type*& to_next) const
{
  to_next = to;
  return noconv;
}

int codecvt<wchar_t, char, mbstate_t>::do_encoding() const __STL_NOTHROW {
  return 1;
}


bool codecvt<wchar_t, char, mbstate_t>::do_always_noconv() const __STL_NOTHROW
{
  return true;
}

int codecvt<wchar_t, char, mbstate_t>::do_length(const  state_type&,
                                                 const  extern_type* from, 
                                                 const  extern_type* end,
                                                 size_t max) const 
{
  return min((size_t) (end - from), max);
}

int codecvt<wchar_t, char, mbstate_t>::do_max_length() const __STL_NOTHROW {
  return 1;
}

# endif

__STL_END_NAMESPACE

# endif /* __STL_NO_MBSTATE_T */

// Local Variables:
// mode:C++
// End:

