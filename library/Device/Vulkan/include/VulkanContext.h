#pragma once

#include <vk_mem_alloc.h>
#include <vulkan/vulkan.hpp>
#include "Context.h"

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
        vk::PhysicalDevice const physicalDevice = nullptr;
        vk::PhysicalDeviceProperties const physicalDeviceProperties = {};
        vk::PhysicalDeviceFeatures const physicalDeviceFeatures = {};
        vk::SurfaceKHR const windowSurface = nullptr;
        std::pair <vk::Extent2D,
                   uint32_t> swapchainSurfaceExtentAndImageCount = {};
        std::pair <vk::Format,
                   vk::ColorSpaceKHR> swapchainSurfaceFormatAndColorSpace = {};
        size_t queueFamilyIndex = 0;
        vk::Device const device = nullptr;
        uint32_t swapchainId = 0;
        std::vector <uint32_t> swapchainImageIds = {};
        std::vector <uint32_t> swapchainImageViewIds = {};
        uint32_t swapchainRenderPassId = 0;
        uint32_t swapchainFramebufferId = 0;
        VmaAllocator memoryAllocator = nullptr;

    protected:
        static std::string
        getPhysicalDeviceName(vk::PhysicalDevice const &physicalDevice);

    private:
        vk::Device
        createDevice(std::vector <std::string> const &vulkanDeviceExtensions) const;

        std::vector <std::shared_ptr <Image>>
        createImages(std::shared_ptr <Swapchain> const &swapchain) const;

        std::vector <std::shared_ptr <ImageView>>
        createImageViews(std::vector <std::shared_ptr <Image>> const &images,
                         vk::Format format) const;

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
                vk::Instance const &instance,
                vk::PhysicalDevice const &physicalDevice,
                std::vector <std::string> const &vulkanDeviceExtensions,
                vk::SurfaceKHR const &windowSurface);

        virtual std::shared_ptr <TexelGL::Buffer>
        createBuffer(void) override;

    public:
        virtual ~Context(void);
    };
} // namespace Vulkan
} // namespace TexelGL