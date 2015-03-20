﻿// Copyright (c) 2013-2015 mogemimi.
// Distributed under the MIT license. See LICENSE.md file for details.

#ifndef POMDOG_VECTOR3_7F01F272_CEB3_49AB_8F83_FF493EFD0757_HPP
#define POMDOG_VECTOR3_7F01F272_CEB3_49AB_8F83_FF493EFD0757_HPP

#if _MSC_VER > 1000
#pragma once
#endif

#include "detail/FloatingPointVector3.hpp"

namespace Pomdog {

///@~English
/// @brief vector in three-dimensional space.
///@~Japanese
/// @brief 3 つの要素を持つベクトル（3 次元ベクトル）を定義します。
using Vector3 = Detail::FloatingPointVector3<float>;

}// namespace Pomdog

#endif // !defined(POMDOG_VECTOR3_7F01F272_CEB3_49AB_8F83_FF493EFD0757_HPP)
