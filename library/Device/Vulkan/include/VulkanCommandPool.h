#pragma once

#include "Object.h"
#include "VulkanInterface.h"

namespace TexelGL {
namespace Vulkan {
    class CommandPool: public TexelGL::Object {
    private:
        vk::raii::CommandPool commandPool;

    public:
        CommandPool(vk::raii::CommandPool &&commandPool);

        CommandPool(CommandPool &&other);

        virtual ~CommandPool(void);
    };
} // namespace Vulkan
} // TexelGL