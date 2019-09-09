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

//# ifdef __CYGWIN__
//#  define __STL_IN_LOCALE_CPP 1
//# endif

#include "locale_impl.h"

__STL_BEGIN_NAMESPACE

// _Locale_impl non-inline member functions.

_Locale_impl::_Locale_impl(const _Locale_impl& L)
  : _Refcount_Base(1), facets(L.facets),
    name(L.name)    
{
  for (size_t i = 1; i < L.facets.size(); ++i) {
    if (L.facets[i] && ((locale::facet*)L.facets[i])->_M_delete)
      ((locale::facet*)L.facets[i])->_M_incr();
  }
}

_Locale_impl::~_Locale_impl() {
  for (size_t i = 1; i < facets.size(); ++i)
    remove(i);
}


void _Locale_impl::remove(size_t index) {
  if (index > 0 && index < facets.size()) {
    locale::facet* old = (locale::facet*)facets[index];
    if (old && old->_M_delete)
      if (old->_M_decr() == 0)
        delete old;
    facets[index] = 0;
  }
}

locale::facet*
_Locale_impl::insert(locale::facet* f, size_t index, bool do_incr) {
  if (f != 0 && index != 0) {
    if (index >= facets.size())
      facets.insert(facets.end(),
                    index - facets.size() + 1, (void*) 0);
    if (do_incr)
      f->_M_incr();

    remove(index);
    facets[index] = (void*)f;
    return f;
  }
  else
    return 0;
}

void _Locale_impl::insert(_Locale_impl* from, const locale::id& n) {
  size_t index = n._M_index;
  this->remove(index);
  if (index > 0 && index < from->facets.size())
    this->insert((locale::facet*)from->facets[index], index, true);
}

// Six functions, one for each category.  Each of them takes a 
// _Locale_impl* and a name, constructs that appropriate category
// facets by name, and inserts them into the locale.  

void _Locale_impl::insert_ctype_facets(const char* pname)
{
  ctype<char>*    ct                      = 0;
# ifndef __STL_NO_MBSTATE_T
  codecvt<char, char, mbstate_t>*    cvt  = 0;
# endif
# ifndef __STL_NO_WCHAR_T
  ctype<wchar_t>* wct                     = 0;
  codecvt<wchar_t, char, mbstate_t>* wcvt = 0;
# endif

  char buf[_Locale_MAX_SIMPLE_NAME];
  if (pname == 0 || pname[0] == 0)
    pname = _Locale_ctype_default(buf);

  if (pname == 0 || pname[0] == 0 || strcmp(pname, "C") == 0) {
    this->insert(_Stl_loc_classic_locale->_M_impl, ctype<char>::id);
    this->insert(_Stl_loc_classic_locale->_M_impl,
                 codecvt<char, char, mbstate_t>::id);
# ifndef __STL_NO_WCHAR_T
    this->insert(_Stl_loc_classic_locale->_M_impl, ctype<wchar_t>::id);
    this->insert(_Stl_loc_classic_locale->_M_impl,
                 codecvt<wchar_t, char, mbstate_t>::id);
# endif
  }
  else {
    __STL_TRY {
      ct   = new ctype_byname<char>(pname);
# ifndef __STL_NO_MBSTATE_T
      cvt  = new codecvt_byname<char, char, mbstate_t>(pname);
# endif
# ifndef __STL_NO_WCHAR_T
      wct  = new ctype_byname<wchar_t>(pname); 
      wcvt = new codecvt_byname<wchar_t, char, mbstate_t>(pname);
# endif
    }
    
# ifndef __STL_NO_WCHAR_T
#  ifdef __STL_NO_MBSTATE_T
    __STL_UNWIND(delete ct; delete wct; delete cvt);
#  else
    __STL_UNWIND(delete ct; delete wct; delete cvt; delete wcvt);
#  endif
# else
#  ifdef __STL_NO_MBSTATE_T
    __STL_UNWIND(delete ct);
#  else
    __STL_UNWIND(delete ct; delete cvt);
#  endif
# endif    
    _Locale_impl_insert(this, ct);
#  ifndef __STL_NO_MBSTATE_T
    _Locale_impl_insert(this, cvt);
#  endif
#  ifndef __STL_NO_WCHAR_T
    _Locale_impl_insert(this, wct);
    _Locale_impl_insert(this, wcvt);
#  endif
  }
}

void _Locale_impl::insert_numeric_facets(const char* pname)
{
  numpunct<char>*    punct  = 0;
  num_get<char, istreambuf_iterator<char, char_traits<char> > >*     get    = 0;
  num_put<char, ostreambuf_iterator<char, char_traits<char> > >*     put    = 0;
# ifndef __STL_NO_WCHAR_T
  numpunct<wchar_t>* wpunct = 0;
  num_get<wchar_t, istreambuf_iterator<wchar_t, char_traits<wchar_t> > >*  wget   = 0;
  num_put<wchar_t, ostreambuf_iterator<wchar_t, char_traits<wchar_t> > >*  wput   = 0;
# endif

  char buf[_Locale_MAX_SIMPLE_NAME];
  if (pname == 0 || pname[0] == 0)
    pname = _Locale_numeric_default(buf);

  if (pname == 0 || pname[0] == 0 || strcmp(pname, "C") == 0) {
    this->insert(_Stl_loc_classic_locale->_M_impl, numpunct<char>::id);
    this->insert(_Stl_loc_classic_locale->_M_impl, 
		 num_put<char, ostreambuf_iterator<char, char_traits<char> >  >::id);
    this->insert(_Stl_loc_classic_locale->_M_impl, 
		 num_get<char, istreambuf_iterator<char, char_traits<char> > >::id);
# ifndef __STL_NO_WCHAR_T
    this->insert(_Stl_loc_classic_locale->_M_impl, numpunct<wchar_t>::id);
    this->insert(_Stl_loc_classic_locale->_M_impl, 
		 num_get<wchar_t, istreambuf_iterator<wchar_t, char_traits<wchar_t> >  >::id);
    this->insert(_Stl_loc_classic_locale->_M_impl, 
		 num_put<wchar_t, ostreambuf_iterator<wchar_t, char_traits<wchar_t> > >::id);
# endif
  }
  else {
    __STL_TRY {
      punct  = new numpunct_byname<char>(pname);
      get    = new num_get<char, istreambuf_iterator<char, char_traits<char> > >;
      put    = new num_put<char, ostreambuf_iterator<char, char_traits<char> > >;
# ifndef __STL_NO_WCHAR_T
      wpunct = new numpunct_byname<wchar_t>(pname);
      wget   = new num_get<wchar_t, istreambuf_iterator<wchar_t, char_traits<wchar_t> > >;
      wput   = new num_put<wchar_t, ostreambuf_iterator<wchar_t, char_traits<wchar_t> > >;
# endif
    }
# ifndef __STL_NO_WCHAR_T
    __STL_UNWIND(delete punct; delete wpunct; delete get; delete wget;
    delete put; delete wput);
# else
    __STL_UNWIND(delete punct; delete get;delete put);
# endif
    
  _Locale_impl_insert(this,punct);
  _Locale_impl_insert(this,get);
  _Locale_impl_insert(this,put);

# ifndef __STL_NO_WCHAR_T
  _Locale_impl_insert(this,wpunct);
  _Locale_impl_insert(this,wget);
  _Locale_impl_insert(this,wput);
# endif
  }
}

void _Locale_impl::insert_time_facets(const char* pname)
{

  time_get<char, istreambuf_iterator<char, char_traits<char> > >*    get  = 0;
  time_put<char, ostreambuf_iterator<char, char_traits<char> > >*    put  = 0;
# ifndef __STL_NO_WCHAR_T
  time_get<wchar_t, istreambuf_iterator<wchar_t, char_traits<wchar_t> > >* wget = 0;
  time_put<wchar_t, ostreambuf_iterator<wchar_t, char_traits<wchar_t> > >* wput = 0;
# endif

  char buf[_Locale_MAX_SIMPLE_NAME];
  if (pname == 0 || pname[0] == 0)
    pname = _Locale_time_default(buf);
  
  if (pname == 0 || pname[0] == 0 || strcmp(pname, "C") == 0) {

    this->insert(_Stl_loc_classic_locale->_M_impl, 
		 time_get<char, istreambuf_iterator<char, char_traits<char> > >::id);
    this->insert(_Stl_loc_classic_locale->_M_impl, 
		 time_put<char, ostreambuf_iterator<char, char_traits<char> > >::id);
# ifndef __STL_NO_WCHAR_T
    this->insert(_Stl_loc_classic_locale->_M_impl,
		 time_get<wchar_t, istreambuf_iterator<wchar_t, char_traits<wchar_t> > >::id);
    this->insert(_Stl_loc_classic_locale->_M_impl,
		 time_put<wchar_t, ostreambuf_iterator<wchar_t, char_traits<wchar_t> > >::id);
# endif
  }
  else {
    __STL_TRY {
      get  = new time_get_byname<char, istreambuf_iterator<char, char_traits<char> > >(pname);
      put  = new time_put_byname<char, ostreambuf_iterator<char, char_traits<char> > >(pname);
# ifndef __STL_NO_WCHAR_T
      wget = new time_get_byname<wchar_t, istreambuf_iterator<wchar_t, char_traits<wchar_t> > >(pname);
      wput = new time_put_byname<wchar_t, ostreambuf_iterator<wchar_t, char_traits<wchar_t> > >(pname);
# endif
    }
# ifndef __STL_NO_WCHAR_T
    __STL_UNWIND(delete get; delete wget; delete put; delete wput);
# else
    __STL_UNWIND(delete get; delete put);
# endif
    _Locale_impl_insert(this,get);
    _Locale_impl_insert(this,put);
# ifndef __STL_NO_WCHAR_T
    _Locale_impl_insert(this,wget);
    _Locale_impl_insert(this,wput);
# endif
  }
}

void _Locale_impl::insert_collate_facets(const char* nam)
{
  collate<char>*    col  = 0;
# ifndef __STL_NO_WCHAR_T
  collate<wchar_t>* wcol = 0;
# endif

  char buf[_Locale_MAX_SIMPLE_NAME];
  if (nam == 0 || nam[0] == 0)
    nam = _Locale_collate_default(buf);

  if (nam == 0 || nam[0] == 0 || strcmp(nam, "C") == 0) {
    this->insert(_Stl_loc_classic_locale->_M_impl, collate<char>::id);
# ifndef __STL_NO_WCHAR_T
    this->insert(_Stl_loc_classic_locale->_M_impl, collate<wchar_t>::id);
# endif
  }
  else {
    __STL_TRY {
      col   = new collate_byname<char>(nam);
# ifndef __STL_NO_WCHAR_T
      wcol  = new collate_byname<wchar_t>(nam); 
# endif
    }
# ifndef __STL_NO_WCHAR_T
    __STL_UNWIND(delete col; delete wcol);
# else
    __STL_UNWIND(delete col);
# endif
    _Locale_impl_insert(this,col);
# ifndef __STL_NO_WCHAR_T
    _Locale_impl_insert(this,wcol);
# endif
  }
}

void _Locale_impl::insert_monetary_facets(const char* pname)
{
  moneypunct<char,    false>* punct   = 0;
  moneypunct<char,    true>*  ipunct  = 0;
  money_get<char, istreambuf_iterator<char, char_traits<char> > >*            get     = 0;
  money_put<char, ostreambuf_iterator<char, char_traits<char> > >*            put     = 0;

# ifndef __STL_NO_WCHAR_T
  moneypunct<wchar_t, false>* wpunct  = 0;
  moneypunct<wchar_t, true>*  wipunct = 0;
  money_get<wchar_t, istreambuf_iterator<wchar_t, char_traits<wchar_t> > >*         wget    = 0;
  money_put<wchar_t, ostreambuf_iterator<wchar_t, char_traits<wchar_t> > >*         wput    = 0;
# endif

  char buf[_Locale_MAX_SIMPLE_NAME];
  if (pname == 0 || pname[0] == 0)
    pname = _Locale_monetary_default(buf);

  if (pname == 0 || pname[0] == 0 || strcmp(pname, "C") == 0) {
    this->insert(_Stl_loc_classic_locale->_M_impl, moneypunct<char, false>::id);
    this->insert(_Stl_loc_classic_locale->_M_impl, moneypunct<char, true>::id);
    this->insert(_Stl_loc_classic_locale->_M_impl, money_get<char, istreambuf_iterator<char, char_traits<char> > >::id);
    this->insert(_Stl_loc_classic_locale->_M_impl, money_put<char, ostreambuf_iterator<char, char_traits<char> > >::id);
# ifndef __STL_NO_WCHAR_T
    this->insert(_Stl_loc_classic_locale->_M_impl, moneypunct<wchar_t, false>::id);
    this->insert(_Stl_loc_classic_locale->_M_impl, moneypunct<wchar_t, true>::id);
    this->insert(_Stl_loc_classic_locale->_M_impl, money_get<wchar_t, istreambuf_iterator<wchar_t, char_traits<wchar_t> > >::id);
    this->insert(_Stl_loc_classic_locale->_M_impl, money_put<wchar_t, ostreambuf_iterator<wchar_t, char_traits<wchar_t> > >::id);
# endif
  }
  else {    
    __STL_TRY {
      punct   = new moneypunct_byname<char, false>(pname);
      ipunct  = new moneypunct_byname<char, true>(pname);
      get     = new money_get<char, istreambuf_iterator<char, char_traits<char> > >;
      put     = new money_put<char, ostreambuf_iterator<char, char_traits<char> > >;
# ifndef __STL_NO_WCHAR_T
      wpunct  = new moneypunct_byname<wchar_t, false>(pname);
      wipunct = new moneypunct_byname<wchar_t, true>(pname);
      wget    = new money_get<wchar_t, istreambuf_iterator<wchar_t, char_traits<wchar_t> > >;
      wput    = new money_put<wchar_t, ostreambuf_iterator<wchar_t, char_traits<wchar_t> > >;
# endif
    }
# ifndef __STL_NO_WCHAR_T
    __STL_UNWIND(delete punct; delete ipunct; delete wpunct; delete wipunct;
    delete get; delete wget; delete put; delete wput);
# else
    __STL_UNWIND(delete punct; delete ipunct; delete get; delete put);
# endif
    _Locale_impl_insert(this,punct);
    _Locale_impl_insert(this,ipunct);
    _Locale_impl_insert(this,get);
    _Locale_impl_insert(this,put);
# ifndef __STL_NO_WCHAR_T
    _Locale_impl_insert(this,wget);
    _Locale_impl_insert(this,wpunct);
    _Locale_impl_insert(this,wipunct);
    _Locale_impl_insert(this,wput);
# endif
  }
}

void _Locale_impl::insert_messages_facets(const char* pname)
{
  messages<char>*    msg  = 0;
# ifndef __STL_NO_WCHAR_T
  messages<wchar_t>* wmsg = 0;
# endif

  char buf[_Locale_MAX_SIMPLE_NAME];
  if (pname == 0 || pname[0] == 0)
    pname = _Locale_messages_default(buf);

  if (pname == 0 || pname[0] == 0 || strcmp(pname, "C") == 0) {
    this->insert(_Stl_loc_classic_locale->_M_impl, messages<char>::id);
# ifndef __STL_NO_WCHAR_T
    this->insert(_Stl_loc_classic_locale->_M_impl, messages<wchar_t>::id);
# endif
  }
  else {
    __STL_TRY {
      msg  = new messages_byname<char>(pname);
# ifndef __STL_NO_WCHAR_T
      wmsg = new messages_byname<wchar_t>(pname);
# endif
    }
# ifndef __STL_NO_WCHAR_T
    __STL_UNWIND(delete msg; delete wmsg);
# else
    __STL_UNWIND(delete msg);
# endif
    _Locale_impl_insert(this,msg);
# ifndef __STL_NO_WCHAR_T
    _Locale_impl_insert(this,wmsg);
# endif
  }
}

static _STL_STATIC_MUTEX _Index_lock __STL_MUTEX_INITIALIZER;

// Takes a reference to a locale::id, and returns its numeric index.
// If no numeric index has yet been assigned, assigns one.  The return
// value is always positive.
size_t _Stl_loc_get_index(locale::id& id)
{
  if (id._M_index == 0) {
    _STL_auto_lock sentry(_Index_lock);
    size_t new_index = locale::id::_S_max++;
    id._M_index = new_index;
  }
  return id._M_index;
}

void _Stl_loc_assign_ids() {
  // This assigns ids to every facet that is a member of a category,
  // and also to money_get/put, num_get/put, and time_get/put
  // instantiated using ordinary pointers as the input/output
  // iterators.  (The default is [io]streambuf_iterator.)

  collate<char>::id._M_index                       = 1;
  ctype<char>::id._M_index                         = 3;
  codecvt<char, char, mbstate_t>::id._M_index      = 5;
  moneypunct<char, true>::id._M_index              = 7;
  moneypunct<char, false>::id._M_index             = 8;
  money_get<char, istreambuf_iterator<char, char_traits<char> > >::id._M_index                     = 11;
  money_get<char, const char*>::id._M_index        = 13;
  money_put<char, ostreambuf_iterator<char, char_traits<char> > >::id._M_index                     = 15;
  money_put<char, char*>::id._M_index              = 17;
  numpunct<char>::id._M_index                      = 19;
  num_get<char, istreambuf_iterator<char, char_traits<char> > >::id._M_index                       = 21;
  num_get<char, const char*>::id._M_index          = 23;
  num_put<char, ostreambuf_iterator<char, char_traits<char> > >::id._M_index                       = 25;
  num_put<char, char*>::id._M_index                = 27;
  time_get<char, istreambuf_iterator<char, char_traits<char> > >::id._M_index                      = 29;
  time_get<char, const char*>::id._M_index         = 31;
  time_put<char, ostreambuf_iterator<char, char_traits<char> > >::id._M_index                      = 33;
  time_put<char, char*>::id._M_index               = 35;
  messages<char>::id._M_index                      = 37;

# ifndef __STL_NO_WCHAR_T
  collate<wchar_t>::id._M_index                    = 2;
  ctype<wchar_t>::id._M_index                      = 4;
  codecvt<wchar_t, char, mbstate_t>::id._M_index   = 6;
  moneypunct<wchar_t, true>::id._M_index           = 9;
  moneypunct<wchar_t, false>::id._M_index          = 10;
  money_get<wchar_t, istreambuf_iterator<wchar_t, char_traits<wchar_t> > >::id._M_index                  = 12;
  money_get<wchar_t, const wchar_t*>::id._M_index  = 14;
  money_put<wchar_t, ostreambuf_iterator<wchar_t, char_traits<wchar_t> > >::id._M_index                  = 16;
  money_put<wchar_t, wchar_t*>::id._M_index        = 18;
  numpunct<wchar_t>::id._M_index                   = 20;
  num_get<wchar_t, istreambuf_iterator<wchar_t, char_traits<wchar_t> > >::id._M_index                       = 22;
  num_get<wchar_t, const wchar_t*>::id._M_index    = 24;
  num_put<wchar_t, ostreambuf_iterator<wchar_t, char_traits<wchar_t> > > ::id._M_index                      = 26;
  num_put<wchar_t, wchar_t*>::id._M_index          = 28;
  time_get<wchar_t, istreambuf_iterator<wchar_t, char_traits<wchar_t> > >::id._M_index                   = 30;
  time_get<wchar_t, const wchar_t*>::id._M_index   = 32;
  time_put<wchar_t, ostreambuf_iterator<wchar_t, char_traits<wchar_t> > >::id._M_index                   = 34;
  time_put<wchar_t, wchar_t*>::id._M_index         = 36;
  messages<wchar_t>::id._M_index                   = 38;
# endif

  locale::id::_S_max                               = 39;
}

_Locale_impl* _Stl_loc_make_classic_locale() {
  // The classic locale contains every facet that belongs to a category.
  _Locale_impl* classic = new _Locale_impl(locale::id::_S_max, "C");

  // collate category
  _Locale_impl_insert(classic, new collate<char>(0));
# ifndef __STL_NO_WCHAR_T
  _Locale_impl_insert(classic, new collate<wchar_t>(0));
# endif
  // ctype category
  _Locale_impl_insert(classic,new ctype<char>(0, false, 0));
  _Locale_impl_insert(classic,new codecvt<char, char, mbstate_t>(0));
# ifndef __STL_NO_WCHAR_T
  _Locale_impl_insert(classic,new ctype<wchar_t>(0));
  _Locale_impl_insert(classic,new codecvt<wchar_t, char, mbstate_t>(0));
# endif
  // monetary category
  _Locale_impl_insert(classic, new moneypunct<char, true>(0));
  _Locale_impl_insert(classic,new moneypunct<char, false>(0));
  _Locale_impl_insert(classic,new money_get<char, istreambuf_iterator<char, char_traits<char> > >(0));
  _Locale_impl_insert(classic,new money_put<char, ostreambuf_iterator<char, char_traits<char> > >(0));
# ifndef __STL_NO_WCHAR_T
  _Locale_impl_insert(classic,new moneypunct<wchar_t, true>(0));
  _Locale_impl_insert(classic,new moneypunct<wchar_t, false>(0));
  _Locale_impl_insert(classic,new money_get<wchar_t, istreambuf_iterator<wchar_t, char_traits<wchar_t> > >(0));
  _Locale_impl_insert(classic,new money_put<wchar_t, ostreambuf_iterator<wchar_t, char_traits<wchar_t> > >(0));
# endif
  // numeric category
  _Locale_impl_insert(classic,new numpunct<char>(0));
  _Locale_impl_insert(classic,new num_get<char, istreambuf_iterator<char, char_traits<char> > >(0));
  _Locale_impl_insert(classic,new num_put<char, ostreambuf_iterator<char, char_traits<char> > >(0));
# ifndef __STL_NO_WCHAR_T
  _Locale_impl_insert(classic,new numpunct<wchar_t>(0));
  _Locale_impl_insert(classic,new num_get<wchar_t, istreambuf_iterator<wchar_t, char_traits<wchar_t> > >(0));
  _Locale_impl_insert(classic,new num_put<wchar_t, ostreambuf_iterator<wchar_t, char_traits<wchar_t> > >(0));
# endif
  // time category
  _Locale_impl_insert(classic,new time_get<char, istreambuf_iterator<char, char_traits<char> > >(0));
  _Locale_impl_insert(classic,new time_put<char, ostreambuf_iterator<char, char_traits<char> > >(0));

# ifndef __STL_NO_WCHAR_T
  _Locale_impl_insert(classic,new time_get<wchar_t, istreambuf_iterator<wchar_t, char_traits<wchar_t> > > (0));
  _Locale_impl_insert(classic,new time_put<wchar_t, ostreambuf_iterator<wchar_t, char_traits<wchar_t> > > (0));
# endif
  
  // messages category
  _Locale_impl_insert(classic,new messages<char>(0));
# ifndef __STL_NO_WCHAR_T
  _Locale_impl_insert(classic,new messages<wchar_t>(0));
# endif

  return classic;
}

// Give L a name where all facets except those in category c
// are taken from name1, and those in category c are taken from name2.
void _Stl_loc_combine_names(_Locale_impl* L,
                   const char* name1, const char* name2,
                   locale::category c)
{
  if ((c & locale::all) == 0 || strcmp(name1, name2) == 0)
    L->name = name1;
  else if ((c & locale::all) == locale::all)
    L->name = name2;
  else {
    // Decompose the names.
    char ctype_buf[_Locale_MAX_SIMPLE_NAME];
    char numeric_buf[_Locale_MAX_SIMPLE_NAME];
    char time_buf[_Locale_MAX_SIMPLE_NAME];
    char collate_buf[_Locale_MAX_SIMPLE_NAME];
    char monetary_buf[_Locale_MAX_SIMPLE_NAME];
    char messages_buf[_Locale_MAX_SIMPLE_NAME];

    _Locale_extract_ctype_name((c & locale::ctype) ? name1 : name2,
                               ctype_buf); 
    _Locale_extract_numeric_name((c & locale::numeric) ? name1 : name2,
                                 numeric_buf); 
    _Locale_extract_time_name((c & locale::time) ? name1 : name2,
                              time_buf); 
    _Locale_extract_collate_name((c & locale::collate) ? name1 : name2,
                                 collate_buf); 
    _Locale_extract_monetary_name((c & locale::monetary) ? name1 : name2,
                                  monetary_buf); 
    _Locale_extract_messages_name((c & locale::messages) ? name1 : name2,
                                  messages_buf); 

    // Construct a new composite name.
    char composite_buf[_Locale_MAX_COMPOSITE_NAME];
    _Locale_compose_name(composite_buf,
                         ctype_buf, numeric_buf, time_buf,
                         collate_buf, monetary_buf, messages_buf);
    L->name = composite_buf;
  }
}

_Locale_impl*   _Stl_loc_global_impl    = 0;



__STL_END_NAMESPACE
