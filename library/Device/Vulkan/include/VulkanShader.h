#pragma once

#include <optional>
#include "Shader.h"
#include "VulkanInterface.h"

namespace TexelGL {
namespace Vulkan {
    class Shader: public TexelGL::Shader {
    private:
        vk::raii::Device const &device;
        std::optional <vk::raii::ShaderModule> shaderModule;

    protected:
        void
        compile(std::string const &entryPoint,
                std::vector <std::pair <uint32_t,
                                        uint32_t>> const &specializationConstants) override;

    public:
        Shader(vk::raii::Device const &device,
               std::shared_ptr <ShaderCompiler> const &shaderCompiler,
               TexelGL::GL::ShaderType shaderType);

        virtual ~Shader(void);
    };
} // namespace Vulkan
} // TexelGL