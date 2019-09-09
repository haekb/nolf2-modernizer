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

#include <iterator>
#include <cstring>
#include <cstdlib>

#include <locale>
#include <algorithm> // for copy

__STL_BEGIN_NAMESPACE

void __init_monetary_formats(money_base::pattern& pos_format,
                             money_base::pattern& neg_format);

void __init_monetary_formats(money_base::pattern& pos_format,
                             money_base::pattern& neg_format,
                             _Locale_monetary * monetary);

_Locale_monetary* __acquire_monetary(const char* name);
void __release_monetary(_Locale_monetary* mon);

# ifndef __STL_NO_WCHAR_T

moneypunct_byname<wchar_t, true>::moneypunct_byname(const char * name,
						 size_t refs):
  moneypunct<wchar_t, true>(refs),
  _M_monetary(__acquire_monetary(name))
{
  if (!_M_monetary)
    locale::_M_throw_runtime_error();
  __init_monetary_formats(_M_pos_format, _M_neg_format, _M_monetary);
}

moneypunct_byname<wchar_t, true>::~moneypunct_byname() 
{
  __release_monetary(_M_monetary);
}

wchar_t moneypunct_byname<wchar_t, true>::do_decimal_point() const
  {return _Locale_mon_decimal_point(_M_monetary);}

wchar_t moneypunct_byname<wchar_t, true>::do_thousands_sep() const
  {return _Locale_mon_thousands_sep(_M_monetary);}

string moneypunct_byname<wchar_t, true>::do_grouping() const
  {return _Locale_mon_grouping(_M_monetary);}

wstring moneypunct_byname<wchar_t, true>::do_curr_symbol() const
{
  string str = _Locale_int_curr_symbol(_M_monetary);
# if defined (__STL_NO_MEMBER_TEMPLATES) || defined (__STL_MSVC)
  wstring result(wstring::_Reserve_t(), str.size());
  copy(str.begin(), str.end(), result.begin());
# else
  wstring result(str.begin(), str.end());
# endif
  return result;
}

wstring moneypunct_byname<wchar_t, true>::do_positive_sign() const
{
  string str = _Locale_positive_sign(_M_monetary);
# if defined (__STL_NO_MEMBER_TEMPLATES) || defined (__STL_MSVC)
  wstring result(wstring::_Reserve_t(), str.size());
  copy(str.begin(), str.end(), result.begin());
# else
  wstring result(str.begin(), str.end());
# endif
  return result;
}


wstring moneypunct_byname<wchar_t, true>::do_negative_sign() const
{
  string str = _Locale_negative_sign(_M_monetary);
# if defined (__STL_NO_MEMBER_TEMPLATES) || defined (__STL_MSVC) 
  wstring result(wstring::_Reserve_t(), str.size());
  copy(str.begin(), str.end(), result.begin());
# else
  wstring result(str.begin(), str.end());
# endif
  return result;
}

int moneypunct_byname<wchar_t, true>::do_frac_digits() const 
  {return _Locale_int_frac_digits(_M_monetary);}

moneypunct_byname<wchar_t, false>::moneypunct_byname(const char * name,
						 size_t refs):
  moneypunct<wchar_t, false>(refs),
  _M_monetary(__acquire_monetary(name))
{
  if (!_M_monetary)
    locale::_M_throw_runtime_error() ;
  __init_monetary_formats(_M_pos_format, _M_neg_format, _M_monetary);
}

moneypunct_byname<wchar_t, false>::~moneypunct_byname()
{
  __release_monetary(_M_monetary);
}

wchar_t moneypunct_byname<wchar_t, false>::do_decimal_point() const
  {return _Locale_mon_decimal_point(_M_monetary);}

wchar_t moneypunct_byname<wchar_t, false>::do_thousands_sep() const
  {return _Locale_mon_thousands_sep(_M_monetary);}

string moneypunct_byname<wchar_t, false>::do_grouping() const
  {return _Locale_mon_grouping(_M_monetary);}

wstring moneypunct_byname<wchar_t, false>::do_curr_symbol() const
{
  string str =  _Locale_currency_symbol(_M_monetary);
# if defined (__STL_NO_MEMBER_TEMPLATES) || defined (__STL_MSVC)
  wstring result(wstring::_Reserve_t(), str.size());
  copy(str.begin(), str.end(), result.begin());
# else
  wstring result(str.begin(), str.end());
# endif
  return result;
}

wstring moneypunct_byname<wchar_t, false>::do_positive_sign() const
{
  string str = _Locale_positive_sign(_M_monetary);
# if defined (__STL_NO_MEMBER_TEMPLATES) || defined (__STL_MSVC)
  wstring result(wstring::_Reserve_t(), str.size());
  copy(str.begin(), str.end(), result.begin());
# else
  wstring result(str.begin(), str.end());
# endif
  return result;
}

wstring moneypunct_byname<wchar_t, false>::do_negative_sign() const
{
  string str = _Locale_negative_sign(_M_monetary);
# if defined (__STL_NO_MEMBER_TEMPLATES) || defined (__STL_MSVC)
  wstring result(wstring::_Reserve_t(), str.size());
  copy(str.begin(), str.end(), result.begin());
# else
  wstring result(str.begin(), str.end());
# endif
  return result;
}

int moneypunct_byname<wchar_t, false>::do_frac_digits() const 
  {return _Locale_frac_digits(_M_monetary);}

char* __write_monetary_value(long double units, char* buf,
                             const locale&)
{
  return buf + sprintf(buf, "%Lf", units);
}

wchar_t* __write_monetary_value(long double units, wchar_t* buf,
                                const locale& loc)
{
  char nbuf[64];
  size_t n = sprintf(nbuf, "%Lf", units);
  (use_facet<ctype<wchar_t> >(loc)).widen(nbuf, nbuf + n, buf);
  return buf + n;
}

# endif /* WCHAR_T */

__STL_END_NAMESPACE  

// Local Variables:
// mode:C++
// End:
