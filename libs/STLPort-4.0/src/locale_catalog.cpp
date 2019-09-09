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

// those wrappers are needed to avoid extern "C"

 void* _Loc_ctype_create(const char * s)
  { return (void*)_Locale_ctype_create(s); }
 void* _Loc_numeric_create(const char * s)
  { return (void*)_Locale_numeric_create(s); }
 void* _Loc_time_create(const char * s)
  { return (void*)_Locale_time_create(s); }
 void* _Loc_collate_create(const char * s)
  { return (void*)_Locale_collate_create(s); }
 void* _Loc_monetary_create(const char * s)
  { return (void*)_Locale_monetary_create(s); }
 void* _Loc_messages_create(const char * s)
  { return (void*)_Locale_messages_create(s); }

 char* _Loc_ctype_name(const void* l, char* s)
  { return _Locale_ctype_name(l, s); }
 char* _Loc_numeric_name(const void* l, char* s)
  { return _Locale_numeric_name(l, s); }
 char* _Loc_time_name(const void* l, char* s)
  { return _Locale_time_name(l,s); }
 char* _Loc_collate_name( const void* l, char* s)
  { return _Locale_collate_name(l,s); }
 char* _Loc_monetary_name(const void* l, char* s)
  { return _Locale_monetary_name(l,s); }
 char* _Loc_messages_name(const void* l, char* s)
  { return _Locale_messages_name(l,s); }

 const char* _Loc_ctype_default(char* p)    { return _Locale_ctype_default(p); }
 const char* _Loc_numeric_default(char * p) { return _Locale_numeric_default(p); }
 const char* _Loc_time_default(char* p)     { return _Locale_time_default(p); }
 const char* _Loc_collate_default(char* p)  { return _Locale_collate_default(p); }
 const char* _Loc_monetary_default(char* p) { return _Locale_monetary_default(p); }
 const char* _Loc_messages_default(char* p) { return _Locale_messages_default(p); }

 void _Loc_ctype_destroy(void* p)    {_Locale_ctype_destroy(p); }
 void _Loc_numeric_destroy(void* p)  {_Locale_numeric_destroy(p); }
 void _Loc_time_destroy(void* p)     {_Locale_time_destroy(p);}
 void _Loc_collate_destroy(void* p)  {_Locale_collate_destroy(p);}
 void _Loc_monetary_destroy(void* p) {_Locale_monetary_destroy(p);}
 void _Loc_messages_destroy(void* p) {_Locale_messages_destroy(p);}

typedef void* (*loc_create_func_t)(const char *);
typedef char* (*loc_name_func_t)(const void* l, char* s);
typedef void (*loc_destroy_func_t)(void* l);
typedef const char* (*loc_default_name_func_t)(char* s);

//----------------------------------------------------------------------
// Acquire and release low-level category objects.  The whole point of
// this is so that we don't allocate (say) four different _Locale_ctype
// objects for a single locale.

struct __eqstr {
  bool operator()(const char* s1, const char* s2) const
    { return strcmp(s1, s2) == 0; }
};

struct __ptr_hash {
  size_t operator()(const void* p) const
    { return __REINTERPRET_CAST(size_t,p); }
};

template <class _Category_ptr>
struct __destroy_fun {
  typedef void (*_fun_type)(_Category_ptr);
  _fun_type _M_fun;
  __destroy_fun(_fun_type __f) : _M_fun(__f) {}
  void operator()(_Category_ptr __c) { _M_fun(__c); }  
};

// Global hash tables for category objects.
typedef hash_map<const char*, pair<void*, size_t>, hash<const char*>, __eqstr> Category_Map;

// Look up a category by name
static hash_map<const char*, pair<void*, size_t>, hash<const char*>, __eqstr>* ctype_hash;
static hash_map<const char*, pair<void*, size_t>, hash<const char*>, __eqstr>* numeric_hash;
static hash_map<const char*, pair<void*, size_t>, hash<const char*>, __eqstr>* time_hash;
static hash_map<const char*, pair<void*, size_t>, hash<const char*>, __eqstr>* collate_hash;
static hash_map<const char*, pair<void*, size_t>, hash<const char*>, __eqstr>* monetary_hash;
static hash_map<const char*, pair<void*, size_t>, hash<const char*>, __eqstr>* messages_hash;

// We have a single lock for all of the hash tables.  We may wish to 
// replace it with six different locks.
/* REFERENCED */
_STL_STATIC_MUTEX __category_hash_lock __STL_MUTEX_INITIALIZER;

static void*
__acquire_category(const char* name, loc_create_func_t create_obj,
                   loc_default_name_func_t default_obj, Category_Map ** M)
{
  typedef Category_Map::iterator Category_iterator;
  pair<Category_iterator, bool> result;
  _STL_auto_lock sentry(__category_hash_lock);

  typedef const char* key_type; 
  pair<const key_type, pair<void*,size_t> > __e(name, pair<void*,size_t>((void*)0,size_t(0)));

  if (!*M)
    *M = new Category_Map();

#if defined(__SC__)		//*TY 06/01/2000 - added workaround for SCpp
  if(!*M) delete *M;	//*TY 06/01/2000 - it forgets to generate dtor for Category_Map class. This fake code forces to generate one.
#endif					//*TY 06/01/2000 - 

  // Find what name to look for.  Be careful if user requests the default.
  char buf[_Locale_MAX_SIMPLE_NAME];
  if (name == 0 || name[0] == 0)
    name = default_obj(buf);
  if (name == 0 || name[0] == 0)
    name = "C";

  // Look for an existing entry with that name.

  result = (*M)->insert_noresize(__e);

  // There was no entry in the map already.  Create the category.
  if (result.second) 
    (*result.first).second.first = create_obj(name);

  // Increment the reference count.
  ++((*result.first).second.second);

  return (*result.first).second.first;
}


static void 
__release_category(void* cat,
                 loc_destroy_func_t destroy_fun,
                 loc_name_func_t get_name,
                 Category_Map* M)
{
  _STL_auto_lock sentry(__category_hash_lock);

  if (cat && M) {
    // Find the name of the category object.
    char buf[_Locale_MAX_SIMPLE_NAME + 1];
    char* name = get_name(cat, buf);

    if (name != 0) {
      Category_Map::iterator it = M->find(name);
      if (it != M->end()) {
        // Decrement the ref count.  If it goes to zero, delete this category
        // from the map.
        if (--((*it).second.second) == 0) {
          void* cat1 = (*it).second.first;
          destroy_fun(cat1);
          M->erase(it);
        }
      }
    }
  }
}

_Locale_ctype* __STL_CALL __acquire_ctype(const char* name)
{ return __REINTERPRET_CAST(_Locale_ctype*,
                            __acquire_category(name, _Loc_ctype_create, _Loc_ctype_default, &ctype_hash)); }
_Locale_numeric* __STL_CALL __acquire_numeric(const char* name)
{ return __REINTERPRET_CAST(_Locale_numeric*,
                            __acquire_category(name, _Loc_numeric_create, _Loc_numeric_default, &numeric_hash)); }
_Locale_time* __STL_CALL __acquire_time(const char* name)
{ return __REINTERPRET_CAST(_Locale_time*,
                            __acquire_category(name, _Loc_time_create, _Loc_time_default, &time_hash)); }
_Locale_collate* __STL_CALL __acquire_collate(const char* name)
{ return __REINTERPRET_CAST(_Locale_collate*,
                            __acquire_category(name, _Loc_collate_create, _Loc_collate_default, &collate_hash)); }
_Locale_monetary* __STL_CALL __acquire_monetary(const char* name)
{ return __REINTERPRET_CAST(_Locale_monetary*,
                            __acquire_category(name, _Loc_monetary_create, _Loc_monetary_default, &monetary_hash)); }
_Locale_messages* __STL_CALL __acquire_messages(const char* name)
{ return __REINTERPRET_CAST(_Locale_messages*,
                            __acquire_category(name, _Loc_messages_create, _Loc_messages_default, &messages_hash)); }

void  __STL_CALL __release_ctype(_Locale_ctype* cat) {
  __release_category(cat, _Loc_ctype_destroy, _Loc_ctype_name, ctype_hash);
}
void __STL_CALL __release_numeric(_Locale_numeric* cat) {
  __release_category(cat, _Loc_numeric_destroy, _Loc_numeric_name, numeric_hash);
}
void __STL_CALL __release_time(_Locale_time* cat) {
  __release_category(cat, _Loc_time_destroy, _Loc_time_name, time_hash);
}
void __STL_CALL __release_collate(_Locale_collate* cat) {
  __release_category(cat, _Loc_collate_destroy, _Loc_collate_name, collate_hash);
}
void __STL_CALL __release_monetary(_Locale_monetary* cat) {
  __release_category(cat, _Loc_monetary_destroy, _Loc_monetary_name, monetary_hash);
}
void __STL_CALL __release_messages(_Locale_messages* cat) {
  __release_category(cat, _Loc_messages_destroy, _Loc_messages_name, messages_hash);
}

__STL_END_NAMESPACE
