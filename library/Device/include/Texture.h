#pragma once

#include "Object.h"
#include "OpenGLDefinitions.h"

namespace TexelGL {
class Texture: public Object {
public:
    Texture(void);

    virtual ~Texture(void);
};
} // namespace TexelGL