#include "VulkanImageView.h"

TexelGL::Vulkan::ImageView::ImageView(vk::ImageView object) :
    object(object)
{
}

TexelGL::Vulkan::ImageView::~ImageView(void)
{
}

TexelGL::Vulkan::ImageView::operator vk::ImageView const &() const
{
    return this->object;
}