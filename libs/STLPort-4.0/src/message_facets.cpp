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

#include "message_facets.h"

__STL_BEGIN_NAMESPACE

void _Catalog_locale_map::insert(int key, const locale& L)
{
# ifdef __STL_NO_WCHAR_T
  typedef char _Char;
# else
  typedef wchar_t _Char;
# endif
  // Don't bother to do anything unless we're using a non-default ctype facet
  try {
    typedef ctype<_Char> wctype;
    const wctype& wct = use_facet<wctype>(L);
    const wctype* zz = (const wctype*)0;
    if (typeid(&wct) != typeid(zz)) {
      if (!M)
        M = new hash_map<int, locale, hash<int>, equal_to<int> >;

#if defined(__SC__)			//*TY 06/01/2000 - added workaround for SCpp
      if (!M) delete M;		//*TY 06/01/2000 - it forgets to generate dtor for hash_map<> class. This fake code forces to generate one.
#endif						//*TY 06/01/2000 - 

      if (M->find(key) == M->end())
        M->insert(pair<const int, locale>(key, L));
    }
  }
  catch(...) {}
}

void _Catalog_locale_map::erase(int key)
{
  if (M)
    M->erase(key);
}

locale _Catalog_locale_map::lookup(int key) const
{
  if (M) {
    hash_map<int, locale, hash<int>, equal_to<int> >::iterator i = M->find(key);
    return i != M->end() ? (*i).second : locale::classic();
  }
  else
    return locale::classic();
}

//----------------------------------------------------------------------
// messages<char>

messages<char>::messages(size_t refs)
#if !(defined(__MRC__) || defined(__SC__) )		//*TY 04/29/2000 - added workaround for mpw
  : locale::facet(refs),
#else					//*TY 04/29/2000 - 
  : _facet(refs),		//*TY 04/29/2000 - they forget to look into the nested class for the ctor
#endif					//*TY 04/29/2000 - 
  _M_message_obj(0)
{
  _M_message_obj = __acquire_messages("C");
}

messages<char>::messages(size_t refs, _Locale_messages* msg_obj)
#if !(defined(__MRC__) || defined(__SC__) )		//*TY 04/29/2000 - added workaround for mpw
  : locale::facet(refs),
#else					//*TY 04/29/2000 - 
  : _facet(refs),		//*TY 04/29/2000 - they forget to look into the nested class for the ctor
#endif					//*TY 04/29/2000 - 
  _M_message_obj(msg_obj)
{}

messages<char>::~messages()
{
  __release_messages(_M_message_obj);
}

int messages<char>::do_open(const string& filename, const locale&) const
{
  return _M_message_obj
    ? _Locale_catopen(_M_message_obj, filename.c_str())
    : -1;
}

string messages<char>::do_get(catalog cat,
                              int set, int p_id, const string& dfault) const
{
  return _M_message_obj != 0 && cat >= 0
    ? string(_Locale_catgets(_M_message_obj, cat, set, p_id, dfault.c_str()))
    : dfault;
}

void messages<char>::do_close(catalog cat) const
{
  if (_M_message_obj)
    _Locale_catclose(_M_message_obj, cat);
}


//----------------------------------------------------------------------
// messages_byname<char>

messages_byname<char>::messages_byname(const char* name, size_t refs)
  : messages<char>(refs, name ? __acquire_messages(name) : 0)
{}

messages_byname<char>::~messages_byname()
{}

__STL_END_NAMESPACE

// Local Variables:
// mode:C++
// End:
