#include <optional>
#include <spirv_reflect.hpp>
#include <glslang/Public/ResourceLimits.h>
#include <glslang/Public/ShaderLang.h>
#include <glslang/SPIRV/GlslangToSpv.h>
#include <spirv_cross/spirv_glsl.hpp>
#include "ShaderCompiler.h"

static std::optional <EShLanguage>
mapShaderTypeToEShLanguage(TexelGL::GL::ShaderType shaderType)
{
    switch (shaderType) {
    case TexelGL::GL::ShaderTypeCompute:
        return EShLangCompute;

    case TexelGL::GL::ShaderTypeFragment:
        return EShLangFragment;

    case TexelGL::GL::ShaderTypeGeometry:
        return EShLangGeometry;

    case TexelGL::GL::ShaderTypeVertex:
        return EShLangVertex;

    default:
        assert(false &&
               "Unsupported shader type.");
        break;
    }

    return std::nullopt;
}

TexelGL::ShaderCompiler::ShaderCompiler(void)
{
    glslang::InitializeProcess();
}

TexelGL::ShaderCompiler::~ShaderCompiler(void)
{
    glslang::FinalizeProcess();
}

std::vector <uint32_t>
TexelGL::ShaderCompiler::convertGLSpirVToVulkan(TexelGL::GL::ShaderType shaderType,
                                                std::span <uint32_t const> const &glSpirVByteCode)
{
    auto const optionalLanguage = mapShaderTypeToEShLanguage(shaderType);

    if (!optionalLanguage) {
        return {};
    }

    auto vulkanSpirVByteCode = std::vector <uint32_t> ();
    auto compiler = spirv_cross::CompilerGLSL(glSpirVByteCode.data(),
                                              glSpirVByteCode.size());
    auto options = compiler.get_common_options();

    options.es = false;
    options.version = 460;
    options.enable_420pack_extension = false;
    compiler.set_common_options(options);

    auto source = compiler.compile();
    auto const language = *optionalLanguage;
    auto shader = glslang::TShader(language);
    auto const sourceString = source.c_str();

    shader.setEnvTarget(glslang::EShTargetLanguage::EShTargetSpv,
                        glslang::EShTargetLanguageVersion::EShTargetSpv_1_6);
    shader.setStrings(&sourceString,
                      1);
    shader.setAutoMapBindings(false);
    shader.setAutoMapLocations(true);
    shader.setEnvClient(glslang::EShClientVulkan,
                        glslang::EShTargetVulkan_1_1);

    auto const defaultResources = GetDefaultResources();
    auto const defaultGLSLVersion = 460;
    auto const forwardCompatible = true;
    auto messages = EShMessages();

    if (!shader.parse(defaultResources,
                      defaultGLSLVersion,
                      forwardCompatible,
                      messages)) {
        auto const error = shader.getInfoLog();

        return {};
    }

    auto program = glslang::TProgram();

    program.addShader(&shader);
    messages = EShMessages();

    if (!program.link(messages)) {
        auto const error = program.getInfoLog();

        return {};
    }

    auto const &intermediate = *program.getIntermediate(language);

    glslang::GlslangToSpv(intermediate,
                          vulkanSpirVByteCode);
    return vulkanSpirVByteCode;
}
