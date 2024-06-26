#pragma once

#include "OpenGLDefinitions.h"

namespace TexelGL {
    class Context;

    class ContextInterface {
    protected:
        Context &context;

    public:
        ContextInterface(Context &context);
    };

    class ContextInterfaceGL10: public ContextInterface {
    public:
        void
        glClear(uint32_t mask);

        void
        glClearColor(float red,
                     float green,
                     float blue,
                     float alpha);

        void
        glClearDepth(double depth);

        void
        glClearStencil(int32_t s);

        void
        glColorMask(uint8_t red,
                    uint8_t green,
                    uint8_t blue,
                    uint8_t alpha);

        void
        glCullFace(TexelGL::GL::Enum mode);

        void
        glDepthFunc(TexelGL::GL::Enum func);

        void
        glDepthMask(uint8_t flag);

        void
        glDisable(TexelGL::GL::Enum cap);

        void
        glDrawBuffer(TexelGL::GL::Enum buf);

        void
        glEnable(TexelGL::GL::Enum cap);

        void
        glFinish(void);

        void
        glFlush(void);

        void
        glFrontFace(TexelGL::GL::Enum mode);

        TexelGL::GL::Enum
        glGetError(void);

        void
        glGetFloatv(TexelGL::GL::Enum name,
                    float &data);

        uint8_t const *
        glGetString(TexelGL::GL::Enum name);

        void
        glHint(TexelGL::GL::Enum target,
               TexelGL::GL::Enum mode);

        void
        glLineWidth(float width);

        void
        glPointSize(float size);

        void
        glPolygonMode(TexelGL::GL::Enum face,
                      TexelGL::GL::Enum mode);

        void
        glReadBuffer(TexelGL::GL::Enum src);

        void
        glStencilMask(uint32_t mask);

        void
        glScissor(int32_t x,
                  int32_t y,
                  int32_t width,
                  int32_t height);

        void
        glTexImage1D(TexelGL::GL::Enum target,
                     int32_t level,
                     int32_t internalformat,
                     int32_t width,
                     int32_t border,
                     TexelGL::GL::Enum format,
                     TexelGL::GL::Enum type,
                     void const *pixels);

        void
        glTexImage2D(TexelGL::GL::Enum target,
                     int32_t level,
                     int32_t internalformat,
                     int32_t width,
                     int32_t height,
                     int32_t border,
                     TexelGL::GL::Enum format,
                     TexelGL::GL::Enum type,
                     void const *pixels);

        void
        glTexParameterf(TexelGL::GL::Enum target,
                        TexelGL::GL::Enum pname,
                        float param);

        void
        glTexParameterfv(TexelGL::GL::Enum target,
                         TexelGL::GL::Enum pname,
                         float const *params);

        void
        glTexParameteri(TexelGL::GL::Enum target,
                        TexelGL::GL::Enum pname,
                        int32_t param);

        void
        glTexParameteriv(TexelGL::GL::Enum target,
                         TexelGL::GL::Enum pname,
                         int32_t const *params);

        void
        glViewport(int32_t x,
                   int32_t y,
                   int32_t width,
                   int32_t height);
    };

    class ContextInterfaceGL11: public ContextInterface {
    public:
        void
        glBindTexture(TexelGL::GL::Enum target,
                      uint32_t texture);

        void
        glCopyTexImage1D(TexelGL::GL::Enum target,
                         int32_t level,
                         int32_t internalformat,
                         int32_t x,
                         int32_t y,
                         int32_t width,
                         int32_t border);

        void
        glCopyTexImage2D(TexelGL::GL::Enum target,
                         int32_t level,
                         int32_t internalformat,
                         int32_t x,
                         int32_t y,
                         int32_t width,
                         int32_t height,
                         int32_t border);

        void
        glCopyTexSubImage1D(TexelGL::GL::Enum target,
                            int32_t level,
                            int32_t xOffset,
                            int32_t x,
                            int32_t y,
                            int32_t width);
        void
        glCopyTexSubImage2D(TexelGL::GL::Enum target,
                            int32_t level,
                            int32_t xOffset,
                            int32_t yOffset,
                            int32_t x,
                            int32_t y,
                            int32_t width,
                            int32_t height);

        void
        glDeleteTextures(int32_t n,
                         uint32_t const *textures);

        void
        glDrawArrays(TexelGL::GL::Enum mode,
                     int32_t first,
                     int32_t count);

