#include "VulkanFramebuffer.h"

TexelGL::Vulkan::Framebuffer::Framebuffer(vk::Framebuffer object) :
    object(object)
{
}

TexelGL::Vulkan::Framebuffer::~Framebuffer(void)
{
}

TexelGL::Vulkan::Framebuffer::operator vk::Framebuffer const &() const
{
    return this->object;
}