#pragma once

#include "Entrypoints.h"

EXPORT_API void
glCreateBuffers(int32_t n,
                uint32_t *buffers);

EXPORT_API void
glCreateFramebuffers(int32_t n,
                     uint32_t *framebuffers);

EXPORT_API void
glCreateRenderbuffers(int32_t n,
                      uint32_t *renderbuffers);

EXPORT_API void
glCreateSamplers(int32_t n,
                 uint32_t *samplers);

EXPORT_API void
glCreateVertexArrays(int32_t n,
                     uint32_t *arrays);