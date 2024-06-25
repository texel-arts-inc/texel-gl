#pragma once

#include <memory>
#include <string>
#include <vector>
#include "ContextInterfaces.h"
#include "ObjectTable.h"

namespace TexelGL {
    class Buffer;

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

        struct BindingState {
            uint32_t arrayBuffer = 0;
            uint32_t elementArrayBuffer = 0;
            std::vector <uint32_t> uniformBuffers = {};
        };

    protected:
        ImmutableState const immutableState = {};
        BindingState bindingState = {};
        ObjectTable objectTable = {};

    public:
        ContextInterfaceGL10 gl10;
        ContextInterfaceGL11 gl11;
        ContextInterfaceGL15 gl15;
        ContextInterfaceGL20 gl20;
        ContextInterfaceGL30 gl30;
        ContextInterfaceGL31 gl31;
        ContextInterfaceGL33 gl33;
        ContextInterfaceGL41 gl41;
        ContextInterfaceGL45 gl45;
        ContextInterfaceGL46 gl46;

    protected:
        virtual std::shared_ptr <Buffer>
        createBuffer(void) = 0;

    public:
        Context(std::string const &deviceName);

        virtual ~Context(void);

        Context &
        operator = (Context const &other);

        uint32_t
        allocateBuffer(void);

        bool
        copyTo(Context &context) const;

        void
        deallocateBuffer(uint32_t id);

        std::shared_ptr <Object>
        getBinding(GL::Enum target) const;

        std::shared_ptr <Object>
        getBinding(GL::Enum target,
                   size_t index) const;

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

        void
        setBinding(GL::Enum target,
                   uint32_t id);

        bool
        shareLists(Context &context) const;
    };
} // namespace TexelGL