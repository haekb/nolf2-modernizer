//////////////////////////////////////////////////////////////////////////////
// Debug handler for new & delete to get more information out of our memory allocation

#ifndef __DEBUGNEW_H__
#define __DEBUGNEW_H__

#ifndef __LTMEM_H__
#include "ltmem.h"
#endif

// Enable floating point exceptions
#include <float.h>

// Using this define will clear any fp exceptions, and then look for the next one. Lithtech.exe seems ripe with 'em, so use this carefully.
#define _START_STRICT_FP _clearfp(); _controlfp(_EM_INEXACT | _EM_UNDERFLOW | _EM_OVERFLOW, _MCW_EM);
#define _END_STRICT_FP _clearfp(); _controlfp(_EM_INEXACT | _EM_UNDERFLOW | _EM_OVERFLOW | _EM_INVALID | _EM_ZERODIVIDE, _MCW_EM);

#ifdef LTMEMTRACK

	// Use this macro in the place of "new"  
	#define debug_new(type) debug_new_fn<type >(__LINE__, __FILE__)
	// Use this macro in the place of "new[]"  (Or "new[]")
	#define debug_newa(type, count) debug_new_fna<type >(count, __LINE__, __FILE__)
	// Use this macro in the place of "new CType(Param)"
	#define debug_new1(type, param1) debug_new_fn_param<type >(param1, __LINE__, __FILE__)
	// Use this macro in the place of "new CType(Param1, Param2)"
	#define debug_new2(type, param1, param2) debug_new_fn_param<type >(param1, param2, __LINE__, __FILE__)
	// Use this macro in the place of "new CType(Param1, Param2, Param3)"
	#define debug_new3(type, param1, param2, param3) debug_new_fn_param<type >(param1, param2, param3, __LINE__, __FILE__)

	// Use this macro in the place of "delete"
	#define debug_delete(ptr) debug_delete_fn(ptr)
	// Use this macro in the place of "delete[]"
	#define debug_deletea(ptr) debug_delete_fna(ptr)

#else // LTMEMTRACK

	#define debug_new(type) debug_new_fn<type >()
	#define debug_newa(type, count) debug_new_fna<type >(count)
	#define debug_new1(type, param1) debug_new_fn_param<type >(param1)
	#define debug_new2(type, param1, param2) debug_new_fn_param<type >(param1, param2)
	#define debug_new3(type, param1, param2, param3) debug_new_fn_param<type >(param1, param2, param3)

	#define debug_delete(ptr) debug_delete_fn(ptr)
	#define debug_deletea(ptr) debug_delete_fna(ptr)

#endif // LTMEMTRACK

#include "DebugNew_impl.h"

#endif //__DEBUGNEW_H__