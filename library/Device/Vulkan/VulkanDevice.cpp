#include "VulkanDevice.h"

size_t
TexelGL::Vulkan::Device::getDefaultPhysicalDeviceIndex(void)
{
    return 0;
}

vk::Instance
TexelGL::Vulkan::Device::createDefaultInstance(std::vector <std::string> const &vulkanInstanceExtensions)
{
    auto const applicationName = std::string();
    auto const applicationVersion = 1;
    auto const engineName = std::string();
    auto const engineVersion = 1;
    auto const version = VK_API_VERSION_1_1;
    auto const applicationInfo = vk::ApplicationInfo(applicationName.c_str(),
                                                     applicationVersion,
                                                     engineName.c_str(),
                                                     engineVersion,
                                                     version);
    auto const defaultVulkanInstanceExtensions = this->getVulkanInstanceExtensions();
    auto vulkanInstanceExtensionPointers = std::vector <char const *> ();

    for (auto const &vulkanInstanceExtension: defaultVulkanInstanceExtensions) {
        vulkanInstanceExtensionPointers.push_back(vulkanInstanceExtension.c_str());
    }

    for (auto const &vulkanInstanceExtension: vulkanInstanceExtensions) {
        vulkanInstanceExtensionPointers.push_back(vulkanInstanceExtension.c_str());
    }

    auto const instanceCreateInfo = vk::InstanceCreateInfo({},
                                                           &applicationInfo,
                                                           {},
                                                           vulkanInstanceExtensionPointers);
    auto const instance = vk::createInstance(instanceCreateInfo);

    return instance;
}

vk::PhysicalDevice
TexelGL::Vulkan::Device::createDefaultPhysicalDevice(void) const
{
    auto const &physicalDevices = this->instance.enumeratePhysicalDevices();
    auto physicalDevice = vk::PhysicalDevice(nullptr);

    if (!physicalDevices.empty()) {
        physicalDevice = physicalDevices[this->physicalDeviceIndex];
    }

    return physicalDevice;
}

std::vector <std::string>
TexelGL::Vulkan::Device::getVulkanInstanceExtensions(void) const
{
    auto vulkanInstanceExtensions = std::vector <std::string> {
        VK_KHR_SURFACE_EXTENSION_NAME,
    };

    return vulkanInstanceExtensions;
}

TexelGL::Vulkan::Device::Device(std::vector <std::string> const &vulkanInstanceExtensions) :
    TexelGL::Device::Device(),
    instance(Device::createDefaultInstance(vulkanInstanceExtensions)),
    physicalDeviceIndex(Device::getDefaultPhysicalDeviceIndex()),
    physicalDevice(this->createDefaultPhysicalDevice())
{
}

TexelGL::Vulkan::Device::~Device(void)
{
}