#pragma once

#include <memory>
#include <string>
#include <vector>
#include "ContextInterfaces.h"
#include "ObjectTable.h"

namespace TexelGL {
    class Buffer;
    class Framebuffer;
    class Program;
    class Renderbuffer;
    class Sampler;
    class Shader;
    class Sync;
    class Texture;
    class VertexArray;

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
        ContextInterfaceGL12 gl12;
        ContextInterfaceGL13 gl13;
        ContextInterfaceGL14 gl14;
        ContextInterfaceGL15 gl15;
        ContextInterfaceGL20 gl20;
        ContextInterfaceGL21 gl21;
        ContextInterfaceGL22 gl22;
        ContextInterfaceGL30 gl30;
        ContextInterfaceGL31 gl31;
        ContextInterfaceGL32 gl32;
        ContextInterfaceGL33 gl33;
        ContextInterfaceGL40 gl40;
        ContextInterfaceGL41 gl41;
        ContextInterfaceGL42 gl42;
        ContextInterfaceGL43 gl43;
        ContextInterfaceGL44 gl44;
        ContextInterfaceGL45 gl45;
        ContextInterfaceGL46 gl46;

    protected:
        virtual std::shared_ptr <Buffer>
        createBuffer(void) = 0;

        virtual std::shared_ptr <Framebuffer>
        createFramebuffer(void) = 0;

        virtual std::shared_ptr <Program>
        createProgram(void) = 0;

        virtual std::shared_ptr <Renderbuffer>
        createRenderbuffer(void) = 0;

        virtual std::shared_ptr <Sampler>
        createSampler(void) = 0;

        virtual std::shared_ptr <Shader>
        createShader(void) = 0;

        virtual std::shared_ptr <Sync>
        createSync(void) = 0;

        virtual std::shared_ptr <Texture>
        createTexture(void) = 0;

        virtual std::shared_ptr <VertexArray>
        createVertexArray(void) = 0;

    public:
        Context(std::string const &deviceName);

        virtual ~Context(void);

        Context &
        operator = (Context const &other);

        uint32_t
        allocateBuffer(void);

        uint32_t
        allocateFramebuffer(void);

        uint32_t
        allocateProgram(void);

        uint32_t
        allocateRenderbuffer(void);

        uint32_t
        allocateSampler(void);

        uint32_t
        allocateShader(void);

        uint32_t
        allocateSync(void);

        uint32_t
        allocateTexture(void);

        uint32_t
        allocateVertexArray(void);

        bool
        copyTo(Context &context) const;

        void
        deallocateObject(uint32_t id);

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

        std::shared_ptr <Object>
        getObject(uint32_t id) const;

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