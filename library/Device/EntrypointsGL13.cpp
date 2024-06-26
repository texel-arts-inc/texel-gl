#include <cassert>
#include "Context.h"
#include "Device.h"
#include "EntrypointsGL13.h"

void
glActiveTexture(TexelGL::GL::Enum texture)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl13.glActiveTexture(texture);
}