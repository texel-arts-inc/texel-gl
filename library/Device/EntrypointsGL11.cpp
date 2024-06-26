#include <cassert>
#include "Context.h"
#include "Device.h"
#include "EntrypointsGL11.h"

void
glBindTexture(TexelGL::GL::Enum target,
              uint32_t texture)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl11.glBindTexture(target,
                               texture);
}

void
glCopyTexImage1D(TexelGL::GL::Enum target,
                 int32_t level,
                 int32_t internalformat,
                 int32_t x,
                 int32_t y,
                 int32_t width,
                 int32_t border)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl11.glCopyTexImage1D(target,
                                  level,
                                  internalformat,
                                  x,
                                  y,
                                  width,
                                  border);
}

void
glCopyTexImage2D(TexelGL::GL::Enum target,
                 int32_t level,
                 int32_t internalformat,
                 int32_t x,
                 int32_t y,
                 int32_t width,
                 int32_t height,
                 int32_t border)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl11.glCopyTexImage2D(target,
                                  level,
                                  internalformat,
                                  x,
                                  y,
                                  width,
                                  height,
                                  border);
}

void
glCopyTexSubImage1D(TexelGL::GL::Enum target,
                    int32_t level,
                    int32_t xOffset,
                    int32_t x,
                    int32_t y,
                    int32_t width)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl11.glCopyTexSubImage1D(target,
                                     level,
                                     xOffset,
                                     x,
                                     y,
                                     width);
}

void
glCopyTexSubImage2D(TexelGL::GL::Enum target,
                    int32_t level,
                    int32_t xOffset,
                    int32_t yOffset,
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

    context.gl11.glCopyTexSubImage2D(target,
                                     level,
                                     xOffset,
                                     yOffset,
                                     x,
                                     y,
                                     width,
                                     height);
}

void
glDeleteTextures(int32_t n,
                 uint32_t const *textures)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl11.glDeleteTextures(n,
                                  textures);
}

void
glDrawArrays(TexelGL::GL::Enum mode,
             int32_t first,
             int32_t count)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl11.glDrawArrays(mode,
                              first,
                              count);
}

void
glDrawElements(TexelGL::GL::Enum mode,
               int32_t count,
               TexelGL::GL::Enum type,
               void const *indices)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl11.glDrawElements(mode,
                                count,
                                type,
                                indices);
}

void
glGenTextures(int32_t n,
              uint32_t *textures)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl11.glGenTextures(n,
                               textures);
}

void
glGetPointerv(TexelGL::GL::Enum pname,
              void **params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl11.glGetPointerv(pname,
                               params);
}

uint8_t
glIsTexture(uint32_t texture)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return false;
    }

    auto &context = *contextPointer;

    return context.gl11.glIsTexture(texture);
}

void
glPolygonOffset(float factor,
                float units)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl11.glPolygonOffset(factor,
                                 units);
}

void
glTexSubImage1D(TexelGL::GL::Enum target,
                int32_t level,
                int32_t xOffset,
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

    context.gl11.glTexSubImage1D(target,
                                 level,
                                 xOffset,
                                 width,
                                 format,
                                 type,
                                 pixels);
}

void
glTexSubImage2D(TexelGL::GL::Enum target,
                int32_t level,
                int32_t xOffset,
                int32_t yOffset,
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

    context.gl11.glTexSubImage2D(target,
                                 level,
                                 xOffset,
                                 yOffset,
                                 width,
                                 height,
                                 format,
                                 type,
                                 pixels);
}