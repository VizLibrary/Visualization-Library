/**************************************************************************************/
/*                                                                                    */
/*  Visualization Library                                                             */
/*  http://www.visualizationlibrary.com                                               */
/*                                                                                    */
/*  Copyright (c) 2005-2010, Michele Bosi                                             */
/*  All rights reserved.                                                              */
/*                                                                                    */
/*  Redistribution and use in source and binary forms, with or without modification,  */
/*  are permitted provided that the following conditions are met:                     */
/*                                                                                    */
/*  - Redistributions of source code must retain the above copyright notice, this     */
/*  list of conditions and the following disclaimer.                                  */
/*                                                                                    */
/*  - Redistributions in binary form must reproduce the above copyright notice, this  */
/*  list of conditions and the following disclaimer in the documentation and/or       */
/*  other materials provided with the distribution.                                   */
/*                                                                                    */
/*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND   */
/*  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED     */
/*  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE            */
/*  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR  */
/*  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES    */
/*  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;      */
/*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON    */
/*  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT           */
/*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS     */
/*  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                      */
/*                                                                                    */
/**************************************************************************************/

#ifndef OpenGL_INCLUDE_ONCE
#define OpenGL_INCLUDE_ONCE

#include <vlCore/OpenGLDefs.hpp>
#include <vlGraphics/config.hpp>

// mic fixme: we should probably inline these guys instead allowing them to reside on a DLL?

namespace vl
{

  VLGRAPHICS_EXPORT void VL_glBindBuffer( GLenum target, GLuint buffer );
  VLGRAPHICS_EXPORT void VL_glGenBuffers( GLsizei n, GLuint * buffers );
  VLGRAPHICS_EXPORT void VL_glDeleteBuffers( GLsizei n, const GLuint * buffers );
  VLGRAPHICS_EXPORT void VL_glBufferData( GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage );
  VLGRAPHICS_EXPORT void VL_glBufferSubData( GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data );
  VLGRAPHICS_EXPORT void* VL_glMapBuffer( GLenum target, GLenum access );
  VLGRAPHICS_EXPORT GLboolean VL_glUnmapBuffer( GLenum target );

  VLGRAPHICS_EXPORT void VL_glSecondaryColor3f( float, float, float );
  VLGRAPHICS_EXPORT void VL_glSecondaryColorPointer( GLint size, GLenum type, GLsizei stride, const GLvoid* pointer );
  VLGRAPHICS_EXPORT void VL_glFogCoordPointer( GLenum type,GLsizei stride,GLvoid* pointer );

  VLGRAPHICS_EXPORT void VL_glEnableVertexAttribArray( GLuint index );
  VLGRAPHICS_EXPORT void VL_glDisableVertexAttribArray( GLuint index );

  VLGRAPHICS_EXPORT void VL_glVertexAttribPointer( GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer );
  VLGRAPHICS_EXPORT void VL_glVertexAttribIPointer( GLuint name, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer );
  VLGRAPHICS_EXPORT void VL_glVertexAttribLPointer(GLuint name, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);

  VLGRAPHICS_EXPORT void VL_glClientActiveTexture( GLenum texture );
  VLGRAPHICS_EXPORT void VL_glActiveTexture( GLenum texture );

  VLGRAPHICS_EXPORT void VL_glBlendFuncSeparate( GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha );
  VLGRAPHICS_EXPORT void VL_glBlendEquationSeparate( GLenum modeRGB, GLenum modeAlpha );
  VLGRAPHICS_EXPORT void VL_glBlendEquation( GLenum mode );
  VLGRAPHICS_EXPORT void VL_glBlendColor( GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha );

  VLGRAPHICS_EXPORT void VL_glPointParameterf( GLenum pname, GLfloat param );
  VLGRAPHICS_EXPORT void VL_glPointParameterfv( GLenum pname, const GLfloat* params );
  VLGRAPHICS_EXPORT void VL_glPointParameteri( GLenum pname, GLenum param);

  VLGRAPHICS_EXPORT void VL_glStencilFuncSeparate( GLenum face, GLenum func, GLint ref, GLuint mask );
  VLGRAPHICS_EXPORT void VL_glStencilOpSeparate( GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass );

  VLGRAPHICS_EXPORT void VL_glSampleCoverage( GLclampf value, GLboolean invert );

  VLGRAPHICS_EXPORT void VL_glBindRenderbuffer( GLenum target, GLuint renderbuffer );
  VLGRAPHICS_EXPORT void VL_glDeleteRenderbuffers( GLsizei n, const GLuint *renderbuffers );
  VLGRAPHICS_EXPORT void VL_glGenRenderbuffers( GLsizei n, GLuint *renderbuffers );
  VLGRAPHICS_EXPORT void VL_glRenderbufferStorage( GLenum target, GLenum internalformat, GLsizei width, GLsizei height );
  VLGRAPHICS_EXPORT void VL_glGetRenderbufferParameteriv( GLenum target, GLenum pname, GLint *params );
  VLGRAPHICS_EXPORT GLboolean VL_glIsFramebuffer( GLuint framebuffer );
  VLGRAPHICS_EXPORT void VL_glBindFramebuffer( GLenum target, GLuint framebuffer );
  VLGRAPHICS_EXPORT void VL_glDeleteFramebuffers( GLsizei n, const GLuint *framebuffers );
  VLGRAPHICS_EXPORT void VL_glGenFramebuffers( GLsizei n, GLuint *framebuffers );
  VLGRAPHICS_EXPORT GLenum VL_glCheckFramebufferStatus( GLenum target );
  VLGRAPHICS_EXPORT void VL_glFramebufferTexture1D( GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level );
  VLGRAPHICS_EXPORT void VL_glFramebufferTexture2D( GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level );
  VLGRAPHICS_EXPORT void VL_glFramebufferTexture3D( GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset );
  VLGRAPHICS_EXPORT void VL_glFramebufferRenderbuffer( GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer );
  VLGRAPHICS_EXPORT void VL_glGetFramebufferAttachmentParameteriv( GLenum target, GLenum attachment, GLenum pname, GLint *params );
  VLGRAPHICS_EXPORT void VL_glGenerateMipmap( GLenum target );

  VLGRAPHICS_EXPORT void VL_glFramebufferTexture( GLenum target, GLenum attachment, GLuint texture, GLint level );
  VLGRAPHICS_EXPORT void VL_glFramebufferTextureLayer( GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer );
  VLGRAPHICS_EXPORT void VL_glRenderbufferStorageMultisample( GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height );
  VLGRAPHICS_EXPORT void VL_glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);

  VLGRAPHICS_EXPORT void VL_glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
  VLGRAPHICS_EXPORT void VL_glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount);
  VLGRAPHICS_EXPORT void VL_glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount, int basevertex);
  VLGRAPHICS_EXPORT void VL_glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, int basevertex);
  VLGRAPHICS_EXPORT void VL_glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices, int basevertex);

  VLGRAPHICS_EXPORT void VL_glProgramParameteri(GLuint program, GLenum pname, GLint value);
  VLGRAPHICS_EXPORT void VL_glBindFragDataLocation(GLuint program, GLuint colorNumber, const GLchar *name);

  VLGRAPHICS_EXPORT void VL_glUniform1uiv(GLint location, GLsizei count, const GLuint *value);
  VLGRAPHICS_EXPORT void VL_glUniform2uiv(GLint location, GLsizei count, const GLuint *value);
  VLGRAPHICS_EXPORT void VL_glUniform3uiv(GLint location, GLsizei count, const GLuint *value);
  VLGRAPHICS_EXPORT void VL_glUniform4uiv(GLint location, GLsizei count, const GLuint *value);
}

#endif
