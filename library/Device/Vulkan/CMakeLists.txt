file(GLOB TEXEL_GL_DEVICE_VULKAN_HEADERS include/*.h)
file(GLOB TEXEL_GL_DEVICE_VULKAN_SOURCES *.cpp)

find_package(glslang REQUIRED)
find_package(spirv_cross_core REQUIRED)
find_package(spirv_cross_glsl REQUIRED)
find_package(spirv_cross_hlsl REQUIRED)
find_package(spirv_cross_msl REQUIRED)
find_package(spirv_cross_reflect REQUIRED)
find_package(spirv_cross_cpp REQUIRED)
find_package(spirv_cross_c REQUIRED)
find_package(SPIRV-Tools REQUIRED)
find_package(VulkanHeaders REQUIRED)
find_package(VulkanMemoryAllocator REQUIRED)

list(
    APPEND TEXEL_GL_DEVICE_VULKAN_INCLUDE_DIRECTORIES
    include
    Vulkan::Headers
)

set(SPIRV_TOOLS_TARGET SPIRV-Tools)

if(NOT TARGET ${SPIRV_TOOLS_TARGET})
    set(SPIRV_TOOLS_TARGET SPIRV-Tools-static)
endif()

list(
    APPEND TEXEL_GL_DEVICE_VULKAN_LIBRARY_DEPENDENCIES
    glslang::glslang
    glslang::glslang-default-resource-limits
    glslang::SPIRV
    spirv-cross-c
    spirv-cross-cpp
    spirv-cross-glsl
    spirv-cross-hlsl
    spirv-cross-msl
    spirv-cross-reflect
    GPUOpen::VulkanMemoryAllocator
    TexelGLDevice
    ${SPIRV_TOOLS_TARGET}
)

add_library(TexelGLDeviceVulkan STATIC ${TEXEL_GL_DEVICE_VULKAN_HEADERS} ${TEXEL_GL_DEVICE_VULKAN_SOURCES})
target_include_directories(TexelGLDeviceVulkan PUBLIC ${TEXEL_GL_DEVICE_VULKAN_INCLUDE_DIRECTORIES})
target_link_libraries(TexelGLDeviceVulkan PUBLIC ${TEXEL_GL_DEVICE_VULKAN_LIBRARY_DEPENDENCIES})