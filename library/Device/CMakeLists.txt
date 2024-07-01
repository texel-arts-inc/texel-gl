file(GLOB TEXEL_GL_DEVICE_HEADERS include/*.h)
file(GLOB TEXEL_GL_DEVICE_SOURCES *.cpp)

find_package(glslang REQUIRED)
find_package(spirv_cross_core REQUIRED)
find_package(spirv_cross_glsl REQUIRED)
find_package(spirv_cross_hlsl REQUIRED)
find_package(spirv_cross_msl REQUIRED)
find_package(spirv_cross_reflect REQUIRED)
find_package(spirv_cross_cpp REQUIRED)
find_package(spirv_cross_c REQUIRED)
find_package(SPIRV-Tools REQUIRED)

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
    APPEND TEXEL_GL_DEVICE_LIBRARY_DEPENDENCIES
    glslang::glslang
    glslang::glslang-default-resource-limits
    glslang::SPIRV
    spirv-cross-c
    spirv-cross-cpp
    spirv-cross-glsl
    spirv-cross-hlsl
    spirv-cross-msl
    spirv-cross-reflect
    ${SPIRV_TOOLS_TARGET}
)

add_library(TexelGLDevice OBJECT ${TEXEL_GL_DEVICE_HEADERS} ${TEXEL_GL_DEVICE_SOURCES})
target_include_directories(TexelGLDevice PUBLIC include)
target_link_libraries(TexelGLDevice PUBLIC ${TEXEL_GL_DEVICE_LIBRARY_DEPENDENCIES})

if(ENABLE_VULKAN)
    add_subdirectory(Vulkan)
endif()