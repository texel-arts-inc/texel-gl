#include "ShaderCompiler.h"
#include "VulkanShader.h"

void
TexelGL::Vulkan::Shader::compile(std::string const &entryPoint,
                                 std::vector <std::pair <uint32_t,
                                                         uint32_t>> const &specializationConstants)
{
    auto spirV = std::vector <uint32_t> ();

    switch (this->state.binaryFormat) {
    case TexelGL::GL::ShaderBinaryFormatSpirV: {
        auto const &shaderData = this->state.shaderData;
        auto const glSpirVByteCode = std::span <uint32_t const> (reinterpret_cast <uint32_t const *> (shaderData.data()),
                                                                 reinterpret_cast <uint32_t const *> (shaderData.data() +
                                                                                                      shaderData.size()));

        spirV = this->shaderCompiler->convertGLSpirVToVulkan(this->shaderType,
                                                             glSpirVByteCode);
        break;
    }

    default:
        assert(false &&
               "Unsupported shader binary format.");
        break;
    }

    if (spirV.empty()) {
        return;
    }

    auto const shaderModuleCreateInformation = vk::ShaderModuleCreateInfo({},
                                                                           spirV);
    auto shaderModule = this->device.createShaderModule(shaderModuleCreateInformation);

    this->shaderModule = std::make_optional(std::move(shaderModule));
}

TexelGL::Vulkan::Shader::Shader(vk::raii::Device const &device,
                                std::shared_ptr <ShaderCompiler> const &shaderCompiler,
                                TexelGL::GL::ShaderType shaderType) :
    TexelGL::Shader::Shader(shaderCompiler,
                            shaderType),
    device(device)
{
}

TexelGL::Vulkan::Shader::~Shader(void)
{
}