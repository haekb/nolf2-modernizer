# include "stlport_prefix.h"

#include <string>

__STL_BEGIN_NAMESPACE

__STL_DECLSPEC const char*  __STL_CALL
__get_c_string(const string& __str) { 
  return __str.c_str(); 
}

# ifndef __STL_NO_FORCE_INSTANTIATE

template class __STL_CLASS_DECLSPEC allocator<char>;
template class __STL_CLASS_DECLSPEC _String_base<char, allocator<char> >;

# ifdef __STL_DEBUG
template class __STL_CLASS_DECLSPEC _Nondebug_string<char, char_traits<char>, allocator<char> >;
# endif

template class basic_string<char, char_traits<char>, allocator<char> >;

# endif

__STL_END_NAMESPACE

