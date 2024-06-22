#pragma once

#include <memory>
#include <vector>
#include "Device.h"
#include "WGLContext.h"

namespace TexelWGL {
    class Device: public TexelGL::Device {
    private:
        Device(void);

        static int16_t
        getContextIndex(TexelWGL::Context::Handle handle);

    public:
        TexelWGL::Context::Handle
        createContextHandle(Context::Descriptor const &descriptor);

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