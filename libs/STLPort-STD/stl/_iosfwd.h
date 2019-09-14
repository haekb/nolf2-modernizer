# ifndef __STL_INTERNAL_IOSFWD
#  define __STL_INTERNAL_IOSFWD

#if defined(__sgi) && !defined(__GNUC__) && !defined(_STANDARD_C_PLUS_PLUS)
#error This header file requires the -LANG:std option
#endif

// This file provides forward declarations of the most important I/O
// classes.  Note that almost all of those classes are class templates,
// with default template arguments.  According to the C++ standard, 
// if a class template is declared more than once in the same scope
// then only one of those declarations may have default arguments.  

// <iosfwd> contains the same declarations as other headers, and including
// both <iosfwd> and (say) <iostream> is permitted.  This means that only
// one header may contain those default template arguments.

// In this implementation, the declarations in <iosfwd> contain default
// template arguments.  All of the other I/O headers include <iosfwd>.

#include <cwchar>              // For mbstate_t
#include <cstddef>             // For ptrdiff_t

#include <stl/type_traits.h> 

#if defined (__STL_UNIX) && defined (__STL_HAS_NO_NEW_C_HEADERS)
#include <sys/types.h>          // For off_t
#endif /* __unix */


__STL_BEGIN_NAMESPACE

template <class _Tp> class allocator;

#define __STL_NULL_CHAR_INIT(_ChT) __STL_DEFAULT_CONSTRUCTED(_ChT)

// template <class _CharT> class char_traits;

#if defined (__sgi) && defined (__STL_HAS_NO_NEW_C_HEADERS) /* IRIX */
typedef off64_t   streamoff;
#elif defined (__unix) && defined (__STL_HAS_NO_NEW_C_HEADERS) /* Other version of UNIX */
typedef off_t     streamoff;
#else /* __unix */
typedef ptrdiff_t streamoff;
#endif /* __STL_HAS_NO_NEW_C_HEADERS */

typedef ptrdiff_t streamsize;

// dwa 12/22/99 - gcc 2.95.2 bug workaround
#ifdef __GNUC__
template <class _StateT> class fpos;
template <class _StateT>
inline bool  __STL_CALL operator==(const fpos<_StateT>& __x, const fpos<_StateT>& __y)
    { return __x._M_pos == __y._M_pos; }
template <class _StateT>
inline bool  __STL_CALL operator!=(const fpos<_StateT>& __x, const fpos<_StateT>& __y)
    { return __x._M_pos != __y._M_pos; }
#endif

// Class fpos, which represents a position within a file.  (The C++
// standard calls for it to be defined in <ios>.  This implementation
// moves it to <iosfwd>, which is included by <ios>.)
template <class _StateT> class fpos
{
public:                         // From table 88 of the C++ standard.
  fpos(streamoff __pos) : _M_pos(__pos), _M_st(__STL_NULL_CHAR_INIT(_StateT)) {}
  fpos() : _M_pos(0), _M_st(__STL_NULL_CHAR_INIT(_StateT)) {}

  operator streamoff() const { return _M_pos; }

// dwa 12/22/99 - gcc 2.95.2 bug workaround
#ifdef __GNUC__
  friend bool operator==<>(const fpos<_StateT>& __x, const fpos<_StateT>& __y);
  friend bool operator!=<>(const fpos<_StateT>& __x, const fpos<_StateT>& __y);
#else
  friend bool  __STL_CALL operator==(const fpos<_StateT>& __x, const fpos<_StateT>& __y)
    { return __x._M_pos == __y._M_pos; }
  friend bool __STL_CALL operator!=(const fpos<_StateT>& __x, const fpos<_StateT>& __y)
    { return __x._M_pos != __y._M_pos; }
#endif
  fpos<_StateT>& operator+=(streamoff __off) {
    _M_pos += __off;
    return *this;
  }
  fpos<_StateT>& operator-=(streamoff __off) {
    _M_pos -= __off;
    return *this;
  }

  fpos<_StateT> operator+(streamoff __off) {
    fpos<_StateT> __tmp(*this);
    __tmp += __off;
    return __tmp;
  }
  fpos<_StateT> operator-(streamoff __off) {
    fpos<_StateT> __tmp(*this);
    __tmp -= __off;
    return __tmp;
  }

public:                         // Manipulation of the state member.
  _StateT state() const { return _M_st; }
  void state(_StateT __st) { _M_st = __st; }
private:
  streamoff _M_pos;
  _StateT _M_st;
};

