#pragma once

#include "Program.h"
#include "VulkanInterface.h"

namespace TexelGL {
namespace Vulkan {
    class Program: public TexelGL::Program {

    public:
        Program(void);

        virtual ~Program(void);
    };
} // namespace Vulkan
} // TexelGL