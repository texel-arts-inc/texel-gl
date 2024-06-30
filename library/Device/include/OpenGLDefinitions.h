#pragma once

#include <cstdint>

namespace TexelGL {
namespace GL {
    enum Enum: uint32_t {
        EnumArrayBuffer = 0x8892,
        EnumCompileStatus = 0x8b81,
        EnumElementArrayBuffer = 0x8893,
        EnumFramebufferComplete = 0x8cd5,
        EnumInvalidOperation = 0x0502,
        EnumLinkStatus = 0x8b82,
        EnumMapFlushExplicitBit = 0x0010,
        EnumMapInvalidateBufferBit = 0x0008,
        EnumMapInvalidateRangeBit = 0x0004,
        EnumMapReadBit = 0x0001,
        EnumMapUnsynchronizedBit = 0x0020,
        EnumMapWriteBit = 0x0002,
        EnumMajorVersion = 0x821b,
        EnumMinorVersion = 0x821c,
        EnumNoError = 0,
        EnumNumExtensions = 0x821d,
        EnumRenderer = 0x1f01,
        EnumUniformBuffer = 0x8a11,
        EnumVendor = 0x1f00,
        EnumValidateStatus = 0x8b83,
    };

    union MapAccessFlags {
        struct {
            uint32_t readBit: 1;
            uint32_t writeBit: 1;
            uint32_t invalidateRangeBit: 1;
            uint32_t invalidateBufferBit: 1;
            uint32_t flushExplicitBit: 1;
            uint32_t unsynchronizedBit: 1;
            uint32_t reserved: 26;
        };

        uint32_t value = 0;
    };

    using Sync = void const *;
} // namespace GL
} // namespace TexelGL