#pragma once

#include "Device.h"
#include <vulkan/vulkan.hpp>

namespace TexelGL {
namespace Vulkan {
    class Device: public virtual TexelGL::Device {
    protected:
        vk::Instance const instance = nullptr;
        size_t physicalDeviceIndex = 0;
        vk::PhysicalDevice const physicalDevice = nullptr;

    private:
        static vk::Instance
        createDefaultInstance(void);

        static size_t
        getDefaultPhysicalDeviceIndex(void);

    private:
        vk::PhysicalDevice
        createDefaultPhysicalDevice(void) const;

    protected:
        Device(void);

    public:
        virtual ~Device(void);
    };
} // namespace Vulkan
} // namespace TexelGL