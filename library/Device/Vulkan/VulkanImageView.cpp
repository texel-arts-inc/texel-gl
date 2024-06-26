#include "VulkanImageView.h"

TexelGL::Vulkan::ImageView::ImageView(vk::raii::ImageView &&object) :
    object(std::move(object))
{
}

TexelGL::Vulkan::ImageView::~ImageView(void)
{
}

TexelGL::Vulkan::ImageView::operator vk::ImageView() const
{
    return this->object;
}