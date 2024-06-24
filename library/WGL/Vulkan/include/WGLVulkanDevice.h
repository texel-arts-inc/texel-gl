#pragma once

#include "WGLDevice.h"
#include "VulkanDevice.h"

namespace TexelWGL {
namespace Vulkan {
    class Device: public TexelWGL::Device,
                  public TexelGL::Vulkan::Device {
    public:
        static Device currentDevice;

    private:
        Device(void);

        virtual std::shared_ptr <TexelWGL::Context>
        createContext(TexelWGL::Context::Descriptor const &descriptor,
                      TexelWGL::Context::Handle handle) const override;

    public:
        virtual ~Device(void);

        virtual bool
        swapBuffers(WGL::DeviceContext deviceContext) override;
    };
} // namespace Vulkan
} // namespace TexelGL