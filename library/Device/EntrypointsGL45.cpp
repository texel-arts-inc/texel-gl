#include <cassert>
#include "Context.h"
#include "Device.h"
#include "EntrypointsGL45.h"

void
glBindTextureUnit(uint32_t unit,
                  uint32_t texture)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glBindTextureUnit(unit,
                                   texture);
}

void
glBlitNamedFramebuffer(uint32_t readFramebuffer,
                       uint32_t drawFramebuffer,
                       int32_t srcX0,
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

    context.gl45.glBlitNamedFramebuffer(readFramebuffer,
                                        drawFramebuffer,
                                        srcX0,
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

TexelGL::GL::Enum
glCheckNamedFramebufferStatus(uint32_t framebuffer,
                              TexelGL::GL::Enum target)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return TexelGL::GL::EnumInvalidOperation;
    }

    auto &context = *contextPointer;

    return context.gl45.glCheckNamedFramebufferStatus(framebuffer,
                                                      target);
}

void
glClearNamedFramebufferiv(uint32_t framebuffer,
                          TexelGL::GL::Enum buffer,
                          int32_t drawbuffer,
                          int32_t const *value)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glClearNamedFramebufferiv(framebuffer,
                                           buffer,
                                           drawbuffer,
                                           value);
}

void
glClearNamedFramebufferfi(uint32_t framebuffer,
                          TexelGL::GL::Enum buffer,
                          int32_t drawbuffer,
                          float depth,
                          int32_t stencil)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glClearNamedFramebufferfi(framebuffer,
                                            buffer,
                                            drawbuffer,
                                            depth,
                                            stencil);
}

void
glClearNamedFramebufferfv(uint32_t framebuffer,
                          TexelGL::GL::Enum buffer,
                          int32_t drawbuffer,
                          float const *value)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glClearNamedFramebufferfv(framebuffer,
                                            buffer,
                                            drawbuffer,
                                            value);
}

void
glClearNamedFramebufferuiv(uint32_t framebuffer,
                           TexelGL::GL::Enum buffer,
                           int32_t drawbuffer,
                           uint32_t const *value)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glClearNamedFramebufferuiv(framebuffer,
                                            buffer,
                                            drawbuffer,
                                            value);
}

void
glClearNamedBufferData(uint32_t buffer,
                       TexelGL::GL::Enum internalformat,
                       TexelGL::GL::Enum format,
                       TexelGL::GL::Enum type,
                       void const *data)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glClearNamedBufferData(buffer,
                                        internalformat,
                                        format,
                                        type,
                                        data);
}

void
glClearNamedBufferSubData(uint32_t buffer,
                          TexelGL::GL::Enum internalformat,
                          intptr_t offset,
                          intptr_t size,
                          TexelGL::GL::Enum format,
                          TexelGL::GL::Enum type,
                          void const *data)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glClearNamedBufferSubData(buffer,
                                           internalformat,
                                           offset,
                                           size,
                                           format,
                                           type,
                                           data);
}

void
glClipControl(TexelGL::GL::Enum origin,
              TexelGL::GL::Enum depth)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glClipControl(origin,
                               depth);
}

void
glCompressedTextureSubImage1D(uint32_t texture,
                              int32_t level,
                              int32_t xoffset,
                              int32_t width,
                              TexelGL::GL::Enum format,
                              int32_t imageSize,
                              void const *data)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glCompressedTextureSubImage1D(texture,
                                               level,
                                               xoffset,
                                               width,
                                               format,
                                               imageSize,
                                               data);
}

void
glCompressedTextureSubImage2D(uint32_t texture,
                              int32_t level,
                              int32_t xoffset,
                              int32_t yoffset,
                              int32_t width,
                              int32_t height,
                              TexelGL::GL::Enum format,
                              int32_t imageSize,
                              void const *data)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glCompressedTextureSubImage2D(texture,
                                               level,
                                               xoffset,
                                               yoffset,
                                               width,
                                               height,
                                               format,
                                               imageSize,
                                               data);
}

void
glCompressedTextureSubImage3D(uint32_t texture,
                              int32_t level,
                              int32_t xoffset,
                              int32_t yoffset,
                              int32_t zoffset,
                              int32_t width,
                              int32_t height,
                              int32_t depth,
                              TexelGL::GL::Enum format,
                              int32_t imageSize,
                              void const *data)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glCompressedTextureSubImage3D(texture,
                                               level,
                                               xoffset,
                                               yoffset,
                                               zoffset,
                                               width,
                                               height,
                                               depth,
                                               format,
                                               imageSize,
                                               data);
}

void
glCopyTextureSubImage1D(uint32_t texture,
                        int32_t level,
                        int32_t xoffset,
                        int32_t x,
                        int32_t y,
                        int32_t width)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glCopyTextureSubImage1D(texture,
                                         level,
                                         xoffset,
                                         x,
                                         y,
                                         width);
}

void
glCopyTextureSubImage2D(uint32_t texture,
                        int32_t level,
                        int32_t xoffset,
                        int32_t yoffset,
                        int32_t x,
                        int32_t y,
                        int32_t width,
                        int32_t height)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glCopyTextureSubImage2D(texture,
                                         level,
                                         xoffset,
                                         yoffset,
                                         x,
                                         y,
                                         width,
                                         height);
}

void
glCopyTextureSubImage3D(uint32_t texture,
                        int32_t level,
                        int32_t xoffset,
                        int32_t yoffset,
                        int32_t zoffset,
                        int32_t x,
                        int32_t y,
                        int32_t width,
                        int32_t height)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glCopyTextureSubImage3D(texture,
                                         level,
                                         xoffset,
                                         yoffset,
                                         zoffset,
                                         x,
                                         y,
                                         width,
                                         height);
}

void
glCopyNamedBufferSubData(uint32_t readBuffer,
                         uint32_t writeBuffer,
                         intptr_t readOffset,
                         intptr_t writeOffset,
                         intptr_t size)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glCopyNamedBufferSubData(readBuffer,
                                          writeBuffer,
                                          readOffset,
                                          writeOffset,
                                          size);
}

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
glCreateProgramPipelines(int32_t n,
                         uint32_t *pipelines)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glCreateProgramPipelines(n,
                                          pipelines);
}

void
glCreateQueries(TexelGL::GL::Enum target,
                int32_t n,
                uint32_t *ids)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glCreateQueries(target,
                                 n,
                                 ids);
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
glCreateTextures(TexelGL::GL::Enum target,
                 int32_t n,
                 uint32_t *textures)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glCreateTextures(target,
                                  n,
                                  textures);
}

void
glCreateTransformFeedbacks(int32_t n,
                           uint32_t *ids)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glCreateTransformFeedbacks(n,
                                            ids);
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

void
glDisableVertexArrayAttrib(uint32_t vaobj,
                           uint32_t index)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glDisableVertexArrayAttrib(vaobj,
                                            index);
}

void
glEnableVertexArrayAttrib(uint32_t vaobj,
                          uint32_t index)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glEnableVertexArrayAttrib(vaobj,
                                           index);
}

void
glFlushMappedNamedBufferRange(uint32_t buffer,
                              intptr_t offset,
                              intptr_t length)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glFlushMappedNamedBufferRange(buffer,
                                               offset,
                                               length);
}

void
glGenerateTextureMipmap(uint32_t texture)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGenerateTextureMipmap(texture);
}

void
glGetnCompressedTexImage(TexelGL::GL::Enum target,
                         int32_t lod,
                         int32_t bufSize,
                         void *pixels)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetnCompressedTexImage(target,
                                          lod,
                                          bufSize,
                                          pixels);
}

void
glGetnTexImage(TexelGL::GL::Enum target,
               int32_t level,
               TexelGL::GL::Enum format,
               TexelGL::GL::Enum type,
               int32_t bufSize,
               void *pixels)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetnTexImage(target,
                                level,
                                format,
                                type,
                                bufSize,
                                pixels);
}

void
glGetnUniformdv(uint32_t program,
                int32_t location,
                int32_t bufSize,
                double *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetnUniformdv(program,
                                 location,
                                 bufSize,
                                 params);
}

void
glGetnUniformfv(uint32_t program,
                int32_t location,
                int32_t bufSize,
                float *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetnUniformfv(program,
                                 location,
                                 bufSize,
                                 params);
}

void
glGetnUniformiv(uint32_t program,
                int32_t location,
                int32_t bufSize,
                int32_t *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetnUniformiv(program,
                                 location,
                                 bufSize,
                                 params);
}

void
glGetnUniformuiv(uint32_t program,
                 int32_t location,
                 int32_t bufSize,
                 uint32_t *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetnUniformuiv(program,
                                  location,
                                  bufSize,
                                  params);
}

void
glGetCompressedTextureImage(uint32_t texture,
                            int32_t level,
                            int32_t bufSize,
                            void *pixels)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetCompressedTextureImage(texture,
                                             level,
                                             bufSize,
                                             pixels);
}

void
glGetCompressedTextureSubImage(uint32_t texture,
                               int32_t level,
                               int32_t xoffset,
                               int32_t yoffset,
                               int32_t zoffset,
                               int32_t width,
                               int32_t height,
                               int32_t depth,
                               int32_t bufSize,
                               void *pixels)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetCompressedTextureSubImage(texture,
                                                level,
                                                xoffset,
                                                yoffset,
                                                zoffset,
                                                width,
                                                height,
                                                depth,
                                                bufSize,
                                                pixels);
}

TexelGL::GL::Enum
glGetGraphicsResetStatus(void)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return TexelGL::GL::EnumInvalidOperation;
    }

    auto &context = *contextPointer;

    return context.gl45.glGetGraphicsResetStatus();
}

void
glGetNamedBufferParameteriv(uint32_t buffer,
                            TexelGL::GL::Enum pname,
                            int32_t *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetNamedBufferParameteriv(buffer,
                                             pname,
                                             params);
}

void
glGetNamedBufferParameteri64v(uint32_t buffer,
                              TexelGL::GL::Enum pname,
                              int64_t *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetNamedBufferParameteri64v(buffer,
                                               pname,
                                               params);
}

void
glGetNamedBufferPointerv(uint32_t buffer,
                         TexelGL::GL::Enum pname,
                         void **params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetNamedBufferPointerv(buffer,
                                          pname,
                                          params);
}

void
glGetNamedBufferSubData(uint32_t buffer,
                        intptr_t offset,
                        intptr_t size,
                        void *data)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetNamedBufferSubData(buffer,
                                         offset,
                                         size,
                                         data);
}

void
glGetNamedFramebufferAttachmentParameteriv(uint32_t framebuffer,
                                           TexelGL::GL::Enum attachment,
                                           TexelGL::GL::Enum pname,
                                           int32_t *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetNamedFramebufferAttachmentParameteriv(framebuffer,
                                                            attachment,
                                                            pname,
                                                            params);
}

void
glGetNamedFramebufferParameteriv(uint32_t framebuffer,
                                 TexelGL::GL::Enum pname,
                                 int32_t *param)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetNamedFramebufferParameteriv(framebuffer,
                                                  pname,
                                                  param);
}

void
glGetNamedRenderbufferParameteriv(uint32_t renderbuffer,
                                  TexelGL::GL::Enum pname,
                                  int32_t *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetNamedRenderbufferParameteriv(renderbuffer,
                                                   pname,
                                                   params);
}

void
glGetQueryBufferObjecti64v(uint32_t id,
                           uint32_t buffer,
                           TexelGL::GL::Enum pname,
                           intptr_t offset)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetQueryBufferObjecti64v(id,
                                            buffer,
                                            pname,
                                            offset);
}

void
glGetQueryBufferObjectiv(uint32_t id,
                         uint32_t buffer,
                         TexelGL::GL::Enum pname,
                         intptr_t offset)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetQueryBufferObjectiv(id,
                                          buffer,
                                          pname,
                                          offset);
}

void
glGetQueryBufferObjectui64v(uint32_t id,
                            uint32_t buffer,
                            TexelGL::GL::Enum pname,
                            intptr_t offset)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetQueryBufferObjectui64v(id,
                                             buffer,
                                             pname,
                                             offset);
}

void
glGetQueryBufferObjectuiv(uint32_t id,
                          uint32_t buffer,
                          TexelGL::GL::Enum pname,
                          intptr_t offset)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetQueryBufferObjectuiv(id,
                                           buffer,
                                           pname,
                                           offset);
}

void
glGetTextureImage(uint32_t texture,
                  int32_t level,
                  TexelGL::GL::Enum format,
                  TexelGL::GL::Enum type,
                  int32_t bufSize,
                  void *pixels)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetTextureImage(texture,
                                   level,
                                   format,
                                   type,
                                   bufSize,
                                   pixels);
}

void
glGetTextureLevelParameterfv(uint32_t texture,
                            int32_t level,
                            TexelGL::GL::Enum pname,
                            float *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetTextureLevelParameterfv(texture,
                                              level,
                                              pname,
                                              params);
}

void
glGetTextureLevelParameteriv(uint32_t texture,
                            int32_t level,
                            TexelGL::GL::Enum pname,
                            int32_t *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetTextureLevelParameteriv(texture,
                                              level,
                                              pname,
                                              params);
}

void
glGetTextureParameterfv(uint32_t texture,
                        TexelGL::GL::Enum pname,
                        float *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetTextureParameterfv(texture,
                                         pname,
                                         params);
}

void
glGetTextureParameteriv(uint32_t texture,
                        TexelGL::GL::Enum pname,
                        int32_t *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetTextureParameteriv(texture,
                                         pname,
                                         params);
}

void
glGetTextureParameterIiv(uint32_t texture,
                        TexelGL::GL::Enum pname,
                        int32_t *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetTextureParameterIiv(texture,
                                          pname,
                                          params);
}

void
glGetTextureParameterIuiv(uint32_t texture,
                          TexelGL::GL::Enum pname,
                          uint32_t *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetTextureParameterIuiv(texture,
                                           pname,
                                           params);
}

void
glGetTextureSubImage(uint32_t texture,
                     int32_t level,
                     int32_t xoffset,
                     int32_t yoffset,
                     int32_t zoffset,
                     int32_t width,
                     int32_t height,
                     int32_t depth,
                     TexelGL::GL::Enum format,
                     TexelGL::GL::Enum type,
                     int32_t bufSize,
                     void *pixels)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetTextureSubImage(texture,
                                      level,
                                      xoffset,
                                      yoffset,
                                      zoffset,
                                      width,
                                      height,
                                      depth,
                                      format,
                                      type,
                                      bufSize,
                                      pixels);
}

void
glGetTransformFeedbacki_v(uint32_t xfb,
                          TexelGL::GL::Enum pname,
                          uint32_t index,
                          int32_t *param)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetTransformFeedbacki_v(xfb,
                                           pname,
                                           index,
                                           param);
}

void
glGetTransformFeedbacki64_v(uint32_t xfb,
                            TexelGL::GL::Enum pname,
                            uint32_t index,
                            int64_t *param)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetTransformFeedbacki64_v(xfb,
                                             pname,
                                             index,
                                             param);
}

void
glGetTransformFeedbackiv(uint32_t xfb,
                         TexelGL::GL::Enum pname,
                         int32_t *param)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetTransformFeedbackiv(xfb,
                                          pname,
                                          param);
}

void
glGetVertexArrayiv(uint32_t vaobj,
                   TexelGL::GL::Enum pname,
                   int32_t *param)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetVertexArrayiv(vaobj,
                                    pname,
                                    param);
}

void
glGetVertexArrayIndexediv(uint32_t vaobj,
                          uint32_t index,
                          TexelGL::GL::Enum pname,
                          int32_t *param)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetVertexArrayIndexediv(vaobj,
                                           index,
                                           pname,
                                           param);
}

void
glGetVertexArrayIndexed64iv(uint32_t vaobj,
                            uint32_t index,
                            TexelGL::GL::Enum pname,
                            int64_t *param)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glGetVertexArrayIndexed64iv(vaobj,
                                             index,
                                             pname,
                                             param);
}

void
glInvalidateNamedFramebufferData(uint32_t framebuffer,
                                 int32_t numAttachments,
                                 TexelGL::GL::Enum const *attachments)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glInvalidateNamedFramebufferData(framebuffer,
                                                  numAttachments,
                                                  attachments);
}

void
glInvalidateNamedFramebufferSubData(uint32_t framebuffer,
                                    int32_t numAttachments,
                                    TexelGL::GL::Enum const *attachments,
                                    int32_t x,
                                    int32_t y,
                                    int32_t width,
                                    int32_t height)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glInvalidateNamedFramebufferSubData(framebuffer,
                                                     numAttachments,
                                                     attachments,
                                                     x,
                                                     y,
                                                     width,
                                                     height);
}

void *
glMapNamedBuffer(uint32_t buffer,
                 TexelGL::GL::Enum access)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return nullptr;
    }

    auto &context = *contextPointer;

    return context.gl45.glMapNamedBuffer(buffer,
                                        access);
}

void *
glMapNamedBufferRange(uint32_t buffer,
                      intptr_t offset,
                      intptr_t length,
                      TexelGL::GL::MapAccessFlags access)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return nullptr;
    }

    auto &context = *contextPointer;

    return context.gl45.glMapNamedBufferRange(buffer,
                                              offset,
                                              length,
                                              access);
}

void
glMemoryBarrierByRegion(uint32_t barriers)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glMemoryBarrierByRegion(barriers);
}

void
glNamedBufferData(uint32_t buffer,
                  intptr_t size,
                  void const *data,
                  TexelGL::GL::Enum usage)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glNamedBufferData(buffer,
                                   size,
                                   data,
                                   usage);
}

void
glNamedBufferStorage(uint32_t buffer,
                     intptr_t size,
                     void const *data,
                     uint32_t flags)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glNamedBufferStorage(buffer,
                                      size,
                                      data,
                                      flags);
}

void
glNamedBufferSubData(uint32_t buffer,
                     intptr_t offset,
                     intptr_t size,
                     void const *data)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glNamedBufferSubData(buffer,
                                      offset,
                                      size,
                                      data);
}

void
glNamedFramebufferDrawBuffer(uint32_t framebuffer,
                             TexelGL::GL::Enum buf)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glNamedFramebufferDrawBuffer(framebuffer,
                                              buf);
}

void
glNamedFramebufferDrawBuffers(uint32_t framebuffer,
                              int32_t n,
                              TexelGL::GL::Enum const *bufs)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glNamedFramebufferDrawBuffers(framebuffer,
                                               n,
                                               bufs);
}

void
glNamedFramebufferParameteri(uint32_t framebuffer,
                             TexelGL::GL::Enum pname,
                             int32_t param)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glNamedFramebufferParameteri(framebuffer,
                                              pname,
                                              param);
}

void
glNamedFramebufferReadBuffer(uint32_t framebuffer,
                             TexelGL::GL::Enum src)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glNamedFramebufferReadBuffer(framebuffer,
                                              src);
}

void
glNamedFramebufferRenderbuffer(uint32_t framebuffer,
                               TexelGL::GL::Enum attachment,
                               TexelGL::GL::Enum renderbuffertarget,
                               uint32_t renderbuffer)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glNamedFramebufferRenderbuffer(framebuffer,
                                                attachment,
                                                renderbuffertarget,
                                                renderbuffer);
}

void
glNamedFramebufferTexture(uint32_t framebuffer,
                          TexelGL::GL::Enum attachment,
                          uint32_t texture,
                          int32_t level)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glNamedFramebufferTexture(framebuffer,
                                           attachment,
                                           texture,
                                           level);
}

void
glNamedFramebufferTextureLayer(uint32_t framebuffer,
                               TexelGL::GL::Enum attachment,
                               uint32_t texture,
                               int32_t level,
                               int32_t layer)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glNamedFramebufferTextureLayer(framebuffer,
                                                attachment,
                                                texture,
                                                level,
                                                layer);
}

void
glReadnPixels(int32_t x,
              int32_t y,
              int32_t width,
              int32_t height,
              TexelGL::GL::Enum format,
              TexelGL::GL::Enum type,
              int32_t bufSize,
              void *data)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glReadnPixels(x,
                               y,
                               width,
                               height,
                               format,
                               type,
                               bufSize,
                               data);
}

 void
glTextureBarrier(void)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glTextureBarrier();
}

void
glTextureBuffer(uint32_t texture,
                TexelGL::GL::Enum internalformat,
                uint32_t buffer)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glTextureBuffer(texture,
                                 internalformat,
                                 buffer);
}

void
glTextureBufferRange(uint32_t texture,
                     TexelGL::GL::Enum internalformat,
                     uint32_t buffer,
                     intptr_t offset,
                     intptr_t size)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glTextureBufferRange(texture,
                                      internalformat,
                                      buffer,
                                      offset,
                                      size);
}

void
glTextureParameterf(uint32_t texture,
                    TexelGL::GL::Enum pname,
                    float param)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glTextureParameterf(texture,
                                     pname,
                                     param);
}

void
glTextureParameterfv(uint32_t texture,
                     TexelGL::GL::Enum pname,
                     float const *param)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glTextureParameterfv(texture,
                                      pname,
                                      param);
}

void
glTextureParameteri(uint32_t texture,
                    TexelGL::GL::Enum pname,
                    int32_t param)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glTextureParameteri(texture,
                                     pname,
                                     param);
}

void
glTextureParameteriv(uint32_t texture,
                     TexelGL::GL::Enum pname,
                     int32_t const *param)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glTextureParameteriv(texture,
                                      pname,
                                      param);
}

void
glTextureParameterIiv(uint32_t texture,
                      TexelGL::GL::Enum pname,
                      int32_t const *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glTextureParameterIiv(texture,
                                       pname,
                                       params);
}

void
glTextureParameterIuiv(uint32_t texture,
                       TexelGL::GL::Enum pname,
                       uint32_t const *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glTextureParameterIuiv(texture,
                                      pname,
                                      params);
}

 void
glTextureStorage1D(uint32_t texture,
                   int32_t levels,
                   TexelGL::GL::Enum internalformat,
                   int32_t width)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glTextureStorage1D(texture,
                                    levels,
                                    internalformat,
                                    width);
}

void
glTextureStorage2D(uint32_t texture,
                   int32_t levels,
                   TexelGL::GL::Enum internalformat,
                   int32_t width,
                   int32_t height)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glTextureStorage2D(texture,
                                    levels,
                                    internalformat,
                                    width,
                                    height);
}

void
glTextureStorage2DMultisample(uint32_t texture,
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

    context.gl45.glTextureStorage2DMultisample(texture,
                                               samples,
                                               internalformat,
                                               width,
                                               height,
                                               fixedsamplelocations);
}

void
glTextureStorage3D(uint32_t texture,
                   int32_t levels,
                   TexelGL::GL::Enum internalformat,
                   int32_t width,
                   int32_t height,
                   int32_t depth)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glTextureStorage3D(texture,
                                    levels,
                                    internalformat,
                                    width,
                                    height,
                                    depth);
}

void
glTextureStorage3DMultisample(uint32_t texture,
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

    context.gl45.glTextureStorage3DMultisample(texture,
                                               samples,
                                               internalformat,
                                               width,
                                               height,
                                               depth,
                                               fixedsamplelocations);
}

void
glTextureSubImage1D(uint32_t texture,
                    int32_t level,
                    int32_t xoffset,
                    int32_t width,
                    TexelGL::GL::Enum format,
                    TexelGL::GL::Enum type,
                    void const *pixels)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glTextureSubImage1D(texture,
                                     level,
                                     xoffset,
                                     width,
                                     format,
                                     type,
                                     pixels);
}

void
glTextureSubImage2D(uint32_t texture,
                    int32_t level,
                    int32_t xoffset,
                    int32_t yoffset,
                    int32_t width,
                    int32_t height,
                    TexelGL::GL::Enum format,
                    TexelGL::GL::Enum type,
                    void const *pixels)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glTextureSubImage2D(texture,
                                     level,
                                     xoffset,
                                     yoffset,
                                     width,
                                     height,
                                     format,
                                     type,
                                     pixels);
}

void
glTextureSubImage3D(uint32_t texture,
                    int32_t level,
                    int32_t xoffset,
                    int32_t yoffset,
                    int32_t zoffset,
                    int32_t width,
                    int32_t height,
                    int32_t depth,
                    TexelGL::GL::Enum format,
                    TexelGL::GL::Enum type,
                    void const *pixels)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glTextureSubImage3D(texture,
                                     level,
                                     xoffset,
                                     yoffset,
                                     zoffset,
                                     width,
                                     height,
                                     depth,
                                     format,
                                     type,
                                     pixels);
}

void
glTransformFeedbackBufferBase(uint32_t xfb,
                              uint32_t index,
                              uint32_t buffer)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glTransformFeedbackBufferBase(xfb,
                                               index,
                                               buffer);
}

void
glTransformFeedbackBufferRange(uint32_t xfb,
                               uint32_t index,
                               uint32_t buffer,
                               intptr_t offset,
                               intptr_t size)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glTransformFeedbackBufferRange(xfb,
                                                index,
                                                buffer,
                                                offset,
                                                size);
}

void
glVertexArrayAttribBinding(uint32_t vaobj,
                           uint32_t attribindex,
                           uint32_t bindingindex)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glVertexArrayAttribBinding(vaobj,
                                            attribindex,
                                            bindingindex);
}

void
glVertexArrayAttribFormat(uint32_t vaobj,
                          uint32_t attribindex,
                          int32_t size,
                          TexelGL::GL::Enum type,
                          uint8_t normalized,
                          uint32_t relativeoffset)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glVertexArrayAttribFormat(vaobj,
                                           attribindex,
                                           size,
                                           type,
                                           normalized,
                                           relativeoffset);
}

void
glVertexArrayAttribIFormat(uint32_t vaobj,
                           uint32_t attribindex,
                           int32_t size,
                           TexelGL::GL::Enum type,
                           uint32_t relativeoffset)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glVertexArrayAttribIFormat(vaobj,
                                            attribindex,
                                            size,
                                            type,
                                            relativeoffset);
}

void
glVertexArrayAttribLFormat(uint32_t vaobj,
                           uint32_t attribindex,
                           int32_t size,
                           TexelGL::GL::Enum type,
                           uint32_t relativeoffset)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glVertexArrayAttribLFormat(vaobj,
                                            attribindex,
                                            size,
                                            type,
                                            relativeoffset);
}

void
glVertexArrayBindingDivisor(uint32_t vaobj,
                            uint32_t bindingindex,
                            uint32_t divisor)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glVertexArrayBindingDivisor(vaobj,
                                             bindingindex,
                                             divisor);
}

void
glVertexArrayElementBuffer(uint32_t vaobj,
                           uint32_t buffer)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glVertexArrayElementBuffer(vaobj,
                                            buffer);
}

void
glVertexArrayVertexBuffer(uint32_t vaobj,
                          uint32_t bindingindex,
                          uint32_t buffer,
                          intptr_t offset,
                          int32_t stride)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glVertexArrayVertexBuffer(vaobj,
                                           bindingindex,
                                           buffer,
                                           offset,
                                           stride);
}

void
glVertexArrayVertexBuffers(uint32_t vaobj,
                           uint32_t first,
                           int32_t count,
                           uint32_t const *buffers,
                           intptr_t const *offsets,
                           int32_t const *strides)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl45.glVertexArrayVertexBuffers(vaobj,
                                            first,
                                            count,
                                            buffers,
                                            offsets,
                                            strides);
}

uint8_t
glUnmapNamedBuffer(uint32_t buffer)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return false;
    }

    auto &context = *contextPointer;

    return context.gl45.glUnmapNamedBuffer(buffer);
}