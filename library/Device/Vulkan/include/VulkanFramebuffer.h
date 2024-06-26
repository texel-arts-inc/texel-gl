#pragma once

#include "Framebuffer.h"
#include "VulkanInterface.h"

namespace TexelGL {
namespace Vulkan {
    class Framebuffer: public TexelGL::Framebuffer {
    private:
        vk::raii::Framebuffer object = nullptr;

    public:
        Framebuffer(void) = default;

        Framebuffer(vk::raii::Framebuffer &&object);

        virtual ~Framebuffer(void);

        operator vk::Framebuffer() const;
    };
} // namespace Vulkan
} // TexelGL