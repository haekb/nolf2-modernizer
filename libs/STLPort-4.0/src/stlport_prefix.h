#ifndef STLPORT_PREFIX_H
# define STLPORT_PREFIX_H

# define __BUILDING_STLPORT 1

// Please add extra compilation switches for particular compilers here

# include <stl/_config.h>

// This section is only for compilers that support precompiled headers !
// Currently there are : Visual C++
// Please remember to make sure to turn on precompiled header option in
// the platform makefile when addinf compilers to this list, otherwise 
// this will result in worse build performance.

# if defined (__STL_MSVC)
# ifndef __STL_USE_DECLSPEC
# include <climits>
# include <cmath>
# include <cstdlib>
# include <cstring>
# include <ctime>
# include <new>
# include <exception>
# include <functional>
# include <memory>
# include <utility>
# include <limits>
# include <algorithm>
# include <iosfwd>
# include <ios>

# include <stdexcept>
# include <string>
// # include <locale>
# endif

# ifdef __STL_MSVC
#  pragma hdrstop
# endif


# endif /* precompiler headers */

#endif /* PREFIX */
