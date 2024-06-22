#pragma once

#include <cstdint>
#include "Context.h"
#include "WGL.h"

namespace TexelWGL {
    class Context: public TexelGL::Context {
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
        virtual ~Context(void);

        Descriptor const &
        getDescriptor(void) const;

        Handle
        getHandle(void) const;
    };
} // namespace TexelGL