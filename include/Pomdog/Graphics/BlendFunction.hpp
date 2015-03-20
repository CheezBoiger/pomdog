﻿// Copyright (c) 2013-2015 mogemimi.
// Distributed under the MIT license. See LICENSE.md file for details.

#ifndef POMDOG_BLENDFUNCTION_5A8D5F85_1D0C_4274_8115_BCEE3F6122EA_HPP
#define POMDOG_BLENDFUNCTION_5A8D5F85_1D0C_4274_8115_BCEE3F6122EA_HPP

#if _MSC_VER > 1000
#pragma once
#endif

#include <cstdint>

namespace Pomdog {

///@~Japanese
/// @brief ソースカラーとデスティネーションカラーのブレンディング処理を定義します。
enum class BlendFunction: std::uint8_t {
	///@~Japanese
	/// @brief ソースとデスティネーションを加算します。
	Add,

	///@~Japanese
	/// @brief ソースからデスティネーションを減算します。
	Subtract,

	///@~Japanese
	/// @brief デスティネーションからソースを減算します。
	ReverseSubtract,

	///@~Japanese
	/// @brief ソースとデスティネーションのうち小さいほうを選択します。
	Min,

	///@~Japanese
	/// @brief ソースとデスティネーションのうち大きいほうを選択します。
	Max,
};

}// namespace Pomdog

#endif // !defined(POMDOG_BLENDFUNCTION_5A8D5F85_1D0C_4274_8115_BCEE3F6122EA_HPP)
