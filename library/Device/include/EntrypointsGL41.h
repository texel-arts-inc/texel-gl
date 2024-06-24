#pragma once

#include "Entrypoints.h"

EXPORT_API void
glClearDepthf(float d);

EXPORT_API void
glShaderBinary(int32_t count,
               uint32_t const *shaders,
               TexelGL::GL::Enum binaryFormat,
               void const *binary,
               int32_t length);