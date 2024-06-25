#include <cassert>
#include "Context.h"
#include "Device.h"
#include "EntrypointsGL30.h"

void
glBindFramebuffer(TexelGL::GL::Enum target,
                  uint32_t framebuffer)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl30.glBindFramebuffer(target,
                                   framebuffer);
}

void
glBindRenderbuffer(TexelGL::GL::Enum target,
                   uint32_t renderbuffer)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl30.glBindRenderbuffer(target,
                                    renderbuffer);
}

void
glBindVertexArray(uint32_t array)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl30.glBindVertexArray(array);
}

void
glBlitFramebuffer(int32_t srcX0,
                  int32_t srcY0,
                  int32_t srcX1,
                  int32_t srcY1,
                  int32_t dstX0,
                  int32_t dstY0,
                  int32_t dstX1,
                  int32_t dstY1,
                  uint32_t mask,
                  TexelGL::GL::Enum filter)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl30.glBlitFramebuffer(srcX0,
                                   srcY0,
                                   srcX1,
                                   srcY1,
                                   dstX0,
                                   dstY0,
                                   dstX1,
                                   dstY1,
                                   mask,
                                   filter);
}

void
glDeleteFramebuffers(int32_t n,
                     uint32_t *framebuffers)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl30.glDeleteFramebuffers(n,
                                      framebuffers);
}

void
glDeleteRenderbuffers(int32_t n,
                      uint32_t *renderbuffers)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl30.glDeleteRenderbuffers(n,
                                       renderbuffers);
}

void
glDeleteVertexArrays(int32_t n,
                     uint32_t *arrays)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl30.glDeleteVertexArrays(n,
                                      arrays);
}

void
glFlushMappedBufferRange(TexelGL::GL::Enum target,
                         intptr_t offset,
                         intptr_t length)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl30.glFlushMappedBufferRange(target,
                                          offset,
                                          length);
}

void
glFramebufferRenderbuffer(TexelGL::GL::Enum target,
                          TexelGL::GL::Enum attachment,
                          TexelGL::GL::Enum renderbufferTarget,
                          uint32_t renderbuffer)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl30.glFramebufferRenderbuffer(target,
                                           attachment,
                                           renderbufferTarget,
                                           renderbuffer);
}

void
glFramebufferTexture2D(TexelGL::GL::Enum target,
                       TexelGL::GL::Enum attachment,
                       TexelGL::GL::Enum textureTarget,
                       uint32_t texture,
                       int32_t level)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl30.glFramebufferTexture2D(target,
                                        attachment,
                                        textureTarget,
                                        texture,
                                        level);
}

void
glGenBuffers(int32_t n,
             uint32_t *buffers)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl30.glGenBuffers(n,
                              buffers);
}

void
glGenFramebuffers(int32_t n,
                  uint32_t *framebuffers)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl30.glGenFramebuffers(n,
                                   framebuffers);
}

void
glGenRenderbuffers(int32_t n,
                   uint32_t *renderbuffers)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl30.glGenRenderbuffers(n,
                                    renderbuffers);
}

void
glGenVertexArrays(int32_t n,
                  uint32_t *arrays)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl30.glGenVertexArrays(n,
                                   arrays);
}

void
glGetIntegeri_v(TexelGL::GL::Enum name,
                uint32_t index,
                int32_t &data)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl30.glGetIntegeri_v(name,
                                 index,
                                 data);
}

void
glGetIntegerv(TexelGL::GL::Enum name,
              int32_t &data)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl30.glGetIntegerv(name,
                               data);
}

void *
glMapBufferRange(TexelGL::GL::Enum target,
                 intptr_t offset,
                 intptr_t length,
                 TexelGL::GL::MapAccessFlags access)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return nullptr;
    }

    auto &context = *contextPointer;

    return context.gl30.glMapBufferRange(target,
                                         offset,
                                         length,
                                         access);
}

void
glRenderbufferStorage(TexelGL::GL::Enum target,
                      TexelGL::GL::Enum internalFormat,
                      int32_t width,
                      int32_t height)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl30.glRenderbufferStorage(target,
                                       internalFormat,
                                       width,
                                       height);
}