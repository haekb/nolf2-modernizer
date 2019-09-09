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
// WARNING: This is an internal header file, included by other C++
// standard library headers.  You should not attempt to use this header
// file directly.


#ifndef __SGI_STL_INTERNAL_NUMERIC_FACETS_H
#define __SGI_STL_INTERNAL_NUMERIC_FACETS_H

# include <stl/_iosfwd.h>
# include <stl/_locale.h>
# include <stl/_string.h>

__STL_BEGIN_NAMESPACE

//----------------------------------------------------------------------
// numpunct facets

template <class _CharT> class numpunct {};
template <class _CharT> class numpunct_byname {};
template <class _Ch, class _InIt> class num_get;

extern const unsigned char __digit_val_table[];
extern const char __narrow_atoms[];

__STL_TEMPLATE_NULL
class __STL_CLASS_DECLSPEC numpunct<char> : public locale::facet
{
  friend class _Locale_impl;
# ifndef __STL_NO_FRIEND_TEMPLATES
  template <class _Ch, class _InIt> friend class num_get;
# endif
#if defined(__MRC__) || defined(__SC__)	//*TY 04/29/2000 - added workaround for mpw
  typedef locale::facet _facet;			//*TY 04/29/2000 - they forget to look into nested class for the ctor.
#endif									//*TY 04/29/2000 - 
public:
  typedef char               char_type;
  typedef string             string_type;

  explicit numpunct(size_t __refs = 0);

  char decimal_point() const { return do_decimal_point(); }
  char thousands_sep() const { return do_thousands_sep(); }
  string grouping() const { return do_grouping(); }
  string truename() const { return do_truename(); }
  string falsename() const { return do_falsename(); }

  __STL_STATIC_MEMBER_DECLSPEC static locale::id id;

# ifndef __STL_NO_FRIEND_TEMPLATES
protected:
# endif
  ~numpunct();

  string  _M_truename;
  string  _M_falsename;

  virtual char do_decimal_point() const;
  virtual char do_thousands_sep() const;
  virtual string do_grouping() const;
  virtual string do_truename() const;
  virtual string do_falsename()  const;
};

# if ! defined (__STL_NO_WCHAR_T)

__STL_TEMPLATE_NULL
class __STL_CLASS_DECLSPEC numpunct<wchar_t> : public locale::facet
{
  friend class _Locale_impl;
#if defined(__MRC__) || defined(__SC__)	//*TY 04/29/2000 - added workaround for mpw
  typedef locale::facet _facet;			//*TY 04/29/2000 - they forget to look into nested class for the ctor.
#endif									//*TY 04/29/2000 - 
public:
  typedef wchar_t               char_type;
  typedef wstring               string_type;

  explicit numpunct(size_t __refs = 0);

  wchar_t decimal_point() const { return do_decimal_point(); }
  wchar_t thousands_sep() const { return do_thousands_sep(); }
  string grouping() const { return do_grouping(); }
  wstring truename() const { return do_truename(); }
  wstring falsename() const { return do_falsename(); }

  __STL_STATIC_MEMBER_DECLSPEC static locale::id id;

protected:
  wstring _M_truename;
  wstring _M_falsename;

  ~numpunct();

  virtual wchar_t do_decimal_point() const;
  virtual wchar_t do_thousands_sep() const;
  virtual string do_grouping() const;
  virtual wstring do_truename() const;
  virtual wstring do_falsename()  const;
};

# endif /* WCHAR_T */

__STL_TEMPLATE_NULL
class __STL_CLASS_DECLSPEC numpunct_byname<char> : public numpunct<char> {
public:
  typedef char                char_type;
  typedef string              string_type;

  explicit numpunct_byname(const char* __name, size_t __refs = 0);

protected:

  ~numpunct_byname();

  virtual char   do_decimal_point() const;
  virtual char   do_thousands_sep() const;
  virtual string do_grouping()      const;

private:
  _Locale_numeric* _M_numeric;
};

