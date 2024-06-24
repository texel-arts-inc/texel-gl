#include "WGLVulkanContext.h"

TexelWGL::Vulkan::Context::Context(TexelWGL::Context::Descriptor const &descriptor,
                                   TexelWGL::Context::Handle handle,
                                   vk::PhysicalDevice const &physicalDevice) :
    TexelGL::Context::Context(Context::getPhysicalDeviceName(physicalDevice)),
    TexelWGL::Context(descriptor,
                      handle,
                      this->TexelGL::Context::immutableState.renderer),
    TexelGL::Vulkan::Context(physicalDevice)
{
}

TexelWGL::Vulkan::Context::~Context(void)
{
}