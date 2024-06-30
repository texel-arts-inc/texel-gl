#pragma once

#include <span>
#include <vector>
#include "OpenGLDefinitions.h"

namespace TexelGL {
class ShaderCompiler {
public:
    ShaderCompiler(void);

    ~ShaderCompiler(void);

    std::vector <uint32_t>
    convertGLSpirVToVulkan(std::span <uint32_t const> const &glSpirVByteCode);
};
} // namespace TexelGL