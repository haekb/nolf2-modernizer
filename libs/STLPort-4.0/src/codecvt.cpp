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

//----------------------------------------------------------------------
// codecvt<char, char, mbstate_t>

codecvt<char, char, mbstate_t>::codecvt(size_t refs)
#if !(defined(__MRC__) || defined(__SC__) )		//*TY 04/29/2000 - added workaround for mpw
  : locale::facet(refs)
#else					//*TY 04/29/2000 - 
  : _facet(refs)		//*TY 04/29/2000 - they forget to look into the nested class for the ctor
#endif					//*TY 04/29/2000 - 
{}

codecvt<char, char, mbstate_t>::~codecvt()
{}

int codecvt<char, char, mbstate_t>::do_length(const mbstate_t&,
                                              const  char* from, 
                                              const  char* end,
                                              size_t max) const
{
  return min( __STATIC_CAST(size_t, (end - from)), max);
}

int codecvt<char, char, mbstate_t>::do_max_length() const __STL_NOTHROW
{
 return 1; 
}

bool
codecvt<char, char, mbstate_t>::do_always_noconv() const __STL_NOTHROW
{
  return true;
}

int 
codecvt<char, char, mbstate_t>::do_encoding() const __STL_NOTHROW
{
  return 1; 
}


codecvt_base::result 
codecvt<char, char, mbstate_t>::do_unshift(mbstate_t& /* __state */,
                                           char*      __to,
                                           char*      /* __to_limit */,
                                           char*&     __to_next) const
{ __to_next = __to; return noconv; }

codecvt_base::result 
codecvt<char, char, mbstate_t>::do_in (mbstate_t&   /* __state */ , 
                                       const char*  __from,
                                       const char*  /* __from_end */,
                                       const char*& __from_next,
                                       char*        __to,
                                       char*        /* __to_end */,
                                       char*&       __to_next) const
{ __from_next = __from; __to_next   = __to; return noconv; }

codecvt_base::result 
codecvt<char, char, mbstate_t>::do_out(mbstate_t&   /* __state */,
                                       const char*  __from,
                                       const char*  /* __from_end */,
                                       const char*& __from_next,
                                       char*        __to,
                                       char*        /* __to_limit */,
                                       char*&       __to_next) const
{ __from_next = __from; __to_next   = __to; return noconv; }

__STL_END_NAMESPACE

# endif /* __STL_NO_MBSTATE_T */

// Local Variables:
// mode:C++
// End:

