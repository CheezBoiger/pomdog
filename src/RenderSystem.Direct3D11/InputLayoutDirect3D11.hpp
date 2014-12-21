﻿//
//  Copyright (C) 2013-2014 mogemimi.
//  Distributed under the MIT License. See LICENSE.md or
//  http://enginetrouble.net/pomdog/license for details.
//

#ifndef POMDOG_INPUTLAYOUTDIRECT3D11_93CA68F0_7EE1_4BC3_9B42_D90E5CB7E839_HPP
#define POMDOG_INPUTLAYOUTDIRECT3D11_93CA68F0_7EE1_4BC3_9B42_D90E5CB7E839_HPP

#if (_MSC_VER > 1000)
#pragma once
#endif

#include "PrerequisitesDirect3D11.hpp"
#include "../RenderSystem/NativeInputLayout.hpp"
#include <Pomdog/Graphics/detail/ForwardDeclarations.hpp>
#include <vector>
#include <string>

namespace Pomdog {
namespace Details {

class ShaderBytecode;

namespace RenderSystem {
namespace Direct3D11 {

class InputLayoutDirect3D11 final: public NativeInputLayout {
public:
	InputLayoutDirect3D11(ID3D11Device* device, ShaderBytecode const& vertexShaderBytecode,
		std::vector<VertexBufferBinding> const& vertexBufferBindings);

	void Apply(ID3D11DeviceContext* deviceContext);

private:
	Microsoft::WRL::ComPtr<ID3D11InputLayout> nativeInputLayout;
};

}// namespace Direct3D11
}// namespace RenderSystem
}// namespace Details
}// namespace Pomdog

#endif // !defined(POMDOG_INPUTLAYOUTDIRECT3D11_93CA68F0_7EE1_4BC3_9B42_D90E5CB7E839_HPP)