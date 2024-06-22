#include "WGLVulkanContext.h"

TexelWGL::Vulkan::Context::Context(TexelWGL::Context::Descriptor const &descriptor,
                                   TexelWGL::Context::Handle handle) :
    TexelWGL::Context(descriptor,
                      handle),
    TexelGL::Vulkan::Context()
{
}

TexelWGL::Vulkan::Context::~Context(void)
{
}