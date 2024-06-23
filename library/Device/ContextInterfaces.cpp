#include <cassert>
#include "Context.h"
#include "ContextInterfaces.h"

TexelGL::ContextInterface::ContextInterface(Context &context) :
    context(context)
{
}

void
TexelGL::ContextInterfaceGL10::glClear(uint32_t mask)
{
}

void
TexelGL::ContextInterfaceGL10::glClearColor(float red, float green, float blue, float alpha)
{
}

void
TexelGL::ContextInterfaceGL10::glClearDepth(double depth)
{
}

void
TexelGL::ContextInterfaceGL10::glFinish(void)
{
}

void
TexelGL::ContextInterfaceGL10::glFlush(void)
{
}

TexelGL::GL::Enum
TexelGL::ContextInterfaceGL10::glGetError(void)
{
    return TexelGL::GL::EnumNoError;
}

void
TexelGL::ContextInterfaceGL10::glGetFloatv(TexelGL::GL::Enum name,
                                           float &data)
{
    switch (name) {
    default:
        break;
    }
}

uint8_t const *
TexelGL::ContextInterfaceGL10::glGetString(TexelGL::GL::Enum name)
{
    switch (name) {
    case TexelGL::GL::EnumRenderer:
        return reinterpret_cast <uint8_t const *> (this->context.getRenderer().c_str());

    case TexelGL::GL::EnumVendor:
        return reinterpret_cast <uint8_t const*> (this->context.getVendor().c_str());

    default:
        return nullptr;
    }
}

void
TexelGL::ContextInterfaceGL10::glReadBuffer(TexelGL::GL::Enum src)
{
}

void
TexelGL::ContextInterfaceGL10::glTexImage2D(TexelGL::GL::Enum target,
                                            int32_t level,
                                            int32_t internalformat,
                                            int32_t width,
                                            int32_t height,
                                            int32_t border,
                                            TexelGL::GL::Enum format,
                                            TexelGL::GL::Enum type,
                                            void const *pixels)
{
}

void
TexelGL::ContextInterfaceGL10::glTexParameterf(TexelGL::GL::Enum target,
                                               TexelGL::GL::Enum pname,
                                               float param)
{
}

void
TexelGL::ContextInterfaceGL10::glTexParameteri(TexelGL::GL::Enum target,
                                               TexelGL::GL::Enum pname,
                                               int32_t param)
{
}

void
TexelGL::ContextInterfaceGL10::glViewport(int32_t x,
                                          int32_t y,
                                          int32_t width,
                                          int32_t height)
{
}

void
TexelGL::ContextInterfaceGL11::glBindTexture(TexelGL::GL::Enum target,
                                             uint32_t texture)
{
}

void
TexelGL::ContextInterfaceGL11::glDeleteTextures(int32_t n,
                                                uint32_t const *textures)
{
}

void
TexelGL::ContextInterfaceGL11::glGenTextures(int32_t n,
                                             uint32_t const *textures)
{
}

void
TexelGL::ContextInterfaceGL11::glTexSubImage2D(TexelGL::GL::Enum target,
                                               int32_t level,
                                               int32_t xOffset,
                                               int32_t yOffset,
                                               int32_t width,
                                               int32_t height,
                                               TexelGL::GL::Enum format,
                                               TexelGL::GL::Enum type,
                                               void const *pixels)
{
}

void
TexelGL::ContextInterfaceGL15::glBindBuffer(TexelGL::GL::Enum target,
                                            uint32_t buffer)
{
}

void
TexelGL::ContextInterfaceGL15::glBufferData(TexelGL::GL::Enum target,
                                            intptr_t size,
                                            void const *data,
                                            TexelGL::GL::Enum usage)
{
}

uint8_t
TexelGL::ContextInterfaceGL15::glUnmapBuffer(TexelGL::GL::Enum target)
{
    return true;
}

void
TexelGL::ContextInterfaceGL20::glAttachShader(uint32_t program,
                                              uint32_t shader)
{
}

void
TexelGL::ContextInterfaceGL20::glBindAttribLocation(uint32_t program,
                                                    uint32_t index,
                                                    char const *name)
{
}

void
TexelGL::ContextInterfaceGL20::glCompileShader(uint32_t shader)
{
}

uint32_t
TexelGL::ContextInterfaceGL20::glCreateProgram(void)
{
    return 0;
}

uint32_t
TexelGL::ContextInterfaceGL20::glCreateShader(void)
{
    return 0;
}

void
TexelGL::ContextInterfaceGL20::glDeleteProgram(uint32_t program)
{
}

void
TexelGL::ContextInterfaceGL20::glDeleteShader(uint32_t shader)
{
}

void
TexelGL::ContextInterfaceGL20::glDetachShader(uint32_t program,
                                              uint32_t shader)
{
}

void
TexelGL::ContextInterfaceGL20::glDisableVertexAttribArray(uint32_t index)
{
}

void
TexelGL::ContextInterfaceGL20::glDrawBuffers(int32_t n,
                                             TexelGL::GL::Enum const* bufs)
{
}

void
TexelGL::ContextInterfaceGL20::glEnableVertexAttribArray(uint32_t index)
{
}

void
TexelGL::ContextInterfaceGL20::glGetShaderiv(uint32_t shader,
                                             TexelGL::GL::Enum name,
                                             int32_t *params)
{
    if (!params) {
        return;
    }

    switch (name) {
    case TexelGL::GL::EnumCompileStatus:
        *params = true;
        break;

    default:
        assert(false);
    }
}

void
TexelGL::ContextInterfaceGL20::glGetProgramiv(uint32_t program,
                                              TexelGL::GL::Enum name,
                                              int32_t *params)
{
    if (!params) {
        return;
    }

    switch (name) {
    case TexelGL::GL::EnumLinkStatus:
        *params = true;
        break;

    default:
        assert(false);
    }
}

void
TexelGL::ContextInterfaceGL20::glGetUniformLocation(uint32_t program,
                                                    char const *name)
{
}

void
TexelGL::ContextInterfaceGL20::glLinkProgram(uint32_t program)
{
}

void
TexelGL::ContextInterfaceGL20::glShaderSource(uint32_t shader,
                                              int32_t count,
                                              char const * const *string,
                                              int32_t const* length)
{
}

void
TexelGL::ContextInterfaceGL20::glUniform1i(int32_t location,
                                           int32_t v0)
{
}

void
TexelGL::ContextInterfaceGL30::glBindFramebuffer(TexelGL::GL::Enum target,
                                                 uint32_t framebuffer)
{
}

void
TexelGL::ContextInterfaceGL30::glBindRenderbuffer(TexelGL::GL::Enum target,
                                                  uint32_t renderbuffer)
{
}

void
TexelGL::ContextInterfaceGL30::glBindVertexArray(uint32_t array)
{
}

void
TexelGL::ContextInterfaceGL30::glBlitFramebuffer(int32_t srcX0,
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
}

void
TexelGL::ContextInterfaceGL30::glDeleteFramebuffers(int32_t n,
                                                    uint32_t *framebuffers)
{
}

void
TexelGL::ContextInterfaceGL30::glDeleteRenderbuffers(int32_t n,
                                                     uint32_t *renderbuffers)
{
}

void
TexelGL::ContextInterfaceGL30::glDeleteVertexArrays(int32_t n,
                                                    uint32_t *arrays)
{
}

void
TexelGL::ContextInterfaceGL30::glFlushMappedBufferRange(TexelGL::GL::Enum target,
                                                        intptr_t offset,
                                                        intptr_t length)
{
}

void
TexelGL::ContextInterfaceGL30::glFramebufferRenderbuffer(TexelGL::GL::Enum target,
                                                         TexelGL::GL::Enum attachment,
                                                         TexelGL::GL::Enum renderbufferTarget,
                                                         uint32_t renderbuffer)
{
}

void
TexelGL::ContextInterfaceGL30::glFramebufferTexture2D(TexelGL::GL::Enum target,
                                                      TexelGL::GL::Enum attachment,
                                                      TexelGL::GL::Enum textureTarget,
                                                      uint32_t texture,
                                                      int32_t level)
{
}

void
TexelGL::ContextInterfaceGL30::glGenBuffers(int32_t n,
                                            uint32_t *buffers)
{
}

void
TexelGL::ContextInterfaceGL30::glGenFramebuffers(int32_t n,
                                                 uint32_t *framebuffers)
{
}

void
TexelGL::ContextInterfaceGL30::glGenRenderbuffers(int32_t n,
                                                  uint32_t *renderbuffers)
{
}

void
TexelGL::ContextInterfaceGL30::glGenVertexArrays(int32_t n,
                                                 uint32_t *arrays)
{
}

void
TexelGL::ContextInterfaceGL30::glGetIntegeri_v(TexelGL::GL::Enum name,
                                               uint32_t index,
                                               int32_t &data)
{
    switch (name) {
    default:
        break;
    }
}

void
TexelGL::ContextInterfaceGL30::glGetIntegerv(TexelGL::GL::Enum name,
                                             int32_t &data)
{
    switch (name) {
    case TexelGL::GL::EnumMajorVersion:
        data = this->context.getMajorVersion();
        break;

    case TexelGL::GL::EnumMinorVersion:
        data = this->context.getMajorVersion();
        break;

    case TexelGL::GL::EnumNumExtensions:
        data = static_cast <int32_t> (this->context.getExtensions().size());
        break;

    default:
        break;
    }
}

void *
TexelGL::ContextInterfaceGL30::glMapBufferRange(TexelGL::GL::Enum target,
                                                intptr_t offset,
                                                intptr_t length,
                                                uint32_t access)
{
    return nullptr;
}

void
TexelGL::ContextInterfaceGL30::glRenderbufferStorage(TexelGL::GL::Enum target,
                                                     TexelGL::GL::Enum internalFormat,
                                                     int32_t width,
                                                     int32_t height)
{
}

void
TexelGL::ContextInterfaceGL31::glGetActiveUniformBlockiv(uint32_t program,
                                                         uint32_t uniformBlockIndex,
                                                         TexelGL::GL::Enum name,
                                                         int32_t *params)
{
}

void
TexelGL::ContextInterfaceGL31::glGetUniformBlockIndex(uint32_t program,
                                                      char const *uniformBlockName)
{
}

void
TexelGL::ContextInterfaceGL31::glUniformBlockBinding(uint32_t program,
                                                     uint32_t uniformBlockIndex,
                                                     uint32_t uniformBlockBinding)
{
}

void
TexelGL::ContextInterfaceGL33::glBindSampler(uint32_t sampler)
{
}

void
TexelGL::ContextInterfaceGL33::glDeleteSamplers(int32_t n,
                                                uint32_t *samplers)
{
}

void
TexelGL::ContextInterfaceGL33::glGenSamplers(int32_t n,
                                             uint32_t *samplers)
{
}

void
TexelGL::ContextInterfaceGL33::glSamplerParameterf(uint32_t sampler,
                                                   TexelGL::GL::Enum name,
                                                   float param)
{
}

void
TexelGL::ContextInterfaceGL33::glSamplerParameterfv(uint32_t sampler,
                                                    TexelGL::GL::Enum name,
                                                    float *param)
{
}

void
TexelGL::ContextInterfaceGL33::glSamplerParameteri(uint32_t sampler,
                                                   TexelGL::GL::Enum name,
                                                   int32_t param)
{
}

void
TexelGL::ContextInterfaceGL33::glSamplerParameteriv(uint32_t sampler,
                                                    TexelGL::GL::Enum name,
                                                    int32_t *param)
{
}

void
TexelGL::ContextInterfaceGL41::glClearDepthf(float d)
{
}