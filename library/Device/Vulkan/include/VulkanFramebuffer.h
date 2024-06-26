#pragma once

#include "Object.h"
#include "VulkanInterface.h"

namespace TexelGL {
namespace Vulkan {
    class Framebuffer: public TexelGL::Object {
    private:
        vk::raii::Framebuffer object = nullptr;

    public:
        Framebuffer(vk::raii::Framebuffer &&object);

        virtual ~Framebuffer(void);

        operator vk::Framebuffer() const;
    };
} // namespace Vulkan
} // TexelGL