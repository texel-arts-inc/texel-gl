#pragma once

#include "Texture.h"
#include "VulkanInterface.h"

namespace TexelGL {
namespace Vulkan {
    class Texture: public TexelGL::Texture {

    public:
        Texture(void);

        virtual ~Texture(void);
    };
} // namespace Vulkan
} // TexelGL