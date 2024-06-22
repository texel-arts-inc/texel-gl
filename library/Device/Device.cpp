#include <map>
#include "Device.h"
#include "Entrypoints.h"

thread_local std::shared_ptr <TexelGL::Context> TexelGL::Device::currentContext = nullptr;

TexelGL::Device::Device(std::vector <std::string> const &extensionsNames)
{
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

void *
TexelGL::Device::getProcedureAddress(std::string const &name) const
{
    static auto const mappings = std::map <std::string,
                                           void *> {
        { "glCreateRenderbuffers", glCreateRenderbuffers },
        { "glGenRenderbuffers", glGenRenderbuffers },
    };

    if (!mappings.contains(name)) {
        return nullptr;
    }

    return mappings.at(name);
}

void
TexelGL::Device::setCurrentContext(std::shared_ptr <Context> const &context)
{
    TexelGL::Device::currentContext = context;
}