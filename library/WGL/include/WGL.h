#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace WGL {
    struct PixelFormatDescriptor {
        enum Attribute {
            AttributeNumberPixelFormats = 0x2000,
            AttributeDrawToWindow = 0x2001,
            AttributeDrawToBitmap = 0x2002,
            AttributeAcceleration = 0x2003,
            AttributeNeedPalette = 0x2004,
            AttributeNeedSystemPalette = 0x2005,
            AttributeSwapLayerBuffers = 0x2006,
            AttributeSwapMethod = 0x2007,
            AttributeNumberOfOverlays = 0x2008,
            AttributeNumberOfUnderlays = 0x2009,
            AttributeTransparent = 0x200A,
            AttributeTransparentRedValue = 0x2037,
            AttributeTransparentGreenValue = 0x2038,
            AttributeTransparentBlueValue = 0x2039,
            AttributeTransparentAlphaValue = 0x203A,
            AttributeTTransparentIndexValue = 0x203B,
            AttributeShareDepth = 0x200C,
            AttributeShareStencil = 0x200D,
            AttributeShareAccumulator = 0x200E,
            AttributeSupportGDI = 0x200F,
            AttributeSupportOpenGL = 0x2010,
            AttributeDoubleBuffer = 0x2011,
            AttributeStereo = 0x2012,
            AttributePixelType = 0x2013,
            AttributeColorBits = 0x2014,
            AttributeRedBits = 0x2015,
            AttributeRedShift = 0x2016,
            AttributeGreenBits = 0x2017,
            AttributeGreenShift = 0x2018,
            AttributeBlueBits = 0x2019,
            AttributeBlueShift = 0x201A,
            AttributeAlphaBits = 0x201B,
            AttributeAlphaShift = 0x201C,
            AttributeAccumulatorBits = 0x201D,
            AttributeAccumulatorRedBits = 0x201E,
            AttributeAccumulatorGreenBits = 0x201F,
            AttributeAccumulatorBlueBits = 0x2020,
            AttributeAccumulatorAlphaBits = 0x2021,
            AttributeDepthBits = 0x2022,
            AttributeStencilBits = 0x2023,
            AttributeAuxilliaryBuffers = 0x2024,
            AttributeNoAcceleration = 0x2025,
            AttributeGenericAcceleration = 0x2026,
            AttributeFullAcceleration = 0x2027,
            AttributeSwapExchange = 0x2028,
            AttributeSwapCopy = 0x2029,
            AttributeSwapUndefined = 0x202A,
            AttributeTypeRGBA = 0x202B,
            AttributeTypeColorIndex = 0x202C,
        };
        enum LayerType: uint8_t {
            LayerTypeMainPlane = 0,
            LayerTypeOverlayPlane = 1,
            LayerTypeUnderlayPlane = 255,
        };

        static_assert(sizeof(LayerType) == sizeof(uint8_t));

        enum PixelType: uint8_t {
            PixelTypeRGBA = 0,
            PixelTypeColorIndex = 1,
        };

        static_assert(sizeof(PixelType) == sizeof(uint8_t));

        union Flags {
            struct {
                uint32_t doubleBuffer: 1;
                uint32_t stereo: 1;
                uint32_t drawToWindow: 1;
                uint32_t drawToBitmap: 1;
                uint32_t supportGDI: 1;
                uint32_t supportOpenGL: 1;
                uint32_t genericFormat: 2;
                uint32_t needPalette: 1;
                uint32_t needSystemPalette: 1;
                uint32_t reserved0: 2;
                uint32_t swapLayerBuffers: 1;
                uint32_t genericAccelerated: 1;
                uint32_t reserved1: 15;
                uint32_t depthDontCare: 1;
                uint32_t doubleBufferDontCare: 1;
                uint32_t stereoDontCare: 1;
            };

            uint32_t value = 0;
        };

        static_assert(sizeof(Flags) == sizeof(uint32_t));

        uint16_t size = sizeof(PixelFormatDescriptor);
        uint16_t version = 1;
        Flags flags = {};
        PixelType pixelType = PixelTypeRGBA;
        uint8_t colorBits = 0;
        uint8_t redBits = 0;
        uint8_t redShift = 0;
        uint8_t greenBits = 0;
        uint8_t greenShift = 0;
        uint8_t blueBits = 0;
        uint8_t blueShift = 0;
        uint8_t alphaBits = 0;
        uint8_t alphaShift = 0;
        uint8_t accumBits = 0;
        uint8_t accumRedBits = 0;
        uint8_t accumGreenBits = 0;
        uint8_t accumBlueBits = 0;
        uint8_t accumAlphaBits = 0;
        uint8_t depthBits = 0;
        uint8_t stencilBits = 0;
        uint8_t auxBuffers = 0;
        LayerType layerType = LayerTypeMainPlane;
        uint8_t reserved = 0;
        uint32_t layerMask = 0;
        uint32_t visibleMask = 0;
        uint32_t damageMask = 0;
    };

    using DeviceContext = void const *;
    using ResourceContext = void const *;
}

namespace TexelWGL {
    class Context {
    public:
        struct Descriptor {
            WGL::DeviceContext deviceContext = nullptr;
        };

        using Handle = uint16_t;

    private:
        Descriptor descriptor = {};
        Handle handle = 0;

    public:
        Context(Descriptor const &descriptor,
                Handle handle);

        Descriptor const &
        getDescriptor(void) const;

        Handle
        getHandle(void) const;
    };

    class Device {
    public:
        static Device currentDevice;
        static thread_local std::shared_ptr <Context> currentContext;

    private:
        std::vector <std::shared_ptr <Context>> contexts = {};
        std::string extensionsString = "";

    private:
        Device(void);

        static int16_t
        getContextIndex(TexelWGL::Context::Handle handle);

    public:
        TexelWGL::Context::Handle
        createContext(Context::Descriptor const &descriptor);

        void
        deleteContext(TexelWGL::Context::Handle handle);

        std::shared_ptr <Context>
        getContext(TexelWGL::Context::Handle handle) const;

        TexelWGL::Context::Handle
        getCurrentContext(void) const;

        std::string const &
        getExtensionsString(void) const;

        void
        setCurrentContext(TexelWGL::Context::Handle handle);
    };
}