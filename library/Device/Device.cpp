#include <map>
#include "Device.h"
#include "EntrypointsGL10.h"
#include "EntrypointsGL11.h"
#include "EntrypointsGL15.h"
#include "EntrypointsGL20.h"
#include "EntrypointsGL30.h"
#include "EntrypointsGL31.h"
#include "EntrypointsGL33.h"
#include "EntrypointsGL41.h"
#include "EntrypointsGL45.h"
#include "EntrypointsGL46.h"

thread_local std::shared_ptr <TexelGL::Context> TexelGL::Device::currentContext = nullptr;

TexelGL::Device::Device(std::vector <std::string> const &extensionsNames)
{
    for (auto const &extensionName: extensionsNames) {
        this->extensionsString += extensionName +
                                  " ";
    }
}

TexelGL::Device::~Device(void)
{
}

void
TexelGL::Device::deleteContext(std::shared_ptr <Context> const &context)
{
    auto const contextIterator = std::find(this->contexts.cbegin(),
                                           this->contexts.cend(),
                                           context);

    if (contextIterator == this->contexts.cend()) {
        return;
    }

    auto const contextIndex = contextIterator -
                              this->contexts.cbegin();

    this->contexts[contextIndex].reset();
}

std::shared_ptr <TexelGL::Context>
TexelGL::Device::getCurrentContext(void) const
{
    return this->currentContext;
}

std::string const &
TexelGL::Device::getExtensionsString(void) const
{
    return this->extensionsString;
}

void *
TexelGL::Device::getProcedureAddress(std::string const &name) const
{
    static auto const mappings = std::map <std::string,
                                           void *> {
        { "glAttachShader", reinterpret_cast <void *> (glAttachShader) },
        { "glBindAttribLocation", reinterpret_cast <void *> (glBindAttribLocation) },
        { "glBindBuffer", reinterpret_cast <void *> (glBindBuffer) },
        { "glBindFramebuffer", reinterpret_cast <void *> (glBindFramebuffer) },
        { "glBindRenderbuffer", reinterpret_cast <void *> (glBindRenderbuffer) },
        { "glBindSampler", reinterpret_cast <void *> (glBindSampler) },
        { "glBindTexture", reinterpret_cast <void *> (glBindTexture) },
        { "glBindVertexArray ",reinterpret_cast <void *> ( glBindVertexArray) },
        { "glBlitFramebuffer", reinterpret_cast <void *> (glBlitFramebuffer) },
        { "glBufferData", reinterpret_cast <void *> (glBufferData) },
        { "glClear", reinterpret_cast <void *> (glClear) },
        { "glClearColor", reinterpret_cast <void *> (glClearColor) },
        { "glClearDepth", reinterpret_cast <void *> (glClearDepth) },
        { "glClearDepthf", reinterpret_cast <void *> (glClearDepthf) },
        { "glCompileShader", reinterpret_cast <void *> (glCompileShader) },
        { "glCreateBuffers", reinterpret_cast <void *> (glCreateBuffers) },
        { "glCreateFramebuffers", reinterpret_cast <void *> (glCreateFramebuffers) },
        { "glCreateRenderbuffers", reinterpret_cast <void *> (glCreateRenderbuffers) },
        { "glCreateProgram", reinterpret_cast <void *> (glCreateProgram) },
        { "glCreateSamplers", reinterpret_cast <void *> (glCreateSamplers) },
        { "glCreateShader", reinterpret_cast <void *> (glCreateShader) },
        { "glCreateVertexArrays", reinterpret_cast <void *> (glCreateVertexArrays) },
        { "glDeleteFramebuffers ",reinterpret_cast <void *> ( glDeleteFramebuffers) },
        { "glDeleteRenderbuffers ",reinterpret_cast <void *> ( glDeleteRenderbuffers) },
        { "glDeleteProgram", reinterpret_cast <void *> (glDeleteProgram) },
        { "glDeleteSamplers", reinterpret_cast <void *> (glDeleteSamplers) },
        { "glDeleteShader", reinterpret_cast <void *> (glDeleteShader) },
        { "glDeleteTextures ",reinterpret_cast <void *> ( glDeleteTextures) },
        { "glDeleteVertexArrays ",reinterpret_cast <void *> ( glDeleteVertexArrays) },
        { "glDetachShader", reinterpret_cast <void *> (glDetachShader) },
        { "glDisbleVertexAttribArray", reinterpret_cast <void *> (glDisableVertexAttribArray) },
        { "glDrawBuffers", reinterpret_cast <void *> (glDrawBuffers) },
        { "glEnableVertexAttribArray", reinterpret_cast <void *> (glEnableVertexAttribArray) },
        { "glFinish", reinterpret_cast <void *> (glFinish) },
        { "glFlush", reinterpret_cast <void *> (glFlush) },
        { "glFlushMappedBufferRange", reinterpret_cast <void *> (glFlushMappedBufferRange) },
        { "glFramebufferRenderbuffer", reinterpret_cast <void *> (glFramebufferRenderbuffer) },
        { "glFramebufferTexture2D", reinterpret_cast <void *> (glFramebufferTexture2D) },
        { "glGenBuffers", reinterpret_cast <void *> (glGenBuffers) },
        { "glGenFramebuffers", reinterpret_cast <void *> (glGenFramebuffers) },
        { "glGenRenderbuffers", reinterpret_cast <void *> (glGenRenderbuffers) },
        { "glGenSamplers", reinterpret_cast <void *> (glGenSamplers) },
        { "glGenTextures", reinterpret_cast <void *> (glGenTextures) },
        { "glGenVertexArrays", reinterpret_cast <void *> (glGenVertexArrays) },
        { "glGetActiveUniformBlockiv", reinterpret_cast <void *> (glGetActiveUniformBlockiv) },
        { "glGetError", reinterpret_cast <void *> (glGetError) },
        { "glGetFloatv", reinterpret_cast <void *> (glGetFloatv) },
        { "glGetIntegeri_v", reinterpret_cast <void *> (glGetIntegeri_v) },
        { "glGetIntegerv", reinterpret_cast <void *> (glGetIntegerv) },
        { "glGetShaderiv", reinterpret_cast <void *> (glGetShaderiv) },
        { "glGetString", reinterpret_cast <void *> (glGetString) },
        { "glGetProgramiv", reinterpret_cast <void *> (glGetProgramiv) },
        { "glGetUniformBlockIndex", reinterpret_cast <void *> (glGetUniformBlockIndex) },
        { "glGetUniformLocation", reinterpret_cast <void *> (glGetUniformLocation) },
        { "glLinkProgram", reinterpret_cast <void *> (glLinkProgram) },
        { "glMapBufferRange", reinterpret_cast <void *> (glMapBufferRange) },
        { "glRenderbufferStorage", reinterpret_cast <void *> (glRenderbufferStorage) },
        { "glSamplerParameterf", reinterpret_cast <void *> (glSamplerParameterf) },
        { "glSamplerParameterfv", reinterpret_cast <void *> (glSamplerParameterfv) },
        { "glSamplerParameteri", reinterpret_cast <void *> (glSamplerParameteri) },
        { "glSamplerParameteriv", reinterpret_cast <void *> (glSamplerParameteriv) },
        { "glShaderSource", reinterpret_cast <void *> (glShaderSource) },
        { "glTexImage2D", reinterpret_cast <void *> (glTexImage2D) },
        { "glTexParameterf", reinterpret_cast <void *> (glTexParameterf) },
        { "glTexParameteri", reinterpret_cast <void *> (glTexParameteri) },
        { "glTexSubImage2D", reinterpret_cast <void *> (glTexSubImage2D) },
        { "glUniform1i", reinterpret_cast <void *> (glUniform1i) },
        { "glUniformBlockBinding", reinterpret_cast <void *> (glUniformBlockBinding) },
        { "glUnmapBuffer", reinterpret_cast <void *> (glUnmapBuffer) },
        { "glViewport", reinterpret_cast <void *> (glViewport) },
    };

    if (!mappings.contains(name)) {
        return nullptr;
    }

    return mappings.at(name);
}

void
TexelGL::Device::setCurrentContext(std::shared_ptr <Context> const &context)
{
    TexelGL::Device::currentContext = context;
}