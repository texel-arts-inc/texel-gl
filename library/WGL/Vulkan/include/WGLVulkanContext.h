#pragma once

#include "VulkanContext.h"
#include "WGLContext.h"

namespace TexelWGL {
namespace Vulkan {
    class Context: public TexelWGL::Context,
                   public TexelGL::Vulkan::Context {
    private:
        std::vector <std::string>
        getVulkanDeviceExtensions(void) const;

    public:
        Context(TexelWGL::Context::Descriptor const &descriptor,
                TexelWGL::Context::Handle handle,
                uint32_t apiVersion,
                std::shared_ptr <vk::raii::Instance> const &instance,
                std::shared_ptr <vk::raii::PhysicalDevice> const &physicalDevice,
                vk::raii::SurfaceKHR &&windowSurface);
        virtual ~Context(void);
    };
} // namespace Vulkan
} // namespace TexelGL