        void
        glDrawElements(TexelGL::GL::Enum mode,
                       int32_t count,
                       TexelGL::GL::Enum type,
                       void const *indices);

        void
        glGenTextures(int32_t n,
                      uint32_t *textures);

        void
        glGetPointerv(TexelGL::GL::Enum pname,
                      void **params);

        uint8_t
        glIsTexture(uint32_t texture);

        void
        glPolygonOffset(float factor,
                        float units);

        void
        glTexSubImage1D(TexelGL::GL::Enum target,
                        int32_t level,
                        int32_t xOffset,
                        int32_t width,
                        TexelGL::GL::Enum format,
                        TexelGL::GL::Enum type,
                        void const *pixels);

        void
        glTexSubImage2D(TexelGL::GL::Enum target,
                        int32_t level,
                        int32_t xOffset,
                        int32_t yOffset,
                        int32_t width,
                        int32_t height,
                        TexelGL::GL::Enum format,
                        TexelGL::GL::Enum type,
                        void const *pixels);
    };

    class ContextInterfaceGL12: public ContextInterface {
    public:
        void
        glCopyTexSubImage3D(TexelGL::GL::Enum target,
                            int32_t level,
                            int32_t xOffset,
                            int32_t yOffset,
                            int32_t zOffset,
                            int32_t x,
                            int32_t y,
                            int32_t width,
                            int32_t height);

        void
        glDrawRangeElements(TexelGL::GL::Enum mode,
                            uint32_t start,
                            uint32_t end,
                            int32_t count,
                            TexelGL::GL::Enum type,
                            void const *indices);

        void
        glTexImage3D(TexelGL::GL::Enum target,
                     int32_t level,
                     int32_t internalFormat,
                     int32_t width,
                     int32_t height,
                     int32_t depth,
                     int32_t border,
                     TexelGL::GL::Enum format,
                     TexelGL::GL::Enum type,
                     void const *pixels);

        void
        glTexSubImage3D(TexelGL::GL::Enum target,
                        int32_t level,
                        int32_t xOffset,
                        int32_t yOffset,
                        int32_t zOffset,
                        int32_t width,
                        int32_t height,
                        int32_t depth,
                        TexelGL::GL::Enum format,
                        TexelGL::GL::Enum type,
                        void const *pixels);
    };

    class ContextInterfaceGL13: public ContextInterface {
    public:
        void
        glActiveTexture(TexelGL::GL::Enum texture);
    };

    class ContextInterfaceGL14: public ContextInterface {
    public:
        void
        glBlendColor(float red,
                     float green,
                     float blue,
                     float alpha);

        void
        glBlendEquation(TexelGL::GL::Enum mode);

        void
        glBlendFuncSeparate(TexelGL::GL::Enum sfactorRGB,
                            TexelGL::GL::Enum dfactorRGB,
                            TexelGL::GL::Enum sfactorAlpha,
                            TexelGL::GL::Enum dfactorAlpha);

        void
        glMultiDrawArrays(TexelGL::GL::Enum mode,
                          int32_t const *first,
                          int32_t const * count,
                          int32_t drawcount);

        void
        glMultiDrawElements(TexelGL::GL::Enum mode,
                            int32_t const *count,
                            TexelGL::GL::Enum type,
                            void const * const *indices,
                            int32_t drawcount);

        void
        glPointParameterf(TexelGL::GL::Enum pname,
                         float param);

        void
        glPointParameterfv(TexelGL::GL::Enum pname,
                           float const *params);

        void
        glPointParameteri(TexelGL::GL::Enum pname,
                          int32_t param);

        void
        glPointParameteriv(TexelGL::GL::Enum pname,
                           int32_t *params);
    };

    class ContextInterfaceGL15: public ContextInterface {
    public:
        void
        glBindBuffer(TexelGL::GL::Enum target,
                     uint32_t buffer);

        void
        glBufferData(TexelGL::GL::Enum target,
                     intptr_t size,
                     void const *data,
                     TexelGL::GL::Enum usage);

        void
        glDeleteBuffers(int32_t n,
                        uint32_t const *buffers);

        void
        glGenBuffers(int32_t n,
                     uint32_t *buffers);

        uint8_t
        glIsBuffer(uint32_t buffer);

        uint8_t
        glUnmapBuffer(TexelGL::GL::Enum target);
    };

    class ContextInterfaceGL20: public ContextInterface {
    public:
        void
        glAttachShader(uint32_t program,
                       uint32_t shader);

        void
        glBindAttribLocation(uint32_t program,
                             uint32_t index,
                             char const *name);

