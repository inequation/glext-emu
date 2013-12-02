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

#if !defined(__gl_h_) && !defined(__GL_H__) && !defined(__X_GL_H)
	#error Please include gl.h (or your OpenGL extension manager's header, such as GLEW) before glext-emu.h
#endif
#if !defined(__glext_h_) && !defined(__GLEXT_H_)
	#error Please include glext.h (or your OpenGL extension manager's header, such as GLEW) before glext-emu.h
#endif

// Reverse header guard: preprocess everything out unless the proper glext-emu
// part is explicitly and exclusively requested.
#if defined(GLEXTEMU_PROTOTYPES) || defined(GLEXTEMU_DEFINITIONS) || defined(GLEXTEMU_PATCH)
#define __glext_emu_h_ 1

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

// A client application may use a custom prefix for its OpenGL command entry
// point pointers (such as qgl in the id Tech game engines). Define
// GLEXTEMU_PFN_PREFIX if your entry points are named in such non-standard
// way. The default is gl for standard OpenGL symbols.
#ifndef GLEXTEMU_PFN_PREFIX
	#define GLEXTEMU_PFN_PREFIX	gl
#endif

// Per-use-case configuration follows.
#if defined(GLEXTEMU_DEFINITIONS)
	// Function definitions use a set of macros to control backing-up the state.

	// The GLEXTEMU_PUSH_* macro family is used to back up the current value of
	// a given state parameter. A custom definition can be used to implement
	// cached switching instead. The default is to use the glGet*() function
	// family to store the current value in a local variable.
	#ifndef GLEXTEMU_PUSH_MATRIX_MODE
		#define GLEXTEMU_PUSH_MATRIX_MODE(newValue)							\
			_GLEXTEMU_PUSH_BINDING(GL_MATRIX_MODE);
	#endif
	#ifndef GLEXTEMU_PUSH_TEXTURE
		#define GLEXTEMU_PUSH_TEXTURE(target, newValue)						\
			_GLEXTEMU_TEXTURE_TO_BINDING(target)							\
			_GLEXTEMU_PUSH_BINDING(bindingParam)
	#endif
	#ifndef GLEXTEMU_PUSH_ACTIVE_TEXTURE
		#define GLEXTEMU_PUSH_ACTIVE_TEXTURE(newValue)						\
			_GLEXTEMU_PUSH_BINDING(GL_ACTIVE_TEXTURE)
	#endif
	#ifndef GLEXTEMU_PUSH_CLIENT_ACTIVE_TEXTURE
		#define GLEXTEMU_PUSH_CLIENT_ACTIVE_TEXTURE(newValue)				\
			_GLEXTEMU_PUSH_BINDING(GL_CLIENT_ACTIVE_TEXTURE);
	#endif
	#ifndef GLEXTEMU_PUSH_BUFFER
		#define GLEXTEMU_PUSH_BUFFER(newValue)								\
			_GLEXTEMU_PUSH_BINDING(GL_ARRAY_BUFFER_BINDING);
	#endif
	#ifndef GLEXTEMU_PUSH_PROGRAM
		#define GLEXTEMU_PUSH_PROGRAM(newValue)								\
			_GLEXTEMU_PUSH_BINDING(GL_CURRENT_PROGRAM);
	#endif
	#ifndef GLEXTEMU_PUSH_RENDERBUFFER
		#define GLEXTEMU_PUSH_RENDERBUFFER(newValue)						\
			_GLEXTEMU_PUSH_BINDING(GL_RENDERBUFFER_BINDING);
	#endif
	#ifndef GLEXTEMU_PUSH_FRAMEBUFFER
		#define GLEXTEMU_PUSH_FRAMEBUFFER(newValue)							\
			_GLEXTEMU_PUSH_BINDING(GL_DRAW_FRAMEBUFFER_BINDING);
	#endif
	#ifndef GLEXTEMU_PUSH_BUFFER_COPY
		#define GLEXTEMU_PUSH_BUFFER_COPY(newValueRead, newValueWrite)		\
			_GLEXTEMU_PUSH_BINDING(GL_COPY_READ_BUFFER_BINDING);			\
			_GLEXTEMU_PUSH_BINDING(GL_COPY_WRITE_BUFFER_BINDING);
	#endif
	#ifndef GLEXTEMU_PUSH_VERTEX_ARRAY
		#define GLEXTEMU_PUSH_VERTEX_ARRAY(vaobj)							\
			_GLEXTEMU_PUSH_BINDING(GL_VERTEX_ARRAY_BINDING);
	#endif
	
	// The GLEXTEMU_POP_* macro family is used to restore the original value of
	// a given state parameter from backup. The default is to call the proper
	// bind function for the given parameter with the backed-up value.
	#ifndef GLEXTEMU_POP_MATRIX_MODE
		#define GLEXTEMU_POP_MATRIX_MODE									\
			_GLEXTEMU_PFN_PREFIXED(MatrixMode)(orig_GL_MATRIX_MODE);
	#endif
	#ifndef GLEXTEMU_POP_TEXTURE
		#define GLEXTEMU_POP_TEXTURE(target)								\
			_GLEXTEMU_PFN_PREFIXED(BindTexture)(target, orig_bindingParam);
	#endif
	#ifndef GLEXTEMU_POP_ACTIVE_TEXTURE
		#define GLEXTEMU_POP_ACTIVE_TEXTURE									\
			_GLEXTEMU_PFN_PREFIXED(ActiveTexture)(orig_GL_ACTIVE_TEXTURE);
	#endif
	#ifndef GLEXTEMU_POP_CLIENT_ACTIVE_TEXTURE
		#define GLEXTEMU_POP_CLIENT_ACTIVE_TEXTURE							\
			_GLEXTEMU_PFN_PREFIXED(ClientActiveTexture)(orig_GL_CLIENT_ACTIVE_TEXTURE);
	#endif
	#ifndef GLEXTEMU_POP_BUFFER
		#define GLEXTEMU_POP_BUFFER											\
			_GLEXTEMU_PFN_PREFIXED(BindBuffer)(GL_ARRAY_BUFFER, orig_GL_ARRAY_BUFFER_BINDING);
	#endif
	#ifndef GLEXTEMU_POP_PROGRAM
		#define GLEXTEMU_POP_PROGRAM										\
			_GLEXTEMU_PFN_PREFIXED(UseProgram)(orig_GL_CURRENT_PROGRAM);
	#endif
	#ifndef GLEXTEMU_POP_RENDERBUFFER
		#define GLEXTEMU_POP_RENDERBUFFER									\
			_GLEXTEMU_PFN_PREFIXED(BindRenderbuffer)(GL_RENDERBUFFER, orig_GL_RENDERBUFFER_BINDING);
	#endif
	#ifndef GLEXTEMU_POP_FRAMEBUFFER
		#define GLEXTEMU_POP_FRAMEBUFFER									\
			_GLEXTEMU_PFN_PREFIXED(BindRenderbuffer)(GL_RENDERBUFFER, orig_GL_DRAW_FRAMEBUFFER_BINDING);
	#endif
	#ifndef GLEXTEMU_POP_BUFFER_COPY
		#define GLEXTEMU_POP_BUFFER_COPY									\
			_GLEXTEMU_PFN_PREFIXED(BindBuffer)(GL_COPY_READ_BUFFER, orig_GL_COPY_READ_BUFFER_BINDING); 	\
			_GLEXTEMU_PFN_PREFIXED(BindBuffer)(GL_COPY_WRITE_BUFFER, orig_GL_COPY_WRITE_BUFFER_BINDING);
	#endif
	#ifndef GLEXTEMU_POP_VERTEX_ARRAY
		#define GLEXTEMU_POP_VERTEX_ARRAY									\
			_GLEXTEMU_PFN_PREFIXED(BindVertexArray)(orig_GL_VERTEX_ARRAY_BINDING);
	#endif
		
	// The GLEXTEMU_DECLARE_CACHED macro is used at the beginning of every
	// function to declare state parameters that it needs caching for. The
	// default is to use no caching.
	#ifndef GLEXTEMU_DECLARE_CACHED
		#define GLEXTEMU_DECLARE_CACHED(type, param, default)
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
	#ifndef GLEXTEMU_FORCE_PATCHING
		#define GLEXTEMU_FORCE_PATCHING	0
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

// Internal helper macros to make sure commands get their prefix
#define _GLEXTEMU_CONCAT2(a, b)			a ## b
#define _GLEXTEMU_CONCAT(a, b)			_GLEXTEMU_CONCAT2(a, b)
#define _GLEXTEMU_PREFIXED(command)		_GLEXTEMU_CONCAT(GLEXTEMU_PREFIX, command)
#define _GLEXTEMU_PFN_PREFIXED(command)	_GLEXTEMU_CONCAT(GLEXTEMU_PFN_PREFIX, command)

// Internal helper macro to facilitate backing up of OpenGL state parameters.
#define _GLEXTEMU_PUSH_BINDING(binding)										\
	GLint orig_ ## binding;													\
	_GLEXTEMU_PFN_PREFIXED(GetIntegerv)(binding, &orig_ ## binding);

// Internal helper macro to convert from a texture target token to a binding.
#define _GLEXTEMU_TEXTURE_TO_BINDING(target)								\
	GLenum bindingParam = GL_TEXTURE_BINDING_2D;							\
	switch (target)															\
	{																		\
		case GL_TEXTURE_1D:	bindingParam = GL_TEXTURE_BINDING_1D;	break;	\
		case GL_TEXTURE_2D:	bindingParam = GL_TEXTURE_BINDING_2D;	break;	\
		case GL_TEXTURE_3D:	bindingParam = GL_TEXTURE_BINDING_3D;	break;	\
		case GL_TEXTURE_CUBE_MAP:											\
			bindingParam = GL_TEXTURE_BINDING_CUBE_MAP;				break;	\
		case GL_TEXTURE_1D_ARRAY:											\
			bindingParam = GL_TEXTURE_BINDING_1D_ARRAY;				break;	\
		case GL_TEXTURE_2D_ARRAY:											\
			bindingParam = GL_TEXTURE_BINDING_2D_ARRAY;				break;	\
		case GL_TEXTURE_BUFFER:												\
			bindingParam = GL_TEXTURE_BINDING_BUFFER;				break;	\
		case GL_TEXTURE_RECTANGLE:											\
			bindingParam = GL_TEXTURE_BINDING_RECTANGLE;			break;	\
		case GL_TEXTURE_2D_MULTISAMPLE:										\
			bindingParam = GL_TEXTURE_BINDING_2D_MULTISAMPLE;		break;	\
		case GL_TEXTURE_2D_MULTISAMPLE_ARRAY:								\
			bindingParam = GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY;	break;	\
	}

// Internal definitions of per-command macros.
#if defined(GLEXTEMU_DEFINITIONS)
	#define _GLEXTEMU_CMD(returnType, command, args, code)				\
		returnType _GLEXTEMU_PREFIXED(command) args code
#elif defined(GLEXTEMU_PROTOTYPES)
	#define _GLEXTEMU_CMD(returnType, command, args, code)				\
		GLEXTEMU_API returnType _GLEXTEMU_PREFIXED(command) args;
#elif defined(GLEXTEMU_PATCH)
	#define _GLEXTEMU_CMD(returnType, command, args, code)				\
		if (GLEXTEMU_FORCE_PATCHING										\
			|| _GLEXTEMU_PFN_PREFIXED(command) == 0)					\
			_GLEXTEMU_PFN_PREFIXED(command) = & _GLEXTEMU_PREFIXED(command);
#endif

// Workaround for GLEW declaring bad types for some instances of internal format
// arguments.
#if defined(__glew_h__) || defined(__GLEW_H__)
	#define GLifmt	GLint
#else
	#define GLifmt	GLenum
#endif

// Temporary placeholder until I figure out how to raise GL errors. :)
#define _GLEXTEMU_RAISE_INVALID_ENUM
#define _GLEXTEMU_RAISE_INVALID_VALUE
#define _GLEXTEMU_RAISE_INVALID_OPERATION
#define _GLEXTEMU_RAISE_INVALID_FRAMEBUFFER_OPERATION

// Per-extension command includes.
#ifdef GLEXTEMU_EXT_direct_state_access
	#include "glext-emu/EXT_direct_state_access.h"
	#if !_GLEXTEMU_USED
		#define _GLEXTEMU_USED 1
	#endif
#endif

// Clean up namespace.
#undef _GLEXTEMU_CMD
#undef _GLEXTEMU_PUSH_BINDING
#undef _GLEXTEMU_PFN_PREFIXED
#undef _GLEXTEMU_PREFIXED
#undef _GLEXTEMU_CONCAT
#undef _GLEXTEMU_CONCAT2

// Warn if this header is included but no extensions are to be emulated.
// Someone probably made a typo in the extension name.
#if _GLEXTEMU_USED
	#undef _GLEXTEMU_USED
#else
	#warning glext-emu.h is included, but no extension was chosen to emulate - check GLEXTEMU_* defines for typos
#endif

#undef __glext_emu_h_
#endif // defined(GLEXTEMU_PROTOTYPES) || defined(GLEXTEMU_DEFINITIONS) || defined(GLEXTEMU_PATCH)
