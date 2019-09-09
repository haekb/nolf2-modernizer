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

_Locale_collate* __acquire_collate(const char* name);
void __release_collate(_Locale_collate* cat);

// collate_byname<char>

collate_byname<char>::collate_byname(const char* name, size_t refs)
  : collate<char>(refs),
    _M_collate(__acquire_collate(name))
{
  if (!_M_collate)
    locale::_M_throw_runtime_error();
}

collate_byname<char>::~collate_byname()
{
  __release_collate(_M_collate);
}

int collate_byname<char>::do_compare(const char* __low1,
                                     const char* __high1,
                                     const char* __low2,
                                     const char* __high2) const {
  return _Locale_strcmp(_M_collate,
                        __low1, __high1 - __low1, 
                        __low2, __high2 - __low2);
}

collate_byname<char>::string_type
collate_byname<char>::do_transform(const char* low, const char* high) const {
  __vector__<char, allocator<char> > buf(high - low);
  size_t n = _Locale_strxfrm(_M_collate,
                             &buf.front(), high - low,
                             low, high - low);
   char& __c1 = *(buf.begin());
   char& __c2 = *(buf.begin() + n);
   return string_type( &__c1, &__c2 );
}

__STL_END_NAMESPACE


// Local Variables:
// mode:C++
// End:

