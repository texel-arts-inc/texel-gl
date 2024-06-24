#pragma once

#include "Device.h"
#include <vulkan/vulkan.hpp>

namespace TexelGL {
namespace Vulkan {
    class Device : public virtual TexelGL::Device {
    protected:
        vk::Instance instance;
        std::vector <vk::PhysicalDevice> physicalDevices;

    protected:
        Device(void);

    public:
        virtual ~Device(void);
    };
} // namespace Vulkan
} // namespace TexelGL