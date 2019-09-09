# include "num_put.h"

//----------------------------------------------------------------------
// Force instantiation of of num_get<> and num_put<>

#if !defined(__STL_NO_FORCE_INSTANTIATE)
# ifndef __STL_NO_WCHAR_T
__STL_BEGIN_NAMESPACE
template class num_put<wchar_t, ostreambuf_iterator<wchar_t, char_traits<wchar_t> > >;
template class num_put<wchar_t, wchar_t*>;
__STL_END_NAMESPACE
# endif /* INSTANTIATE_WIDE_STREAMS */
#endif
