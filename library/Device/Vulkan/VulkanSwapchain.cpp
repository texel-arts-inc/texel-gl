#include "VulkanSwapchain.h"

TexelGL::Vulkan::Swapchain::Swapchain(vk::SwapchainKHR object) :
    object(object)
{
}

TexelGL::Vulkan::Swapchain::~Swapchain(void)
{
}

TexelGL::Vulkan::Swapchain::operator vk::SwapchainKHR const &() const
{
    return this->object;
}