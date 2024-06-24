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
        return nullptr;
    }

    auto const defaultVulkanDeviceExtensions = this->getVulkanDeviceExtensions();
    auto vulkanDeviceExtensionPointers = std::vector <char const *> ();

    for (auto const &vulkanDeviceExtension: defaultVulkanDeviceExtensions) {
        vulkanDeviceExtensionPointers.push_back(vulkanDeviceExtension.c_str());
    }

    for (auto const &vulkanDeviceExtension: vulkanDeviceExtensions) {
        vulkanDeviceExtensionPointers.push_back(vulkanDeviceExtension.c_str());
    }

    auto const deviceCreateInformation = vk::DeviceCreateInfo({},
                                                              0,
                                                              nullptr,
                                                              vulkanDeviceExtensionPointers.size(),
                                                              vulkanDeviceExtensionPointers.data());
    auto const device = physicalDevice.createDevice(deviceCreateInformation);

    return device;
}

std::vector <std::string>
TexelGL::Vulkan::Context::getVulkanDeviceExtensions(void) const
{
    auto vulkanDeviceExtensions = std::vector <std::string> {
    };

    return vulkanDeviceExtensions;
}

TexelGL::Vulkan::Context::Context(vk::PhysicalDevice const &physicalDevice,
                                  vk::SurfaceKHR const &windowSurface,
                                  std::vector <std::string> const &vulkanDeviceExtensions) :
    TexelGL::Context::Context(Context::getPhysicalDeviceName(physicalDevice)),
    physicalDevice(physicalDevice),
    physicalDeviceProperties(this->physicalDevice.getProperties()),
    physicalDeviceFeatures(this->physicalDevice.getFeatures()),
    windowSurface(windowSurface),
    device(this->createDevice(vulkanDeviceExtensions))
{
}

TexelGL::Vulkan::Context::~Context(void)
{
}