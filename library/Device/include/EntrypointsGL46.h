#pragma once

#include "Entrypoints.h"

EXPORT_API void
glSpecializeShader(uint32_t shader,
                   char const *pEntryPoint,
                   uint32_t numSpecializationConstants,
                   uint32_t const *pConstantIndex,
                   uint32_t const *pConstantValue);