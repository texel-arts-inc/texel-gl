cmake_minimum_required(VERSION 3.28)

set(TEXEL_GL_VERSION 1.0)

project(TexelGL VERSION ${TEXEL_GL_VERSION})

# Options
option(ENABLE_VULKAN "Enable Vulkan backend support" TRUE)

# Compiler flags
add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/EHsc>)   # Enable exceptions for MSVC
add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/MP>)     # Enable parallel build for MSVC
set(CMAKE_CXX_STANDARD 20)                              # Require C++ 20 language support
set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)               # Enable position independent code

add_subdirectory(library)