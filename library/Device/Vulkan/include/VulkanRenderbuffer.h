#pragma once

#include "Renderbuffer.h"
#include "VulkanInterface.h"

namespace TexelGL {
namespace Vulkan {
    class Renderbuffer: public TexelGL::Renderbuffer {

    public:
        Renderbuffer(void);

        virtual ~Renderbuffer(void);
    };
} // namespace Vulkan
} // TexelGL