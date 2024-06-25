#pragma once

#include <vulkan/vulkan.hpp>
#include "Object.h"

namespace TexelGL {
namespace Vulkan {
    class Swapchain: public TexelGL::Object {
    private:
        vk::SwapchainKHR object = nullptr;

    public:
        Swapchain(vk::SwapchainKHR object);

        virtual ~Swapchain(void);

        operator vk::SwapchainKHR const &() const;
    };
} // namespace Vulkan
} // TexelGL