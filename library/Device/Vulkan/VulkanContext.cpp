#include "VulkanContext.h"

std::string
TexelGL::Vulkan::Context::getPhysicalDeviceName(vk::PhysicalDevice const &physicalDevice)
{
    auto const &properties = physicalDevice.getProperties();

    return std::string(&properties.deviceName[0]);
}

TexelGL::Vulkan::Context::Context(vk::PhysicalDevice const &physicalDevice) :
    TexelGL::Context::Context(Context::getPhysicalDeviceName(physicalDevice)),
    physicalDevice(physicalDevice),
    physicalDeviceProperties(this->physicalDevice.getProperties()),
    physicalDeviceFeatures(this->physicalDevice.getFeatures())
{
}

TexelGL::Vulkan::Context::~Context(void)
{
}