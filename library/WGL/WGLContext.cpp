#include "WGLContext.h"

TexelWGL::Context::Context(Descriptor const &descriptor,
                           Handle handle,
                           std::string const &deviceName,
                           std::shared_ptr <TexelGL::ShaderCompiler> const &shaderCompiler) :
    TexelGL::Context(deviceName,
                     shaderCompiler),
    descriptor(descriptor),
    handle(handle)
{
}

TexelWGL::Context::~Context(void)
{
}

TexelWGL::Context::Descriptor const &
TexelWGL::Context::getDescriptor(void) const
{
    return this->descriptor;
}

TexelWGL::Context::Handle
TexelWGL::Context::getHandle(void) const
{
    return this->handle;
}