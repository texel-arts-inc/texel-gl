#pragma once

#include <optional>
#include <map>
#include <memory>
#include <span>
#include <string>
#include <vector>
#include "Object.h"
#include "OpenGLDefinitions.h"

namespace TexelGL {
class ShaderCompiler;

class Shader: public Object {
protected:
    struct State {
        bool compiled = false;
        TexelGL::GL::ShaderBinaryFormat binaryFormat = TexelGL::GL::ShaderBinaryFormatGLSL;
        std::vector <uint8_t> shaderData = {};
    };

protected:
    TexelGL::GL::ShaderType const shaderType;
    std::shared_ptr <ShaderCompiler> shaderCompiler;
    State state = {};

public:
    static std::optional <TexelGL::GL::ShaderBinaryFormat>
    mapToShaderBinaryFormat(TexelGL::GL::Enum format);

    static std::optional <TexelGL::GL::ShaderType>
    mapToShaderType(TexelGL::GL::Enum format);

protected:
    virtual void
    compile(std::string const &entryPoint,
            std::vector <std::pair <uint32_t,
                                    uint32_t>> const &specializationConstants) = 0;

public:
    Shader(std::shared_ptr <ShaderCompiler> const &shaderCompiler,
           TexelGL::GL::ShaderType shaderType);

    virtual ~Shader(void);

    void
    compileShader(std::string const &entryPoint,
                  std::vector <std::pair <uint32_t,
                                          uint32_t>> const &specializationConstants);

    void
    setShaderBinary(TexelGL::GL::ShaderBinaryFormat format,
                    std::span <uint8_t const> const &binaryData);
};
} // namespace TexelGL