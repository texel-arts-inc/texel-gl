#include "VulkanImage.h"

TexelGL::Vulkan::Image::Image(vk::raii::Image &&object) :
    object(std::move(object))
{
}

TexelGL::Vulkan::Image::~Image(void)
{
}

TexelGL::Vulkan::Image::operator vk::Image() const
{
    return this->object;
}