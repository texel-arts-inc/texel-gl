file(GLOB TEXEL_GLX_HEADERS include/*.h)
file(GLOB TEXEL_GLX_SOURCES *.cpp)

add_library(TexelGLXLibrary OBJECT ${TEXEL_GLX_HEADERS} ${TEXEL_GLX_SOURCES})
target_include_directories(TexelGLXLibrary PUBLIC include)
target_link_libraries(TexelGLXLibrary PUBLIC TexelGLDevice)

if(ENABLE_VULKAN)
    add_subdirectory(Vulkan)
endif()