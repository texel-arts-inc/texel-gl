#include "VulkanDevice.h"

TexelGL::Vulkan::Device::Device(void) :
    TexelGL::Device::Device()
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
    auto const &physicalDevices = instance.enumeratePhysicalDevices();

    this->instance = instance;
    this->physicalDevices = physicalDevices;
}

TexelGL::Vulkan::Device::~Device(void)
{
}