#pragma once

#include "Object.h"
#include "OpenGLDefinitions.h"

namespace TexelGL {
class Program: public Object {
public:
    Program(void);

    virtual ~Program(void);
};
} // namespace TexelGL