#pragma once

#include "Sampler.h"
#include "VulkanInterface.h"

namespace TexelGL {
namespace Vulkan {
    class Sampler: public TexelGL::Sampler {

    public:
        Sampler(void);

        virtual ~Sampler(void);
    };
} // namespace Vulkan
} // TexelGL