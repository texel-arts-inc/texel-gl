#pragma once

#include <vulkan/vulkan.hpp>
#include "Context.h"

namespace TexelGL {
namespace Vulkan {
    class Context: public virtual TexelGL::Context {
    protected:
        vk::PhysicalDevice const physicalDevice;
        vk::PhysicalDeviceProperties const physicalDeviceProperties = {};
        vk::PhysicalDeviceFeatures const physicalDeviceFeatures = {};

    protected:
        static std::string
        getPhysicalDeviceName(vk::PhysicalDevice const &physicalDevice);

    protected:
        Context(vk::PhysicalDevice const &physicalDevice);

    public:
        virtual ~Context(void);
    };
} // namespace Vulkan
} // namespace TexelGL