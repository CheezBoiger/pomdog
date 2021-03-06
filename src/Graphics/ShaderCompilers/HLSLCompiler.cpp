// Copyright (c) 2013-2017 mogemimi. Distributed under the MIT license.

#include "Pomdog/Graphics/ShaderCompilers/HLSLCompiler.hpp"
#include "../../RenderSystem/NativeGraphicsDevice.hpp"
#include "../../RenderSystem/ShaderBytecode.hpp"
#include "../../RenderSystem/ShaderCompileOptions.hpp"
#include "Pomdog/Graphics/GraphicsDevice.hpp"
#include "Pomdog/Graphics/Shader.hpp"
#include "Pomdog/Graphics/ShaderLanguage.hpp"
#include "Pomdog/Utility/Assert.hpp"

using Pomdog::Detail::ShaderBytecode;
using Pomdog::Detail::ShaderCompileOptions;

namespace Pomdog {
namespace ShaderCompilers {

std::unique_ptr<Shader> HLSLCompiler::CreateShaderFromBinary(
    GraphicsDevice & graphicsDevice,
    const void* shaderSource,
    std::size_t byteLength,
    ShaderPipelineStage pipelineStage)
{
    POMDOG_ASSERT(shaderSource != nullptr);
    POMDOG_ASSERT(byteLength > 0);
    POMDOG_ASSERT(graphicsDevice.GetSupportedLanguage() == ShaderLanguage::HLSL);

    auto nativeGraphicsDevice = graphicsDevice.GetNativeGraphicsDevice();

    ShaderBytecode shaderBytecode;
    shaderBytecode.Code = shaderSource;
    shaderBytecode.ByteLength = byteLength;

    ShaderCompileOptions compileOptions;
    compileOptions.Profile.PipelineStage = pipelineStage;
    compileOptions.Precompiled = true;

    return nativeGraphicsDevice->CreateShader(shaderBytecode, compileOptions);
}

std::unique_ptr<Shader> HLSLCompiler::CreateShaderFromSource(
    GraphicsDevice & graphicsDevice,
    const void* shaderSource,
    std::size_t byteLength,
    const std::string& entryPoint,
    ShaderPipelineStage pipelineStage,
    const Optional<std::string>& currentDirectory)
{
    POMDOG_ASSERT(shaderSource != nullptr);
    POMDOG_ASSERT(byteLength > 0);
    POMDOG_ASSERT(graphicsDevice.GetSupportedLanguage() == ShaderLanguage::HLSL);

    auto nativeGraphicsDevice = graphicsDevice.GetNativeGraphicsDevice();

    ShaderBytecode shaderBytecode;
    shaderBytecode.Code = shaderSource;
    shaderBytecode.ByteLength = byteLength;

    ShaderCompileOptions compileOptions;
    compileOptions.EntryPoint = entryPoint;
    compileOptions.Profile.PipelineStage = pipelineStage;
    compileOptions.Profile.ShaderModel.Major = 4;
    compileOptions.Profile.ShaderModel.Minor = 0;
    compileOptions.Precompiled = false;

    if (currentDirectory) {
        compileOptions.CurrentDirectory = *currentDirectory;
    }

    return nativeGraphicsDevice->CreateShader(shaderBytecode, compileOptions);
}

} // namespace ShaderCompilers
} // namespace Pomdog
