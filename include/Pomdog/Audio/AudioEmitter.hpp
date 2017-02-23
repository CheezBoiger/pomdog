// Copyright (c) 2013-2017 mogemimi. Distributed under the MIT license.

#pragma once

#include "Pomdog/Math/Vector3.hpp"

namespace Pomdog {

class AudioEmitter {
public:
    Vector3 Forward;
    Vector3 Position;
    Vector3 Up;
    Vector3 Velocity;
    float DopplerScale;
};

} // namespace Pomdog
