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

#include "locale_impl.h"
#include <stl/_numeric_facets.h>


__STL_BEGIN_NAMESPACE

//----------------------------------------------------------------------
// numpunct<char>

numpunct<char>::numpunct(size_t refs)
#if !(defined(__MRC__) || defined(__SC__) )		//*TY 04/29/2000 - added workaround for mpw
  : locale::facet(refs),
#else					//*TY 04/29/2000 - 
  : _facet(refs),		//*TY 04/29/2000 - they forget to look into the nested class for the ctor
#endif					//*TY 04/29/2000 - 
    _M_truename("true"),
    _M_falsename("false")
{
}

numpunct<char>::~numpunct() 
{}

char   numpunct<char>::do_decimal_point() const { return '.'; }
char   numpunct<char>::do_thousands_sep() const { return ','; }
string numpunct<char>::do_grouping()  const { return string();}
string numpunct<char>::do_truename()  const { return _M_truename;}
string numpunct<char>::do_falsename() const { return _M_falsename; }

__STL_END_NAMESPACE

// Local Variables:
// mode:C++
// End:
