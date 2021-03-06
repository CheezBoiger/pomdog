// Copyright (c) 2013-2017 mogemimi. Distributed under the MIT license.

#pragma once

#include "Pomdog/Math/detail/ForwardDeclarations.hpp"
#include "Pomdog/Basic/Export.hpp"

namespace Pomdog {

class POMDOG_EXPORT Viewport final {
public:
    int TopLeftX;
    int TopLeftY;
    int Width;
    int Height;
    float MinDepth;
    float MaxDepth;

public:
    Viewport() noexcept = default;

    explicit Viewport(const Rectangle& bounds) noexcept;

    Viewport(int x, int y, int width, int height) noexcept;

    Viewport(int x, int y, int width, int height,
        float minDepth, float maxDepth) noexcept;

    Vector3 Project(
        const Vector3& source,
        const Matrix4x4& worldViewProjection) const;

    Vector3 Unproject(
        const Vector3& source,
        const Matrix4x4& worldViewProjection) const;

    Rectangle GetBounds() const noexcept;

    float GetAspectRatio() const;
};

} // namespace Pomdog
