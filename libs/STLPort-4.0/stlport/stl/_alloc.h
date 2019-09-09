/*
 *
 * Copyright (c) 1996,1997
 * Silicon Graphics Computer Systems, Inc.
 *
 * Copyright (c) 1997
 * Moscow Center for SPARC Technology
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

/* NOTE: This is an internal header file, included by other STL headers.
 *   You should not attempt to use it directly.
 */

#ifndef __SGI_STL_INTERNAL_ALLOC_H
#define __SGI_STL_INTERNAL_ALLOC_H


// This implements some standard node allocators.  These are
// NOT the same as the allocators in the C++ draft standard or in
// in the original STL.  They do not encapsulate different pointer
// types; indeed we assume that there is only one pointer type.
// The allocation primitives are intended to allocate individual objects,
// not larger arenas as with the original STL allocators.

# ifndef __STLPORT_CSTDDEF
#  include <cstddef>
# endif

#if !defined (__STLPORT_DEBUG_H) && (defined  (__STL_DEBUG) || defined (__STL_ASSERTIONS))
# include <stl/debug/_debug.h>
#endif

# ifndef __STLPORT_CSTDLIB
#  include <cstdlib>
# endif
# ifndef __STLPORT_CSTRING
#  include <cstring>
# endif

# ifndef __THROW_BAD_ALLOC
#  if !defined(__STL_USE_EXCEPTIONS)
#   if !defined (__STLPORT_CSTDIO)
#    include <cstdio>
#   endif
#   if !defined (__STLPORT_CSTDLIB)
#    include <cstdlib>
#   endif
#   define __THROW_BAD_ALLOC fprintf(stderr, "out of memory\n"); exit(1)
#  else /* !defined(__STL_USE_EXCEPTIONS) */
#   define __THROW_BAD_ALLOC throw __STLPORT_STD::bad_alloc()
#  endif /* !defined(__STL_USE_EXCEPTIONS) */
# endif   /* __THROW_BAD_ALLOC */

# ifndef __STLPORT_NEW
#  include <new>
# endif

#if defined (__STL_THREADS) && ! defined (__SGI_STL_INTERNAL_THREADS_H)
# include <stl/_threads.h>
#endif

// #ifndef __TYPE_TRAITS_H
// # include <stl/type_traits.h>
// #endif

#ifndef __SGI_STL_INTERNAL_CONSTRUCT_H
# include <stl/_construct.h>
#endif

#ifndef __ALLOC
#   define __ALLOC __sgi_alloc
#endif

# ifndef __RESTRICT
#  define __RESTRICT
# endif

# if defined ( __STL_USE_ABBREVS )
// ugliness is intentional - to reduce conflicts probability
#  define __malloc_alloc   M__A
#  define __node_alloc     D__A
#  define __new_alloc      N__A
#  define __debug_alloc    G__A
# endif

#if defined (__STL_THREADS) || (defined(__SGI_STL_OWN_IOSTREAMS) && ! defined (__STL_NO_THREADS) && ! defined (_NOTHREADS) )
# define __NODE_ALLOCATOR_THREADS true
#else
# define __NODE_ALLOCATOR_THREADS false
#endif

# ifdef __STL_SGI_THREADS
  // We test whether threads are in use before locking.
  // Perhaps this should be moved into stl_threads.h, but that
  // probably makes it harder to avoid the procedure call when
  // it isn't needed.
    extern "C" {
      extern int __us_rsthread_malloc;
    }
// The above is copied from malloc.h.  Including <malloc.h>
// would be cleaner but fails with certain levels of standard
// conformance.
# endif

__STL_BEGIN_NAMESPACE

template <class _Tp, class _Alloc>
struct __allocator;

// Malloc-based allocator.  Typically slower than default alloc below.
// Typically thread-safe and more storage efficient.

typedef void (* __oom_handler_type)();

template <int __inst>
class __malloc_alloc {
private:

  static void* __STL_CALL _S_oom_malloc(size_t);
  //  static void* __STL_CALL _S_oom_realloc(void*, size_t);

  static __oom_handler_type __oom_handler;

public:
  // this one is needed for proper simple_alloc wrapping
  typedef char value_type;

# if defined (__STL_MEMBER_TEMPLATE_CLASSES) && defined (__STL_USE_RAW_SGI_ALLOCATORS)
  template <class _Tp1> struct rebind {
    typedef __allocator<_Tp1, __malloc_alloc<__inst> > other;
  };
# endif

  static void* __STL_CALL allocate(size_t __n)
    {
      void* __result = malloc(__n);
      if (0 == __result) __result = _S_oom_malloc(__n);
      return __result;
    }

  static void __STL_CALL deallocate(void* __p, size_t /* __n */)
    {
      free((char*)__p);
    }

  static __oom_handler_type __STL_CALL set_malloc_handler(__oom_handler_type __f)
    {
      __oom_handler_type __old = __oom_handler;
      __oom_handler = __f;
      return(__old);
    }
    
};


// New-based allocator.  Typically slower than default alloc below.
// Typically thread-safe and more storage efficient.
class __STL_CLASS_DECLSPEC __new_alloc {
public:
  // this one is needed for proper simple_alloc wrapping
  typedef char value_type;
# if defined (__STL_MEMBER_TEMPLATE_CLASSES)  && defined(__STL_USE_RAW_SGI_ALLOCATORS)
  template <class _Tp1> struct rebind {
    typedef __allocator<_Tp1, __new_alloc > other;
  };
# endif
  static void* __STL_CALL  allocate(size_t __n) { 
    return __stl_new(__n);
  }
  static void __STL_CALL deallocate(void* __p, size_t) { 
    __stl_delete(__p);
  }
};


// Allocator adaptor to check size arguments for debugging.
// Reports errors using assert.  Checking can be disabled with
// NDEBUG, but it's far better to just use the underlying allocator
// instead when no checking is desired.
// There is some evidence that this can confuse Purify.
// This adaptor can only be applied to raw allocators

template <class _Alloc>
class __debug_alloc : public _Alloc {
public:
  typedef _Alloc __allocator_type;
  typedef typename _Alloc::value_type value_type;
private:
  struct __alloc_header {
    size_t __magic: 16;
    size_t __type_size:16;
    __STL_UINT32_T _M_size;
  }; // that is 8 bytes for sure
  // Sunpro CC has bug on enums, so extra_before/after set explicitly
  enum { __pad=8, __magic=0xdeba, __deleted_magic = 0xdebd,
	 __shred_byte= __STL_SHRED_BYTE
  };

  enum { __extra_before = 16, __extra_after = 8 };
  // Size of space used to store size.  Note
  // that this must be large enough to preserve
  // alignment.
  static size_t __STL_CALL __extra_before_chunk() {
    return (long)__extra_before/sizeof(value_type)+
      (size_t)((long)__extra_before%sizeof(value_type)>0);
  }
  static size_t __STL_CALL __extra_after_chunk() {
    return (long)__extra_after/sizeof(value_type)+
      (size_t)((long)__extra_after%sizeof(value_type)>0);
  }
public:

# if defined (__STL_MEMBER_TEMPLATE_CLASSES) && defined (__STL_USE_RAW_SGI_ALLOCATORS)
  template <class _Tp1> struct rebind {
    typedef __allocator< _Tp1, __debug_alloc<_Alloc> > other;
  };
# endif

  //  __debug_alloc(const _Alloc&);
  __debug_alloc() {}
  ~__debug_alloc() {}
  static void * __STL_CALL allocate(size_t);
  static void __STL_CALL deallocate(void *, size_t);
};


// Default node allocator.
// With a reasonable compiler, this should be roughly as fast as the
// original STL class-specific allocators, but with less fragmentation.
// Default_alloc_template parameters are experimental and MAY
// DISAPPEAR in the future.  Clients should just use alloc for now.
//
// Important implementation properties:
// 1. If the client request an object of size > _MAX_BYTES, the resulting
//    object will be obtained directly from malloc.
// 2. In all other cases, we allocate an object of size exactly
//    _S_round_up(requested_size).  Thus the client has enough size
//    information that we can return the object to the proper free list
//    without permanently losing part of the object.
//

// The first template parameter specifies whether more than one thread
// may use this allocator.  It is safe to allocate an object from
// one instance of a default_alloc and deallocate it with another
// one.  This effectively transfers its ownership to the second one.
// This may have undesirable effects on reference locality.
// The second parameter is unreferenced and serves only to allow the
// creation of multiple default_alloc instances.

# if defined(__OS400__)
enum {_ALIGN = 16, _ALIGN_SHIFT=4, _MAX_BYTES = 256};
#  define  _NFREELISTS 16
# else
enum {_ALIGN = 8, _ALIGN_SHIFT=3, _MAX_BYTES = 128};
// SunPro CC 4.0.1 has bug on enums
//  enum {_NFREELISTS = _MAX_BYTES/_ALIGN};
#  define  _NFREELISTS 16
# endif /* __OS400__ */

class __STL_CLASS_DECLSPEC _Node_alloc_obj {
public:
    _Node_alloc_obj * _M_free_list_link;
};


template <bool __threads, int __inst>
class __node_alloc {
  __PRIVATE:
  static inline size_t __STL_CALL
  _S_round_up(size_t __bytes) 
    { return (((__bytes) + (size_t)_ALIGN-1) & ~((size_t)_ALIGN - 1)); }

  typedef _Node_alloc_obj _Obj;

private:

  // Returns an object of size __n, and optionally adds to size __n free list.
  static void*  __STL_CALL _S_refill(size_t __n);
  // Allocates a chunk for nobjs of size size.  nobjs may be reduced
  // if it is inconvenient to allocate the requested number.
  static char*  __STL_CALL _S_chunk_alloc(size_t __p_size, int& __nobjs);


  // Chunk allocation state.
  static _Node_alloc_obj * __STL_VOLATILE _S_free_list[_NFREELISTS]; 
  static char* _S_start_free;
  static char* _S_end_free;
  static size_t _S_heap_size;

public:
  // this one is needed for proper simple_alloc wrapping
  typedef char value_type;

# if defined (__STL_MEMBER_TEMPLATE_CLASSES) && defined (__STL_USE_RAW_SGI_ALLOCATORS)
  template <class _Tp1> struct rebind {
    typedef __allocator<_Tp1, __node_alloc<__threads, __inst> > other;
  };
# endif
  /* __n must be > 0      */
  static void * __STL_CALL allocate(size_t __n);
  /* __p may not be 0 */
  static void __STL_CALL deallocate(void *__p, size_t __n);
} ;

# if defined (__STL_USE_TEMPLATE_EXPORT)
__STL_EXPORT_TEMPLATE_CLASS __malloc_alloc<0>;
__STL_EXPORT_TEMPLATE_CLASS __node_alloc<__NODE_ALLOCATOR_THREADS, 0>;
# endif /* __STL_USE_TEMPLATE_EXPORT */
typedef __node_alloc<__NODE_ALLOCATOR_THREADS, 0> _Node_alloc;
# if defined (__STL_USE_TEMPLATE_EXPORT)
__STL_EXPORT_TEMPLATE_CLASS __debug_alloc<_Node_alloc>;
__STL_EXPORT_TEMPLATE_CLASS __debug_alloc<__new_alloc>;
__STL_EXPORT_TEMPLATE_CLASS __debug_alloc<__malloc_alloc<0> >;
# endif

# if defined ( __STL_USE_NEWALLOC )
#  if defined ( __STL_DEBUG_ALLOC )
typedef __debug_alloc<__new_alloc> __sgi_alloc;
#  else
typedef __new_alloc __sgi_alloc;
#  endif /* __STL_DEBUG_ALLOC */

typedef __new_alloc __single_client_alloc;
typedef __new_alloc __multithreaded_alloc;

#  elif defined (__STL_USE_MALLOC)
#   if defined ( __STL_DEBUG_ALLOC )
typedef __debug_alloc<__malloc_alloc<0> > __sgi_alloc;
#   else
typedef __malloc_alloc<0> __sgi_alloc;
#   endif /* __STL_DEBUG_ALLOC */
typedef __malloc_alloc<0> __single_client_alloc;
typedef __malloc_alloc<0> __multithreaded_alloc;
# else
#   if defined ( __STL_DEBUG_ALLOC )
typedef __debug_alloc<_Node_alloc> __sgi_alloc;
#   else
typedef _Node_alloc __sgi_alloc;
#   endif

typedef __node_alloc<false, 0> __single_client_alloc;
typedef __node_alloc<true, 0>  __multithreaded_alloc;

#  endif /* __STL_USE_NEWALLOC */

// This implements allocators as specified in the C++ standard.  
//
// Note that standard-conforming allocators use many language features
// that are not yet widely implemented.  In particular, they rely on
// member templates, partial specialization, partial ordering of function
// templates, the typename keyword, and the use of the template keyword
// to refer to a template member of a dependent type.

template <class _Tp>
class __STL_CLASS_DECLSPEC allocator {
public:

  typedef _Tp        value_type;
  typedef value_type *       pointer;
  typedef const _Tp* const_pointer;
  typedef _Tp&       reference;
  typedef const _Tp& const_reference;
  typedef size_t     size_type;
  typedef ptrdiff_t  difference_type;


# if defined (__STL_MEMBER_TEMPLATE_CLASSES)
  template <class _Tp1> struct rebind {
    typedef allocator<_Tp1> other;
  };
# endif

  allocator() __STL_NOTHROW {}

 # if defined (__STL_MEMBER_TEMPLATES)
  template <class _Tp1> allocator(const allocator<_Tp1>&) __STL_NOTHROW {}
 # endif
    
  allocator(const allocator<_Tp>&) __STL_NOTHROW {}
    
  ~allocator() __STL_NOTHROW {}

  pointer address(reference __x) { return &__x; }

  const_pointer address(const_reference __x) const { return &__x; }

  // __n is permitted to be 0.  The C++ standard says nothing about what
  // the return value is when __n == 0.
  _Tp* allocate(size_type __n, const void* = 0) const {
    return __n != 0 ? __REINTERPRET_CAST(value_type*,__sgi_alloc::allocate(__n * sizeof(value_type))) 
                    : 0;
  }

  // __p is permitted to be a null pointer, only if n==0.
  void deallocate(pointer __p, size_type __n) const {
    __STL_ASSERT( (__p == 0) == (__n == 0) )
      if (__p != 0) 
      __sgi_alloc::deallocate((void*)__p, __n * sizeof(value_type));
  }

  // backwards compatibility
  void deallocate(pointer __p) const
  {  if (__p != 0) __sgi_alloc::deallocate((void*)__p, sizeof(value_type)); }

  size_type max_size() const __STL_NOTHROW 
    { return size_t(-1) / sizeof(value_type); }

  void construct(pointer __p, const _Tp& __val) const { __STLPORT_STD::construct(__p, __val); }
  void destroy(pointer __p) const { __STLPORT_STD::destroy(__p); }
};

__STL_TEMPLATE_NULL
class __STL_CLASS_DECLSPEC allocator<void> {
public:
  typedef size_t      size_type;
  typedef ptrdiff_t   difference_type;
  typedef void*       pointer;
  typedef const void* const_pointer;
# if defined (__STL_CLASS_PARTIAL_SPECIALIZATION)
  typedef void        value_type;
# endif
# if defined (__STL_MEMBER_TEMPLATE_CLASSES)
  template <class _Tp1> struct rebind {
    typedef allocator<_Tp1> other;
  };
# endif
};


template <class _T1, class _T2>
inline bool  __STL_CALL operator==(const allocator<_T1>&, const allocator<_T2>&) 
{
  return true;
}

template <class _T1, class _T2>
inline bool  __STL_CALL operator!=(const allocator<_T1>&, const allocator<_T2>&)
{
  return false;
}

# if defined (__STL_USE_TEMPLATE_EXPORT)
__STL_EXPORT_TEMPLATE_CLASS allocator<char>;
#  if defined (__STL_HAS_WCHAR_T)
__STL_EXPORT_TEMPLATE_CLASS allocator<wchar_t>;
#  endif

# endif /* __STL_USE_TEMPLATE_EXPORT */

template<class _Tp, class _Alloc>
class __simple_alloc {
  typedef _Alloc __alloc_type;
public:

  typedef typename _Alloc::value_type __alloc_value_type;
  typedef _Tp value_type;

  static size_t  __STL_CALL __chunk(size_t __n) { 
    return (sizeof(__alloc_value_type)==sizeof(value_type)) ? __n : 
	    ((__n*sizeof(value_type)+sizeof(__alloc_value_type)-1)/sizeof(__alloc_value_type));
  }
  static _Tp*  __STL_CALL allocate(size_t __n)
    { return 0 == __n ? 0 : (_Tp*) __alloc_type::allocate(__chunk(__n)); }

  static void  __STL_CALL deallocate(_Tp * __p, size_t __n) { 
    __alloc_type::deallocate((__alloc_value_type*)__p, __chunk(__n)); }
};

# ifndef __STL_NO_EXTENSIONS
// Allocator adaptor to turn an SGI-style allocator (e.g. alloc, malloc_alloc)
// into a standard-conforming allocator.   Note that this adaptor does
// *not* assume that all objects of the underlying alloc class are
// identical, nor does it assume that all of the underlying alloc's
// member functions are static member functions.  Note, also, that 
// __allocator<_Tp, alloc> is essentially the same thing as allocator<_Tp>.

template <class _Tp, class _Alloc>
struct __allocator : public _Alloc {
  typedef _Alloc __underlying_alloc;

  typedef size_t    size_type;
  typedef ptrdiff_t difference_type;
  typedef _Tp*       pointer;
  typedef const _Tp* const_pointer;
  typedef _Tp&       reference;
  typedef const _Tp& const_reference;
  typedef _Tp        value_type;

# if defined (__STL_MEMBER_TEMPLATE_CLASSES)
  template <class _Tp1> struct rebind {
    typedef __allocator<_Tp1, _Alloc> other;
  };
# endif
  __allocator() __STL_NOTHROW {}
  __allocator(const _Alloc& ) __STL_NOTHROW {}
  __allocator(const __allocator<_Tp, _Alloc>& __a) __STL_NOTHROW
    : _Alloc(__a) {}
# if defined (__STL_MEMBER_TEMPLATES) && defined (__STL_FUNCTION_TMPL_PARTIAL_ORDER)
  template <class _Tp1> 
  __allocator(const __allocator<_Tp1, _Alloc>& __a) __STL_NOTHROW
    : _Alloc(__a) {}
# endif
  ~__allocator() __STL_NOTHROW {}

  pointer address(reference __x) const { return &__x; }

# if !defined (__WATCOM_CPLUSPLUS__)
  const_pointer address(const_reference __x) const { return &__x; }
# endif

  // __n is permitted to be 0.
  _Tp* allocate(size_type __n, const void* = 0) {
    return __n != 0 
        ? __STATIC_CAST(_Tp*,__underlying_alloc::allocate(__n * sizeof(_Tp))) 
        : 0;
  }

  // __p is not permitted to be a null pointer.
  void deallocate(pointer __p, size_type __n)
    { if (__p) __underlying_alloc::deallocate(__p, __n * sizeof(_Tp)); }

  size_type max_size() const __STL_NOTHROW 
    { return size_t(-1) / sizeof(_Tp); }

  void construct(pointer __p, const _Tp& __val) { __STLPORT_STD::construct(__p, __val); }
  void destroy(pointer __p) { __STLPORT_STD::destroy(__p); }

  const __underlying_alloc& __get_underlying_alloc() const { return *this; }
};

#ifdef __STL_CLASS_PARTIAL_SPECIALIZATION
template <class _Alloc>
class __allocator<void, _Alloc> {
  typedef size_t      size_type;
  typedef ptrdiff_t   difference_type;
  typedef void*       pointer;
  typedef const void* const_pointer;
  typedef void        value_type;
#ifdef __STL_MEMBER_TEMPLATE_CLASSES
  template <class _Tp1> struct rebind {
    typedef __allocator<_Tp1, _Alloc> other;
  };
#endif
};
#endif

template <class _Tp, class _Alloc>
inline bool  __STL_CALL operator==(const __allocator<_Tp, _Alloc>& __a1,
                                   const __allocator<_Tp, _Alloc>& __a2)
{
  return __a1.__get_underlying_alloc() == __a2.__get_underlying_alloc();
}

#ifdef __STL_USE_SEPARATE_RELOPS_NAMESPACE
template <class _Tp, class _Alloc>
inline bool  __STL_CALL operator!=(const __allocator<_Tp, _Alloc>& __a1,
                                   const __allocator<_Tp, _Alloc>& __a2)
{
  return __a1.__get_underlying_alloc() != __a2.__get_underlying_alloc();
}
#endif /* __STL_FUNCTION_TMPL_PARTIAL_ORDER */


// Comparison operators for all of the predifined SGI-style allocators.
// This ensures that __allocator<malloc_alloc> (for example) will
// work correctly.

#ifndef __STL_NON_TYPE_TMPL_PARAM_BUG
template <int inst>
inline bool  __STL_CALL operator==(const __malloc_alloc<inst>&,
                                   const __malloc_alloc<inst>&)
{
  return true;
}

#ifdef __STL_FUNCTION_TMPL_PARTIAL_ORDER
template <int __inst>
inline bool  __STL_CALL operator!=(const __malloc_alloc<__inst>&,
                                   const __malloc_alloc<__inst>&)
{
  return false;
}
#endif /* __STL_FUNCTION_TMPL_PARTIAL_ORDER */

template <bool __threads, int __inst>
inline bool  __STL_CALL operator==(const __node_alloc<__threads, __inst>&,
                                   const __node_alloc<__threads, __inst>&)
{
  return true;
}

#if defined( __STL_FUNCTION_TMPL_PARTIAL_ORDER )

template <bool __threads, int __inst>
inline bool  __STL_CALL operator!=(const __node_alloc<__threads, __inst>&,
                                   const __node_alloc<__threads, __inst>&)
{
  return false;
}
#endif /* __STL_FUNCTION_TMPL_PARTIAL_ORDER */

#endif /* __STL_NON_TYPE_TMPL_PARAM_BUG */

template <class _Alloc>
inline bool  __STL_CALL operator==(const __debug_alloc<_Alloc>&,
                                   const __debug_alloc<_Alloc>&) {
  return true;
}

# ifdef __STL_USE_SEPARATE_RELOPS_NAMESPACE
template <class _Alloc>
inline bool  __STL_CALL operator!=(const __debug_alloc<_Alloc>&,
                                   const __debug_alloc<_Alloc>&) {
  return false;
}
# endif
#endif /* __STL_NO_EXTENSIONS : excluding __allocator */

// Another allocator adaptor: _Alloc_traits.  This serves two
// purposes.  First, make it possible to write containers that can use
// either SGI-style allocators or standard-conforming allocator.
// Second, provide a mechanism so that containers can query whether or
// not the allocator has distinct instances.  If not, the container
// can avoid wasting a word of memory to store an empty object.

// This adaptor uses partial specialization.  The general case of
// _Alloc_traits<_Tp, _Alloc> assumes that _Alloc is a
// standard-conforming allocator, possibly with non-equal instances
// and non-static members.  (It still behaves correctly even if _Alloc
// has static member and if all instances are equal.  Refinements
// affect performance, not correctness.)

// The fully general version.

// fbp: _S_instanceless is unused in STLport
// _Alloc_type is always being used to do allocation/deallocation
// allocator_type is the type being converted to _Allocator when returned
// from Container::get_allocator, unless it is NOT a raw alloc, in which case
// __get_alloc will return __allocator

template <class _Tp, class _Allocator>
struct _Alloc_traits
{
# if defined (__STL_MEMBER_TEMPLATE_CLASSES) 
  typedef typename _Allocator::__STL_TEMPLATE rebind<_Tp> _Rebind_type;
  typedef typename _Rebind_type::other  allocator_type;
# else
  // this is not actually true, used only to pass this type through
  // to dynamic overload selection in _STL_alloc_proxy methods
  typedef _Allocator allocator_type;
# endif
};


#if defined (__STL_CLASS_PARTIAL_SPECIALIZATION)
// The version for the default allocator.

template <class _Tp, class _Tp1>
struct _Alloc_traits<_Tp, allocator<_Tp1> > {
  typedef allocator<_Tp> allocator_type;
};

#  if defined (__STL_USE_RAW_SGI_ALLOCATORS)
// Versions for the predefined SGI-style allocators.
template <class _Tp, int __inst>
struct _Alloc_traits<_Tp, __malloc_alloc<__inst> > {
  typedef __allocator<_Tp, __malloc_alloc<__inst> > allocator_type;
};


template <class _Tp, bool __threads, int __inst>
struct _Alloc_traits<_Tp, __node_alloc<__threads, __inst> > {
  typedef __allocator<_Tp, __node_alloc<__threads, __inst> > 
          allocator_type;
};

template <class _Tp, class _Alloc>
struct _Alloc_traits<_Tp, __debug_alloc<_Alloc> > {
  typedef __allocator<_Tp, __debug_alloc<_Alloc> > allocator_type;
};
#  endif

# ifndef __STL_NO_EXTENSIONS
// Versions for the __allocator adaptor used with the predefined
// SGI-style allocators.

template <class _Tp, class _Tp1, class _Alloc>
struct _Alloc_traits<_Tp, __allocator<_Tp1, _Alloc > > {
  typedef __allocator<_Tp, _Alloc > allocator_type;
};
# endif

#endif /* __STL_CLASS_PARTIAL_SPECIALIZATION */

# if defined (__STL_MEMBER_TEMPLATE_CLASSES) 

// __a may be not rebound, return different type
template <class _Tp, class _Alloc>
inline __STL_TYPENAME_ON_RETURN_TYPE _Alloc_traits<_Tp, _Alloc>::allocator_type  __STL_CALL
__stl_alloc_create(const _Alloc& __a, const _Tp*) {
  typedef typename _Alloc_traits<_Tp, _Alloc>::allocator_type _Rebound_type;
  return _Rebound_type(__a);
}

#else

#  if defined (__STL_USE_RAW_SGI_ALLOCATORS)

// Versions for the predefined SGI-style allocators.
template <class _Tp>
inline __allocator<_Tp, __new_alloc > __STL_CALL
__stl_alloc_create(const __new_alloc&, const _Tp*) {
  return __allocator<_Tp, __new_alloc >();
}
template <class _Tp>
inline __allocator<_Tp, __new_alloc >&  __STL_CALL
__stl_alloc_rebind(__new_alloc& __a, const _Tp*) {
  return (__allocator<_Tp, __new_alloc >&)__a;
}

template <class _Tp, class _Alloc>
inline __allocator<_Tp, __debug_alloc<_Alloc> > __STL_CALL
__stl_alloc_create(const __debug_alloc<_Alloc>&, const _Tp*) {
  return __allocator<_Tp, __debug_alloc<_Alloc> >();
}
template <class _Tp, class _Alloc>
inline __allocator<_Tp, __debug_alloc<_Alloc> >& __STL_CALL
__stl_alloc_rebind(__debug_alloc<_Alloc>& __a, const _Tp*) {
  return (__allocator<_Tp, __debug_alloc<_Alloc> >&)__a;
}

#  if defined (__STL_NON_TYPE_TMPL_PARAM_BUG)

typedef __malloc_alloc<0> __malloc_alloc_dfl;
typedef __node_alloc<false, 0> __single_client_node_alloc;
typedef __node_alloc<true, 0>  __multithreaded_node_alloc;

template <class _Tp>
inline __allocator<_Tp, __malloc_alloc_dfl >& __STL_CALL
__stl_alloc_rebind(__malloc_alloc_dfl& __a, const _Tp*) {
  return (__allocator<_Tp, __malloc_alloc_dfl >&)__a;
}

template <class _Tp>
inline __allocator<_Tp, __single_client_node_alloc >& __STL_CALL
__stl_alloc_rebind(__single_client_node_alloc& __a, const _Tp*) {
  return (__allocator<_Tp, __single_client_node_alloc >&)__a;
}

template <class _Tp>
inline __allocator<_Tp, __multithreaded_node_alloc >& __STL_CALL
__stl_alloc_rebind(__multithreaded_node_alloc& __a, const _Tp*) {
  return (__allocator<_Tp, __multithreaded_node_alloc >&)__a;
}

template <class _Tp>
inline __allocator<_Tp, __malloc_alloc_dfl > __STL_CALL
__stl_alloc_create(const __malloc_alloc_dfl&, const _Tp*) {
  return __allocator<_Tp, __malloc_alloc_dfl > ();
}

template <class _Tp>
inline __allocator<_Tp, __single_client_node_alloc > __STL_CALL
__stl_alloc_create(const __single_client_node_alloc&, const _Tp*) {
  return __allocator<_Tp, __single_client_node_alloc >();
}

template <class _Tp>
inline __allocator<_Tp, __multithreaded_node_alloc > __STL_CALL
__stl_alloc_create(const __multithreaded_node_alloc&, const _Tp*) {
  return __allocator<_Tp, __multithreaded_node_alloc >();
}

#  else

template <class _Tp, int __inst>
inline __allocator<_Tp, __malloc_alloc<__inst> >& __STL_CALL
__stl_alloc_rebind(__malloc_alloc<__inst>& __a, const _Tp*) {
  return (__allocator<_Tp, __malloc_alloc<__inst> >&)__a;
}

template <class _Tp, bool __threads, int __inst>
inline __allocator<_Tp, __node_alloc<__threads, __inst> >& __STL_CALL
__stl_alloc_rebind(__node_alloc<__threads, __inst>& __a, const _Tp*) {
  return (__allocator<_Tp, __node_alloc<__threads, __inst> >&)__a;
}

template <class _Tp, int __inst>
inline __allocator<_Tp, __malloc_alloc<__inst> > __STL_CALL
__stl_alloc_create(const __malloc_alloc<__inst>&, const _Tp*) {
  return __allocator<_Tp, __malloc_alloc<__inst> >();
}

template <class _Tp, bool __threads, int __inst>
inline __allocator<_Tp, __node_alloc<__threads, __inst> > __STL_CALL
__stl_alloc_create(const __node_alloc<__threads, __inst>&, const _Tp*) {
  return __allocator<_Tp, __node_alloc<__threads, __inst> >();
}

#  endif
# endif /* defined (__STL_USE_RAW_SGI_ALLOCATORS) */

// If custom allocators are being used without member template classes support :
// user (on purpose) is forced to define rebind/get operations !!!

template <class _Tp1, class _Tp2>
inline allocator<_Tp2>& __STL_CALL
__stl_alloc_rebind(allocator<_Tp1>& __a, const _Tp2*) {
  return (allocator<_Tp2>&)(__a);
}

template <class _Tp1, class _Tp2>
inline allocator<_Tp2> __STL_CALL
__stl_alloc_create(const allocator<_Tp1>&, const _Tp2*) {
  return allocator<_Tp2>();
}

#  ifndef __STL_NO_EXTENSIONS

template <class _Tp1, class _Alloc, class _Tp2>
inline __allocator<_Tp2, _Alloc>& __STL_CALL
__stl_alloc_rebind(__allocator<_Tp1, _Alloc>& __a, const _Tp2*) {
  return (__allocator<_Tp2, _Alloc>&)__a;
}

template <class _Tp1, class _Alloc, class _Tp2>
inline __allocator<_Tp2, _Alloc> __STL_CALL
__stl_alloc_create(const __allocator<_Tp1, _Alloc>&, const _Tp2*) {
  return __allocator<_Tp2, _Alloc>();
}
#  endif /* __STL_NO_EXTENSIONS */

#endif /* __STL_MEMBER_TEMPLATE_CLASSES */

// inheritance is being used for EBO optimization

template <class _Value, class _Tp, class _MaybeReboundAlloc>
class __STL_CLASS_DECLSPEC _STL_alloc_proxy : public _MaybeReboundAlloc {
private:
  typedef _MaybeReboundAlloc _Base;
  typedef _STL_alloc_proxy<_Value, _Tp, _MaybeReboundAlloc> _Self;
public:
  _Value _M_data;
  // construction/destruction
  inline _STL_alloc_proxy(const _Self& __x) : _MaybeReboundAlloc(__x), _M_data(__x._M_data) {} 
  inline _STL_alloc_proxy(const _MaybeReboundAlloc& __a, _Value __p) : _MaybeReboundAlloc(__a), 
    _M_data(__p) {}
  inline _Self& operator = (const _Self& __x) { _M_data = __x._M_data; return *this; } 
  //  _Self& operator = (const _Value& __x) { _M_data = __x; return *this; } 
  inline _Self& operator = (const _Base& __x) { ((_Base&)*this) = __x; return *this; } 
  //  operator _Value() const { return _M_data; } 
  
  // Unified interface to perform allocate()/deallocate() with limited
  // language support
#if defined (__STL_MEMBER_TEMPLATE_CLASSES)
# if 1 // def __BORLANDC__
  inline _Tp* allocate(size_t __n) { 
    return _Base::allocate(__n);
  }
# else
  __STL_USING_BASE_MEMBER _MaybeReboundAlloc::allocate;
# endif
#else
  // else it is rebound already, and allocate() member is accessible
  inline _Tp* allocate(size_t __n) { 
    return __stl_alloc_rebind(__STATIC_CAST(_Base&,*this),(_Tp*)0).allocate(__n); 
  }
  inline void deallocate(_Tp* __p, size_t __n) { 
    __stl_alloc_rebind(__STATIC_CAST(_Base&, *this),(_Tp*)0).deallocate(__p, __n); 
  }
#endif
};


# if defined (__STL_USE_TEMPLATE_EXPORT)
__STL_EXPORT_TEMPLATE_CLASS _STL_alloc_proxy<char *,char,allocator<char> >;
#  if defined (__STL_HAS_WCHAR_T)
__STL_EXPORT_TEMPLATE_CLASS _STL_alloc_proxy<wchar_t *,wchar_t,allocator<wchar_t> >;
#  endif
# endif /* __STL_USE_TEMPLATE_EXPORT */

__STL_END_NAMESPACE

# if !defined (__STL_LINK_TIME_INSTANTIATION)
#  include <stl/_alloc.c>
# endif

#endif /* __SGI_STL_INTERNAL_ALLOC_H */

// Local Variables:
// mode:C++
// End:

