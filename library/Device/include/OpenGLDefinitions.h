#pragma once

#include <cstdint>

namespace TexelGL {
namespace GL {
    enum Enum: uint32_t {
        EnumArrayBuffer = 0x8892,
        EnumCompileStatus = 0x8b81,
        EnumComputeShader = 0x91b9,
        EnumElementArrayBuffer = 0x8893,
        EnumFragmentShader = 0x8b30,
        EnumFramebufferComplete = 0x8cd5,
        EnumGeometryShader = 0x8dd9,
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
        EnumShaderBinaryFormatSpirV = 0x9551,
        EnumSpirVBinary = 0x9552,
        EnumUniformBuffer = 0x8a11,
        EnumValidateStatus = 0x8b83,
        EnumVendor = 0x1f00,
        EnumVertexShader = 0x8b31,
    };

    enum ShaderBinaryFormat {
        ShaderBinaryFormatGLSL,
        ShaderBinaryFormatSpirV,
    };

    enum ShaderType {
        ShaderTypeCompute,
        ShaderTypeFragment,
        ShaderTypeGeometry,
        ShaderTypeVertex,
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