//
//  Copyright (C) 2013 mogemimi.
//
//  Distributed under the MIT License.
//  See accompanying file LICENSE.md or copy at
//  http://enginetrouble.net/pomdog/LICENSE.md for details.
//

#ifndef POMDOG_SRC_GL4_EFFECTPASSGL4_5C5F046F_F42A_4AAD_AC22_389698C435EB_HPP
#define POMDOG_SRC_GL4_EFFECTPASSGL4_5C5F046F_F42A_4AAD_AC22_389698C435EB_HPP

#if (_MSC_VER > 1000)
#	pragma once
#endif

#include "OpenGLPrerequisites.hpp"
#include <Pomdog/Graphics/detail/ForwardDeclarations.hpp>
#include <Pomdog/Utility/detail/Tagged.hpp>
#include "../RenderSystem/NativeEffectPass.hpp"
#include "../Utility/Optional.hpp"

namespace Pomdog {
namespace Details {
namespace RenderSystem {

class ShaderBytecode;

namespace GL4 {

using ShaderProgramGL4 = Tagged<GLuint, EffectPass>;

class EffectPassGL4 final: public NativeEffectPass
{
public:
	EffectPassGL4() = delete;
	
	EffectPassGL4(ShaderBytecode const& vertexShaderBytecode, ShaderBytecode const& pixelShaderBytecode);
	
	~EffectPassGL4();

	void ApplyShaders();
	
private:
	Optional<ShaderProgramGL4> shaderProgram;
};

}// namespace GL4
}// namespace RenderSystem
}// namespace Details
}// namespace Pomdog

#endif // !defined(POMDOG_SRC_GL4_EFFECTPASSGL4_5C5F046F_F42A_4AAD_AC22_389698C435EB_HPP)
