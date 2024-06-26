#pragma once

#include "VertexArray.h"
#include "VulkanInterface.h"

namespace TexelGL {
namespace Vulkan {
    class VertexArray: public TexelGL::VertexArray {

    public:
        VertexArray(void);

        virtual ~VertexArray(void);
    };
} // namespace Vulkan
} // TexelGL