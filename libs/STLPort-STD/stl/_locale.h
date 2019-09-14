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


#ifndef __SGI_STL_INTERNAL_LOCALE_H
#define __SGI_STL_INTERNAL_LOCALE_H

#include <typeinfo>
#include <cstdlib>
#include <stl/_threads.h>
#include <stl/_string_fwd.h>

__STL_BEGIN_NAMESPACE

class __STL_CLASS_DECLSPEC _Locale_impl;             // Forward declaration of opaque type.
class __STL_CLASS_DECLSPEC locale;

class __STL_CLASS_DECLSPEC locale {
  friend class _Locale_impl;
  friend class ios_base;
public:
  // types:

  class __STL_DECLSPEC facet : private _Refcount_Base {
    friend class locale;
    friend class _Locale_impl;
  protected:
    explicit facet(size_t __no_del = 0) : _Refcount_Base(1), _M_delete(__no_del == 0) {}
    virtual ~facet();
    
  private:                        // Invalidate assignment and copying.
    facet(const facet&);          
    void operator=(const facet&); 
    
  private:                        // Data members.
    const bool _M_delete;
  };
  
  class __STL_DECLSPEC id {
    friend class locale;
    friend class _Locale_impl;
  public:
    size_t _M_index;
    static size_t _S_max;
  };
  
  typedef int category;
# if defined (__STL_STATIC_CONST_INIT_BUG) || defined (__STL_USE_DECLSPEC)
  enum _Category {
# else
  static const category
# endif
    none      = 0x000,
    collate   = 0x010,
    ctype     = 0x020,
    monetary  = 0x040,
    numeric   = 0x100,
    time      = 0x200,
    messages  = 0x400,
    all       = collate | ctype | monetary | numeric | time | messages
# if defined (__STL_STATIC_CONST_INIT_BUG) || defined (__STL_USE_DECLSPEC)
  }
# endif
  ;

  // construct/copy/destroy:
  locale();
  locale(const locale&) __STL_NOTHROW;
  explicit locale(const char *);
  locale(const locale&, const char*, category);

private:
  locale(_Locale_impl*, bool);

public:

# if defined ( __STL_MEMBER_TEMPLATES ) && defined (__STL_FUNCTION_TMPL_PARTIAL_ORDER)
  template <class _Facet> 
  locale(const locale& __loc, _Facet* __f) : _M_impl(0)
    {
      _M_impl = this->_S_copy_impl(__loc._M_impl, __f != 0);
      if (__f != 0)
	this->_M_insert(__f, _Facet::id);
    }
# endif

  locale(const locale&, const locale&, category);
  ~locale() __STL_NOTHROW;
  const locale& operator=(const locale&) __STL_NOTHROW;

# if !(defined (__STL_NO_MEMBER_TEMPLATES) || defined (__STL_NO_EXPLICIT_FUNCTION_TMPL_ARGS))
  template <class _Facet> locale combine(const locale&)
#  ifndef __STL_INLINE_MEMBER_TEMPLATES
	;
#  else
{
  locale __result(__loc._M_impl, true);
  if (facet* __f = __loc._M_get_facet(_Facet::id)) {
    __result._M_insert(__f, _Facet::id);
    __f->_M_incr();
  }
  else
    _M_throw_runtime_error();

  return __result;
}
#  endif
# endif
  // locale operations:
  basic_string<char, char_traits<char>, allocator<char> > name() const;

  bool operator==(const locale&) const;
  bool operator!=(const locale&) const;

# if ! defined ( __STL_MEMBER_TEMPLATES ) || defined (__STL_INLINE_MEMBER_TEMPLATES)
  bool operator()(const string& __x,
                  const string& __y) const;
#  ifndef __STL_NO_WCHAR_T
  bool operator()(const wstring& __x,
                  const wstring& __y) const;
#  endif
# else
  template <class _CharT, class _Traits, class _Alloc>
  bool operator()(const basic_string<_CharT, _Traits, _Alloc>& __x,
                  const basic_string<_CharT, _Traits, _Alloc>& __y) const
#  if !defined(__MWERKS__) || __MWERKS__ > 0x2301
	;
#  else
                  
  {
	  const __STLPORT_STD::collate<_CharT>& __col = 
	    use_facet<__STLPORT_STD::collate<_CharT> >(*this);
	  return __col.compare(__x.data(), __x.data() + __x.size(),
	                       __y.data(), __y.data() + __y.size());
  }              
#  endif
# endif

  // global locale objects:
  static locale __STL_CALL global(const locale&);
  static const locale& __STL_CALL classic();

public:                         // Helper functions for locale globals.
  facet* _M_get_facet(const id&) const;
  static void __STL_CALL _M_throw_runtime_error(const char* = 0);

private:                        // More helper functions.
  static void __STL_CALL _S_initialize();
  static void __STL_CALL _S_uninitialize();
  static _Locale_impl* __STL_CALL _S_copy_impl(_Locale_impl*, bool);
  void _M_insert(facet* __f, id& __id);

private:                        // Data members
  _Locale_impl* _M_impl;      

};

//----------------------------------------------------------------------
// locale globals

# ifdef __STL_NO_EXPLICIT_FUNCTION_TMPL_ARGS
template <class _Facet>
inline const _Facet& 
_Use_facet<_Facet>::operator *() const
# else
template <class _Facet> inline const _Facet& use_facet(const locale& __loc)
# endif
{
  const locale::facet* __f = __loc._M_get_facet(_Facet::id);
  if (!__f) {
    __STL_THROW(bad_cast());
  }
  const _Facet* __fc = __STATIC_CAST(const _Facet*,__f);
  return *__fc;
}

 
# ifdef __STL_NO_EXPLICIT_FUNCTION_TMPL_ARGS
template <class _Facet> 
struct has_facet {
  const locale& __loc;
  has_facet(const locale& __p_loc) : __loc(__p_loc) {}
  operator bool() const __STL_NOTHROW
# else
template <class _Facet> inline bool has_facet(const locale& __loc) __STL_NOTHROW 
# endif
{
  return __loc._M_get_facet(_Facet::id) != 0;
}

# ifdef __STL_NO_EXPLICIT_FUNCTION_TMPL_ARGS
  // close class definition
};
# endif

__STL_END_NAMESPACE

# ifndef __STL_LINK_TIME_INSTANTIATION
#  include <stl/_locale.c>
# endif

#endif /* __SGI_STL_INTERNAL_LOCALE_H */

// Local Variables:
// mode:C++
// End:

