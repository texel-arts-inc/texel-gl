#include <cassert>
#include "Context.h"
#include "Device.h"
#include "Entrypoints.h"
#include "OpenGLDefinitions.h"

EXPORT_API TexelGL::GL::Enum
glGetError(void)
{
    return TexelGL::GL::EnumNoError;   
}

EXPORT_API void
glGetFloatv(TexelGL::GL::Enum name,
            float &data)
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