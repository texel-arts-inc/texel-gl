#pragma once

#include "Entrypoints.h"

EXPORT_API void
glClear(uint32_t mask);

EXPORT_API void
glClearColor(float red,
             float green,
             float blue,
             float alpha);

EXPORT_API void
glClearDepth(double depth);

EXPORT_API void
glFinish(void);

EXPORT_API void
glFlush(void);

EXPORT_API TexelGL::GL::Enum
glGetError(void);

EXPORT_API void
glGetFloatv(TexelGL::GL::Enum name,
            float &data);

EXPORT_API uint8_t const *
glGetString(TexelGL::GL::Enum name);

EXPORT_API void
glReadBuffer(TexelGL::GL::Enum src);

EXPORT_API void
glTexImage2D(TexelGL::GL::Enum target,
             int32_t level,
             int32_t internalformat,
             int32_t width,
             int32_t height,
             int32_t border,
             TexelGL::GL::Enum format,
             TexelGL::GL::Enum type,
             void const *pixels);

EXPORT_API void
glTexParameterf(TexelGL::GL::Enum target,
                TexelGL::GL::Enum pname,
                float param);

EXPORT_API void
glTexParameteri(TexelGL::GL::Enum target,
                TexelGL::GL::Enum pname,
                int32_t param);

EXPORT_API void
glViewport(int32_t x,
           int32_t y,
           int32_t width,
           int32_t height);