#pragma once

#include <vk_mem_alloc.h>

#if defined _WIN32
    #define NOMINMAX 1
    #include <windows.h>

    #define VK_USE_PLATFORM_WIN32_KHR 1
    #include <vulkan/vulkan_win32.h>
#endif

#include <vulkan/vulkan_raii.hpp>