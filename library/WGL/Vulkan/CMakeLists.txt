find_package(Vulkan REQUIRED)

file(GLOB TEXEL_WGL_DEVICE_VULKAN_HEADERS include/*.h)
file(GLOB TEXEL_WGL_DEVICE_VULKAN_SOURCES *.cpp)

list(
    APPEND TEXEL_WGL_DEVICE_VULKAN_LIBRARY_DEPENDENCIES
    TexelGLDeviceVulkan
    TexelWGLLibrary
    Vulkan::Vulkan
)

add_library(TexelWGLDeviceVulkan OBJECT ${TEXEL_WGL_DEVICE_VULKAN_HEADERS} ${TEXEL_WGL_DEVICE_VULKAN_SOURCES})
target_include_directories(TexelWGLDeviceVulkan PRIVATE include)
target_link_libraries(TexelWGLDeviceVulkan PUBLIC ${TEXEL_WGL_DEVICE_VULKAN_LIBRARY_DEPENDENCIES})