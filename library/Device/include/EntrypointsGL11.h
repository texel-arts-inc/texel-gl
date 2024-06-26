#pragma once

#include "Entrypoints.h"

EXPORT_API void
glBindTexture(TexelGL::GL::Enum target,
              uint32_t texture);

EXPORT_API void
glCopyTexImage1D(TexelGL::GL::Enum target,
                 int32_t level,
                 int32_t internalformat,
                 int32_t x,
                 int32_t y,
                 int32_t width,
                 int32_t border);

EXPORT_API void
glCopyTexImage2D(TexelGL::GL::Enum target,
                 int32_t level,
                 int32_t internalformat,
                 int32_t x,
                 int32_t y,
                 int32_t width,
                 int32_t height,
                 int32_t border);

EXPORT_API void
glCopyTexSubImage1D(TexelGL::GL::Enum target,
                    int32_t level,
                    int32_t xOffset,
                    int32_t x,
                    int32_t y,
                    int32_t width);
EXPORT_API void
glCopyTexSubImage2D(TexelGL::GL::Enum target,
                    int32_t level,
                    int32_t xOffset,
                    int32_t yOffset,
                    int32_t x,
                    int32_t y,
                    int32_t width,
                    int32_t height);

EXPORT_API void
glDeleteTextures(int32_t n,
                 uint32_t const *textures);

EXPORT_API void
glDrawArrays(TexelGL::GL::Enum mode,
             int32_t first,
             int32_t count);

EXPORT_API void
glDrawElements(TexelGL::GL::Enum mode,
               int32_t count,
               TexelGL::GL::Enum type,
               void const *indices);

EXPORT_API void
glGenTextures(int32_t n,
              uint32_t *textures);

EXPORT_API void
glGetPointerv(TexelGL::GL::Enum pname,
              void **params);

EXPORT_API uint8_t
glIsTexture(uint32_t texture);

EXPORT_API void
glPolygonOffset(float factor,
                float units);

EXPORT_API void
glTexSubImage1D(TexelGL::GL::Enum target,
                int32_t level,
                int32_t xOffset,
                int32_t width,
                TexelGL::GL::Enum format,
                TexelGL::GL::Enum type,
                void const *pixels);

EXPORT_API void
glTexSubImage2D(TexelGL::GL::Enum target,
                int32_t level,
                int32_t xOffset,
                int32_t yOffset,
                int32_t width,
                int32_t height,
                TexelGL::GL::Enum format,
                TexelGL::GL::Enum type,
                void const *pixels);