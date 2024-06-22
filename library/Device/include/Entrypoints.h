#pragma once

#if defined(_WIN32)
    #define EXPORT_API extern "C" __declspec(dllexport)
#endif