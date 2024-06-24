#include "WGLVulkanContext.h"
#include "WGLVulkanDevice.h"

TexelWGL::Device &TexelWGL::Device::currentDevice = TexelWGL::Vulkan::Device::currentDevice;
TexelWGL::Vulkan::Device TexelWGL::Vulkan::Device::currentDevice = {};

TexelWGL::Vulkan::Device::Device(void) :
    TexelGL::Device(TexelWGL::Device::getExtensionsNames({})),
    TexelWGL::Device(),
    TexelGL::Vulkan::Device()
{
}

std::shared_ptr <TexelWGL::Context>
TexelWGL::Vulkan::Device::createContext(TexelWGL::Context::Descriptor const &descriptor,
                                        TexelWGL::Context::Handle handle) const
{
    return std::make_shared <TexelWGL::Vulkan::Context> (descriptor,
                                                         handle,
                                                         this->physicalDevice);
}

TexelWGL::Vulkan::Device::~Device(void)
{
}