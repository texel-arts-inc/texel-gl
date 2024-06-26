#pragma once

#include "Entrypoints.h"

EXPORT_API void
glCopyTexSubImage3D(TexelGL::GL::Enum target,
                    int32_t level,
                    int32_t xOffset,
                    int32_t yOffset,
                    int32_t zOffset,
                    int32_t x,
                    int32_t y,
                    int32_t width,
                    int32_t height);

EXPORT_API void
glDrawRangeElements(TexelGL::GL::Enum mode,
                    uint32_t start,
                    uint32_t end,
                    int32_t count,
                    TexelGL::GL::Enum type,
                    void const *indices);

EXPORT_API void
glTexImage3D(TexelGL::GL::Enum target,
             int32_t level,
             int32_t internalFormat,
             int32_t width,
             int32_t height,
             int32_t depth,
             int32_t border,
             TexelGL::GL::Enum format,
             TexelGL::GL::Enum type,
             void const *pixels);

EXPORT_API void
glTexSubImage3D(TexelGL::GL::Enum target,
                int32_t level,
                int32_t xOffset,
                int32_t yOffset,
                int32_t zOffset,
                int32_t width,
                int32_t height,
                int32_t depth,
                TexelGL::GL::Enum format,
                TexelGL::GL::Enum type,
                void const *pixels);