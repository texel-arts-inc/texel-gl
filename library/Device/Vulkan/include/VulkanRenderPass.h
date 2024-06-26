#pragma once

#include "Object.h"
#include "VulkanInterface.h"

namespace TexelGL {
namespace Vulkan {
    class RenderPass: public TexelGL::Object {
    private:
        vk::raii::RenderPass object = nullptr;

    public:
        RenderPass(vk::raii::RenderPass &&object);

        virtual ~RenderPass(void);

        operator vk::RenderPass() const;
    };
} // namespace Vulkan
} // TexelGL