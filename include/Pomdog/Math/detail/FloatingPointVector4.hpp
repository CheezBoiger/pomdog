//
//  Copyright (C) 2013 mogemimi.
//
//  Distributed under the MIT License.
//  See accompanying file LICENSE.md or copy at
//  http://enginetrouble.net/pomdog/LICENSE.md for details.
//

#ifndef POMDOG_FLOATINGPOINTVECTOR4_HPP
#define POMDOG_FLOATINGPOINTVECTOR4_HPP

#if (_MSC_VER > 1000)
#	pragma once
#endif

#include "../../Config/FundamentalTypes.hpp"
#include "ForwardDeclarations.hpp"
#include <type_traits>

namespace Pomdog {
namespace Details {

/// @addtogroup Framework
/// @{
/// @addtogroup Math
/// @{

///@~English
/// @brief vector in four-dimensional space.
///@~Japanese
/// @brief 4 つの要素を持つベクトル（4 次元ベクトル）を定義します。
template <typename T>
class FloatingPointVector4
{
public:
	static_assert(std::is_floating_point<T>::value, "T is floating point.");
	typedef T value_type;

	T x, y, z, w;

public:
	// Constructors:
	FloatingPointVector4() = default;
	
	///@brief Copy constructor.
	FloatingPointVector4(FloatingPointVector4 const&) = default;
	
	///@brief Move constructor.
	FloatingPointVector4(FloatingPointVector4 &&) = default;

	///@brief Construct from floating-point values.
	FloatingPointVector4(T x, T y, T z, T w);
	FloatingPointVector4(FloatingPointVector3<T> const& xyz, T w);
	
	virtual ~FloatingPointVector4() = default;

	// Assignment operators:
	FloatingPointVector4 & operator=(FloatingPointVector4 const& other) = default;
	FloatingPointVector4 & operator=(FloatingPointVector4 && other) = default;

	FloatingPointVector4 & operator+=(FloatingPointVector4 const& other);
	FloatingPointVector4 & operator-=(FloatingPointVector4 const& other);
	FloatingPointVector4 & operator*=(T scaleFactor);
	FloatingPointVector4 & operator/=(T scaleFactor);

	// Unary operators:
	FloatingPointVector4 operator+() const;
	FloatingPointVector4 operator-() const;

	// Binary operators:
	FloatingPointVector4 operator+(FloatingPointVector4 const& other) const;
	FloatingPointVector4 operator-(FloatingPointVector4 const& other) const;
	FloatingPointVector4 operator*(FloatingPointVector4 const& other) const;
	FloatingPointVector4 operator/(FloatingPointVector4 const& other) const;
	FloatingPointVector4 operator*(T scaleFactor) const;
	FloatingPointVector4 operator/(T scaleFactor) const;
	
	bool operator == (FloatingPointVector4 const& other) const;
	bool operator != (FloatingPointVector4 const& other) const;

	// Products and length, normalize:
	
	///@~Japanese
	/// @brief ベクトルの長さを計算します。
	T Length() const;
	
	///@~Japanese
	/// @brief ベクトルの長さの 2 乗を計算します。
	T LengthSquared() const;

	///@~Japanese
	/// @brief 2 つのベクトル間の距離を計算します。
	static T Distance(FloatingPointVector4 const& a, FloatingPointVector4 const& b);

	///@~Japanese
	/// @brief 2 つのベクトルの内積を計算します。
	static T Dot(FloatingPointVector4 const& a, FloatingPointVector4 const& b);

	///@~Japanese
	/// @brief 現在のベクトルを単位ベクトルに変換します。
	void Normalize();

	///@~Japanese
	/// @brief 指定されたベクトルの単位ベクトルを計算します。
	static FloatingPointVector4 Normalize(FloatingPointVector4 const& source);

	///@~Japanese
	/// @brief 指定されたベクトルの単位ベクトルを計算します。
	static void Normalize(FloatingPointVector4 const& source, FloatingPointVector4 & result);

	///@~English
	/// @brief Returns pointer to the first element.
	///@~Japanese
	/// @brief 最初の要素へのポインタを返します。
	T const* Data() const;

	///@~English
	/// @brief Returns pointer to the first element.
	///@~Japanese
	/// @brief 最初の要素へのポインタを返します。
	T* Data();
};

template <typename T>
FloatingPointVector4<T> operator*(T scaleFactor, FloatingPointVector4<T> const& vector);

/// @}
/// @}

}// namespace Details
}// namespace Pomdog

#endif // !defined(POMDOG_FLOATINGPOINTVECTOR4_HPP)