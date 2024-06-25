#include "VulkanRenderPass.h"

TexelGL::Vulkan::RenderPass::RenderPass(vk::RenderPass object) :
    object(object)
{
}

TexelGL::Vulkan::RenderPass::~RenderPass(void)
{
}

TexelGL::Vulkan::RenderPass::operator vk::RenderPass const &() const
{
    return this->object;
}