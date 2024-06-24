#pragma once

#include "VulkanContext.h"
#include "WGLContext.h"

namespace TexelWGL {
namespace Vulkan {
    class Context: public TexelWGL::Context,
                   public TexelGL::Vulkan::Context {
    public:
        Context(TexelWGL::Context::Descriptor const &descriptor,
                TexelWGL::Context::Handle handle,
                vk::PhysicalDevice const &physicalDevice);
        virtual ~Context(void);
    };
} // namespace Vulkan
} // namespace TexelGL