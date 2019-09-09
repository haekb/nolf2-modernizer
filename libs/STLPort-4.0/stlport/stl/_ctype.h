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

#ifndef __SGI_STL_INTERNAL_CTYPE_H
#define __SGI_STL_INTERNAL_CTYPE_H

# include <stl/c_locale.h>

# ifndef __STL_INTERNAL_ALGOBASE_H
#  include <stl/_algobase.h>
# endif

__STL_BEGIN_NAMESPACE

class __STL_CLASS_DECLSPEC ctype_base {
public:
  enum mask {
    space   = _Locale_SPACE,
    print   = _Locale_PRINT,
    cntrl   = _Locale_CNTRL,
    upper   = _Locale_UPPER,
    lower   = _Locale_LOWER,
    alpha   = _Locale_ALPHA,
    digit   = _Locale_DIGIT,
    punct   = _Locale_PUNCT,
    xdigit  = _Locale_XDIGIT,
    alnum   = alpha | digit,
    graph   = alnum | punct
  };
};

template <class charT> class ctype {};
template <class charT> class ctype_byname {};

# ifndef __STL_NO_WCHAR_T
__STL_TEMPLATE_NULL
class __STL_CLASS_DECLSPEC ctype<wchar_t> : public locale::facet, public ctype_base 
{
#if defined(__MRC__) || defined(__SC__)	//*TY 04/29/2000 - added workaround for mpw
  typedef locale::facet _facet;			//*TY 04/29/2000 - they forget to look into nested class for the ctor.
#endif									//*TY 04/29/2000 - 
  friend class _Locale_impl;
public:
  typedef wchar_t char_type;

  explicit ctype(size_t refs = 0);

  bool is(mask __m, wchar_t __c) const
    { return do_is(__m, __c); }

  const wchar_t* is(const wchar_t* __low, const wchar_t* __high,
                    mask* __vec) const
    { return do_is(__low, __high, __vec); }

  const wchar_t* scan_is(mask __m, 
                         const wchar_t* __low, const wchar_t* __high) const
    { return do_scan_is(__m, __low, __high); }

  const wchar_t* scan_not (mask __m, 
                           const wchar_t* __low, const wchar_t* __high) const
    { return do_scan_not(__m, __low, __high); }

  wchar_t (toupper)(wchar_t __c) const { return do_toupper(__c); }
  const wchar_t* (toupper)(wchar_t* __low, wchar_t* __high) const
    { return do_toupper(__low, __high); }

  wchar_t (tolower)(wchar_t __c) const { return do_tolower(__c); }
  const wchar_t* (tolower)(wchar_t* __low, wchar_t* __high) const
    { return do_tolower(__low, __high); }

  wchar_t widen(char __c) const { return do_widen(__c); }
  const char* widen(const char* __low, const char* __high,
                    wchar_t* __to) const
    { return do_widen(__low, __high, __to); }

  char narrow(wchar_t __c, char __dfault) const
    { return do_narrow(__c, __dfault); }
  const wchar_t* narrow(const wchar_t* __low, const wchar_t* __high,
                        char __dfault, char* __to) const
    { return do_narrow(__low, __high, __dfault, __to); }

  __STL_STATIC_MEMBER_DECLSPEC static locale::id id;

protected:
  ~ctype();

  virtual bool           do_is(mask __m, wchar_t __c) const;
  virtual const wchar_t* do_is(const wchar_t*, const wchar_t*, mask*) const;
  virtual const wchar_t* do_scan_is(mask,
                                    const wchar_t*, const wchar_t*) const;
  virtual const wchar_t* do_scan_not(mask,
                                     const wchar_t*, const wchar_t*) const;
  virtual wchar_t do_toupper(wchar_t __c) const;
  virtual const wchar_t* do_toupper(wchar_t*, const wchar_t*) const;
  virtual wchar_t do_tolower(wchar_t c) const;
  virtual const wchar_t* do_tolower(wchar_t*, const wchar_t*) const;
  virtual wchar_t do_widen(char c) const;
  virtual const char* do_widen(const char*, const char*, wchar_t*) const;
  virtual char  do_narrow(wchar_t __c, char __dfault) const;
  virtual const wchar_t* do_narrow(const wchar_t*, const wchar_t*,
                                   char, char*) const;
};

__STL_TEMPLATE_NULL
class __STL_CLASS_DECLSPEC ctype_byname<wchar_t>: public ctype<wchar_t> {
public:
  explicit ctype_byname(const char* __name, size_t __refs = 0);

protected:
  ~ctype_byname();

  virtual bool           do_is(mask __m, wchar_t __c) const;
  virtual const wchar_t* do_is(const wchar_t*, const wchar_t*, mask*) const;
  virtual const wchar_t* do_scan_is(mask,
                                    const wchar_t*, const wchar_t*) const;
  virtual const wchar_t* do_scan_not(mask,
                                     const wchar_t*, const wchar_t*) const;
  virtual wchar_t do_toupper(wchar_t __c) const;
  virtual const wchar_t* do_toupper(wchar_t*, const wchar_t*) const;
  virtual wchar_t do_tolower(wchar_t c) const;
  virtual const wchar_t* do_tolower(wchar_t*, const wchar_t*) const;

private:
  _Locale_ctype* _M_ctype;
};

# endif /* WCHAR_T */

//ctype specializations

__STL_TEMPLATE_NULL
class __STL_CLASS_DECLSPEC ctype<char> : 
  public locale::facet, public ctype_base 
{

# ifndef __STL_NO_WCHAR_T
#  ifdef __STL_MSVC
    typedef ctype<wchar_t> _Wctype;
    friend _Wctype;
#  else
    friend class ctype<wchar_t>;
#  endif
# endif
  friend class _Locale_impl;
#if defined(__MRC__) || defined(__SC__)	//*TY 04/29/2000 - added workaround for mpw
  typedef locale::facet _facet;			//*TY 04/29/2000 - they forget to look into nested class for the ctor.
#endif									//*TY 04/29/2000 - 
public:
  typedef char char_type;

  explicit ctype(const mask* = 0, bool = false, size_t = 0);
  
  inline bool is(mask __m, char __c) const
    { return ((*(table()+(unsigned char)__c)) & __m) != 0; }
  const char* is(const char*, const char*, mask*) const;
  const char* scan_is(mask __m, const char* __low, const char* __high) const;
  const char* scan_not(mask __m, const char* __low, const char* __high) const;

  char        (toupper)(char __c) const { return do_toupper(__c); }
  const char* (toupper)(char* __low, const char* __high) const
    { return do_toupper(__low, __high); }

  char        (tolower)(char __c) const { return do_tolower(__c); }
  const char* (tolower)(char* __low, const char* __high) const
    { return do_tolower(__low, __high); }
  
  char        widen(char __c) const
    { return do_widen(__c); }
  const char* widen(const char* __low, const char* __high, char* __to) const
    { return do_widen(__low, __high, __to); }

  char        narrow(char __c, char __dfault) const
    { return do_narrow(__c, __dfault); }
  const char* narrow(const char* __low, const char* __high,
                     char __dfault, char* __to) const 
    { return do_narrow(__low, __high, __dfault, __to); }

  __STL_STATIC_MEMBER_DECLSPEC static locale::id id;
# if defined(__STL_STATIC_CONST_INIT_BUG) // || defined(__MRC__) || defined(__SC__)		//*TY 04/29/2000 - turned out this work around is not needed for mpw
  enum __TableSize { table_size = 256 };
# else
  static const size_t table_size = 256;
# endif

protected:
  const mask* table() const __STL_NOTHROW {return _M_ctype_table;}
  static const mask* __STL_CALL classic_table() __STL_NOTHROW { return & _S_classic_table [1]; }

  ~ctype();

  virtual char        do_toupper(char __c) const
    { return (char) _S_upper[(unsigned char) __c]; }
  virtual char        do_tolower(char __c) const
    { return (char) _S_lower[(unsigned char) __c]; }

  virtual const char* do_toupper(char*, const char*) const;
  virtual const char* do_tolower(char*, const char*) const;

  virtual char        do_widen(char __c) const { return __c; }
  virtual const char* do_widen(const char* __low, const char* __high,
                               char* __to) const {
    copy(__low, __high, __to);
    return __high;    
  }

  virtual char        do_narrow(char __c, char /* dfault */ ) const { return __c; }
  virtual const char* do_narrow(const char* __low, const char* __high,
                                char /* dfault */, char* __to) const {
    copy(__low, __high, __to);
    return __high; 
  }

private:
  struct _Is_mask {
    mask __m;
    _Is_mask(mask __x): __m(__x) {}
   bool operator()(char __c) {return (__m & (unsigned char) __c) != 0;}
  };

  static const mask _S_classic_table[257 /* table_size + 1 */];
  const mask* _M_ctype_table;
  bool _M_delete;

  static const unsigned char _S_upper[256 /* table_size */];
  static const unsigned char _S_lower[256 /* table_size */];
};


__STL_TEMPLATE_NULL
class __STL_CLASS_DECLSPEC ctype_byname<char>: public ctype<char> {
public:
  explicit ctype_byname(const char*, size_t = 0);
  ~ctype_byname();

  virtual char        do_toupper(char __c) const;
  virtual char        do_tolower(char __c) const;

  virtual const char* do_toupper(char*, const char*) const;
  virtual const char* do_tolower(char*, const char*) const;

private:
  mask _M_byname_table[table_size + 1];
  _Locale_ctype* _M_ctype;
};



__STL_END_NAMESPACE

#endif /* __SGI_STL_INTERNAL_CTYPE_H */

// Local Variables:
// mode:C++
// End:

