
# include "stlport_prefix.h"

#include <utility>
#include <memory>
#include <vector>

__STL_BEGIN_NAMESPACE

#if !defined(__STL_NO_FORCE_INSTANTIATE)

# ifdef __STL_DEBUG
template struct __STL_CLASS_DECLSPEC __stl_debug_engine<bool>;
# endif

template class __STL_CLASS_DECLSPEC __node_alloc<false,0>;
template class __STL_CLASS_DECLSPEC __node_alloc<true,0>;
template class __STL_CLASS_DECLSPEC __debug_alloc<_Node_alloc>;

template class __STL_CLASS_DECLSPEC __debug_alloc<__new_alloc>;

template class allocator<void*>;
template class _STL_alloc_proxy<void**, void*, allocator<void*> >;
template class _Vector_base<void*,allocator<void*> >;
# if defined (__STL_DEBUG)
template class __WORKAROUND_DBG_RENAME(vector) <void*,allocator<void*> >;
# endif
template class __vector__<void*,allocator<void*> >;

# endif

__STL_END_NAMESPACE


# if defined (_WIN32) && defined (__STL_USE_DECLSPEC)
// stlportmt.cpp : Defines the entry point for the DLL application.
//
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}
# endif
