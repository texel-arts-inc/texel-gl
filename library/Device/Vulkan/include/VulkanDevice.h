#pragma once

#include <memory>
#include <vector>
#include "Device.h"

namespace TexelGL {
namespace Vulkan {
    class Device : public virtual TexelGL::Device {
    protected:
        Device(void);

    public:
        virtual ~Device(void);
    };
} // namespace Vulkan
} // namespace TexelGL