#pragma once

#include "Entrypoints.h"

EXPORT_API void
glBindBuffersBase(TexelGL::GL::Enum target,
                  uint32_t first,
                  int32_t count,
                  uint32_t const *buffers);

EXPORT_API void
glBindBuffersRange(TexelGL::GL::Enum target,
                   uint32_t first,
                   int32_t count,
                   uint32_t const *buffers,
                   intptr_t const *offsets,
                   intptr_t const *sizes);