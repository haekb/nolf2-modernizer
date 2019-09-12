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

#ifndef __STL_LOCALE_C
# define __STL_LOCALE_C

#include <stl/_ctype.h>
#include <stl/_string.h>
#include <stl/_collate.h>

__STL_BEGIN_NAMESPACE

//----------------------------------------------------------------------
// Template members

// Lets the locale act as a comparison function object for strings.
// It may or may not be a strict weak ordering, depending on how the
// collate facet is defined.
# if defined ( __STL_MEMBER_TEMPLATES ) && ! defined (__STL_INLINE_MEMBER_TEMPLATES)

#  if !defined(__MWERKS__) || __MWERKS__ > 0x2301
template <class _CharT, class _Tr, class _Al>
bool locale::operator()(const basic_string<_CharT, _Tr, _Al>& __x,
                        const basic_string<_CharT, _Tr, _Al>& __y) const {
  const __STLPORT_STD::collate<_CharT>& __col = 
    use_facet<__STLPORT_STD::collate<_CharT> >(*this);
  return __col.compare(__x.data(), __x.data() + __x.size(),
                       __y.data(), __y.data() + __y.size());
}

#   if !defined (__STL_NO_EXPLICIT_FUNCTION_TMPL_ARGS) && ! defined (__STL_INLINE_MEMBER_TEMPLATES)
// A sort of generalized constructor.  Creates a copy of the 
// current locale, except taking _Facet from the other locale __loc.
template <class _Facet>
locale locale::combine(const locale& __loc) 
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
#   endif  /* __STL_NO_EXPLICIT_FUNCTION_TMPL_ARGS */

#  endif /* __MWERKS__ */

# endif /* MEMBER_TEMPLATES */

__STL_END_NAMESPACE

#endif
