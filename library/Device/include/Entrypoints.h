#pragma once

#include <cstdint>

#if defined(_WIN32)
    #define EXPORT_API extern "C" __declspec(dllexport)
#endif

EXPORT_API void
glCreateRenderbuffers(int32_t n,
                      uint32_t *renderbuffers);
EXPORT_API void
glGenRenderbuffers(int32_t n,
                   uint32_t *renderbuffers);