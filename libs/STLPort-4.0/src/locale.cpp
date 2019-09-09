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

#include <locale>
#include <hash_map>
#include "locale_impl.h"

__STL_BEGIN_NAMESPACE

locale::facet::~facet() {}

# if ! defined ( __STL_MEMBER_TEMPLATES ) || defined (__STL_INLINE_MEMBER_TEMPLATES)

template <class _CharT>
inline bool 
locale_do_operator_call (const locale* __that, const basic_string<_CharT, char_traits<_CharT>, allocator<_CharT> >& __x,
			      const basic_string<_CharT, char_traits<_CharT>, allocator<_CharT> >& __y)
{
  //  typedef char _CharT;
  const __STLPORT_STD::collate<_CharT>& __col = 
    use_facet<__STLPORT_STD::collate<_CharT> >(*__that);
  return __col.compare(__x.data(), __x.data() + __x.size(),
                       __y.data(), __y.data() + __y.size());
}

// members that fail to be templates 
bool locale::operator()(const string& __x,
                  const string& __y) const {
  return locale_do_operator_call(this, __x, __y);
}

#  ifndef __STL_NO_WCHAR_T
bool locale::operator()(const wstring& __x,
                  const wstring& __y) const {
  return locale_do_operator_call(this, __x, __y);
}
#  endif
# endif

//----------------------------------------------------------------------
// struct locale::id

size_t locale::id::_S_max;
locale*         _Stl_loc_classic_locale = 0;
_STL_STATIC_MUTEX _Stl_loc_global_locale_lock __STL_MUTEX_INITIALIZER;

  
//----------------------------------------------------------------------
// class locale

// Helper function: return a copy of I.  If do_clone is true
// we create a new _Locale_impl object, otherwise we just adjust
// the reference counts.
_Locale_impl*  __STL_CALL
locale::_S_copy_impl(_Locale_impl* I, bool do_clone)
{
  if (do_clone) {
    _Locale_impl* result = new _Locale_impl(*I);
    result->name = "*";
    return result;
  }
  else {
    I->_M_incr();
    return I;
  }
}

void locale::_M_insert(facet* f, locale::id& n)
{
  if (f)
    _M_impl->insert(f, _Stl_loc_get_index(n), false);
}


void __STL_CALL
locale::_M_throw_runtime_error(const char* name)
{
  char buf[256];

  if (name) {
    const char* prefix = "bad locale name: ";
    strcpy(buf, prefix);
    strncat(buf, name, 256 - strlen(prefix));
    buf[255] = '\0';
  }
  else {
    strcpy(buf, "locale error");
  }
  __STL_THROW(runtime_error(buf));
}


// Initialization of the locale system.  This must be called before
// any locales are constructed.  (Meaning that it must be called when
// the I/O library itself is initialized.)
void __STL_CALL
locale::_S_initialize()
{

  _Stl_loc_assign_ids();
  _Locale_impl* classic_impl = _Stl_loc_make_classic_locale();
  _Stl_loc_global_impl = classic_impl;
  _Stl_loc_classic_locale = new locale(classic_impl, false);
  // Postcondition: number of references to classic_impl is 2.
}



void __STL_CALL
locale::_S_uninitialize()
{
  if (_Stl_loc_global_impl->_M_decr() == 0)
    delete _Stl_loc_global_impl;
  delete _Stl_loc_classic_locale;

  _Stl_loc_global_impl = 0;
  _Stl_loc_classic_locale = 0;
}


// Default constructor: create a copy of the global locale.
locale::locale()
  : _M_impl(0)
{
  _M_impl = _S_copy_impl(_Stl_loc_global_impl, false);
}

// Copy constructor
locale::locale(const locale& L) __STL_NOTHROW
  : _M_impl(0)
{
  _M_impl = _S_copy_impl(L._M_impl, false);
}

// Make a locale directly from a _Locale_impl object.  If the second argument
// is true, we clone the _Locale_impl.  If false, we just twiddle pointers.
locale::locale(_Locale_impl* impl, bool do_copy)
  : _M_impl(0)
{
  _M_impl = _S_copy_impl(impl, do_copy);
}


// Create a locale from a name.
locale::locale(const char* name)
  : _M_impl(0)
{
  if (!name)
    _M_throw_runtime_error(0);

  __STL_TRY {
    _M_impl = new _Locale_impl(locale::id::_S_max, name);

    // Insert categories one at a time.
    _M_impl->insert_ctype_facets(name);
    _M_impl->insert_numeric_facets(name);
    _M_impl->insert_time_facets(name);
    _M_impl->insert_collate_facets(name);
    _M_impl->insert_monetary_facets(name);
    _M_impl->insert_messages_facets(name);
  }
  __STL_UNWIND(delete _M_impl);
}

// Contruct a new locale where all facets that aren't in category c
// come from L1, and all those that are in category c come from L2.
locale::locale(const locale& L1, const locale& L2, category c)
  : _M_impl(0)
{
  _M_impl = new _Locale_impl(*L1._M_impl);
  _Locale_impl* i2 = L2._M_impl;

  static string nameless("*");
  if (L1.name() != nameless && L2.name() != nameless)
    _Stl_loc_combine_names(_M_impl,
                  L1._M_impl->name.c_str(), L2._M_impl->name.c_str(),
                  c);
  else {
    _M_impl->name = "*";
  }

  if (c & collate) {
    _M_impl->insert( i2, __STLPORT_STD::collate<char>::id);
# ifndef __STL_NO_WCHAR_T
    _M_impl->insert( i2, __STLPORT_STD::collate<wchar_t>::id);
# endif
  }
  if (c & ctype) {
    _M_impl->insert( i2, __STLPORT_STD::ctype<char>::id);
    _M_impl->insert( i2, __STLPORT_STD::codecvt<char, char, mbstate_t>::id);
# ifndef __STL_NO_WCHAR_T
    _M_impl->insert( i2, __STLPORT_STD::ctype<wchar_t>::id);
    _M_impl->insert( i2, __STLPORT_STD::codecvt<wchar_t, char, mbstate_t>::id);
# endif
  }
  if (c & monetary) {
    _M_impl->insert( i2, __STLPORT_STD::moneypunct<char, true>::id);
    _M_impl->insert( i2, __STLPORT_STD::moneypunct<char, false>::id);
    _M_impl->insert( i2, __STLPORT_STD::money_get<char, istreambuf_iterator<char, char_traits<char> > >::id);
    _M_impl->insert( i2, __STLPORT_STD::money_put<char, ostreambuf_iterator<char, char_traits<char> > >::id);
# ifndef __STL_NO_WCHAR_T
    _M_impl->insert( i2, __STLPORT_STD::moneypunct<wchar_t, true>::id);
    _M_impl->insert( i2, __STLPORT_STD::moneypunct<wchar_t, false>::id);
    _M_impl->insert( i2, __STLPORT_STD::money_get<wchar_t, istreambuf_iterator<wchar_t, char_traits<wchar_t> > >::id);
    _M_impl->insert( i2, __STLPORT_STD::money_put<wchar_t, ostreambuf_iterator<wchar_t, char_traits<wchar_t> > >::id);
# endif
  }
  if (c & numeric) {
    _M_impl->insert( i2, __STLPORT_STD::numpunct<char>::id);
    _M_impl->insert( i2, __STLPORT_STD::num_get<char, istreambuf_iterator<char, char_traits<char> > >::id);
    _M_impl->insert( i2, __STLPORT_STD::num_put<char, ostreambuf_iterator<char, char_traits<char> > >::id);
# ifndef __STL_NO_WCHAR_T
    _M_impl->insert( i2, __STLPORT_STD::numpunct<wchar_t>::id);
    _M_impl->insert( i2, num_get<wchar_t, istreambuf_iterator<wchar_t, char_traits<wchar_t> > >::id);
    _M_impl->insert( i2, num_put<wchar_t, ostreambuf_iterator<wchar_t, char_traits<wchar_t> > >::id);
# endif
  }
  if (c & time) {
    _M_impl->insert( i2, __STLPORT_STD::time_get<char, istreambuf_iterator<char, char_traits<char> > >::id);
    _M_impl->insert( i2, __STLPORT_STD::time_put<char, ostreambuf_iterator<char, char_traits<char> > >::id);
# ifndef __STL_NO_WCHAR_T
    _M_impl->insert( i2, __STLPORT_STD::time_get<wchar_t, istreambuf_iterator<wchar_t, char_traits<wchar_t> > >::id);
    _M_impl->insert( i2, __STLPORT_STD::time_put<wchar_t, ostreambuf_iterator<wchar_t, char_traits<wchar_t> > >::id);
# endif
  }
  if (c & messages) {
    _M_impl->insert( i2, __STLPORT_STD::messages<char>::id);
# ifndef __STL_NO_WCHAR_T
    _M_impl->insert( i2, __STLPORT_STD::messages<wchar_t>::id);
# endif
  }
}

