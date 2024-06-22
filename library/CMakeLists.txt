project(TexelGLLibrary LANGUAGES CXX)

file(GLOB TEXEL_GL_HEADERS include/*.h)
file(GLOB TEXEL_GL_SOURCES *.cpp)

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

add_subdirectory(Device)

list(
    APPEND TEXEL_GL_LIBRARY_DEPENDENCIES
    TexelGLDevice
)

if(ENABLE_VULKAN)
    list(
        APPEND TEXEL_GL_LIBRARY_DEPENDENCIES
        TexelGLDeviceVulkan
    )
endif()

if(WIN32)
    add_subdirectory(WGL)

    if(ENABLE_VULKAN)
        list(
            APPEND TEXEL_GL_LIBRARY_DEPENDENCIES
            TexelWGLDeviceVulkan
            TexelWGLLibrary
        )
    endif()
endif()

add_library(TexelGLLibrary ${TEXEL_GL_LIBRARY_TYPE} ${TEXEL_GL_HEADERS} ${TEXEL_GL_SOURCES})
set_target_properties(TexelGLLibrary PROPERTIES OUTPUT_NAME ${TEXEL_GL_LIBRARY_NAME})
target_include_directories(TexelGLLibrary PRIVATE include)
target_link_libraries(TexelGLLibrary PUBLIC ${TEXEL_GL_LIBRARY_DEPENDENCIES})