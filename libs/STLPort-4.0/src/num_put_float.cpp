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

# ifdef __DECCXX
#define NDIG 400
# else
#define NDIG 82
# endif

# ifdef __STL_NO_LONG_DOUBLE
#  define MAXECVT 17
#  define MAXFCVT 18
typedef double max_double_type;
# else
#  define MAXECVT 35
#  define MAXFCVT 36
typedef long double max_double_type;
# endif

#define MAXFSIG MAXECVT
#define MAXESIZ 5

#define todigit(x) ((x)+'0')

# include <stl/_config.h>

# ifdef __STL_UNIX

# include <values.h>

# if defined (__sun) 
#  include <floatingpoint.h>
# endif

# if !defined(__STL_USE_GLIBC) && !defined(__FreeBSD__)   // dwa 1/10/00 - nan.h not supplied with gcc
// DEC & Solaris need this
#  include <nan.h>
# endif

# endif

# include <stdlib.h>

#if defined (_MSC_VER) || defined (__MINGW32__) || defined (__BORLANDC__)
# include <float.h>
#endif

#if defined(__MRC__) || defined(__SC__)		//*TY 02/24/2000 - added support for MPW
# include <fp.h>
#endif

#include <cmath>

#if defined( __MSL__ )
# include <cstdlib>	// for atoi
# include <cstdio>	// for snprintf
# include <algorithm>
# include <cassert>
#endif

# include <ios>
# include <algorithm>

__STL_BEGIN_NAMESPACE


// Tests for infinity and NaN differ on different OSs.  We encapsulate
// these differences here.

#if defined(__STL_USE_GLIBC) || defined (__hpux) || defined(__MSL__)
# if defined(__MSL__)
	// dwa 1/16/00 -- untested!
  inline bool _Stl_is_nan_or_inf(double x) { int fp_class = fpclassify(x); return x == FP_NAN || x == FP_INFINITE;  }
  inline bool _Stl_is_neg_nan(double x)    { return isnan(x) && ( __STL_VENDOR_STD::copysign(1., x) < 0 ); }
# else
  inline bool _Stl_is_nan_or_inf(double x) { return !finite(x); }
  inline bool _Stl_is_neg_nan(double x)    { return isnan(x) && ( copysign(1., x) < 0 ); }
# endif
  inline bool _Stl_is_inf(double x)        { return isinf(x); }
  inline bool _Stl_is_neg_inf(double x)    { return isinf(x) < 0; }
#elif defined(__unix) && !defined(__FreeBSD__) /* (__sgi) || defined (__sun) IRIX , Solaris, others ? */
  inline bool _Stl_is_nan_or_inf(double x) { return IsNANorINF(x); }
  inline bool _Stl_is_inf(double x)        { return IsNANorINF(x) && IsINF(x); }
  inline bool _Stl_is_neg_inf(double x)    { return (IsINF(x)) && (x < 0.0); }
  inline bool _Stl_is_neg_nan(double x)    { return IsNegNAN(x); }
# elif defined (__BORLANDC__) && __BORLANDC__ < 0x540
  inline bool _Stl_is_nan_or_inf(double x) { return !_finite(x); }
  inline bool _Stl_is_inf(double x)        {
    return _Stl_is_nan_or_inf(x) && ! _isnan(x);
  }
  inline bool _Stl_is_neg_inf(double x)    { 
    return _Stl_is_inf(x) && x < 0 ; 
  }
  inline bool _Stl_is_neg_nan(double x)    { return _isnan(x) && x < 0 ; } 
#elif defined (_MSC_VER) || defined (__MINGW32__) || defined (__BORLANDC__)
  inline bool _Stl_is_nan_or_inf(double x) { return !_finite(x); }
  inline bool _Stl_is_inf(double x)        {
    int fclass = _fpclass(x); 
    return fclass == _FPCLASS_NINF || fclass == _FPCLASS_PINF; 
  }
  inline bool _Stl_is_neg_inf(double x)    { 
    return _fpclass(x) == _FPCLASS_NINF; 
  }
  inline bool _Stl_is_neg_nan(double x)    { return _isnan(x) && _copysign(1., x) < 0 ; } 
#elif defined(__MRC__) || defined(__SC__)		//*TY 02/24/2000 - added support for MPW
  bool _Stl_is_nan_or_inf(double x) { return isnan(x) || !isfinite(x); }
  bool _Stl_is_inf(double x)        { return !isfinite(x); }
  bool _Stl_is_neg_inf(double x)    { return !isfinite(x) && signbit(x); }
  bool _Stl_is_neg_nan(double x)    { return isnan(x) && signbit(x); }
#elif defined (__FreeBSD__)
 inline bool _Stl_is_nan_or_inf(double x) { return !finite(x); }
 inline bool _Stl_is_inf(double x)        {
   return _Stl_is_nan_or_inf(x) && ! isnan(x);
  }
  inline bool _Stl_is_neg_inf(double x)    { 
   return _Stl_is_inf(x) && x < 0 ; 
  }
  inline bool _Stl_is_neg_nan(double x)    { return isnan(x) && copysign(1., x) < 0 ; } 
#endif

// Reentrant versions of floating-point conversion functions.  The argument
// lists look slightly different on different operating systems, so we're
// encapsulating the differences here.

#if defined (__CYGWIN__)
  inline char* _Stl_ecvtR(double x, int n, int* pt, int* sign, char* buf)
    { return ecvtbuf(x, n, pt, sign, buf); }
  inline char* _Stl_fcvtR(double x, int n, int* pt, int* sign, char* buf)
    { return fcvtbuf(x, n, pt, sign, buf); }
  inline char* _Stl_qecvtR(long double x, int n, int* pt, int* sign, char* buf)
    { return ecvtbuf(x, n, pt, sign, buf); }
  inline char* _Stl_qfcvtR(long double x, int n, int* pt, int* sign, char* buf)
    { return fcvtbuf(x, n, pt, sign, buf); }
#elif defined (__STL_USE_GLIBC)
  inline char* _Stl_ecvtR(double x, int n, int* pt, int* sign, char* buf)
    { return buf + ecvt_r(x, n, pt, sign, buf, NDIG+2); }
  inline char* _Stl_fcvtR(double x, int n, int* pt, int* sign, char* buf)
    { return buf + fcvt_r(x, n, pt, sign, buf, NDIG+2); }
  inline char* _Stl_qecvtR(long double x, int n, int* pt, int* sign, char* buf)
    { return buf + qecvt_r(x, n, pt, sign, buf, NDIG+2); }
  inline char* _Stl_qfcvtR(long double x, int n, int* pt, int* sign, char* buf)
    { return buf + qfcvt_r(x, n, pt, sign, buf, NDIG+2); }
#elif defined (__sun)
  inline char* _Stl_ecvtR(double x, int n, int* pt, int* sign, char* buf)
    { return econvert(x, n, pt, sign, buf); }
  inline char* _Stl_fcvtR(double x, int n, int* pt, int* sign, char* buf)
    { return fconvert(x, n, pt, sign, buf); }
  inline char* _Stl_qecvtR(long double x, int n, int* pt, int* sign, char* buf)
    { return qeconvert(&x, n, pt, sign, buf); }
  inline char* _Stl_qfcvtR(long double x, int n, int* pt, int* sign, char* buf)
    { return qfconvert(&x, n, pt, sign, buf); }
#elif defined (__DECCXX) 
  inline char* _Stl_ecvtR(double x, int n, int* pt, int* sign, char* buf)
    { return (ecvt_r(x, n, pt, sign, buf, NDIG)==0 ? buf : 0); }
  inline char* _Stl_fcvtR(double x, int n, int* pt, int* sign, char* buf)
    { return (fcvt_r(x, n, pt, sign, buf, NDIG)==0 ? buf : 0); }
// fbp : no "long double" conversions !
  inline char* _Stl_qecvtR(long double x, int n, int* pt, int* sign, char* buf)
    { return (ecvt_r((double)x, n, pt, sign, buf, NDIG)==0 ? buf : 0) ; }
  inline char* _Stl_qfcvtR(long double x, int n, int* pt, int* sign, char* buf)
    { return (fcvt_r((double)x, n, pt, sign, buf, NDIG)==0 ? buf : 0); }
#elif defined (__hpux)
   inline char* _Stl_ecvtR(double x, int n, int* pt, int* sign, char* buf)
     { return ecvt(x, n, pt, sign); }
   inline char* _Stl_fcvtR(double x, int n, int* pt, int* sign, char* buf)
     { return fcvt(x, n, pt, sign); }
#  ifdef _REENTRANT
   inline char* _Stl_qecvtR(long double x, int n, int* pt, int* sign, char* buf)
     { return (_ldecvt_r(*(long_double*)&x, n, pt, sign, buf, NDIG+2)==0 ? buf : 0); }
   inline char* _Stl_qfcvtR(long double x, int n, int* pt, int* sign, char* buf)
     { return (_ldfcvt_r(*(long_double*)&x, n, pt, sign, buf, NDIG+2)==0 ? buf : 0); }
#  else
   inline char* _Stl_qecvtR(long double x, int n, int* pt, int* sign, char* buf)
     { return _ldecvt(*(long_double*)&x, n, pt, sign); }
   inline char* _Stl_qfcvtR(long double x, int n, int* pt, int* sign, char* buf)
     { return _ldfcvt(*(long_double*)&x, n, pt, sign); }
#  endif

#elif defined (__unix)  && !defined(__FreeBSD__)/* defined(__sgi) IRIX */
  inline char* _Stl_ecvtR(double x, int n, int* pt, int* sign, char* buf)
    { return ecvt_r(x, n, pt, sign, buf); }
  inline char* _Stl_fcvtR(double x, int n, int* pt, int* sign, char* buf)
    { return fcvt_r(x, n, pt, sign, buf); }
  inline char* _Stl_qecvtR(long double x, int n, int* pt, int* sign, char* buf)
    { return qecvt_r(x, n, pt, sign, buf); }
  inline char* _Stl_qfcvtR(long double x, int n, int* pt, int* sign, char* buf)
    { return qfcvt_r(x, n, pt, sign, buf); }

#elif defined (__FreeBSD__)

/*
 * Copyright (c) 1995-1997 The Apache Group.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the Apache Group
 *    for use in the Apache HTTP server project (http://www.apache.org/)."
 *
 * 4. The names "Apache Server" and "Apache Group" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission.
 *
 * 5. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the Apache Group
 *    for use in the Apache HTTP server project (http://www.apache.org/)."
 */

static char *
     ap_cvt(double arg, int ndigits, int *decpt, int *sign, int eflag, char *str)
{
    register int r2;
    double fi, fj;
    register char *p, *p1;
    static char buf[NDIG];

    if (ndigits >= NDIG - 1)
        ndigits = NDIG - 2;
    r2 = 0;
    *sign = 0;
    p = &buf[0];
    if (arg < 0) {
        *sign = 1;
        arg = -arg;
    }
    arg = modf(arg, &fi);
    p1 = &buf[NDIG];
    /*
     * Do integer part
     */
    if (fi != 0) {
        p1 = &buf[NDIG];
        while (fi != 0) {
            fj = modf(fi / 10, &fi);
            *--p1 = (int) ((fj + .03) * 10) + '0';
            r2++;
        }
        while (p1 < &buf[NDIG])
            *p++ = *p1++;
    }
    else if (arg > 0) {
        while ((fj = arg * 10) < 1) {
            arg = fj;
            r2--;
        }
    }
    p1 = &buf[ndigits];
    if (eflag == 0)
        p1 += r2;
    *decpt = r2;
    if (p1 < &buf[0]) {
        buf[0] = '\0';
        str = buf;
        return (buf);
    }
    while (p <= p1 && p < &buf[NDIG]) {
        arg *= 10;
        arg = modf(arg, &fj);
        *p++ = (int) fj + '0';
    }
    if (p1 >= &buf[NDIG]) {
        buf[NDIG - 1] = '\0';
        str = buf;
        return (buf);
    }
    p = p1;
    *p1 += 5;
    while (*p1 > '9') {
        *p1 = '0';
        if (p1 > buf)
            ++ * --p1;
        else {
            *p1 = '1';
            (*decpt)++;
            if (eflag == 0) {
                if (p > buf)
                    *p = '0';
                p++;
            }
        }
    }
    *p = '\0';
    str = buf;
    return (buf);
}

static char *
     ap_ecvt(double arg, int ndigits, int *decpt, int *sign, char *buf)
{
    return ap_cvt(arg, ndigits, decpt, sign, 1, buf);
}

static char *
     ap_fcvt(double arg, int ndigits, int *decpt, int *sign, char *buf)
{
    return ap_cvt(arg, ndigits, decpt, sign, 0, buf);
}
/*** End of Apache code ***/
inline char* _Stl_ecvtR(double x, int n, int* pt, int* sign, char* buf)
  { return ap_ecvt(x, n, pt, sign, buf); }
inline char* _Stl_fcvtR(double x, int n, int* pt, int* sign, char* buf)
  { return ap_fcvt(x, n, pt, sign, buf); }
inline char* _Stl_qecvtR(long double x, int n, int* pt, int* sign, char* buf)
  { return ap_ecvt(x, n, pt, sign, buf); }
inline char* _Stl_qfcvtR(long double x, int n, int* pt, int* sign, char* buf)
  { return ap_fcvt(x, n, pt, sign, buf); }

#elif defined (__MSL__)

	// dwa 1/16/00 -- untested!
	// dwa 1/16/00: I would be not be shocked if this wasn't reentrant
	namespace {
		// extra bytes for sign, leading zero, decimal point, exponent,
		// null termination
		const int scientific_buffer_extra = 30;
		
		char* cvt_nan_inf_aux(int fp_class, const int n, int* const pt, char* const result)
		{
			if (fp_class == FP_NAN)
				strcpy(result, "Nan");
			else if (fp_class == FP_INFINITE)
				strcpy(result, n < 8 ? "Inf" : "Infinity");
			else
				return 0;
				
			return result;
		}
		
		// Returns 0 if the number is not a NAN or INF. Otherwise suitable return value for
		// ecvt.
		template <class T>
		char* cvt_nan_inf(const T x, const int n, int* const pt, int* const sign, char* const buf)
		{
			char* const result = cvt_nan_inf_aux(fpclassify(x), n, pt, buf);
			if (result != 0)
			{
				// documentation gives no indication of what this should really be.
				*pt = 0;
				*sign = x < 0.0;
			}
			return result;
		}
		
		template <class T> const char* ecvt_fmt_string();
		template <> inline const char* ecvt_fmt_string<double>() { return "%0.*E"; }
		template <> inline const char* ecvt_fmt_string<long double>() { return "%0.*LE"; }

		template <class T> const char* fcvt_fmt_string();
		template <> inline const char* fcvt_fmt_string<double>() { return "%0.*f"; }
		template <> inline const char* fcvt_fmt_string<long double>() { return "%0.*Lf"; }

	#if defined( NDEBUG )
		const size_t stack_buffer_size = 400;	// set large for efficiency
	#else
		const size_t stack_buffer_size = 4;		// set small for testing purposes
	#endif

		
	  template <class T>
	  char* ecvtR(const T x, const int n, int* const pt, int* const sign, char* const result)
	  {
	  	char* const nan_inf_result = cvt_nan_inf(x, n, pt, sign, result);
	  	if (nan_inf_result != 0)
	  		return nan_inf_result;
	  		
		int buffer_size = n + scientific_buffer_extra;
		
		char stack_buffer[stack_buffer_size];
	  	char* const buffer = buffer_size > stack_buffer_size
	  		? new char[buffer_size] : stack_buffer;	// no alloca provided for mac

		// One significant digit will come before the decimal point, so we only
		// want n-1 digits afterwards. (snprintf not supported by CW!)
	  	sprintf(buffer, ecvt_fmt_string<T>(), n - 1, x);
	  	char* const begin = buffer;
	  	char* const end = find(begin, begin + buffer_size, '\0');
	  	
	  	// Handle the sign
	  	const bool neg = *buffer == '-';
	  	char* const mantissa = neg ? begin + 1 : begin;
	  	*sign = neg;
	  	
	  	char* const end_mantissa = find(mantissa, end, 'E');
	  	
	  	*result = *mantissa; // copy the first digit of the mantissa
	  	
	  	// copy the rest (skipping over the decimal point)
	  	char* const end_result = copy(mantissa + 2, end_mantissa, result + 1);
	  	
	  	// if this ever goes off, I guess we need to zero-fill
	  	assert(end_result == result + n);
	  	
	  	// null-terminate
	  	*end_result = '\0';

	  	// The exponent is just after the 'E'
	  	char* const exponent = end_mantissa + 1;
	  	
	  	// There was one digit before the decimal, so we must adjust
	  	*pt = atoi(exponent) + 1;
	  	
	  	if (buffer_size > stack_buffer_size)
	  		delete[] buffer;
	  		
	  	return result;
	  }

	  template <class T>
	  char* fcvtR(const T x, const int n, int* const pt, int* const sign, char* const result)
	  {
	  	char* const nan_inf_result = cvt_nan_inf(x, n, pt, sign, result);
	  	if (nan_inf_result != 0)
	  		return nan_inf_result;
	  		
	  	// 310 is a constant gleaned from the Sun documentation. It might need to be changed.
		int buffer_size = 310 + max(n, 0) + scientific_buffer_extra;
		
		char stack_buffer[stack_buffer_size];
	  	char* const buffer = buffer_size > stack_buffer_size
	  		? new char[buffer_size] : stack_buffer;	// no alloca provided for mac

		// One significant digit will come before the decimal point, so we only
		// want n-1 digits afterwards. (snprintf not supported by CW!)
	  	sprintf(buffer, fcvt_fmt_string<T>(), n - 1, x);
	  	char* const begin = buffer;
	  	char* const end = find(begin, begin + buffer_size, '\0');
	  	
	  	// Handle the sign
	  	const bool neg = *buffer == '-';
	  	char* const first_digit_pos = neg ? begin + 1 : begin;
	  	*sign = neg;
	  	
	  	char* const pt_pos = find(first_digit_pos, end, '.');
	  	*pt = pt_pos - first_digit_pos;
	  	char* const frac_pos = pt_pos == end ? pt_pos : pt_pos + 1;
	  	
	  	// add everything from after the decimal point through the null terminator
	  	copy(frac_pos, end + 1, 
	  		// to the sequence from the first digit to the decimal point
	  		copy(first_digit_pos, pt_pos, result) );
	  			  	
	  	if (buffer_size > stack_buffer_size)
	  		delete[] buffer;
	  		
	  	return result;
	  }

	}

  inline char* _Stl_ecvtR(double x, int n, int* pt, int* sign, char* result)
  {
  	return ecvtR(x, n, pt, sign, result);
  }
    
  char* _Stl_fcvtR(double x, int n, int* pt, int* sign, char* result)
  {
  	return fcvtR(x, n, pt, sign, result);
  }
    
  inline char* _Stl_qecvtR(long double x, int n, int* pt, int* sign, char* result)
  {
  	return ecvtR(x, n, pt, sign, result);
  }
  
  inline char* _Stl_qfcvtR(long double x, int n, int* pt, int* sign, char* result)
  {
  	return fcvtR(x, n, pt, sign, result);
  }
  
#elif defined (_MSC_VER) || defined (__MINGW32__) || defined (__BORLANDC__)
  inline char* _Stl_ecvtR(double x, int n, int* pt, int* sign, char* buf)
    {
    strcpy(buf, _ecvt(x, n, pt, sign));
    return buf; 
    }
  inline char* _Stl_fcvtR(double x, int n, int* pt, int* sign, char* buf)
    {
    strcpy(buf, _fcvt(x, n, pt, sign));
    return buf; 
    }
  inline char* _Stl_qecvtR(long double x, int n, int* pt, int* sign, char* buf)
    {
    strcpy(buf, _ecvt((double)x, n, pt, sign));
    return buf; 
    }
  inline char* _Stl_qfcvtR(long double x, int n, int* pt, int* sign, char* buf)
    {
    strcpy(buf, _fcvt((double)x, n, pt, sign));
    return buf; 
    }
#elif defined (__MRC__) || defined(__SC__)		//*TY 02/24/2000 - added support for MPW
  inline char* _Stl_ecvtR(double x, int n, int* pt, int* sign, char* )
    { return ecvt( x, n, pt, sign ); }
	
  inline char* _Stl_fcvtR(double x, int n, int* pt, int* sign, char* )
    { return fcvt(x, n, pt, sign); }

  inline char* _Stl_qecvtR(long double x, int n, int* pt, int* sign, char* )
    { return ecvt( x, n, pt, sign ); }

  inline char* _Stl_qfcvtR(long double x, int n, int* pt, int* sign, char* )
    { return fcvt(x, n, pt, sign); }
#endif


//----------------------------------------------------------------------
// num_put

// Helper functions for _M_do_put_float

// __format_float formats a mantissa and exponent as returned by
// one of the conversion functions (ecvt_r, fcvt_r, qecvt_r, qfcvt_r)
// according to the specified precision and format flags.  This is
// based on doprnt but is much simpler since it is concerned only
// with floating point input and does not consider all formats.  It
// also does not deal with blank padding, which is handled by
// __copy_float_and_fill. 

void __format_float_scientific(char * buf, const char * bp, 
	   		      int decpt, int sign, max_double_type x,
		  	      ios_base::fmtflags flags,
		  	      int precision, bool /* islong */)
{
  char * suffix;
  char expbuf[MAXESIZ + 2];
  // sign if required
  if (sign)
    *buf++ = '-';
  else if (flags & ios_base::showpos)
    *buf++ = '+';
  
  // first digit of mantissa
  *buf++ = *bp++;

  // decimal point if required
  if (precision != 0 || flags & ios_base::showpoint)
    *buf++ = '.';
  // rest of mantissa
  int rz = precision;
  while (rz-- > 0 && *bp != 0)
    *buf++ = *bp++;

  // exponent
  *(suffix = &expbuf[MAXESIZ]) = 0;
  if (x != 0) {
    int nn = decpt - 1;
    if (nn < 0)
      nn = -nn;
    for (; nn > 9; nn /= 10)
      *--suffix = (char) todigit(nn % 10);
    *--suffix = (char) todigit(nn);
  }
  	
  // prepend leading zeros to exponent
  while (suffix > &expbuf[MAXESIZ - 2])
    *--suffix = '0';
  
  // put in the exponent sign
  *--suffix = (char) ((decpt > 0 || x == 0) ? '+' : '-');
  
  // put in the e
  *--suffix = flags & ios_base::uppercase ? 'E' : 'e';

  // copy the suffix
  strcpy(buf, suffix);
}
  
void __format_float_fixed(char * buf, const char * bp, 
	   		  int decpt, int sign, max_double_type /* x */,
		  	  ios_base::fmtflags flags,
		  	  int precision, bool islong )
{
  if (sign && decpt > -precision && *bp != 0)
    *buf++ = '-';
  else if (flags & ios_base::showpos)
    *buf++ = '+';
  
  int rzero   = 0;
  int nn      = decpt;
  int k       = 0;
  int maxfsig = islong ? 2*MAXFSIG : MAXFSIG;

  do {
    *buf++ = (char) ((nn <= 0 || *bp == 0 || k >= maxfsig) ?
      '0' : (k++, *bp++));
  } while (--nn > 0);

  // decimal point if needed
  if (flags & ios_base::showpoint || precision > 0)
    *buf++ = '.';

  // digits after decimal point if any
  nn = min(precision, MAXFCVT);
  if (precision > nn)
    rzero = precision - nn;
  while (--nn >= 0)
    *buf++ = (++decpt <= 0 || *bp == '\0' || k >= maxfsig)
      		? '0' : (k++, *bp++);

  // trailing zeros if needed
  while (rzero-- > 0)
    *buf++ = '0';
  *buf++ = '\0';
}

void __format_float(char * buf, const char * bp, 
                    int decpt, int sign, max_double_type x,
                    ios_base::fmtflags flags,
                    int precision, bool islong)
{
  const char* inf[2] = { "inf", "INF" };
  const char* nan[2] = { "nan", "NAN" };

  // Output of infinities and NANs does not depend on the format flags
  if (_Stl_is_nan_or_inf((double)x)) {       // Infinity or NaN
    const char** inf_or_nan = 0;
    if (_Stl_is_inf((double)x)) {            // Infinity
      inf_or_nan = inf;
      if (_Stl_is_neg_inf((double)x))
        *buf++ = '-';
      else if (flags & ios_base::showpos)
        *buf++ = '+';
    }
    else {                      // NaN
      inf_or_nan = nan;
      if (_Stl_is_neg_nan((double)x))
        *buf++ = '-';
      else if (flags & ios_base::showpos)
        *buf++ = '+';
    }
    strcpy(buf, flags & ios_base::uppercase ? inf_or_nan[1] : inf_or_nan[0]);
  }
  else {                        // representable number
    switch (flags & ios_base::floatfield) {
      case ios_base::scientific:
        __format_float_scientific(buf, bp, decpt, sign, x, flags,
                                  precision, islong);
        break;
  
      case ios_base::fixed:
        __format_float_fixed(buf, bp, decpt, sign, x, flags,
                             precision, islong);
        break;
  
      default: // g format
        // establish default precision
        if (flags & ios_base::showpoint || precision > 0) {
          if (precision == 0) precision = 1;
        }
        else
          precision = 6;

        // reset exponent if value is zero
        if (x == 0)
          decpt = 1;

        int kk = precision;
        if (!(flags & ios_base::showpoint)) {
          int n = strlen(bp);
          if (n < kk)
          kk = n;
          while (kk >= 1 && bp[kk-1] == '0')
            --kk;
        }

        if (decpt < -3 || decpt > precision) {
          precision = kk - 1;
          __format_float_scientific(buf, bp, decpt, sign, x,
                                    flags, precision, islong);
        }
        else {
          precision = kk - decpt;
          __format_float_fixed(buf, bp, decpt, sign, x,
                               flags, precision, islong);
        }
      break;
    } /* switch */
  } /* else */
}

char*  __STL_CALL
__write_float(char* buf, ios_base::fmtflags flags, int precision,
              double x)
{
  char cvtbuf[NDIG+2];
  char * bp;
  int decpt, sign;

  if (flags & ios_base::fixed)
    bp = _Stl_fcvtR(x, min(precision, MAXFCVT), &decpt, &sign, cvtbuf);
  else
    bp = _Stl_ecvtR(x, min(precision + 1, MAXECVT),     &decpt, &sign, cvtbuf);

  __format_float(buf, bp, decpt, sign, x, flags, precision, false);

  return buf + strlen(buf);
}

char*  __STL_CALL
__write_float(char* buf, ios_base::fmtflags flags, int precision,
              long double x)
{
  char cvtbuf[NDIG+2];
  char * bp;
  int decpt, sign;

  if (flags & ios_base::scientific)
    bp = _Stl_qecvtR(x, min(precision + 1, MAXECVT), &decpt, &sign, cvtbuf);
  else
    bp = _Stl_qfcvtR(x, min(precision, MAXFCVT),     &decpt, &sign, cvtbuf);

  __format_float(buf, bp, decpt, sign, x, flags, precision, true);

  return buf + strlen(buf);
}

# ifndef __STL_NO_WCHAR_T

wchar_t* __STL_CALL
__convert_float_buffer(const char* first, const char* last, wchar_t* out,
                       const ctype<wchar_t>& ct, wchar_t dot)
{
  ct.widen(first, last, out);
  replace(out, out + (last - first), ct.widen('.'), dot);
  return out + (last - first);
}

# endif

void __STL_CALL
__adjust_float_buffer(char* first, char* last, char dot)
{
  replace(first, last, '.', dot);
}

__STL_END_NAMESPACE

// Local Variables:
// mode:C++
// End:
