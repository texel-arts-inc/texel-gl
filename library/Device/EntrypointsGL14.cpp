#include <cassert>
#include "Context.h"
#include "Device.h"
#include "EntrypointsGL14.h"

void
glBlendColor(float red,
             float green,
             float blue,
             float alpha)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl14.glBlendColor(red,
                              green,
                              blue,
                              alpha);
}

void
glBlendEquation(TexelGL::GL::Enum mode)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl14.glBlendEquation(mode);
}

void
glBlendFuncSeparate(TexelGL::GL::Enum sfactorRGB,
                    TexelGL::GL::Enum dfactorRGB,
                    TexelGL::GL::Enum sfactorAlpha,
                    TexelGL::GL::Enum dfactorAlpha)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl14.glBlendFuncSeparate(sfactorRGB,
                                     dfactorRGB,
                                     sfactorAlpha,
                                     dfactorAlpha);
}

void
glMultiDrawArrays(TexelGL::GL::Enum mode,
                  int32_t const *first,
                  int32_t const *count,
                  int32_t drawcount)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl14.glMultiDrawArrays(mode,
                                   first,
                                   count,
                                   drawcount);
}

void
glMultiDrawElements(TexelGL::GL::Enum mode,
                    int32_t const *count,
                    TexelGL::GL::Enum type,
                    void const * const *indices,
                    int32_t drawcount)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl14.glMultiDrawElements(mode,
                                     count,
                                     type,
                                     indices,
                                     drawcount);
}

void
glPointParameterf(TexelGL::GL::Enum pname,
                 float param)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl14.glPointParameterf(pname,
                                   param);
}

void
glPointParameterfv(TexelGL::GL::Enum pname,
                   float const *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl14.glPointParameterfv(pname,
                                    params);
}

void
glPointParameteri(TexelGL::GL::Enum pname,
                  int32_t param)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl14.glPointParameteri(pname,
                                   param);
}

void
glPointParameteriv(TexelGL::GL::Enum pname,
                   int32_t *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl14.glPointParameteriv(pname,
                                    params);
}