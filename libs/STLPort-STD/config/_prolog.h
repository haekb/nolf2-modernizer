
# undef min
# undef max

#if defined (__STL_MSVC) || defined (__ICL) || defined (__BORLANDC__)

# if !(defined (__STL_MSVC) && (__STL_MSVC < 1200))
#  pragma warning(push)
# endif

# if defined (__BORLANDC__)
#  pragma warning(disable:8012)
#  pragma warning(disable:8091)
# else
# include <config/_msvc_warnings_off.h>
# endif

#elif defined(__sgi) && !defined(__GNUC__) && (_MIPS_SIM != _MIPS_SIM_ABI32)

#pragma set woff 1209
#pragma set woff 1174
#pragma set woff 1375
// from iterator_base.h
#pragma set woff 1183

#elif defined(__DECCXX)

# ifdef __PRAGMA_ENVIRONMENT
#  pragma __environment __save
#  pragma __environment __header_defaults
# endif

#elif defined(__IBMCPP__)
// supress EDC3130: A constant is being used as a conditional expression
#pragma info(nocnd)

#endif
