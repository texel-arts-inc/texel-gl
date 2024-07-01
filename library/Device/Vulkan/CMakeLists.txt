find_package(VulkanHeaders REQUIRED)
find_package(VulkanMemoryAllocator REQUIRED)

file(GLOB TEXEL_GL_DEVICE_VULKAN_HEADERS include/*.h)
file(GLOB TEXEL_GL_DEVICE_VULKAN_SOURCES *.cpp)

list(
    APPEND TEXEL_GL_DEVICE_VULKAN_INCLUDE_DIRECTORIES
    include
    Vulkan::Headers
)
list(
    APPEND TEXEL_GL_DEVICE_VULKAN_LIBRARY_DEPENDENCIES
    GPUOpen::VulkanMemoryAllocator
    TexelGLDevice
    ${SPIRV_TOOLS_TARGET}
)

add_library(TexelGLDeviceVulkan STATIC ${TEXEL_GL_DEVICE_VULKAN_HEADERS} ${TEXEL_GL_DEVICE_VULKAN_SOURCES})
target_include_directories(TexelGLDeviceVulkan PUBLIC ${TEXEL_GL_DEVICE_VULKAN_INCLUDE_DIRECTORIES})
target_link_libraries(TexelGLDeviceVulkan PUBLIC ${TEXEL_GL_DEVICE_VULKAN_LIBRARY_DEPENDENCIES})