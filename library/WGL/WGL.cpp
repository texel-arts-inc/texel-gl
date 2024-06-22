#include "WGL.h"

TexelWGL::Device TexelWGL::Device::currentDevice = {};
thread_local std::shared_ptr <TexelWGL::Context> TexelWGL::Device::currentContext = nullptr;

TexelWGL::Context::Context(Descriptor const &descriptor,
                           Handle handle) :
    descriptor(descriptor),
    handle(handle)
{
}

TexelWGL::Context::Descriptor const &
TexelWGL::Context::getDescriptor(void) const
{
    return this->descriptor;
}

TexelWGL::Context::Handle
TexelWGL::Context::getHandle(void) const
{
    return this->handle;
}

TexelWGL::Device::Device(void)
{
    static auto const extensionsNames = std::vector <std::string> {
        "WGL_ARB_extensions_string",
        "WGL_ARB_pixel_format",
    };

    for (auto const &extensionName: extensionsNames) {
        this->extensionsString += extensionName +
                                  " ";
    }
}

int16_t
TexelWGL::Device::getContextIndex(TexelWGL::Context::Handle handle)
{
    auto const contextIndex = static_cast <int16_t> (handle) -
                              1;

    return contextIndex;
}

TexelWGL::Context::Handle
TexelWGL::Device::createContext(Context::Descriptor const &descriptor)
{
    auto const handle = static_cast <Context::Handle> (this->contexts.size()) +
                        1;
    auto const context = std::make_shared <Context> (descriptor,
                                                     handle);

    this->contexts.push_back(context);
    this->setCurrentContext(handle);
    return handle;
}

void
TexelWGL::Device::deleteContext(TexelWGL::Context::Handle handle)
{
    auto const contextIndex = Device::getContextIndex(handle);

    if (contextIndex < 0) {
        return;
    }

    this->contexts[contextIndex].reset();
}

std::shared_ptr <TexelWGL::Context>
TexelWGL::Device::getContext(Context::Handle handle) const
{
    auto const contextIndex = Device::getContextIndex(handle);

    if (contextIndex < 0) {
        return nullptr;
    }

    auto const &context = this->contexts[contextIndex];

    return context;
}

TexelWGL::Context::Handle
TexelWGL::Device::getCurrentContext(void) const
{
    if (!this->currentContext) {
        return 0;
    }

    return this->currentContext->getHandle();
}

std::string const &
TexelWGL::Device::getExtensionsString(void) const
{
    return this->extensionsString;
}

void
TexelWGL::Device::setCurrentContext(Context::Handle handle)
{
    auto const context = this->getContext(handle);

    TexelWGL::Device::currentContext = context;
}