typedef fpos<mbstate_t> streampos;
typedef fpos<mbstate_t> wstreampos;

__STL_END_NAMESPACE

#include <stl/char_traits.h>

__STL_BEGIN_NAMESPACE

class __STL_CLASS_DECLSPEC ios_base;

template <class _CharT, __DFL_TMPL_PARAM(_Traits , char_traits<_CharT>) >
class __STL_CLASS_DECLSPEC basic_ios;

template <class _CharT, __DFL_TMPL_PARAM(_Traits , char_traits<_CharT>) >
class __STL_CLASS_DECLSPEC basic_streambuf;

template <class _CharT, __DFL_TMPL_PARAM(_Traits , char_traits<_CharT>) >
class __STL_CLASS_DECLSPEC basic_istream;

template <class _CharT, __DFL_TMPL_PARAM(_Traits , char_traits<_CharT>) >
class __STL_CLASS_DECLSPEC basic_ostream;

template <class _CharT, __DFL_TMPL_PARAM(_Traits , char_traits<_CharT>) >
class __STL_CLASS_DECLSPEC basic_iostream;

template <class _CharT, __DFL_TMPL_PARAM( _Traits , char_traits<_CharT>),
          __DFL_TMPL_PARAM(_Allocator , allocator<_CharT>) >
class __STL_CLASS_DECLSPEC basic_stringbuf;

template <class _CharT, __DFL_TMPL_PARAM(_Traits , char_traits<_CharT>),
          __DFL_TMPL_PARAM(_Allocator , allocator<_CharT>) >
class __STL_CLASS_DECLSPEC basic_istringstream;

template <class _CharT, __DFL_TMPL_PARAM(_Traits , char_traits<_CharT>),
          __DFL_TMPL_PARAM(_Allocator , allocator<_CharT>) >
class __STL_CLASS_DECLSPEC basic_ostringstream;

template <class _CharT, __DFL_TMPL_PARAM(_Traits , char_traits<_CharT>),
          __DFL_TMPL_PARAM(_Allocator , allocator<_CharT>) >
class __STL_CLASS_DECLSPEC basic_stringstream;

template <class _CharT, __DFL_TMPL_PARAM(_Traits , char_traits<_CharT>) >
class __STL_CLASS_DECLSPEC basic_filebuf;

template <class _CharT, __DFL_TMPL_PARAM(_Traits , char_traits<_CharT>) >
class __STL_CLASS_DECLSPEC basic_ifstream;

template <class _CharT, __DFL_TMPL_PARAM(_Traits , char_traits<_CharT>) >
class __STL_CLASS_DECLSPEC basic_ofstream;

template <class _CharT, __DFL_TMPL_PARAM(_Traits , char_traits<_CharT>) >
class __STL_CLASS_DECLSPEC basic_fstream;

template <class _CharT, __DFL_TMPL_PARAM(_Traits , char_traits<_CharT>) >
class istreambuf_iterator;

template <class _CharT, __DFL_TMPL_PARAM(_Traits , char_traits<_CharT>) >
class ostreambuf_iterator;

typedef basic_ios<char, char_traits<char> >    ios;

# ifndef __STL_NO_WCHAR_T
typedef basic_ios<wchar_t, char_traits<wchar_t> > wios;
# endif

// Forward declaration of class locale, and of the most important facets.
class locale;
# ifdef __STL_NO_EXPLICIT_FUNCTION_TMPL_ARGS
template <class _Facet>
struct __STL_CLASS_DECLSPEC _Use_facet {
  const locale& __loc;
  _Use_facet(const locale& __p_loc) : __loc(__p_loc) {}
  inline const _Facet& operator *() const;
};
# define use_facet *_Use_facet
# else
template <class _Facet> inline const _Facet& use_facet(const locale&);
# endif

template <class _CharT> class ctype;
template <class _CharT> class ctype_byname;
template <class _CharT> class collate;
template <class _CharT> class collate_byname;

__STL_TEMPLATE_NULL class __STL_CLASS_DECLSPEC ctype<char>;
__STL_TEMPLATE_NULL class __STL_CLASS_DECLSPEC ctype_byname<char>;
__STL_TEMPLATE_NULL class __STL_CLASS_DECLSPEC collate<char>;
__STL_TEMPLATE_NULL class __STL_CLASS_DECLSPEC collate_byname<char>;

#  ifndef __STL_NO_WCHAR_T
__STL_TEMPLATE_NULL class __STL_CLASS_DECLSPEC ctype<wchar_t>;
__STL_TEMPLATE_NULL class __STL_CLASS_DECLSPEC ctype_byname<wchar_t>;
__STL_TEMPLATE_NULL class __STL_CLASS_DECLSPEC collate<wchar_t>;
__STL_TEMPLATE_NULL class __STL_CLASS_DECLSPEC collate_byname<wchar_t>;
#  endif

# if !(defined (__SUNPRO_CC) && __SUNPRO_CC < 0x500 )
// Typedefs for ordinary (narrow-character) streams.
__STL_TEMPLATE_NULL class __STL_CLASS_DECLSPEC basic_streambuf<char, char_traits<char> >;
# endif

typedef basic_istream<char, char_traits<char> >   istream;
typedef basic_ostream<char, char_traits<char> >   ostream;
typedef basic_iostream<char, char_traits<char> >  iostream;

// # if !(defined (__SUNPRO_CC) && __SUNPRO_CC < 0x500 )
typedef basic_streambuf<char,char_traits<char> > streambuf;
// #endif

typedef basic_stringbuf<char, char_traits<char>, allocator<char> >     stringbuf;
typedef basic_istringstream<char, char_traits<char>, allocator<char> > istringstream;
typedef basic_ostringstream<char, char_traits<char>, allocator<char> > ostringstream;
typedef basic_stringstream<char, char_traits<char>, allocator<char> >  stringstream;

typedef basic_filebuf<char, char_traits<char> >  filebuf;
typedef basic_ifstream<char, char_traits<char> > ifstream;
typedef basic_ofstream<char, char_traits<char> > ofstream;
typedef basic_fstream<char, char_traits<char> >  fstream;

# ifndef __STL_NO_WCHAR_T
// Typedefs for wide-character streams.
typedef basic_streambuf<wchar_t, char_traits<wchar_t> > wstreambuf;
typedef basic_istream<wchar_t, char_traits<wchar_t> >   wistream;
typedef basic_ostream<wchar_t, char_traits<wchar_t> >   wostream;
typedef basic_iostream<wchar_t, char_traits<wchar_t> >  wiostream;

typedef basic_stringbuf<wchar_t, char_traits<wchar_t>, allocator<wchar_t> >     wstringbuf;
typedef basic_istringstream<wchar_t, char_traits<wchar_t>, allocator<wchar_t> > wistringstream;
typedef basic_ostringstream<wchar_t, char_traits<wchar_t>, allocator<wchar_t> > wostringstream;
typedef basic_stringstream<wchar_t, char_traits<wchar_t>, allocator<wchar_t> >  wstringstream;

typedef basic_filebuf<wchar_t, char_traits<wchar_t> >  wfilebuf;
typedef basic_ifstream<wchar_t, char_traits<wchar_t> > wifstream;
typedef basic_ofstream<wchar_t, char_traits<wchar_t> > wofstream;
typedef basic_fstream<wchar_t, char_traits<wchar_t> >  wfstream;
# endif

__STL_END_NAMESPACE

#endif

// Local Variables:
// mode:C++
// End:
