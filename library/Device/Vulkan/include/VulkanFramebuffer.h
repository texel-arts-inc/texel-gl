#pragma once

#include <vulkan/vulkan.hpp>
#include "Object.h"

namespace TexelGL {
namespace Vulkan {
    class Framebuffer: public TexelGL::Object {
    private:
        vk::Framebuffer object = nullptr;

    public:
        Framebuffer(vk::Framebuffer object);

        virtual ~Framebuffer(void);

        operator vk::Framebuffer const &() const;
    };
} // namespace Vulkan
} // TexelGL