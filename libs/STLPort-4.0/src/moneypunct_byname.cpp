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

#include "locale_impl.h"

__STL_BEGIN_NAMESPACE

void __init_monetary_formats(money_base::pattern& pos_format,
                             money_base::pattern& neg_format);

void __init_monetary_formats(money_base::pattern& pos_format,
                             money_base::pattern& neg_format,
                             _Locale_monetary * monetary);

_Locale_monetary* __acquire_monetary(const char* name);
void __release_monetary(_Locale_monetary* mon);

moneypunct_byname<char, true>::moneypunct_byname(const char * name,
						 size_t refs):
  moneypunct<char, true>(refs),
  _M_monetary(__acquire_monetary(name))
{
  if (!_M_monetary)
    locale::_M_throw_runtime_error();
  __init_monetary_formats(_M_pos_format, _M_neg_format, _M_monetary);
}

moneypunct_byname<char, true>::~moneypunct_byname()
{
  __release_monetary(_M_monetary);
}

char moneypunct_byname<char, true>::do_decimal_point() const 
  {return _Locale_mon_decimal_point(_M_monetary);}

char moneypunct_byname<char, true>::do_thousands_sep() const
  {return _Locale_mon_thousands_sep(_M_monetary);}

string moneypunct_byname<char, true>::do_grouping() const
  {return _Locale_mon_grouping(_M_monetary);}

string moneypunct_byname<char, true>::do_curr_symbol() const
  {return _Locale_int_curr_symbol(_M_monetary);}

string moneypunct_byname<char, true>::do_positive_sign() const
  {return _Locale_positive_sign(_M_monetary);}

string moneypunct_byname<char, true>::do_negative_sign() const
  {return _Locale_negative_sign(_M_monetary);}

int moneypunct_byname<char, true>::do_frac_digits() const 
  {return _Locale_int_frac_digits(_M_monetary);}

moneypunct_byname<char, false>::moneypunct_byname(const char * name,
						  size_t refs):
  moneypunct<char, false>(refs),
  _M_monetary(__acquire_monetary(name))
{
  if (!_M_monetary)
    locale::_M_throw_runtime_error();
  __init_monetary_formats(_M_pos_format, _M_neg_format, _M_monetary);
}

moneypunct_byname<char, false>::~moneypunct_byname()
{
  __release_monetary(_M_monetary);
}

char moneypunct_byname<char, false>::do_decimal_point() const
  {return _Locale_mon_decimal_point(_M_monetary);}

char moneypunct_byname<char, false>::do_thousands_sep() const
  {return _Locale_mon_thousands_sep(_M_monetary);}

string moneypunct_byname<char, false>::do_grouping() const
  {return _Locale_mon_grouping(_M_monetary);}

string moneypunct_byname<char, false>::do_curr_symbol() const
  {return _Locale_currency_symbol(_M_monetary);}

string moneypunct_byname<char, false>::do_positive_sign() const
  {return _Locale_positive_sign(_M_monetary);}

string moneypunct_byname<char, false>::do_negative_sign() const
  {return _Locale_negative_sign(_M_monetary);}

int moneypunct_byname<char, false>::do_frac_digits() const 
  {return _Locale_frac_digits(_M_monetary);}

__STL_END_NAMESPACE  

// Local Variables:
// mode:C++
// End:
