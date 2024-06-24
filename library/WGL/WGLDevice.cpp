#include <map>
#include "WGLDevice.h"
#include "WGLEntrypoints.h"

TexelGL::Device &TexelGL::Device::currentDevice = TexelWGL::Device::currentDevice;

int16_t
TexelWGL::Device::getContextIndex(TexelWGL::Context::Handle handle)
{
    auto const contextIndex = static_cast <int16_t> (handle) -
                              1;

    return contextIndex;
}

std::vector <std::string>
TexelWGL::Device::getExtensionsNames(std::vector <std::string> const &backendExtensionNames)
{
    auto extensionNames = std::vector <std::string> {
        "WGL_ARB_extensions_string",
        "WGL_ARB_pixel_format",
    };

    extensionNames.insert(extensionNames.end(),
                          backendExtensionNames.cbegin(),
                          backendExtensionNames.cend());

    return extensionNames;
}

TexelWGL::Device::Device(std::vector <std::string> const &backendExtensionNames) :
    TexelGL::Device(TexelWGL::Device::getExtensionsNames(backendExtensionNames))
{
}

TexelWGL::Device::~Device(void)
{
}

TexelWGL::Context::Handle
TexelWGL::Device::createContextHandle(Context::Descriptor const &descriptor)
{
    auto const handle = static_cast <Context::Handle> (this->contexts.size()) +
                        1;
    auto const context = this->createContext(descriptor,
                                             handle);

    this->contexts.push_back(context);
    this->setCurrentContextHandle(handle);
    return handle;
}

void
TexelWGL::Device::deleteContextHandle(Context::Handle handle)
{
    auto const contextIndex = Device::getContextIndex(handle);

    if (contextIndex < 0) {
        return;
    }

    auto const &context = this->contexts[contextIndex];

    this->deleteContext(context);
}

bool
TexelWGL::Device::describePixelFormat(WGL::DeviceContext deviceContext,
                                      int32_t pixelFormat,
                                      uint32_t numBytes,
                                      WGL::PixelFormatDescriptor &pixelFormatDescriptor)
{
    return true;
}

std::shared_ptr <TexelWGL::Context>
TexelWGL::Device::getContext(Context::Handle handle) const
{
    auto const contextIndex = Device::getContextIndex(handle);

    if (contextIndex < 0) {
        return nullptr;
    }

    auto const &context = std::dynamic_pointer_cast <Context> (this->contexts[contextIndex]);

    return context;
}

TexelWGL::Context::Handle
TexelWGL::Device::getCurrentContextHandle(void) const
{
    auto const &context = std::dynamic_pointer_cast <Context> (this->getCurrentContext());

    if (!context) {
        return 0;
    }

    return context->getHandle();
}

int32_t
TexelWGL::Device::getPixelFormat(WGL::DeviceContext hdc) const
{
    return 1;
}

void *
TexelWGL::Device::getProcedureAddress(std::string const &name) const
{
    static auto const mappings = std::map <std::string,
                                           void *> {
        { "wglCopyContext", reinterpret_cast <void *> (TexelWGL::copyContext) },
        { "wglChoosePixelFormat", reinterpret_cast <void *> (TexelWGL::choosePixelFormatWithDescriptor) },
        { "wglChoosePixelFormatARB", reinterpret_cast <void *> (TexelWGL::choosePixelFormat) },
        { "wglCreateContext", reinterpret_cast <void *> (TexelWGL::createContext) },
        { "wglCreateLayerContext", reinterpret_cast <void *> (TexelWGL::createLayerContext) },
        { "wglDeleteContext", reinterpret_cast <void *> (TexelWGL::deleteContext) },
        { "wglDescribePixelFormat", reinterpret_cast <void *> (TexelWGL::describePixelFormat) },
        { "wglGetCurrentContext", reinterpret_cast <void *> (TexelWGL::getCurrentContext) },
        { "wglGetCurrentDC", reinterpret_cast <void *> (TexelWGL::getCurrentDeviceContext) },
        { "wglGetCurrentReadDC", reinterpret_cast <void *> (TexelWGL::getCurrentReadDeviceContext) },
        { "wglGetExtensionsString", reinterpret_cast <void *> (TexelWGL::getExtensionsString) },
        { "wglGetExtensionsStringARB", reinterpret_cast <void *> (TexelWGL::getExtensionsString) },
        { "wglGetPixelFormat", reinterpret_cast <void *> (TexelWGL::getPixelFormat) },
        { "wglGetPixelFormatAttribfvARB", reinterpret_cast <void *> (TexelWGL::getPixelFormatAttribfv) },
        { "wglGetPixelFormatAttribivARB", reinterpret_cast <void *> (TexelWGL::getPixelFormatAttribiv) },
        { "wglGetProcAddress", reinterpret_cast <void *> (TexelWGL::getProcedureAddress) },
        { "wglMakeCurrent", reinterpret_cast <void *> (TexelWGL::makeCurrentContext) },
        { "wglSetPixelFormat", reinterpret_cast <void *> (TexelWGL::setPixelFormat) },
        { "wglShareLists", reinterpret_cast <void *> (TexelWGL::shareLists) },
        { "wglSwapBuffers", reinterpret_cast <void *> (TexelWGL::swapBuffers) },
        { "wglSwapLayerBuffers", reinterpret_cast <void *> (TexelWGL::swapLayerBuffers) },
    };

    if (!mappings.contains(name)) {
        return nullptr;
    }

    auto const address = mappings.at(name);

    if (address) {
        return address;
    }

    return TexelGL::Device::getProcedureAddress(name);
}

void
TexelWGL::Device::setCurrentContextHandle(Context::Handle handle)
{
    auto const context = this->getContext(handle);

    this->setCurrentContext(context);
}

bool
TexelWGL::Device::setPixelFormat(WGL::DeviceContext deviceContext,
                                 int32_t pixelFormat,
                                 WGL::PixelFormatDescriptor &pixelFormatDescriptor)
{
    return true;
}

bool
TexelWGL::Device::swapLayerBuffers(WGL::DeviceContext deviceContext,
                                   int32_t layer)
{
    return true;
}