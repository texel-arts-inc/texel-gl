#pragma once

#include "Entrypoints.h"

EXPORT_API void
glBindSampler(uint32_t sampler);

EXPORT_API void
glDeleteSamplers(int32_t n,
                 uint32_t *samplers);

EXPORT_API void
glGenSamplers(int32_t n,
              uint32_t *samplers);

EXPORT_API void
glSamplerParameterf(uint32_t sampler,
                    TexelGL::GL::Enum name,
                    float param);

EXPORT_API void
glSamplerParameterfv(uint32_t sampler,
                     TexelGL::GL::Enum name,
                     float *param);

EXPORT_API void
glSamplerParameteri(uint32_t sampler,
                    TexelGL::GL::Enum name,
                    int32_t param);

EXPORT_API void
glSamplerParameteriv(uint32_t sampler,
                     TexelGL::GL::Enum name,
                     int32_t *param);