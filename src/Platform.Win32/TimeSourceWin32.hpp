// Copyright (c) 2013-2017 mogemimi. Distributed under the MIT license.

#pragma once

#include "Pomdog/Application/TimePoint.hpp"

namespace Pomdog {
namespace Detail {
namespace Win32 {

class TimeSourceWin32 {
public:
    TimeSourceWin32();

    TimePoint Now() const;

private:
    double secondsPerTick;
};

} // namespace Win32
} // namespace Detail
} // namespace Pomdog
