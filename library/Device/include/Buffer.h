#pragma once

#include "Object.h"

namespace TexelGL {
class Buffer: public Object {
public:
    Buffer(void);

    virtual ~Buffer(void);

    virtual void
    allocateBytes(size_t bytes) = 0;
};
} // namespace TexelGL