#pragma once

#include <vulkan/vulkan.hpp>
#include "Object.h"

namespace TexelGL {
namespace Vulkan {
    class ImageView: public TexelGL::Object {
    private:
        vk::ImageView object = nullptr;

    public:
        ImageView(vk::ImageView object);

        virtual ~ImageView(void);

        operator vk::ImageView const &() const;
    };
} // namespace Vulkan
} // TexelGL