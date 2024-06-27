#pragma once

#include "Device.h"
#include "VulkanInterface.h"

namespace TexelGL {
namespace Vulkan {
    class Device: public virtual TexelGL::Device {
    protected:
        vk::raii::Context context = {};
        uint32_t apiVersion = VK_API_VERSION_1_1;
        std::shared_ptr <vk::raii::Instance> instance = nullptr;
        size_t physicalDeviceIndex = 0;
        std::shared_ptr <vk::raii::PhysicalDevice> physicalDevice = nullptr;

    private:
        static size_t
        getDefaultPhysicalDeviceIndex(void);

    private:
        std::shared_ptr <vk::raii::Instance>
        createDefaultInstance(std::vector <std::string> const &vulkanInstanceLayers,
                              std::vector <std::string> const &vulkanInstanceExtensions);

        std::shared_ptr <vk::raii::PhysicalDevice>
        createDefaultPhysicalDevice(void) const;

        std::vector <std::string>
        getVulkanInstanceLayers(void) const;

        std::vector <std::string>
        getVulkanInstanceExtensions(void) const;

    protected:
        Device(std::vector <std::string> const &vulkanInstanceLayers,
               std::vector <std::string> const &vulkanInstanceExtensions);

    public:
        virtual ~Device(void);
    };
} // namespace Vulkan
} // namespace TexelGL