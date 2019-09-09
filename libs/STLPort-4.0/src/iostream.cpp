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

#include <string>
#include <istream>
#include <ostream>
#include <fstream>
#include <locale>
#include <stl/stdio_streambuf>

__STL_BEGIN_NAMESPACE

#if defined (__BORLANDC__)
using __STL_VENDOR_CSTD::_streams;
#endif

// Good guess for having problems with global
// native iostream objects is the absence of new-style ones
# ifdef __STL_HAS_NO_NEW_IOSTREAMS
#  define GLOBAL_NATIVE_STREAM_OBJECTS
#  ifndef __STL_NO_WCHAR_T
#   define GLOBAL_NATIVE_WIDE_STREAM_OBJECTS
#  endif
# endif

#if !defined(__STL_NO_FORCE_INSTANTIATE)

// instantiations
template class __STL_CLASS_DECLSPEC istreambuf_iterator<char, char_traits<char> >;
template class __STL_CLASS_DECLSPEC ostreambuf_iterator<char, char_traits<char> >;

template  class __STL_CLASS_DECLSPEC basic_ostream<char, char_traits<char> >;

# if defined (__STL_USE_TEMPLATE_EXPORT)
template  class __STL_CLASS_DECLSPEC _Osentry<char, char_traits<char> >;
template  class __STL_CLASS_DECLSPEC _Isentry<char, char_traits<char> >;
# endif

template  class __STL_CLASS_DECLSPEC basic_istream<char, char_traits<char> >;
template  class __STL_CLASS_DECLSPEC basic_iostream<char, char_traits<char> >;

#ifndef __STL_NO_WCHAR_T

template class __STL_CLASS_DECLSPEC ostreambuf_iterator<wchar_t, char_traits<wchar_t> >;
template class __STL_CLASS_DECLSPEC  istreambuf_iterator<wchar_t, char_traits<wchar_t> >;

# if defined (__STL_USE_TEMPLATE_EXPORT)
template class __STL_CLASS_DECLSPEC _Osentry<wchar_t, char_traits<wchar_t> >;
template class __STL_CLASS_DECLSPEC _Isentry<wchar_t, char_traits<wchar_t> >;
# endif

template class __STL_CLASS_DECLSPEC basic_ostream<wchar_t, char_traits<wchar_t> >;
template class __STL_CLASS_DECLSPEC basic_istream<wchar_t, char_traits<wchar_t> >;
template class __STL_CLASS_DECLSPEC basic_iostream<wchar_t, char_traits<wchar_t> >;
#endif /* INSTANTIATE_WIDE_STREAMS */

#endif

// This file handles iostream initialization.  It is inherently
// nonportable, since the C++ language definition provides no mechanism
// for controlling order of initialization of nonlocal objects.  
// Initialization has three parts, which must be performed in the following
// order:
//  (1) Initialize the locale system by calling __initialize_locales()
//  (2) Call the constructors for the eight global stream objects.
//  (3) Create streambufs for the global stream objects, and initialize
//      the stream objects by calling the init() member function.


#if defined (__STL_MSVC) || defined(__MWERKS__) || defined (__ICL)

// Definitions of the eight global I/O objects that are declared in 
// <iostream>. For VC++ we use the init_seg pragma to put the global I/O
// objects into an intitialization segement that will not
// be executed. We then explicitly invoke the constructors
// with placement new in ios_base::_S_initialize() 

#if defined(__MWERKS__)
# pragma suppress_init_code on
#else
# pragma init_seg("SGI_STL_NO_INIT")
#endif

__STL_DECLSPEC istream cin(0);
__STL_DECLSPEC ostream cout(0);
__STL_DECLSPEC ostream cerr(0);
__STL_DECLSPEC ostream clog(0);

__STL_DECLSPEC wistream wcin(0);
__STL_DECLSPEC wostream wcout(0);
__STL_DECLSPEC wostream wcerr(0);
__STL_DECLSPEC wostream wclog(0);

#if defined(__MWERKS__)
# pragma suppress_init_code off
#endif

#else


// Definitions of the eight global I/O objects that are declared in 
// <iostream>.  Disgusting hack: we deliberately define them with the
// wrong types so that the constructors don't get run automatically.
// We need special tricks to make sure that these objects are struct-
// aligned rather than byte-aligned.

// This is not portable.  Declaring a variable with different types in
// two translations units is "undefined", according to the C++ standard.
// Most compilers, however, silently accept this instead of diagnosing
// it as an error.

template<class T>
union _Stl_aligned_buffer {
  char buf[sizeof(T)];
  struct { double a; double b; } padding;
};

__STL_DECLSPEC _Stl_aligned_buffer<istream> cin;
__STL_DECLSPEC _Stl_aligned_buffer<ostream> cout;
__STL_DECLSPEC _Stl_aligned_buffer<ostream> cerr;
__STL_DECLSPEC _Stl_aligned_buffer<ostream> clog;

# ifndef __STL_NO_WCHAR_T

__STL_DECLSPEC _Stl_aligned_buffer<wistream> wcin;
__STL_DECLSPEC _Stl_aligned_buffer<wostream> wcout;
__STL_DECLSPEC _Stl_aligned_buffer<wostream> wcerr;
__STL_DECLSPEC _Stl_aligned_buffer<wostream> wclog;

# endif

# ifdef GLOBAL_NATIVE_STREAM_OBJECTS

_Stl_aligned_buffer<istream> saved_cin;
_Stl_aligned_buffer<ostream> saved_cout;
_Stl_aligned_buffer<ostream> saved_cerr;
_Stl_aligned_buffer<ostream> saved_clog;

# ifndef __STL_NO_WCHAR_T

_Stl_aligned_buffer<wistream> saved_wcin;
_Stl_aligned_buffer<wostream> saved_wcout;
_Stl_aligned_buffer<wostream> saved_wcerr;
_Stl_aligned_buffer<wostream> saved_wclog;

# endif
# endif /* GLOBAL */
#endif /* STL_MSVC || __MWERKS__ */

// Member functions from class ios_base and ios_base::Init

long ios_base::Init::_S_count = 0;

filebuf*
_Stl_create_filebuf(FILE* f, ios_base::openmode mode )
{
  basic_filebuf<char, char_traits<char> >* result;
  
  result = new basic_filebuf<char, char_traits<char> >();

  try {
    result->open(_FILE_fd(*f), mode);
  }
  catch(...) {}

  if (!result->is_open()) {
    delete result;
    result = 0;
  }
  return result;
}

# ifndef __STL_NO_WCHAR_T

wfilebuf*
_Stl_create_wfilebuf(FILE* f, ios_base::openmode mode )
{
  basic_filebuf<wchar_t, char_traits<wchar_t> >* result;
  
  result = new basic_filebuf<wchar_t, char_traits<wchar_t> >();

  try {
    result->open(_FILE_fd(*f), mode);
  }
  catch(...) {}

  if (!result->is_open()) {
    delete result;
    result = 0;
  }
  return result;
}

# endif

void  __STL_CALL ios_base::_S_initialize()
{
# ifndef __STL_HAS_NO_NAMESPACES
  using SGI::stdio_istreambuf;
  using SGI::stdio_ostreambuf;
# endif
  // Initialize the locale system.
  locale::_S_initialize();

  __STL_TRY {
    // Run constructors for the four narrow stream objects.
# if defined(__STL_MSVC) || defined(__MWERKS__) || defined (__ICL)
    istream* ptr_cin  = new(&cin)  istream(0);
    ostream* ptr_cout = new(&cout) ostream(0);
    ostream* ptr_cerr = new(&cerr) ostream(0);
    ostream* ptr_clog = new(&clog) ostream(0);
# else

# ifdef GLOBAL_NATIVE_STREAM_OBJECTS
    memcpy(saved_cin.buf, cin.buf, sizeof(cin));
    memcpy(saved_cout.buf, cout.buf, sizeof(cout));
    memcpy(saved_cerr.buf, cerr.buf, sizeof(cerr));
    memcpy(saved_clog.buf, clog.buf, sizeof(clog));
# endif

    istream* ptr_cin  = new(cin.buf)  istream(0);
    ostream* ptr_cout = new(cout.buf) ostream(0);
    ostream* ptr_cerr = new(cerr.buf) ostream(0);
    ostream* ptr_clog = new(clog.buf) ostream(0);
# endif
    // Initialize the four narrow stream objects.
    ptr_cin->init(new stdio_istreambuf(stdin));
    ptr_cout->init(new stdio_ostreambuf(stdout));
    ptr_cerr->init(new stdio_ostreambuf(stderr));
    ptr_clog->init(new stdio_ostreambuf(stderr));

    ptr_cin->tie(ptr_cout);
    ptr_cerr->setf(ios_base::unitbuf);

# ifndef __STL_NO_WCHAR_T

# if defined(__STL_MSVC) || defined(__MWERKS__) || defined (__ICL)
    // Run constructors for the four wide stream objects.
    wistream* ptr_wcin  = new(&wcin)  wistream(0);
    wostream* ptr_wcout = new(&wcout) wostream(0);
    wostream* ptr_wcerr = new(&wcerr) wostream(0);
    wostream* ptr_wclog = new(&wclog) wostream(0);
# else


# ifdef GLOBAL_NATIVE_WIDE_STREAM_OBJECTS
    memcpy(saved_wcin.buf, wcin.buf, sizeof(wcin));
    memcpy(saved_wcout.buf, wcout.buf, sizeof(wcout));
    memcpy(saved_wcerr.buf, wcerr.buf, sizeof(wcerr));
    memcpy(saved_wclog.buf, wclog.buf, sizeof(wclog));
# endif

    // Run constructors for the four wide stream objects.
    wistream* ptr_wcin  = new(wcin.buf)  wistream(0);
    wostream* ptr_wcout = new(wcout.buf) wostream(0);
    wostream* ptr_wcerr = new(wcerr.buf) wostream(0);
    wostream* ptr_wclog = new(wclog.buf) wostream(0);

# endif /*__STL_MSVC */
    
    wfilebuf* win  = _Stl_create_wfilebuf(stdin, ios_base::in);
    wfilebuf* wout = _Stl_create_wfilebuf(stdout, ios_base::out);;
    wfilebuf* werr = _Stl_create_wfilebuf(stderr, ios_base::out);
    wfilebuf* wlog = _Stl_create_wfilebuf(stderr, ios_base::out);
    
    ptr_wcin->init(win);
    ptr_wcout->init(wout);
    ptr_wcerr->init(werr);
    ptr_wclog->init(wlog);

    ptr_wcin->tie(ptr_wcout);
    ptr_wcerr->setf(ios_base::unitbuf);
    
# endif /*  __STL_NO_WCHAR_T */

  }

  __STL_CATCH_ALL {}
}

void __STL_CALL ios_base::_S_uninitialize()
{
  // Note that destroying output streambufs flushes the buffers.

  istream* ptr_cin  = __REINTERPRET_CAST(istream*,&cin);
  ostream* ptr_cout = __REINTERPRET_CAST(ostream*,&cout);
  ostream* ptr_cerr = __REINTERPRET_CAST(ostream*,&cerr);
  ostream* ptr_clog = __REINTERPRET_CAST(ostream*,&clog);

# ifndef __STL_NO_WCHAR_T
  wistream* ptr_wcin  = __REINTERPRET_CAST(wistream*,&wcin);
  wostream* ptr_wcout = __REINTERPRET_CAST(wostream*,&wcout);
  wostream* ptr_wcerr = __REINTERPRET_CAST(wostream*,&wcerr);
  wostream* ptr_wclog = __REINTERPRET_CAST(wostream*,&wclog);
# endif

  delete ptr_cin->rdbuf(0);
  delete ptr_cout->rdbuf(0);
  delete ptr_cerr->rdbuf(0);
  delete ptr_clog->rdbuf(0);

  _Destroy(ptr_cin);
  _Destroy(ptr_cout);
  _Destroy(ptr_cerr);
  _Destroy(ptr_clog);

# ifndef __STL_NO_WCHAR_T
  delete ptr_wcin->rdbuf(0);
  delete ptr_wcout->rdbuf(0);
  delete ptr_wcerr->rdbuf(0);
  delete ptr_wclog->rdbuf(0);

  _Destroy(ptr_wcin);
  _Destroy(ptr_wcout);
  _Destroy(ptr_wcerr);
  _Destroy(ptr_wclog);

# endif

  // Shut down the locale subsystem.
  locale::_S_uninitialize();
# ifdef GLOBAL_NATIVE_STREAM_OBJECTS
    memcpy(cin.buf,  saved_cin.buf, sizeof(cin));
    memcpy(cout.buf, saved_cout.buf, sizeof(cout));
    memcpy(cerr.buf, saved_cerr.buf, sizeof(cerr));
    memcpy(clog.buf, saved_clog.buf, sizeof(clog));
# endif

# ifdef GLOBAL_NATIVE_WIDE_STREAM_OBJECTS
    memcpy(wcin.buf,  saved_wcin.buf, sizeof(wcin));
    memcpy(wcout.buf, saved_wcout.buf, sizeof(wcout));
    memcpy(wcerr.buf, saved_wcerr.buf, sizeof(wcerr));
    memcpy(wclog.buf, saved_wclog.buf, sizeof(wclog));
# endif
}


bool __STL_CALL ios_base::sync_with_stdio(bool sync) {
# ifndef __STL_HAS_NO_NAMESPACES
  using SGI::stdio_istreambuf;
  using SGI::stdio_ostreambuf;
# endif
  istream* ptr_cin  = __REINTERPRET_CAST(istream*,&cin);
  ostream* ptr_cout = __REINTERPRET_CAST(ostream*,&cout);
  ostream* ptr_cerr = __REINTERPRET_CAST(ostream*,&cerr);
  ostream* ptr_clog = __REINTERPRET_CAST(ostream*,&clog);

  streambuf* old_cin  = ptr_cin->rdbuf();
  streambuf* old_cout = ptr_cout->rdbuf();
  streambuf* old_cerr = ptr_cerr->rdbuf();
  streambuf* old_clog = ptr_clog->rdbuf();
  bool was_synced = old_cin != 0 &&
                    __DYNAMIC_CAST(stdio_istreambuf*,old_cin) != 0;

  streambuf* new_cin  = 0;
  streambuf* new_cout = 0;
  streambuf* new_cerr = 0;
  streambuf* new_clog = 0;

  try {
    if (sync && !was_synced) {
      new_cin  = new stdio_istreambuf(stdin);
      new_cout = new stdio_ostreambuf(stdout);
      new_cerr = new stdio_ostreambuf(stderr);
      new_clog = new stdio_ostreambuf(stderr);
    }
    else if (!sync && was_synced) {
      new_cin  = _Stl_create_filebuf(stdin, ios_base::in);
      new_cout = _Stl_create_filebuf(stdout, ios_base::out);
      new_cerr = _Stl_create_filebuf(stderr, ios_base::out);
      new_clog = _Stl_create_filebuf(stderr, ios_base::out);
    }
  }
  catch(...) {}

  if (new_cin && new_cout && new_cerr && new_clog) {
    ptr_cin->rdbuf(new_cin);
    ptr_cout->rdbuf(new_cout);
    ptr_cerr->rdbuf(new_cerr);
    ptr_clog->rdbuf(new_clog);

    delete old_cin;
    delete old_cout;
    delete old_cerr;
    delete old_clog;
  }
  else {
    delete new_cin;
    delete new_cout;
    delete new_cerr;
    delete new_clog;
  }

  return was_synced;
}

__STL_END_NAMESPACE


// Local Variables:
// mode:C++
// End:
