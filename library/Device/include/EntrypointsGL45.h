#pragma once

#include "Entrypoints.h"

EXPORT_API void
glBindTextureUnit(uint32_t unit,
                  uint32_t texture);

EXPORT_API void
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
                       TexelGL::GL::Enum filter);

EXPORT_API TexelGL::GL::Enum
glCheckNamedFramebufferStatus(uint32_t framebuffer,
                              TexelGL::GL::Enum target);

EXPORT_API void
glClearNamedFramebufferiv(uint32_t framebuffer,
                          TexelGL::GL::Enum buffer,
                          int32_t drawbuffer,
                          int32_t const *value);

EXPORT_API void
glClearNamedFramebufferfi(uint32_t framebuffer,
                          TexelGL::GL::Enum buffer,
                          int32_t drawbuffer,
                          float depth,
                          int32_t stencil);

EXPORT_API void
glClearNamedFramebufferfv(uint32_t framebuffer,
                          TexelGL::GL::Enum buffer,
                          int32_t drawbuffer,
                          float const *value);

EXPORT_API void
glClearNamedFramebufferuiv(uint32_t framebuffer,
                           TexelGL::GL::Enum buffer,
                           int32_t drawbuffer,
                           uint32_t const *value);

EXPORT_API void
glClearNamedBufferData(uint32_t buffer,
                       TexelGL::GL::Enum internalformat,
                       TexelGL::GL::Enum format,
                       TexelGL::GL::Enum type,
                       void const *data);

EXPORT_API void
glClearNamedBufferSubData(uint32_t buffer,
                          TexelGL::GL::Enum internalformat,
                          intptr_t offset,
                          intptr_t size,
                          TexelGL::GL::Enum format,
                          TexelGL::GL::Enum type,
                          void const *data);

EXPORT_API void
glClipControl(TexelGL::GL::Enum origin,
              TexelGL::GL::Enum depth);

EXPORT_API void
glCompressedTextureSubImage1D(uint32_t texture,
                              int32_t level,
                              int32_t xoffset,
                              int32_t width,
                              TexelGL::GL::Enum format,
                              int32_t imageSize,
                              void const *data);

EXPORT_API void
glCompressedTextureSubImage2D(uint32_t texture,
                              int32_t level,
                              int32_t xoffset,
                              int32_t yoffset,
                              int32_t width,
                              int32_t height,
                              TexelGL::GL::Enum format,
                              int32_t imageSize,
                              void const *data);

EXPORT_API void
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
                              void const *data);

EXPORT_API void
glCopyTextureSubImage1D(uint32_t texture,
                        int32_t level,
                        int32_t xoffset,
                        int32_t x,
                        int32_t y,
                        int32_t width);

EXPORT_API void
glCopyTextureSubImage2D(uint32_t texture,
                        int32_t level,
                        int32_t xoffset,
                        int32_t yoffset,
                        int32_t x,
                        int32_t y,
                        int32_t width,
                        int32_t height);

EXPORT_API void
glCopyTextureSubImage3D(uint32_t texture,
                        int32_t level,
                        int32_t xoffset,
                        int32_t yoffset,
                        int32_t zoffset,
                        int32_t x,
                        int32_t y,
                        int32_t width,
                        int32_t height);

EXPORT_API void
glCopyNamedBufferSubData(uint32_t readBuffer,
                         uint32_t writeBuffer,
                         intptr_t readOffset,
                         intptr_t writeOffset,
                         intptr_t size);

EXPORT_API void
glCreateBuffers(int32_t n,
                uint32_t *buffers);

EXPORT_API void
glCreateFramebuffers(int32_t n,
                     uint32_t *framebuffers);

EXPORT_API void
glCreateProgramPipelines(int32_t n,
                         uint32_t *pipelines);

EXPORT_API void
glCreateQueries(TexelGL::GL::Enum target,
                int32_t n,
                uint32_t *ids);

EXPORT_API void
glCreateRenderbuffers(int32_t n,
                      uint32_t *renderbuffers);

EXPORT_API void
glCreateTextures(TexelGL::GL::Enum target,
                 int32_t n,
                 uint32_t *textures);

EXPORT_API void
glCreateTransformFeedbacks(int32_t n,
                           uint32_t *ids);

EXPORT_API void
glCreateSamplers(int32_t n,
                 uint32_t *samplers);

EXPORT_API void
glCreateVertexArrays(int32_t n,
                     uint32_t *arrays);

EXPORT_API void
glDisableVertexArrayAttrib(uint32_t vaobj,
                           uint32_t index);

EXPORT_API void
glEnableVertexArrayAttrib(uint32_t vaobj,
                          uint32_t index);

EXPORT_API void
glFlushMappedNamedBufferRange(uint32_t buffer,
                              intptr_t offset,
                              intptr_t length);

EXPORT_API void
glGenerateTextureMipmap(uint32_t texture);

EXPORT_API void
glGetnCompressedTexImage(TexelGL::GL::Enum target,
                         int32_t lod,
                         int32_t bufSize,
                         void *pixels);

EXPORT_API void
glGetnTexImage(TexelGL::GL::Enum target,
               int32_t level,
               TexelGL::GL::Enum format,
               TexelGL::GL::Enum type,
               int32_t bufSize,
               void *pixels);

EXPORT_API void
glGetnUniformdv(uint32_t program,
                int32_t location,
                int32_t bufSize,
                double *params);

EXPORT_API void
glGetnUniformfv(uint32_t program,
                int32_t location,
                int32_t bufSize,
                float *params);

EXPORT_API void
glGetnUniformiv(uint32_t program,
                int32_t location,
                int32_t bufSize,
                int32_t *params);

EXPORT_API void
glGetnUniformuiv(uint32_t program,
                 int32_t location,
                 int32_t bufSize,
                 uint32_t *params);

EXPORT_API void
glGetCompressedTextureImage(uint32_t texture,
                            int32_t level,
                            int32_t bufSize,
                            void *pixels);

EXPORT_API void
glGetCompressedTextureSubImage(uint32_t texture,
                               int32_t level,
                               int32_t xoffset,
                               int32_t yoffset,
                               int32_t zoffset,
                               int32_t width,
                               int32_t height,
                               int32_t depth,
                               int32_t bufSize,
                               void *pixels);

EXPORT_API TexelGL::GL::Enum
glGetGraphicsResetStatus(void);

EXPORT_API void
glGetNamedBufferParameteriv(uint32_t buffer,
                            TexelGL::GL::Enum pname,
                            int32_t *params);

EXPORT_API void
glGetNamedBufferParameteri64v(uint32_t buffer,
                              TexelGL::GL::Enum pname,
                              int64_t *params);

EXPORT_API void
glGetNamedBufferPointerv(uint32_t buffer,
                         TexelGL::GL::Enum pname,
                         void **params);

EXPORT_API void
glGetNamedBufferSubData(uint32_t buffer,
                        intptr_t offset,
                        intptr_t size,
                        void *data);

EXPORT_API void
glGetNamedFramebufferAttachmentParameteriv(uint32_t framebuffer,
                                           TexelGL::GL::Enum attachment,
                                           TexelGL::GL::Enum pname,
                                           int32_t *params);

EXPORT_API void
glGetNamedFramebufferParameteriv(uint32_t framebuffer,
                                 TexelGL::GL::Enum pname,
                                 int32_t *param);

EXPORT_API void
glGetNamedRenderbufferParameteriv(uint32_t renderbuffer,
                                  TexelGL::GL::Enum pname,
                                  int32_t *params);

EXPORT_API void
glGetQueryBufferObjecti64v(uint32_t id,
                           uint32_t buffer,
                           TexelGL::GL::Enum pname,
                           intptr_t offset);

EXPORT_API void
glGetQueryBufferObjectiv(uint32_t id,
                         uint32_t buffer,
                         TexelGL::GL::Enum pname,
                         intptr_t offset);

EXPORT_API void
glGetQueryBufferObjectui64v(uint32_t id,
                            uint32_t buffer,
                            TexelGL::GL::Enum pname,
                            intptr_t offset);

EXPORT_API void
glGetQueryBufferObjectuiv(uint32_t id,
                          uint32_t buffer,
                          TexelGL::GL::Enum pname,
                          intptr_t offset);

EXPORT_API void
glGetTextureImage(uint32_t texture,
                  int32_t level,
                  TexelGL::GL::Enum format,
                  TexelGL::GL::Enum type,
                  int32_t bufSize,
                  void *pixels);

EXPORT_API void
glGetTextureLevelParameterfv(uint32_t texture,
                            int32_t level,
                            TexelGL::GL::Enum pname,
                            float *params);

EXPORT_API void
glGetTextureLevelParameteriv(uint32_t texture,
                            int32_t level,
                            TexelGL::GL::Enum pname,
                            int32_t *params);

EXPORT_API void
glGetTextureParameterfv(uint32_t texture,
                        TexelGL::GL::Enum pname,
                        float *params);

EXPORT_API void
glGetTextureParameteriv(uint32_t texture,
                        TexelGL::GL::Enum pname,
                        int32_t *params);

EXPORT_API void
glGetTextureParameterIiv(uint32_t texture,
                        TexelGL::GL::Enum pname,
                        int32_t *params);

EXPORT_API void
glGetTextureParameterIuiv(uint32_t texture,
                          TexelGL::GL::Enum pname,
                          uint32_t *params);

EXPORT_API void
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
                     void *pixels);

EXPORT_API void
glGetTransformFeedbacki_v(uint32_t xfb,
                          TexelGL::GL::Enum pname,
                          uint32_t index,
                          int32_t *param);

EXPORT_API void
glGetTransformFeedbacki64_v(uint32_t xfb,
                            TexelGL::GL::Enum pname,
                            uint32_t index,
                            int64_t *param);

EXPORT_API void
glGetTransformFeedbackiv(uint32_t xfb,
                         TexelGL::GL::Enum pname,
                         int32_t *param);

EXPORT_API void
glGetVertexArrayiv(uint32_t vaobj,
                   TexelGL::GL::Enum pname,
                   int32_t *param);

EXPORT_API void
glGetVertexArrayIndexediv(uint32_t vaobj,
                          uint32_t index,
                          TexelGL::GL::Enum pname,
                          int32_t *param);

EXPORT_API void
glGetVertexArrayIndexed64iv(uint32_t vaobj,
                            uint32_t index,
                            TexelGL::GL::Enum pname,
                            int64_t *param);

EXPORT_API void
glInvalidateNamedFramebufferData(uint32_t framebuffer,
                                 int32_t numAttachments,
                                 TexelGL::GL::Enum const *attachments);

EXPORT_API void
glInvalidateNamedFramebufferSubData(uint32_t framebuffer,
                                    int32_t numAttachments,
                                    TexelGL::GL::Enum const *attachments,
                                    int32_t x,
                                    int32_t y,
                                    int32_t width,
                                    int32_t height);

EXPORT_API void *
glMapNamedBuffer(uint32_t buffer,
                 TexelGL::GL::Enum access);

EXPORT_API void *
glMapNamedBufferRange(uint32_t buffer,
                      intptr_t offset,
                      intptr_t length,
                      TexelGL::GL::MapAccessFlags access);

EXPORT_API void
glMemoryBarrierByRegion(uint32_t barriers);

EXPORT_API void
glNamedBufferData(uint32_t buffer,
                  intptr_t size,
                  void const *data,
                  TexelGL::GL::Enum usage);

EXPORT_API void
glNamedBufferStorage(uint32_t buffer,
                     intptr_t size,
                     void const *data,
                     uint32_t flags);

EXPORT_API void
glNamedBufferSubData(uint32_t buffer,
                     intptr_t offset,
                     intptr_t size,
                     void const *data);

EXPORT_API void
glNamedFramebufferDrawBuffer(uint32_t framebuffer,
                             TexelGL::GL::Enum buf);

EXPORT_API void
glNamedFramebufferDrawBuffers(uint32_t framebuffer,
                              int32_t n,
                              TexelGL::GL::Enum const *bufs);

EXPORT_API void
glNamedFramebufferParameteri(uint32_t framebuffer,
                             TexelGL::GL::Enum pname,
                             int32_t param);

EXPORT_API void
glNamedFramebufferReadBuffer(uint32_t framebuffer,
                             TexelGL::GL::Enum src);

EXPORT_API void
glNamedFramebufferRenderbuffer(uint32_t framebuffer,
                               TexelGL::GL::Enum attachment,
                               TexelGL::GL::Enum renderbuffertarget,
                               uint32_t renderbuffer);

EXPORT_API void
glNamedFramebufferTexture(uint32_t framebuffer,
                          TexelGL::GL::Enum attachment,
                          uint32_t texture,
                          int32_t level);

EXPORT_API void
glNamedFramebufferTextureLayer(uint32_t framebuffer,
                               TexelGL::GL::Enum attachment,
                               uint32_t texture,
                               int32_t level,
                               int32_t layer);

EXPORT_API void
glReadnPixels(int32_t x,
              int32_t y,
              int32_t width,
              int32_t height,
              TexelGL::GL::Enum format,
              TexelGL::GL::Enum type,
              int32_t bufSize,
              void *data);

EXPORT_API void
glTextureBarrier(void);


EXPORT_API void
glTextureBuffer(uint32_t texture,
                TexelGL::GL::Enum internalformat,
                uint32_t buffer);

EXPORT_API void
glTextureBufferRange(uint32_t texture,
                     TexelGL::GL::Enum internalformat,
                     uint32_t buffer,
                     intptr_t offset,
                     intptr_t size);

EXPORT_API void
glTextureParameterf(uint32_t texture,
                    TexelGL::GL::Enum pname,
                    float param);

EXPORT_API void
glTextureParameterfv(uint32_t texture,
                     TexelGL::GL::Enum pname,
                     float const *param);

EXPORT_API void
glTextureParameteri(uint32_t texture,
                    TexelGL::GL::Enum pname,
                    int32_t param);

EXPORT_API void
glTextureParameteriv(uint32_t texture,
                     TexelGL::GL::Enum pname,
                     int32_t const *param);

EXPORT_API void
glTextureParameterIiv(uint32_t texture,
                      TexelGL::GL::Enum pname,
                      int32_t const *params);

EXPORT_API void
glTextureParameterIuiv(uint32_t texture,
                       TexelGL::GL::Enum pname,
                       uint32_t const *params);

EXPORT_API void
glTextureStorage1D(uint32_t texture,
                   int32_t levels,
                   TexelGL::GL::Enum internalformat,
                   int32_t width);

EXPORT_API void
glTextureStorage2D(uint32_t texture,
                   int32_t levels,
                   TexelGL::GL::Enum internalformat,
                   int32_t width,
                   int32_t height);

EXPORT_API void
glTextureStorage2DMultisample(uint32_t texture,
                              int32_t samples,
                              TexelGL::GL::Enum internalformat,
                              int32_t width,
                              int32_t height,
                              uint8_t fixedsamplelocations);

EXPORT_API void
glTextureStorage3D(uint32_t texture,
                   int32_t levels,
                   TexelGL::GL::Enum internalformat,
                   int32_t width,
                   int32_t height,
                   int32_t depth);

EXPORT_API void
glTextureStorage3DMultisample(uint32_t texture,
                              int32_t samples,
                              TexelGL::GL::Enum internalformat,
                              int32_t width,
                              int32_t height,
                              int32_t depth,
                              uint8_t fixedsamplelocations);

EXPORT_API void
glTextureSubImage1D(uint32_t texture,
                    int32_t level,
                    int32_t xoffset,
                    int32_t width,
                    TexelGL::GL::Enum format,
                    TexelGL::GL::Enum type,
                    void const *pixels);

EXPORT_API void
glTextureSubImage2D(uint32_t texture,
                    int32_t level,
                    int32_t xoffset,
                    int32_t yoffset,
                    int32_t width,
                    int32_t height,
                    TexelGL::GL::Enum format,
                    TexelGL::GL::Enum type,
                    void const *pixels);

EXPORT_API void
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
                    void const *pixels);

EXPORT_API void
glTransformFeedbackBufferBase(uint32_t xfb,
                              uint32_t index,
                              uint32_t buffer);

EXPORT_API void
glTransformFeedbackBufferRange(uint32_t xfb,
                               uint32_t index,
                               uint32_t buffer,
                               intptr_t offset,
                               intptr_t size);

EXPORT_API void
glVertexArrayAttribBinding(uint32_t vaobj,
                           uint32_t attribindex,
                           uint32_t bindingindex);

EXPORT_API void
glVertexArrayAttribFormat(uint32_t vaobj,
                          uint32_t attribindex,
                          int32_t size,
                          TexelGL::GL::Enum type,
                          uint8_t normalized,
                          uint32_t relativeoffset);

EXPORT_API void
glVertexArrayAttribIFormat(uint32_t vaobj,
                           uint32_t attribindex,
                           int32_t size,
                           TexelGL::GL::Enum type,
                           uint32_t relativeoffset);

EXPORT_API void
glVertexArrayAttribLFormat(uint32_t vaobj,
                           uint32_t attribindex,
                           int32_t size,
                           TexelGL::GL::Enum type,
                           uint32_t relativeoffset);

EXPORT_API void
glVertexArrayBindingDivisor(uint32_t vaobj,
                            uint32_t bindingindex,
                            uint32_t divisor);

EXPORT_API void
glVertexArrayElementBuffer(uint32_t vaobj,
                           uint32_t buffer);

EXPORT_API void
glVertexArrayVertexBuffer(uint32_t vaobj,
                          uint32_t bindingindex,
                          uint32_t buffer,
                          intptr_t offset,
                          int32_t stride);

EXPORT_API void
glVertexArrayVertexBuffers(uint32_t vaobj,
                           uint32_t first,
                           int32_t count,
                           uint32_t const *buffers,
                           intptr_t const *offsets,
                           int32_t const *strides);

EXPORT_API uint8_t
glUnmapNamedBuffer(uint32_t buffer);