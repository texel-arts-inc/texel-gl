#include "Program.h"
#include "Shader.h"

TexelGL::Program::Program(void)
{
}

TexelGL::Program::~Program(void)
{
}

void
TexelGL::Program::attachShader(std::shared_ptr <Shader> const &shader)
{
    auto const shaderType = shader->getType();

    this->shaders[shaderType] = shader;
}

void
TexelGL::Program::detachShader(std::shared_ptr <Shader> const &shader)
{
    auto const shaderType = shader->getType();

    this->shaders.erase(shaderType);
}
