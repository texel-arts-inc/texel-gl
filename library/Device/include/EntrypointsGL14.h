#pragma once

#include "Entrypoints.h"

EXPORT_API void
glBlendColor(float red,
             float green,
             float blue,
             float alpha);

EXPORT_API void
glBlendEquation(TexelGL::GL::Enum mode);

EXPORT_API void
glBlendFuncSeparate(TexelGL::GL::Enum sfactorRGB,
                    TexelGL::GL::Enum dfactorRGB,
                    TexelGL::GL::Enum sfactorAlpha,
                    TexelGL::GL::Enum dfactorAlpha);

EXPORT_API void
glMultiDrawArrays(TexelGL::GL::Enum mode,
                  int32_t const *first,
                  int32_t const * count,
                  int32_t drawcount);

EXPORT_API void
glMultiDrawElements(TexelGL::GL::Enum mode,
                    int32_t const *count,
                    TexelGL::GL::Enum type,
                    void const * const *indices,
                    int32_t drawcount);

EXPORT_API void
glPointParameterf(TexelGL::GL::Enum pname,
                 float param);

EXPORT_API void
glPointParameterfv(TexelGL::GL::Enum pname,
                   float const *params);

EXPORT_API void
glPointParameteri(TexelGL::GL::Enum pname,
                  int32_t param);

EXPORT_API void
glPointParameteriv(TexelGL::GL::Enum pname,
                   int32_t *params);