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

#ifndef __SGI_STL_INTERNAL_COLLATE_H
#define __SGI_STL_INTERNAL_COLLATE_H

#include <stl/c_locale.h>
#include <stl/_string_fwd.h>
#include <stl/_locale.h>

__STL_BEGIN_NAMESPACE


template <class _CharT> class collate {};
template <class _CharT> class collate_byname {};

__STL_TEMPLATE_NULL
class __STL_CLASS_DECLSPEC collate<char> : public locale::facet 
{
  friend class _Locale_impl;
#if defined(__MRC__) || defined(__SC__)	//*TY 04/29/2000 - added workaround for mpw
  typedef locale::facet _facet;			//*TY 04/29/2000 - they forget to look into nested class for the ctor.
#endif									//*TY 04/29/2000 - 
public:
  typedef char   char_type;
  typedef string string_type;

  explicit collate(size_t __refs = 0);

  int compare(const char* __low1, const char* __high1,
              const char* __low2, const char* __high2) const {
    return do_compare( __low1, __high1, __low2, __high2);
  }

  string_type transform(const char* __low, const char* __high) const;

  long hash(const char* __low, const char* __high) const
    { return do_hash(__low, __high); }

  __STL_STATIC_MEMBER_DECLSPEC static locale::id id;

protected:
  ~collate();

  virtual int do_compare(const char*, const char*,
                         const char*, const char*) const;
  virtual string_type do_transform(const char*, const char*) const;
  virtual long do_hash(const char*, const char*) const;
private:
  collate(const collate<char>&);
  collate<char>& operator =(const collate<char>&);  
};

# ifndef __STL_NO_WCHAR_T

__STL_TEMPLATE_NULL
class __STL_CLASS_DECLSPEC collate<wchar_t> : public locale::facet 
{
  friend class _Locale_impl;
#if defined(__MRC__) || defined(__SC__)	//*TY 04/29/2000 - added workaround for mpw
  typedef locale::facet _facet;			//*TY 04/29/2000 - they forget to look into nested class for the ctor.
#endif									//*TY 04/29/2000 - 
public:
  typedef wchar_t char_type;
  typedef wstring string_type;

  explicit collate(size_t __refs = 0);

  int compare(const wchar_t* __low1, const wchar_t* __high1,
              const wchar_t* __low2, const wchar_t* __high2) const {
    return do_compare( __low1, __high1, __low2, __high2);
  }

  string_type transform(const wchar_t* __low, const wchar_t* __high) const;

  long hash(const wchar_t* __low, const wchar_t* __high) const
    { return do_hash(__low, __high); }

  __STL_STATIC_MEMBER_DECLSPEC static locale::id id;

protected:
  ~collate();

  virtual int do_compare(const wchar_t*, const wchar_t*,
                         const wchar_t*, const wchar_t*) const;
  virtual string_type do_transform(const wchar_t*, const wchar_t*) const;
  virtual long do_hash(const wchar_t* __low, const wchar_t* __high) const;
private:
  collate(const collate<wchar_t>&);
  collate<wchar_t>& operator = (const collate<wchar_t>&);  
};

# endif /* NO_WCHAR_T */

__STL_TEMPLATE_NULL
class __STL_CLASS_DECLSPEC collate_byname<char>: public collate<char> 
{
public:
  explicit collate_byname(const char* __name, size_t __refs = 0);

protected:
  ~collate_byname();

  virtual int do_compare(const char*, const char*,
                         const char*, const char*) const;
  virtual string_type do_transform(const char*, const char*) const;

private:
  _Locale_collate* _M_collate;
  collate_byname(const collate_byname<char>&);
  collate_byname<char>& operator =(const collate_byname<char>&);  
};

# ifndef __STL_NO_WCHAR_T

__STL_TEMPLATE_NULL
class __STL_CLASS_DECLSPEC collate_byname<wchar_t>: public collate<wchar_t> 
{
public:
  explicit collate_byname(const char * __name, size_t __refs = 0);

protected:
  ~collate_byname();

  virtual int do_compare(const wchar_t*, const wchar_t*,
                         const wchar_t*, const wchar_t*) const;
  virtual string_type do_transform(const wchar_t*, const wchar_t*) const;

private:
  _Locale_collate* _M_collate;
  collate_byname(const collate_byname<wchar_t>&);
  collate_byname<wchar_t>& operator =(const collate_byname<wchar_t>&);  
};

# endif /* NO_WCHAR_T */


__STL_END_NAMESPACE

#endif /* __SGI_STL_INTERNAL_COLLATE_H */

// Local Variables:
// mode:C++
// End:
