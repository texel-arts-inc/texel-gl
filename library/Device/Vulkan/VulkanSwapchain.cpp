#include "VulkanImage.h"
#include "VulkanImageView.h"
#include "VulkanSwapchain.h"

TexelGL::Vulkan::Swapchain::Swapchain(vk::raii::Device const &device,
                                      vk::raii::SwapchainKHR &&object,
                                      vk::Format format) :
    object(std::move(object))
{
    auto const &swapchain = this->object;
    auto const &images = swapchain.getImages();
    auto vulkanImageViews = std::vector <std::shared_ptr <ImageView>> ();

    for (auto &image: images) {
        auto const imageViewCreateInformation = vk::ImageViewCreateInfo({},
                                                                        image,
                                                                        vk::ImageViewType::e2D,
                                                                        format,
                                                                        {},
                                                                        { vk::ImageAspectFlagBits::eColor,
                                                                          0,
                                                                          1,
                                                                          0,
                                                                          1 });
        auto imageView = device.createImageView(imageViewCreateInformation);

        vulkanImageViews.push_back(std::make_shared <ImageView> (std::move(imageView)));
    }

    this->imageViews = vulkanImageViews;
}

TexelGL::Vulkan::Swapchain::~Swapchain(void)
{
}

TexelGL::Vulkan::Swapchain::operator vk::SwapchainKHR() const
{
    return this->object;
}

std::vector <std::shared_ptr <TexelGL::Vulkan::ImageView>> const &
TexelGL::Vulkan::Swapchain::getImageViews(void) const
{
    return this->imageViews;
}