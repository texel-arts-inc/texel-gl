#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace TexelGL {
    class Context;
} // namespace TexelGL

namespace TexelGL {
    class Device {
    public:
        static Device currentDevice;
        static thread_local std::shared_ptr <Context> currentContext;

    protected:
        std::vector <std::shared_ptr <Context>> contexts = {};
        std::string extensionsString = "";

    protected:
        Device(void);
        virtual ~Device(void) = default;

        void
        deleteContext(std::shared_ptr <Context> const &context);

        std::shared_ptr <Context>
        getCurrentContext(void) const;

        void
        setCurrentContext(std::shared_ptr <Context> const &context);

    public:
        std::string const &
        getExtensionsString(void) const;
    };
} // namespace TexelGL