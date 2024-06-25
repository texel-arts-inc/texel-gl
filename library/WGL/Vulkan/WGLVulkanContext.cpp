#include "WGLVulkanContext.h"

std::vector <std::string>
TexelWGL::Vulkan::Context::getVulkanDeviceExtensions(void) const
{
    auto vulkanDeviceExtensions = std::vector <std::string> {
    };

    return vulkanDeviceExtensions;
}

TexelWGL::Vulkan::Context::Context(TexelWGL::Context::Descriptor const &descriptor,
                                   TexelWGL::Context::Handle handle,
                                   uint32_t apiVersion,
                                   vk::Instance const &instance,
                                   vk::PhysicalDevice const &physicalDevice,
                                   vk::SurfaceKHR const &windowSurface) :
    TexelGL::Context::Context(Context::getPhysicalDeviceName(physicalDevice)),
    TexelWGL::Context(descriptor,
                      handle,
                      this->TexelGL::Context::immutableState.renderer),
    TexelGL::Vulkan::Context(apiVersion,
                             instance,
                             physicalDevice,
                             this->getVulkanDeviceExtensions(),
                             windowSurface)
{
}

TexelWGL::Vulkan::Context::~Context(void)
{
}