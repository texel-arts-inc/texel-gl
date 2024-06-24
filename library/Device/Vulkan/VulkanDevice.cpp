#include "VulkanDevice.h"

vk::Instance
TexelGL::Vulkan::Device::createDefaultInstance(void)
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
    auto const instanceCreateInfo = vk::InstanceCreateInfo({},
                                                           &applicationInfo);
    auto instance = vk::createInstance(instanceCreateInfo);

    return instance;
}

size_t
TexelGL::Vulkan::Device::getDefaultPhysicalDeviceIndex(void)
{
    return 0;
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

TexelGL::Vulkan::Device::Device(void) :
    TexelGL::Device::Device(),
    instance(Device::createDefaultInstance()),
    physicalDeviceIndex(Device::getDefaultPhysicalDeviceIndex()),
    physicalDevice(this->createDefaultPhysicalDevice())
{
}

TexelGL::Vulkan::Device::~Device(void)
{
}