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
#ifndef __STL_NUMERIC_FACETS_C
#define __STL_NUMERIC_FACETS_C

#include  <stl/_pair.h>
# include <stl/_stream_iterator.h>

__STL_BEGIN_NAMESPACE


template <class _CharT, class _InputIterator>
locale::id num_get<_CharT, _InputIterator>::id;

template <class _CharT, class _OutputIterator>
locale::id num_put<_CharT, _OutputIterator>::id;

# if defined (__STL_DESIGNATED_DLL) || ! defined (__STL_NO_CUSTOM_IO)

// issue 118
template <class _CharT, class _InputIter>  
_InputIter 
num_get<_CharT, _InputIter>::do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                                    ios_base::iostate& __err, short& __val) const {
  return _M_do_get_integer(__in, __end, __str, __err, __val, (_CharT*)0 );
}

template <class _CharT, class _InputIter>  
_InputIter 
num_get<_CharT, _InputIter>::do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                                    ios_base::iostate& __err, int& __val) const {
  return _M_do_get_integer(__in, __end, __str, __err, __val, (_CharT*)0 );
}

template <class _CharT, class _InputIter>  
_InputIter 
num_get<_CharT, _InputIter>::do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                                    ios_base::iostate& __err, long& __val) const {
  return _M_do_get_integer(__in, __end, __str, __err, __val, (_CharT*)0 );
}

template <class _CharT, class _InputIter>  
_InputIter 
num_get<_CharT, _InputIter>::do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                                    ios_base::iostate& __err,
                                    unsigned short& __val) const {
  return _M_do_get_integer(__in, __end, __str, __err, __val, (_CharT*)0 );
}

template <class _CharT, class _InputIter>  
_InputIter 
num_get<_CharT, _InputIter>::do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                                    ios_base::iostate& __err, 
                                    unsigned int& __val) const {
  return _M_do_get_integer(__in, __end, __str, __err, __val, (_CharT*)0 );
}

template <class _CharT, class _InputIter>  
_InputIter 
num_get<_CharT, _InputIter>::do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                                    ios_base::iostate& __err,
                                    unsigned long& __val) const {
  return _M_do_get_integer(__in, __end, __str, __err, __val, (_CharT*)0 );
}


template <class _CharT, class _InputIter>  
_InputIter 
num_get<_CharT, _InputIter>::do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                                    ios_base::iostate& __err,
                                    float& __val) const {
  return _M_do_get_float(__in, __end, __str, __err, __val, (_CharT*)0 );
}

template <class _CharT, class _InputIter>  
_InputIter 
num_get<_CharT, _InputIter>::do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                                    ios_base::iostate& __err, 
                                    double& __val) const {
  return _M_do_get_float(__in, __end, __str, __err, __val, (_CharT*)0 );
}

#ifndef __STL_NO_LONG_DOUBLE
template <class _CharT, class _InputIter>  
_InputIter 
num_get<_CharT, _InputIter>::do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                           ios_base::iostate& __err,
                                    long double& __val) const {
  return _M_do_get_float(__in, __end, __str, __err, __val, (_CharT*)0 );
}
#endif /* __STL_LONG_DOUBLE */

template <class _CharT, class _InputIter>  
_InputIter 
num_get<_CharT, _InputIter>::do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                           ios_base::iostate& __err,
                           void*& __p) const {
    ptrdiff_t __val;
    iter_type __tmp = _M_do_get_integer(__in, __end, __str, __err, __val, (_CharT*)0 );
    if (!(__err & ios_base::failbit))
      __p = __REINTERPRET_CAST(void*,__val);
    return __tmp;
  }


#ifdef __STL_LONG_LONG

template <class _CharT, class _InputIter>  
_InputIter 
num_get<_CharT, _InputIter>::do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                                    ios_base::iostate& __err,
                                    long long& __val) const {
  return _M_do_get_integer(__in, __end, __str, __err, __val, (_CharT*)0 );
}

template <class _CharT, class _InputIter>  
_InputIter 
num_get<_CharT, _InputIter>::do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                                    ios_base::iostate& __err,
                                    unsigned long long& __val) const {
  return _M_do_get_integer(__in, __end, __str, __err, __val, (_CharT*)0 );
}

#endif /* __STL_LONG_LONG */

# ifndef __STL_NO_BOOL
template <class _CharT, class _OutputIter>  
_OutputIter 
num_put<_CharT, _OutputIter>::do_put(_OutputIter __s, ios_base& __f, 
                                     char_type __fill,  bool __val) const {
  return __f.flags() & ios_base::boolalpha
    ? _M_do_put_bool(__s, __f, __fill, __val)
    : _M_do_put_integer(__s, __f, __fill, __STATIC_CAST(long,__val));
}
# endif

template <class _CharT, class _OutputIter>
_OutputIter 
num_put<_CharT, _OutputIter>::do_put(_OutputIter __s, ios_base& __f, _CharT __fill,
                                     long __val) const {
  return _M_do_put_integer(__s, __f, __fill, __val);
}


template <class _CharT, class _OutputIter>  
_OutputIter 
num_put<_CharT, _OutputIter>::do_put(_OutputIter __s, ios_base& __f, _CharT __fill,
                           unsigned long __val) const {
  return _M_do_put_integer(__s, __f, __fill, __val);
}

template <class _CharT, class _OutputIter>  
_OutputIter 
num_put<_CharT, _OutputIter>::do_put(_OutputIter __s, ios_base& __f, _CharT __fill,
                                     double __val) const {
  return _M_do_put_float(__s, __f, __fill, __val);
}

#ifndef __STL_NO_LONG_DOUBLE
template <class _CharT, class _OutputIter>  
_OutputIter 
num_put<_CharT, _OutputIter>::do_put(_OutputIter __s, ios_base& __f, _CharT __fill,
                                     long double __val) const {
  return _M_do_put_float(__s, __f, __fill, __val);
}
#endif

#ifdef __STL_LONG_LONG
template <class _CharT, class _OutputIter>  
_OutputIter 
num_put<_CharT, _OutputIter>::do_put(_OutputIter __s, ios_base& __f, _CharT __fill,
                                     long long __val) const {
  return _M_do_put_integer(__s, __f, __fill, __val);
}

template <class _CharT, class _OutputIter>  
_OutputIter 
num_put<_CharT, _OutputIter>::do_put(_OutputIter __s, ios_base& __f, _CharT __fill,
                                     unsigned long long __val) const {
  return _M_do_put_integer(__s, __f, __fill, __val);
}

#endif /* __STL_LONG_LONG */

template <class _CharT, class _OutputIter>  
_OutputIter 
num_put<_CharT, _OutputIter>::do_put(_OutputIter __s, ios_base& __f, _CharT __fill,
                                     const void* __val) const {
  return _M_do_put_integer(__s, __f, __fill,
                           __REINTERPRET_CAST(unsigned long,__val));
}

# endif

# ifdef __STL_USE_TEMPLATE_EXPORT

__STL_EXPORT_TEMPLATE_CLASS num_get<char, istreambuf_iterator<char, char_traits<char> > >;
__STL_EXPORT_TEMPLATE_CLASS num_get<char, const char*>;

#  ifndef __STL_NO_WCHAR_T
__STL_EXPORT_TEMPLATE_CLASS num_get<wchar_t, istreambuf_iterator<wchar_t, char_traits<wchar_t> > >;
__STL_EXPORT_TEMPLATE_CLASS num_get<wchar_t, const wchar_t*>;
#  endif /* __STL_NO_WCHAR_T */

__STL_EXPORT_TEMPLATE_CLASS num_put<char, ostreambuf_iterator<char, char_traits<char> > >;
__STL_EXPORT_TEMPLATE_CLASS num_put<char, char*>;

#  ifndef __STL_NO_WCHAR_T
__STL_EXPORT_TEMPLATE_CLASS num_put<wchar_t, ostreambuf_iterator<wchar_t, char_traits<wchar_t> > >;
__STL_EXPORT_TEMPLATE_CLASS num_put<wchar_t, wchar_t*>;
#  endif /* __STL_NO_WCHAR_T */

# endif

# if defined (__STL_DESIGNATED_DLL) || ! defined (__STL_NO_CUSTOM_IO)

