//
//  Copyright (C) 2013 mogemimi.
//
//  Distributed under the MIT License.
//  See accompanying file LICENSE.md or copy at
//  http://enginetrouble.net/pomdog/LICENSE.md for details.
//

#include <pomdog/Math/Rectangle.hpp>
#include <pomdog/Utility/Assert.hpp>

namespace Pomdog {

Rectangle::Rectangle(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height)
	: x(x)
	, y(y)
	, width(width)
	, height(height)
{}
//-----------------------------------------------------------------------
Rectangle::Rectangle(Point2D const& position, std::int32_t width, std::int32_t height)
	: x(position.x)
	, y(position.y)
	, width(width)
	, height(height)
{}
//-----------------------------------------------------------------------
bool Rectangle::operator==(Rectangle const& other) const
{
	return (
		x == other.x &&
		y == other.y &&
		width  == other.width &&
		height == other.height
	);
}
//-----------------------------------------------------------------------
bool Rectangle::operator!=(Rectangle const& other) const
{
	return (
		x != other.x ||
		y != other.y ||
		width  != other.width ||
		height != other.height
	);
}
//-----------------------------------------------------------------------
std::int32_t Rectangle::Bottom() const
{
	return y + height;
}
//-----------------------------------------------------------------------
std::int32_t Rectangle::Right() const
{
	return x + width;
}
//-----------------------------------------------------------------------
std::int32_t Rectangle::Top() const
{
	return y;
}
//-----------------------------------------------------------------------
std::int32_t Rectangle::Left() const
{
	return x;
}
//-----------------------------------------------------------------------
Point2D Rectangle::Center() const
{
	return Point2D(x + width / 2, y + height / 2);
}
//-----------------------------------------------------------------------
Point2D Rectangle::GetLocation() const
{
	return Point2D(x, y);
}
//-----------------------------------------------------------------------
void Rectangle::SetLocation(Point2D const& position)
{
	this->x = position.x;
	this->y = position.y;
}
//-----------------------------------------------------------------------
void Rectangle::Offset(std::int32_t offsetX, std::int32_t offsetY)
{
	this->x += offsetX;
	this->y += offsetY;
}
//-----------------------------------------------------------------------
void Rectangle::Offset(Point2D const& offset)
{
	x += offset.x;
	y += offset.y;
}

}// namespace Pomdog