#include "Context.h"

TexelGL::Context::Context(void) :
    immutableState(Context::ImmutableState {
        .version = Context::ImmutableState::Version {
            .major = 4,
            .minor = 6,
        },
    })
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

uint32_t TexelGL::Context::getMinorVersion(void) const
{
    return this->immutableState.version.minor;
}
