#pragma once

#include <memory>
#include <map>
#include "Object.h"
#include "OpenGLDefinitions.h"

namespace TexelGL {
class Shader;

class Program: public Object {
protected:
    std::map <TexelGL::GL::ShaderType,
              std::shared_ptr <Shader>> shaders = {};

public:
    Program(void);

    virtual ~Program(void);

    virtual void
    attachShader(std::shared_ptr <Shader> const &shader);

    virtual void
    detachShader(std::shared_ptr <Shader> const &shader);

    virtual void
    link(void) = 0;
};
} // namespace TexelGL