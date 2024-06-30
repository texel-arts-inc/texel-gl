#pragma once

#include "Object.h"
#include "VulkanInterface.h"

namespace TexelGL {
namespace Vulkan {
    class Semaphore: public TexelGL::Object {

    public:
        Semaphore(void);

        virtual ~Semaphore(void);
    };
} // namespace Vulkan
} // TexelGL