﻿//
//  Copyright (C) 2013 mogemimi.
//
//  Distributed under the MIT License.
//  See accompanying file LICENSE.md or copy at
//  http://enginetrouble.net/pomdog/LICENSE.md for details.
//

#ifndef POMDOG_SRC_GL4_SAMPLERSTATEGL4_B8072910_B914_4640_9103_CEA8D030AD4F_HPP
#define POMDOG_SRC_GL4_SAMPLERSTATEGL4_B8072910_B914_4640_9103_CEA8D030AD4F_HPP

#if (_MSC_VER > 1000)
#	pragma once
#endif

#include "OpenGLPrerequisites.hpp"
#include "../RenderSystem/NativeSamplerState.hpp"
#include <Pomdog/Graphics/detail/ForwardDeclarations.hpp>
#include <Pomdog/Utility/detail/Tagged.hpp>

namespace Pomdog {
namespace Details {
namespace RenderSystem {
namespace GL4 {

using TextureAddressModeGL4 = Tagged<GLenum, TextureAddressMode>;
using SamplerObjectGL4 = Tagged<GLenum, SamplerState>;

class SamplerStateGL4 final: public NativeSamplerState
{
public:
	SamplerStateGL4() = delete;
	
	explicit SamplerStateGL4(SamplerDescription const& description);
	
	~SamplerStateGL4() override;
	
	///@copydoc NativeSamplerState
	void Apply(std::size_t index) override;
	
private:
	// C++14:
	// std::optional<SamplerObjectGL4> samplerObject;

	// Older C++:
	SamplerObjectGL4 samplerObject;
	bool samplerObjectEnable;
};

}// namespace GL4
}// namespace RenderSystem
}// namespace Details
}// namespace Pomdog

#endif // !defined(POMDOG_SRC_GL4_SAMPLERSTATEGL4_B8072910_B914_4640_9103_CEA8D030AD4F_HPP)
