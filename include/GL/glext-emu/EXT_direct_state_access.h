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

#if !__glext-emu_h_
	#error Please do not include this file directly, define GLEXTEMU_VENDOR_extension_names and include GL/glext-emu.h instead
#endif

_GLEXTEMU_CMD
(
void, ClientAttribDefaultEXT, (GLbitfield mask),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, PushClientAttribDefaultEXT, (GLbitfield mask),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MatrixLoadfEXT, (GLenum mode, const GLfloat *m),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MatrixLoaddEXT, (GLenum mode, const GLdouble *m),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MatrixMultfEXT, (GLenum mode, const GLfloat *m),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MatrixMultdEXT, (GLenum mode, const GLdouble *m),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MatrixLoadIdentityEXT, (GLenum mode),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MatrixRotatefEXT, (GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MatrixRotatedEXT, (GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MatrixScalefEXT, (GLenum mode, GLfloat x, GLfloat y, GLfloat z),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MatrixScaledEXT, (GLenum mode, GLdouble x, GLdouble y, GLdouble z),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MatrixTranslatefEXT, (GLenum mode, GLfloat x, GLfloat y, GLfloat z),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MatrixTranslatedEXT, (GLenum mode, GLdouble x, GLdouble y, GLdouble z),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MatrixFrustumEXT, (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MatrixOrthoEXT, (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MatrixPopEXT, (GLenum mode),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MatrixPushEXT, (GLenum mode),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MatrixLoadTransposefEXT, (GLenum mode, const GLfloat *m),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MatrixLoadTransposedEXT, (GLenum mode, const GLdouble *m),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MatrixMultTransposefEXT, (GLenum mode, const GLfloat *m),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MatrixMultTransposedEXT, (GLenum mode, const GLdouble *m),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, TextureParameterfEXT, (GLuint texture, GLenum target, GLenum pname, GLfloat param),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, TextureParameterfvEXT, (GLuint texture, GLenum target, GLenum pname, const GLfloat *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, TextureParameteriEXT, (GLuint texture, GLenum target, GLenum pname, GLint param),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, TextureParameterivEXT, (GLuint texture, GLenum target, GLenum pname, const GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, TextureImage1DEXT, (GLuint texture, GLenum target, GLint level, GLifmt internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, TextureImage2DEXT, (GLuint texture, GLenum target, GLint level, GLifmt internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, TextureSubImage1DEXT, (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, TextureSubImage2DEXT, (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CopyTextureImage1DEXT, (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CopyTextureImage2DEXT, (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CopyTextureSubImage1DEXT, (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CopyTextureSubImage2DEXT, (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetTextureImageEXT, (GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetTextureParameterfvEXT, (GLuint texture, GLenum target, GLenum pname, GLfloat *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetTextureParameterivEXT, (GLuint texture, GLenum target, GLenum pname, GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetTextureLevelParameterfvEXT, (GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetTextureLevelParameterivEXT, (GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, TextureImage3DEXT, (GLuint texture, GLenum target, GLint level, GLifmt internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, TextureSubImage3DEXT, (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CopyTextureSubImage3DEXT, (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexParameterfEXT, (GLenum texunit, GLenum target, GLenum pname, GLfloat param),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexParameterfvEXT, (GLenum texunit, GLenum target, GLenum pname, const GLfloat *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexParameteriEXT, (GLenum texunit, GLenum target, GLenum pname, GLint param),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexParameterivEXT, (GLenum texunit, GLenum target, GLenum pname, const GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexImage1DEXT, (GLenum texunit, GLenum target, GLint level, GLifmt internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexImage2DEXT, (GLenum texunit, GLenum target, GLint level, GLifmt internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexSubImage1DEXT, (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexSubImage2DEXT, (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CopyMultiTexImage1DEXT, (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CopyMultiTexImage2DEXT, (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CopyMultiTexSubImage1DEXT, (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CopyMultiTexSubImage2DEXT, (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexImageEXT, (GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexParameterfvEXT, (GLenum texunit, GLenum target, GLenum pname, GLfloat *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexParameterivEXT, (GLenum texunit, GLenum target, GLenum pname, GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexLevelParameterfvEXT, (GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexLevelParameterivEXT, (GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexImage3DEXT, (GLenum texunit, GLenum target, GLint level, GLifmt internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexSubImage3DEXT, (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CopyMultiTexSubImage3DEXT, (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, BindMultiTextureEXT, (GLenum texunit, GLenum target, GLuint texture),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, EnableClientStateIndexedEXT, (GLenum array, GLuint index),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, DisableClientStateIndexedEXT, (GLenum array, GLuint index),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexCoordPointerEXT, (GLenum texunit, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexEnvfEXT, (GLenum texunit, GLenum target, GLenum pname, GLfloat param),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexEnvfvEXT, (GLenum texunit, GLenum target, GLenum pname, const GLfloat *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexEnviEXT, (GLenum texunit, GLenum target, GLenum pname, GLint param),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexEnvivEXT, (GLenum texunit, GLenum target, GLenum pname, const GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexGendEXT, (GLenum texunit, GLenum coord, GLenum pname, GLdouble param),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexGendvEXT, (GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexGenfEXT, (GLenum texunit, GLenum coord, GLenum pname, GLfloat param),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexGenfvEXT, (GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexGeniEXT, (GLenum texunit, GLenum coord, GLenum pname, GLint param),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexGenivEXT, (GLenum texunit, GLenum coord, GLenum pname, const GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexEnvfvEXT, (GLenum texunit, GLenum target, GLenum pname, GLfloat *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexEnvivEXT, (GLenum texunit, GLenum target, GLenum pname, GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexGendvEXT, (GLenum texunit, GLenum coord, GLenum pname, GLdouble *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexGenfvEXT, (GLenum texunit, GLenum coord, GLenum pname, GLfloat *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexGenivEXT, (GLenum texunit, GLenum coord, GLenum pname, GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetFloatIndexedvEXT, (GLenum target, GLuint index, GLfloat *data),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetDoubleIndexedvEXT, (GLenum target, GLuint index, GLdouble *data),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetPointerIndexedvEXT, (GLenum target, GLuint index, GLvoid* *data),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CompressedTextureImage3DEXT, (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *bits),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CompressedTextureImage2DEXT, (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *bits),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CompressedTextureImage1DEXT, (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *bits),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CompressedTextureSubImage3DEXT, (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *bits),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CompressedTextureSubImage2DEXT, (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *bits),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CompressedTextureSubImage1DEXT, (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *bits),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetCompressedTextureImageEXT, (GLuint texture, GLenum target, GLint lod, GLvoid *img),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CompressedMultiTexImage3DEXT, (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *bits),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CompressedMultiTexImage2DEXT, (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *bits),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CompressedMultiTexImage1DEXT, (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *bits),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CompressedMultiTexSubImage3DEXT, (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *bits),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CompressedMultiTexSubImage2DEXT, (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *bits),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, CompressedMultiTexSubImage1DEXT, (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *bits),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetCompressedMultiTexImageEXT, (GLenum texunit, GLenum target, GLint lod, GLvoid *img),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedProgramStringEXT, (GLuint program, GLenum target, GLenum format, GLsizei len, const GLvoid *string),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParameter4dEXT, (GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParameter4dvEXT, (GLuint program, GLenum target, GLuint index, const GLdouble *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParameter4fEXT, (GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParameter4fvEXT, (GLuint program, GLenum target, GLuint index, const GLfloat *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetNamedProgramLocalParameterdvEXT, (GLuint program, GLenum target, GLuint index, GLdouble *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetNamedProgramLocalParameterfvEXT, (GLuint program, GLenum target, GLuint index, GLfloat *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetNamedProgramivEXT, (GLuint program, GLenum target, GLenum pname, GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetNamedProgramStringEXT, (GLuint program, GLenum target, GLenum pname, GLvoid *string),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParameters4fvEXT, (GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParameterI4iEXT, (GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParameterI4ivEXT, (GLuint program, GLenum target, GLuint index, const GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParametersI4ivEXT, (GLuint program, GLenum target, GLuint index, GLsizei count, const GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParameterI4uiEXT, (GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParameterI4uivEXT, (GLuint program, GLenum target, GLuint index, const GLuint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedProgramLocalParametersI4uivEXT, (GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetNamedProgramLocalParameterIivEXT, (GLuint program, GLenum target, GLuint index, GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetNamedProgramLocalParameterIuivEXT, (GLuint program, GLenum target, GLuint index, GLuint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, TextureParameterIivEXT, (GLuint texture, GLenum target, GLenum pname, const GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, TextureParameterIuivEXT, (GLuint texture, GLenum target, GLenum pname, const GLuint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetTextureParameterIivEXT, (GLuint texture, GLenum target, GLenum pname, GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetTextureParameterIuivEXT, (GLuint texture, GLenum target, GLenum pname, GLuint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexParameterIivEXT, (GLenum texunit, GLenum target, GLenum pname, const GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexParameterIuivEXT, (GLenum texunit, GLenum target, GLenum pname, const GLuint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexParameterIivEXT, (GLenum texunit, GLenum target, GLenum pname, GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetMultiTexParameterIuivEXT, (GLenum texunit, GLenum target, GLenum pname, GLuint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform1fEXT, (GLuint program, GLint location, GLfloat v0),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform2fEXT, (GLuint program, GLint location, GLfloat v0, GLfloat v1),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform3fEXT, (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform4fEXT, (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform1iEXT, (GLuint program, GLint location, GLint v0),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform2iEXT, (GLuint program, GLint location, GLint v0, GLint v1),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform3iEXT, (GLuint program, GLint location, GLint v0, GLint v1, GLint v2),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform4iEXT, (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform1fvEXT, (GLuint program, GLint location, GLsizei count, const GLfloat *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform2fvEXT, (GLuint program, GLint location, GLsizei count, const GLfloat *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform3fvEXT, (GLuint program, GLint location, GLsizei count, const GLfloat *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform4fvEXT, (GLuint program, GLint location, GLsizei count, const GLfloat *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform1ivEXT, (GLuint program, GLint location, GLsizei count, const GLint *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform2ivEXT, (GLuint program, GLint location, GLsizei count, const GLint *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform3ivEXT, (GLuint program, GLint location, GLsizei count, const GLint *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform4ivEXT, (GLuint program, GLint location, GLsizei count, const GLint *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix2fvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix3fvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix4fvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix2x3fvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix3x2fvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix2x4fvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix4x2fvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix3x4fvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix4x3fvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform1uiEXT, (GLuint program, GLint location, GLuint v0),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform2uiEXT, (GLuint program, GLint location, GLuint v0, GLuint v1),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform3uiEXT, (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform4uiEXT, (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform1uivEXT, (GLuint program, GLint location, GLsizei count, const GLuint *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform2uivEXT, (GLuint program, GLint location, GLsizei count, const GLuint *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform3uivEXT, (GLuint program, GLint location, GLsizei count, const GLuint *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform4uivEXT, (GLuint program, GLint location, GLsizei count, const GLuint *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedBufferDataEXT, (GLuint buffer, GLsizeiptr size, const GLvoid *data, GLenum usage),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedBufferSubDataEXT, (GLuint buffer, GLintptr offset, GLsizeiptr size, const GLvoid *data),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
GLvoid*, MapNamedBufferEXT, (GLuint buffer, GLenum access),
{
	(*(volatile void *)0) = 0;
	return 0;
}
)

_GLEXTEMU_CMD
(
GLboolean, UnmapNamedBufferEXT, (GLuint buffer),
{
	(*(volatile void *)0) = 0;
	return GL_FALSE;
}
)

_GLEXTEMU_CMD
(
GLvoid*, MapNamedBufferRangeEXT, (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access),
{
	(*(volatile void *)0) = 0;
	return 0;
}
)

_GLEXTEMU_CMD
(
void, FlushMappedNamedBufferRangeEXT, (GLuint buffer, GLintptr offset, GLsizeiptr length),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedCopyBufferSubDataEXT, (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetNamedBufferParameterivEXT, (GLuint buffer, GLenum pname, GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetNamedBufferPointervEXT, (GLuint buffer, GLenum pname, GLvoid* *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetNamedBufferSubDataEXT, (GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid *data),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, TextureBufferEXT, (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexBufferEXT, (GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedRenderbufferStorageEXT, (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetNamedRenderbufferParameterivEXT, (GLuint renderbuffer, GLenum pname, GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
GLenum, CheckNamedFramebufferStatusEXT, (GLuint framebuffer, GLenum target),
{
	(*(volatile void *)0) = 0;
	return GL_FRAMEBUFFER_UNSUPPORTED;
}
)

_GLEXTEMU_CMD
(
void, NamedFramebufferTexture1DEXT, (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedFramebufferTexture2DEXT, (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedFramebufferTexture3DEXT, (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedFramebufferRenderbufferEXT, (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetNamedFramebufferAttachmentParameterivEXT, (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GenerateTextureMipmapEXT, (GLuint texture, GLenum target),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GenerateMultiTexMipmapEXT, (GLenum texunit, GLenum target),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, FramebufferDrawBufferEXT, (GLuint framebuffer, GLenum mode),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, FramebufferDrawBuffersEXT, (GLuint framebuffer, GLsizei n, const GLenum *bufs),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, FramebufferReadBufferEXT, (GLuint framebuffer, GLenum mode),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, GetFramebufferParameterivEXT, (GLuint framebuffer, GLenum pname, GLint *params),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedRenderbufferStorageMultisampleEXT, (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedRenderbufferStorageMultisampleCoverageEXT, (GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedFramebufferTextureEXT, (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedFramebufferTextureLayerEXT, (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, NamedFramebufferTextureFaceEXT, (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, TextureRenderbufferEXT, (GLuint texture, GLenum target, GLuint renderbuffer),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, MultiTexRenderbufferEXT, (GLenum texunit, GLenum target, GLuint renderbuffer),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform1dEXT, (GLuint program, GLint location, GLdouble x),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform2dEXT, (GLuint program, GLint location, GLdouble x, GLdouble y),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform3dEXT, (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform4dEXT, (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform1dvEXT, (GLuint program, GLint location, GLsizei count, const GLdouble *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform2dvEXT, (GLuint program, GLint location, GLsizei count, const GLdouble *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform3dvEXT, (GLuint program, GLint location, GLsizei count, const GLdouble *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniform4dvEXT, (GLuint program, GLint location, GLsizei count, const GLdouble *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix2dvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix3dvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix4dvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix2x3dvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix2x4dvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix3x2dvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix3x4dvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix4x2dvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value),
{
	(*(volatile void *)0) = 0;
}
)

_GLEXTEMU_CMD
(
void, ProgramUniformMatrix4x3dvEXT, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value),
{
	(*(volatile void *)0) = 0;
}
)
