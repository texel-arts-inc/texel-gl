#pragma once

#include "Object.h"
#include "OpenGLDefinitions.h"

namespace TexelGL {
class Framebuffer: public Object {
public:
    Framebuffer(void);

    virtual ~Framebuffer(void);
};
} // namespace TexelGL