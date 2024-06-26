#include "VulkanRenderPass.h"

TexelGL::Vulkan::RenderPass::RenderPass(vk::raii::RenderPass &&object) :
    object(std::move(object))
{
}

TexelGL::Vulkan::RenderPass::~RenderPass(void)
{
}

TexelGL::Vulkan::RenderPass::operator vk::RenderPass() const
{
    return this->object;
}