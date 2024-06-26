#include <cassert>
#include "Context.h"
#include "Device.h"
#include "EntrypointsGL12.h"

void
glCopyTexSubImage3D(TexelGL::GL::Enum target,
                    int32_t level,
                    int32_t xOffset,
                    int32_t yOffset,
                    int32_t zOffset,
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

    context.gl12.glCopyTexSubImage3D(target,
                                     level,
                                     xOffset,
                                     yOffset,
                                     zOffset,
                                     x,
                                     y,
                                     width,
                                     height);
}

void
glDrawRangeElements(TexelGL::GL::Enum mode,
                    uint32_t start,
                    uint32_t end,
                    int32_t count,
                    TexelGL::GL::Enum type,
                    void const *indices)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl12.glDrawRangeElements(mode,
                                     start,
                                     end,
                                     count,
                                     type,
                                     indices);
}

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
             void const *pixels)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl12.glTexImage3D(target,
                                 level,
                                 internalFormat,
                                 width,
                                 height,
                                 depth,
                                 border,
                                 format,
                                 type,
                                 pixels);
}

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
                void const *pixels)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl12.glTexSubImage3D(target,
                                 level,
                                 xOffset,
                                 yOffset,
                                 zOffset,
                                 width,
                                 height,
                                 depth,
                                 format,
                                 type,
                                 pixels);
}