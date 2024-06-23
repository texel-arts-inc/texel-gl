#pragma once

#include <cstdint>

namespace TexelGL {
namespace GL {
    enum Enum: uint32_t {
        EnumCompileStatus = 0x8b81,
        EnumInvalidOperation = 0x0502,
        EnumLinkStatus = 0x8b82,
        EnumMajorVersion = 0x821b,
        EnumMinorVersion = 0x821c,
        EnumNoError = 0,
        EnumNumExtensions = 0x821d,
        EnumRenderer = 0x1f01,
        EnumVendor = 0x1f00,
        EnumValidateStatus = 0x8b83,
    };
} // namespace GL
} // namespace TexelGL