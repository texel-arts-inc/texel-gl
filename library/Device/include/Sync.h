#pragma once

#include "Object.h"
#include "OpenGLDefinitions.h"

namespace TexelGL {
class Sync: public Object {
public:
    Sync(void);

    virtual ~Sync(void);
};
} // namespace TexelGL