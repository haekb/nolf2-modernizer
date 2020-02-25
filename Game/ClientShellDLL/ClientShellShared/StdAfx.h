// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#ifndef __STDAFX_H__
#define __STDAFX_H__

// This removes warnings about truncating symbol names when using stl maps.
//
#pragma warning( disable : 4786 )  

// This removes warnings in Vis C about the CodeWarrior pragma 'force_active'
//
#pragma warning( disable : 4068 )

#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <windows.h>
#include <limits.h>

#include "mfcstub.h"

#include "DebugNew.h"

#include "iltclient.h"
#include "iltserver.h"
#include "iltmessage.h"
#include "globals.h"

#include "iltmodel.h"
#include "ilttransform.h"
#include "iltphysics.h"
#include "iltmath.h"
#include "iltsoundmgr.h"
#include "ltobjectcreate.h"
#include "ltbasetypes.h"

#include "Factory.h"

#include "iclientshell.h"
#include "ClientUtilities.h"
#include "CommonUtilities.h"
#include "GameClientShell.h"
#include "AutoMessage.h"

// Enable floating point exceptions
#include <float.h>

#ifndef _START_STRICT_FP
// Using this define will clear any fp exceptions, and then look for the next one. Lithtech.exe seems ripe with 'em, so use this carefully.
#define _START_STRICT_FP _clearfp(); _controlfp(_EM_INEXACT | _EM_UNDERFLOW | _EM_OVERFLOW, _MCW_EM);
#define _END_STRICT_FP _clearfp(); _controlfp(_EM_INEXACT | _EM_UNDERFLOW | _EM_OVERFLOW | _EM_INVALID | _EM_ZERODIVIDE, _MCW_EM);
#endif

#endif // __STDAFX_H__