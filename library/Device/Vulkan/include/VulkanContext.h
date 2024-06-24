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
        size_t queueFamilyIndex = 0;
        vk::Device const device = nullptr;
        vk::SwapchainKHR const swapchain = nullptr;

    protected:
        static std::string
        getPhysicalDeviceName(vk::PhysicalDevice const &physicalDevice);

    protected:
        size_t
        getQueueFamilyIndex(void) const;

    private:
        vk::Device
        createDevice(std::vector <std::string> const &vulkanDeviceExtensions) const;

        vk::SwapchainKHR
        createSwapchain(uint32_t queueFamilyIndex) const;

        std::vector <std::string>
        getVulkanDeviceExtensions(void) const;

    protected:
        Context(vk::PhysicalDevice const &physicalDevice,
                std::vector <std::string> const &vulkanDeviceExtensions,
                vk::SurfaceKHR const &windowSurface);

    public:
        virtual ~Context(void);
    };
} // namespace Vulkan
} // namespace TexelGL