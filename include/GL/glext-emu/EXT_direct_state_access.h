// GENERATED AUTOMATICALLY - DO NOT MODIFY!!!
// Run ../generators/EXT_direct_state_access.py to regenerate the actual header.

/*
glext-emu - implementation of EXT_direct_state_access

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

#if !__glext_emu_h_
	#error Please do not include this file directly, define GLEXTEMU_VENDOR_extension_names and include GL/glext-emu.h instead
#endif

// Save some typing in matrix functions.
#define _GLEXTEMU_MATRIX_MODE(mode)											\
	GLEXTEMU_PUSH_MATRIX_MODE(mode)											\
	_GLEXTEMU_PFN_PREFIXED(MatrixMode)(mode);

// Save some typing in textue functions.
#define _GLEXTEMU_TEXTURE(texture, target)									\
	GLEXTEMU_PUSH_TEXTURE(target, texture)									\
	_GLEXTEMU_PFN_PREFIXED(BindTexture)(target, texture);

// Save some typing in multitexture functions.
#define _GLEXTEMU_ACTIVE_TEXTURE(texunit)									\
	GLEXTEMU_PUSH_ACTIVE_TEXTURE(texunit)									\
	_GLEXTEMU_PFN_PREFIXED(ActiveTexture)(texunit);

// Save some typing in client texture functions.
#define _GLEXTEMU_CLIENT_ACTIVE_TEXTURE(index)								\
	GLEXTEMU_PUSH_CLIENT_ACTIVE_TEXTURE(GL_TEXTURE0 + index)				\
	_GLEXTEMU_PFN_PREFIXED(ClientActiveTexture)(GL_TEXTURE0 + index);

// Save some typing in buffer functions.
#define _GLEXTEMU_BUFFER(buffer)											\
	GLEXTEMU_PUSH_BUFFER(buffer)											\
	_GLEXTEMU_PFN_PREFIXED(BindBuffer)(GL_ARRAY_BUFFER, buffer);

// Save some typing in program functions.
#define _GLEXTEMU_PROGRAM(program)											\
	GLEXTEMU_PUSH_PROGRAM(program)											\
	_GLEXTEMU_PFN_PREFIXED(UseProgram)(program);

// Save some typing in render buffer functions.
#define _GLEXTEMU_RENDERBUFFER(renderbuffer)								\
	GLEXTEMU_PUSH_RENDERBUFFER(renderbuffer)								\
	_GLEXTEMU_PFN_PREFIXED(BindRenderbuffer)(GL_RENDERBUFFER, renderbuffer);

// Save some typing in frame buffer functions.
#define _GLEXTEMU_FRAMEBUFFER(framebuffer)									\
	GLEXTEMU_PUSH_FRAMEBUFFER(framebuffer)									\
	_GLEXTEMU_PFN_PREFIXED(BindFramebuffer)(GL_FRAMEBUFFER, framebuffer);

// Save some typing in buffer copy functions.
#define _GLEXTEMU_BUFFER_COPY(readBuffer, writeBuffer)						\
	GLEXTEMU_PUSH_BUFFER_COPY(readBuffer, writeBuffer)						\
	_GLEXTEMU_PFN_PREFIXED(BindBuffer)(GL_COPY_READ_BUFFER, readBuffer);	\
	_GLEXTEMU_PFN_PREFIXED(BindBuffer)(GL_COPY_WRITE_BUFFER, writeBuffer);	\

// Save some typing in vertex array object functions.
#define _GLEXTEMU_VERTEX_ARRAY(vaobj)										\
	GLEXTEMU_PUSH_VERTEX_ARRAY(vaobj)										\
	_GLEXTEMU_PFN_PREFIXED(BindVertexArray)(vaobj);

// Save *a lot* of typing for indexed simple state variable gets.
#define _GLEXTEMU_INDEXED_GET(type, suffix, arg_type)						\
_GLEXTEMU_CMD(void, Get ## type ## suffix, (GLenum target, GLuint index, arg_type data),	\
{																			\
	switch (target)															\
	{																		\
		case GL_PROGRAM_MATRIX_EXT:											\
		case GL_TRANSPOSE_PROGRAM_MATRIX_EXT:								\
		case GL_PROGRAM_MATRIX_STACK_DEPTH_EXT:								\
			{																\
				_GLEXTEMU_MATRIX_MODE(GL_MATRIX0_ARB + index)				\
				GLenum t;													\
				switch (target)												\
				{															\
					case GL_PROGRAM_MATRIX_EXT:								\
						t = GL_CURRENT_MATRIX_ARB;	break;					\
					case GL_TRANSPOSE_PROGRAM_MATRIX_EXT:					\
						t = GL_TRANSPOSE_CURRENT_MATRIX_ARB;	break;		\
					case GL_PROGRAM_MATRIX_STACK_DEPTH_EXT:					\
						t = GL_CURRENT_MATRIX_STACK_DEPTH_ARB;	break;		\
				}															\
				_GLEXTEMU_PFN_PREFIXED(Get ## type ## v)(t, data);			\
			}																\
			break;															\
		case GL_CURRENT_MATRIX_NV:											\
		case GL_CURRENT_MATRIX_STACK_DEPTH_NV:								\
		case GL_CURRENT_RASTER_TEXTURE_COORDS:								\
		case GL_CURRENT_TEXTURE_COORDS:										\
		case GL_TEXTURE_BINDING_1D:											\
		case GL_TEXTURE_BINDING_1D_ARRAY:									\
		case GL_TEXTURE_BINDING_2D:											\
		case GL_TEXTURE_BINDING_2D_ARRAY:									\
		case GL_TEXTURE_BINDING_3D:											\
		case GL_TEXTURE_BINDING_BUFFER_EXT:									\
		case GL_TEXTURE_BINDING_CUBE_MAP:									\
		case GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB:							\
		case GL_TEXTURE_BINDING_RECTANGLE_ARB:								\
		case GL_TEXTURE_BINDING_RENDERBUFFER_NV:							\
		case GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV:					\
		case GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT:						\
		case GL_TEXTURE_BUFFER_FORMAT_EXT:									\
		case GL_TEXTURE_GEN_Q:												\
		case GL_TEXTURE_GEN_R:												\
		case GL_TEXTURE_GEN_S:												\
		case GL_TEXTURE_GEN_T:												\
		case GL_TEXTURE_MATRIX:												\
		case GL_TEXTURE_STACK_DEPTH:										\
		case GL_TRANSPOSE_TEXTURE_MATRIX:									\
		case GL_TEXTURE_1D:													\
		case GL_TEXTURE_2D:													\
		case GL_TEXTURE_3D:													\
		case GL_TEXTURE_CUBE_MAP:											\
		case GL_TEXTURE_RECTANGLE_ARB:										\
			{																\
				_GLEXTEMU_ACTIVE_TEXTURE(GL_TEXTURE0 + index)						\
				_GLEXTEMU_PFN_PREFIXED(Get ## type ## v)(target, data);		\
			}																\
			break;															\
		case GL_TEXTURE_COORD_ARRAY:										\
		case GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING:							\
		case GL_TEXTURE_COORD_ARRAY_COUNT_EXT:								\
		case GL_TEXTURE_COORD_ARRAY_SIZE:									\
		case GL_TEXTURE_COORD_ARRAY_STRIDE:									\
		case GL_TEXTURE_COORD_ARRAY_TYPE:									\
			{																\
				_GLEXTEMU_CLIENT_ACTIVE_TEXTURE(GL_TEXTURE0 + index)		\
				_GLEXTEMU_PFN_PREFIXED(Get ## type ## v)(target, data);		\
			}																\
			break;															\
		default:															\
			_GLEXTEMU_RAISE_INVALID_ENUM									\
			break;															\
	}																		\
}																			\
)

// Save *a lot* of typing for indexed simple state variable gets.
#define _GLEXTEMU_INDEXED_ISENABLED(suffix)									\
_GLEXTEMU_CMD(GLboolean, IsEnabled ## suffix, (GLenum target, GLuint index),\
{																			\
	switch (target)															\
	{																		\
		case GL_TEXTURE_1D:													\
		case GL_TEXTURE_2D:													\
		case GL_TEXTURE_3D:													\
		case GL_TEXTURE_CUBE_MAP:											\
		case GL_TEXTURE_RECTANGLE_ARB:										\
		case GL_TEXTURE_GEN_S:												\
		case GL_TEXTURE_GEN_T:												\
		case GL_TEXTURE_GEN_R:												\
		case GL_TEXTURE_GEN_Q:												\
			{																\
				_GLEXTEMU_ACTIVE_TEXTURE(GL_TEXTURE0 + index)				\
				return _GLEXTEMU_PFN_PREFIXED(IsEnabled)(target);			\
			}																\
		case GL_TEXTURE_COORD_ARRAY:										\
			{																\
				_GLEXTEMU_CLIENT_ACTIVE_TEXTURE(GL_TEXTURE0 + index)		\
				return _GLEXTEMU_PFN_PREFIXED(IsEnabled)(target);			\
			}																\
			break;															\
		default:															\
			_GLEXTEMU_RAISE_INVALID_ENUM									\
			break;															\
	}																		\
	return GL_FALSE;														\
}																			\
)

// FIXME: hack for GLEW
#ifndef GL_COPY_READ_BUFFER_BINDING
	#define GL_COPY_READ_BUFFER_BINDING 0x8F36
#endif
#ifndef GL_COPY_WRITE_BUFFER_BINDING
	#define GL_COPY_WRITE_BUFFER_BINDING 0x8F37
#endif

_GLEXTEMU_CMD
(
void, ClientAttribDefaultEXT, (GLbitfield mask),
{
	if (mask & GL_CLIENT_PIXEL_STORE_BIT)
	{
		_GLEXTEMU_PFN_PREFIXED(PixelStorei)(GL_UNPACK_SWAP_BYTES, GL_FALSE);
		_GLEXTEMU_PFN_PREFIXED(PixelStorei)(GL_UNPACK_LSB_FIRST, GL_FALSE);
		_GLEXTEMU_PFN_PREFIXED(PixelStorei)(GL_UNPACK_IMAGE_HEIGHT, 0);
		_GLEXTEMU_PFN_PREFIXED(PixelStorei)(GL_UNPACK_SKIP_IMAGES, 0);
		_GLEXTEMU_PFN_PREFIXED(PixelStorei)(GL_UNPACK_ROW_LENGTH, 0);
		_GLEXTEMU_PFN_PREFIXED(PixelStorei)(GL_UNPACK_SKIP_ROWS, 0);
		_GLEXTEMU_PFN_PREFIXED(PixelStorei)(GL_UNPACK_SKIP_PIXELS, 0);
		_GLEXTEMU_PFN_PREFIXED(PixelStorei)(GL_UNPACK_ALIGNMENT, 4);
		_GLEXTEMU_PFN_PREFIXED(PixelStorei)(GL_PACK_SWAP_BYTES, GL_FALSE);
		_GLEXTEMU_PFN_PREFIXED(PixelStorei)(GL_PACK_LSB_FIRST, GL_FALSE);
		_GLEXTEMU_PFN_PREFIXED(PixelStorei)(GL_PACK_IMAGE_HEIGHT, 0);
		_GLEXTEMU_PFN_PREFIXED(PixelStorei)(GL_PACK_SKIP_IMAGES, 0);
		_GLEXTEMU_PFN_PREFIXED(PixelStorei)(GL_PACK_ROW_LENGTH, 0);
		_GLEXTEMU_PFN_PREFIXED(PixelStorei)(GL_PACK_SKIP_ROWS, 0);
		_GLEXTEMU_PFN_PREFIXED(PixelStorei)(GL_PACK_SKIP_PIXELS, 0);
		_GLEXTEMU_PFN_PREFIXED(PixelStorei)(GL_PACK_ALIGNMENT, 4);

		_GLEXTEMU_PFN_PREFIXED(BindBuffer)(GL_PIXEL_UNPACK_BUFFER, 0);
		_GLEXTEMU_PFN_PREFIXED(BindBuffer)(GL_PIXEL_PACK_BUFFER, 0);
	}
	
	if (mask & GL_CLIENT_VERTEX_ARRAY_BIT)
	{
		int i;
		GLint max;

		_GLEXTEMU_PFN_PREFIXED(BindBuffer)(GL_ARRAY_BUFFER, 0);
		_GLEXTEMU_PFN_PREFIXED(BindBuffer)(GL_ELEMENT_ARRAY_BUFFER, 0);

		//_GLEXTEMU_PFN_PREFIXED(DisableClientState)(GL_EDGE_FLAG_ARRAY);
		//_GLEXTEMU_PFN_PREFIXED(EdgePointer)(0, 0);

		_GLEXTEMU_PFN_PREFIXED(DisableClientState)(GL_INDEX_ARRAY);
		_GLEXTEMU_PFN_PREFIXED(IndexPointer)(GL_FLOAT, 0, 0);

		_GLEXTEMU_PFN_PREFIXED(DisableClientState)(GL_SECONDARY_COLOR_ARRAY);
		_GLEXTEMU_PFN_PREFIXED(SecondaryColorPointer)(4, GL_FLOAT, 0, 0);

		_GLEXTEMU_PFN_PREFIXED(DisableClientState)(GL_FOG_COORD_ARRAY);
		_GLEXTEMU_PFN_PREFIXED(FogCoordPointer)(GL_FLOAT, 0, 0);

		_GLEXTEMU_PFN_PREFIXED(GetIntegerv)(GL_MAX_TEXTURE_COORDS, &max);
		for (i=0; i<max; i++) {
			_GLEXTEMU_PFN_PREFIXED(ClientActiveTexture)(GL_TEXTURE0 + i);
			_GLEXTEMU_PFN_PREFIXED(DisableClientState)(GL_TEXTURE_COORD_ARRAY);
			_GLEXTEMU_PFN_PREFIXED(TexCoordPointer)(4, GL_FLOAT, 0, 0);
		}

		_GLEXTEMU_PFN_PREFIXED(DisableClientState)(GL_COLOR_ARRAY);
		_GLEXTEMU_PFN_PREFIXED(ColorPointer)(4, GL_FLOAT, 0, 0);

		_GLEXTEMU_PFN_PREFIXED(DisableClientState)(GL_NORMAL_ARRAY);
		_GLEXTEMU_PFN_PREFIXED(NormalPointer)(GL_FLOAT, 0, 0);

		_GLEXTEMU_PFN_PREFIXED(DisableClientState)(GL_VERTEX_ARRAY);
		_GLEXTEMU_PFN_PREFIXED(VertexPointer)(4, GL_FLOAT, 0, 0);

		_GLEXTEMU_PFN_PREFIXED(DisableClientState)(GL_WEIGHT_ARRAY_ARB);
		_GLEXTEMU_PFN_PREFIXED(WeightPointerARB)(0, GL_FLOAT, 0, 0);

		_GLEXTEMU_PFN_PREFIXED(GetIntegerv)(GL_MAX_VERTEX_ATTRIBS, &max);
		for (i=0; i<max; i++) {
			_GLEXTEMU_PFN_PREFIXED(DisableVertexAttribArray)(i);
			_GLEXTEMU_PFN_PREFIXED(VertexAttribPointer)(i, 4, GL_FLOAT, GL_FALSE, 0, 0);
		}

		_GLEXTEMU_PFN_PREFIXED(ClientActiveTexture)(GL_TEXTURE0);
	}
}
)

_GLEXTEMU_CMD
(
void, PushClientAttribDefaultEXT, (GLbitfield mask),
{
	_GLEXTEMU_PFN_PREFIXED(PushClientAttrib)(mask);
	_GLEXTEMU_PREFIXED(ClientAttribDefaultEXT)(mask);
}
)

_GLEXTEMU_CMD
(
void, EnableClientStateIndexedEXT, (GLenum array, GLuint index),
{
	if (array == GL_TEXTURE_COORD_ARRAY)
	{
		_GLEXTEMU_CLIENT_ACTIVE_TEXTURE(index)
		_GLEXTEMU_PFN_PREFIXED(EnableClientState)(array);
		GLEXTEMU_POP_CLIENT_ACTIVE_TEXTURE
	}
	else
	{
		_GLEXTEMU_RAISE_INVALID_ENUM
	}
}
)

_GLEXTEMU_CMD
(
void, DisableClientStateIndexedEXT, (GLenum array, GLuint index),
{
	if (array == GL_TEXTURE_COORD_ARRAY)
	{
		_GLEXTEMU_CLIENT_ACTIVE_TEXTURE(index)
		_GLEXTEMU_PFN_PREFIXED(DisableClientState)(array);
		GLEXTEMU_POP_CLIENT_ACTIVE_TEXTURE
	}
	else
	{
		_GLEXTEMU_RAISE_INVALID_ENUM
	}
}
)

_GLEXTEMU_CMD
(
void, EnableClientStateiEXT, (GLenum array, GLuint index),
{
	_GLEXTEMU_PREFIXED(EnableClientStateIndexedEXT)(array, index);
}
)

_GLEXTEMU_CMD
(
void, DisableClientStateiEXT, (GLenum array, GLuint index),
{
	_GLEXTEMU_PREFIXED(DisableClientStateIndexedEXT)(array, index);
}
)

_GLEXTEMU_CMD
(
void, GetFramebufferParameterivEXT, (GLuint framebuffer, GLenum pname, GLint* params),
{
	_GLEXTEMU_FRAMEBUFFER(framebuffer)
	_GLEXTEMU_PFN_PREFIXED(GetFramebufferParameteriv)(GL_FRAMEBUFFER, pname, params);
	GLEXTEMU_POP_FRAMEBUFFER
}
)

_GLEXTEMU_INDEXED_GET(Boolean, IndexedvEXT, GLboolean *)
_GLEXTEMU_INDEXED_GET(Integer, IndexedvEXT, GLint *)
_GLEXTEMU_INDEXED_GET(Float, IndexedvEXT, GLfloat *)
_GLEXTEMU_INDEXED_GET(Double, IndexedvEXT, GLdouble *)
_GLEXTEMU_INDEXED_GET(Pointer, IndexedvEXT, GLvoid **)
_GLEXTEMU_INDEXED_GET(Boolean, i_v, GLboolean *)
_GLEXTEMU_INDEXED_GET(Integer, i_v, GLint *)
_GLEXTEMU_INDEXED_GET(Float, i_vEXT, GLfloat *)
_GLEXTEMU_INDEXED_GET(Double, i_vEXT, GLdouble *)
_GLEXTEMU_INDEXED_GET(Pointer, i_vEXT, GLvoid **)
// FIXME!!! forward calls to regular glIsEnabledi()
_GLEXTEMU_INDEXED_ISENABLED(i)
_GLEXTEMU_INDEXED_ISENABLED(IndexedEXT)

//Auto-generated implementation goes here.

_GLEXTEMU_CMD
(
void, MatrixLoadfEXT, (GLenum mode, const GLfloat* m),
{
	_GLEXTEMU_MATRIX_MODE(mode)
	_GLEXTEMU_PFN_PREFIXED(LoadMatrixf)(m);
	GLEXTEMU_POP_MATRIX_MODE
}
)

_GLEXTEMU_CMD
(
void, MatrixLoaddEXT, (GLenum mode, const GLdouble* m),
{
	_GLEXTEMU_MATRIX_MODE(mode)
	_GLEXTEMU_PFN_PREFIXED(LoadMatrixd)(m);
	GLEXTEMU_POP_MATRIX_MODE
}
)

_GLEXTEMU_CMD
(
void, MatrixMultfEXT, (GLenum mode, const GLfloat* m),
{
	_GLEXTEMU_MATRIX_MODE(mode)
	_GLEXTEMU_PFN_PREFIXED(MultMatrixf)(m);
	GLEXTEMU_POP_MATRIX_MODE
}
)

_GLEXTEMU_CMD
(
void, MatrixMultdEXT, (GLenum mode, const GLdouble* m),
{
	_GLEXTEMU_MATRIX_MODE(mode)
	_GLEXTEMU_PFN_PREFIXED(MultMatrixd)(m);
	GLEXTEMU_POP_MATRIX_MODE
}
)

_GLEXTEMU_CMD
(
void, MatrixLoadIdentityEXT, (GLenum mode),
{
	_GLEXTEMU_MATRIX_MODE(mode)
	_GLEXTEMU_PFN_PREFIXED(LoadIdentity)();
	GLEXTEMU_POP_MATRIX_MODE
}
)

_GLEXTEMU_CMD
(
void, MatrixRotatefEXT, (GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z),
{
	_GLEXTEMU_MATRIX_MODE(mode)
	_GLEXTEMU_PFN_PREFIXED(Rotatef)(angle, x, y, z);
	GLEXTEMU_POP_MATRIX_MODE
}
)

_GLEXTEMU_CMD
(
void, MatrixRotatedEXT, (GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z),
{
	_GLEXTEMU_MATRIX_MODE(mode)
	_GLEXTEMU_PFN_PREFIXED(Rotated)(angle, x, y, z);
	GLEXTEMU_POP_MATRIX_MODE
}
)

_GLEXTEMU_CMD
(
void, MatrixScalefEXT, (GLenum mode, GLfloat x, GLfloat y, GLfloat z),
{
	_GLEXTEMU_MATRIX_MODE(mode)
	_GLEXTEMU_PFN_PREFIXED(Scalef)(x, y, z);
	GLEXTEMU_POP_MATRIX_MODE
}
)

_GLEXTEMU_CMD
(
void, MatrixScaledEXT, (GLenum mode, GLdouble x, GLdouble y, GLdouble z),
{
	_GLEXTEMU_MATRIX_MODE(mode)
	_GLEXTEMU_PFN_PREFIXED(Scaled)(x, y, z);
	GLEXTEMU_POP_MATRIX_MODE
}
)

_GLEXTEMU_CMD
(
void, MatrixTranslatefEXT, (GLenum mode, GLfloat x, GLfloat y, GLfloat z),
{
	_GLEXTEMU_MATRIX_MODE(mode)
	_GLEXTEMU_PFN_PREFIXED(Translatef)(x, y, z);
	GLEXTEMU_POP_MATRIX_MODE
}
)

_GLEXTEMU_CMD
(
void, MatrixTranslatedEXT, (GLenum mode, GLdouble x, GLdouble y, GLdouble z),
{
	_GLEXTEMU_MATRIX_MODE(mode)
	_GLEXTEMU_PFN_PREFIXED(Translated)(x, y, z);
	GLEXTEMU_POP_MATRIX_MODE
}
)

_GLEXTEMU_CMD
(
void, MatrixFrustumEXT, (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar),
{
	_GLEXTEMU_MATRIX_MODE(mode)
	_GLEXTEMU_PFN_PREFIXED(Frustum)(left, right, bottom, top, zNear, zFar);
	GLEXTEMU_POP_MATRIX_MODE
}
)

_GLEXTEMU_CMD
(
void, MatrixOrthoEXT, (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar),
{
	_GLEXTEMU_MATRIX_MODE(mode)
	_GLEXTEMU_PFN_PREFIXED(Ortho)(left, right, bottom, top, zNear, zFar);
	GLEXTEMU_POP_MATRIX_MODE
}
)

_GLEXTEMU_CMD
(
void, MatrixPopEXT, (GLenum mode),
{
	_GLEXTEMU_MATRIX_MODE(mode)
	_GLEXTEMU_PFN_PREFIXED(PopMatrix)();
	GLEXTEMU_POP_MATRIX_MODE
}
)

_GLEXTEMU_CMD
(
void, MatrixPushEXT, (GLenum mode),
{
	_GLEXTEMU_MATRIX_MODE(mode)
	_GLEXTEMU_PFN_PREFIXED(PushMatrix)();
	GLEXTEMU_POP_MATRIX_MODE
}
)

_GLEXTEMU_CMD
(
void, TextureParameterfEXT, (GLuint texture, GLenum target, GLenum pname, GLfloat param),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(TexParameterf)(target, pname, param);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, TextureParameterfvEXT, (GLuint texture, GLenum target, GLenum pname, const GLfloat* params),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(TexParameterfv)(target, pname, params);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, TextureParameteriEXT, (GLuint texture, GLenum target, GLenum pname, GLint param),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(TexParameteri)(target, pname, param);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, TextureParameterivEXT, (GLuint texture, GLenum target, GLenum pname, const GLint* params),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(TexParameteriv)(target, pname, params);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, TextureImage1DEXT, (GLuint texture, GLenum target, GLint level, GLifmt internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(TexImage1D)(target, level, internalformat, width, border, format, type, pixels);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, TextureImage2DEXT, (GLuint texture, GLenum target, GLint level, GLifmt internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(TexImage2D)(target, level, internalformat, width, height, border, format, type, pixels);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, TextureSubImage1DEXT, (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(TexSubImage1D)(target, level, xoffset, width, format, type, pixels);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, TextureSubImage2DEXT, (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(TexSubImage2D)(target, level, xoffset, yoffset, width, height, format, type, pixels);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, CopyTextureImage1DEXT, (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(CopyTexImage1D)(target, level, internalformat, x, y, width, border);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, CopyTextureImage2DEXT, (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(CopyTexImage2D)(target, level, internalformat, x, y, width, height, border);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, CopyTextureSubImage1DEXT, (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(CopyTexSubImage1D)(target, level, xoffset, x, y, width);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, CopyTextureSubImage2DEXT, (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(CopyTexSubImage2D)(target, level, xoffset, yoffset, x, y, width, height);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, GetTextureImageEXT, (GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLvoid* pixels),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(GetTexImage)(target, level, format, type, pixels);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, GetTextureParameterfvEXT, (GLuint texture, GLenum target, GLenum pname, GLfloat* params),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(GetTexParameterfv)(target, pname, params);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, GetTextureParameterivEXT, (GLuint texture, GLenum target, GLenum pname, GLint* params),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(GetTexParameteriv)(target, pname, params);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, GetTextureLevelParameterfvEXT, (GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat* params),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(GetTexLevelParameterfv)(target, level, pname, params);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, GetTextureLevelParameterivEXT, (GLuint texture, GLenum target, GLint level, GLenum pname, GLint* params),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(GetTexLevelParameteriv)(target, level, pname, params);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, TextureImage3DEXT, (GLuint texture, GLenum target, GLint level, GLifmt internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(TexImage3D)(target, level, internalformat, width, height, depth, border, format, type, pixels);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, TextureSubImage3DEXT, (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(TexSubImage3D)(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, CopyTextureSubImage3DEXT, (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(CopyTexSubImage3D)(target, level, xoffset, yoffset, zoffset, x, y, width, height);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, BindMultiTextureEXT, (GLenum texunit, GLenum target, GLuint texture),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(BindTexture)(target, texture);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexCoordPointerEXT, (GLenum texunit, GLint size, GLenum type, GLsizei stride, const void* pointer),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexCoordPointer)(size, type, stride, pointer);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexEnvfEXT, (GLenum texunit, GLenum target, GLenum pname, GLfloat param),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexEnvf)(target, pname, param);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexEnvfvEXT, (GLenum texunit, GLenum target, GLenum pname, const GLfloat* params),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexEnvfv)(target, pname, params);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexEnviEXT, (GLenum texunit, GLenum target, GLenum pname, GLint param),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexEnvi)(target, pname, param);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexEnvivEXT, (GLenum texunit, GLenum target, GLenum pname, const GLint* params),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexEnviv)(target, pname, params);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexGendEXT, (GLenum texunit, GLenum coord, GLenum pname, GLdouble param),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexGend)(coord, pname, param);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexGendvEXT, (GLenum texunit, GLenum coord, GLenum pname, const GLdouble* params),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexGendv)(coord, pname, params);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexGenfEXT, (GLenum texunit, GLenum coord, GLenum pname, GLfloat param),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexGenf)(coord, pname, param);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexGenfvEXT, (GLenum texunit, GLenum coord, GLenum pname, const GLfloat* params),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexGenfv)(coord, pname, params);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexGeniEXT, (GLenum texunit, GLenum coord, GLenum pname, GLint param),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexGeni)(coord, pname, param);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexGenivEXT, (GLenum texunit, GLenum coord, GLenum pname, const GLint* params),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexGeniv)(coord, pname, params);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexEnvfvEXT, (GLenum texunit, GLenum target, GLenum pname, GLfloat* params),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(GetTexEnvfv)(target, pname, params);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexEnvivEXT, (GLenum texunit, GLenum target, GLenum pname, GLint* params),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(GetTexEnviv)(target, pname, params);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexGendvEXT, (GLenum texunit, GLenum coord, GLenum pname, GLdouble* params),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(GetTexGendv)(coord, pname, params);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexGenfvEXT, (GLenum texunit, GLenum coord, GLenum pname, GLfloat* params),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(GetTexGenfv)(coord, pname, params);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexGenivEXT, (GLenum texunit, GLenum coord, GLenum pname, GLint* params),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(GetTexGeniv)(coord, pname, params);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexParameteriEXT, (GLenum texunit, GLenum target, GLenum pname, GLint param),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexParameteri)(target, pname, param);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexParameterivEXT, (GLenum texunit, GLenum target, GLenum pname, const GLint* params),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexParameteriv)(target, pname, params);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexParameterfEXT, (GLenum texunit, GLenum target, GLenum pname, GLfloat param),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexParameterf)(target, pname, param);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexParameterfvEXT, (GLenum texunit, GLenum target, GLenum pname, const GLfloat* params),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexParameterfv)(target, pname, params);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexImage1DEXT, (GLenum texunit, GLenum target, GLint level, GLifmt internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexImage1D)(target, level, internalformat, width, border, format, type, pixels);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexImage2DEXT, (GLenum texunit, GLenum target, GLint level, GLifmt internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexImage2D)(target, level, internalformat, width, height, border, format, type, pixels);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexSubImage1DEXT, (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexSubImage1D)(target, level, xoffset, width, format, type, pixels);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexSubImage2DEXT, (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexSubImage2D)(target, level, xoffset, yoffset, width, height, format, type, pixels);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, CopyMultiTexImage1DEXT, (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(CopyTexImage1D)(target, level, internalformat, x, y, width, border);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, CopyMultiTexImage2DEXT, (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(CopyTexImage2D)(target, level, internalformat, x, y, width, height, border);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, CopyMultiTexSubImage1DEXT, (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(CopyTexSubImage1D)(target, level, xoffset, x, y, width);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, CopyMultiTexSubImage2DEXT, (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(CopyTexSubImage2D)(target, level, xoffset, yoffset, x, y, width, height);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexImageEXT, (GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, GLvoid* pixels),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(GetTexImage)(target, level, format, type, pixels);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexParameterfvEXT, (GLenum texunit, GLenum target, GLenum pname, GLfloat* params),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(GetTexParameterfv)(target, pname, params);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexParameterivEXT, (GLenum texunit, GLenum target, GLenum pname, GLint* params),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(GetTexParameteriv)(target, pname, params);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexLevelParameterfvEXT, (GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat* params),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(GetTexLevelParameterfv)(target, level, pname, params);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexLevelParameterivEXT, (GLenum texunit, GLenum target, GLint level, GLenum pname, GLint* params),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(GetTexLevelParameteriv)(target, level, pname, params);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexImage3DEXT, (GLenum texunit, GLenum target, GLint level, GLifmt internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexImage3D)(target, level, internalformat, width, height, depth, border, format, type, pixels);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexSubImage3DEXT, (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexSubImage3D)(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, CopyMultiTexSubImage3DEXT, (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(CopyTexSubImage3D)(target, level, xoffset, yoffset, zoffset, x, y, width, height);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, EnableIndexedEXT, (GLenum target, GLuint index),
{
	_GLEXTEMU_ACTIVE_TEXTURE(index)
	_GLEXTEMU_PFN_PREFIXED(Enable)(index);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, DisableIndexedEXT, (GLenum target, GLuint index),
{
	_GLEXTEMU_ACTIVE_TEXTURE(index)
	_GLEXTEMU_PFN_PREFIXED(Disable)(index);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, CompressedTextureImage3DEXT, (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* bits),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(CompressedTexImage3D)(target, level, internalformat, width, height, depth, border, imageSize, bits);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, CompressedTextureImage2DEXT, (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* bits),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(CompressedTexImage2D)(target, level, internalformat, width, height, border, imageSize, bits);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, CompressedTextureImage1DEXT, (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* bits),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(CompressedTexImage1D)(target, level, internalformat, width, border, imageSize, bits);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, CompressedTextureSubImage3DEXT, (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* bits),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(CompressedTexSubImage3D)(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, bits);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, CompressedTextureSubImage2DEXT, (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* bits),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(CompressedTexSubImage2D)(target, level, xoffset, yoffset, width, height, format, imageSize, bits);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, CompressedTextureSubImage1DEXT, (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* bits),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(CompressedTexSubImage1D)(target, level, xoffset, width, format, imageSize, bits);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, GetCompressedTextureImageEXT, (GLuint texture, GLenum target, GLint lod, GLvoid* img),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(GetCompressedTexImage)(target, lod, img);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, CompressedMultiTexImage3DEXT, (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* bits),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(CompressedTexImage3D)(target, level, internalformat, width, height, depth, border, imageSize, bits);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, CompressedMultiTexImage2DEXT, (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* bits),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(CompressedTexImage2D)(target, level, internalformat, width, height, border, imageSize, bits);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, CompressedMultiTexImage1DEXT, (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* bits),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(CompressedTexImage1D)(target, level, internalformat, width, border, imageSize, bits);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, CompressedMultiTexSubImage3DEXT, (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* bits),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(CompressedTexSubImage3D)(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, bits);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, CompressedMultiTexSubImage2DEXT, (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* bits),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(CompressedTexSubImage2D)(target, level, xoffset, yoffset, width, height, format, imageSize, bits);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, CompressedMultiTexSubImage1DEXT, (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* bits),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(CompressedTexSubImage1D)(target, level, xoffset, width, format, imageSize, bits);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, GetCompressedMultiTexImageEXT, (GLenum texunit, GLenum target, GLint lod, GLvoid* img),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(GetCompressedTexImage)(target, lod, img);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MatrixLoadTransposefEXT, (GLenum mode, const GLfloat* m),
{
	_GLEXTEMU_MATRIX_MODE(mode)
	_GLEXTEMU_PFN_PREFIXED(LoadTransposeMatrixf)(m);
	GLEXTEMU_POP_MATRIX_MODE
}
)

_GLEXTEMU_CMD
(
void, MatrixLoadTransposedEXT, (GLenum mode, const GLdouble* m),
{
	_GLEXTEMU_MATRIX_MODE(mode)
	_GLEXTEMU_PFN_PREFIXED(LoadTransposeMatrixd)(m);
	GLEXTEMU_POP_MATRIX_MODE
}
)

_GLEXTEMU_CMD
(
void, MatrixMultTransposefEXT, (GLenum mode, const GLfloat* m),
{
	_GLEXTEMU_MATRIX_MODE(mode)
	_GLEXTEMU_PFN_PREFIXED(MultTransposeMatrixf)(m);
	GLEXTEMU_POP_MATRIX_MODE
}
)

_GLEXTEMU_CMD
(
void, MatrixMultTransposedEXT, (GLenum mode, const GLdouble* m),
{
	_GLEXTEMU_MATRIX_MODE(mode)
	_GLEXTEMU_PFN_PREFIXED(MultTransposeMatrixd)(m);
	GLEXTEMU_POP_MATRIX_MODE
}
)

_GLEXTEMU_CMD
(
void, NamedBufferDataEXT, (GLuint buffer, GLsizeiptr size, const GLvoid* data, GLenum usage),
{
	_GLEXTEMU_BUFFER(buffer)
	_GLEXTEMU_PFN_PREFIXED(BufferData)(GL_ARRAY_BUFFER, size, data, usage);
	GLEXTEMU_POP_BUFFER
}
)

_GLEXTEMU_CMD
(
void, NamedBufferSubDataEXT, (GLuint buffer, GLintptr offset, GLsizeiptr size, const GLvoid* data),
{
	_GLEXTEMU_BUFFER(buffer)
	_GLEXTEMU_PFN_PREFIXED(BufferSubData)(GL_ARRAY_BUFFER, offset, size, data);
	GLEXTEMU_POP_BUFFER
}
)

_GLEXTEMU_CMD
(
void*, MapNamedBufferEXT, (GLuint buffer, GLenum access),
{
	_GLEXTEMU_BUFFER(buffer)
	return _GLEXTEMU_PFN_PREFIXED(MapBuffer)(GL_ARRAY_BUFFER, access);
	GLEXTEMU_POP_BUFFER
}
)

_GLEXTEMU_CMD
(
GLboolean, UnmapNamedBufferEXT, (GLuint buffer),
{
	_GLEXTEMU_BUFFER(buffer)
	return _GLEXTEMU_PFN_PREFIXED(UnmapBuffer)(GL_ARRAY_BUFFER);
	GLEXTEMU_POP_BUFFER
}
)

_GLEXTEMU_CMD
(
void, GetNamedBufferParameterivEXT, (GLuint buffer, GLenum pname, GLint* params),
{
	_GLEXTEMU_BUFFER(buffer)
	_GLEXTEMU_PFN_PREFIXED(GetBufferParameteriv)(GL_ARRAY_BUFFER, pname, params);
	GLEXTEMU_POP_BUFFER
}
)

_GLEXTEMU_CMD
(
void, GetNamedBufferPointervEXT, (GLuint buffer, GLenum pname, GLvoid** params),
{
	_GLEXTEMU_BUFFER(buffer)
	_GLEXTEMU_PFN_PREFIXED(GetBufferPointerv)(GL_ARRAY_BUFFER, pname, params);
	GLEXTEMU_POP_BUFFER
}
)

_GLEXTEMU_CMD
(
void, GetNamedBufferSubDataEXT, (GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid* data),
{
	_GLEXTEMU_BUFFER(buffer)
	_GLEXTEMU_PFN_PREFIXED(GetBufferSubData)(GL_ARRAY_BUFFER, offset, size, data);
	GLEXTEMU_POP_BUFFER
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform1fEXT, (GLuint program, GLint location, GLfloat v0),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform1f)(location, v0);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform2fEXT, (GLuint program, GLint location, GLfloat v0, GLfloat v1),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform2f)(location, v0, v1);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform3fEXT, (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform3f)(location, v0, v1, v2);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform4fEXT, (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform4f)(location, v0, v1, v2, v3);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform1iEXT, (GLuint program, GLint location, GLint v0),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform1i)(location, v0);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform2iEXT, (GLuint program, GLint location, GLint v0, GLint v1),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform2i)(location, v0, v1);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform3iEXT, (GLuint program, GLint location, GLint v0, GLint v1, GLint v2),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform3i)(location, v0, v1, v2);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform4iEXT, (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform4i)(location, v0, v1, v2, v3);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform1fvEXT, (GLuint program, GLint location, GLsizei count, const GLfloat* value),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform1fv)(location, count, value);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform2fvEXT, (GLuint program, GLint location, GLsizei count, const GLfloat* value),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform2fv)(location, count, value);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform3fvEXT, (GLuint program, GLint location, GLsizei count, const GLfloat* value),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform3fv)(location, count, value);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform4fvEXT, (GLuint program, GLint location, GLsizei count, const GLfloat* value),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform4fv)(location, count, value);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform1ivEXT, (GLuint program, GLint location, GLsizei count, const GLint* value),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform1iv)(location, count, value);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform2ivEXT, (GLuint program, GLint location, GLsizei count, const GLint* value),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform2iv)(location, count, value);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform3ivEXT, (GLuint program, GLint location, GLsizei count, const GLint* value),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform3iv)(location, count, value);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform4ivEXT, (GLuint program, GLint location, GLsizei count, const GLint* value),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform4iv)(location, count, value);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix2fvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(UniformMatrix2fv)(location, count, transpose, value);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix3fvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(UniformMatrix3fv)(location, count, transpose, value);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix4fvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(UniformMatrix4fv)(location, count, transpose, value);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix2x3fvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(UniformMatrix2x3fv)(location, count, transpose, value);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix3x2fvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(UniformMatrix3x2fv)(location, count, transpose, value);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix2x4fvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(UniformMatrix2x4fv)(location, count, transpose, value);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix4x2fvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(UniformMatrix4x2fv)(location, count, transpose, value);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix3x4fvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(UniformMatrix3x4fv)(location, count, transpose, value);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix4x3fvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(UniformMatrix4x3fv)(location, count, transpose, value);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, TextureBufferEXT, (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(TexBuffer)(target, internalformat, buffer);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, MultiTexBufferEXT, (GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexBuffer)(target, internalformat, buffer);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, TextureParameterIivEXT, (GLuint texture, GLenum target, GLenum pname, const GLint* params),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(TexParameterIiv)(target, pname, params);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, TextureParameterIuivEXT, (GLuint texture, GLenum target, GLenum pname, const GLuint* params),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(TexParameterIuiv)(target, pname, params);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, GetTextureParameterIivEXT, (GLuint texture, GLenum target, GLenum pname, GLint* params),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(GetTexParameterIiv)(target, pname, params);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, GetTextureParameterIuivEXT, (GLuint texture, GLenum target, GLenum pname, GLuint* params),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(GetTexParameterIuiv)(target, pname, params);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, MultiTexParameterIivEXT, (GLenum texunit, GLenum target, GLenum pname, const GLint* params),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexParameterIiv)(target, pname, params);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, MultiTexParameterIuivEXT, (GLenum texunit, GLenum target, GLenum pname, const GLuint* params),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexParameterIuiv)(target, pname, params);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexParameterIivEXT, (GLenum texunit, GLenum target, GLenum pname, GLint* params),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(GetTexParameterIiv)(target, pname, params);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexParameterIuivEXT, (GLenum texunit, GLenum target, GLenum pname, GLuint* params),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(GetTexParameterIuiv)(target, pname, params);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform1uiEXT, (GLuint program, GLint location, GLuint v0),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform1ui)(location, v0);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform2uiEXT, (GLuint program, GLint location, GLuint v0, GLuint v1),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform2ui)(location, v0, v1);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform3uiEXT, (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform3ui)(location, v0, v1, v2);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform4uiEXT, (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform4ui)(location, v0, v1, v2, v3);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform1uivEXT, (GLuint program, GLint location, GLsizei count, const GLuint* value),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform1uiv)(location, count, value);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform2uivEXT, (GLuint program, GLint location, GLsizei count, const GLuint* value),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform2uiv)(location, count, value);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform3uivEXT, (GLuint program, GLint location, GLsizei count, const GLuint* value),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform3uiv)(location, count, value);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform4uivEXT, (GLuint program, GLint location, GLsizei count, const GLuint* value),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(Uniform4uiv)(location, count, value);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParameters4fvEXT, (GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat* params),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(ProgramLocalParameters4fvEXT)(target, index, count, params);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParameterI4iEXT, (GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(ProgramLocalParameterI4iNV)(target, index, x, y, z, w);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParameterI4ivEXT, (GLuint program, GLenum target, GLuint index, const GLint* params),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(ProgramLocalParameterI4ivNV)(target, index, params);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParametersI4ivEXT, (GLuint program, GLenum target, GLuint index, GLsizei count, const GLint* params),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(ProgramLocalParametersI4ivNV)(target, index, count, params);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParameterI4uiEXT, (GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(ProgramLocalParameterI4uiNV)(target, index, x, y, z, w);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParameterI4uivEXT, (GLuint program, GLenum target, GLuint index, const GLuint* params),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(ProgramLocalParameterI4uivNV)(target, index, params);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParametersI4uivEXT, (GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint* params),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(ProgramLocalParametersI4uivNV)(target, index, count, params);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, NamedProgramStringEXT, (GLuint program, GLenum target, GLenum format, GLsizei len, const GLvoid* string),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(ProgramStringARB)(target, format, len, string);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParameter4dEXT, (GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(ProgramLocalParameter4dARB)(target, index, x, y, z, w);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParameter4dvEXT, (GLuint program, GLenum target, GLuint index, const GLdouble* params),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(ProgramLocalParameter4dvARB)(target, index, params);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParameter4fEXT, (GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(ProgramLocalParameter4fARB)(target, index, x, y, z, w);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParameter4fvEXT, (GLuint program, GLenum target, GLuint index, const GLfloat* params),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(ProgramLocalParameter4fvARB)(target, index, params);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, GetNamedProgramLocalParameterdvEXT, (GLuint program, GLenum target, GLuint index, GLdouble* params),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(GetProgramLocalParameterdvARB)(target, index, params);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, GetNamedProgramLocalParameterfvEXT, (GLuint program, GLenum target, GLuint index, GLfloat* params),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(GetProgramLocalParameterfvARB)(target, index, params);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, GetNamedProgramivEXT, (GLuint program, GLenum target, GLenum pname, GLint* params),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(GetProgramiv)(target, pname, params);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, GetNamedProgramStringEXT, (GLuint program, GLenum target, GLenum pname, GLvoid* string),
{
	_GLEXTEMU_PROGRAM(program)
	_GLEXTEMU_PFN_PREFIXED(GetProgramStringARB)(target, pname, string);
	GLEXTEMU_POP_PROGRAM
}
)

_GLEXTEMU_CMD
(
void, NamedRenderbufferStorageEXT, (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height),
{
	_GLEXTEMU_RENDERBUFFER(renderbuffer)
	_GLEXTEMU_PFN_PREFIXED(RenderbufferStorage)(GL_RENDERBUFFER, internalformat, width, height);
	GLEXTEMU_POP_RENDERBUFFER
}
)

_GLEXTEMU_CMD
(
void, GetNamedRenderbufferParameterivEXT, (GLuint renderbuffer, GLenum pname, GLint* params),
{
	_GLEXTEMU_RENDERBUFFER(renderbuffer)
	_GLEXTEMU_PFN_PREFIXED(GetRenderbufferParameteriv)(GL_RENDERBUFFER, pname, params);
	GLEXTEMU_POP_RENDERBUFFER
}
)

_GLEXTEMU_CMD
(
void, NamedRenderbufferStorageMultisampleEXT, (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height),
{
	_GLEXTEMU_RENDERBUFFER(renderbuffer)
	_GLEXTEMU_PFN_PREFIXED(RenderbufferStorageMultisample)(GL_RENDERBUFFER, samples, internalformat, width, height);
	GLEXTEMU_POP_RENDERBUFFER
}
)

_GLEXTEMU_CMD
(
void, NamedRenderbufferStorageMultisampleCoverageEXT, (GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height),
{
	_GLEXTEMU_RENDERBUFFER(renderbuffer)
	_GLEXTEMU_PFN_PREFIXED(RenderbufferStorageMultisampleCoverageNV)(GL_RENDERBUFFER, coverageSamples, colorSamples, internalformat, width, height);
	GLEXTEMU_POP_RENDERBUFFER
}
)

_GLEXTEMU_CMD
(
GLenum, CheckNamedFramebufferStatusEXT, (GLuint framebuffer, GLenum target),
{
	_GLEXTEMU_FRAMEBUFFER(framebuffer)
	return _GLEXTEMU_PFN_PREFIXED(CheckFramebufferStatus)(target);
	GLEXTEMU_POP_FRAMEBUFFER
}
)

_GLEXTEMU_CMD
(
void, NamedFramebufferTexture1DEXT, (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level),
{
	_GLEXTEMU_FRAMEBUFFER(framebuffer)
	_GLEXTEMU_PFN_PREFIXED(FramebufferTexture1D)(GL_FRAMEBUFFER, attachment, textarget, texture, level);
	GLEXTEMU_POP_FRAMEBUFFER
}
)

_GLEXTEMU_CMD
(
void, NamedFramebufferTexture2DEXT, (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level),
{
	_GLEXTEMU_FRAMEBUFFER(framebuffer)
	_GLEXTEMU_PFN_PREFIXED(FramebufferTexture2D)(GL_FRAMEBUFFER, attachment, textarget, texture, level);
	GLEXTEMU_POP_FRAMEBUFFER
}
)

_GLEXTEMU_CMD
(
void, NamedFramebufferTexture3DEXT, (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset),
{
	_GLEXTEMU_FRAMEBUFFER(framebuffer)
	_GLEXTEMU_PFN_PREFIXED(FramebufferTexture3D)(GL_FRAMEBUFFER, attachment, textarget, texture, level, zoffset);
	GLEXTEMU_POP_FRAMEBUFFER
}
)

_GLEXTEMU_CMD
(
void, NamedFramebufferRenderbufferEXT, (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer),
{
	_GLEXTEMU_FRAMEBUFFER(framebuffer)
	_GLEXTEMU_PFN_PREFIXED(FramebufferRenderbuffer)(GL_FRAMEBUFFER, attachment, renderbuffertarget, renderbuffer);
	GLEXTEMU_POP_FRAMEBUFFER
}
)

_GLEXTEMU_CMD
(
void, GetNamedFramebufferAttachmentParameterivEXT, (GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params),
{
	_GLEXTEMU_FRAMEBUFFER(framebuffer)
	_GLEXTEMU_PFN_PREFIXED(GetFramebufferAttachmentParameteriv)(GL_FRAMEBUFFER, attachment, pname, params);
	GLEXTEMU_POP_FRAMEBUFFER
}
)

_GLEXTEMU_CMD
(
void, GenerateTextureMipmapEXT, (GLuint texture, GLenum target),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(GenerateMipmap)(target);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, GenerateMultiTexMipmapEXT, (GLenum texunit, GLenum target),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(GenerateMipmap)(target);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, FramebufferDrawBufferEXT, (GLuint framebuffer, GLenum mode),
{
	_GLEXTEMU_FRAMEBUFFER(framebuffer)
	_GLEXTEMU_PFN_PREFIXED(DrawBuffer)(mode);
	GLEXTEMU_POP_FRAMEBUFFER
}
)

_GLEXTEMU_CMD
(
void, FramebufferDrawBuffersEXT, (GLuint framebuffer, GLsizei n, const GLenum* bufs),
{
	_GLEXTEMU_FRAMEBUFFER(framebuffer)
	_GLEXTEMU_PFN_PREFIXED(DrawBuffers)(n, bufs);
	GLEXTEMU_POP_FRAMEBUFFER
}
)

_GLEXTEMU_CMD
(
void, FramebufferReadBufferEXT, (GLuint framebuffer, GLenum mode),
{
	_GLEXTEMU_FRAMEBUFFER(framebuffer)
	_GLEXTEMU_PFN_PREFIXED(ReadBuffer)(mode);
	GLEXTEMU_POP_FRAMEBUFFER
}
)

_GLEXTEMU_CMD
(
void, NamedCopyBufferSubDataEXT, (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size),
{
	_GLEXTEMU_BUFFER_COPY(readBuffer, writeBuffer)
	_GLEXTEMU_PFN_PREFIXED(CopyBufferSubData)(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, readOffset, writeOffset, size);
	GLEXTEMU_POP_BUFFER_COPY
}
)

_GLEXTEMU_CMD
(
void, NamedFramebufferTextureEXT, (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level),
{
	_GLEXTEMU_FRAMEBUFFER(framebuffer)
	_GLEXTEMU_PFN_PREFIXED(FramebufferTexture)(GL_FRAMEBUFFER, attachment, texture, level);
	GLEXTEMU_POP_FRAMEBUFFER
}
)

_GLEXTEMU_CMD
(
void, NamedFramebufferTextureLayerEXT, (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer),
{
	_GLEXTEMU_FRAMEBUFFER(framebuffer)
	_GLEXTEMU_PFN_PREFIXED(FramebufferTextureLayer)(GL_FRAMEBUFFER, attachment, texture, level, layer);
	GLEXTEMU_POP_FRAMEBUFFER
}
)

_GLEXTEMU_CMD
(
void, NamedFramebufferTextureFaceEXT, (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face),
{
	_GLEXTEMU_FRAMEBUFFER(framebuffer)
	_GLEXTEMU_PFN_PREFIXED(FramebufferTextureFaceEXT)(GL_FRAMEBUFFER, attachment, texture, level, face);
	GLEXTEMU_POP_FRAMEBUFFER
}
)

_GLEXTEMU_CMD
(
void, TextureRenderbufferEXT, (GLuint texture, GLenum target, GLuint renderbuffer),
{
	_GLEXTEMU_TEXTURE(texture, target)
	_GLEXTEMU_PFN_PREFIXED(TexRenderbufferNV)(target, renderbuffer);
	GLEXTEMU_POP_TEXTURE(target)
}
)

_GLEXTEMU_CMD
(
void, MultiTexRenderbufferEXT, (GLenum texunit, GLenum target, GLuint renderbuffer),
{
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexRenderbufferNV)(target, renderbuffer);
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, VertexArrayVertexOffsetEXT, (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset),
{
	_GLEXTEMU_VERTEX_ARRAY(vaobj)
	_GLEXTEMU_BUFFER(buffer)
	_GLEXTEMU_PFN_PREFIXED(VertexPointer)(size, type, stride, (void *)offset);
	GLEXTEMU_POP_BUFFER
	GLEXTEMU_POP_VERTEX_ARRAY
}
)

_GLEXTEMU_CMD
(
void, VertexArrayColorOffsetEXT, (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset),
{
	_GLEXTEMU_VERTEX_ARRAY(vaobj)
	_GLEXTEMU_BUFFER(buffer)
	_GLEXTEMU_PFN_PREFIXED(ColorPointer)(size, type, stride, (void *)offset);
	GLEXTEMU_POP_BUFFER
	GLEXTEMU_POP_VERTEX_ARRAY
}
)

_GLEXTEMU_CMD
(
void, VertexArrayEdgeFlagOffsetEXT, (GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset),
{
	_GLEXTEMU_VERTEX_ARRAY(vaobj)
	_GLEXTEMU_BUFFER(buffer)
	_GLEXTEMU_PFN_PREFIXED(EdgeFlagPointer)(stride, (void *)offset);
	GLEXTEMU_POP_BUFFER
	GLEXTEMU_POP_VERTEX_ARRAY
}
)

_GLEXTEMU_CMD
(
void, VertexArrayIndexOffsetEXT, (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset),
{
	_GLEXTEMU_VERTEX_ARRAY(vaobj)
	_GLEXTEMU_BUFFER(buffer)
	_GLEXTEMU_PFN_PREFIXED(IndexPointer)(type, stride, (void *)offset);
	GLEXTEMU_POP_BUFFER
	GLEXTEMU_POP_VERTEX_ARRAY
}
)

_GLEXTEMU_CMD
(
void, VertexArrayNormalOffsetEXT, (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset),
{
	_GLEXTEMU_VERTEX_ARRAY(vaobj)
	_GLEXTEMU_BUFFER(buffer)
	_GLEXTEMU_PFN_PREFIXED(NormalPointer)(type, stride, (void *)offset);
	GLEXTEMU_POP_BUFFER
	GLEXTEMU_POP_VERTEX_ARRAY
}
)

_GLEXTEMU_CMD
(
void, VertexArrayTexCoordOffsetEXT, (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset),
{
	_GLEXTEMU_VERTEX_ARRAY(vaobj)
	_GLEXTEMU_BUFFER(buffer)
	_GLEXTEMU_PFN_PREFIXED(TexCoordPointer)(size, type, stride, (void *)offset);
	GLEXTEMU_POP_BUFFER
	GLEXTEMU_POP_VERTEX_ARRAY
}
)

_GLEXTEMU_CMD
(
void, VertexArrayMultiTexCoordOffsetEXT, (GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset),
{
	_GLEXTEMU_VERTEX_ARRAY(vaobj)
	_GLEXTEMU_BUFFER(buffer)
	_GLEXTEMU_ACTIVE_TEXTURE(texunit)
	_GLEXTEMU_PFN_PREFIXED(TexCoordPointer)(size, type, stride, (void *)offset);
	GLEXTEMU_POP_BUFFER
	GLEXTEMU_POP_VERTEX_ARRAY
	GLEXTEMU_POP_ACTIVE_TEXTURE
}
)

_GLEXTEMU_CMD
(
void, VertexArrayFogCoordOffsetEXT, (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset),
{
	_GLEXTEMU_VERTEX_ARRAY(vaobj)
	_GLEXTEMU_BUFFER(buffer)
	_GLEXTEMU_PFN_PREFIXED(FogCoordPointer)(type, stride, (void *)offset);
	GLEXTEMU_POP_BUFFER
	GLEXTEMU_POP_VERTEX_ARRAY
}
)

_GLEXTEMU_CMD
(
void, VertexArraySecondaryColorOffsetEXT, (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset),
{
	_GLEXTEMU_VERTEX_ARRAY(vaobj)
	_GLEXTEMU_BUFFER(buffer)
	_GLEXTEMU_PFN_PREFIXED(SecondaryColorPointer)(size, type, stride, (void *)offset);
	GLEXTEMU_POP_BUFFER
	GLEXTEMU_POP_VERTEX_ARRAY
}
)

_GLEXTEMU_CMD
(
void, VertexArrayVertexAttribOffsetEXT, (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset),
{
	_GLEXTEMU_VERTEX_ARRAY(vaobj)
	_GLEXTEMU_BUFFER(buffer)
	_GLEXTEMU_PFN_PREFIXED(VertexAttribPointer)(index, size, type, normalized, stride, (void *)offset);
	GLEXTEMU_POP_BUFFER
	GLEXTEMU_POP_VERTEX_ARRAY
}
)

_GLEXTEMU_CMD
(
void, VertexArrayVertexAttribIOffsetEXT, (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset),
{
	_GLEXTEMU_VERTEX_ARRAY(vaobj)
	_GLEXTEMU_BUFFER(buffer)
	_GLEXTEMU_PFN_PREFIXED(VertexAttribIPointer)(index, size, type, stride, (void *)offset);
	GLEXTEMU_POP_BUFFER
	GLEXTEMU_POP_VERTEX_ARRAY
}
)

_GLEXTEMU_CMD
(
void, EnableVertexArrayEXT, (GLuint vaobj, GLenum array),
{
	_GLEXTEMU_VERTEX_ARRAY(vaobj)
	_GLEXTEMU_PFN_PREFIXED(EnableClientState)(array);
	GLEXTEMU_POP_VERTEX_ARRAY
}
)

_GLEXTEMU_CMD
(
void, DisableVertexArrayEXT, (GLuint vaobj, GLenum array),
{
	_GLEXTEMU_VERTEX_ARRAY(vaobj)
	_GLEXTEMU_PFN_PREFIXED(DisableClientState)(array);
	GLEXTEMU_POP_VERTEX_ARRAY
}
)

_GLEXTEMU_CMD
(
void, EnableVertexArrayAttribEXT, (GLuint vaobj, GLuint index),
{
	_GLEXTEMU_VERTEX_ARRAY(vaobj)
	_GLEXTEMU_PFN_PREFIXED(EnableVertexAttribArray)(index);
	GLEXTEMU_POP_VERTEX_ARRAY
}
)

_GLEXTEMU_CMD
(
void, DisableVertexArrayAttribEXT, (GLuint vaobj, GLuint index),
{
	_GLEXTEMU_VERTEX_ARRAY(vaobj)
	_GLEXTEMU_PFN_PREFIXED(DisableVertexAttribArray)(index);
	GLEXTEMU_POP_VERTEX_ARRAY
}
)

_GLEXTEMU_CMD
(
void, GetVertexArrayIntegervEXT, (GLuint vaobj, GLenum pname, GLint* param),
{
	_GLEXTEMU_VERTEX_ARRAY(vaobj)
	_GLEXTEMU_PFN_PREFIXED(GetIntegerv)(pname, param);
	GLEXTEMU_POP_VERTEX_ARRAY
}
)

_GLEXTEMU_CMD
(
void, GetVertexArrayPointervEXT, (GLuint vaobj, GLenum pname, GLvoid** param),
{
	_GLEXTEMU_VERTEX_ARRAY(vaobj)
	_GLEXTEMU_PFN_PREFIXED(GetPointerv)(pname, param);
	GLEXTEMU_POP_VERTEX_ARRAY
}
)

_GLEXTEMU_CMD
(
void, GetVertexArrayIntegeri_vEXT, (GLuint vaobj, GLuint index, GLenum pname, GLint* param),
{
	_GLEXTEMU_VERTEX_ARRAY(vaobj)
	_GLEXTEMU_PFN_PREFIXED(GetIntegeri_v)(index, pname, param);
	GLEXTEMU_POP_VERTEX_ARRAY
}
)

_GLEXTEMU_CMD
(
void, GetVertexArrayPointeri_vEXT, (GLuint vaobj, GLuint index, GLenum pname, GLvoid** param),
{
	_GLEXTEMU_VERTEX_ARRAY(vaobj)
	_GLEXTEMU_PFN_PREFIXED(GetVertexAttribPointerv)(index, pname, param);
	GLEXTEMU_POP_VERTEX_ARRAY
}
)

_GLEXTEMU_CMD
(
void*, MapNamedBufferRangeEXT, (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access),
{
	_GLEXTEMU_BUFFER(buffer)
	return _GLEXTEMU_PFN_PREFIXED(MapBufferRange)(GL_ARRAY_BUFFER, offset, length, access);
	GLEXTEMU_POP_BUFFER
}
)

_GLEXTEMU_CMD
(
void, FlushMappedNamedBufferRangeEXT, (GLuint buffer, GLintptr offset, GLsizeiptr length),
{
	_GLEXTEMU_BUFFER(buffer)
	_GLEXTEMU_PFN_PREFIXED(FlushMappedBufferRange)(GL_ARRAY_BUFFER, offset, length);
	GLEXTEMU_POP_BUFFER
}
)



// Clean up namespace.
#undef _GLEXTEMU_INDEXED_ISENABLED
#undef _GLEXTEMU_INDEXED_GET
#undef _GLEXTEMU_BUFFER
#undef _GLEXTEMU_CLIENT_ACTIVE_TEXTURE
#undef _GLEXTEMU_TEXTURE
#undef _GLEXTEMU_ACTIVE_TEXTURE
#undef _GLEXTEMU_MATRIX_MODE
