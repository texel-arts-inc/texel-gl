#pragma once

#include <vulkan/vulkan.hpp>
#include "Object.h"

namespace TexelGL {
namespace Vulkan {
    class Image: public TexelGL::Object {
    private:
        vk::Image object = nullptr;

    public:
        Image(vk::Image object);

        virtual ~Image(void);

        operator vk::Image const &() const;
    };
} // namespace Vulkan
} // TexelGL