#include <cassert>
#include "Context.h"
#include "Device.h"
#include "EntrypointsGL33.h"

void
glBindSampler(uint32_t sampler)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl33.glBindSampler(sampler);
}

void
glDeleteSamplers(int32_t n,
                 uint32_t *samplers)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl33.glDeleteSamplers(n,
                                  samplers);
}

void
glGenSamplers(int32_t n,
              uint32_t *samplers)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl33.glGenSamplers(n,
                               samplers);
}

void
glSamplerParameterf(uint32_t sampler,
                    TexelGL::GL::Enum name,
                    float param)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl33.glSamplerParameterf(sampler,
                                     name,
                                     param);
}

void
glSamplerParameterfv(uint32_t sampler,
                     TexelGL::GL::Enum name,
                     float *param)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl33.glSamplerParameterfv(sampler,
                                      name,
                                      param);
}

void
glSamplerParameteri(uint32_t sampler,
                    TexelGL::GL::Enum name,
                    int32_t param)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl33.glSamplerParameteri(sampler,
                                     name,
                                     param);
}

void
glSamplerParameteriv(uint32_t sampler,
                     TexelGL::GL::Enum name,
                     int32_t *param)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl33.glSamplerParameteriv(sampler,
                                      name,
                                      param);
}