        void
        glCompileShader(uint32_t shader);

        uint32_t
        glCreateProgram(void);

        uint32_t
        glCreateShader(TexelGL::GL::Enum shaderType);

        void
        glDeleteProgram(uint32_t program);

        void
        glDeleteShader(uint32_t shader);

        void
        glDetachShader(uint32_t program,
                       uint32_t shader);

        void
        glDisableVertexAttribArray(uint32_t index);

        void
        glDrawBuffers(int32_t n,
                      TexelGL::GL::Enum const *bufs);

        void
        glEnableVertexAttribArray(uint32_t index);

        void
        glGetShaderiv(uint32_t shader,
                      TexelGL::GL::Enum name,
                      int32_t *params);

        void
        glGetProgramiv(uint32_t program,
                       TexelGL::GL::Enum name,
                       int32_t *params);

        void
        glGetUniformLocation(uint32_t program,
                             char const *name);

        void
        glLinkProgram(uint32_t program);

        void
        glShaderSource(uint32_t shader,
                       int32_t count,
                       char const * const *string,
                       int32_t const *length);

        void
        glUniform1i(int32_t location,
                    int32_t v0);

        void
        glUseProgram(uint32_t program);
    };

    class ContextInterfaceGL21: public ContextInterface {
    };

    class ContextInterfaceGL22: public ContextInterface {
    };

    class ContextInterfaceGL30: public ContextInterface {
    public:
        void
        glBindBufferBase(TexelGL::GL::Enum target,
                         uint32_t index,
                         uint32_t buffer);

        void
        glBindBufferRange(TexelGL::GL::Enum target,
                          uint32_t index,
                          uint32_t buffer,
                          intptr_t offset,
                          intptr_t size);

        void
        glBindFramebuffer(TexelGL::GL::Enum target,
                          uint32_t framebuffer);

        void
        glBindRenderbuffer(TexelGL::GL::Enum target,
                           uint32_t renderbuffer);

        void
        glBindVertexArray(uint32_t array);

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
                          TexelGL::GL::Enum filter);

        void
        glDeleteFramebuffers(int32_t n,
                             uint32_t *framebuffers);

        void
        glDeleteRenderbuffers(int32_t n,
                              uint32_t *renderbuffers);

        void
        glDeleteVertexArrays(int32_t n,
                             uint32_t *arrays);

        void
        glFlushMappedBufferRange(TexelGL::GL::Enum target,
                                 intptr_t offset,
                                 intptr_t length);

        void
        glFramebufferRenderbuffer(TexelGL::GL::Enum target,
                                  TexelGL::GL::Enum attachment,
                                  TexelGL::GL::Enum renderbufferTarget,
                                  uint32_t renderbuffer);

        void
        glFramebufferTexture2D(TexelGL::GL::Enum target,
                               TexelGL::GL::Enum attachment,
                               TexelGL::GL::Enum textureTarget,
                               uint32_t texture,
                               int32_t level);

        void
        glGenerateMipmap(TexelGL::GL::Enum target);

        void
        glGenBuffers(int32_t n,
                     uint32_t *buffers);

        void
        glGenFramebuffers(int32_t n,
                          uint32_t *framebuffers);

        void
        glGenRenderbuffers(int32_t n,
                           uint32_t *renderbuffers);

        void
        glGenVertexArrays(int32_t n,
                          uint32_t *arrays);

        void
        glGetIntegeri_v(TexelGL::GL::Enum name,
                        uint32_t index,
                        int32_t &data);

        void
        glGetIntegerv(TexelGL::GL::Enum name,
                      int32_t &data);

        void *
        glMapBufferRange(TexelGL::GL::Enum target,
                         intptr_t offset,
                         intptr_t length,
                         TexelGL::GL::MapAccessFlags access);

        void
        glRenderbufferStorage(TexelGL::GL::Enum target,
                              TexelGL::GL::Enum internalFormat,
                              int32_t width,
                              int32_t height);
    };

    class ContextInterfaceGL31: public ContextInterface {
    public:
        void
        glGetActiveUniformBlockiv(uint32_t program,
                                  uint32_t uniformBlockIndex,
                                  TexelGL::GL::Enum name,
                                  int32_t *params);

        void
        glGetUniformBlockIndex(uint32_t program,
                               char const *uniformBlockName);

        void
        glUniformBlockBinding(uint32_t program,
                              uint32_t uniformBlockIndex,
                              uint32_t uniformBlockBinding);
    };

    class ContextInterfaceGL32: public ContextInterface {
    public:
        TexelGL::GL::Enum
        glClientWaitSync(TexelGL::GL::Sync sync,
                         uint32_t flags,
                         uint64_t timeout);

        void
        glDeleteSync(TexelGL::GL::Sync sync);

        void
        glDrawElementsBaseVertex(TexelGL::GL::Enum mode,
                                 int32_t count,
                                 TexelGL::GL::Enum type,
                                 void const *indices,
                                 int32_t basevertex);

        void
        glDrawElementsInstancedBaseVertex(TexelGL::GL::Enum mode,
                                          int32_t count,
                                          TexelGL::GL::Enum type,
                                          void const *indices,
                                          int32_t instancecount,
                                          int32_t basevertex);

        void
        glDrawRangeElementsBaseVertex(TexelGL::GL::Enum mode,
                                      uint32_t start,
                                      uint32_t end,
                                      int32_t count,
                                      TexelGL::GL::Enum type,
                                      void const *indices,
                                      int32_t basevertex);

        TexelGL::GL::Sync
        glFenceSync(TexelGL::GL::Enum condition,
                    uint32_t flags);

        void
        glFramebufferTexture(TexelGL::GL::Enum target,
                             TexelGL::GL::Enum attachment,
                             uint32_t texture,
                             int32_t level);

        void
        glGetBufferParameteri64v(TexelGL::GL::Enum target,
                                 TexelGL::GL::Enum pname,
                                 int64_t *params);

        void
        glGetInteger64i_v(TexelGL::GL::Enum target,
                          uint32_t index,
                          int64_t *data);

        void
        glGetInteger64v(TexelGL::GL::Enum pname,
                        int64_t *data);

        void
        glGetMultisamplefv(TexelGL::GL::Enum pname,
                           uint32_t index,
                           float *val);

        void
        glGetSynciv(TexelGL::GL::Sync sync,
                    TexelGL::GL::Enum pname,
                    int32_t count,
                    int32_t *length,
                    int32_t *values);

        uint8_t
        glIsSync(TexelGL::GL::Sync sync);

        void
        glMultiDrawElementsBaseVertex(TexelGL::GL::Enum mode,
                                      int32_t const *count,
                                      TexelGL::GL::Enum type,
                                      void const * const *indices,
                                      int32_t drawcount,
                                      int32_t const *basevertex);

        void
        glProvokingVertex(TexelGL::GL::Enum mode);

        void
        glTexImage2DMultisample(TexelGL::GL::Enum target,
                                int32_t samples,
                                TexelGL::GL::Enum internalformat,
                                int32_t width,
                                int32_t height,
                                uint8_t fixedsamplelocations);

        void
        glTexImage3DMultisample(TexelGL::GL::Enum target,
                                int32_t samples,
                                TexelGL::GL::Enum internalformat,
                                int32_t width,
                                int32_t height,
                                int32_t depth,
                                uint8_t fixedsamplelocations);

        void
        glSampleMaski(uint32_t maskNumber,
                      uint32_t mask);

        void
        glWaitSync(TexelGL::GL::Sync sync,
                   uint32_t flags,
                   uint64_t timeout);
    };

    class ContextInterfaceGL33: public ContextInterface {
    public:
        void
        glBindSampler(uint32_t sampler);

        void
        glDeleteSamplers(int32_t n,
                         uint32_t *samplers);

        void
        glGenSamplers(int32_t n,
                      uint32_t *samplers);

        void
        glSamplerParameterf(uint32_t sampler,
                            TexelGL::GL::Enum name,
                            float param);

        void
        glSamplerParameterfv(uint32_t sampler,
                             TexelGL::GL::Enum name,
                             float *param);

        void
        glSamplerParameteri(uint32_t sampler,
                            TexelGL::GL::Enum name,
                            int32_t param);

        void
        glSamplerParameteriv(uint32_t sampler,
                             TexelGL::GL::Enum name,
                             int32_t *param);
    };

    class ContextInterfaceGL40: public ContextInterface {
    };

    class ContextInterfaceGL41: public ContextInterface {
    public:
        void
        glClearDepthf(float d);

        void
        glShaderBinary(int32_t count,
                       uint32_t const *shaders,
                       TexelGL::GL::Enum binaryFormat,
                       void const *binary,
                       int32_t length);
    };

    class ContextInterfaceGL42: public ContextInterface {
    };

    class ContextInterfaceGL43: public ContextInterface {
    };

    class ContextInterfaceGL44: public ContextInterface {
    public:
        void
        glBindBuffersBase(TexelGL::GL::Enum target,
                          uint32_t first,
                          int32_t count,
                          uint32_t const *buffers);

        void
        glBindBuffersRange(TexelGL::GL::Enum target,
                           uint32_t first,
                           int32_t count,
                           uint32_t const *buffers,
                           intptr_t const *offsets,
                           intptr_t const *sizes);
    };

    class ContextInterfaceGL45: public ContextInterface {
    public:
        void
        glBindTextureUnit(uint32_t unit,
                          uint32_t texture);

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
                               TexelGL::GL::Enum filter);

        TexelGL::GL::Enum
        glCheckNamedFramebufferStatus(uint32_t framebuffer,
                                      TexelGL::GL::Enum target);

        void
        glClearNamedFramebufferiv(uint32_t framebuffer,
                                  TexelGL::GL::Enum buffer,
                                  int32_t drawbuffer,
                                  int32_t const *value);

        void
        glClearNamedFramebufferfi(uint32_t framebuffer,
                                  TexelGL::GL::Enum buffer,
                                  int32_t drawbuffer,
                                  float depth,
                                  int32_t stencil);

        void
        glClearNamedFramebufferfv(uint32_t framebuffer,
                                  TexelGL::GL::Enum buffer,
                                  int32_t drawbuffer,
                                  float const *value);

        void
        glClearNamedFramebufferuiv(uint32_t framebuffer,
                                   TexelGL::GL::Enum buffer,
                                   int32_t drawbuffer,
                                   uint32_t const *value);

        void
        glClearNamedBufferData(uint32_t buffer,
                               TexelGL::GL::Enum internalformat,
                               TexelGL::GL::Enum format,
                               TexelGL::GL::Enum type,
                               void const *data);

        void
        glClearNamedBufferSubData(uint32_t buffer,
                                  TexelGL::GL::Enum internalformat,
                                  intptr_t offset,
                                  intptr_t size,
                                  TexelGL::GL::Enum format,
                                  TexelGL::GL::Enum type,
                                  void const *data);

        void
        glClipControl(TexelGL::GL::Enum origin,
                      TexelGL::GL::Enum depth);

        void
        glCompressedTextureSubImage1D(uint32_t texture,
                                      int32_t level,
                                      int32_t xoffset,
                                      int32_t width,
                                      TexelGL::GL::Enum format,
                                      int32_t imageSize,
                                      void const *data);

        void
        glCompressedTextureSubImage2D(uint32_t texture,
                                      int32_t level,
                                      int32_t xoffset,
                                      int32_t yoffset,
                                      int32_t width,
                                      int32_t height,
                                      TexelGL::GL::Enum format,
                                      int32_t imageSize,
                                      void const *data);

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
                                      void const *data);

        void
        glCopyTextureSubImage1D(uint32_t texture,
                                int32_t level,
                                int32_t xoffset,
                                int32_t x,
                                int32_t y,
                                int32_t width);

        void
        glCopyTextureSubImage2D(uint32_t texture,
                                int32_t level,
                                int32_t xoffset,
                                int32_t yoffset,
                                int32_t x,
                                int32_t y,
                                int32_t width,
                                int32_t height);

        void
        glCopyTextureSubImage3D(uint32_t texture,
                                int32_t level,
                                int32_t xoffset,
                                int32_t yoffset,
                                int32_t zoffset,
                                int32_t x,
                                int32_t y,
                                int32_t width,
                                int32_t height);

        void
        glCopyNamedBufferSubData(uint32_t readBuffer,
                                 uint32_t writeBuffer,
                                 intptr_t readOffset,
                                 intptr_t writeOffset,
                                 intptr_t size);

        void
        glCreateBuffers(int32_t n,
                        uint32_t *buffers);

        void
        glCreateFramebuffers(int32_t n,
                             uint32_t *framebuffers);

        void
        glCreateProgramPipelines(int32_t n,
                                 uint32_t *pipelines);

        void
        glCreateQueries(TexelGL::GL::Enum target,
                        int32_t n,
                        uint32_t *ids);

        void
        glCreateRenderbuffers(int32_t n,
                              uint32_t *renderbuffers);

        void
        glCreateTextures(TexelGL::GL::Enum target,
                         int32_t n,
                         uint32_t *textures);

        void
        glCreateTransformFeedbacks(int32_t n,
                                   uint32_t *ids);

        void
        glCreateSamplers(int32_t n,
                         uint32_t *samplers);

        void
        glCreateVertexArrays(int32_t n,
                             uint32_t *arrays);

        void
        glDisableVertexArrayAttrib(uint32_t vaobj,
                                   uint32_t index);

        void
        glEnableVertexArrayAttrib(uint32_t vaobj,
                                  uint32_t index);

        void
        glFlushMappedNamedBufferRange(uint32_t buffer,
                                      intptr_t offset,
                                      intptr_t length);

        void
        glGenerateTextureMipmap(uint32_t texture);

        void
        glGetnCompressedTexImage(TexelGL::GL::Enum target,
                                 int32_t lod,
                                 int32_t bufSize,
                                 void *pixels);

        void
        glGetnTexImage(TexelGL::GL::Enum target,
                       int32_t level,
                       TexelGL::GL::Enum format,
                       TexelGL::GL::Enum type,
                       int32_t bufSize,
                       void *pixels);

        void
        glGetnUniformdv(uint32_t program,
                        int32_t location,
                        int32_t bufSize,
                        double *params);

        void
        glGetnUniformfv(uint32_t program,
                        int32_t location,
                        int32_t bufSize,
                        float *params);

        void
        glGetnUniformiv(uint32_t program,
                        int32_t location,
                        int32_t bufSize,
                        int32_t *params);

        void
        glGetnUniformuiv(uint32_t program,
                         int32_t location,
                         int32_t bufSize,
                         uint32_t *params);

        void
        glGetCompressedTextureImage(uint32_t texture,
                                    int32_t level,
                                    int32_t bufSize,
                                    void *pixels);

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
                                       void *pixels);

        TexelGL::GL::Enum
        glGetGraphicsResetStatus(void);

        void
        glGetNamedBufferParameteriv(uint32_t buffer,
                                    TexelGL::GL::Enum pname,
                                    int32_t *params);

        void
        glGetNamedBufferParameteri64v(uint32_t buffer,
                                      TexelGL::GL::Enum pname,
                                      int64_t *params);

        void
        glGetNamedBufferPointerv(uint32_t buffer,
                                 TexelGL::GL::Enum pname,
                                 void **params);

        void
        glGetNamedBufferSubData(uint32_t buffer,
                                intptr_t offset,
                                intptr_t size,
                                void *data);

        void
        glGetNamedFramebufferAttachmentParameteriv(uint32_t framebuffer,
                                                   TexelGL::GL::Enum attachment,
                                                   TexelGL::GL::Enum pname,
                                                   int32_t *params);

        void
        glGetNamedFramebufferParameteriv(uint32_t framebuffer,
                                         TexelGL::GL::Enum pname,
                                         int32_t *param);

        void
        glGetNamedRenderbufferParameteriv(uint32_t renderbuffer,
                                          TexelGL::GL::Enum pname,
                                          int32_t *params);

        void
        glGetQueryBufferObjecti64v(uint32_t id,
                                   uint32_t buffer,
                                   TexelGL::GL::Enum pname,
                                   intptr_t offset);

        void
        glGetQueryBufferObjectiv(uint32_t id,
                                 uint32_t buffer,
                                 TexelGL::GL::Enum pname,
                                 intptr_t offset);

        void
        glGetQueryBufferObjectui64v(uint32_t id,
                                    uint32_t buffer,
                                    TexelGL::GL::Enum pname,
                                    intptr_t offset);

        void
        glGetQueryBufferObjectuiv(uint32_t id,
                                  uint32_t buffer,
                                  TexelGL::GL::Enum pname,
                                  intptr_t offset);

        void
        glGetTextureImage(uint32_t texture,
                          int32_t level,
                          TexelGL::GL::Enum format,
                          TexelGL::GL::Enum type,
                          int32_t bufSize,
                          void *pixels);

        void
        glGetTextureLevelParameterfv(uint32_t texture,
                                    int32_t level,
                                    TexelGL::GL::Enum pname,
                                    float *params);

        void
        glGetTextureLevelParameteriv(uint32_t texture,
                                    int32_t level,
                                    TexelGL::GL::Enum pname,
                                    int32_t *params);

        void
        glGetTextureParameterfv(uint32_t texture,
                                TexelGL::GL::Enum pname,
                                float *params);

        void
        glGetTextureParameteriv(uint32_t texture,
                                TexelGL::GL::Enum pname,
                                int32_t *params);

        void
        glGetTextureParameterIiv(uint32_t texture,
                                TexelGL::GL::Enum pname,
                                int32_t *params);

        void
        glGetTextureParameterIuiv(uint32_t texture,
                                  TexelGL::GL::Enum pname,
                                  uint32_t *params);

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
                             void *pixels);

        void
        glGetTransformFeedbacki_v(uint32_t xfb,
                                  TexelGL::GL::Enum pname,
                                  uint32_t index,
                                  int32_t *param);

        void
        glGetTransformFeedbacki64_v(uint32_t xfb,
                                    TexelGL::GL::Enum pname,
                                    uint32_t index,
                                    int64_t *param);

        void
        glGetTransformFeedbackiv(uint32_t xfb,
                                 TexelGL::GL::Enum pname,
                                 int32_t *param);

        void
        glGetVertexArrayiv(uint32_t vaobj,
                           TexelGL::GL::Enum pname,
                           int32_t *param);

        void
        glGetVertexArrayIndexediv(uint32_t vaobj,
                                  uint32_t index,
                                  TexelGL::GL::Enum pname,
                                  int32_t *param);

        void
        glGetVertexArrayIndexed64iv(uint32_t vaobj,
                                    uint32_t index,
                                    TexelGL::GL::Enum pname,
                                    int64_t *param);

        void
        glInvalidateNamedFramebufferData(uint32_t framebuffer,
                                         int32_t numAttachments,
                                         TexelGL::GL::Enum const *attachments);

        void
        glInvalidateNamedFramebufferSubData(uint32_t framebuffer,
                                            int32_t numAttachments,
                                            TexelGL::GL::Enum const *attachments,
                                            int32_t x,
                                            int32_t y,
                                            int32_t width,
                                            int32_t height);

        void *
        glMapNamedBuffer(uint32_t buffer,
                         TexelGL::GL::Enum access);

        void *
        glMapNamedBufferRange(uint32_t buffer,
                              intptr_t offset,
                              intptr_t length,
                              TexelGL::GL::MapAccessFlags access);

        void
        glMemoryBarrierByRegion(uint32_t barriers);

        void
        glNamedBufferData(uint32_t buffer,
                          intptr_t size,
                          void const *data,
                          TexelGL::GL::Enum usage);

        void
        glNamedBufferStorage(uint32_t buffer,
                             intptr_t size,
                             void const *data,
                             uint32_t flags);

        void
        glNamedBufferSubData(uint32_t buffer,
                             intptr_t offset,
                             intptr_t size,
                             void const *data);

        void
        glNamedFramebufferDrawBuffer(uint32_t framebuffer,
                                     TexelGL::GL::Enum buf);

        void
        glNamedFramebufferDrawBuffers(uint32_t framebuffer,
                                      int32_t n,
                                      TexelGL::GL::Enum const *bufs);

        void
        glNamedFramebufferParameteri(uint32_t framebuffer,
                                     TexelGL::GL::Enum pname,
                                     int32_t param);

        void
        glNamedFramebufferReadBuffer(uint32_t framebuffer,
                                     TexelGL::GL::Enum src);

        void
        glNamedFramebufferRenderbuffer(uint32_t framebuffer,
                                       TexelGL::GL::Enum attachment,
                                       TexelGL::GL::Enum renderbuffertarget,
                                       uint32_t renderbuffer);

        void
        glNamedFramebufferTexture(uint32_t framebuffer,
                                  TexelGL::GL::Enum attachment,
                                  uint32_t texture,
                                  int32_t level);

        void
        glNamedFramebufferTextureLayer(uint32_t framebuffer,
                                       TexelGL::GL::Enum attachment,
                                       uint32_t texture,
                                       int32_t level,
                                       int32_t layer);

        void
        glReadnPixels(int32_t x,
                      int32_t y,
                      int32_t width,
                      int32_t height,
                      TexelGL::GL::Enum format,
                      TexelGL::GL::Enum type,
                      int32_t bufSize,
                      void *data);

        void
        glTextureBarrier(void);


        void
        glTextureBuffer(uint32_t texture,
                        TexelGL::GL::Enum internalformat,
                        uint32_t buffer);

        void
        glTextureBufferRange(uint32_t texture,
                             TexelGL::GL::Enum internalformat,
                             uint32_t buffer,
                             intptr_t offset,
                             intptr_t size);

        void
        glTextureParameterf(uint32_t texture,
                            TexelGL::GL::Enum pname,
                            float param);

        void
        glTextureParameterfv(uint32_t texture,
                             TexelGL::GL::Enum pname,
                             float const *param);

        void
        glTextureParameteri(uint32_t texture,
                            TexelGL::GL::Enum pname,
                            int32_t param);

        void
        glTextureParameteriv(uint32_t texture,
                             TexelGL::GL::Enum pname,
                             int32_t const *param);

        void
        glTextureParameterIiv(uint32_t texture,
                              TexelGL::GL::Enum pname,
                              int32_t const *params);

        void
        glTextureParameterIuiv(uint32_t texture,
                               TexelGL::GL::Enum pname,
                               uint32_t const *params);

        void
        glTextureStorage1D(uint32_t texture,
                           int32_t levels,
                           TexelGL::GL::Enum internalformat,
                           int32_t width);

        void
        glTextureStorage2D(uint32_t texture,
                           int32_t levels,
                           TexelGL::GL::Enum internalformat,
                           int32_t width,
                           int32_t height);

        void
        glTextureStorage2DMultisample(uint32_t texture,
                                      int32_t samples,
                                      TexelGL::GL::Enum internalformat,
                                      int32_t width,
                                      int32_t height,
                                      uint8_t fixedsamplelocations);

        void
        glTextureStorage3D(uint32_t texture,
                           int32_t levels,
                           TexelGL::GL::Enum internalformat,
                           int32_t width,
                           int32_t height,
                           int32_t depth);

        void
        glTextureStorage3DMultisample(uint32_t texture,
                                      int32_t samples,
                                      TexelGL::GL::Enum internalformat,
                                      int32_t width,
                                      int32_t height,
                                      int32_t depth,
                                      uint8_t fixedsamplelocations);

        void
        glTextureSubImage1D(uint32_t texture,
                            int32_t level,
                            int32_t xoffset,
                            int32_t width,
                            TexelGL::GL::Enum format,
                            TexelGL::GL::Enum type,
                            void const *pixels);

        void
        glTextureSubImage2D(uint32_t texture,
                            int32_t level,
                            int32_t xoffset,
                            int32_t yoffset,
                            int32_t width,
                            int32_t height,
                            TexelGL::GL::Enum format,
                            TexelGL::GL::Enum type,
                            void const *pixels);

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
                            void const *pixels);

        void
        glTransformFeedbackBufferBase(uint32_t xfb,
                                      uint32_t index,
                                      uint32_t buffer);

        void
        glTransformFeedbackBufferRange(uint32_t xfb,
                                       uint32_t index,
                                       uint32_t buffer,
                                       intptr_t offset,
                                       intptr_t size);

        void
        glVertexArrayAttribBinding(uint32_t vaobj,
                                   uint32_t attribindex,
                                   uint32_t bindingindex);

        void
        glVertexArrayAttribFormat(uint32_t vaobj,
                                  uint32_t attribindex,
                                  int32_t size,
                                  TexelGL::GL::Enum type,
                                  uint8_t normalized,
                                  uint32_t relativeoffset);

        void
        glVertexArrayAttribIFormat(uint32_t vaobj,
                                   uint32_t attribindex,
                                   int32_t size,
                                   TexelGL::GL::Enum type,
                                   uint32_t relativeoffset);

        void
        glVertexArrayAttribLFormat(uint32_t vaobj,
                                   uint32_t attribindex,
                                   int32_t size,
                                   TexelGL::GL::Enum type,
                                   uint32_t relativeoffset);

        void
        glVertexArrayBindingDivisor(uint32_t vaobj,
                                    uint32_t bindingindex,
                                    uint32_t divisor);

        void
        glVertexArrayElementBuffer(uint32_t vaobj,
                                   uint32_t buffer);

        void
        glVertexArrayVertexBuffer(uint32_t vaobj,
                                  uint32_t bindingindex,
                                  uint32_t buffer,
                                  intptr_t offset,
                                  int32_t stride);

        void
        glVertexArrayVertexBuffers(uint32_t vaobj,
                                   uint32_t first,
                                   int32_t count,
                                   uint32_t const *buffers,
                                   intptr_t const *offsets,
                                   int32_t const *strides);

        uint8_t
        glUnmapNamedBuffer(uint32_t buffer);
    };

    class ContextInterfaceGL46: public ContextInterface {
    public:
        void
        glSpecializeShader(uint32_t shader,
                           char const *pEntryPoint,
                           uint32_t numSpecializationConstants,
                           uint32_t const *pConstantIndex,
                           uint32_t const *pConstantValue);
    };
} // namespace TexelGL