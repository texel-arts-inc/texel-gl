#pragma once

#include "Entrypoints.h"

EXPORT_API void
glAttachShader(uint32_t program,
               uint32_t shader);

EXPORT_API void
glBindAttribLocation(uint32_t program,
                     uint32_t index,
                     char const *name);

EXPORT_API void
glCompileShader(uint32_t shader);

EXPORT_API uint32_t
glCreateProgram(void);

EXPORT_API uint32_t
glCreateShader(TexelGL::GL::Enum shaderType);

EXPORT_API void
glDeleteProgram(uint32_t program);

EXPORT_API void
glDeleteShader(uint32_t shader);

EXPORT_API void
glDetachShader(uint32_t program,
               uint32_t shader);

EXPORT_API void
glDisableVertexAttribArray(uint32_t index);

EXPORT_API void
glDrawBuffers(int32_t n,
              TexelGL::GL::Enum const *bufs);

EXPORT_API void
glEnableVertexAttribArray(uint32_t index);

EXPORT_API void
glGetShaderiv(uint32_t shader,
              TexelGL::GL::Enum name,
              int32_t *params);

EXPORT_API void
glGetProgramiv(uint32_t program,
               TexelGL::GL::Enum name,
               int32_t *params);

EXPORT_API void
glGetUniformLocation(uint32_t program,
                     char const *name);

EXPORT_API void
glLinkProgram(uint32_t program);

EXPORT_API void
glShaderSource(uint32_t shader,
               int32_t count,
               char const * const *string,
               int32_t const *length);

EXPORT_API void
glUniform1i(int32_t location,
            int32_t v0);

EXPORT_API void
glUseProgram(uint32_t program);