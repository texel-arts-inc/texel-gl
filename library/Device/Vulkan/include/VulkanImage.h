#pragma once

#include "Object.h"
#include "VulkanInterface.h"

namespace TexelGL {
namespace Vulkan {
    class Image: public TexelGL::Object {
    private:
        vk::raii::Image object = nullptr;

    public:
        Image(vk::raii::Image &&object);

        virtual ~Image(void);

        operator vk::Image() const;
    };
} // namespace Vulkan
} // TexelGL