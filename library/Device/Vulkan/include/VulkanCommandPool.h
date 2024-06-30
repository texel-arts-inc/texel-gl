#pragma once

#include <vector>
#include "Object.h"
#include "VulkanInterface.h"

namespace TexelGL {
namespace Vulkan {
    class CommandPool: public TexelGL::Object {
    private:
        static size_t const commandBufferCount;

    private:
        vk::raii::Device const &device;
        vk::raii::CommandPool commandPool;
        std::vector <vk::raii::CommandBuffer> commandBuffers = {};

    private:
        std::vector <vk::raii::CommandBuffer>
        createCommandBuffers(size_t count) const;

    public:
        CommandPool(vk::raii::Device const &device,
                    vk::raii::CommandPool &&commandPool);

        CommandPool(CommandPool &&other);

        virtual ~CommandPool(void);
    };
} // namespace Vulkan
} // TexelGL