#include "VulkanBuffer.h"
#include "VulkanContext.h"
#include "VulkanFence.h"
#include "VulkanFramebuffer.h"
#include "VulkanImage.h"
#include "VulkanImageView.h"
#include "VulkanProgram.h"
#include "VulkanRenderbuffer.h"
#include "VulkanRenderPass.h"
#include "VulkanSampler.h"
#include "VulkanSemaphore.h"
#include "VulkanShader.h"
#include "VulkanSwapchain.h"
#include "VulkanSync.h"
#include "VulkanTexture.h"
#include "VulkanVertexArray.h"

std::string
TexelGL::Vulkan::Context::getPhysicalDeviceName(std::shared_ptr <vk::raii::PhysicalDevice> const &physicalDevice)
{
    auto const &properties = physicalDevice->getProperties();

    return std::string(&properties.deviceName[0]);
}

TexelGL::Vulkan::CommandPool
TexelGL::Vulkan::Context::createCommandPool(void) const
{
    auto const flags = vk::CommandPoolCreateFlags {
        vk::CommandPoolCreateFlagBits::eResetCommandBuffer,
    };
    auto const queueFamilyIndex = this->queueFamilyIndex;
    auto const commandPoolCreateInformation = vk::CommandPoolCreateInfo(flags,
                                                                        queueFamilyIndex);
    auto commandPool = this->device.createCommandPool(commandPoolCreateInformation);
    auto vulkanCommandPool = CommandPool(this->device,
                                         std::move(commandPool));

    return vulkanCommandPool;
}

vk::raii::Device
TexelGL::Vulkan::Context::createDevice(std::vector <std::string> const &vulkanDeviceExtensions) const
{
    auto &physicalDevice = *this->physicalDevice;
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
    auto device = physicalDevice.createDevice(deviceCreateInformation);

    return device;
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
                                                                 static_cast <vk::RenderPass> (*renderPass),
                                                                 imageViews,
                                                                 width,
                                                                 height,
                                                                 1);
    auto framebuffer = this->device.createFramebuffer(framebufferCreateInfo);
    auto const vulkanFramebuffer = std::make_shared <Framebuffer> (std::move(framebuffer));

    return vulkanFramebuffer;
}

std::shared_ptr <TexelGL::Vulkan::Swapchain>
TexelGL::Vulkan::Context::createSwapchain(uint32_t queueFamilyIndex) const
{
    auto const &windowSurface = this->windowSurface;
    auto &physicalDevice = *this->physicalDevice;
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
    auto swapchain = this->device.createSwapchainKHR(swapchainCreateInformation);
    auto const vulkanSwapchain = std::make_shared <Swapchain> (this->device,
                                                               std::move(swapchain),
                                                               surfaceFormat);

    return vulkanSwapchain;
}

std::shared_ptr <TexelGL::Vulkan::RenderPass>
TexelGL::Vulkan::Context::createSwapchainRenderPass(std::shared_ptr <Swapchain> const &swapchain,
                                                    vk::Format swapchainFormat) const
{
    auto const swapchainImageViews = swapchain->getImageViews();
    auto const colorImageLoadOperation = vk::AttachmentLoadOp::eClear;
    auto const colorImageFinalLayout = vk::ImageLayout::ePresentSrcKHR;
    auto const swapchainColorAttachmentDescription = vk::AttachmentDescription({},
                                                                               swapchainFormat,
                                                                               vk::SampleCountFlagBits::e1,
                                                                               colorImageLoadOperation,
                                                                               vk::AttachmentStoreOp::eStore,
                                                                               vk::AttachmentLoadOp::eDontCare,
                                                                               vk::AttachmentStoreOp::eDontCare,
                                                                               vk::ImageLayout::eUndefined,
                                                                               colorImageFinalLayout);
    auto const swapchainAttachmentDescriptions = std::vector <vk::AttachmentDescription> (swapchainImageViews.size(),
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

    return swapchainRenderPass;
}

size_t
TexelGL::Vulkan::Context::getQueueFamilyIndex(void) const
{
    auto const &physicalDevice = *this->physicalDevice;
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
    auto &physicalDevice = *this->physicalDevice;
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
    auto const &physicalDevice = *this->physicalDevice;
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

TexelGL::Vulkan::Context::Context(std::shared_ptr <ShaderCompiler> shaderCompiler,
                                  uint32_t apiVersion,
                                  std::shared_ptr <vk::raii::Instance> const &instance,
                                  std::shared_ptr <vk::raii::PhysicalDevice> const &physicalDevice,
                                  std::vector <std::string> const &vulkanDeviceExtensions,
                                  vk::raii::SurfaceKHR &&windowSurface) :
    TexelGL::Context::Context(Context::getPhysicalDeviceName(physicalDevice),
                              shaderCompiler),
    physicalDevice(physicalDevice),
    physicalDeviceProperties(this->physicalDevice->getProperties()),
    physicalDeviceFeatures(this->physicalDevice->getFeatures()),
    windowSurface(std::move(windowSurface)),
    swapchainSurfaceExtentAndImageCount(this->getSwapchainSurfaceExtentAndImageCount()),
    swapchainSurfaceFormatAndColorSpace(this->getSwapchainSurfaceFormatAndColorSpace()),
    queueFamilyIndex(this->getQueueFamilyIndex()),
    device(this->createDevice(vulkanDeviceExtensions)),
    commandPool(this->createCommandPool())
{
    auto &objectTable = this->objectTable;
    auto const swapchain = this->createSwapchain(queueFamilyIndex);
    auto const swapchainSurfaceExtent = this->swapchainSurfaceExtentAndImageCount.first;
    auto const swapchainSurfaceFormat = this->swapchainSurfaceFormatAndColorSpace.first;
    auto const swapchainImageViews = swapchain->getImageViews();
    auto const swapchainRenderPass = this->createSwapchainRenderPass(swapchain,
                                                                     swapchainSurfaceFormat);
    auto const swapchainRenderPassId = objectTable.allocateObject(swapchainRenderPass);
    auto const swapchainFramebuffer = this->createFramebuffer(swapchainSurfaceExtent.width,
                                                              swapchainSurfaceExtent.height,
                                                              swapchainRenderPass,
                                                              swapchainImageViews);
    auto const swapchainId = objectTable.allocateObject(swapchain);
    auto const swapchainFramebufferId = objectTable.allocateObject(swapchainFramebuffer);

    auto const vulkanFunctions = VmaVulkanFunctions {
        .vkGetInstanceProcAddr = &vkGetInstanceProcAddr,
        .vkGetDeviceProcAddr = &vkGetDeviceProcAddr,
    };

    auto const allocatorCreateInfo = VmaAllocatorCreateInfo {
        .flags = VMA_ALLOCATOR_CREATE_EXT_MEMORY_BUDGET_BIT,
        .physicalDevice = static_cast <vk::PhysicalDevice> (*this->physicalDevice),
        .device = static_cast <vk::Device> (this->device),
        .pVulkanFunctions = &vulkanFunctions,
        .instance = static_cast <vk::Instance> (*instance),
        .vulkanApiVersion = apiVersion,
    };

    auto memoryAllocator = VmaAllocator();

    vmaCreateAllocator(&allocatorCreateInfo,
                       &memoryAllocator);

    this->swapchainId = swapchainId;
    this->swapchainRenderPassId = swapchainRenderPassId;
    this->swapchainFramebufferId = swapchainFramebufferId;
    this->memoryAllocator = memoryAllocator;
}

TexelGL::Vulkan::Context::~Context(void)
{
    this->objectTable.deallocateObject(this->swapchainFramebufferId);
    this->objectTable.deallocateObject(this->swapchainId);
    this->objectTable.deallocateObject(this->swapchainRenderPassId);

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

std::shared_ptr <TexelGL::Framebuffer>
TexelGL::Vulkan::Context::createFramebuffer(void)
{
    return std::make_shared <Vulkan::Framebuffer> ();
}

std::shared_ptr <TexelGL::Program>
TexelGL::Vulkan::Context::createProgram(void)
{
    return std::make_shared <Vulkan::Program> ();
}

std::shared_ptr <TexelGL::Renderbuffer>
TexelGL::Vulkan::Context::createRenderbuffer(void)
{
    return std::make_shared <Vulkan::Renderbuffer> ();
}

std::shared_ptr <TexelGL::Sampler>
TexelGL::Vulkan::Context::createSampler(void)
{
    return std::make_shared <Vulkan::Sampler> ();
}

std::shared_ptr <TexelGL::Shader>
TexelGL::Vulkan::Context::createShader(TexelGL::GL::ShaderType shaderType)
{
    return std::make_shared <Vulkan::Shader> (this->device,
                                              this->shaderCompiler,
                                              shaderType);
}

std::shared_ptr <TexelGL::Sync>
TexelGL::Vulkan::Context::createSync(void)
{
    return std::make_shared <Vulkan::Sync> ();
}

std::shared_ptr <TexelGL::Texture>
TexelGL::Vulkan::Context::createTexture(void)
{
    return std::make_shared <Vulkan::Texture> ();
}

std::shared_ptr <TexelGL::VertexArray>
TexelGL::Vulkan::Context::createVertexArray(void)
{
    return std::make_shared <Vulkan::VertexArray> ();
}