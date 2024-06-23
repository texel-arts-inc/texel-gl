#include <cassert>
#include "Context.h"
#include "Device.h"
#include "EntrypointsGL41.h"

void
glClearDepthf(float d)
{
    auto const &contextPointer = TexelGL::Device::currentContext;

    if (!contextPointer) {
        return;
    }

    auto &context = *contextPointer;

    context.gl41.glClearDepthf(d);
}