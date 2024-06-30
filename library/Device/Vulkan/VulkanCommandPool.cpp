#include "VulkanCommandPool.h"

size_t const TexelGL::Vulkan::CommandPool::commandBufferCount = 3;

std::vector <vk::raii::CommandBuffer>
TexelGL::Vulkan::CommandPool::createCommandBuffers(size_t count) const
{
    auto const commandBufferAllocateInformation = vk::CommandBufferAllocateInfo(this->commandPool,
                                                                                vk::CommandBufferLevel::ePrimary,
                                                                                count);
    auto commandBuffers = this->device.allocateCommandBuffers(commandBufferAllocateInformation);

    return commandBuffers;
}

TexelGL::Vulkan::CommandPool::CommandPool(vk::raii::Device const &device,
                                          vk::raii::CommandPool &&commandPool) :
    device(device),
    commandPool(std::move(commandPool)),
    commandBuffers(this->createCommandBuffers(CommandPool::commandBufferCount))
{
}

TexelGL::Vulkan::CommandPool::CommandPool(TexelGL::Vulkan::CommandPool &&other) :
    CommandPool(other.device,
                std::move(other.commandPool))
{
}

TexelGL::Vulkan::CommandPool::~CommandPool(void)
{
}