// __get_integer for wchar_t.
template <class _InputIter, class _Integer>
pair<_InputIter, bool> __STL_CALL
__get_integer(_InputIter __first, _InputIter __last,
              int __base, 
# ifdef __STL_NO_WCHAR_T
	      char __separator,
# else
	      wchar_t __separator,
# endif 
	      bool __do_sep,
              const locale& __loc,
              _Integer& __val) 
{
  int __got = 0;
  bool __overflow = false;
  bool __negative = false;
  _Integer __result = 0;
# ifdef __STL_NO_WCHAR_T
  typedef char _CharT;
# else
  typedef wchar_t _CharT;
# endif 

  const ctype<_CharT>& __c_type = use_facet<ctype<_CharT> >(__loc) ;

  _CharT __digits[10];
  _CharT __xdigits[12];
  __initialize_get_digit(__digits, __xdigits, __c_type);

  if (__first == __last)
    return make_pair(__first, false);
  else {
    _CharT __c = *__first;
    if (__c == __c_type.widen('-')) {
      __negative = true;
      ++__first;
    }
    else if (__c == __c_type.widen('+')) 
      ++__first;
  }

  for ( ; __first != __last ; ++__first) {
    int __n = __get_digit(*__first, __digits, __xdigits, __separator);
    if (__n < 0) {               // Not a digit
      if (__do_sep && __n == -1) // Separator.  Just ignore it.
        continue;
      else                       // Something other than digit or separator.
        break;
    }
    else if (__n >= __base)
      break;

    _Integer __next = __base * __result + __n;
    ++__got;
    if (__result != 0)
      __overflow = __overflow || __next <= __result;
    __result = __next;
  }

  __val = __overflow
    ? numeric_limits<_Integer>::min()
    : (__negative ? -__result : __result);
  return make_pair(__first, __got > 0 && !__overflow);
}

inline int __STL_CALL
__get_digit_from_table(unsigned __index)
{
  return (__index > 127 ? 0xFF : __digit_val_table[__index]);
}

template <class _InputIter, class _CharT>
int 
_M_get_base_or_zero(_InputIter& __in, _InputIter& __end, 
                    ios_base& __str, locale& __loc, _CharT*)
{
  const ctype<_CharT>& __c_type = use_facet<ctype<_CharT> >(__loc);
  
  _CharT __atoms[5];

  __c_type.widen(__narrow_atoms, __narrow_atoms + 5, __atoms);

  bool __negative = false;
  _CharT __c = *__in;

  if (__c == __atoms[1] /* __minus_char */ ) {
    __negative = true;
    ++__in;
  }
  else if (__c == __atoms[0] /* __plus_char */ ) 
    ++__in;


  int __base;
  int __valid_zero = 0;
  
  ios_base::fmtflags __basefield = __str.flags() & ios_base::basefield; 

  switch (__basefield) {
  case ios_base::oct:
    __base = 8;
    break;
  case ios_base::dec:
    __base = 10;
    break;
  case ios_base::hex:
    __base = 16;
    if (__in != __end && *__in == __atoms[2] /* __zero_char */ ) {
      ++__in;
      if (__in != __end &&
          (*__in == __atoms[3] /* __x_char */ || *__in == __atoms[4] /* __X_char */ ))
        ++__in;
      else
        __valid_zero = 1; // That zero is valid by itself.
    }
    break;
  default:
    if (__in != __end && *__in == __atoms[2] /* __zero_char */ ) {
      ++__in;
      if (__in != __end &&
          (*__in == __atoms[3] /* __x_char */ || *__in == __atoms[4] /* __X_char */ )) {
        ++__in;
        __base = 16;
      }
      else
        {
          __base = 8;
          __valid_zero = 1; // That zero is still valid by itself.
        }
    }
    else
      __base = 10;
    break;
  }
  return (__base << 2) | ((int)__negative << 1) | __valid_zero;
}

// __get_integer for char

template <class _InputIter, class _Integer> // class _CharT
bool __STL_CALL
__get_integer_nogroup(_InputIter& __first, _InputIter& __last,
                      int __base, _Integer& __val, 
					  int __got, bool __is_negative	) 
{
  bool __overflow = false;
  _Integer __result = 0;

  if (__first == __last) {      // We may have already read a 0.  If so,
    if (__got > 0) {            // the result is 0 even if we're at eof.
      __val = 0;
      return true;
    }
    else
      return false;
  }
  
  if (numeric_limits<_Integer>::is_signed) {
      
    _Integer __min_over_base = numeric_limits<_Integer>::min() / __STATIC_CAST(_Integer, __base);

    for ( ; __first != __last ; ++__first) {

      int __n = __get_digit_from_table(*__first);

      if (__n >= __base)
        break;
      
      ++__got;

      if (__result < __min_over_base)
        __overflow = true;  // don't need to keep accumulating
      else {
        _Integer __next = __STATIC_CAST(_Integer, __base * __result - __n);
        if (__result != 0)
          __overflow = __overflow || __next >= __result;
        __result = __next;
      }
    }

    // fbp : added to not modify value if nothing was read
    if (__got > 0)
      __val = __overflow
        ? __is_negative ? numeric_limits<_Integer>::min()
        : numeric_limits<_Integer>::max()
        : (__is_negative ? __result : __STATIC_CAST(_Integer, -__result));
    
  }
  
  else {

    _Integer __max_over_base =  numeric_limits<_Integer>::max() / __STATIC_CAST(_Integer,__base);

    for ( ; __first != __last ; ++__first) {
   
      int __n = __get_digit_from_table(*__first);

      if (__n >= __base)
        break;
   
      ++__got;
      
      if (__result > __max_over_base)
        __overflow = true;  //don't need to keep accumulating
      else {
        _Integer __next = __STATIC_CAST(_Integer, __base * __result + __n);
        if (__result != 0)
          __overflow = __overflow || __next <= __result;
        __result = __next;
      }
    }
   
    // fbp : added to not modify value if nothing was read
    if (__got > 0)
      __val = __overflow
        ? numeric_limits<_Integer>::max()
        : (__is_negative ? __STATIC_CAST(_Integer, -__result) : __result);
    
  }

  // overflow is being treated as failure
  return ((__got > 0) && !__overflow);

}

template <class _InputIter, class _Integer>
bool __STL_CALL
__get_integer_group(_InputIter& __first, _InputIter& __last,
					int __base,
					_Integer& __val,
					char __separator, const string& __grouping,
					int __got = 0,
					bool __is_negative = false) 
{
  bool __overflow = false;
  _Integer __result = 0;
  string __group_sizes;
  char __current_group_size = 0;

  if (__first == __last) {      // We may have already read a 0.  If so,
    if (__got > 0) {            // the result is 0 even if we're at eof.
      __val = 0;
      return true;
    }
    else
      return false;
  }
  
  if (numeric_limits<_Integer>::is_signed) {

    _Integer __min_over_base =  numeric_limits<_Integer>::min() / __STATIC_CAST(_Integer, __base);

    for ( ; __first != __last ; ++__first) {

      const char __c = __STATIC_CAST(const char, *__first);

      if (__c == __separator) {
        __group_sizes.push_back(__current_group_size);
        __current_group_size = 0;
        continue;
      }

      int __n = __get_digit_from_table(__c);

      if (__n >= __base)
        break;
      ++__got;
      ++__current_group_size;

      if (__result < __min_over_base)
	__overflow = true;  // don't need to keep accumulating
      else {
        _Integer __next = __STATIC_CAST(_Integer, __base * __result - __n);
        if (__result != 0)
        __overflow = __overflow || __next >= __result;
      __result = __next;
      }
    }

  if (__group_sizes.size() != 0)
    __group_sizes.push_back(__current_group_size);
  
    // fbp : added to not modify value if nothing was read
    if (__got > 0)
      __val = __overflow
        ? __is_negative ? numeric_limits<_Integer>::min()
        : numeric_limits<_Integer>::max()
        : (__is_negative ? __result : __STATIC_CAST(_Integer, -__result));
  }
  
  else {

    _Integer __max_over_base =  numeric_limits<_Integer>::max() / __STATIC_CAST(_Integer, __base);

    for ( ; __first != __last ; ++__first) {
      const char __c = __STATIC_CAST(const char, *__first);
      if (__c == __separator) {
        __group_sizes.push_back(__current_group_size);
        __current_group_size = 0;
        continue;
      }

      int __n = __get_digit_from_table(__c);

      if (__n >= __base)
        break;

      ++__got;
      ++__current_group_size;

      if (__result > __max_over_base)
	__overflow = true;  //don't need to keep accumulating
      else {
        _Integer __next = __STATIC_CAST(_Integer, __base * __result + __n);
        if (__result != 0)
          __overflow = __overflow || __next <= __result;
        __result = __next;
      }
    }

    if (__group_sizes.size() != 0)
      __group_sizes.push_back(__current_group_size);

    // fbp : added to not modify value if nothing was read
    if (__got > 0)   
      __val = __overflow
        ? numeric_limits<_Integer>::max()
        : (__is_negative ? __STATIC_CAST(_Integer, -__result) : __result);
  }
  
  reverse(__group_sizes.begin(), __group_sizes.end());

  return ( __got > 0 )  && (!__overflow) &&
    __valid_grouping(__group_sizes, __grouping);
}


template <class _InputIter, class _Integer, class _CharT>
_InputIter  __STL_DECLSPEC __STL_CALL
_M_do_get_integer(_InputIter& __in, _InputIter& __end, ios_base& __str,
                  ios_base::iostate& __err, _Integer& __val, _CharT* __pc) 
{

  locale __loc = __str.getloc();
  typedef numpunct<_CharT> _Numpunct;

  const _Numpunct& __numpunct = use_facet<_Numpunct>(__loc) ;
  _CharT __separator  = __numpunct.thousands_sep();
  string __grouping = __numpunct.grouping();

  const int __base_or_zero = _M_get_base_or_zero(__in, __end, __str, __loc, __pc);
  const int  __got = __base_or_zero & 1;
  const bool __negative = __base_or_zero & 2;
  const int __base = __base_or_zero >> 2;

  bool __result =
    __grouping.empty() ?
    __get_integer_nogroup(__in, __end, __base,  __val, __got, __negative)
    :
    __get_integer_group(__in, __end, __base, __val,
			  __STATIC_CAST(char, __separator), __grouping, __got, __negative);
  
  __err = __STATIC_CAST(ios_base::iostate, __result ? ios_base::goodbit : ios_base::failbit);
  if (__in == __end)
    __err |= ios_base::eofbit;
  return __in;
}

// _M_do_get_float and its helper functions.
template <class _InputIter, class _CharT>
_InputIter  __STL_CALL
__copy_sign(_InputIter __first, _InputIter __last, string& __v,
            _CharT __plus, _CharT __minus) {
    if (__first != __last) {
    _CharT __c = *__first;
    if (__c == __plus)
      ++__first;
    else if (__c == __minus) {
      __v.push_back('-');
      ++__first;
    }
  }
  return __first;
}


template <class _InputIter, class _CharT>
pair<_InputIter, bool> __STL_CALL
__copy_digits(_InputIter __first, _InputIter __last,
              string& __v, const _CharT* __digits)
{
  bool __ok = false;

  for ( ; __first != __last; ++__first) {
    pair<char, bool> __tmp = __get_fdigit(*__first, __digits);
    if (__tmp.second) {
      __v.push_back(__tmp.first);
      __ok = true;
    }
    else
      break;
  }
  return make_pair(__first, __ok);
}

template <class _InputIter, class _CharT>
pair<_InputIter, bool> __STL_CALL
__copy_grouped_digits(_InputIter __first, _InputIter __last,
		      string& __v, const _CharT * __digits,
		      _CharT __sep, const string& __grouping,
		      bool& __grouping_ok)
{
  bool __ok = false;
  string __group_sizes;
  char __current_group_size = 0;

  for ( ; __first != __last; ++__first) {
    pair<char, bool> __tmp = __get_fdigit_or_sep(*__first, __sep,
					         __digits);
    if (__tmp.second) {
      if (__tmp.first == ',') {
	__group_sizes.push_back(__current_group_size);
	__current_group_size = 0;
      }
      else {
        __ok = true;
        __v.push_back(__tmp.first);
  	++__current_group_size;
      }
    }
    else
      break;
  }
  
  if (__group_sizes.size() != 0)
    __group_sizes.push_back(__current_group_size);
  
  reverse(__group_sizes.begin(), __group_sizes.end());
  __grouping_ok = __valid_grouping(__group_sizes, __grouping);
  return make_pair(__first, __ok);	
}


template <class _InputIter, class _Float, class _CharT>
_InputIter  __STL_DECLSPEC __STL_CALL
_M_do_get_float(_InputIter __in, _InputIter __end, ios_base& __s,
		ios_base::iostate& __err, _Float& __val, _CharT*)
{
	// dwa 1/24/00 - this variable never used
  //  ios_base::fmtflags __flags = __s.flags();

  // Create a string, copying characters of the form 
  // [+-]? [0-9]* .? [0-9]* ([eE] [+-]? [0-9]+)?

  bool __digits_before_dot /* = false */;
  bool __digits_after_dot = false;
  bool __ok;
  pair<_InputIter, bool> __tmp;
  string __buf;

  typedef numpunct<_CharT> _Numpunct;
  locale __loc = __s.getloc();

  const _Numpunct& __numpunct = use_facet<_Numpunct>(__loc) ;
  (void)__numpunct; // dwa 1/24/00 - suppress unreferenced variable warning

  _CharT __digits[10];
  _CharT __plus;
  _CharT __minus;
  _CharT __dot;
  _CharT __pow_e;
  _CharT __pow_E;
  _CharT __sep;
  string __grouping;
  bool   __grouping_ok = true;

  __initialize_get_float(__loc,
                         __plus, __minus, __dot, __pow_e, __pow_E,
			 __sep, __grouping, __digits);

  // Get an optional sign
  __in = __copy_sign(__in, __end, __buf, __plus, __minus);

  // Get an optional string of digits.
  if (__grouping.size() != 0)
    __tmp = __copy_grouped_digits(__in, __end, __buf, __digits,
				  __sep, __grouping, __grouping_ok);
  else
    __tmp = __copy_digits(__in, __end, __buf, __digits);
  __in = __tmp.first;
  __digits_before_dot = __tmp.second;
    
  // Get an optional decimal point, and an optional string of digits.
  if (__in != __end && *__in == __dot) {
    __buf.push_back('.');
    ++__in;

    __tmp = __copy_digits(__in, __end, __buf, __digits);
    __in = __tmp.first;
    __digits_after_dot = __tmp.second;
  }

  // There have to be some digits, somewhere.
  __ok = __digits_before_dot || __digits_after_dot;
  
  // Get an optional exponent.
  if (__ok && __in != __end && (*__in == __pow_e || *__in == __pow_E)) {
    __buf.push_back('e');
    ++__in;
    __in = __copy_sign(__in, __end, __buf, __plus, __minus);
    __tmp = __copy_digits(__in, __end, __buf, __digits);
    __in = __tmp.first;
    __ok = __tmp.second;        // If we have an exponent then the sign 
                                // is optional but the digits aren't.
  }

  __string_to_float(__buf, __val);
  
  __err = __STATIC_CAST(ios_base::iostate, __ok ? ios_base::goodbit : ios_base::failbit);
  if (__tmp.first == __end)
    __err |= ios_base::eofbit;
  return __tmp.first;
}

# ifndef __STL_NO_BOOL

template <class _CharT, class _InputIter>
_InputIter
num_get<_CharT, _InputIter>::do_get(_InputIter __in, _InputIter __end,
                                    ios_base& __s,
                                    ios_base::iostate& __err, bool& __x) const
{
  if (__s.flags() & ios_base::boolalpha) {
    locale __loc = __s.getloc();
    const numpunct<_CharT>& __np = use_facet<numpunct<_CharT> >(__loc) ;
//    const ctype<_CharT>& __ct =    use_facet<ctype<_CharT> >(__loc) ;

    const basic_string<_CharT> __truename  = __np.truename();
    const basic_string<_CharT> __falsename = __np.falsename();
    bool __true_ok  = true;
    bool __false_ok = true;

    size_t __n = 0;
    for ( ; __in != __end; ++__in) {
      char __c = *__in;
      __true_ok  = __true_ok  && (__c == __truename[__n]);
      __false_ok = __false_ok && (__c == __falsename[__n]);
      ++__n;

      if ((!__true_ok && !__false_ok) ||
          (__true_ok  && __n >= __truename.size()) ||
          (__false_ok && __n >= __falsename.size())) {
	++__in;
        break;
      }
    }
    if (__true_ok  && __n < __truename.size())  __true_ok  = false;
    if (__false_ok && __n < __falsename.size()) __false_ok = false;
    
    if (__true_ok || __false_ok) {
      __err = ios_base::goodbit;
      __x = __true_ok;
    }
    else
      __err = ios_base::failbit;

    if (__in == __end)
      __err |= ios_base::eofbit;

    return __in;
  }

  else {
    long __lx;
    _InputIter __tmp = this->do_get(__in, __end, __s, __err, __lx);
    if (!(__err & ios_base::failbit)) {
      if (__lx == 0)
        __x = false;
      else if (__lx == 1)
        __x = true;
      else
        __err |= ios_base::failbit;
    }
    return __tmp;
  }
}

# endif /* __STL_NO_BOOL */

//----------------------------------------------------------------------
// num_put facet

template <class _CharT, class _OutputIter>
_OutputIter  __STL_CALL
__copy_float_and_fill(const _CharT* __first, const _CharT* __last,
                      _OutputIter __out,
                      ios_base::fmtflags __flags,
                      int __width, _CharT __fill,
                      _CharT __plus, _CharT __minus) {
  if (__width <= __last - __first)
    return copy(__first, __last, __out);
  else {
    int __pad = __width - (__last - __first);
    ios_base::fmtflags __dir = __flags & ios_base::adjustfield;

    if (__dir == ios_base::left) {
      __out = copy(__first, __last, __out);
      return fill_n(__out, __pad, __fill);
    }
    else if (__dir == ios_base::internal && __first != __last &&
             (*__first == __plus || *__first == __minus)) {
      *__out++ = *__first++;
      __out = fill_n(__out, __pad, __fill);
      return copy(__first, __last, __out);
    }
    else {
      __out = fill_n(__out, __pad, __fill);
      return copy(__first, __last, __out);
    }
  }
}

#ifndef __STL_NO_WCHAR_T
// Helper routine for wchar_t
template <class _OutputIter>
_OutputIter  __STL_CALL
__put_float(char* __ibuf, char* __iend, _OutputIter __out,
            ios_base& __f, wchar_t __fill,
            const locale& __loc, wchar_t __decimal_point,
            wchar_t __sep, const string& __grouping)
{
  const ctype<wchar_t>& __ct = use_facet<ctype<wchar_t> >(__loc) ;

  wchar_t __wbuf[128];
  wchar_t* __eend = __convert_float_buffer(__ibuf, __iend, __wbuf,
                                           __ct, __decimal_point);
  if (__grouping.size() != 0) {
    // In order to do separator-insertion only to the left of the
    // decimal point, we adjust the size of the first (right-most)
    // group.  We need to be careful if there is only one entry in
    // grouping:  in this case we need to duplicate the first entry.

    string __new_grouping = __grouping;
    wchar_t* __decimal_pos = find(__wbuf, __eend, __decimal_point);
    if (__grouping.size() == 1)
      __new_grouping.push_back(__grouping[0]);

	// dwa 1/24/00 - try as I might, there doesn't seem to be a way
    // to suppress the warning
    __new_grouping[0] += __STATIC_CAST(char, __eend - __decimal_pos);
    ptrdiff_t __len = __insert_grouping(__wbuf, __eend, __new_grouping,
					__sep,
					__ct.widen('+'), __ct.widen('-'),
					0);
    __eend = __wbuf + __len;
  }

  return __copy_float_and_fill(__wbuf, __eend, __out,
                               __f.flags(), __f.width(0), __fill,
                               __ct.widen('+'), __ct.widen('-')); 
}
# endif /* WCHAR_T */

// Helper routine for char
template <class _OutputIter>
inline _OutputIter  __STL_CALL
__put_float(char* __ibuf, char* __iend, _OutputIter __out,
            ios_base& __f, char __fill,
            const locale&, char __decimal_point,
            char __sep, const string& __grouping)
{
  __adjust_float_buffer(__ibuf, __iend, __decimal_point);
  if (__grouping.size() != 0) {
    string __new_grouping = __grouping;
    const char * __decimal_pos = find(__ibuf, __iend, __decimal_point);
    if (__grouping.size() == 1)
      __new_grouping.push_back(__grouping[0]);
    __new_grouping[0] += __STATIC_CAST(char, __iend - __decimal_pos);
    ptrdiff_t __len = __insert_grouping(__ibuf, __iend, __new_grouping,
					__sep, 0);
    __iend = __ibuf + __len;
  }

  return __copy_float_and_fill(__ibuf, __iend, __out,
                               __f.flags(), __f.width(0), __fill, '+', '-');
}

template <class _CharT, class _OutputIter, class _Float>
_OutputIter __STL_DECLSPEC __STL_CALL
_M_do_put_float(_OutputIter __s, ios_base& __f,
                _CharT __fill, _Float __x)
{
  char   __buf[128];
  char* __iend = __write_float(__buf, __f.flags(), __f.precision(), __x);

  locale __loc = __f.getloc();
  const numpunct<_CharT>& __np = use_facet<numpunct<_CharT> >(__loc) ;
  return __put_float(__buf, __iend, __s, __f, __fill,
                     __loc, __np.decimal_point(),
		     __np.thousands_sep(), __np.grouping());
}

// _M_do_put_integer and its helper functions.

template <class _CharT, class _OutputIter>
_OutputIter __STL_CALL
__copy_integer_and_fill(const _CharT* __buf, ptrdiff_t __len,
                        _OutputIter __out,
                        ios_base::fmtflags __flg, int __wid, _CharT __fill,
                        _CharT __plus, _CharT __minus)
{
  if (__len >= __wid)
    return copy(__buf, __buf + __len, __out);
  else {
    ptrdiff_t __pad = __wid - __len;
    ios_base::fmtflags __dir = __flg & ios_base::adjustfield;

    if (__dir == ios_base::left) {
      __out = copy(__buf, __buf + __len, __out);
      return fill_n(__out, __pad, __fill);
    }
    else if (__dir == ios_base::internal && __len != 0 &&
             (__buf[0] == __plus || __buf[0] == __minus)) {
      *__out++ = __buf[0];
      __out = fill_n(__out, __pad, __fill);
      return copy(__buf + 1, __buf + __len, __out);
    }
    else if (__dir == ios_base::internal && __len >= 2 &&
             (__flg & ios_base::showbase) &&
             (__flg & ios_base::basefield) == ios_base::hex) {
      *__out++ = __buf[0];
      *__out++ = __buf[1];
      __out = fill_n(__out, __pad, __fill);
      return copy(__buf + 2, __buf + __len, __out);
    }
    else {
      __out = fill_n(__out, __pad, __fill);
      return copy(__buf, __buf + __len, __out);
    }
  }
}

