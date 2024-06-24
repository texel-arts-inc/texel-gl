#pragma once

#include <string>
#include <vector>
#include "ContextInterfaces.h"

namespace TexelGL {
    class Context {
    private:
        struct ImmutableState {
            struct Version {
                uint32_t major = 0;
                uint32_t minor = 0;
            };

            using Extensions = std::vector <std::string>;

            Version version = {};
            std::string renderer = "";
            std::string vendor = "";
            Extensions extensions = {};
        };

    private:
        ImmutableState const immutableState = {};

    public:
        ContextInterfaceGL10 gl10;
        ContextInterfaceGL11 gl11;
        ContextInterfaceGL15 gl15;
        ContextInterfaceGL20 gl20;
        ContextInterfaceGL30 gl30;
        ContextInterfaceGL31 gl31;
        ContextInterfaceGL33 gl33;
        ContextInterfaceGL41 gl41;

    public:
        Context(void);
        virtual ~Context(void);

        Context &
        operator = (Context const &other);

        bool
        copyTo(Context &context) const;

        ImmutableState::Extensions const &
        getExtensions(void) const;

        uint32_t
        getMajorVersion(void) const;

        uint32_t
        getMinorVersion(void) const;

        std::string const &
        getRenderer(void) const;

        std::string const &
        getVendor(void) const;

        bool
        shareLists(Context &context) const;
    };
} // namespace TexelGL