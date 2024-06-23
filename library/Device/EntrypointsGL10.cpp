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