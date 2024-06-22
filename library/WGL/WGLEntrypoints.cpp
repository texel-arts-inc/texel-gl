#include <cassert>
#include <map>
#include <memory>
#include <vector>
#include "Entrypoints.h"
#include "WGLEntrypoints.h"
#include "WGLDevice.h"

EXPORT_API int32_t
wglChoosePixelFormat(WGL::DeviceContext deviceContext,
                        WGL::PixelFormatDescriptor *pixelFormatDescriptor)
{
    return TexelWGL::choosePixelFormatWithDescriptor(deviceContext,
                                                     pixelFormatDescriptor);
}

EXPORT_API int32_t
wglCopyContext(WGL::ResourceContext source,
               WGL::ResourceContext destination,
               uint32_t groups)
{
    return TexelWGL::copyContext(source,
                                 destination,
                                 groups);
}

EXPORT_API WGL::ResourceContext
wglCreateContext(WGL::DeviceContext deviceContext)
{
    return TexelWGL::createContext(deviceContext);
}

EXPORT_API WGL::ResourceContext
wglCreateLayerContext(WGL::DeviceContext deviceContext,
                      int32_t layer)
{
    return TexelWGL::createLayerContext(deviceContext,
                                        layer);
}

EXPORT_API int32_t
wglDeleteContext(WGL::ResourceContext resourceContext)
{
    return TexelWGL::deleteContext(resourceContext);
}

EXPORT_API int32_t
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

EXPORT_API WGL::ResourceContext
wglGetCurrentContext(void)
{
    return TexelWGL::getCurrentContext();
}

EXPORT_API WGL::DeviceContext
wglGetCurrentDC(void)
{
    return TexelWGL::getCurrentDeviceContext();
}

EXPORT_API WGL::DeviceContext
wglGetCurrentReadDC(void)
{
    return TexelWGL::getCurrentReadDeviceContext();
}

EXPORT_API int32_t
wglGetPixelFormat(WGL::DeviceContext deviceContext)
{
    return TexelWGL::getPixelFormat(deviceContext);
}

EXPORT_API void const *
wglGetProcAddress(char const *name)
{
    return TexelWGL::getProcedureAddress(name);
}

EXPORT_API char const *
wglGetExtensionsString(WGL::DeviceContext deviceContext)
{
    return TexelWGL::getExtensionsString(deviceContext).c_str();
}

EXPORT_API int32_t
wglMakeCurrent(WGL::DeviceContext deviceContext,
               WGL::ResourceContext resourceContext)
{
    return TexelWGL::makeCurrentContext(deviceContext,
                                        resourceContext);
}

EXPORT_API int32_t
wglSetPixelFormat(WGL::DeviceContext deviceContext,
                  int32_t pixelFormat,
                  WGL::PixelFormatDescriptor *pixelFormatDescriptor)
{
    return TexelWGL::setPixelFormat(deviceContext,
                                    pixelFormat,
                                    pixelFormatDescriptor);
}

EXPORT_API int32_t
wglShareLists(WGL::ResourceContext source,
              WGL::ResourceContext destination)
{
    return TexelWGL::shareLists(source,
                                destination);
}

EXPORT_API int32_t
wglSwapBuffers(WGL::DeviceContext deviceContext)
{
    return TexelWGL::swapBuffers(deviceContext);
}

EXPORT_API int32_t
wglSwapLayerBuffers(WGL::DeviceContext deviceContext,
                    int32_t layer)
{
    return TexelWGL::swapLayerBuffers(deviceContext,
                                      layer);
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
    return 1;
}

WGL::ResourceContext
getCurrentContext(void)
{
    auto const &context = std::static_pointer_cast <TexelWGL::Context> (Device::currentContext);

    return context ? reinterpret_cast <WGL::ResourceContext> (static_cast <uintptr_t> (context->getHandle())) :
                     nullptr;
}

WGL::DeviceContext
getCurrentDeviceContext(void)
{
    auto const &context = std::static_pointer_cast <TexelWGL::Context> (Device::currentContext);

    return context ? context->getDescriptor().deviceContext :
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