//
//  Copyright (C) 2013-2014 mogemimi.
//
//  Distributed under the MIT License.
//  See accompanying file LICENSE.md or copy at
//  http://enginetrouble.net/pomdog/LICENSE.md for details.
//

#ifndef POMDOG_SPRITEDRAWINGCONTEXT_4AC87153_9AFF_4B5C_AA4F_B9125DD093DE_HPP
#define POMDOG_SPRITEDRAWINGCONTEXT_4AC87153_9AFF_4B5C_AA4F_B9125DD093DE_HPP

#if (_MSC_VER > 1000)
#	pragma once
#endif

#include <memory>
#include <Pomdog/Pomdog.hpp>
#include "UI/DrawingContext.hpp"
#include "Graphics/SpriteBatch.hpp"
#include "Graphics/SpriteFont.hpp"

namespace Pomdog {
namespace UI {

class SpriteDrawingContext final: public UI::DrawingContext {
private:
	SpriteBatch & spriteBatch;
	SpriteBatch & spriteFontBatch;
	SpriteFont & spriteFont;
	std::shared_ptr<EffectPass> distanceFieldEffect;
	std::shared_ptr<Texture2D> texture;
	std::vector<Matrix3x2> matrixStack;

public:
	explicit SpriteDrawingContext(SpriteBatch & spriteBatchIn, SpriteBatch & spriteFontBatchIn,
		std::shared_ptr<EffectPass> const& distanceFieldEffectIn, SpriteFont & spriteFontIn, std::shared_ptr<Texture2D> const& textureIn);
	
	Matrix3x2 Top() const override;
	
	void Push(Matrix3x2 const& matrix) override;
	
	void Pop() override;
	
	void DrawRectangle(Matrix3x2 const& transform, Color const& color, Rectangle const& rectangle) override;
	
	void DrawLine(Matrix3x2 const& transform, Color const& color, float penSize, Vector2 const& point1, Vector2 const& point2) override;
	
	void DrawString(Matrix3x2 const& transform, Color const& color,
		FontWeight fontWeight, FontSize fontSize, std::string const& text) override;
};

}// namespace UI
}// namespace Pomdog

#endif // !defined(POMDOG_SPRITEDRAWINGCONTEXT_4AC87153_9AFF_4B5C_AA4F_B9125DD093DE_HPP)