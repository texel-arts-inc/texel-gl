#pragma once

#include "WGLDevice.h"
#include "VulkanDevice.h"

namespace TexelWGL {
namespace Vulkan {
    class Device : public TexelWGL::Device,
                   public TexelGL::Vulkan::Device {
    public:
        static Device currentDevice;

    private:
        Device(void);

    public:
        virtual ~Device(void);

        virtual TexelWGL::Context::Handle
        createContextHandle(Context::Descriptor const &descriptor) override;
    };
} // namespace Vulkan
} // namespace TexelGL