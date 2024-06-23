#include <cassert>
#include "Context.h"
#include "Device.h"
#include "EntrypointsGL15.h"

void
glBindBuffer(TexelGL::GL::Enum target,
             uint32_t buffer)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl15.glBindBuffer(target,
                              buffer);
}

void
glBufferData(TexelGL::GL::Enum target,
             intptr_t size,
             void const *data,
             TexelGL::GL::Enum usage)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl15.glBufferData(target,
                              size,
                              data,
                              usage);
}

uint8_t
glUnmapBuffer(TexelGL::GL::Enum target)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return false;
    }

    auto &context = *contextPointer;

    return context.gl15.glUnmapBuffer(target);
}
