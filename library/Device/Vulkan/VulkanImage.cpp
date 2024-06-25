#include "VulkanImage.h"

TexelGL::Vulkan::Image::Image(vk::Image object) :
    object(object)
{
}

TexelGL::Vulkan::Image::~Image(void)
{
}

TexelGL::Vulkan::Image::operator vk::Image const &() const
{
    return this->object;
}