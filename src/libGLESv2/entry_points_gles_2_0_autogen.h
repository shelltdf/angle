// GENERATED FILE - DO NOT EDIT.
// Generated by generate_entry_points.py using data from gl.xml.
//
// Copyright 2018 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// entry_points_gles_2_0_autogen.h:
//   Defines the GLES 2.0 entry points.

#ifndef LIBGLESV2_ENTRY_POINTS_GLES_2_0_AUTOGEN_H_
#define LIBGLESV2_ENTRY_POINTS_GLES_2_0_AUTOGEN_H_

#include <GLES2/gl2.h>
#include <export.h>

namespace gl
{
ANGLE_EXPORT void GL_APIENTRY AttachShader(GLuint program, GLuint shader);
ANGLE_EXPORT void GL_APIENTRY BindAttribLocation(GLuint program, GLuint index, const GLchar *name);
ANGLE_EXPORT void GL_APIENTRY BindFramebuffer(GLenum target, GLuint framebuffer);
ANGLE_EXPORT void GL_APIENTRY BindRenderbuffer(GLenum target, GLuint renderbuffer);
ANGLE_EXPORT void GL_APIENTRY BlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
ANGLE_EXPORT void GL_APIENTRY BlendEquation(GLenum mode);
ANGLE_EXPORT void GL_APIENTRY BlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
ANGLE_EXPORT void GL_APIENTRY BlendFuncSeparate(GLenum sfactorRGB,
                                                GLenum dfactorRGB,
                                                GLenum sfactorAlpha,
                                                GLenum dfactorAlpha);
ANGLE_EXPORT GLenum GL_APIENTRY CheckFramebufferStatus(GLenum target);
ANGLE_EXPORT void GL_APIENTRY CompileShader(GLuint shader);
ANGLE_EXPORT GLuint GL_APIENTRY CreateProgram();
ANGLE_EXPORT GLuint GL_APIENTRY CreateShader(GLenum type);
ANGLE_EXPORT void GL_APIENTRY DeleteFramebuffers(GLsizei n, const GLuint *framebuffers);
ANGLE_EXPORT void GL_APIENTRY DeleteProgram(GLuint program);
ANGLE_EXPORT void GL_APIENTRY DeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers);
ANGLE_EXPORT void GL_APIENTRY DeleteShader(GLuint shader);
ANGLE_EXPORT void GL_APIENTRY DetachShader(GLuint program, GLuint shader);
ANGLE_EXPORT void GL_APIENTRY DisableVertexAttribArray(GLuint index);
ANGLE_EXPORT void GL_APIENTRY EnableVertexAttribArray(GLuint index);
ANGLE_EXPORT void GL_APIENTRY FramebufferRenderbuffer(GLenum target,
                                                      GLenum attachment,
                                                      GLenum renderbuffertarget,
                                                      GLuint renderbuffer);
ANGLE_EXPORT void GL_APIENTRY FramebufferTexture2D(GLenum target,
                                                   GLenum attachment,
                                                   GLenum textarget,
                                                   GLuint texture,
                                                   GLint level);
ANGLE_EXPORT void GL_APIENTRY GenFramebuffers(GLsizei n, GLuint *framebuffers);
ANGLE_EXPORT void GL_APIENTRY GenRenderbuffers(GLsizei n, GLuint *renderbuffers);
ANGLE_EXPORT void GL_APIENTRY GenerateMipmap(GLenum target);
ANGLE_EXPORT void GL_APIENTRY GetActiveAttrib(GLuint program,
                                              GLuint index,
                                              GLsizei bufSize,
                                              GLsizei *length,
                                              GLint *size,
                                              GLenum *type,
                                              GLchar *name);
ANGLE_EXPORT void GL_APIENTRY GetActiveUniform(GLuint program,
                                               GLuint index,
                                               GLsizei bufSize,
                                               GLsizei *length,
                                               GLint *size,
                                               GLenum *type,
                                               GLchar *name);
ANGLE_EXPORT void GL_APIENTRY GetAttachedShaders(GLuint program,
                                                 GLsizei maxCount,
                                                 GLsizei *count,
                                                 GLuint *shaders);
ANGLE_EXPORT GLint GL_APIENTRY GetAttribLocation(GLuint program, const GLchar *name);
ANGLE_EXPORT void GL_APIENTRY GetFramebufferAttachmentParameteriv(GLenum target,
                                                                  GLenum attachment,
                                                                  GLenum pname,
                                                                  GLint *params);
ANGLE_EXPORT void GL_APIENTRY GetProgramInfoLog(GLuint program,
                                                GLsizei bufSize,
                                                GLsizei *length,
                                                GLchar *infoLog);
ANGLE_EXPORT void GL_APIENTRY GetProgramiv(GLuint program, GLenum pname, GLint *params);
ANGLE_EXPORT void GL_APIENTRY GetRenderbufferParameteriv(GLenum target,
                                                         GLenum pname,
                                                         GLint *params);
ANGLE_EXPORT void GL_APIENTRY GetShaderInfoLog(GLuint shader,
                                               GLsizei bufSize,
                                               GLsizei *length,
                                               GLchar *infoLog);
ANGLE_EXPORT void GL_APIENTRY GetShaderPrecisionFormat(GLenum shadertype,
                                                       GLenum precisiontype,
                                                       GLint *range,
                                                       GLint *precision);
ANGLE_EXPORT void GL_APIENTRY GetShaderSource(GLuint shader,
                                              GLsizei bufSize,
                                              GLsizei *length,
                                              GLchar *source);
ANGLE_EXPORT void GL_APIENTRY GetShaderiv(GLuint shader, GLenum pname, GLint *params);
ANGLE_EXPORT GLint GL_APIENTRY GetUniformLocation(GLuint program, const GLchar *name);
ANGLE_EXPORT void GL_APIENTRY GetUniformfv(GLuint program, GLint location, GLfloat *params);
ANGLE_EXPORT void GL_APIENTRY GetUniformiv(GLuint program, GLint location, GLint *params);
ANGLE_EXPORT void GL_APIENTRY GetVertexAttribPointerv(GLuint index, GLenum pname, void **pointer);
ANGLE_EXPORT void GL_APIENTRY GetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params);
ANGLE_EXPORT void GL_APIENTRY GetVertexAttribiv(GLuint index, GLenum pname, GLint *params);
ANGLE_EXPORT GLboolean GL_APIENTRY IsFramebuffer(GLuint framebuffer);
ANGLE_EXPORT GLboolean GL_APIENTRY IsProgram(GLuint program);
ANGLE_EXPORT GLboolean GL_APIENTRY IsRenderbuffer(GLuint renderbuffer);
ANGLE_EXPORT GLboolean GL_APIENTRY IsShader(GLuint shader);
ANGLE_EXPORT void GL_APIENTRY LinkProgram(GLuint program);
ANGLE_EXPORT void GL_APIENTRY ReleaseShaderCompiler();
ANGLE_EXPORT void GL_APIENTRY RenderbufferStorage(GLenum target,
                                                  GLenum internalformat,
                                                  GLsizei width,
                                                  GLsizei height);
ANGLE_EXPORT void GL_APIENTRY ShaderBinary(GLsizei count,
                                           const GLuint *shaders,
                                           GLenum binaryformat,
                                           const void *binary,
                                           GLsizei length);
ANGLE_EXPORT void GL_APIENTRY ShaderSource(GLuint shader,
                                           GLsizei count,
                                           const GLchar *const *string,
                                           const GLint *length);
ANGLE_EXPORT void GL_APIENTRY StencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask);
ANGLE_EXPORT void GL_APIENTRY StencilMaskSeparate(GLenum face, GLuint mask);
ANGLE_EXPORT void GL_APIENTRY StencilOpSeparate(GLenum face,
                                                GLenum sfail,
                                                GLenum dpfail,
                                                GLenum dppass);
ANGLE_EXPORT void GL_APIENTRY Uniform1f(GLint location, GLfloat v0);
ANGLE_EXPORT void GL_APIENTRY Uniform1fv(GLint location, GLsizei count, const GLfloat *value);
ANGLE_EXPORT void GL_APIENTRY Uniform1i(GLint location, GLint v0);
ANGLE_EXPORT void GL_APIENTRY Uniform1iv(GLint location, GLsizei count, const GLint *value);
ANGLE_EXPORT void GL_APIENTRY Uniform2f(GLint location, GLfloat v0, GLfloat v1);
ANGLE_EXPORT void GL_APIENTRY Uniform2fv(GLint location, GLsizei count, const GLfloat *value);
ANGLE_EXPORT void GL_APIENTRY Uniform2i(GLint location, GLint v0, GLint v1);
ANGLE_EXPORT void GL_APIENTRY Uniform2iv(GLint location, GLsizei count, const GLint *value);
ANGLE_EXPORT void GL_APIENTRY Uniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
ANGLE_EXPORT void GL_APIENTRY Uniform3fv(GLint location, GLsizei count, const GLfloat *value);
ANGLE_EXPORT void GL_APIENTRY Uniform3i(GLint location, GLint v0, GLint v1, GLint v2);
ANGLE_EXPORT void GL_APIENTRY Uniform3iv(GLint location, GLsizei count, const GLint *value);
ANGLE_EXPORT void GL_APIENTRY
Uniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
ANGLE_EXPORT void GL_APIENTRY Uniform4fv(GLint location, GLsizei count, const GLfloat *value);
ANGLE_EXPORT void GL_APIENTRY Uniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
ANGLE_EXPORT void GL_APIENTRY Uniform4iv(GLint location, GLsizei count, const GLint *value);
ANGLE_EXPORT void GL_APIENTRY UniformMatrix2fv(GLint location,
                                               GLsizei count,
                                               GLboolean transpose,
                                               const GLfloat *value);
ANGLE_EXPORT void GL_APIENTRY UniformMatrix3fv(GLint location,
                                               GLsizei count,
                                               GLboolean transpose,
                                               const GLfloat *value);
ANGLE_EXPORT void GL_APIENTRY UniformMatrix4fv(GLint location,
                                               GLsizei count,
                                               GLboolean transpose,
                                               const GLfloat *value);
ANGLE_EXPORT void GL_APIENTRY UseProgram(GLuint program);
ANGLE_EXPORT void GL_APIENTRY ValidateProgram(GLuint program);
ANGLE_EXPORT void GL_APIENTRY VertexAttrib1f(GLuint index, GLfloat x);
ANGLE_EXPORT void GL_APIENTRY VertexAttrib1fv(GLuint index, const GLfloat *v);
ANGLE_EXPORT void GL_APIENTRY VertexAttrib2f(GLuint index, GLfloat x, GLfloat y);
ANGLE_EXPORT void GL_APIENTRY VertexAttrib2fv(GLuint index, const GLfloat *v);
ANGLE_EXPORT void GL_APIENTRY VertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z);
ANGLE_EXPORT void GL_APIENTRY VertexAttrib3fv(GLuint index, const GLfloat *v);
ANGLE_EXPORT void GL_APIENTRY
VertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
ANGLE_EXPORT void GL_APIENTRY VertexAttrib4fv(GLuint index, const GLfloat *v);
ANGLE_EXPORT void GL_APIENTRY VertexAttribPointer(GLuint index,
                                                  GLint size,
                                                  GLenum type,
                                                  GLboolean normalized,
                                                  GLsizei stride,
                                                  const void *pointer);
}  // namespace gl

#endif  // LIBGLESV2_ENTRY_POINTS_GLES_2_0_AUTOGEN_H_
