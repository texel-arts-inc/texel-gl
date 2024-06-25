#include "VulkanBuffer.h"
#include "VulkanContext.h"

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

vk::SwapchainKHR
TexelGL::Vulkan::Context::createSwapchain(uint32_t queueFamilyIndex) const
{
    auto const &windowSurface = this->windowSurface;
    auto const surfaceCapabilities = physicalDevice.getSurfaceCapabilitiesKHR(windowSurface);
    auto const surfaceFormats = physicalDevice.getSurfaceFormatsKHR(windowSurface);
    auto const defaultImageCount = uint32_t(3);
    auto const imageCount = std::clamp(defaultImageCount,
                                       surfaceCapabilities.minImageCount,
                                       surfaceCapabilities.maxImageCount);
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

    return swapchain;
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

std::vector <std::string>
TexelGL::Vulkan::Context::getVulkanDeviceExtensions(void) const
{
    auto vulkanDeviceExtensions = std::vector <std::string> {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME,
    };

    return vulkanDeviceExtensions;
}

TexelGL::Vulkan::Context::Context(vk::PhysicalDevice const &physicalDevice,
                                  std::vector <std::string> const &vulkanDeviceExtensions,
                                  vk::SurfaceKHR const &windowSurface) :
    TexelGL::Context::Context(Context::getPhysicalDeviceName(physicalDevice)),
    physicalDevice(physicalDevice),
    physicalDeviceProperties(this->physicalDevice.getProperties()),
    physicalDeviceFeatures(this->physicalDevice.getFeatures()),
    windowSurface(windowSurface),
    queueFamilyIndex(this->getQueueFamilyIndex()),
    device(this->createDevice(vulkanDeviceExtensions)),
    swapchain(this->createSwapchain(queueFamilyIndex))
{
}

TexelGL::Vulkan::Context::~Context(void)
{
}

std::shared_ptr <TexelGL::Buffer>
TexelGL::Vulkan::Context::createBuffer(void)
{
    return std::make_shared <Vulkan::Buffer> ();
}