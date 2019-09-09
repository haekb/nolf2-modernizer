# include "num_put.h"

//----------------------------------------------------------------------
// Force instantiation of num_put<>
#if !defined(__STL_NO_FORCE_INSTANTIATE)

__STL_BEGIN_NAMESPACE
template class num_put<char, char*>;
template class num_put<char, ostreambuf_iterator<char, char_traits<char> > >;
__STL_END_NAMESPACE

#endif
