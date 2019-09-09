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
// numpunct<wchar_t>

# ifdef __STL_NO_WCHAR_T

static bool __dummy_w_numpunct;

# else

numpunct<wchar_t>::numpunct(size_t refs)
#if !(defined(__MRC__) || defined(__SC__) )		//*TY 04/29/2000 - added workaround for mpw
  : locale::facet(refs),
#else					//*TY 04/29/2000 - 
  : _facet(refs),		//*TY 04/29/2000 - they forget to look into the nested class for the ctor
#endif					//*TY 04/29/2000 - 
    _M_truename(L"true"),
    _M_falsename(L"false")
{
}

numpunct<wchar_t>::~numpunct() 
{}

wchar_t numpunct<wchar_t>::do_decimal_point() const
{
  return L'.';
}

wchar_t numpunct<wchar_t>::do_thousands_sep() const
{
  return L',';
}

string numpunct<wchar_t>::do_grouping() const
{
  return string();
}


wstring numpunct<wchar_t>::do_truename() const
{
  return _M_truename;
}
 
wstring numpunct<wchar_t>::do_falsename() const
{
  return _M_falsename;
} 

// numpunct_byname<wchar_t> 

numpunct_byname<wchar_t>::numpunct_byname(const char* name, size_t refs)
  : numpunct<wchar_t>(refs),
    _M_numeric(__acquire_numeric(name))
{
  if (!_M_numeric)
    locale::_M_throw_runtime_error();

  const char* truename  = _Locale_true(_M_numeric);
  const char* falsename = _Locale_false(_M_numeric);
  _M_truename.resize(strlen(truename));
  _M_truename.resize(strlen(falsename));
  copy(truename,  truename  + strlen(truename), _M_truename.begin());
  copy(falsename, falsename + strlen(falsename), _M_falsename.begin());
}

numpunct_byname<wchar_t>::~numpunct_byname()
{
  __release_numeric(_M_numeric);
}

wchar_t numpunct_byname<wchar_t>::do_decimal_point() const {
  return (wchar_t) _Locale_decimal_point(_M_numeric);
}

wchar_t numpunct_byname<wchar_t>::do_thousands_sep() const {
  return (wchar_t) _Locale_thousands_sep(_M_numeric);
}

string numpunct_byname<wchar_t>::do_grouping() const {
  const char * __grouping = _Locale_grouping(_M_numeric);
  if (__grouping != NULL && __grouping[0] == CHAR_MAX)
    __grouping = "";
  return __grouping;
}

# endif

__STL_END_NAMESPACE

// Local Variables:
// mode:C++
// End:
