#pragma once

#include "Entrypoints.h"

EXPORT_API void
glBindFramebuffer(TexelGL::GL::Enum target,
                  uint32_t framebuffer);

EXPORT_API void
glBindRenderbuffer(TexelGL::GL::Enum target,
                   uint32_t renderbuffer);

EXPORT_API void
glBindVertexArray(uint32_t array);

EXPORT_API void
glBlitFramebuffer(int32_t srcX0,
                  int32_t srcY0,
                  int32_t srcX1,
                  int32_t srcY1,
                  int32_t dstX0,
                  int32_t dstY0,
                  int32_t dstX1,
                  int32_t dstY1,
                  uint32_t mask,
                  TexelGL::GL::Enum filter);

EXPORT_API void
glDeleteFramebuffers(int32_t n,
                     uint32_t *framebuffers);

EXPORT_API void
glDeleteRenderbuffers(int32_t n,
                      uint32_t *renderbuffers);

EXPORT_API void
glDeleteVertexArrays(int32_t n,
                     uint32_t *arrays);

EXPORT_API void
glFlushMappedBufferRange(TexelGL::GL::Enum target,
                         intptr_t offset,
                         intptr_t length);

EXPORT_API void
glFramebufferRenderbuffer(TexelGL::GL::Enum target,
                          TexelGL::GL::Enum attachment,
                          TexelGL::GL::Enum renderbufferTarget,
                          uint32_t renderbuffer);

EXPORT_API void
glFramebufferTexture2D(TexelGL::GL::Enum target,
                       TexelGL::GL::Enum attachment,
                       TexelGL::GL::Enum textureTarget,
                       uint32_t texture,
                       int32_t level);

EXPORT_API void
glGenBuffers(int32_t n,
             uint32_t *buffers);

EXPORT_API void
glGenFramebuffers(int32_t n,
                  uint32_t *framebuffers);

EXPORT_API void
glGenRenderbuffers(int32_t n,
                   uint32_t *renderbuffers);

EXPORT_API void
glGenVertexArrays(int32_t n,
                  uint32_t *arrays);

EXPORT_API void
glGetIntegeri_v(TexelGL::GL::Enum name,
                uint32_t index,
                int32_t &data);

EXPORT_API void
glGetIntegerv(TexelGL::GL::Enum name,
              int32_t &data);

EXPORT_API void *
glMapBufferRange(TexelGL::GL::Enum target,
                 intptr_t offset,
                 intptr_t length,
                 TexelGL::GL::MapAccessFlags access);

EXPORT_API void
glRenderbufferStorage(TexelGL::GL::Enum target,
                      TexelGL::GL::Enum internalFormat,
                      int32_t width,
                      int32_t height);