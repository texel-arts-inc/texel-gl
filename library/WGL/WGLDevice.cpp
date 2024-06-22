#include "WGLDevice.h"

TexelGL::Device &TexelGL::Device::currentDevice = TexelWGL::Device::currentDevice;

int16_t
TexelWGL::Device::getContextIndex(TexelWGL::Context::Handle handle)
{
    auto const contextIndex = static_cast <int16_t> (handle) -
                              1;

    return contextIndex;
}

TexelWGL::Device::Device(void) :
    TexelGL::Device()
{
}

TexelWGL::Device::~Device(void)
{
}

void
TexelWGL::Device::deleteContextHandle(TexelWGL::Context::Handle handle)
{
    auto const contextIndex = Device::getContextIndex(handle);

    if (contextIndex < 0) {
        return;
    }

    auto const &context = this->contexts[contextIndex];

    this->deleteContext(context);
}

std::shared_ptr <TexelWGL::Context>
TexelWGL::Device::getContext(Context::Handle handle) const
{
    auto const contextIndex = Device::getContextIndex(handle);

    if (contextIndex < 0) {
        return nullptr;
    }

    auto const &context = static_pointer_cast <TexelWGL::Context> (this->contexts[contextIndex]);

    return context;
}

TexelWGL::Context::Handle
TexelWGL::Device::getCurrentContextHandle(void) const
{
    auto const &context = static_pointer_cast <TexelWGL::Context> (this->getCurrentContext());

    if (!context) {
        return 0;
    }

    return context->getHandle();
}

void
TexelWGL::Device::setCurrentContextHandle(Context::Handle handle)
{
    auto const context = this->getContext(handle);

    this->setCurrentContext(context);
}