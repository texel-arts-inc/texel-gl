#include "VulkanBuffer.h"
#include "VulkanContext.h"
#include "VulkanFramebuffer.h"
#include "VulkanImage.h"
#include "VulkanImageView.h"
#include "VulkanRenderPass.h"
#include "VulkanSwapchain.h"

std::string
TexelGL::Vulkan::Context::getPhysicalDeviceName(vk::PhysicalDevice const &physicalDevice)
{
    auto const &properties = physicalDevice.getProperties();

    return std::string(&properties.deviceName[0]);
}

vk::Device
TexelGL::Vulkan::Context::createDevice(std::vector <std::string> const &vulkanDeviceExtensions) const
{
    auto const &physicalDevice = this->physicalDevice;
    auto const queueFamilyIndex = this->queueFamilyIndex;
    auto const defaultVulkanDeviceExtensions = this->getVulkanDeviceExtensions();
    auto vulkanDeviceExtensionPointers = std::vector <char const *> ();

    for (auto const &vulkanDeviceExtension: defaultVulkanDeviceExtensions) {
        vulkanDeviceExtensionPointers.push_back(vulkanDeviceExtension.c_str());
    }

    for (auto const &vulkanDeviceExtension: vulkanDeviceExtensions) {
        vulkanDeviceExtensionPointers.push_back(vulkanDeviceExtension.c_str());
    }

    auto const queuePriority = 0.0f;
    auto const queuePriorities = std::vector <float> {
        queuePriority,
    };
    auto const queueCreateInformation = vk::DeviceQueueCreateInfo({},
                                                                  queueFamilyIndex,
                                                                  queuePriorities);
    auto const queueCreateInformationArray = std::vector <vk::DeviceQueueCreateInfo> {
        queueCreateInformation,
    };

    auto const deviceCreateInformation = vk::DeviceCreateInfo({},
                                                              queueCreateInformationArray,
                                                              {},
                                                              vulkanDeviceExtensionPointers);
    auto const device = physicalDevice.createDevice(deviceCreateInformation);

    return device;
}

std::vector <std::shared_ptr <TexelGL::Vulkan::Image>>
TexelGL::Vulkan::Context::createImages(std::shared_ptr <Swapchain> const &swapchain) const
{
    auto const images = this->device.getSwapchainImagesKHR(*swapchain);
    auto vulkanImages = std::vector <std::shared_ptr <Image>> ();

    for (auto &image: images) {
        vulkanImages.push_back(std::make_shared <Image> (image));
    }

    return vulkanImages;
}

std::vector <std::shared_ptr <TexelGL::Vulkan::ImageView>>
TexelGL::Vulkan::Context::createImageViews(std::vector <std::shared_ptr <Image>> const &images,
                                           vk::Format format) const
{
    auto vulkanImageViews = std::vector <std::shared_ptr <ImageView>> ();

    for (auto const &image: images) {
        auto const imageViewCreateInformation = vk::ImageViewCreateInfo({},
                                                                        *image,
                                                                        vk::ImageViewType::e2D,
                                                                        format,
                                                                        {},
                                                                        { vk::ImageAspectFlagBits::eColor,
                                                                          0,
                                                                          1,
                                                                          0,
                                                                          1 });
        auto imageView = this->device.createImageView(imageViewCreateInformation);

        vulkanImageViews.push_back(std::make_shared <ImageView> (imageView));
    }

    return vulkanImageViews;
}

std::shared_ptr <TexelGL::Vulkan::Framebuffer>
TexelGL::Vulkan::Context::createFramebuffer(size_t width,
                                            size_t height,
                                            std::shared_ptr <RenderPass> const &renderPass,
                                            std::vector <std::shared_ptr <ImageView>> const &vulkanImageViews) const
{
    auto imageViews = std::vector <vk::ImageView> ();

    for (auto const &vulkanImageView: vulkanImageViews) {
        imageViews.push_back(*vulkanImageView);
    }

    auto const framebufferCreateInfo = vk::FramebufferCreateInfo(vk::FramebufferCreateFlags(),
                                                                 *renderPass,
                                                                 imageViews,
                                                                 width,
                                                                 height,
                                                                 1);
    auto const framebuffer = this->device.createFramebuffer(framebufferCreateInfo);
    auto const vulkanFramebuffer = std::make_shared <Framebuffer> (framebuffer);

    return vulkanFramebuffer;
}

std::shared_ptr <TexelGL::Vulkan::Swapchain>
TexelGL::Vulkan::Context::createSwapchain(uint32_t queueFamilyIndex) const
{
    auto const &windowSurface = this->windowSurface;
    auto const surfaceCapabilities = physicalDevice.getSurfaceCapabilitiesKHR(windowSurface);
    auto const defaultImageCount = uint32_t(3);
    auto const imageCount = std::clamp(defaultImageCount,
                                       surfaceCapabilities.minImageCount,
                                       surfaceCapabilities.maxImageCount);
    auto const surfaceFormat = this->swapchainSurfaceFormatAndColorSpace.first;
    auto const colorSpace = this->swapchainSurfaceFormatAndColorSpace.second;
    auto const swapchainExtent = surfaceCapabilities.currentExtent;
    auto const preTransform = vk::SurfaceTransformFlagBitsKHR::eIdentity;
    auto const compositeAlpha = vk::CompositeAlphaFlagBitsKHR::eOpaque;
    auto const swapchainPresentMode = vk::PresentModeKHR::eFifo;
    auto const queueFamilyIndices = std::vector <uint32_t> {
        static_cast <uint32_t> (queueFamilyIndex),
    };
    auto const swapchainCreateInformation = vk::SwapchainCreateInfoKHR({},
                                                                       windowSurface,
                                                                       imageCount,
                                                                       surfaceFormat,
                                                                       colorSpace,
                                                                       swapchainExtent,
                                                                       1,
                                                                       vk::ImageUsageFlagBits::eColorAttachment,
                                                                       vk::SharingMode::eExclusive,
                                                                       queueFamilyIndices,
                                                                       preTransform,
                                                                       compositeAlpha,
                                                                       swapchainPresentMode,
                                                                       false,
                                                                       nullptr);
    auto const swapchain = this->device.createSwapchainKHR(swapchainCreateInformation);
    auto const vulkanSwapchain = std::make_shared <Swapchain> (swapchain);

    return vulkanSwapchain;
}

size_t
TexelGL::Vulkan::Context::getQueueFamilyIndex(void) const
{
    auto const &physicalDevice = this->physicalDevice;
    auto const queueFamilyProperties = physicalDevice.getQueueFamilyProperties();
    auto graphicsQueueFamilyIndex = queueFamilyProperties.size();

    for (auto i = size_t(0);
         i < queueFamilyProperties.size();
         ++i) {
        auto const &queueFamilyProperty = queueFamilyProperties[i];
        auto const &flags = queueFamilyProperty.queueFlags;
        auto const graphicsSupported = flags & vk::QueueFlagBits::eGraphics;
        auto const presentSupported = physicalDevice.getSurfaceSupportKHR(i,
                                                                          windowSurface);

        if (graphicsSupported &&
            presentSupported) {
            graphicsQueueFamilyIndex = i;
            break;
        }
    }

    if (graphicsQueueFamilyIndex ==
        queueFamilyProperties.size()) {
        assert(false &&
               "Failed to find a suitable graphics and presentation combination.");
        return -1;
    }

    return graphicsQueueFamilyIndex;
}

std::pair <vk::Extent2D,
           uint32_t>
TexelGL::Vulkan::Context::getSwapchainSurfaceExtentAndImageCount(void) const
{
    auto const &windowSurface = this->windowSurface;
    auto const surfaceCapabilities = physicalDevice.getSurfaceCapabilitiesKHR(windowSurface);
    auto const defaultImageCount = uint32_t(3);
    auto const imageCount = std::clamp(defaultImageCount,
                                       surfaceCapabilities.minImageCount,
                                       surfaceCapabilities.maxImageCount);
    auto const swapchainExtent = surfaceCapabilities.currentExtent;

    return std::make_pair(swapchainExtent,
                          imageCount);
}

std::pair <vk::Format,
           vk::ColorSpaceKHR>
TexelGL::Vulkan::Context::getSwapchainSurfaceFormatAndColorSpace(void) const
{
    auto const &windowSurface = this->windowSurface;
    auto const &physicalDevice = this->physicalDevice;
    auto const surfaceFormats = physicalDevice.getSurfaceFormatsKHR(windowSurface);
    auto surfaceFormat = vk::Format::eUndefined;
    auto colorSpace = vk::ColorSpaceKHR::eSrgbNonlinear;

    for (auto i = size_t(0);
         i < surfaceFormats.size();
         ++i) {

        if (surfaceFormats[i].format !=
            vk::Format::eUndefined) {
            surfaceFormat = surfaceFormats[i].format;
            colorSpace = surfaceFormats[i].colorSpace;
            break;
        }
    }

    if (surfaceFormat ==
        vk::Format::eUndefined) {
        surfaceFormat = surfaceFormat = vk::Format::eB8G8R8A8Unorm;
    }

    return std::make_pair(surfaceFormat,
                          colorSpace);
}

std::vector <std::string>
TexelGL::Vulkan::Context::getVulkanDeviceExtensions(void) const
{
    auto vulkanDeviceExtensions = std::vector <std::string> {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME,
    };

    return vulkanDeviceExtensions;
}

TexelGL::Vulkan::Context::Context(uint32_t apiVersion,
                                  vk::Instance const &instance,
                                  vk::PhysicalDevice const &physicalDevice,
                                  std::vector <std::string> const &vulkanDeviceExtensions,
                                  vk::SurfaceKHR const &windowSurface) :
    TexelGL::Context::Context(Context::getPhysicalDeviceName(physicalDevice)),
    physicalDevice(physicalDevice),
    physicalDeviceProperties(this->physicalDevice.getProperties()),
    physicalDeviceFeatures(this->physicalDevice.getFeatures()),
    windowSurface(windowSurface),
    swapchainSurfaceExtentAndImageCount(this->getSwapchainSurfaceExtentAndImageCount()),
    swapchainSurfaceFormatAndColorSpace(this->getSwapchainSurfaceFormatAndColorSpace()),
    queueFamilyIndex(this->getQueueFamilyIndex()),
    device(this->createDevice(vulkanDeviceExtensions))
{
    auto &objectTable = this->objectTable;
    auto const swapchain = this->createSwapchain(queueFamilyIndex);
    auto const swapchainImages = this->createImages(swapchain);
    auto const swapchainSurfaceExtent = this->swapchainSurfaceExtentAndImageCount.first;
    auto const swapchainSurfaceFormat = this->swapchainSurfaceFormatAndColorSpace.first;
    auto const swapchainImageViews = this->createImageViews(swapchainImages,
                                                            swapchainSurfaceFormat);
    auto const colorImageLoadOperation = vk::AttachmentLoadOp::eClear;
    auto const colorImageFinalLayout = vk::ImageLayout::ePresentSrcKHR;
    auto const swapchainColorAttachmentDescription = vk::AttachmentDescription({},
                                                                               swapchainSurfaceFormat,
                                                                               vk::SampleCountFlagBits::e1,
                                                                               colorImageLoadOperation,
                                                                               vk::AttachmentStoreOp::eStore,
                                                                               vk::AttachmentLoadOp::eDontCare,
                                                                               vk::AttachmentStoreOp::eDontCare,
                                                                               vk::ImageLayout::eUndefined,
                                                                               colorImageFinalLayout);
    auto const swapchainAttachmentDescriptions = std::vector <vk::AttachmentDescription> (swapchainImages.size(),
                                                                                          swapchainColorAttachmentDescription);
    auto const swapchainColorAttachment = vk::AttachmentReference(0,
                                                                  vk::ImageLayout::eColorAttachmentOptimal);
    auto const swapchainSubPassDescription = vk::SubpassDescription({},
                                                                    vk::PipelineBindPoint::eGraphics,
                                                                    {},
                                                                    swapchainColorAttachment);
    auto const swapchainRenderPassCreateInformation = vk::RenderPassCreateInfo({},
                                                                               swapchainAttachmentDescriptions,
                                                                               swapchainSubPassDescription);
    auto const swapchainRenderPass = std::make_shared <RenderPass> (this->device.createRenderPass(swapchainRenderPassCreateInformation));
    auto const swapchainRenderPassId = objectTable.allocateObject(swapchainRenderPass);
    auto const swapchainFramebuffer = this->createFramebuffer(swapchainSurfaceExtent.width,
                                                              swapchainSurfaceExtent.height,
                                                              swapchainRenderPass,
                                                              swapchainImageViews);
    auto const swapchainId = objectTable.allocateObject(swapchain);
    auto swapchainImageIds = std::vector <uint32_t> ();

    for (auto const &swapchainImage: swapchainImages) {
        auto const id = objectTable.allocateObject(swapchainImage);

        swapchainImageIds.push_back(id);
    }

    auto swapchainImageViewIds = std::vector <uint32_t> ();

    for (auto const &swapchainImageView: swapchainImageViews) {
        auto const id = objectTable.allocateObject(swapchainImageView);

        swapchainImageViewIds.push_back(id);
    }

    auto const swapchainFramebufferId = objectTable.allocateObject(swapchainFramebuffer);

    auto const vulkanFunctions = VmaVulkanFunctions {
        .vkGetInstanceProcAddr = &vkGetInstanceProcAddr,
        .vkGetDeviceProcAddr = &vkGetDeviceProcAddr,
    };

    auto const allocatorCreateInfo = VmaAllocatorCreateInfo {
        .flags = VMA_ALLOCATOR_CREATE_EXT_MEMORY_BUDGET_BIT,
        .physicalDevice = this->physicalDevice,
        .device = this->device,
        .pVulkanFunctions = &vulkanFunctions,
        .instance = instance,
        .vulkanApiVersion = apiVersion,
    };

    auto memoryAllocator = VmaAllocator();

    vmaCreateAllocator(&allocatorCreateInfo,
                       &memoryAllocator);

    this->swapchainId = swapchainId;
    this->swapchainImageIds = std::move(swapchainImageIds);
    this->swapchainImageViewIds = std::move(swapchainImageViewIds);
    this->swapchainRenderPassId = swapchainRenderPassId;
    this->swapchainFramebufferId = swapchainFramebufferId;
    this->memoryAllocator = memoryAllocator;
}

TexelGL::Vulkan::Context::~Context(void)
{
    if (this->memoryAllocator) {
        vmaDestroyAllocator(this->memoryAllocator);
        this->memoryAllocator = nullptr;
    }
}

std::shared_ptr <TexelGL::Buffer>
TexelGL::Vulkan::Context::createBuffer(void)
{
    return std::make_shared <Vulkan::Buffer> (this->memoryAllocator);
}