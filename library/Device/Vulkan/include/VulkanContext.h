#pragma once

#include "Context.h"

namespace TexelGL {
namespace Vulkan {
    class Context : public virtual TexelGL::Context {
    protected:
        Context(void);

    public:
        virtual ~Context(void);
    };
} // namespace Vulkan
} // namespace TexelGL