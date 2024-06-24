#include <cassert>
#include "Context.h"
#include "Device.h"
#include "EntrypointsGL41.h"

void
glClearDepthf(float d)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl41.glClearDepthf(d);
}

void
glShaderBinary(int32_t count,
               uint32_t const *shaders,
               TexelGL::GL::Enum binaryFormat,
               void const *binary,
               int32_t length)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl41.glShaderBinary(count,
                                shaders,
                                binaryFormat,
                                binary,
                                length);
}