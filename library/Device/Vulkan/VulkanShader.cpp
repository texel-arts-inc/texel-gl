#include "ShaderCompiler.h"
#include "VulkanShader.h"

void
TexelGL::Vulkan::Shader::compile(std::string const &entryPoint,
                                 std::vector <std::pair <uint32_t,
                                                         uint32_t>> const &specializationConstants)
{
    switch (this->state.binaryFormat) {
    case TexelGL::GL::ShaderBinaryFormatSpirV: {
        auto const &shaderData = this->state.shaderData;
        auto const glSpirVByteCode = std::span <uint32_t const> (reinterpret_cast <uint32_t const *> (shaderData.data()),
                                                                 reinterpret_cast <uint32_t const *> (shaderData.data() +
                                                                                                      shaderData.size()));

        this->shaderCompiler->convertGLSpirVToVulkan(glSpirVByteCode);
        break;
    }

    default:
        assert(false &&
               "Unsupported shader binary format.");
        break;
    }
}

TexelGL::Vulkan::Shader::Shader(std::shared_ptr <ShaderCompiler> const &shaderCompiler,
                                TexelGL::GL::ShaderType shaderType) :
    TexelGL::Shader::Shader(shaderCompiler,
                            shaderType)
{
}

TexelGL::Vulkan::Shader::~Shader(void)
{
}