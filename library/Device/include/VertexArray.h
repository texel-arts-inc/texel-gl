#pragma once

#include "Object.h"
#include "OpenGLDefinitions.h"

namespace TexelGL {
class VertexArray: public Object {
public:
    VertexArray(void);

    virtual ~VertexArray(void);
};
} // namespace TexelGL