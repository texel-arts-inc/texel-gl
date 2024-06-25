#pragma once

#include "Device.h"
#include <vulkan/vulkan.hpp>

namespace TexelGL {
namespace Vulkan {
    class Device: public virtual TexelGL::Device {
    protected:
        uint32_t apiVersion = VK_API_VERSION_1_1;
        vk::Instance const instance = nullptr;
        size_t physicalDeviceIndex = 0;
        vk::PhysicalDevice const physicalDevice = nullptr;

    private:
        static size_t
        getDefaultPhysicalDeviceIndex(void);

    private:
        vk::Instance
        createDefaultInstance(std::vector <std::string> const &vulkanInstanceExtensions);

        vk::PhysicalDevice
        createDefaultPhysicalDevice(void) const;

        std::vector <std::string>
        getVulkanInstanceExtensions(void) const;

    protected:
        Device(std::vector <std::string> const &vulkanInstanceExtensions);

    public:
        virtual ~Device(void);
    };
} // namespace Vulkan
} // namespace TexelGL