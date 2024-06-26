
#include "VulkanInterface.h"
#include "WGLVulkanContext.h"
#include "WGLVulkanDevice.h"

TexelWGL::Device &
TexelWGL::Device::getCurrentDevice(void)
{
    return TexelWGL::Vulkan::Device::getCurrentDevice();
}

TexelWGL::Vulkan::Device &
TexelWGL::Vulkan::Device::getCurrentDevice(void)
{
    static TexelWGL::Vulkan::Device currentDevice = {};

    return currentDevice;
}

TexelWGL::Vulkan::Device::Device(void) :
    TexelGL::Device(TexelWGL::Device::getExtensionsNames({})),
    TexelWGL::Device(),
    TexelGL::Vulkan::Device(this->getVulkanInstanceLayers(),
                            this->getVulkanInstanceExtensions()),
    processInstance(GetModuleHandle(nullptr))
{
}

std::shared_ptr <TexelWGL::Context>
TexelWGL::Vulkan::Device::createContext(TexelWGL::Context::Descriptor const &descriptor,
                                        TexelWGL::Context::Handle handle) const
{
    auto const processInstance = static_cast <HINSTANCE> (const_cast <void *> (this->processInstance));
    auto const windowHandle = WindowFromDC(static_cast <HDC> (const_cast <void *> (descriptor.deviceContext)));
    auto const surfaceCreateInformation = vk::Win32SurfaceCreateInfoKHR({},
                                                                        processInstance,
                                                                        windowHandle);
    auto windowSurface = this->instance->createWin32SurfaceKHR(surfaceCreateInformation);

    return std::make_shared <TexelWGL::Vulkan::Context> (descriptor,
                                                         handle,
                                                         shaderCompiler,
                                                         this->apiVersion,
                                                         this->instance,
                                                         this->physicalDevice,
                                                         std::move(windowSurface));
}

std::vector <std::string>
TexelWGL::Vulkan::Device::getVulkanInstanceLayers(void) const
{
    return std::vector <std::string> ();
}

std::vector <std::string>
TexelWGL::Vulkan::Device::getVulkanInstanceExtensions(void) const
{
    auto vulkanInstanceExtensions = std::vector <std::string> {
        VK_KHR_WIN32_SURFACE_EXTENSION_NAME,
    };

    return vulkanInstanceExtensions;
}

TexelWGL::Vulkan::Device::~Device(void)
{
}

bool
TexelWGL::Vulkan::Device::swapBuffers(WGL::DeviceContext deviceContext)
{
    return true;
}