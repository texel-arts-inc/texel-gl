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
glGenTextures(int32_t n,
              uint32_t const *textures)
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