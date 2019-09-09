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

# ifndef LOCALE_IMPL_H
#  define  LOCALE_IMPL_H

#include <clocale>             // C locale header file.
#include <vector>
#include <locale>

__STL_BEGIN_NAMESPACE

//----------------------------------------------------------------------
// Class _Locale_impl

class __STL_CLASS_DECLSPEC _Locale_impl : public _Refcount_Base
{
public:
  _Locale_impl(size_t n, const char* s) : _Refcount_Base(1), facets(n, (void*)0 ), name(s) {}
  _Locale_impl(const _Locale_impl&);
  ~_Locale_impl();

  void remove(size_t index);
  locale::facet* insert(locale::facet*, size_t index, bool do_incr);
  void insert(_Locale_impl* from, const locale::id& n);

// Helper functions for byname construction of locales.
  void insert_ctype_facets(const char* name);
  void insert_numeric_facets(const char* name);
  void insert_time_facets(const char* name);
  void insert_collate_facets(const char* name);
  void insert_monetary_facets(const char* name);
  void insert_messages_facets(const char* name);
  
  vector<void*> facets;
  basic_string<char, char_traits<char>, allocator<char> > name;

private:
  void operator=(const _Locale_impl&);
};

template <class Facet>
inline locale::facet* 
_Locale_impl_insert(_Locale_impl* __that, Facet* f) {
  return __that->insert(f, Facet::id._M_index, false);
}

size_t _Stl_loc_get_index(locale::id& id);
void _Stl_loc_assign_ids();
_Locale_impl* _Stl_loc_make_classic_locale();
void _Stl_loc_combine_names(_Locale_impl* L,
                            const char* name1, const char* name2,
                            locale::category c);

extern _Locale_impl*   _Stl_loc_global_impl;
extern locale*         _Stl_loc_classic_locale;
extern _STL_STATIC_MUTEX _Stl_loc_global_locale_lock;

// this is really from locale.cpp
_Locale_numeric*  __STL_CALL __acquire_numeric(const char* name);
void  __STL_CALL __release_numeric(_Locale_numeric* cat);

__STL_END_NAMESPACE

#endif
