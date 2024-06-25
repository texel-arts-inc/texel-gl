#pragma once

#include <vulkan/vulkan.hpp>
#include "Object.h"

namespace TexelGL {
namespace Vulkan {
    class RenderPass: public TexelGL::Object {
    private:
        vk::RenderPass object = nullptr;

    public:
        RenderPass(vk::RenderPass object);

        virtual ~RenderPass(void);

        operator vk::RenderPass const &() const;
    };
} // namespace Vulkan
} // TexelGL