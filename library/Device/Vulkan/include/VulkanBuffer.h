#pragma once

#include <vk_mem_alloc.h>
#include <vulkan/vulkan.hpp>
#include "Buffer.h"

namespace TexelGL {
namespace Vulkan {
    class Buffer: public TexelGL::Buffer {
    private:
        VmaAllocator memoryAllocator = nullptr;
        VkBuffer object = nullptr;
        VmaAllocation memoryAllocation = nullptr;

    private:
        void
        deallocateBufferAndAllocation(void);

    public:
        Buffer(VmaAllocator const &memoryAllocator);

        virtual ~Buffer(void);

        virtual void
        allocateBytes(size_t bytes) override;

        virtual std::span <uint8_t>
        mapBuffer(intptr_t offset,
                  intptr_t length,
                  TexelGL::GL::MapAccessFlags access) override;

        virtual void
        unmapBuffer(void) override;
    };
} // namespace Vulkan
} // TexelGL