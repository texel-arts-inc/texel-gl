#include <cassert>
#include "Context.h"
#include "Device.h"
#include "EntrypointsGL31.h"

void
glGetActiveUniformBlockiv(uint32_t program,
                          uint32_t uniformBlockIndex,
                          TexelGL::GL::Enum name,
                          int32_t *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl31.glGetActiveUniformBlockiv(program,
                                           uniformBlockIndex,
                                           name,
                                           params);
}

void
glGetUniformBlockIndex(uint32_t program,
                       char const *uniformBlockName)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl31.glGetUniformBlockIndex(program,
                                        uniformBlockName);
}

void
glUniformBlockBinding(uint32_t program,
                      uint32_t uniformBlockIndex,
                      uint32_t uniformBlockBinding)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl31.glUniformBlockBinding(program,
                                       uniformBlockIndex,
                                       uniformBlockBinding);
}