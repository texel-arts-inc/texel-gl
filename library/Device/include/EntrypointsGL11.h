#pragma once

#include "Entrypoints.h"

EXPORT_API void
glBindTexture(TexelGL::GL::Enum target,
              uint32_t texture);

EXPORT_API void
glDeleteTextures(int32_t n,
                 uint32_t const *textures);

EXPORT_API void
glGenTextures(int32_t n,
              uint32_t const *textures);

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