// Create a locale that's a copy of L, except that all of the facets
// in category c are instead constructed by name.
locale::locale(const locale& L, const char* name, locale::category c)
  : _M_impl(0)
{
  if (name == 0 || strcmp(name, "*") == 0)
    _M_throw_runtime_error(name);

  __STL_TRY {
    _M_impl = new _Locale_impl(*L._M_impl);
    _Stl_loc_combine_names(_M_impl, L._M_impl->name.c_str(), name, c);

    if (c & locale::ctype)
      _M_impl->insert_ctype_facets(name);
    if (c & locale::numeric)
      _M_impl->insert_numeric_facets(name);
    if (c & locale::time)
      _M_impl->insert_time_facets(name);
    if (c & locale::collate)
      _M_impl->insert_collate_facets(name);
    if (c & locale::monetary)
      _M_impl->insert_monetary_facets(name);
    if (c & locale::messages)
      _M_impl->insert_messages_facets(name);
  }
  __STL_UNWIND(delete _M_impl)
}

// Destructor.
locale::~locale() __STL_NOTHROW
{
  if (_M_impl->_M_decr() == 0)
    delete _M_impl;
}

// Assignment operator.  Much like the copy constructor: just a bit of
// pointer twiddling.
const locale& locale::operator=(const locale& L) __STL_NOTHROW
{
  if (this->_M_impl != L._M_impl) {
    if (this->_M_impl->_M_decr() == 0)
      delete this->_M_impl;
    this->_M_impl = _S_copy_impl(L._M_impl, false);
  }
  return *this;
}

locale::facet* locale::_M_get_facet(const locale::id& n) const
{
  return n._M_index < _M_impl->facets.size()
    ? (locale::facet*)_M_impl->facets[n._M_index]
    : (locale::facet*) 0;
}

string locale::name() const {
  return _M_impl->name;
}


// Compare two locales for equality.
bool locale::operator==(const locale& L) const {
  static string nameless("*");

  return this->_M_impl == L._M_impl ||
         (this->name() == L.name() && this->name() != nameless);
}

bool locale::operator!=(const locale& L) const {
  return !(*this == L);
}

// Static member functions.
const locale&  __STL_CALL
locale::classic() {
  return *_Stl_loc_classic_locale;
}

locale  __STL_CALL
locale::global(const locale& L) 
{
  locale old;                   // A copy of the old global locale.

  L._M_impl->_M_incr();
  {
    _STL_auto_lock lock(_Stl_loc_global_locale_lock);
    _Stl_loc_global_impl->_M_decr();     // We made a copy, so it can't be zero.
    _Stl_loc_global_impl = L._M_impl;
  }

                                // Set the global C locale, if appropriate.
  static string nameless("*");
  if (L.name() != nameless)
    setlocale(LC_ALL, L.name().c_str());

  return old;
}


// static data members.

# if !defined (__STL_STATIC_CONST_INIT_BUG) && ! defined (__STL_USE_DECLSPEC)

const locale::category locale::none;
const locale::category locale::collate;
const locale::category locale::ctype;
const locale::category locale::monetary;
const locale::category locale::numeric;
const locale::category locale::time; 
const locale::category locale::messages;
const locale::category locale::all;

# endif


//----------------------------------------------------------------------
// Declarations of (non-template) facets' static data members
__STL_STATIC_MEMBER_DECLSPEC locale::id collate<char>::id;
__STL_STATIC_MEMBER_DECLSPEC locale::id ctype<char>::id;

__STL_STATIC_MEMBER_DECLSPEC locale::id numpunct<char>::id;


# ifndef __STL_NO_MBSTATE_T
__STL_STATIC_MEMBER_DECLSPEC locale::id codecvt<char, char, mbstate_t>::id;
__STL_STATIC_MEMBER_DECLSPEC locale::id codecvt<wchar_t, char, mbstate_t>::id;
# endif

__STL_STATIC_MEMBER_DECLSPEC locale::id moneypunct<char, true>::id;
__STL_STATIC_MEMBER_DECLSPEC locale::id moneypunct<char, false>::id;

__STL_STATIC_MEMBER_DECLSPEC locale::id messages<char>::id;

# ifndef __STL_NO_WCHAR_T
__STL_STATIC_MEMBER_DECLSPEC locale::id numpunct<wchar_t>::id;
__STL_STATIC_MEMBER_DECLSPEC locale::id ctype<wchar_t>::id;
__STL_STATIC_MEMBER_DECLSPEC locale::id collate<wchar_t>::id;
__STL_STATIC_MEMBER_DECLSPEC locale::id moneypunct<wchar_t, true>::id;
__STL_STATIC_MEMBER_DECLSPEC locale::id moneypunct<wchar_t, false>::id;
__STL_STATIC_MEMBER_DECLSPEC locale::id messages<wchar_t>::id;
# endif



__STL_END_NAMESPACE
