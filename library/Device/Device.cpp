#include "Device.h"

thread_local std::shared_ptr <TexelGL::Context> TexelGL::Device::currentContext = nullptr;

TexelGL::Device::Device(void)
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

TexelGL::Device::~Device(void)
{
}

void
TexelGL::Device::deleteContext(std::shared_ptr <Context> const &context)
{
    auto const contextIterator = std::find(this->contexts.cbegin(),
                                           this->contexts.cend(),
                                           context);

    if (contextIterator == this->contexts.cend()) {
        return;
    }

    auto const contextIndex = contextIterator -
                              this->contexts.cbegin();

    this->contexts[contextIndex].reset();
}

std::shared_ptr <TexelGL::Context>
TexelGL::Device::getCurrentContext(void) const
{
    return this->currentContext;
}

std::string const &
TexelGL::Device::getExtensionsString(void) const
{
    return this->extensionsString;
}

void
TexelGL::Device::setCurrentContext(std::shared_ptr <Context> const &context)
{
    TexelGL::Device::currentContext = context;
}