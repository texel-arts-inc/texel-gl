#define NOMINMAX 1
#define VK_USE_PLATFORM_WIN32_KHR 1

#include "WGLVulkanContext.h"
#include "WGLVulkanDevice.h"
#include <windows.h>
#include <vulkan/vulkan_win32.h>

TexelWGL::Device &TexelWGL::Device::currentDevice = TexelWGL::Vulkan::Device::currentDevice;
TexelWGL::Vulkan::Device TexelWGL::Vulkan::Device::currentDevice = {};

TexelWGL::Vulkan::Device::Device(void) :
    TexelGL::Device(TexelWGL::Device::getExtensionsNames({})),
    TexelWGL::Device(),
    TexelGL::Vulkan::Device(this->getVulkanInstanceExtensions()),
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
    auto const windowSurface = this->instance.createWin32SurfaceKHR(surfaceCreateInformation);

    return std::make_shared <TexelWGL::Vulkan::Context> (descriptor,
                                                         handle,
                                                         this->apiVersion,
                                                         this->instance,
                                                         this->physicalDevice,
                                                         windowSurface);
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