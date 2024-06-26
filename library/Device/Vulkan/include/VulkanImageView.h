#pragma once

#include "Object.h"
#include "VulkanInterface.h"

namespace TexelGL {
namespace Vulkan {
    class ImageView: public TexelGL::Object {
    private:
        vk::raii::ImageView object = nullptr;

    public:
        ImageView(vk::raii::ImageView &&object);

        virtual ~ImageView(void);

        operator vk::ImageView() const;
    };
} // namespace Vulkan
} // TexelGL