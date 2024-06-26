#pragma once

#include "Entrypoints.h"

EXPORT_API TexelGL::GL::Enum
glClientWaitSync(TexelGL::GL::Sync sync,
                 uint32_t flags,
                 uint64_t timeout);

EXPORT_API void
glDeleteSync(TexelGL::GL::Sync sync);

EXPORT_API void
glDrawElementsBaseVertex(TexelGL::GL::Enum mode,
                         int32_t count,
                         TexelGL::GL::Enum type,
                         void const *indices,
                         int32_t basevertex);

EXPORT_API void
glDrawElementsInstancedBaseVertex(TexelGL::GL::Enum mode,
                                  int32_t count,
                                  TexelGL::GL::Enum type,
                                  void const *indices,
                                  int32_t instancecount,
                                  int32_t basevertex);

EXPORT_API void
glDrawRangeElementsBaseVertex(TexelGL::GL::Enum mode,
                              uint32_t start,
                              uint32_t end,
                              int32_t count,
                              TexelGL::GL::Enum type,
                              void const *indices,
                              int32_t basevertex);

EXPORT_API TexelGL::GL::Sync
glFenceSync(TexelGL::GL::Enum condition,
            uint32_t flags);

EXPORT_API void
glFramebufferTexture(TexelGL::GL::Enum target,
                     TexelGL::GL::Enum attachment,
                     uint32_t texture,
                     int32_t level);

EXPORT_API void
glGetBufferParameteri64v(TexelGL::GL::Enum target,
                         TexelGL::GL::Enum pname,
                         int64_t *params);

EXPORT_API void
glGetInteger64i_v(TexelGL::GL::Enum target,
                  uint32_t index,
                  int64_t *data);

EXPORT_API void
glGetInteger64v(TexelGL::GL::Enum pname,
                int64_t *data);

EXPORT_API void
glGetMultisamplefv(TexelGL::GL::Enum pname,
                   uint32_t index,
                   float *val);

EXPORT_API void
glGetSynciv(TexelGL::GL::Sync sync,
            TexelGL::GL::Enum pname,
            int32_t count,
            int32_t *length,
            int32_t *values);

EXPORT_API uint8_t
glIsSync(TexelGL::GL::Sync sync);

EXPORT_API void
glMultiDrawElementsBaseVertex(TexelGL::GL::Enum mode,
                              int32_t const *count,
                              TexelGL::GL::Enum type,
                              void const * const *indices,
                              int32_t drawcount,
                              int32_t const *basevertex);

EXPORT_API void
glProvokingVertex(TexelGL::GL::Enum mode);

EXPORT_API void
glTexImage2DMultisample(TexelGL::GL::Enum target,
                        int32_t samples,
                        TexelGL::GL::Enum internalformat,
                        int32_t width,
                        int32_t height,
                        uint8_t fixedsamplelocations);

EXPORT_API void
glTexImage3DMultisample(TexelGL::GL::Enum target,
                        int32_t samples,
                        TexelGL::GL::Enum internalformat,
                        int32_t width,
                        int32_t height,
                        int32_t depth,
                        uint8_t fixedsamplelocations);

EXPORT_API void
glSampleMaski(uint32_t maskNumber,
              uint32_t mask);

EXPORT_API void
glWaitSync(TexelGL::GL::Sync sync,
           uint32_t flags,
           uint64_t timeout);