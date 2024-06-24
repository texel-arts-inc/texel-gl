#pragma once

#include <vulkan/vulkan.hpp>
#include "Context.h"

namespace TexelGL {
namespace Vulkan {
    class Context: public virtual TexelGL::Context {
    protected:
        vk::PhysicalDevice const physicalDevice = nullptr;
        vk::PhysicalDeviceProperties const physicalDeviceProperties = {};
        vk::PhysicalDeviceFeatures const physicalDeviceFeatures = {};
        vk::SurfaceKHR const windowSurface = nullptr;
        vk::Device const device = nullptr;

    protected:
        static std::string
        getPhysicalDeviceName(vk::PhysicalDevice const &physicalDevice);

    private:
        vk::Device
        createDevice(std::vector <std::string> const &vulkanDeviceExtensions) const;

        std::vector <std::string>
        getVulkanDeviceExtensions(void) const;

    protected:
        Context(vk::PhysicalDevice const &physicalDevice,
                vk::SurfaceKHR const &windowSurface,
            std::vector <std::string> const& vulkanDeviceExtensions);

    public:
        virtual ~Context(void);
    };
} // namespace Vulkan
} // namespace TexelGL