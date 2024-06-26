#include "VulkanFramebuffer.h"

TexelGL::Vulkan::Framebuffer::Framebuffer(vk::raii::Framebuffer &&object) :
    object(std::move(object))
{
}

TexelGL::Vulkan::Framebuffer::~Framebuffer(void)
{
}

TexelGL::Vulkan::Framebuffer::operator vk::Framebuffer() const
{
    return this->object;
}