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
        Device(void);

    public:
        virtual ~Device(void);

        virtual TexelWGL::Context::Handle
        createContextHandle(Context::Descriptor const &descriptor) = 0;

        void
        deleteContextHandle(TexelWGL::Context::Handle handle);

        std::shared_ptr <Context>
        getContext(TexelWGL::Context::Handle handle) const;

        TexelWGL::Context::Handle
        getCurrentContextHandle(void) const;

        void
        setCurrentContextHandle(TexelWGL::Context::Handle handle);
    };
} // namespace TexelGL