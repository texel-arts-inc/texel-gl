#include <cassert>
#include "Buffer.h"
#include "Context.h"

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
    gl15(*this),
    gl20(*this),
    gl30(*this),
    gl31(*this),
    gl33(*this),
    gl41(*this),
    gl45(*this),
    gl46(*this)
{
    static auto constexpr maxUniformBuffers = 16;

    this->bindingState.uniformBuffers.resize(maxUniformBuffers);
}

TexelGL::Context::~Context(void)
{
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

bool
TexelGL::Context::copyTo(Context &context) const
{
    context = *this;
    return true;
}

void
TexelGL::Context::deallocateBuffer(uint32_t id)
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