#pragma once

#include <span>
#include "Object.h"
#include "OpenGLDefinitions.h"

namespace TexelGL {
class Buffer: public Object {
public:
    Buffer(void);

    virtual ~Buffer(void);

    virtual void
    allocateBytes(size_t bytes) = 0;

    virtual std::span <uint8_t>
    mapBuffer(intptr_t offset,
              intptr_t length,
              TexelGL::GL::MapAccessFlags access) = 0;

    virtual void
    unmapBuffer(void) = 0;
};
} // namespace TexelGL