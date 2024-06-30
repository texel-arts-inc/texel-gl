#pragma once

#include "Object.h"
#include "VulkanInterface.h"

namespace TexelGL {
namespace Vulkan {
    class CommandPool: public TexelGL::Object {

    public:
        CommandPool(void);

        virtual ~CommandPool(void);
    };
} // namespace Vulkan
} // TexelGL