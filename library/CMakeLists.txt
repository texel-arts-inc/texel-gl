project(TexelGLLibrary LANGUAGES CXX)

file(GLOB TEXEL_GL_HEADERS include/*.h)
file(GLOB TEXEL_GL_SOURCES *.cpp)

unset(TEXEL_GL_LIBRARY_INCLUDE_DIRECTORIES)
unset(TEXEL_GL_LIBRARY_DEPENDENCIES)

if(APPLE)
    set(TEXEL_GL_LIBRARY_NAME "OpenGL")
    set(TEXEL_GL_LIBRARY_TYPE SHARED)
elseif(EMSCRIPTEN)
    set(TEXEL_GL_LIBRARY_NAME "GL")
    set(TEXEL_GL_LIBRARY_TYPE STATIC)
elseif(UNIX)
    set(TEXEL_GL_LIBRARY_NAME "GL")
    set(TEXEL_GL_LIBRARY_TYPE SHARED)
elseif(WIN32)
    set(TEXEL_GL_LIBRARY_NAME "OpenGL32")
    set(TEXEL_GL_LIBRARY_TYPE SHARED)
endif()

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
find_package(Vulkan REQUIRED)

list(
    APPEND TEXEL_GL_LIBRARY_INCLUDE_DIRECTORIES
    include
    Vulkan::Headers
)

set(SPIRV_TOOLS_TARGET SPIRV-Tools)

if(NOT TARGET ${SPIRV_TOOLS_TARGET})
    set(SPIRV_TOOLS_TARGET SPIRV-Tools-static)
endif()

list(
    APPEND TEXEL_GL_LIBRARY_DEPENDENCIES
    glslang::glslang
    glslang::glslang-default-resource-limits
    glslang::SPIRV
    spirv-cross-c
    spirv-cross-cpp
    spirv-cross-glsl
    spirv-cross-hlsl
    spirv-cross-msl
    spirv-cross-reflect
    Vulkan::Vulkan
    ${SPIRV_TOOLS_TARGET}
)

add_subdirectory(Device)

if(WIN32)
    add_subdirectory(WGL)
    list(
        APPEND TEXEL_GL_LIBRARY_DEPENDENCIES
        TexelGLDevice
        TexelWGLLibrary
    )
endif()

add_library(TexelGLLibrary ${TEXEL_GL_LIBRARY_TYPE} ${TEXEL_GL_HEADERS} ${TEXEL_GL_SOURCES})
set_target_properties(TexelGLLibrary PROPERTIES OUTPUT_NAME ${TEXEL_GL_LIBRARY_NAME})
target_include_directories(TexelGLLibrary PRIVATE ${TEXEL_GL_LIBRARY_INCLUDE_DIRECTORIES})
target_link_libraries(TexelGLLibrary PUBLIC ${TEXEL_GL_LIBRARY_DEPENDENCIES})