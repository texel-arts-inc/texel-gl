#pragma once

#include "Shader.h"
#include "VulkanInterface.h"

namespace TexelGL {
namespace Vulkan {
    class Shader: public TexelGL::Shader {

    public:
        Shader(void);

        virtual ~Shader(void);
    };
} // namespace Vulkan
} // TexelGL