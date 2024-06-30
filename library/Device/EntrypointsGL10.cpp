#include <cassert>
#include "Context.h"
#include "Device.h"
#include "EntrypointsGL10.h"

void
glClear(uint32_t mask)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glClear(mask);
}

void
glClearColor(float red,
             float green,
             float blue,
             float alpha)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glClearColor(red,
                              green,
                              blue,
                              alpha);
}

void
glClearDepth(double depth)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glClearDepth(depth);
}

void
glClearStencil(int32_t s)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glClearStencil(s);
}

void
glColorMask(uint8_t red,
            uint8_t green,
            uint8_t blue,
            uint8_t alpha)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glColorMask(red,
                             green,
                             blue,
                             alpha);
}

void
glCullFace(TexelGL::GL::Enum mode)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glCullFace(mode);
}

void
glDepthFunc(TexelGL::GL::Enum func)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glDepthFunc(func);
}

void
glDepthMask(uint8_t flag)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glDepthMask(flag);
}

void
glDisable(TexelGL::GL::Enum cap)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glDisable(cap);
}

void
glDrawBuffer(TexelGL::GL::Enum buf)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glDrawBuffer(buf);
}

void
glEnable(TexelGL::GL::Enum cap)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glEnable(cap);
}

void
glFinish(void)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glFinish();
}

void
glFlush(void)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glFlush();
}

void
glFrontFace(TexelGL::GL::Enum mode)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glFrontFace(mode);
}

TexelGL::GL::Enum
glGetError(void)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return TexelGL::GL::EnumCompileStatus;
    }

    auto &context = *contextPointer;

    return context.gl10.glGetError();
}

void
glGetFloatv(TexelGL::GL::Enum name,
            float &data)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glGetFloatv(name,
                             data);
}

uint8_t const *
glGetString(TexelGL::GL::Enum name)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return nullptr;
    }

    auto &context = *contextPointer;

    return context.gl10.glGetString(name);
}

void
glHint(TexelGL::GL::Enum target,
       TexelGL::GL::Enum mode)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    return context.gl10.glHint(target,
                               mode);
}

void
glLineWidth(float width)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    return context.gl10.glLineWidth(width);
}

void
glPointSize(float size)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    return context.gl10.glPointSize(size);
}

void
glPolygonMode(TexelGL::GL::Enum face,
              TexelGL::GL::Enum mode)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    return context.gl10.glPolygonMode(face,
                                      mode);
}

void
glReadBuffer(TexelGL::GL::Enum src)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glReadBuffer(src);
}

void
glStencilMask(uint32_t mask)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glStencilMask(mask);
}

void
glScissor(int32_t x,
          int32_t y,
          int32_t width,
          int32_t height)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glScissor(x,
                           y,
                           width,
                           height);
}

void
glTexImage1D(TexelGL::GL::Enum target,
             int32_t level,
             int32_t internalformat,
             int32_t width,
             int32_t border,
             TexelGL::GL::Enum format,
             TexelGL::GL::Enum type,
             void const *pixels)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glTexImage1D(target,
                              level,
                              internalformat,
                              width,
                              border,
                              format,
                              type,
                              pixels);
}

void
glTexImage2D(TexelGL::GL::Enum target,
             int32_t level,
             int32_t internalformat,
             int32_t width,
             int32_t height,
             int32_t border,
             TexelGL::GL::Enum format,
             TexelGL::GL::Enum type,
             void const *pixels)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glTexImage2D(target,
                              level,
                              internalformat,
                              width,
                              height,
                              border,
                              format,
                              type,
                              pixels);
}

void
glTexParameterf(TexelGL::GL::Enum target,
                TexelGL::GL::Enum pname,
                float param)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glTexParameterf(target,
                                 pname,
                                 param);
}

void
glTexParameterfv(TexelGL::GL::Enum target,
                 TexelGL::GL::Enum pname,
                 float const *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glTexParameterfv(target,
                                  pname,
                                  params);
}

void
glTexParameteri(TexelGL::GL::Enum target,
                TexelGL::GL::Enum pname,
                int32_t param)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glTexParameteri(target,
                                 pname,
                                 param);
}

void
glTexParameteriv(TexelGL::GL::Enum target,
                 TexelGL::GL::Enum pname,
                 int32_t const *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glTexParameteriv(target,
                                  pname,
                                  params);
}

void
glViewport(int32_t x,
           int32_t y,
           int32_t width,
           int32_t height)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl10.glViewport(x,
                            y,
                            width,
                            height);
}