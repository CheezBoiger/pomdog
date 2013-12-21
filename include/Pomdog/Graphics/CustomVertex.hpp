//
//  Copyright (C) 2013 mogemimi.
//
//  Distributed under the MIT License.
//  See accompanying file LICENSE.md or copy at
//  http://enginetrouble.net/pomdog/LICENSE.md for details.
//

#ifndef POMDOG_CUSTOMVERTEX_614B90BE_45A7_486E_909C_2A51C33975C8_HPP
#define POMDOG_CUSTOMVERTEX_614B90BE_45A7_486E_909C_2A51C33975C8_HPP

#if (_MSC_VER > 1000)
#	pragma once
#endif

#include <utility>
#include <vector>
#include "../Config/Export.hpp"
#include "../Config/FundamentalTypes.hpp"
#include "../Math/detail/ForwardDeclarations.hpp"
#include "VertexDeclaration.hpp"

namespace Pomdog {
namespace Details {
namespace Graphics {

template <typename T> struct ToVertexElementFormat;
template <> struct ToVertexElementFormat<float> {
	static constexpr VertexElementFormat value = VertexElementFormat::Float;
};
template <> struct ToVertexElementFormat<Vector2> {
	static constexpr VertexElementFormat value = VertexElementFormat::Float2;
};
template <> struct ToVertexElementFormat<Vector3> {
	static constexpr VertexElementFormat value = VertexElementFormat::Float3;
};
template <> struct ToVertexElementFormat<Vector4> {
	static constexpr VertexElementFormat value = VertexElementFormat::Float4;
};
template <> struct ToVertexElementFormat<Color> {
	static constexpr VertexElementFormat value = VertexElementFormat::Float4;
};
template <> struct ToVertexElementFormat<Quaternion> {
	static constexpr VertexElementFormat value = VertexElementFormat::Float4;
};

std::uint8_t POMDOG_EXPORT ToByteWidth(VertexElementFormat format);

template <VertexElementFormat... Formats>
std::vector<VertexElement> VertexCombined()
{
	std::initializer_list<VertexElementFormat> formats { Formats... };

	std::vector<VertexElement> vertexElements;
	vertexElements.reserve(formats.size());
	std::uint16_t offsetBytes = 0;
	for (auto format: formats) {
		vertexElements.push_back({offsetBytes, format});
		offsetBytes += ToByteWidth(format);
	}
	return std::move(vertexElements);
}

template <typename... Elements>
struct VertexElementTuple;

template <typename Element>
struct VertexElementTuple<Element> {
	Element end;
};

template <typename Head, typename... Elements>
struct VertexElementTuple<Head, Elements...> {
	Head first;
	VertexElementTuple<Elements...> elements;
};

}// namespace Graphics
}// namespace Details

/// @addtogroup Framework
/// @{
/// @addtogroup Graphics
/// @{

template <typename T, typename... Arguments>
class CustomVertex
{
public:
	Details::Graphics::VertexElementTuple<T, Arguments...> vertex;

	static VertexDeclaration Declaration()
	{
		using Details::Graphics::VertexCombined;
		using Details::Graphics::ToVertexElementFormat;
		return VertexDeclaration(VertexCombined<
			ToVertexElementFormat<T>::value,
			ToVertexElementFormat<Arguments>::value...
		>());
	}
};

/// @}
/// @}

}// namespace Pomdog

#endif // !defined(POMDOG_CUSTOMVERTEX_614B90BE_45A7_486E_909C_2A51C33975C8_HPP)