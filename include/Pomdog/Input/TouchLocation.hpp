﻿// Copyright (c) 2013-2015 mogemimi.
// Distributed under the MIT license. See LICENSE.md file for details.

#ifndef POMDOG_TOUCHLOCATION_F1E1CEB0_7202_4485_BA08_F987E4AF9574_HPP
#define POMDOG_TOUCHLOCATION_F1E1CEB0_7202_4485_BA08_F987E4AF9574_HPP

#if _MSC_VER > 1000
#pragma once
#endif

#include "TouchLocationState.hpp"
#include "Pomdog/Basic/Export.hpp"
#include "Pomdog/Math/Point2D.hpp"
#include <cstdint>

namespace Pomdog {

class TouchLocation {
public:
	Point2D Position;
	std::uint16_t Id;
	TouchLocationState State = TouchLocationState::Invalid;
};

}// namespace Pomdog

#endif // !defined(POMDOG_TOUCHLOCATION_F1E1CEB0_7202_4485_BA08_F987E4AF9574_HPP)
