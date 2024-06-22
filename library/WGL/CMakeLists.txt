file(GLOB TEXEL_WGL_HEADERS include/*.h)
file(GLOB TEXEL_WGL_SOURCES *.cpp)

add_library(TexelWGLLibrary OBJECT ${TEXEL_WGL_HEADERS} ${TEXEL_WGL_SOURCES})
target_include_directories(TexelWGLLibrary PUBLIC include)
target_link_libraries(TexelWGLLibrary PUBLIC TexelGLDevice)

if(ENABLE_VULKAN)
    add_subdirectory(Vulkan)
endif()