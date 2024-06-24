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
        glFinish(void);

        void
        glFlush(void);

        TexelGL::GL::Enum
        glGetError(void);

        void
        glGetFloatv(TexelGL::GL::Enum name,
                    float &data);

        uint8_t const *
        glGetString(TexelGL::GL::Enum name);

        void
        glReadBuffer(TexelGL::GL::Enum src);

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
        glTexParameteri(TexelGL::GL::Enum target,
                        TexelGL::GL::Enum pname,
                        int32_t param);

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
        glDeleteTextures(int32_t n,
                         uint32_t const *textures);

        void
        glGenTextures(int32_t n,
                      uint32_t const *textures);

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
        glCreateShader(void);

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
    };

    class ContextInterfaceGL30: public ContextInterface {
    public:
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
                         uint32_t access);

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

    class ContextInterfaceGL45: public ContextInterface {
    public:
        void
        glCreateBuffers(int32_t n,
                        uint32_t *buffers);

        void
        glCreateFramebuffers(int32_t n,
                             uint32_t *framebuffers);

        void
        glCreateRenderbuffers(int32_t n,
                              uint32_t *renderbuffers);

        void
        glCreateSamplers(int32_t n,
                         uint32_t *samplers);

        void
        glCreateVertexArrays(int32_t n,
                             uint32_t *arrays);
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