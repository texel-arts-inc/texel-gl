#include <cassert>
#include <algorithm>
#include "Shader.h"

std::optional <TexelGL::GL::ShaderBinaryFormat>
TexelGL::Shader::mapToShaderBinaryFormat(TexelGL::GL::Enum format)
{
    switch (format) {
    case TexelGL::GL::EnumShaderBinaryFormatSpirV:
        return TexelGL::GL::ShaderBinaryFormatSpirV;

    default:
        assert(false &&
               "Unsupported shader binary format.");
        return std::nullopt;
    }
}

std::optional <TexelGL::GL::ShaderType>
TexelGL::Shader::mapToShaderType(TexelGL::GL::Enum format)
{
    switch (format) {
    case TexelGL::GL::EnumComputeShader:
        return TexelGL::GL::ShaderTypeCompute;

    case TexelGL::GL::EnumFragmentShader:
        return TexelGL::GL::ShaderTypeFragment;

    case TexelGL::GL::EnumGeometryShader:
        return TexelGL::GL::ShaderTypeGeometry;

    case TexelGL::GL::EnumVertexShader:
        return TexelGL::GL::ShaderTypeVertex;

    default:
        assert(false &&
               "Unsupported shader type.");
        return std::nullopt;
    }
}

TexelGL::Shader::Shader(std::shared_ptr <ShaderCompiler> const &shaderCompiler,
                        TexelGL::GL::ShaderType shaderType) :
    shaderType(shaderType),
    shaderCompiler(shaderCompiler)
{
}

TexelGL::Shader::~Shader(void)
{
}

void
TexelGL::Shader::compileShader(std::string const &entryPoint,
                               std::vector <std::pair <uint32_t,
                                                       uint32_t>> const &specializationConstants)
{
    if (this->state.compiled) {
        return;
    }

    if (this->state.shaderData.empty()) {
        return;
    }

    this->compile(entryPoint,
                  specializationConstants);
    this->state.compiled = true;
}

void
TexelGL::Shader::setShaderBinary(TexelGL::GL::ShaderBinaryFormat format,
                                 std::span <uint8_t const> const &binaryData)
{
    this->state.binaryFormat = format;
    this->state.shaderData = std::vector <uint8_t> (binaryData.begin(),
                                                    binaryData.end());
}