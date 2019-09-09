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

// Some helper functions used in ctype<>::scan_is and scan_is_not.

# ifndef __STL_NO_WCHAR_T

  struct _Ctype_w_is_mask {
    typedef wchar_t argument_type;
    typedef bool    result_type;

    ctype_base::mask M;
    const ctype_base::mask* table;
    
    _Ctype_w_is_mask(ctype_base::mask m, const ctype_base::mask* t)
      : M(m), table(t) {}
    bool operator()(wchar_t c) const
      { return c >= 0 && size_t(c) < ctype<char>::table_size && (table[c] & M); }
  };

//----------------------------------------------------------------------
// ctype<wchar_t>

ctype<wchar_t>::ctype(size_t refs)
#if !(defined(__MRC__) || defined(__SC__) )		//*TY 04/29/2000 - added workaround for mpw
  : locale::facet(refs)
#else					//*TY 04/29/2000 - 
  : _facet(refs)		//*TY 04/29/2000 - they forget to look into the nested class for the ctor
#endif					//*TY 04/29/2000 - 
{ }


ctype<wchar_t>::~ctype() { }

bool ctype<wchar_t>::do_is(mask m, wchar_t c) const
{
  const mask* table = ctype<char>::classic_table();
  return c >= 0 && size_t(c) < ctype<char>::table_size && (m & table[c]);
}

const wchar_t* ctype<wchar_t>::do_is(const wchar_t* low, const wchar_t* high,
                                     mask* vec) const
{
  // boris : not clear if this is the right thing to do...
  const mask* table = ctype<char>::classic_table();
  for ( ; low < high; ++low, ++vec) {
    wchar_t c = *low;
    *vec = c >= 0 && size_t(c) < ctype<char>::table_size ? table[c] : mask(0);
  }
  return high;
}

const wchar_t*
ctype<wchar_t>::do_scan_is(mask m,
                           const wchar_t* low, const wchar_t* high) const
{
  return find_if(low, high, _Ctype_w_is_mask(m, ctype<char>::classic_table()));
}

const wchar_t*
ctype<wchar_t>::do_scan_not(mask m,
                            const wchar_t* low, const wchar_t* high) const
{
  return find_if(low, high, not1(_Ctype_w_is_mask(m, ctype<char>::classic_table())));
}

wchar_t ctype<wchar_t>::do_toupper(wchar_t c) const
{
  return c >= 0 && size_t(c) < ctype<char>::table_size
    ? (wchar_t) ctype<char>::_S_upper[c]
    : c;
}

const wchar_t* 
ctype<wchar_t>::do_toupper(wchar_t* low, const wchar_t* high) const
{
  for ( ; low < high; ++low) {
    wchar_t c = *low;
    *low = c >= 0 && size_t(c) < ctype<char>::table_size
      ? (wchar_t) ctype<char>::_S_upper[c]
      : c;
  }
  return high;
}

wchar_t ctype<wchar_t>::do_tolower(wchar_t c) const
{
  return c >= 0 && size_t(c) < ctype<char>::table_size
    ? (wchar_t) ctype<char>::_S_lower[c]
    : c;
}

const wchar_t* 
ctype<wchar_t>::do_tolower(wchar_t* low, const wchar_t* high) const
{
  for ( ; low < high; ++low) {
    wchar_t c = *low;
    *low = c >= 0 && size_t(c) < ctype<char>::table_size
      ? (wchar_t) ctype<char>::_S_lower[c]
      : c;
  }
  return high;
}

wchar_t ctype<wchar_t>::do_widen(char c) const 
{
  return (wchar_t) c;
}

const char* 
ctype<wchar_t>::do_widen(const char* low, const char* high,
                         wchar_t* dest) const
{
  while (low != high)
    *dest++ = (wchar_t) *low++;
  return high;
}

char ctype<wchar_t>::do_narrow(wchar_t c, char dfault) const 
{
  return (char) c == c ? c : dfault;
}

const wchar_t* ctype<wchar_t>::do_narrow(const wchar_t* low,
                                         const wchar_t* high,
                                         char dfault, char* dest) const
{
  while (low != high) {
    wchar_t c = *low++;
    *dest++ = (char) c == c ? c : dfault;
  }

  return high;
}

# endif /* WCHAR_T */

__STL_END_NAMESPACE

// Local Variables:
// mode:C++
// End:

