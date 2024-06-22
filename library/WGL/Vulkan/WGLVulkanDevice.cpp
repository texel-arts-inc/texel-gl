#include "WGLVulkanDevice.h"

TexelWGL::Device &TexelWGL::Device::currentDevice = TexelWGL::Vulkan::Device::currentDevice;
TexelWGL::Vulkan::Device TexelWGL::Vulkan::Device::currentDevice = {};

TexelWGL::Vulkan::Device::Device(void) :
    TexelWGL::Device(),
    TexelGL::Vulkan::Device()
{
}

TexelWGL::Vulkan::Device::~Device(void)
{
}

TexelWGL::Context::Handle
TexelWGL::Vulkan::Device::createContextHandle(Context::Descriptor const &descriptor)
{
    auto const handle = static_cast <Context::Handle> (this->contexts.size()) +
                        1;
    auto const context = std::make_shared <Context> (descriptor,
                                                     handle);

    this->contexts.push_back(context);
    this->setCurrentContextHandle(handle);
    return handle;
}