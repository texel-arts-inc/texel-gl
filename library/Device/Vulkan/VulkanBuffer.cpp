#include "VulkanBuffer.h"

void
TexelGL::Vulkan::Buffer::deallocateBufferAndAllocation(void)
{
    if (!this->object) {
        return;
    }

    assert(this->memoryAllocation);

    vmaDestroyBuffer(this->memoryAllocator,
                        this->object,
                        this->memoryAllocation);
    this->object = nullptr;
    this->memoryAllocation = nullptr;
}

TexelGL::Vulkan::Buffer::Buffer(VmaAllocator const &memoryAllocator) :
    memoryAllocator(memoryAllocator)
{
}

TexelGL::Vulkan::Buffer::~Buffer(void)
{
    this->deallocateBufferAndAllocation();
}

void
TexelGL::Vulkan::Buffer::allocateBytes(size_t bytes)
{
    auto const bufferCreateInformation = VkBufferCreateInfo {
        .sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
        .size = bytes,
        .usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT |
                 VK_BUFFER_USAGE_TRANSFER_DST_BIT |
                 VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
    };

    auto const allocationCreateInformation = VmaAllocationCreateInfo {
        .flags = VMA_ALLOCATION_CREATE_HOST_ACCESS_RANDOM_BIT,
        .usage = VMA_MEMORY_USAGE_AUTO,
    };

    auto buffer = VkBuffer(nullptr);
    auto memoryAllocation = VmaAllocation(nullptr);

    if (vmaCreateBuffer(this->memoryAllocator,
                        &bufferCreateInformation,
                        &allocationCreateInformation,
                        &buffer,
                        &memoryAllocation,
                        nullptr) !=
        VK_SUCCESS) {
        assert(false);
        return;
    }

    this->deallocateBufferAndAllocation();
    this->object = buffer;
    this->memoryAllocation = memoryAllocation;
}

std::span <uint8_t>
TexelGL::Vulkan::Buffer::mapBuffer(intptr_t offset,
                                   intptr_t length,
                                   TexelGL::GL::MapAccessFlags access)
{
    auto data = static_cast <void *> (nullptr);

    if (vmaMapMemory(this->memoryAllocator,
                     this->memoryAllocation,
                     &data) !=
        VK_SUCCESS) {
        return {};
    }
    auto const start = static_cast <uint8_t *> (data) +
                       offset;
    auto const end = start +
                     length;
    auto mapping = std::span <uint8_t> (start,
                                        end);

    return mapping;
}

void
TexelGL::Vulkan::Buffer::unmapBuffer(void)
{
    vmaUnmapMemory(this->memoryAllocator,
                   this->memoryAllocation);
}