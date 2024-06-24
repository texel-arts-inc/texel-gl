#pragma once

#include <memory>
#include <vector>
#include "Device.h"
#include "WGLContext.h"

namespace TexelWGL {
    class Device: public virtual TexelGL::Device {
    public:
        static Device &currentDevice;

    private:
        static int16_t
        getContextIndex(TexelWGL::Context::Handle handle);

    protected:
        static std::vector <std::string>
        getExtensionsNames(std::vector <std::string> const &backendExtensionNames);

    protected:
        Device(void) = default;

        Device(std::vector <std::string> const &backendExtentionNames);

        virtual std::shared_ptr <TexelWGL::Context>
        createContext(Context::Descriptor const &descriptor,
                      Context::Handle handle) const = 0;

    public:
        virtual ~Device(void);

        TexelWGL::Context::Handle
        createContextHandle(Context::Descriptor const &descriptor);

        void
        deleteContextHandle(TexelWGL::Context::Handle handle);

        bool
        describePixelFormat(WGL::DeviceContext deviceContext,
                            int32_t pixelFormat,
                            uint32_t numBytes,
                            WGL::PixelFormatDescriptor &pixelFormatDescriptor);

        std::shared_ptr <Context>
        getContext(TexelWGL::Context::Handle handle) const;

        TexelWGL::Context::Handle
        getCurrentContextHandle(void) const;

        int32_t
        getPixelFormat(WGL::DeviceContext hdc) const;

        virtual void *
        getProcedureAddress(std::string const &name) const override;

        void
        setCurrentContextHandle(TexelWGL::Context::Handle handle);

        bool
        setPixelFormat(WGL::DeviceContext deviceContext,
                       int32_t pixelFormat,
                       WGL::PixelFormatDescriptor &pixelFormatDescriptor);

        bool
        swapBuffers(WGL::DeviceContext deviceContext);

        bool
        swapLayerBuffers(WGL::DeviceContext deviceContext,
                         int32_t layer);
    };
} // namespace TexelGL