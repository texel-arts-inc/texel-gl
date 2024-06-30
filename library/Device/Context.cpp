#include <cassert>
#include "Buffer.h"
#include "Context.h"
#include "Framebuffer.h"
#include "Program.h"
#include "Renderbuffer.h"
#include "Sampler.h"
#include "Shader.h"
#include "Sync.h"
#include "Texture.h"
#include "VertexArray.h"

TexelGL::Context::Context(std::string const &deviceName) :
    immutableState(Context::ImmutableState {
        .version = Context::ImmutableState::Version {
            .major = 4,
            .minor = 6,
        },
        .renderer = deviceName,
    }),
    gl10(*this),
    gl11(*this),
    gl12(*this),
    gl13(*this),
    gl14(*this),
    gl15(*this),
    gl20(*this),
    gl21(*this),
    gl22(*this),
    gl30(*this),
    gl31(*this),
    gl32(*this),
    gl33(*this),
    gl40(*this),
    gl41(*this),
    gl42(*this),
    gl43(*this),
    gl44(*this),
    gl45(*this),
    gl46(*this)
{
    static auto constexpr maxUniformBuffers = 16;

    this->bindingState.uniformBuffers.resize(maxUniformBuffers);
}

TexelGL::Context::~Context(void)
{
    this->objectTable.reset();
}

TexelGL::Context &
TexelGL::Context::operator = (Context const &other)
{
    auto &immutableState = const_cast <ImmutableState &> (this->immutableState);

    immutableState = other.immutableState;
    return *this;
}

uint32_t
TexelGL::Context::allocateBuffer(void)
{
    auto const object = this->createBuffer();
    auto const id = this->objectTable.allocateObject(object);

    return id;
}

uint32_t
TexelGL::Context::allocateFramebuffer(void)
{
    auto const object = this->createFramebuffer();
    auto const id = this->objectTable.allocateObject(object);

    return id;
}

uint32_t
TexelGL::Context::allocateProgram(void)
{
    auto const object = this->createProgram();
    auto const id = this->objectTable.allocateObject(object);

    return id;
}

uint32_t
TexelGL::Context::allocateRenderbuffer(void)
{
    auto const object = this->createRenderbuffer();
    auto const id = this->objectTable.allocateObject(object);

    return id;
}

uint32_t
TexelGL::Context::allocateSampler(void)
{
    auto const object = this->createSampler();
    auto const id = this->objectTable.allocateObject(object);

    return id;
}

uint32_t
TexelGL::Context::allocateShader(TexelGL::GL::ShaderType shaderType)
{
    auto const object = this->createShader(shaderType);
    auto const id = this->objectTable.allocateObject(object);

    return id;
}

uint32_t
TexelGL::Context::allocateSync(void)
{
    auto const object = this->createSync();
    auto const id = this->objectTable.allocateObject(object);

    return id;
}

uint32_t
TexelGL::Context::allocateTexture(void)
{
    auto const object = this->createTexture();
    auto const id = this->objectTable.allocateObject(object);

    return id;
}

uint32_t
TexelGL::Context::allocateVertexArray(void)
{
    auto const object = this->createVertexArray();
    auto const id = this->objectTable.allocateObject(object);

    return id;
}

bool
TexelGL::Context::copyTo(Context &context) const
{
    context = *this;
    return true;
}

void
TexelGL::Context::deallocateObject(uint32_t id)
{
    this->objectTable.deallocateObject(id);
}

std::shared_ptr <TexelGL::Object>
TexelGL::Context::getBinding(GL::Enum target) const
{
    auto const &bindingState = this->bindingState;

    switch (target) {
    case TexelGL::GL::EnumArrayBuffer:
        return this->objectTable.getObject(bindingState.arrayBuffer);

    case TexelGL::GL::EnumElementArrayBuffer:
        return this->objectTable.getObject(bindingState.elementArrayBuffer);

    case TexelGL::GL::EnumUniformBuffer:
        return this->objectTable.getObject(bindingState.uniformBuffers.front());

    default:
        return nullptr;
    }
}

std::shared_ptr <TexelGL::Object>
TexelGL::Context::getBinding(GL::Enum target,
                             size_t index) const
{
    auto const &bindingState = this->bindingState;

    switch (target) {
    case TexelGL::GL::EnumUniformBuffer:
        if (index >=
            bindingState.uniformBuffers.size()) {
            return nullptr;
        }

        return this->objectTable.getObject(bindingState.uniformBuffers[index]);

    default:
        return nullptr;
    }
}

TexelGL::Context::ImmutableState::Extensions const &
TexelGL::Context::getExtensions(void) const
{
    return this->immutableState.extensions;
}

uint32_t
TexelGL::Context::getMajorVersion(void) const
{
    return this->immutableState.version.major;
}

uint32_t
TexelGL::Context::getMinorVersion(void) const
{
    return this->immutableState.version.minor;
}

std::shared_ptr <TexelGL::Object>
TexelGL::Context::getObject(uint32_t id) const
{
    return this->objectTable.getObject(id);
}

std::string const &
TexelGL::Context::getRenderer(void) const
{
    return this->immutableState.renderer;
}

std::string const &
TexelGL::Context::getVendor(void) const
{
    return this->immutableState.vendor;
}

void
TexelGL::Context::setBinding(GL::Enum target,
                             uint32_t id)
{
    auto &bindingState = this->bindingState;

    switch (target) {
    case TexelGL::GL::EnumArrayBuffer:
        bindingState.arrayBuffer = id;
        break;

    case TexelGL::GL::EnumElementArrayBuffer:
        bindingState.elementArrayBuffer = id;
        break;

    case TexelGL::GL::EnumUniformBuffer:
        bindingState.uniformBuffers.front() = id;
        break;

    default:
        break;
    }
}

bool
TexelGL::Context::shareLists(Context &context) const
{
    return true;
}