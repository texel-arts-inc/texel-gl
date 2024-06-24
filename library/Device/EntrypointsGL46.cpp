#include <cassert>
#include "Context.h"
#include "Device.h"
#include "EntrypointsGL46.h"

void
glSpecializeShader(uint32_t shader,
                   char const *pEntryPoint,
                   uint32_t numSpecializationConstants,
                   uint32_t const *pConstantIndex,
                   uint32_t const *pConstantValue)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl46.glSpecializeShader(shader,
                                    pEntryPoint,
                                    numSpecializationConstants,
                                    pConstantIndex,
                                    pConstantValue);
}