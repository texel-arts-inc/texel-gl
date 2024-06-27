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
        static thread_local std::shared_ptr <Context> currentContext;

    protected:
        std::vector <std::shared_ptr <Context>> contexts = {};
        std::string extensionsString = "";

    public:
        static Device &
        getCurrentDevice(void);

    protected:
        Device(void) = default;

        Device(std::vector <std::string> const &extensionsNames);

        virtual ~Device(void);

        void
        deleteContext(std::shared_ptr <Context> const &context);

        std::shared_ptr <Context>
        getCurrentContext(void) const;

        void
        setCurrentContext(std::shared_ptr <Context> const &context);

    public:
        virtual std::string const &
        getExtensionsString(void) const;

        virtual void *
        getProcedureAddress(std::string const &name) const;
    };
} // namespace TexelGL