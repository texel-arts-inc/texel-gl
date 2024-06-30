#include "VulkanCommandPool.h"

TexelGL::Vulkan::CommandPool::CommandPool(vk::raii::CommandPool &&commandPool) :
    commandPool(std::move(commandPool))
{
}

TexelGL::Vulkan::CommandPool::CommandPool(TexelGL::Vulkan::CommandPool &&other) :
    CommandPool(std::move(other.commandPool))
{
}

TexelGL::Vulkan::CommandPool::~CommandPool(void)
{
}