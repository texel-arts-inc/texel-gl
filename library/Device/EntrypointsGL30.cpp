#include <cassert>
#include "Context.h"
#include "Device.h"
#include "Entrypoints.h"
#include "OpenGLDefinitions.h"

void
glGenRenderbuffers(int32_t n,
                   uint32_t *renderbuffers)
{
}

EXPORT_API void
glGetIntegerv(TexelGL::GL::Enum name,
              int32_t &data)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto const &context = *contextPointer;

    switch (name) {
    case TexelGL::GL::EnumMajorVersion:
        data = context.getMajorVersion();
        break;

    case TexelGL::GL::EnumMinorVersion:
        data = context.getMajorVersion();
        break;

    case TexelGL::GL::EnumNumExtensions:
        data = static_cast <int32_t> (context.getExtensions().size());
        break;

    default:
        break;
    }
}

EXPORT_API void
glGetIntegeri_v(TexelGL::GL::Enum name,
                uint32_t index,
                int32_t &data)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto const &context = *contextPointer;

    switch (name) {
    default:
        break;
    }
}