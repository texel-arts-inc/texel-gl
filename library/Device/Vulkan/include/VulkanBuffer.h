#pragma once

#include <vulkan/vulkan.hpp>
#include "Buffer.h"

namespace TexelGL {
namespace Vulkan {
    class Buffer: public TexelGL::Buffer {
    private:
        vk::Buffer object = nullptr;

    public:
        Buffer(void);

        virtual ~Buffer(void);

        virtual void
        allocateBytes(size_t bytes) override;
    };
} // namespace Vulkan
} // TexelGL