# ifndef __STL_NO_WCHAR_T
__STL_TEMPLATE_NULL
class __STL_CLASS_DECLSPEC numpunct_byname<wchar_t>: public numpunct<wchar_t> {
public:
  typedef wchar_t               char_type;
  typedef wstring               string_type;

  explicit numpunct_byname(const char* __name, size_t __refs = 0);

protected:

  ~numpunct_byname();

  virtual wchar_t   do_decimal_point() const;
  virtual wchar_t   do_thousands_sep() const;
  virtual string do_grouping() const;

private:
  _Locale_numeric* _M_numeric;
};

# endif /* WCHAR_T */


//----------------------------------------------------------------------
// num_get facets


# ifdef __STL_LIMITED_DEFAULT_TEMPLATES
template <class _CharT, class _InputIter>  
# else
template <class _CharT, class _InputIter = istreambuf_iterator<_CharT> >  
# endif
class num_get: public locale::facet
{
  friend class _Locale_impl;
#if defined(__MRC__) || defined(__SC__)	//*TY 04/29/2000 - added workaround for mpw
  typedef locale::facet _facet;			//*TY 04/29/2000 - they forget to look into nested class for the ctor.
#endif
public:
  typedef _CharT     char_type;
  typedef _InputIter iter_type;

#if !(defined(__MRC__)||defined(__SC__))	//*TY 02/26/2000 - added workaround for MPW compilers; explicit will prevent the compiler to find out the proper ctor
  explicit 
#endif										//*TY 02/26/2000 - 
  num_get(size_t __refs = 0) 
#if !(defined(__MRC__) || defined(__SC__) )		//*TY 04/29/2000 - added workaround for mpw
  : locale::facet(__refs)
#else
  : _facet(__refs)		//*TY 04/29/2000 - they forget to look into the nested class for the ctor
#endif
  {}
    
# ifndef __STL_NO_BOOL
  _InputIter get(_InputIter __in, _InputIter __end, ios_base& __str,
                ios_base::iostate& __err, bool& __val) const {
    return do_get(__in, __end, __str, __err, __val);
  }
# endif

  _InputIter get(_InputIter __in, _InputIter __end, ios_base& __str,
                ios_base::iostate& __err, short& __val) const {
    return do_get(__in, __end, __str, __err, __val);
  }

  _InputIter get(_InputIter __in, _InputIter __end, ios_base& __str,
                ios_base::iostate& __err, int& __val) const {
    return do_get(__in, __end, __str, __err, __val);
  }

  _InputIter get(_InputIter __in, _InputIter __end, ios_base& __str,
                ios_base::iostate& __err, long& __val) const {
    return do_get(__in, __end, __str, __err, __val);
  }

  _InputIter get(_InputIter __in, _InputIter __end, ios_base& __str,
                ios_base::iostate& __err, unsigned short& __val) const {
    return do_get(__in, __end, __str, __err, __val);
  }

  _InputIter get(_InputIter __in, _InputIter __end, ios_base& __str,
                ios_base::iostate& __err, unsigned int& __val) const {
    return do_get(__in, __end, __str, __err, __val);
  }

  _InputIter get(_InputIter __in, _InputIter __end, ios_base& __str,
                ios_base::iostate& __err, unsigned long& __val) const {
    return do_get(__in, __end, __str, __err, __val);
  }

#ifdef __STL_LONG_LONG

  _InputIter get(_InputIter __in, _InputIter __end, ios_base& __str,
                ios_base::iostate& __err, long long& __val) const {
    return do_get(__in, __end, __str, __err, __val);
  }

  _InputIter get(_InputIter __in, _InputIter __end, ios_base& __str,
                ios_base::iostate& __err, unsigned long long& __val) const {
    return do_get(__in, __end, __str, __err, __val);
  }

#endif /* _STL_LONG_LONG */

  _InputIter get(_InputIter __in, _InputIter __end, ios_base& __str,
                 ios_base::iostate& __err, float& __val) const {
    return do_get(__in, __end, __str, __err, __val);
  }

  _InputIter get(_InputIter __in, _InputIter __end, ios_base& __str,
                ios_base::iostate& __err, double& __val) const {
    return do_get(__in, __end, __str, __err, __val);
  }

# ifndef __STL_NO_LONG_DOUBLE

  _InputIter get(_InputIter __in, _InputIter __end, ios_base& __str,
                ios_base::iostate& __err, long double& __val) const {
    return do_get(__in, __end, __str, __err, __val);
  }
# endif

  _InputIter get(_InputIter __in, _InputIter __end, ios_base& __str,
                ios_base::iostate& __err, void*& __val) const {
    return do_get(__in, __end, __str, __err, __val);
  }

  __STL_STATIC_MEMBER_DECLSPEC static locale::id id;

protected:
  ~num_get() {}

  typedef string               string_type; 
  typedef ctype<_CharT>        _Ctype;
  typedef numpunct<_CharT>     _Numpunct;

# ifndef __STL_NO_BOOL
  virtual _InputIter do_get(_InputIter __in, _InputIter __end,
                           ios_base& __str, ios_base::iostate& __err, bool& __val) const;
# endif
  // issue 118
  virtual _InputIter do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                           ios_base::iostate& __err, short& __val) const;
  virtual _InputIter do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                           ios_base::iostate& __err, int& __val) const;
  virtual _InputIter do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                           ios_base::iostate& __err, long& __val) const;
  virtual _InputIter do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                           ios_base::iostate& __err, unsigned short& __val) const;
  virtual _InputIter do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                           ios_base::iostate& __err, unsigned int& __val) const;
  virtual _InputIter do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                           ios_base::iostate& __err, unsigned long& __val) const;
  virtual _InputIter do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                          ios_base::iostate& __err, float& __val) const;
  virtual _InputIter do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                           ios_base::iostate& __err, double& __val) const;
  virtual _InputIter do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                           ios_base::iostate& __err,
                           void*& __p) const;

#ifndef __STL_NO_LONG_DOUBLE
  virtual _InputIter do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                           ios_base::iostate& __err, long double& __val) const;
#endif /* __STL_LONG_DOUBLE */

#ifdef __STL_LONG_LONG

  virtual _InputIter do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                            ios_base::iostate& __err, long long& __val) const;
  virtual _InputIter do_get(_InputIter __in, _InputIter __end, ios_base& __str,
                           ios_base::iostate& __err, unsigned long long& __val) const;
#endif /* __STL_LONG_LONG */

};


//----------------------------------------------------------------------
// num_put facet

# ifdef __STL_LIMITED_DEFAULT_TEMPLATES
template <class _CharT, class _OutputIter>  
# else
template <class _CharT, class _OutputIter = ostreambuf_iterator<_CharT, char_traits<_CharT> > >  
# endif
class num_put: public locale::facet
{
  friend class _Locale_impl;
#if defined(__MRC__) || defined(__SC__)	//*TY 04/29/2000 - added workaround for mpw
  typedef locale::facet _facet;			//*TY 04/29/2000 - they forget to look into nested class for the ctor.
#endif									//*TY 04/29/2000 - 
public:
  typedef _CharT      char_type;
  typedef _OutputIter iter_type;

#if !(defined(__MRC__)||defined(__SC__))	//*TY 02/26/2000 - added workaround for MPW compilers; explicit will prevent the compiler to find out the proper ctor
  explicit 
#endif										//*TY 02/26/2000 - 
  num_put(size_t __refs = 0) 
#if !(defined(__MRC__) || defined(__SC__) )		//*TY 04/29/2000 - added workaround for mpw
  : locale::facet(__refs)
#else					//*TY 04/29/2000 - 
  : _facet(__refs)		//*TY 04/29/2000 - they forget to look into the nested class for the ctor
#endif					//*TY 04/29/2000 - 
  {}

  iter_type put(iter_type __s, ios_base& __f, char_type __fill,
                bool __val) const {
    return do_put(__s, __f, __fill, __val);
  }

  iter_type put(iter_type __s, ios_base& __f, char_type __fill,
               long __val) const {
    return do_put(__s, __f, __fill, __val);
  }

  iter_type put(iter_type __s, ios_base& __f, char_type __fill,
                unsigned long __val) const {
    return do_put(__s, __f, __fill, __val);
  }

#ifdef __STL_LONG_LONG
  iter_type put(iter_type __s, ios_base& __f, char_type __fill,
                long long __val) const {
    return do_put(__s, __f, __fill, __val);
  }

  iter_type put(iter_type __s, ios_base& __f, char_type __fill,
                unsigned long long __val) const {
    return do_put(__s, __f, __fill, __val);
  }
#endif

  iter_type put(iter_type __s, ios_base& __f, char_type __fill,
                double __val) const {
    return do_put(__s, __f, __fill, (double)__val);
  }

#ifndef __STL_NO_LONG_DOUBLE
  iter_type put(iter_type __s, ios_base& __f, char_type __fill,
                long double __val) const {
    return do_put(__s, __f, __fill, __val);
  }
# endif

  iter_type put(iter_type __s, ios_base& __f, char_type __fill,
                const void * __val) const {
    return do_put(__s, __f, __fill, __val);
  }

  __STL_STATIC_MEMBER_DECLSPEC static locale::id id;

protected:
  ~num_put() {}   
# ifndef __STL_NO_BOOL
  _OutputIter _M_do_put_bool(_OutputIter __s, ios_base& __f, _CharT __fill, bool    __x) const;
  virtual _OutputIter do_put(_OutputIter __s, ios_base& __f, _CharT __fill, bool __val) const;
# endif
  virtual _OutputIter do_put(_OutputIter __s, ios_base& __f, _CharT __fill, long __val) const;
  virtual _OutputIter do_put(_OutputIter __s, ios_base& __f, _CharT __fill, unsigned long __val) const;
  virtual _OutputIter do_put(_OutputIter __s, ios_base& __f, _CharT __fill, double __val) const;
#ifndef __STL_NO_LONG_DOUBLE
  virtual _OutputIter do_put(_OutputIter __s, ios_base& __f, _CharT __fill, long double __val) const;
#endif

#ifdef __STL_LONG_LONG
  virtual _OutputIter do_put(_OutputIter __s, ios_base& __f, _CharT __fill, long long __val) const;
  virtual _OutputIter do_put(_OutputIter __s, ios_base& __f, _CharT __fill, 
                           unsigned long long __val) const ;
#endif /* __STL_LONG_LONG */
  virtual _OutputIter do_put(_OutputIter __s, ios_base& __f, _CharT __fill, const void* __val) const;
};

# if defined (__STL_DESIGNATED_DLL) || ! defined (__STL_NO_CUSTOM_IO)

template < class _InputIter, class _Integer, class _CharT>
_InputIter __STL_DECLSPEC __STL_CALL
_M_do_get_integer(_InputIter&, _InputIter&, ios_base&, ios_base::iostate&, _Integer&, _CharT*);

template <class _InputIter, class _Float, class _CharT>
_InputIter __STL_DECLSPEC __STL_CALL
_M_do_get_float(_InputIter, _InputIter, ios_base&, ios_base::iostate&, _Float&, _CharT*);

// _M_do_put_float and its helper functions.  Strategy: write the output
// to a buffer of char, transform the buffer to _CharT, and then copy
// it to the output.

template <class _CharT, class _OutputIter, class _Integer>
_OutputIter __STL_DECLSPEC __STL_CALL
_M_do_put_integer(_OutputIter __s, ios_base& __f, _CharT __fill, _Integer  __val);

template <class _CharT, class _OutputIter,class _Float>
_OutputIter __STL_DECLSPEC __STL_CALL
_M_do_put_float(_OutputIter __s, ios_base& __f, _CharT __fill,_Float    __x);

char* __STL_CALL __write_float(char*, ios_base::fmtflags, int, double);
char* __STL_CALL __write_float(char*, ios_base::fmtflags, int, long double);

ptrdiff_t __STL_CALL __insert_grouping(char*, char*, const string&, char, int);
ptrdiff_t __STL_CALL __insert_grouping(wchar_t*, wchar_t*, const string&,
                            wchar_t, wchar_t, wchar_t, int);
ptrdiff_t __STL_CALL __insert_grouping(char* first, char* last, const string&,
                            char, char, char, int);
ptrdiff_t __STL_CALL __insert_grouping(wchar_t* first, wchar_t* last, const string&,
                            wchar_t, wchar_t, wchar_t, int );

#ifndef __STL_NO_WCHAR_T
wchar_t* __STL_CALL __convert_float_buffer(const char*, const char*, wchar_t*,
                                const ctype<wchar_t>&, wchar_t);
#endif

void __STL_CALL __adjust_float_buffer(char*, char*, char);

// _M_do_put_integer and its helper functions.

char* __STL_CALL __write_integer(char*, ios_base::fmtflags, long);
char* __STL_CALL __write_integer(char*, ios_base::fmtflags, unsigned long);

#ifdef __STL_LONG_LONG
char* __STL_CALL __write_integer(char*, ios_base::fmtflags, long long);
char* __STL_CALL __write_integer(char*, ios_base::fmtflags, unsigned long long);
#endif /* __STL_LONG_LONG */

// _M_do_get_integer and its helper functions.  

# ifdef __STL_NO_WCHAR_T
void __STL_CALL __initialize_get_digit(char*, char*, const ctype<char>&);
int __STL_CALL  __get_digit(char, const char*, const char*, char);
# else
// Helper functions for _M_do_get_integer
void __STL_CALL __initialize_get_digit(wchar_t*, wchar_t*, const ctype<wchar_t>&);
int __STL_CALL  __get_digit(wchar_t, const wchar_t*, const wchar_t*, wchar_t);

template <class _InputIter, class _Integer>
bool __STL_CALL
__get_integer_nogroup(_InputIter& __first, _InputIter& __last,
                      int __base, _Integer& __val, int __got = 0, bool __is_negative = false);

# endif

extern bool  __STL_CALL __valid_grouping(const string &, const string &);

inline pair<char, bool> __STL_CALL __get_fdigit(char __c, const char*)
  { return pair<char, bool>(__c, __c >= '0' && __c <= '9'); }

inline pair<char, bool> __STL_CALL __get_fdigit_or_sep(char __c, char __sep,
					    const char *)
  {return __c == __sep ? pair<char, bool>(',', true)
		       : pair<char, bool>(__c, __c >= '0' && __c <= '9');
  }

# ifndef __STL_NO_WCHAR_T
pair<char, bool> __STL_CALL __get_fdigit(wchar_t, const wchar_t*);
pair<char, bool> __STL_CALL __get_fdigit_or_sep(wchar_t, wchar_t, const wchar_t*);
# endif

void __STL_CALL __initialize_get_float(const locale&,
                                       char&, char&, char&, char&, char&,
                                       char&, string&,
                                       char*);

# ifndef __STL_NO_WCHAR_T
void  __STL_CALL __initialize_get_float(const locale&,
                                        wchar_t&, wchar_t&, wchar_t&, wchar_t&, wchar_t&,
                                        wchar_t&, string&, wchar_t*);
# endif
void  __STL_CALL __string_to_float(const string&, float&);
void  __STL_CALL __string_to_float(const string&, double&);
void  __STL_CALL __string_to_float(const string&, long double&);

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
              _Integer& __val) ;

# endif /* CUSTOM_IO */

__STL_END_NAMESPACE

# ifndef __STL_LINK_TIME_INSTANTIATION
#  include <stl/_numeric_facets.c>
# endif

#endif /* __SGI_STL_INTERNAL_NUMERIC_FACETS_H */

// Local Variables:
// mode:C++
// End:

