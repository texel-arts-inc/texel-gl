#include <spirv_cross/spirv_glsl.hpp>
#include <spirv_reflect.hpp>
#include "ShaderCompiler.h"

TexelGL::ShaderCompiler::ShaderCompiler(void)
{
}

TexelGL::ShaderCompiler::~ShaderCompiler(void)
{
}

std::vector <uint32_t>
TexelGL::ShaderCompiler::convertGLSpirVToVulkan(std::span <uint32_t const> const &glSpirVByteCode)
{
    auto vulkanSpirVByteCode = std::vector <uint32_t> ();

    return vulkanSpirVByteCode;
}
