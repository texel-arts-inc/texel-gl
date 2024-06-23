#pragma once

#include "OpenGLDefinitions.h"

#if defined(_WIN32)
    #define EXPORT_API extern "C" __declspec(dllexport)
#else
    #define EXPORT_API  extern "C" __attribute__((visibility("default")))
#endif