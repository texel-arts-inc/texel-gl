#include <cassert>
#include "Context.h"
#include "Device.h"
#include "EntrypointsGL20.h"

void
glAttachShader(uint32_t program,
               uint32_t shader)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl20.glAttachShader(program,
                                shader);
}

void
glBindAttribLocation(uint32_t program,
                     uint32_t index,
                     char const *name)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl20.glBindAttribLocation(program,
                                      index,
                                      name);
}

void
glCompileShader(uint32_t shader)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl20.glCompileShader(shader);
}

uint32_t
glCreateProgram(void)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return 0;
    }

    auto &context = *contextPointer;

    return context.gl20.glCreateProgram();
}

uint32_t
glCreateShader(void)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return 0;
    }

    auto &context = *contextPointer;

    return context.gl20.glCreateShader();
}

void
glDeleteProgram(uint32_t program)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl20.glDeleteProgram(program);
}

void
glDeleteShader(uint32_t shader)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl20.glDeleteShader(shader);
}

void
glDetachShader(uint32_t program,
               uint32_t shader)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl20.glDetachShader(program,
                                shader);
}

void
glDisableVertexAttribArray(uint32_t index)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl20.glDisableVertexAttribArray(index);
}

void
glDrawBuffers(int32_t n,
              TexelGL::GL::Enum const *bufs)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl20.glDrawBuffers(n,
                               bufs);
}

void
glEnableVertexAttribArray(uint32_t index)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl20.glEnableVertexAttribArray(index);
}

void
glGetShaderiv(uint32_t shader,
              TexelGL::GL::Enum name,
              int32_t *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl20.glGetShaderiv(shader,
                               name,
                               params);
}

void
glGetProgramiv(uint32_t program,
               TexelGL::GL::Enum name,
               int32_t *params)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl20.glGetProgramiv(program,
                                name,
                                params);
}

void
glGetUniformLocation(uint32_t program,
                     char const *name)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl20.glGetUniformLocation(program,
                                      name);
}

 void
glLinkProgram(uint32_t program)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl20.glLinkProgram(program);
}

void
glShaderSource(uint32_t shader,
               int32_t count,
               char const * const *string,
               int32_t const *length)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl20.glShaderSource(shader,
                                count,
                                string,
                                length);
}

void
glUniform1i(int32_t location,
            int32_t v0)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl20.glUniform1i(location,
                             v0);
}

void
glUseProgram(uint32_t program)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl20.glUseProgram(program);
}