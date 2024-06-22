#include <cassert>
#include <memory>
#include <vector>
#include "Entrypoints.h"
#include "WGLEntrypoints.h"
#include "WGLDevice.h"

namespace TexelWGL {
int32_t
choosePixelFormatWithDescriptor(WGL::DeviceContext deviceContext,
                                WGL::PixelFormatDescriptor *pixelFormatDescriptor)
{

    return 1;
}

int32_t
choosePixelFormat(WGL::DeviceContext deviceContext,
                  int32_t const *attribIList,
                  float const *attribFList,
                  uint32_t numMaxFormats,
                  int32_t *formats,
                  uint32_t *numFormats)
{
    if (!numMaxFormats) {
        return false;
    }

    auto integerAttributes = std::vector <std::pair <WGL::PixelFormatDescriptor::Attribute,
                                                     int32_t>> ();

    while (*attribIList) {
        auto const attribute = static_cast <WGL::PixelFormatDescriptor::Attribute> (*attribIList);

        ++attribIList;

        auto const value = *attribIList;

        integerAttributes.push_back(std::make_pair(attribute,
                                                   value));
        ++attribIList;
    }

    if (formats) {
        *formats = 1;
    }

    if (numFormats) {
        *numFormats = 1;
    }

    return true;
}

int32_t
copyContext(WGL::ResourceContext source,
            WGL::ResourceContext destination,
            uint32_t groups)
{
    assert(false);
    return 0;
}

WGL::ResourceContext
createContext(WGL::DeviceContext deviceContext)
{
    auto const descriptor = Context::Descriptor {
        .deviceContext = deviceContext,
    };
    auto &device = static_cast <TexelWGL::Device &> (Device::currentDevice);

    return reinterpret_cast <WGL::ResourceContext> (static_cast <uintptr_t> (device.createContextHandle(descriptor)));
}

WGL::ResourceContext
createLayerContext(WGL::DeviceContext deviceContext,
                   int32_t layer)
{
    auto const descriptor = Context::Descriptor {
        .deviceContext = deviceContext,
    };
    auto &device = static_cast <TexelWGL::Device &> (Device::currentDevice);

    return reinterpret_cast <WGL::ResourceContext> (static_cast <uintptr_t> (device.createContextHandle(descriptor)));
}

int32_t
deleteContext(WGL::ResourceContext resourceContext)
{
    auto const handle = static_cast <TexelWGL::Context::Handle> (reinterpret_cast <uintptr_t> (resourceContext));
    auto &device = static_cast <TexelWGL::Device &> (Device::currentDevice);
    auto const &context = device.getContext(handle);

    if (!context) {
        return false;
    }

    device.deleteContextHandle(handle);
    return true;
}

int32_t
describePixelFormat(WGL::DeviceContext deviceContext,
                    int32_t pixelFormat,
                    uint32_t numBytes,
                    WGL::PixelFormatDescriptor *pixelFormatDescriptor)
{
    if (!pixelFormatDescriptor) {
        return false;
    }

    auto &device = static_cast <TexelWGL::Device &> (Device::currentDevice);

    return device.describePixelFormat(deviceContext,
                                      pixelFormat,
                                      numBytes,
                                      *pixelFormatDescriptor);
}

WGL::ResourceContext
getCurrentContext(void)
{
    auto const &context = std::dynamic_pointer_cast <TexelWGL::Context> (Device::currentContext);

    return context ? reinterpret_cast <WGL::ResourceContext> (static_cast <uintptr_t> (context->getHandle())) :
                     nullptr;
}

WGL::DeviceContext
getCurrentDeviceContext(void)
{
    auto const &context = std::dynamic_pointer_cast <TexelWGL::Context> (Device::currentContext);

    return context ? context->getDescriptor().deviceContext :
                     nullptr;
}

WGL::DeviceContext
getCurrentReadDeviceContext(void)
{
    assert(false);
    return nullptr;
}

char const *
getExtensionsString(WGL::DeviceContext deviceContext)
{
    return Device::currentDevice.getExtensionsString().c_str();
}

int32_t
getPixelFormat(WGL::DeviceContext hdc)
{
    return 1;
}

int32_t
getPixelFormatAttribfv(WGL::DeviceContext hdc,
                        int32_t pixelFormat,
                        int32_t layerPlane,
                        uint32_t numAttributes,
                        int32_t const *attributes,
                        float *values)
{
    return true;
}

int32_t
getPixelFormatAttribiv(WGL::DeviceContext deviceContext,
                        int32_t pixelFormat,
                        int32_t layerPlane,
                        uint32_t numAttributes,
                        int32_t const *attributes,
                        int32_t *values)
{
    return true;
}

void const *
getProcedureAddress(char const *name)
{
    auto const &device = static_cast <TexelWGL::Device const &> (Device::currentDevice);
    auto const procedureName = std::string(name);

    return device.getProcedureAddress(procedureName);
}

int32_t
makeCurrentContext(WGL::DeviceContext deviceContext,
                   WGL::ResourceContext resourceContext)
{
    auto &device = static_cast <TexelWGL::Device &> (Device::currentDevice);

    if (!resourceContext) {
        device.setCurrentContextHandle(0);
        return true;
    }

    auto const handle = static_cast <TexelWGL::Context::Handle> (reinterpret_cast <uintptr_t> (resourceContext));
    auto const &context = device.getContext(handle);

    if (!context) {
        return false;
    }

    device.setCurrentContextHandle(handle);
    return true;
}

int32_t
setPixelFormat(WGL::DeviceContext deviceContext,
               int32_t pixelFormat,
               WGL::PixelFormatDescriptor *pixelFormatDescriptor)
{
    return true;
}

int32_t
shareLists(WGL::ResourceContext source,
           WGL::ResourceContext destination)
{
    assert(false);
    return false;
}

int32_t
swapBuffers(WGL::DeviceContext deviceContext)
{
    assert(false);
    return 1;
}

int32_t
swapLayerBuffers(WGL::DeviceContext deviceContext,
                 int32_t layer)
{
    assert(false);
    return true;
}
} // namespace TexelWGL