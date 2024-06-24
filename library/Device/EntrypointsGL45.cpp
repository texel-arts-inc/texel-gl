#include <cassert>
#include "Context.h"
#include "Device.h"
#include "EntrypointsGL45.h"

void
glCreateBuffers(int32_t n,
                uint32_t *buffers)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glCreateBuffers(n,
                                 buffers);
}

void
glCreateFramebuffers(int32_t n,
                     uint32_t *framebuffers)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glCreateFramebuffers(n,
                                      framebuffers);
}

void
glCreateRenderbuffers(int32_t n,
                      uint32_t *renderbuffers)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glCreateRenderbuffers(n,
                                       renderbuffers);
}

void
glCreateSamplers(int32_t n,
                 uint32_t *samplers)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glCreateSamplers(n,
                                  samplers);
}

void
glCreateVertexArrays(int32_t n,
                     uint32_t *arrays)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glCreateVertexArrays(n,
                                      arrays);
}