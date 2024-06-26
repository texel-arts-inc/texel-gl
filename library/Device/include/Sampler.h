#pragma once

#include "Object.h"
#include "OpenGLDefinitions.h"

namespace TexelGL {
class Sampler: public Object {
public:
    Sampler(void);

    virtual ~Sampler(void);
};
} // namespace TexelGL