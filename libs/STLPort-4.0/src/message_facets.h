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
#ifndef MESSAGE_FACETS_H
# define MESSAGE_FACETS_H

#include <string>
#include <locale>
#include <typeinfo>
#include <hash_map>

__STL_BEGIN_NAMESPACE

_Locale_messages* __acquire_messages(const char* name); 
void __release_messages(_Locale_messages* cat);

// Class _Catalog_locale_map.  The reason for this is that, internally,
// a message string is always a char*.  We need a ctype facet to convert
// a string to and from wchar_t, and the user is permitted to provide such
// a facet when calling open().

struct _Catalog_locale_map
{
  _Catalog_locale_map() : M(0) {}
  ~_Catalog_locale_map() { if (M) delete M; }

  void insert(int key, const locale& L);
  locale lookup(int key) const;
  void erase(int key);

  hash_map<int, locale, hash<int>, equal_to<int> >* M;

private:                        // Invalidate copy constructor and assignment
  _Catalog_locale_map(const _Catalog_locale_map&);
  void operator=(const _Catalog_locale_map&);
};

__STL_END_NAMESPACE

#endif
