#pragma once

#include "Object.h"
#include "VulkanInterface.h"

namespace TexelGL {
namespace Vulkan {
    class Image;
    class ImageView;

    class Swapchain: public TexelGL::Object {
    private:
        vk::raii::SwapchainKHR object = nullptr;
        std::vector <std::shared_ptr <ImageView>> imageViews = {};

    public:
        Swapchain(vk::raii::Device const &device,
                  vk::raii::SwapchainKHR &&object,
                  vk::Format format);

        virtual ~Swapchain(void);

        operator vk::SwapchainKHR() const;

        std::vector <std::shared_ptr <ImageView>> const &
        getImageViews(void) const;
    };
} // namespace Vulkan
} // TexelGL