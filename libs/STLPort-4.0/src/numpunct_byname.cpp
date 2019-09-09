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

// numpunct_byname<char>

numpunct_byname<char>::numpunct_byname(const char* name, size_t refs)
  : numpunct<char>(refs),
    _M_numeric(__acquire_numeric(name))
{
  if (!_M_numeric)
    locale::_M_throw_runtime_error();

  _M_truename  = _Locale_true(_M_numeric);
  _M_falsename = _Locale_false(_M_numeric);
}

numpunct_byname<char>::~numpunct_byname()
{
  __release_numeric(_M_numeric);
}

char numpunct_byname<char>::do_decimal_point() const {
  return _Locale_decimal_point(_M_numeric);
}

char numpunct_byname<char>::do_thousands_sep() const {
  return _Locale_thousands_sep(_M_numeric);
}

string numpunct_byname<char>::do_grouping() const {
  const char * __grouping = _Locale_grouping(_M_numeric);
  if (__grouping != NULL && __grouping[0] == CHAR_MAX)
    __grouping = "";
  return __grouping;
}
__STL_END_NAMESPACE

// Local Variables:
// mode:C++
// End:
