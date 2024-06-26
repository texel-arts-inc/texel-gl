#pragma once

#include "Sync.h"
#include "VulkanInterface.h"

namespace TexelGL {
namespace Vulkan {
    class Sync: public TexelGL::Sync {

    public:
        Sync(void);

        virtual ~Sync(void);
    };
} // namespace Vulkan
} // TexelGL