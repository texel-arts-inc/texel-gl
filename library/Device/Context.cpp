#include <cassert>
#include "Context.h"

TexelGL::Context::Context(void) :
    immutableState(Context::ImmutableState {
        .version = Context::ImmutableState::Version {
            .major = 4,
            .minor = 6,
        },
    }),
    gl10(*this),
    gl11(*this),
    gl15(*this),
    gl20(*this),
    gl30(*this),
    gl31(*this),
    gl33(*this),
    gl41(*this)
{
}

TexelGL::Context::~Context(void)
{
}

TexelGL::Context::ImmutableState::Extensions const &
TexelGL::Context::getExtensions(void) const
{
    return this->immutableState.extensions;
}

uint32_t
TexelGL::Context::getMajorVersion(void) const
{
    return this->immutableState.version.major;
}

uint32_t
TexelGL::Context::getMinorVersion(void) const
{
    return this->immutableState.version.minor;
}

std::string const &
TexelGL::Context::getRenderer(void) const
{
    return this->immutableState.renderer;
}

std::string const &
TexelGL::Context::getVendor(void) const
{
    return this->immutableState.vendor;
}
