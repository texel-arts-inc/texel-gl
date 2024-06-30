#pragma once

#include "Object.h"
#include "VulkanInterface.h"

namespace TexelGL {
namespace Vulkan {
    class Fence: public TexelGL::Object {

    public:
        Fence(void);

        virtual ~Fence(void);
    };
} // namespace Vulkan
} // TexelGL