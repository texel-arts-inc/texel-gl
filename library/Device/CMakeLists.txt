file(GLOB TEXEL_GL_DEVICE_HEADERS include/*.h)
file(GLOB TEXEL_GL_DEVICE_SOURCES *.cpp)

add_library(TexelGLDevice OBJECT ${TEXEL_GL_DEVICE_HEADERS} ${TEXEL_GL_DEVICE_SOURCES})
target_include_directories(TexelGLDevice PUBLIC include)

if(ENABLE_VULKAN)
    add_subdirectory(Vulkan)
endif()