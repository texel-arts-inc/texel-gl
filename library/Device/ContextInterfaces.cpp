#include <cassert>
#include "Buffer.h"
#include "Context.h"
#include "ContextInterfaces.h"
#include "Device.h"
#include "Program.h"
#include "Renderbuffer.h"
#include "Shader.h"
#include "Sync.h"
#include "Texture.h"
#include "VertexArray.h"

TexelGL::ContextInterface::ContextInterface(Context &context) :
    context(context)
{
}

void
TexelGL::ContextInterfaceGL10::glClear(uint32_t mask)
{
}

void
TexelGL::ContextInterfaceGL10::glClearColor(float red,
                                            float green,
                                            float blue,
                                            float alpha)
{
}

void
TexelGL::ContextInterfaceGL10::glClearDepth(double depth)
{
}

void
TexelGL::ContextInterfaceGL10::glClearStencil(int32_t s)
{
}

void
TexelGL::ContextInterfaceGL10::glColorMask(uint8_t red,
                                           uint8_t green,
                                           uint8_t blue,
                                           uint8_t alpha)
{
}

void
TexelGL::ContextInterfaceGL10::glCullFace(TexelGL::GL::Enum mode)
{
}

void
TexelGL::ContextInterfaceGL10::glDepthFunc(TexelGL::GL::Enum func)
{
}

void
TexelGL::ContextInterfaceGL10::glDepthMask(uint8_t flag)
{
}

void
TexelGL::ContextInterfaceGL10::glDisable(TexelGL::GL::Enum cap)
{
}

void
TexelGL::ContextInterfaceGL10::glDrawBuffer(TexelGL::GL::Enum buf)
{
}

void
TexelGL::ContextInterfaceGL10::glEnable(TexelGL::GL::Enum cap)
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

void
TexelGL::ContextInterfaceGL10::glFrontFace(TexelGL::GL::Enum mode)
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
TexelGL::ContextInterfaceGL10::glHint(TexelGL::GL::Enum target,
                                      TexelGL::GL::Enum mode)
{
}

void
TexelGL::ContextInterfaceGL10::glLineWidth(float width)
{
}

void
TexelGL::ContextInterfaceGL10::glPointSize(float size)
{
}

void
TexelGL::ContextInterfaceGL10::glPolygonMode(TexelGL::GL::Enum face,
                                             TexelGL::GL::Enum mode)
{
}

void
TexelGL::ContextInterfaceGL10::glReadBuffer(TexelGL::GL::Enum src)
{
}

void
TexelGL::ContextInterfaceGL10::glStencilMask(uint32_t mask)
{
}

void
TexelGL::ContextInterfaceGL10::glScissor(int32_t x,
                                         int32_t y,
                                         int32_t width,
                                         int32_t height)
{
}

void
TexelGL::ContextInterfaceGL10::glTexImage1D(TexelGL::GL::Enum target,
                                            int32_t level,
                                            int32_t internalformat,
                                            int32_t width,
                                            int32_t border,
                                            TexelGL::GL::Enum format,
                                            TexelGL::GL::Enum type,
                                            void const *pixels)
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
TexelGL::ContextInterfaceGL10::glTexParameterfv(TexelGL::GL::Enum target,
                                                TexelGL::GL::Enum pname,
                                                float const *params)
{
}

void
TexelGL::ContextInterfaceGL10::glTexParameteri(TexelGL::GL::Enum target,
                                               TexelGL::GL::Enum pname,
                                               int32_t param)
{
}

void
TexelGL::ContextInterfaceGL10::glTexParameteriv(TexelGL::GL::Enum target,
                                                TexelGL::GL::Enum pname,
                                                int32_t const *params)
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
TexelGL::ContextInterfaceGL11::glCopyTexImage1D(TexelGL::GL::Enum target,
                                                int32_t level,
                                                int32_t internalformat,
                                                int32_t x,
                                                int32_t y,
                                                int32_t width,
                                                int32_t border)
{
}

void
TexelGL::ContextInterfaceGL11::glCopyTexImage2D(TexelGL::GL::Enum target,
                                                int32_t level,
                                                int32_t internalformat,
                                                int32_t x,
                                                int32_t y,
                                                int32_t width,
                                                int32_t height,
                                                int32_t border)
{
}

void
TexelGL::ContextInterfaceGL11::glCopyTexSubImage1D(TexelGL::GL::Enum target,
                                                   int32_t level,
                                                   int32_t xOffset,
                                                   int32_t x,
                                                   int32_t y,
                                                   int32_t width)
{
}

void
TexelGL::ContextInterfaceGL11::glCopyTexSubImage2D(TexelGL::GL::Enum target,
                                                   int32_t level,
                                                   int32_t xOffset,
                                                   int32_t yOffset,
                                                   int32_t x,
                                                   int32_t y,
                                                   int32_t width,
                                                   int32_t height)
{
}

void
TexelGL::ContextInterfaceGL11::glDeleteTextures(int32_t n,
                                                uint32_t const *textures)
{
    for (auto i = size_t(0);
         i < n;
         ++i) {
        this->context.deallocateObject(textures[i]);
    }
}

void
TexelGL::ContextInterfaceGL11::glDrawArrays(TexelGL::GL::Enum mode,
                                            int32_t first,
                                            int32_t count)
{
}

void
TexelGL::ContextInterfaceGL11::glDrawElements(TexelGL::GL::Enum mode,
                                              int32_t count,
                                              TexelGL::GL::Enum type,
                                              void const *indices)
{
}

void
TexelGL::ContextInterfaceGL11::glGenTextures(int32_t n,
                                             uint32_t *textures)
{
    for (auto i = size_t(0);
         i < n;
         ++i) {
        auto const id = this->context.allocateTexture();

        textures[i] = id;
    }
}

void
TexelGL::ContextInterfaceGL11::glGetPointerv(TexelGL::GL::Enum pname,
                                             void **params)
{
}

uint8_t
TexelGL::ContextInterfaceGL11::glIsTexture(uint32_t texture)
{
    return true;
}

void
TexelGL::ContextInterfaceGL11::glPolygonOffset(float factor,
                                               float units)
{
}

void
TexelGL::ContextInterfaceGL11::glTexSubImage1D(TexelGL::GL::Enum target,
                                               int32_t level,
                                               int32_t xOffset,
                                               int32_t width,
                                               TexelGL::GL::Enum format,
                                               TexelGL::GL::Enum type,
                                               void const *pixels)
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
TexelGL::ContextInterfaceGL12::glCopyTexSubImage3D(TexelGL::GL::Enum target,
                                                   int32_t level,
                                                   int32_t xOffset,
                                                   int32_t yOffset,
                                                   int32_t zOffset,
                                                   int32_t x,
                                                   int32_t y,
                                                   int32_t width,
                                                   int32_t height)
{
}

void
TexelGL::ContextInterfaceGL12::glDrawRangeElements(TexelGL::GL::Enum mode,
                                                   uint32_t start,
                                                   uint32_t end,
                                                   int32_t count,
                                                   TexelGL::GL::Enum type,
                                                   void const *indices)
{
}

void
TexelGL::ContextInterfaceGL12::glTexImage3D(TexelGL::GL::Enum target,
                                            int32_t level,
                                            int32_t internalFormat,
                                            int32_t width,
                                            int32_t height,
                                            int32_t depth,
                                            int32_t border,
                                            TexelGL::GL::Enum format,
                                            TexelGL::GL::Enum type,
                                            void const *pixels)
{
}

void
TexelGL::ContextInterfaceGL12::glTexSubImage3D(TexelGL::GL::Enum target,
                                               int32_t level,
                                               int32_t xOffset,
                                               int32_t yOffset,
                                               int32_t zOffset,
                                               int32_t width,
                                               int32_t height,
                                               int32_t depth,
                                               TexelGL::GL::Enum format,
                                               TexelGL::GL::Enum type,
                                               void const *pixels)
{
}

void
TexelGL::ContextInterfaceGL13::glActiveTexture(TexelGL::GL::Enum texture)
{
}

void
TexelGL::ContextInterfaceGL14::glBlendColor(float red,
                                            float green,
                                            float blue,
                                            float alpha)
{
}

void
TexelGL::ContextInterfaceGL14::glBlendEquation(TexelGL::GL::Enum mode)
{
}

void
TexelGL::ContextInterfaceGL14::glBlendFuncSeparate(TexelGL::GL::Enum sfactorRGB,
                                                   TexelGL::GL::Enum dfactorRGB,
                                                   TexelGL::GL::Enum sfactorAlpha,
                                                   TexelGL::GL::Enum dfactorAlpha)
{
}

void
TexelGL::ContextInterfaceGL14::glMultiDrawArrays(TexelGL::GL::Enum mode,
                                                 int32_t const *first,
                                                 int32_t const *count,
                                                 int32_t drawcount)
{
}

void
TexelGL::ContextInterfaceGL14::glMultiDrawElements(TexelGL::GL::Enum mode,
                                                   int32_t const *count,
                                                   TexelGL::GL::Enum type,
                                                   void const * const *indices,
                                                   int32_t drawcount)
{
}

void
TexelGL::ContextInterfaceGL14::glPointParameterf(TexelGL::GL::Enum pname,
                                                 float param)
{
}

void
TexelGL::ContextInterfaceGL14::glPointParameterfv(TexelGL::GL::Enum pname,
                                                  float const *params)
{
}

void
TexelGL::ContextInterfaceGL14::glPointParameteri(TexelGL::GL::Enum pname,
                                                 int32_t param)
{
}

void
TexelGL::ContextInterfaceGL14::glPointParameteriv(TexelGL::GL::Enum pname,
                                                  int32_t *params)
{
}

void
TexelGL::ContextInterfaceGL15::glBindBuffer(TexelGL::GL::Enum target,
                                            uint32_t buffer)
{
    this->context.setBinding(target,
                             buffer);
}

void
TexelGL::ContextInterfaceGL15::glBufferData(TexelGL::GL::Enum target,
                                            intptr_t size,
                                            void const *data,
                                            TexelGL::GL::Enum usage)
{
    auto const buffer = std::dynamic_pointer_cast <Buffer> (this->context.getBinding(target));

    if (!buffer) {
        return;
    }

    buffer->allocateBytes(size);
}


void
TexelGL::ContextInterfaceGL15::glDeleteBuffers(int32_t n,
                                               uint32_t const *buffers)
{
    for (auto i = size_t(0);
         i < n;
         ++i) {
        this->context.deallocateObject(buffers[i]);
    }
}

void
TexelGL::ContextInterfaceGL15::glGenBuffers(int32_t n,
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

uint8_t
TexelGL::ContextInterfaceGL15::glIsBuffer(uint32_t buffer)
{
    return false;
}

uint8_t
TexelGL::ContextInterfaceGL15::glUnmapBuffer(TexelGL::GL::Enum target)
{
    auto const &context = this->context;
    auto const bufferPointer = std::dynamic_pointer_cast <Buffer> (context.getBinding(target));

    if (!bufferPointer) {
        return false;
    }

    auto &buffer = *bufferPointer;

    buffer.unmapBuffer();
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
    return this->context.allocateProgram();
}

uint32_t
TexelGL::ContextInterfaceGL20::glCreateShader(void)
{
    return this->context.allocateShader();
}

void
TexelGL::ContextInterfaceGL20::glDeleteProgram(uint32_t program)
{
    this->context.deallocateObject(program);
}

void
TexelGL::ContextInterfaceGL20::glDeleteShader(uint32_t shader)
{
    this->context.deallocateObject(shader);
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
TexelGL::ContextInterfaceGL20::glUseProgram(uint32_t program)
{
}

void
TexelGL::ContextInterfaceGL30::glBindBufferBase(TexelGL::GL::Enum target,
                                                uint32_t index,
                                                uint32_t buffer)
{
}

void
TexelGL::ContextInterfaceGL30::glBindBufferRange(TexelGL::GL::Enum target,
                                                 uint32_t index,
                                                 uint32_t buffer,
                                                 intptr_t offset,
                                                 intptr_t size)
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
    for (auto i = size_t(0);
         i < n;
         ++i) {
        this->context.deallocateObject(framebuffers[i]);
    }
}

void
TexelGL::ContextInterfaceGL30::glDeleteRenderbuffers(int32_t n,
                                                     uint32_t *renderbuffers)
{
    for (auto i = size_t(0);
         i < n;
         ++i) {
        this->context.deallocateObject(renderbuffers[i]);
    }
}

void
TexelGL::ContextInterfaceGL30::glDeleteVertexArrays(int32_t n,
                                                    uint32_t *arrays)
{
    for (auto i = size_t(0);
         i < n;
         ++i) {
        this->context.deallocateObject(arrays[i]);
    }
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
TexelGL::ContextInterfaceGL30::glGenerateMipmap(TexelGL::GL::Enum target)
{
}

void
TexelGL::ContextInterfaceGL30::glGenBuffers(int32_t n,
                                            uint32_t *buffers)
{
    for (auto i = size_t(0);
         i < n;
         ++i) {
        auto const id = this->context.allocateBuffer();

        buffers[i] = id;
    }
}

void
TexelGL::ContextInterfaceGL30::glGenFramebuffers(int32_t n,
                                                 uint32_t *framebuffers)
{
    for (auto i = size_t(0);
         i < n;
         ++i) {
        auto const id = this->context.allocateFramebuffer();

        framebuffers[i] = id;
    }
}

void
TexelGL::ContextInterfaceGL30::glGenRenderbuffers(int32_t n,
                                                  uint32_t *renderbuffers)
{
    for (auto i = size_t(0);
         i < n;
         ++i) {
        auto const id = this->context.allocateRenderbuffer();

        renderbuffers[i] = id;
    }
}

void
TexelGL::ContextInterfaceGL30::glGenVertexArrays(int32_t n,
                                                 uint32_t *arrays)
{
    for (auto i = size_t(0);
         i < n;
         ++i) {
        auto const id = this->context.allocateVertexArray();

        arrays[i] = id;
    }
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
        data = this->context.getMinorVersion();
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
                                                TexelGL::GL::MapAccessFlags access)
{
    auto const &context = this->context;
    auto const bufferPointer = std::dynamic_pointer_cast <Buffer> (context.getBinding(target));

    if (!bufferPointer) {
        return nullptr;
    }

    auto &buffer = *bufferPointer;
    auto const mapping = buffer.mapBuffer(offset,
                                          length,
                                          access);

    return mapping.data();
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

TexelGL::GL::Enum
TexelGL::ContextInterfaceGL32::glClientWaitSync(TexelGL::GL::Sync sync,
                                                uint32_t flags,
                                                uint64_t timeout)
{
    return TexelGL::GL::EnumInvalidOperation;
}

void
TexelGL::ContextInterfaceGL32::glDeleteSync(TexelGL::GL::Sync sync)
{
    this->context.deallocateObject(static_cast <uint32_t> (reinterpret_cast <uintptr_t> (sync)));
}

void
TexelGL::ContextInterfaceGL32::glDrawElementsBaseVertex(TexelGL::GL::Enum mode,
                                                        int32_t count,
                                                        TexelGL::GL::Enum type,
                                                        void const *indices,
                                                        int32_t basevertex)
{
}

void
TexelGL::ContextInterfaceGL32::glDrawElementsInstancedBaseVertex(TexelGL::GL::Enum mode,
                                                                 int32_t count,
                                                                 TexelGL::GL::Enum type,
                                                                 void const *indices,
                                                                 int32_t instancecount,
                                                                 int32_t basevertex)
{
}

void
TexelGL::ContextInterfaceGL32::glDrawRangeElementsBaseVertex(TexelGL::GL::Enum mode,
                                                             uint32_t start,
                                                             uint32_t end,
                                                             int32_t count,
                                                             TexelGL::GL::Enum type,
                                                             void const *indices,
                                                             int32_t basevertex)
{
}

TexelGL::GL::Sync
TexelGL::ContextInterfaceGL32::glFenceSync(TexelGL::GL::Enum condition,
                                           uint32_t flags)
{
    return reinterpret_cast <TexelGL::GL::Sync> (static_cast <uintptr_t> (this->context.allocateSync()));
}

void
TexelGL::ContextInterfaceGL32::glFramebufferTexture(TexelGL::GL::Enum target,
                                                    TexelGL::GL::Enum attachment,
                                                    uint32_t texture,
                                                    int32_t level)
{
}

void
TexelGL::ContextInterfaceGL32::glGetBufferParameteri64v(TexelGL::GL::Enum target,
                                                        TexelGL::GL::Enum pname,
                                                        int64_t *params)
{
}

void
TexelGL::ContextInterfaceGL32::glGetInteger64i_v(TexelGL::GL::Enum target,
                                                 uint32_t index,
                                                 int64_t *data)
{
}

void
TexelGL::ContextInterfaceGL32::glGetInteger64v(TexelGL::GL::Enum pname,
                                               int64_t *data)
{
}

void
TexelGL::ContextInterfaceGL32::glGetMultisamplefv(TexelGL::GL::Enum pname,
                                                  uint32_t index,
                                                  float *val)
{
}

void
TexelGL::ContextInterfaceGL32::glGetSynciv(TexelGL::GL::Sync sync,
                                           TexelGL::GL::Enum pname,
                                           int32_t count,
                                           int32_t *length,
                                           int32_t *values)
{
}

uint8_t
TexelGL::ContextInterfaceGL32::glIsSync(TexelGL::GL::Sync sync)
{
    return false;
}

void
TexelGL::ContextInterfaceGL32::glMultiDrawElementsBaseVertex(TexelGL::GL::Enum mode,
                                                             int32_t const *count,
                                                             TexelGL::GL::Enum type,
                                                             void const * const *indices,
                                                             int32_t drawcount,
                                                             int32_t const *basevertex)
{
}

void
TexelGL::ContextInterfaceGL32::glProvokingVertex(TexelGL::GL::Enum mode)
{
}

void
TexelGL::ContextInterfaceGL32::glTexImage2DMultisample(TexelGL::GL::Enum target,
                                                       int32_t samples,
                                                       TexelGL::GL::Enum internalformat,
                                                       int32_t width,
                                                       int32_t height,
                                                       uint8_t fixedsamplelocations)
{
}

void
TexelGL::ContextInterfaceGL32::glTexImage3DMultisample(TexelGL::GL::Enum target,
                        int32_t samples,
                        TexelGL::GL::Enum internalformat,
                        int32_t width,
                        int32_t height,
                        int32_t depth,
                        uint8_t fixedsamplelocations)
{
}

void
TexelGL::ContextInterfaceGL32::glSampleMaski(uint32_t maskNumber,
                                             uint32_t mask)
{
}

void
TexelGL::ContextInterfaceGL32::glWaitSync(TexelGL::GL::Sync sync,
                                          uint32_t flags,
                                          uint64_t timeout)
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
    for (auto i = size_t(0);
         i < n;
         ++i) {
        this->context.deallocateObject(samplers[i]);
    }
}

void
TexelGL::ContextInterfaceGL33::glGenSamplers(int32_t n,
                                             uint32_t *samplers)
{
    for (auto i = size_t(0);
         i < n;
         ++i) {
        auto const id = this->context.allocateSampler();

        samplers[i] = id;
    }
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

void
TexelGL::ContextInterfaceGL41::glShaderBinary(int32_t count,
                                              uint32_t const *shaders,
                                              TexelGL::GL::Enum binaryFormat,
                                              void const *binary,
                                              int32_t length)
{
}
void
TexelGL::ContextInterfaceGL44::glBindBuffersBase(TexelGL::GL::Enum target,
                                                 uint32_t first,
                                                 int32_t count,
                                                 uint32_t const *buffers)
{
}

void
TexelGL::ContextInterfaceGL44::glBindBuffersRange(TexelGL::GL::Enum target,
                                                  uint32_t first,
                                                  int32_t count,
                                                  uint32_t const *buffers,
                                                  intptr_t const *offsets,
                                                  intptr_t const *sizes)
{
}

void
TexelGL::ContextInterfaceGL45::glBindTextureUnit(uint32_t unit,
                                                 uint32_t texture)
{
}

void
TexelGL::ContextInterfaceGL45::glBlitNamedFramebuffer(uint32_t readFramebuffer,
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
}

TexelGL::GL::Enum
TexelGL::ContextInterfaceGL45::glCheckNamedFramebufferStatus(uint32_t framebuffer,
                                                             TexelGL::GL::Enum target)
{
    return TexelGL::GL::EnumFramebufferComplete;
}

void
TexelGL::ContextInterfaceGL45::glClearNamedFramebufferiv(uint32_t framebuffer,
                                                         TexelGL::GL::Enum buffer,
                                                         int32_t drawbuffer,
                                                         int32_t const *value)
{
}

void
TexelGL::ContextInterfaceGL45::glClearNamedFramebufferfi(uint32_t framebuffer,
                                                         TexelGL::GL::Enum buffer,
                                                         int32_t drawbuffer,
                                                         float depth,
                                                         int32_t stencil)
{
}

void
TexelGL::ContextInterfaceGL45::glClearNamedFramebufferfv(uint32_t framebuffer,
                                                         TexelGL::GL::Enum buffer,
                                                         int32_t drawbuffer,
                                                         float const *value)
{
}

void
TexelGL::ContextInterfaceGL45::glClearNamedFramebufferuiv(uint32_t framebuffer,
                                                          TexelGL::GL::Enum buffer,
                                                          int32_t drawbuffer,
                                                          uint32_t const *value)
{
}

void
TexelGL::ContextInterfaceGL45::glClearNamedBufferData(uint32_t buffer,
                                                      TexelGL::GL::Enum internalformat,
                                                      TexelGL::GL::Enum format,
                                                      TexelGL::GL::Enum type,
                                                      void const *data)
{
}

void
TexelGL::ContextInterfaceGL45::glClearNamedBufferSubData(uint32_t buffer,
                                                         TexelGL::GL::Enum internalformat,
                                                         intptr_t offset,
                                                         intptr_t size,
                                                         TexelGL::GL::Enum format,
                                                         TexelGL::GL::Enum type,
                                                         void const *data)
{
}

void
TexelGL::ContextInterfaceGL45::glClipControl(TexelGL::GL::Enum origin,
                                             TexelGL::GL::Enum depth)
{
}

void
TexelGL::ContextInterfaceGL45::glCompressedTextureSubImage1D(uint32_t texture,
                                                             int32_t level,
                                                             int32_t xoffset,
                                                             int32_t width,
                                                             TexelGL::GL::Enum format,
                                                             int32_t imageSize,
                                                             void const *data)
{
}

void
TexelGL::ContextInterfaceGL45::glCompressedTextureSubImage2D(uint32_t texture,
                                                             int32_t level,
                                                             int32_t xoffset,
                                                             int32_t yoffset,
                                                             int32_t width,
                                                             int32_t height,
                                                             TexelGL::GL::Enum format,
                                                             int32_t imageSize,
                                                             void const *data)
{
}

void
TexelGL::ContextInterfaceGL45::glCompressedTextureSubImage3D(uint32_t texture,
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
}

void
TexelGL::ContextInterfaceGL45::glCopyTextureSubImage1D(uint32_t texture,
                                                       int32_t level,
                                                       int32_t xoffset,
                                                       int32_t x,
                                                       int32_t y,
                                                       int32_t width)
{
}

void
TexelGL::ContextInterfaceGL45::glCopyTextureSubImage2D(uint32_t texture,
                                                       int32_t level,
                                                       int32_t xoffset,
                                                       int32_t yoffset,
                                                       int32_t x,
                                                       int32_t y,
                                                       int32_t width,
                                                       int32_t height)
{
}

void
TexelGL::ContextInterfaceGL45::glCopyTextureSubImage3D(uint32_t texture,
                                                       int32_t level,
                                                       int32_t xoffset,
                                                       int32_t yoffset,
                                                       int32_t zoffset,
                                                       int32_t x,
                                                       int32_t y,
                                                       int32_t width,
                                                       int32_t height)
{
}

void
TexelGL::ContextInterfaceGL45::glCopyNamedBufferSubData(uint32_t readBuffer,
                                                        uint32_t writeBuffer,
                                                        intptr_t readOffset,
                                                        intptr_t writeOffset,
                                                        intptr_t size)
{
}

void
TexelGL::ContextInterfaceGL45::glCreateBuffers(int32_t n,
                                               uint32_t *buffers)
{
    for (auto i = size_t(0);
         i < n;
         ++i) {
        auto const id = this->context.allocateBuffer();

        buffers[i] = id;
    }
}

void
TexelGL::ContextInterfaceGL45::glCreateFramebuffers(int32_t n,
                                                    uint32_t *framebuffers)
{
}

void
TexelGL::ContextInterfaceGL45::glCreateProgramPipelines(int32_t n,
                                                        uint32_t *pipelines)
{
}

void
TexelGL::ContextInterfaceGL45::glCreateQueries(TexelGL::GL::Enum target,
                                               int32_t n,
                                               uint32_t *ids)
{
}

void
TexelGL::ContextInterfaceGL45::glCreateRenderbuffers(int32_t n,
                                                     uint32_t *renderbuffers)
{
}

void
TexelGL::ContextInterfaceGL45::glCreateSamplers(int32_t n,
                                                uint32_t *samplers)
{
}

void
TexelGL::ContextInterfaceGL45::glCreateTextures(TexelGL::GL::Enum target,
                                                int32_t n,
                                                uint32_t *textures)
{
}

void
TexelGL::ContextInterfaceGL45::glCreateTransformFeedbacks(int32_t n,
                                                          uint32_t *ids)
{
}

void
TexelGL::ContextInterfaceGL45::glCreateVertexArrays(int32_t n,
                                                    uint32_t *arrays)
{
}

void
TexelGL::ContextInterfaceGL45::glDisableVertexArrayAttrib(uint32_t vaobj,
                           uint32_t index)
{
}

void
TexelGL::ContextInterfaceGL45::glEnableVertexArrayAttrib(uint32_t vaobj,
                          uint32_t index)
{
}

void
TexelGL::ContextInterfaceGL45::glFlushMappedNamedBufferRange(uint32_t buffer,
                              intptr_t offset,
                              intptr_t length)
{
}

void
TexelGL::ContextInterfaceGL45::glGenerateTextureMipmap(uint32_t texture)
{
}

void
TexelGL::ContextInterfaceGL45::glGetnCompressedTexImage(TexelGL::GL::Enum target,
                         int32_t lod,
                         int32_t bufSize,
                         void *pixels)
{
}

void
TexelGL::ContextInterfaceGL45::glGetnTexImage(TexelGL::GL::Enum target,
               int32_t level,
               TexelGL::GL::Enum format,
               TexelGL::GL::Enum type,
               int32_t bufSize,
               void *pixels)
{
}

void
TexelGL::ContextInterfaceGL45::glGetnUniformdv(uint32_t program,
                int32_t location,
                int32_t bufSize,
                double *params)
{
}

void
TexelGL::ContextInterfaceGL45::glGetnUniformfv(uint32_t program,
                int32_t location,
                int32_t bufSize,
                float *params)
{
}

void
TexelGL::ContextInterfaceGL45::glGetnUniformiv(uint32_t program,
                int32_t location,
                int32_t bufSize,
                int32_t *params)
{
}

void
TexelGL::ContextInterfaceGL45::glGetnUniformuiv(uint32_t program,
                 int32_t location,
                 int32_t bufSize,
                 uint32_t *params)
{
}

void
TexelGL::ContextInterfaceGL45::glGetCompressedTextureImage(uint32_t texture,
                            int32_t level,
                            int32_t bufSize,
                            void *pixels)
{
}

void
TexelGL::ContextInterfaceGL45::glGetCompressedTextureSubImage(uint32_t texture,
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
}

TexelGL::GL::Enum
TexelGL::ContextInterfaceGL45::glGetGraphicsResetStatus(void)
{
    return TexelGL::GL::EnumNoError;
}

void
TexelGL::ContextInterfaceGL45::glGetNamedBufferParameteriv(uint32_t buffer,
                                                           TexelGL::GL::Enum pname,
                                                           int32_t *params)
{
}

void
TexelGL::ContextInterfaceGL45::glGetNamedBufferParameteri64v(uint32_t buffer,
                                                             TexelGL::GL::Enum pname,
                                                             int64_t *params)
{
}

void
TexelGL::ContextInterfaceGL45::glGetNamedBufferPointerv(uint32_t buffer,
                                                        TexelGL::GL::Enum pname,
                                                        void **params)
{
}

void
TexelGL::ContextInterfaceGL45::glGetNamedBufferSubData(uint32_t buffer,
                                                       intptr_t offset,
                                                       intptr_t size,
                                                       void *data)
{
}

void
TexelGL::ContextInterfaceGL45::glGetNamedFramebufferAttachmentParameteriv(uint32_t framebuffer,
                                                                          TexelGL::GL::Enum attachment,
                                                                          TexelGL::GL::Enum pname,
                                                                          int32_t *params)
{
}

void
TexelGL::ContextInterfaceGL45::glGetNamedFramebufferParameteriv(uint32_t framebuffer,
                                                                TexelGL::GL::Enum pname,
                                                                int32_t *param)
{
}

void
TexelGL::ContextInterfaceGL45::glGetNamedRenderbufferParameteriv(uint32_t renderbuffer,
                                                                 TexelGL::GL::Enum pname,
                                                                 int32_t *params)
{
}

void
TexelGL::ContextInterfaceGL45::glGetQueryBufferObjecti64v(uint32_t id,
                                                          uint32_t buffer,
                                                          TexelGL::GL::Enum pname,
                                                          intptr_t offset)
{
}

void
TexelGL::ContextInterfaceGL45::glGetQueryBufferObjectiv(uint32_t id,
                                                        uint32_t buffer,
                                                        TexelGL::GL::Enum pname,
                                                        intptr_t offset)
{
}

void
TexelGL::ContextInterfaceGL45::glGetQueryBufferObjectui64v(uint32_t id,
                                                           uint32_t buffer,
                                                           TexelGL::GL::Enum pname,
                                                           intptr_t offset)
{
}

void
TexelGL::ContextInterfaceGL45::glGetQueryBufferObjectuiv(uint32_t id,
                                                         uint32_t buffer,
                                                         TexelGL::GL::Enum pname,
                                                         intptr_t offset)
{
}

void
TexelGL::ContextInterfaceGL45::glGetTextureImage(uint32_t texture,
                                                 int32_t level,
                                                 TexelGL::GL::Enum format,
                                                 TexelGL::GL::Enum type,
                                                 int32_t bufSize,
                                                 void *pixels)
{
}

void
TexelGL::ContextInterfaceGL45::glGetTextureLevelParameterfv(uint32_t texture,
                                                            int32_t level,
                                                            TexelGL::GL::Enum pname,
                                                            float *params)
{
}

void
TexelGL::ContextInterfaceGL45::glGetTextureLevelParameteriv(uint32_t texture,
                                                            int32_t level,
                                                            TexelGL::GL::Enum pname,
                                                            int32_t *params)
{
}

void
TexelGL::ContextInterfaceGL45::glGetTextureParameterfv(uint32_t texture,
                                                       TexelGL::GL::Enum pname,
                                                       float *params)
{
}

void
TexelGL::ContextInterfaceGL45::glGetTextureParameteriv(uint32_t texture,
                                                       TexelGL::GL::Enum pname,
                                                       int32_t *params)
{
}

void
TexelGL::ContextInterfaceGL45::glGetTextureParameterIiv(uint32_t texture,
                                                        TexelGL::GL::Enum pname,
                                                        int32_t *params)
{
}

void
TexelGL::ContextInterfaceGL45::glGetTextureParameterIuiv(uint32_t texture,
                                                         TexelGL::GL::Enum pname,
                                                         uint32_t *params)
{
}

void
TexelGL::ContextInterfaceGL45::glGetTextureSubImage(uint32_t texture,
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
}

void
TexelGL::ContextInterfaceGL45::glGetTransformFeedbacki_v(uint32_t xfb,
                                                         TexelGL::GL::Enum pname,
                                                         uint32_t index,
                                                         int32_t *param)
{
}

void
TexelGL::ContextInterfaceGL45::glGetTransformFeedbacki64_v(uint32_t xfb,
                                                           TexelGL::GL::Enum pname,
                                                           uint32_t index,
                                                           int64_t *param)
{
}

void
TexelGL::ContextInterfaceGL45::glGetTransformFeedbackiv(uint32_t xfb,
                                                        TexelGL::GL::Enum pname,
                                                        int32_t *param)
{
}

void
TexelGL::ContextInterfaceGL45::glGetVertexArrayiv(uint32_t vaobj,
                                                  TexelGL::GL::Enum pname,
                                                  int32_t *param)
{
}

void
TexelGL::ContextInterfaceGL45::glGetVertexArrayIndexediv(uint32_t vaobj,
                                                         uint32_t index,
                                                         TexelGL::GL::Enum pname,
                                                         int32_t *param)
{
}

void
TexelGL::ContextInterfaceGL45::glGetVertexArrayIndexed64iv(uint32_t vaobj,
                                                           uint32_t index,
                                                           TexelGL::GL::Enum pname,
                                                           int64_t *param)
{
}

void
TexelGL::ContextInterfaceGL45::glInvalidateNamedFramebufferData(uint32_t framebuffer,
                                                                int32_t numAttachments,
                                                                TexelGL::GL::Enum const *attachments)
{
}

void
TexelGL::ContextInterfaceGL45::glInvalidateNamedFramebufferSubData(uint32_t framebuffer,
                                                                   int32_t numAttachments,
                                                                   TexelGL::GL::Enum const *attachments,
                                                                   int32_t x,
                                                                   int32_t y,
                                                                   int32_t width,
                                                                   int32_t height)
{
}

void *
TexelGL::ContextInterfaceGL45::glMapNamedBuffer(uint32_t buffer,
                                                TexelGL::GL::Enum access)
{
    return nullptr;
}

void *
TexelGL::ContextInterfaceGL45::glMapNamedBufferRange(uint32_t buffer,
                                                     intptr_t offset,
                                                     intptr_t length,
                                                     TexelGL::GL::MapAccessFlags access)
{
    auto const &context = this->context;
    auto const bufferPointer = std::dynamic_pointer_cast <Buffer> (context.getObject(buffer));

    if (!bufferPointer) {
        return nullptr;
    }

    auto &bufferObject = *bufferPointer;
    auto const mapping = bufferObject.mapBuffer(offset,
                                                length,
                                                access);

    return mapping.data();
}

void
TexelGL::ContextInterfaceGL45::glMemoryBarrierByRegion(uint32_t barriers)
{
}

void
TexelGL::ContextInterfaceGL45::glNamedBufferData(uint32_t buffer,
                                                 intptr_t size,
                                                 void const *data,
                                                 TexelGL::GL::Enum usage)
{
}

void
TexelGL::ContextInterfaceGL45::glNamedBufferStorage(uint32_t buffer,
                                                    intptr_t size,
                                                    void const *data,
                                                    uint32_t flags)
{
    auto const bufferObject = std::dynamic_pointer_cast <Buffer> (this->context.getObject(buffer));

    if (!bufferObject) {
        return;
    }

    bufferObject->allocateBytes(size);
}

void
TexelGL::ContextInterfaceGL45::glNamedBufferSubData(uint32_t buffer,
                                                    intptr_t offset,
                                                    intptr_t size,
                                                    void const *data)
{
}

void
TexelGL::ContextInterfaceGL45::glNamedFramebufferDrawBuffer(uint32_t framebuffer,
                                                            TexelGL::GL::Enum buf)
{
}

void
TexelGL::ContextInterfaceGL45::glNamedFramebufferDrawBuffers(uint32_t framebuffer,
                                                             int32_t n,
                                                             TexelGL::GL::Enum const *bufs)
{
}

void
TexelGL::ContextInterfaceGL45::glNamedFramebufferParameteri(uint32_t framebuffer,
                                                            TexelGL::GL::Enum pname,
                                                            int32_t param)
{
}

void
TexelGL::ContextInterfaceGL45::glNamedFramebufferReadBuffer(uint32_t framebuffer,
                                                            TexelGL::GL::Enum src)
{
}

void
TexelGL::ContextInterfaceGL45::glNamedFramebufferRenderbuffer(uint32_t framebuffer,
                                                              TexelGL::GL::Enum attachment,
                                                              TexelGL::GL::Enum renderbuffertarget,
                                                              uint32_t renderbuffer)
{
}

void
TexelGL::ContextInterfaceGL45::glNamedFramebufferTexture(uint32_t framebuffer,
                                                         TexelGL::GL::Enum attachment,
                                                         uint32_t texture,
                                                         int32_t level)
{
}

void
TexelGL::ContextInterfaceGL45::glNamedFramebufferTextureLayer(uint32_t framebuffer,
                                                              TexelGL::GL::Enum attachment,
                                                              uint32_t texture,
                                                              int32_t level,
                                                              int32_t layer)
{
}

void
TexelGL::ContextInterfaceGL45::glReadnPixels(int32_t x,
                                             int32_t y,
                                             int32_t width,
                                             int32_t height,
                                             TexelGL::GL::Enum format,
                                             TexelGL::GL::Enum type,
                                             int32_t bufSize,
                                             void *data)
{
}

 void
TexelGL::ContextInterfaceGL45::glTextureBarrier(void)
{
}

void
TexelGL::ContextInterfaceGL45::glTextureBuffer(uint32_t texture,
                                               TexelGL::GL::Enum internalformat,
                                               uint32_t buffer)
{
}

void
TexelGL::ContextInterfaceGL45::glTextureBufferRange(uint32_t texture,
                                                    TexelGL::GL::Enum internalformat,
                                                    uint32_t buffer,
                                                    intptr_t offset,
                                                    intptr_t size)
{
}

void
TexelGL::ContextInterfaceGL45::glTextureParameterf(uint32_t texture,
                                                   TexelGL::GL::Enum pname,
                                                   float param)
{
}

void
TexelGL::ContextInterfaceGL45::glTextureParameterfv(uint32_t texture,
                                                    TexelGL::GL::Enum pname,
                                                    float const *param)
{
}

void
TexelGL::ContextInterfaceGL45::glTextureParameteri(uint32_t texture,
                                                   TexelGL::GL::Enum pname,
                                                   int32_t param)
{
}

void
TexelGL::ContextInterfaceGL45::glTextureParameteriv(uint32_t texture,
                                                    TexelGL::GL::Enum pname,
                                                    int32_t const *param)
{
}

void
TexelGL::ContextInterfaceGL45::glTextureParameterIiv(uint32_t texture,
                                                     TexelGL::GL::Enum pname,
                                                     int32_t const *params)
{
}

void
TexelGL::ContextInterfaceGL45::glTextureParameterIuiv(uint32_t texture,
                                                      TexelGL::GL::Enum pname,
                                                      uint32_t const *params)
{
}

void
TexelGL::ContextInterfaceGL45::glTextureStorage1D(uint32_t texture,
                                                  int32_t levels,
                                                  TexelGL::GL::Enum internalformat,
                                                  int32_t width)
{
}

void
TexelGL::ContextInterfaceGL45::glTextureStorage2D(uint32_t texture,
                                                  int32_t levels,
                                                  TexelGL::GL::Enum internalformat,
                                                  int32_t width,
                                                  int32_t height)
{
}

void
TexelGL::ContextInterfaceGL45::glTextureStorage2DMultisample(uint32_t texture,
                                                             int32_t samples,
                                                             TexelGL::GL::Enum internalformat,
                                                             int32_t width,
                                                             int32_t height,
                                                             uint8_t fixedsamplelocations)
{
}

void
TexelGL::ContextInterfaceGL45::glTextureStorage3D(uint32_t texture,
                                                  int32_t levels,
                                                  TexelGL::GL::Enum internalformat,
                                                  int32_t width,
                                                  int32_t height,
                                                  int32_t depth)
{
}

void
TexelGL::ContextInterfaceGL45::glTextureStorage3DMultisample(uint32_t texture,
                                                             int32_t samples,
                                                             TexelGL::GL::Enum internalformat,
                                                             int32_t width,
                                                             int32_t height,
                                                             int32_t depth,
                                                             uint8_t fixedsamplelocations)
{
}

void
TexelGL::ContextInterfaceGL45::glTextureSubImage1D(uint32_t texture,
                                                   int32_t level,
                                                   int32_t xoffset,
                                                   int32_t width,
                                                   TexelGL::GL::Enum format,
                                                   TexelGL::GL::Enum type,
                                                   void const *pixels)
{
}

void
TexelGL::ContextInterfaceGL45::glTextureSubImage2D(uint32_t texture,
                                                   int32_t level,
                                                   int32_t xoffset,
                                                   int32_t yoffset,
                                                   int32_t width,
                                                   int32_t height,
                                                   TexelGL::GL::Enum format,
                                                   TexelGL::GL::Enum type,
                                                   void const *pixels)
{
}

void
TexelGL::ContextInterfaceGL45::glTextureSubImage3D(uint32_t texture,
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
}

void
TexelGL::ContextInterfaceGL45::glTransformFeedbackBufferBase(uint32_t xfb,
                                                             uint32_t index,
                                                             uint32_t buffer)
{
}

void
TexelGL::ContextInterfaceGL45::glTransformFeedbackBufferRange(uint32_t xfb,
                                                              uint32_t index,
                                                              uint32_t buffer,
                                                              intptr_t offset,
                                                              intptr_t size)
{
}

void
TexelGL::ContextInterfaceGL45::glVertexArrayAttribBinding(uint32_t vaobj,
                                                          uint32_t attribindex,
                                                          uint32_t bindingindex)
{
}

void
TexelGL::ContextInterfaceGL45::glVertexArrayAttribFormat(uint32_t vaobj,
                                                         uint32_t attribindex,
                                                         int32_t size,
                                                         TexelGL::GL::Enum type,
                                                         uint8_t normalized,
                                                         uint32_t relativeoffset)
{
}

void
TexelGL::ContextInterfaceGL45::glVertexArrayAttribIFormat(uint32_t vaobj,
                                                          uint32_t attribindex,
                                                          int32_t size,
                                                          TexelGL::GL::Enum type,
                                                          uint32_t relativeoffset)
{
}

void
TexelGL::ContextInterfaceGL45::glVertexArrayAttribLFormat(uint32_t vaobj,
                                                          uint32_t attribindex,
                                                          int32_t size,
                                                          TexelGL::GL::Enum type,
                                                          uint32_t relativeoffset)
{
}

void
TexelGL::ContextInterfaceGL45::glVertexArrayBindingDivisor(uint32_t vaobj,
                                                           uint32_t bindingindex,
                                                           uint32_t divisor)
{
}

void
TexelGL::ContextInterfaceGL45::glVertexArrayElementBuffer(uint32_t vaobj,
                                                          uint32_t buffer)
{
}

void
TexelGL::ContextInterfaceGL45::glVertexArrayVertexBuffer(uint32_t vaobj,
                                                         uint32_t bindingindex,
                                                         uint32_t buffer,
                                                         intptr_t offset,
                                                         int32_t stride)
{
}

void
TexelGL::ContextInterfaceGL45::glVertexArrayVertexBuffers(uint32_t vaobj,
                                                          uint32_t first,
                                                          int32_t count,
                                                          uint32_t const *buffers,
                                                          intptr_t const *offsets,
                                                          int32_t const *strides)
{
}

uint8_t
TexelGL::ContextInterfaceGL45::glUnmapNamedBuffer(uint32_t buffer)
{
    auto const &context = this->context;
    auto const bufferPointer = std::dynamic_pointer_cast <Buffer> (context.getObject(buffer));

    if (!bufferPointer) {
        return false;
    }

    auto &bufferObject = *bufferPointer;

    bufferObject.unmapBuffer();
    return true;
}

void
TexelGL::ContextInterfaceGL46::glSpecializeShader(uint32_t shader,
                                                  char const *pEntryPoint,
                                                  uint32_t numSpecializationConstants,
                                                  uint32_t const *pConstantIndex,
                                                  uint32_t const *pConstantValue)
{
}