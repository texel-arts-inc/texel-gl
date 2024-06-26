#include <cassert>
#include "Context.h"
#include "Device.h"
#include "EntrypointsGL44.h"

void
glBindBuffersBase(TexelGL::GL::Enum target,
                  uint32_t first,
                  int32_t count,
                  uint32_t const *buffers)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl44.glBindBuffersBase(target,
                                   first,
                                   count,
                                   buffers);
}

void
glBindBuffersRange(TexelGL::GL::Enum target,
                   uint32_t first,
                   int32_t count,
                   uint32_t const *buffers,
                   intptr_t const *offsets,
                   intptr_t const *sizes)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl44.glBindBuffersRange(target,
                                    first,
                                    count,
                                    buffers,
                                    offsets,
                                    sizes);
}