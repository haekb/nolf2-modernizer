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

# ifndef __STL_NO_WCHAR_T

messages<wchar_t>::messages(size_t refs)
#if !(defined(__MRC__) || defined(__SC__) )		//*TY 04/29/2000 - added workaround for mpw
  : locale::facet(refs),
#else					//*TY 04/29/2000 - 
  : _facet(refs),		//*TY 04/29/2000 - they forget to look into the nested class for the ctor
#endif					//*TY 04/29/2000 - 
    _M_message_obj(0), _M_map(new _Catalog_locale_map)
{
  _M_message_obj = __acquire_messages("C");
}

messages<wchar_t>::messages(size_t refs, _Locale_messages* msg_obj)
#if !(defined(__MRC__) || defined(__SC__) )		//*TY 04/29/2000 - added workaround for mpw
  : locale::facet(refs),
#else					//*TY 04/29/2000 - 
  : _facet(refs),		//*TY 04/29/2000 - they forget to look into the nested class for the ctor
#endif					//*TY 04/29/2000 - 
    _M_message_obj(msg_obj), _M_map(new _Catalog_locale_map)
{}

messages<wchar_t>::~messages()
{
  __release_messages(_M_message_obj);
  delete _M_map;
}

int messages<wchar_t>::do_open(const string& filename, const locale& L) const
{
  int result = _M_message_obj
    ? _Locale_catopen(_M_message_obj, filename.c_str())
    : -1;

  if (result >= 0)
    _M_map->insert(result, L);

  return result;
}

wstring
messages<wchar_t>::do_get(catalog thecat,
                          int set, int p_id, const wstring& dfault) const
{
  typedef ctype<wchar_t> wctype;
  const wctype& ct = use_facet<wctype>(_M_map->lookup(thecat));

  const char* str = _Locale_catgets(_M_message_obj, thecat, set, p_id, "");

  // Verify that the lookup failed; an empty string might represent success.
  if (!str)
    return dfault;
  else if (str[0] == '\0') {
    const char* str2 = _Locale_catgets(_M_message_obj, thecat, set, p_id, "*");
    if (!str2 || strcmp(str2, "*") == 0)
      return dfault;
  }

  // str is correct.  Now we must widen it to get a wstring.
  size_t n = strlen(str);

  // NOT PORTABLE.  What we're doing relies on internal details of the 
  // string implementation.  (Contiguity of string elements.)
  wstring result(n, wchar_t(0));
  ct.widen(str, str + n, &*result.begin());
  return result;
}

void messages<wchar_t>::do_close(catalog thecat) const
{
  if (_M_message_obj)
    _Locale_catclose(_M_message_obj, thecat);
  _M_map->erase(thecat);
}

# endif


//----------------------------------------------------------------------
// messages_byname<wchar_t>

# ifndef __STL_NO_WCHAR_T

messages_byname<wchar_t>::messages_byname(const char* name, size_t refs)
  : messages<wchar_t>(refs, name ? __acquire_messages(name) : 0)
{}

messages_byname<wchar_t>::~messages_byname()
{}

# endif

__STL_END_NAMESPACE

// Local Variables:
// mode:C++
// End:
