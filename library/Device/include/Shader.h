#pragma once

#include "Object.h"
#include "OpenGLDefinitions.h"

namespace TexelGL {
class Shader: public Object {
public:
    Shader(void);

    virtual ~Shader(void);
};
} // namespace TexelGL