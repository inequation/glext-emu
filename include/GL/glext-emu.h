/*
glext-emu

Header-only libraries for emulation of select OpenGL extensions for easier
programming while maintaining backwards compatibility with feature-challenged
drivers.

The MIT License (MIT)

Copyright (c) 2013 Leszek Godlewski

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef __gl_h_
	#error Please include gl.h before glext-emu.h
#endif

#if defined(GLEXTEMU_PROTOTYPES) || defined(GLEXTEMU_DEFINITIONS) || defined(GLEXTEMU_PATCH)
#define __glext-emu_h_ 1

// This header is meant to be re-included for each of the use cases: exporting
// function prototypes, definitions or patch commands. Only one define should be
// active per inclusion.
#if (defined(GLEXTEMU_PROTOTYPES) && defined(GLEXTEMU_DEFINITIONS)) || (defined(GLEXTEMU_PATCH) && defined(GLEXTEMU_PROTOTYPES))
	#error Please define only one of GLEXTEMU_PROTOTYPES, GLEXTEMU_DEFINITIONS and GLEXTEMU_PATCH
#endif

// The glext-emu-declared/defined functions need a distinctive prefix.
#ifndef GLEXTEMU_PREFIX
	#error Please define GLEXTEMU_PREFIX
#endif

// Per-use-case configuration follows.
#if defined(GLEXTEMU_DEFINITIONS)
	// Function definitions use a set of macros to control state caching.
	
	// The GLEXTEMU_DECLARE_CACHE macro is used at the beginning of every
	// function to declare state parameters that it needs caching for. The
	// default is to use no caching.
	#ifndef GLEXTEMU_DECLARE_CACHE
		#define GLEXTEMU_DECLARE_CACHE(type, param, default)
	#endif

	// The GLEXTEMU_COMPARE_CACHED macro is used to compare the cached value
	// for the given state parameter with the potential new value. It's expected
	// to return a non-zero value if the cached value differs from the new one,
	// and zero if the new value is equal to the cached one. The default is
	// no-op (no caching).
	#ifndef GLEXTEMU_COMPARE_CACHED
		#define GLEXTEMU_GET_CACHED(param, newValue)
	#endif

	// The GLEXTEMU_SET_CACHED macro is used to set a new cached value for the
	// given state parameter. The default is no-op (no caching).
	#ifndef GLEXTEMU_SET_CACHED
		#define GLEXTEMU_SET_CACHED(param, value)
	#endif
#elif defined(GLEXTEMU_PATCH)
	// GL entry point patching uses a set of macros to control patching of
	// OpenGL entry point pointers as used by the client application. The patch
	// code looks like this:
	// if (GLEXTEMU_FORCE_PATCHING || GLEXTEMU_PFN_PREFIX ## command == NULL)
	// 		GLEXTEMU_PFN_PREFIX ## command = & GLEXTEMU_PREFIX ## command;
	// So this implies that a pointer named "GLEXTEMU_PFN_PREFIX ## command"
	// must exist, it must be NULL if the extension specifying that command is
	// to be emulated (unless GLEXTEMU_FORCE_PATCHING is defined to a non-zero
	// value) and it must be writable.

	// A client application may enforce patching even of supported extensions by
	// defining GLEXTEMU_FORCE_PATCHING to a non-zero value. This can be useful
	// for debugging purposes. The default is 0 (only patch NULL entry points).
	#define GLEXTEMU_FORCE_PATCHING	0

	// A client application may use a custom prefix for its OpenGL command entry
	// point pointers (such as qgl in the id Tech game engines). Define
	// GLEXTEMU_PFN_PREFIX if your entry points are named in such non-standard
	// way. The default is gl for standard OpenGL symbols.
	#ifndef GLEXTEMU_PFN_PREFIX
		#define GLEXTEMU_PFN_PREFIX	gl
	#endif
#endif

// The GLEXTEMU_API is a general-purpose function prefix added to function
// prototypes in much the same way as the GLAPI macro in OpenGL. You can use it
// to declare the functions static within a C++ class, for instance.
#ifndef GLEXTEMU_API
	#ifdef GLAPI
		#define GLEXTEMU_API GLAPI
	#else
		#define GLEXTEMU_API extern
	#endif
#endif

// Internal definitions of per-command macros.
#if defined(GLEXTEMU_DEFINITIONS)
	#define _GLEXTEMU_CMD(returnType, command, args, code)		\
		returnType GLEXTEMU_PREFIX ## command args code
#elif defined(GLEXTEMU_PROTOTYPES)
	#define _GLEXTEMU_CMD(returnType, command, args, code)		\
		GLEXTEMU_API returnType GLEXTEMU_PREFIX ## command args;
#elif defined(GLEXTEMU_PATCH)
	#define _GLEXTEMU_CMD(returnType, command, args, code)		\
		if (GLEXTEMU_FORCE_PATCHING								\
			|| GLEXTEMU_PFN_PREFIX ## command == 0)				\
			GLEXTEMU_PFN_PREFIX ## command = & GLEXTEMU_PREFIX ## command;
#endif

// Per-extension command includes.
#ifdef GLEXTEMU_EXT_direct_state_access
	#include "glext-emu/EXT_direct_state_access.h"
	#if !_GLEXTEMU_USED
		#define _GLEXTEMU_USED 1
	#endif
#endif

// Warn if this header is included but no extensions are to be emulated.
// Someone probably made a typo in the extension name.
#if _GLEXTEMU_USED
	#undef _GLEXTEMU_USED
#else
	#warning glext-emu.h is included, but no extension was chosen to emulate - check GLEXTEMU_* defines for typos
#endif

#undef __glext-emu_h_
#endif // defined(GLEXTEMU_PROTOTYPES) || defined(GLEXTEMU_DEFINITIONS) || defined(GLEXTEMU_PATCH)
