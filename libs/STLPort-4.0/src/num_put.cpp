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

# include "num_put.h"

__STL_BEGIN_NAMESPACE

//----------------------------------------------------------------------
// num_put

// Helper functions for _M_do_put_integer

void __STL_CALL
__make_integer_conversion_spec(char * 	       cvtspec, 
				    ios_base::fmtflags flags,
				    bool 	       is_signed,
				    bool 	       is_long_long) 
{
  *cvtspec++ = '%';
  if (flags & ios_base::showpos)  *cvtspec++ = '+';
  if (flags & ios_base::showbase) *cvtspec++ = '#';

  *cvtspec++ = 'l';             // %l... for long, %ll... for unsigned long.
  if (is_long_long)             // We never construct a conversion specifier
    *cvtspec++ = 'l';           // for any type shorter than long.

  switch (flags & ios_base::basefield) {
    case ios_base::oct:
      *cvtspec++ = 'o'; break;
    case ios_base::hex:
      *cvtspec++ = flags & ios_base::uppercase ? 'X' : 'x'; break;
    default:
      *cvtspec++ = is_signed ? 'd' : 'u';
  }

  *cvtspec++ = 0;
}

char* __STL_CALL
__write_integer(char* buf, ios_base::fmtflags flags, long x)
{
  char cvtspec[64];
  __make_integer_conversion_spec(cvtspec, flags, true, false);
  sprintf(buf, cvtspec, x);
  return buf + strlen(buf);
}

char* __STL_CALL
__write_integer(char* buf, ios_base::fmtflags flags, unsigned long x)
{
  char cvtspec[64];
  __make_integer_conversion_spec(cvtspec, flags, false, false);
  sprintf(buf, cvtspec, x);
  return buf + strlen(buf);
}

#ifdef __STL_LONG_LONG

char* __STL_CALL
__write_integer(char* buf, ios_base::fmtflags flags, long long x)
{
  char cvtspec[64];
  __make_integer_conversion_spec(cvtspec, flags, true, true);
  sprintf(buf, cvtspec, x);
  return buf + strlen(buf);
}

char* __STL_CALL
__write_integer(char* buf, ios_base::fmtflags flags, unsigned long long x)
{
  char cvtspec[64];
  __make_integer_conversion_spec(cvtspec, flags, false, true);
  sprintf(buf, cvtspec, x);
  return buf + strlen(buf);
}

#endif /* __STL_LONG_LONG */


ptrdiff_t __STL_CALL
__insert_grouping(char* first, char* last, const string& grouping,
                  char separator, int basechars)
{
  return __insert_grouping_aux(first, last, grouping, separator,
		               '+', '-', basechars);
}

ptrdiff_t __STL_CALL
__insert_grouping(char * first, char * last, const string& grouping,
		  char separator, char Plus, char Minus, int basechars)
{
  return __insert_grouping_aux(first, last, grouping, 
			       separator, Plus, Minus, basechars);
}

# ifndef __STL_NO_WCHAR_T

ptrdiff_t __STL_CALL
__insert_grouping(wchar_t* first, wchar_t* last, const string& grouping,
                  wchar_t separator, wchar_t Plus, wchar_t Minus,
		  int basechars)
{
  return __insert_grouping_aux(first, last, grouping, separator, 
			       Plus, Minus, basechars);
}

# endif

__STL_END_NAMESPACE

// Local Variables:
// mode:C++
// End:
