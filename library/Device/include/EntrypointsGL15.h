#pragma once

#include "Entrypoints.h"

EXPORT_API void
glBindBuffer(TexelGL::GL::Enum target,
             uint32_t buffer);

EXPORT_API void
glBufferData(TexelGL::GL::Enum target,
             intptr_t size,
             void const *data,
             TexelGL::GL::Enum usage);

EXPORT_API void
glDeleteBuffers(int32_t n,
                uint32_t const *buffers);

EXPORT_API void
glGenBuffers(int32_t n,
             uint32_t *buffers);

EXPORT_API uint8_t
glIsBuffer(uint32_t buffer);

EXPORT_API uint8_t
glUnmapBuffer(TexelGL::GL::Enum target);