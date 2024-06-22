#include <cassert>
#include <map>
#include "Entrypoints.h"

extern "C" {
    __declspec(dllexport) int32_t
    wglChoosePixelFormat(WGL::DeviceContext deviceContext,
                         WGL::PixelFormatDescriptor *pixelFormatDescriptor)
    {
        return TexelWGL::choosePixelFormatWithDescriptor(deviceContext,
                                                         pixelFormatDescriptor);
    }

    __declspec(dllexport) int32_t
    wglCopyContext(WGL::ResourceContext source,
                   WGL::ResourceContext destination,
                   uint32_t groups)
    {
        return TexelWGL::copyContext(source,
                                     destination,
                                     groups);
    }

    __declspec(dllexport) WGL::ResourceContext
    wglCreateContext(WGL::DeviceContext deviceContext)
    {
        return TexelWGL::createContext(deviceContext);
    }

    __declspec(dllexport) WGL::ResourceContext
    wglCreateLayerContext(WGL::DeviceContext deviceContext,
                          int32_t layer)
    {
        return TexelWGL::createLayerContext(deviceContext,
                                            layer);
    }

    __declspec(dllexport) int32_t
    wglDeleteContext(WGL::ResourceContext resourceContext)
    {
        return TexelWGL::deleteContext(resourceContext);
    }

    __declspec(dllexport) int32_t
    wglDescribePixelFormat(WGL::DeviceContext deviceContext,
                           int32_t pixelFormat,
                           uint32_t numBytes,
                           WGL::PixelFormatDescriptor *pixelFormatDescriptor)
    {
        return TexelWGL::describePixelFormat(deviceContext,
                                             pixelFormat,
                                             numBytes,
                                             pixelFormatDescriptor);
    }

    __declspec(dllexport) WGL::ResourceContext
    wglGetCurrentContext(void)
    {
        return TexelWGL::getCurrentContext();
    }

    __declspec(dllexport) WGL::DeviceContext
    wglGetCurrentDC(void)
    {
        return TexelWGL::getCurrentDeviceContext();
    }

    __declspec(dllexport) WGL::DeviceContext
    wglGetCurrentReadDC(void)
    {
        return TexelWGL::getCurrentReadDeviceContext();
    }

    __declspec(dllexport) int32_t
    wglGetPixelFormat(WGL::DeviceContext deviceContext)
    {
        return TexelWGL::getPixelFormat(deviceContext);
    }

    __declspec(dllexport) void const *
    wglGetProcAddress(char const *name)
    {
        return TexelWGL::getProcedureAddress(name);
    }

    __declspec(dllexport) char const *
    wglGetExtensionsString(WGL::DeviceContext deviceContext)
    {
        return TexelWGL::getExtensionsString(deviceContext).c_str();
    }

    __declspec(dllexport) int32_t
    wglMakeCurrent(WGL::DeviceContext deviceContext,
                   WGL::ResourceContext resourceContext)
    {
        return TexelWGL::makeCurrentContext(deviceContext,
                                            resourceContext);
    }

    __declspec(dllexport) int32_t
    wglSetPixelFormat(WGL::DeviceContext deviceContext,
                      int32_t pixelFormat,
                      WGL::PixelFormatDescriptor *pixelFormatDescriptor)
    {
        return TexelWGL::setPixelFormat(deviceContext,
                                        pixelFormat,
                                        pixelFormatDescriptor);
    }

    __declspec(dllexport) int32_t
    wglShareLists(WGL::ResourceContext source,
                  WGL::ResourceContext destination)
    {
        return TexelWGL::shareLists(source,
                                    destination);
    }

    __declspec(dllexport) int32_t
    wglSwapBuffers(WGL::DeviceContext deviceContext)
    {
        return TexelWGL::swapBuffers(deviceContext);
    }

    __declspec(dllexport) int32_t
    wglSwapLayerBuffers(WGL::DeviceContext deviceContext,
                        int32_t layer)
    {
        return TexelWGL::swapLayerBuffers(deviceContext,
                                          layer);
    }
}

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

    return reinterpret_cast <WGL::ResourceContext> (static_cast <uintptr_t> (Device::currentDevice.createContext(descriptor)));
}

WGL::ResourceContext
createLayerContext(WGL::DeviceContext deviceContext,
                   int32_t layer)
{
    auto const descriptor = Context::Descriptor {
        .deviceContext = deviceContext,
    };

    return reinterpret_cast <WGL::ResourceContext> (static_cast <uintptr_t> (Device::currentDevice.createContext(descriptor)));
}

int32_t
deleteContext(WGL::ResourceContext resourceContext)
{
    auto const handle = static_cast <TexelWGL::Context::Handle> (reinterpret_cast <uintptr_t> (resourceContext));
    auto const &context = Device::currentDevice.getContext(handle);

    if (!context) {
        return false;
    }

    Device::currentDevice.deleteContext(handle);
    return true;
}

int32_t
describePixelFormat(WGL::DeviceContext deviceContext,
                    int32_t pixelFormat,
                    uint32_t numBytes,
                    WGL::PixelFormatDescriptor *pixelFormatDescriptor)
{
    return 1;
}

WGL::ResourceContext
getCurrentContext(void)
{
    return Device::currentContext ? reinterpret_cast <WGL::ResourceContext> (static_cast <uintptr_t> (Device::currentContext->getHandle())) :
                                    nullptr;
}

WGL::DeviceContext
getCurrentDeviceContext(void)
{
    return Device::currentContext ? Device::currentContext->getDescriptor().deviceContext :
                                   nullptr;
}

WGL::DeviceContext
getCurrentReadDeviceContext(void)
{
    assert(false);
    return nullptr;
}

std::string const &
getExtensionsString(WGL::DeviceContext deviceContext)
{
    return Device::currentDevice.getExtensionsString();
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
    auto const procedureName = std::string(name);
    static auto const mappings = std::map <std::string,
                                           void *> {
        { "wglCopyContext", wglCopyContext },
        { "wglChoosePixelFormat", wglChoosePixelFormat },
        { "wglChoosePixelFormatARB", choosePixelFormat },
        { "wglCreateContext", wglCreateContext },
        { "wglCreateLayerContext", wglCreateLayerContext },
        { "wglDeleteContext", wglDeleteContext },
        { "wglDescribePixelFormat", wglDescribePixelFormat },
        { "wglGetCurrentContext", wglGetCurrentContext },
        { "wglGetCurrentDC", wglGetCurrentDC },
        { "wglGetCurrentReadDC", wglGetCurrentReadDC },
        { "wglGetExtensionsString", wglGetExtensionsString },
        { "wglGetExtensionsStringARB", wglGetExtensionsString },
        { "wglGetPixelFormat", wglGetPixelFormat },
        { "wglGetPixelFormatAttribfvARB", getPixelFormatAttribfv },
        { "wglGetPixelFormatAttribivARB", getPixelFormatAttribiv },
        { "wglGetProcAddress", wglGetProcAddress },
        { "wglMakeCurrent", wglMakeCurrent },
        { "wglSetPixelFormat", wglSetPixelFormat },
        { "wglShareLists", wglShareLists },
        { "wglSwapBuffers", wglSwapBuffers },
        { "wglSwapLayerBuffers", wglSwapLayerBuffers },
    };

    if (!mappings.contains(procedureName)) {
        return nullptr;
    }

    return mappings.at(name);
}

int32_t
makeCurrentContext(WGL::DeviceContext deviceContext,
                   WGL::ResourceContext resourceContext)
{
    if (!resourceContext) {
        Device::currentDevice.setCurrentContext(0);
        return true;
    }

    auto const handle = static_cast <TexelWGL::Context::Handle> (reinterpret_cast <uintptr_t> (resourceContext));
    auto const &context = Device::currentDevice.getContext(handle);

    if (!context) {
        return false;
    }

    Device::currentDevice.setCurrentContext(handle);
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