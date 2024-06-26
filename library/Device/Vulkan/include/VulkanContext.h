#pragma once

#include "Context.h"
#include "VulkanInterface.h"

namespace TexelGL {
namespace Vulkan {
    class Buffer;
    class Framebuffer;
    class Image;
    class ImageView;
    class RenderPass;
    class Swapchain;

    class Context: public virtual TexelGL::Context {
    protected:
        std::shared_ptr <vk::raii::PhysicalDevice> physicalDevice = nullptr;
        vk::PhysicalDeviceProperties const physicalDeviceProperties = {};
        vk::PhysicalDeviceFeatures const physicalDeviceFeatures = {};
        vk::raii::SurfaceKHR const &windowSurface;
        std::pair <vk::Extent2D,
                   uint32_t> swapchainSurfaceExtentAndImageCount = {};
        std::pair <vk::Format,
                   vk::ColorSpaceKHR> swapchainSurfaceFormatAndColorSpace = {};
        size_t queueFamilyIndex = 0;
        vk::raii::Device const device = nullptr;
        uint32_t swapchainId = 0;
        uint32_t swapchainRenderPassId = 0;
        uint32_t swapchainFramebufferId = 0;
        VmaAllocator memoryAllocator = nullptr;

    protected:
        static std::string
        getPhysicalDeviceName(std::shared_ptr <vk::raii::PhysicalDevice> const &physicalDevice);

    private:
        vk::raii::Device
        createDevice(std::vector <std::string> const &vulkanDeviceExtensions) const;

        std::shared_ptr <Framebuffer>
        createFramebuffer(size_t width,
                          size_t height,
                          std::shared_ptr <RenderPass> const &renderPass,
                          std::vector <std::shared_ptr <ImageView>> const &vulkanImageViews) const;

        std::shared_ptr <Swapchain>
        createSwapchain(uint32_t queueFamilyIndex) const;

        size_t
        getQueueFamilyIndex(void) const;

        std::pair <vk::Extent2D,
                   uint32_t>
        getSwapchainSurfaceExtentAndImageCount(void) const;

        std::pair <vk::Format,
                   vk::ColorSpaceKHR>
        getSwapchainSurfaceFormatAndColorSpace(void) const;

        std::vector <std::string>
        getVulkanDeviceExtensions(void) const;

    protected:
        Context(uint32_t apiVersion,
                std::shared_ptr <vk::raii::Instance> const &instance,
                std::shared_ptr <vk::raii::PhysicalDevice> const &physicalDevice,
                std::vector <std::string> const &vulkanDeviceExtensions,
                vk::raii::SurfaceKHR &&windowSurface);

        virtual std::shared_ptr <TexelGL::Buffer>
        createBuffer(void) override;

    public:
        virtual ~Context(void);
    };
} // namespace Vulkan
} // namespace TexelGL