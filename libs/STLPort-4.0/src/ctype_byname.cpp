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
#include <stl/_locale.h>
#include <stl/_ctype.h>
#include <stl/_threads.h>

__STL_BEGIN_NAMESPACE

_Locale_ctype* __acquire_ctype(const char* name); 
void __release_ctype(_Locale_ctype* cat);


//----------------------------------------------------------------------
// ctype_byname<char>

ctype_byname<char>::ctype_byname(const char* name, size_t refs)
#ifdef __GNUC__
   : ctype<char>(_M_byname_table, false, refs), // JGS, the +1 not needed 
#else
  : ctype<char>(_M_byname_table + 1, false, refs),
#endif
    _M_ctype(__acquire_ctype(name))
{

  if (!_M_ctype)
    locale::_M_throw_runtime_error();

  // We have to do this, instead of just pointer twiddling, because
  // ctype_base::mask isn't the same type as _Locale_mask_t.  

  _Locale_mask_t* p = _Locale_ctype_table(_M_ctype);

   if (!p)
     locale::_M_throw_runtime_error(); 

  for (size_t i = 0; i < table_size + 1; ++i) {
    _Locale_mask_t __m = p[i];
    if (__m & (upper | lower))
      __m |= alpha;
    _M_byname_table[i] = mask(__m);
  }
}

ctype_byname<char>::~ctype_byname()
{
  __release_ctype(_M_ctype);
}

char ctype_byname<char>::do_toupper(char c) const 
{
  return _Locale_toupper(_M_ctype, c);
}

char ctype_byname<char>::do_tolower(char c) const 
{
  return _Locale_tolower(_M_ctype, c);
}

const char*
ctype_byname<char>::do_toupper(char* first, const char* last) const
{
  for ( ; first != last ; ++first) 
    *first = _Locale_toupper(_M_ctype, *first);
  return last;
}

const char*
ctype_byname<char>::do_tolower(char* first, const char* last) const
{
  for ( ; first != last ; ++first) 
    *first = _Locale_tolower(_M_ctype, *first);
  return last;
}


__STL_END_NAMESPACE

// Local Variables:
// mode:C++
// End:

