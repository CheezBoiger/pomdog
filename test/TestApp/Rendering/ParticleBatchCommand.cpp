﻿//
//  Copyright (C) 2013-2014 mogemimi.
//
//  Distributed under the MIT License.
//  See accompanying file LICENSE.md or copy at
//  http://enginetrouble.net/pomdog/LICENSE.md for details.
//

#include "ParticleBatchCommand.hpp"
#include "../Graphics/SpriteRenderer.hpp"

namespace Pomdog {
namespace Details {
namespace Rendering {

ParticleBatchCommand::~ParticleBatchCommand() = default;

void ParticleBatchCommand::Execute(std::shared_ptr<GraphicsContext> const& graphicsContext)
{
	auto blendStateOld = graphicsContext->GetBlendState();
	graphicsContext->SetBlendState(blendState);

	POMDOG_ASSERT(spriteRenderer);
	spriteRenderer->Begin(SpriteSortMode::Deferred, modelViewProjection);
	{
		for (auto & particle: *particles)
		{
			spriteRenderer->Draw(texture, Matrix3x2::Identity, particle.Position,
				Rectangle(0, 0, texture->Width(), texture->Height()),
				particle.Color, particle.Rotation, {0.5f, 0.5f}, particle.Size, 0);
		}
	}
	spriteRenderer->End();
	graphicsContext->SetBlendState(blendStateOld);
}

}// namespace Rendering
}// namespace Details
}// namespace Pomdog
