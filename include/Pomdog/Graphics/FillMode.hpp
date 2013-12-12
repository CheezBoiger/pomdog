﻿//
//  Copyright (C) 2013 mogemimi.
//
//  Distributed under the MIT License.
//  See accompanying file LICENSE.md or copy at
//  http://enginetrouble.net/pomdog/LICENSE.md for details.
//

#ifndef POMDOG_FILLMODE_E311626B_384B_4509_BB62_350D45C16730_HPP
#define POMDOG_FILLMODE_E311626B_384B_4509_BB62_350D45C16730_HPP

#if (_MSC_VER > 1000)
#	pragma once
#endif

#include "../Config/FundamentalTypes.hpp"

namespace Pomdog {

/// @addtogroup Framework
/// @{
/// @addtogroup Graphics
/// @{

///@~Japanese
/// @brief プリミティブを形成する各頂点とそれらを結ぶラインの塗りつぶしモードを定義します。
enum class FillMode: std::uint16_t
{
	///@~Japanese
	/// @brief 各頂点を結ぶラインを描画します。
	WireFrame,

	///@~Japanese
	/// @brief 頂点によって形成されたプリミティブのソリッド面を塗りつぶします。既定値です。
	Solid,
};

/// @}
/// @}

}// namespace Pomdog

#endif // !defined(POMDOG_FILLMODE_E311626B_384B_4509_BB62_350D45C16730_HPP)
