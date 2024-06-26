#pragma once

#include "Object.h"
#include "OpenGLDefinitions.h"

namespace TexelGL {
class Renderbuffer: public Object {
public:
    Renderbuffer(void);

    virtual ~Renderbuffer(void);
};
} // namespace TexelGL