#ifndef __STL_NO_WCHAR_T
// Helper function for wchar_t
template <class _OutputIter>
_OutputIter __STL_CALL
__put_integer(char* __buf, char* __iend, _OutputIter __s,
              const locale& __loc, const string& __grouping, wchar_t __sep,
              ios_base::fmtflags __flags, int __wid, wchar_t __fill)
{
  const ctype<wchar_t>& __ct = use_facet<ctype<wchar_t> >(__loc);
  wchar_t __plus  = __ct.widen('+');
  wchar_t __minus = __ct.widen('-');

  wchar_t __wbuf[64];
  __ct.widen(__buf, __iend, __wbuf);
  ptrdiff_t __len = __iend - __buf;
  wchar_t* __eend = __wbuf + __len;
  if (!__grouping.empty()) {
    int __basechars;
    if (__flags & ios_base::showbase)
      switch (__flags & ios_base::basefield) {
	case ios_base::hex: __basechars = 2; break;
	case ios_base::oct: __basechars = 1; break;
	default: __basechars = 0;
      }
    else
      __basechars = 0;

    __len = __insert_grouping(__wbuf, __eend, __grouping, __sep,
			      __plus, __minus, __basechars);
  }

  return __copy_integer_and_fill(__wbuf, __len, __s,
                                 __flags, __wid, __fill,
                                 __plus, __minus);
}
#endif

// Helper function for char
template <class _OutputIter>
_OutputIter __STL_CALL
__put_integer(char* __buf, char* __iend, _OutputIter __s,
              const locale&, const string& __grouping, char __sep,
              ios_base::fmtflags __flags, int __wid, char __fill)
{
  ptrdiff_t __len = __iend - __buf;

  if (!__grouping.empty()) {
    int __basechars;
    if (__flags & ios_base::showbase)
      switch (__flags & ios_base::basefield) {
	case ios_base::hex: __basechars = 2; break;
	case ios_base::oct: __basechars = 1; break;
	default: __basechars = 0;
      }
    else
      __basechars = 0;
    __len = __insert_grouping(__buf, __iend, __grouping, __sep, __basechars);
  }
  
  return __copy_integer_and_fill(__buf, __len, __s,
                                 __flags, __wid, __fill,
                                 '+', '-');
}

template <class _CharT, class _OutputIter, class _Integer>
_OutputIter __STL_DECLSPEC __STL_CALL
_M_do_put_integer(_OutputIter __s,
		  ios_base& __f, _CharT __fill, 
		  _Integer  __val)
{
  char __buf[64];               // Large enough for a base 8 64-bit integer,
                                // plus any necessary grouping.

  ios_base::fmtflags __flags = __f.flags();
  char* __iend = __write_integer(__buf, __flags, __val);  
  locale __loc = __f.getloc();
  const numpunct<_CharT>& __np = use_facet<numpunct<_CharT> >(__loc);
 
  return __put_integer(__buf, __iend, __s,
                       __loc, __np.grouping(), __np.thousands_sep(),
                       __flags, __f.width(0), __fill);
}

// _M_do_put_bool, used only for alpha output of bool.
# ifndef __STL_NO_BOOL
template <class _CharT, class _OutputIter>
_OutputIter
num_put<_CharT, _OutputIter>::_M_do_put_bool(_OutputIter __s, ios_base& __f, _CharT __fill,
                                             bool    __x) const 
{
  locale __loc = __f.getloc();
  typedef numpunct<_CharT> _Punct;
  const _Punct& __np = use_facet<_Punct>(__loc);
  basic_string<_CharT> __str = __x ? __np.truename() : __np.falsename();

  // Reuse __copy_integer_and_fill.  Since internal padding makes no
  // sense for bool, though, make sure we use something else instead.
  // The last two argument to __copy_integer_and_fill are dummies.
  ios_base::fmtflags __flags = __f.flags();
  if ((__flags & ios_base::adjustfield) == ios_base::internal)
    __flags = (__flags & ~ios_base::adjustfield) | ios_base::right;

  return __copy_integer_and_fill(__str.c_str(), __str.size(), __s,
                                 __flags, __f.width(0), __fill,
                                 (_CharT) 0, (_CharT) 0);
}
# endif

# endif /* __STL_NO_CUSTOM_IO */

__STL_END_NAMESPACE


#endif /* __STL_NUMERIC_FACETS_C */

// Local Variables:
// mode:C++
// End:
