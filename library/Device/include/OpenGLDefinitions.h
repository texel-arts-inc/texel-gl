#pragma once

#include <cstdint>

namespace TexelGL {
namespace GL {
    enum Enum: uint32_t {
        EnumMajorVersion = 0x821b,
        EnumMinorVersion = 0x821c,
        EnumNoError = 0,
        EnumNumExtensions = 0x821d,
    };
} // namespace GL
} // namespace TexelGL