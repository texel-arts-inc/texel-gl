#include <cassert>
#include "Context.h"
#include "Device.h"
#include "EntrypointsGL32.h"

TexelGL::GL::Enum
glClientWaitSync(TexelGL::GL::Sync sync,
                 uint32_t flags,
                 uint64_t timeout)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return TexelGL::GL::EnumInvalidOperation;
    }

    auto &context = *contextPointer;

    return context.gl32.glClientWaitSync(sync,
                                         flags,
                                         timeout);
}

void
glDeleteSync(TexelGL::GL::Sync sync)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl32.glDeleteSync(sync);
}

void
glDrawElementsBaseVertex(TexelGL::GL::Enum mode,
                         int32_t count,
                         TexelGL::GL::Enum type,
                         void const *indices,
                         int32_t basevertex)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl32.glDrawElementsBaseVertex(mode,
                                          count,
                                          type,
                                          indices,
                                          basevertex);
}

void
glDrawElementsInstancedBaseVertex(TexelGL::GL::Enum mode,
                                  int32_t count,
                                  TexelGL::GL::Enum type,
                                  void const *indices,
                                  int32_t instancecount,
                                  int32_t basevertex)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl32.glDrawElementsInstancedBaseVertex(mode,
                                                   count,
                                                   type,
                                                   indices,
                                                   instancecount,
                                                   basevertex);
}

void
glDrawRangeElementsBaseVertex(TexelGL::GL::Enum mode,
                              uint32_t start,
                              uint32_t end,
                              int32_t count,
                              TexelGL::GL::Enum type,
                              void const *indices,
                              int32_t basevertex)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl32.glDrawRangeElementsBaseVertex(mode,
                                               start,
                                               end,
                                               count,
                                               type,
                                               indices,
                                               basevertex);
}

TexelGL::GL::Sync
glFenceSync(TexelGL::GL::Enum condition,
            uint32_t flags)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return 0;
    }

    auto &context = *contextPointer;

    return context.gl32.glFenceSync(condition,
                                    flags);
}

void
glFramebufferTexture(TexelGL::GL::Enum target,
                     TexelGL::GL::Enum attachment,
                     uint32_t texture,
                     int32_t level)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl32.glFramebufferTexture(target,
                                      attachment,
                                      texture,
                                      level);
}

void
glGetBufferParameteri64v(TexelGL::GL::Enum target,
                         TexelGL::GL::Enum pname,
                         int64_t *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl32.glGetBufferParameteri64v(target,
                                          pname,
                                          params);
}

void
glGetInteger64i_v(TexelGL::GL::Enum target,
                  uint32_t index,
                  int64_t *data)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl32.glGetInteger64i_v(target,
                                   index,
                                   data);
}

void
glGetInteger64v(TexelGL::GL::Enum pname,
                int64_t *data)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl32.glGetInteger64v(pname,
                                 data);
}

void
glGetMultisamplefv(TexelGL::GL::Enum pname,
                   uint32_t index,
                   float *val)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl32.glGetMultisamplefv(pname,
                                    index,
                                    val);
}

void
glGetSynciv(TexelGL::GL::Sync sync,
            TexelGL::GL::Enum pname,
            int32_t count,
            int32_t *length,
            int32_t *values)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl32.glGetSynciv(sync,
                             pname,
                             count,
                             length,
                             values);
}

uint8_t
glIsSync(TexelGL::GL::Sync sync)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return false;
    }

    auto &context = *contextPointer;

    return context.gl32.glIsSync(sync);
}

void
glMultiDrawElementsBaseVertex(TexelGL::GL::Enum mode,
                              int32_t const *count,
                              TexelGL::GL::Enum type,
                              void const * const *indices,
                              int32_t drawcount,
                              int32_t const *basevertex)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl32.glMultiDrawElementsBaseVertex(mode,
                                               count,
                                               type,
                                               indices,
                                               drawcount,
                                               basevertex);
}

void
glProvokingVertex(TexelGL::GL::Enum mode)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl32.glProvokingVertex(mode);
}

void
glTexImage2DMultisample(TexelGL::GL::Enum target,
                        int32_t samples,
                        TexelGL::GL::Enum internalformat,
                        int32_t width,
                        int32_t height,
                        uint8_t fixedsamplelocations)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl32.glTexImage2DMultisample(target,
                                         samples,
                                         internalformat,
                                         width,
                                         height,
                                         fixedsamplelocations);
}

void
glTexImage3DMultisample(TexelGL::GL::Enum target,
                        int32_t samples,
                        TexelGL::GL::Enum internalformat,
                        int32_t width,
                        int32_t height,
                        int32_t depth,
                        uint8_t fixedsamplelocations)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl32.glTexImage3DMultisample(target,
                                         samples,
                                         internalformat,
                                         width,
                                         height,
                                         depth,
                                         fixedsamplelocations);
}

void
glSampleMaski(uint32_t maskNumber,
              uint32_t mask)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl32.glSampleMaski(maskNumber,
                               mask);
}

void
glWaitSync(TexelGL::GL::Sync sync,
           uint32_t flags,
           uint64_t timeout)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl32.glWaitSync(sync,
                            flags,
                            timeout);
}