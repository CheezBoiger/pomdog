// Copyright (c) 2013-2016 mogemimi. Distributed under the MIT license.

#pragma once

#include "Pomdog/Math/detail/ForwardDeclarations.hpp"
#include "Pomdog/Basic/Export.hpp"
#include <cstddef>
#include <cstdint>
#include <cfloat>
#include <type_traits>
#include <array>

namespace Pomdog {
namespace Detail {

template <typename T>
class POMDOG_EXPORT FloatingPointMatrix3x3 {
public:
    static_assert(std::is_floating_point<T>::value, "T is floating point.");
    typedef T value_type;

    std::array<std::array<T, 3>, 3> m;

private:
    static constexpr std::size_t RowSize = 3;
    static constexpr std::size_t ColumnSize = 3;

public:
    // Constructors:
    FloatingPointMatrix3x3() noexcept = default;

    ///@brief Construct from floating-point values.
    FloatingPointMatrix3x3(
        T m00, T m01, T m02,
        T m10, T m11, T m12,
        T m20, T m21, T m22) noexcept;

    // Assignment operators:
    FloatingPointMatrix3x3 & operator*=(FloatingPointMatrix3x3 const& other) noexcept;
    FloatingPointMatrix3x3 & operator+=(FloatingPointMatrix3x3 const& other) noexcept;
    FloatingPointMatrix3x3 & operator-=(FloatingPointMatrix3x3 const& other) noexcept;
    FloatingPointMatrix3x3 & operator*=(T scaleFactor) noexcept;
    FloatingPointMatrix3x3 & operator/=(T scaleFactor);

    // Unary operators:
    FloatingPointMatrix3x3 operator+() const noexcept;
    FloatingPointMatrix3x3 operator-() const noexcept;

    // Binary operators:
    FloatingPointMatrix3x3 operator+(FloatingPointMatrix3x3 const& other) const noexcept;
    FloatingPointMatrix3x3 operator-(FloatingPointMatrix3x3 const& other) const noexcept;
    FloatingPointMatrix3x3 operator*(FloatingPointMatrix3x3 const& other) const noexcept;
    FloatingPointMatrix3x3 operator*(T scaleFactor) const noexcept;
    FloatingPointMatrix3x3 operator/(T scaleFactor) const;

    bool operator==(FloatingPointMatrix3x3 const& other) const noexcept;
    bool operator!=(FloatingPointMatrix3x3 const& other) const noexcept;

    // Function-call operators:
    T const& operator()(std::size_t row, std::size_t column) const;
    T & operator()(std::size_t row, std::size_t column);

    void SetScale(FloatingPointVector3<T> const& scale) noexcept;

    FloatingPointVector3<T> GetScale() const noexcept;

    T Determinant() const noexcept;

    FloatingPointMatrix2x2<T> Minor2x2(std::size_t row, std::size_t column) const;

    static FloatingPointMatrix3x3
    Multiply(const FloatingPointMatrix3x3& matrix1, const FloatingPointMatrix3x3& matrix2) noexcept;

    static FloatingPointMatrix3x3
    Multiply(const FloatingPointMatrix3x3& matrix1, T scaleFactor) noexcept;

    static FloatingPointMatrix3x3
    Adjoint(FloatingPointMatrix3x3 const& matrix);

    static void
    Transpose(FloatingPointMatrix3x3 const& matrix, FloatingPointMatrix3x3 & result) noexcept;

    static FloatingPointMatrix3x3
    Transpose(FloatingPointMatrix3x3 const& matrix) noexcept;

    static void
    Invert(FloatingPointMatrix3x3 const& matrix, FloatingPointMatrix3x3 & result);

    static FloatingPointMatrix3x3
    Invert(FloatingPointMatrix3x3 const& matrix);

    static void
    Lerp(FloatingPointMatrix3x3 const& source1, FloatingPointMatrix3x3 const& source2,
        T amount, FloatingPointMatrix3x3 & result) noexcept;

    static FloatingPointMatrix3x3
    Lerp(FloatingPointMatrix3x3 const& source1, FloatingPointMatrix3x3 const& source2,
        T amount) noexcept;

    static void
    CreateTranslation(FloatingPointVector2<T> const& position, FloatingPointMatrix3x3 & result) noexcept;

    static FloatingPointMatrix3x3
    CreateTranslation(FloatingPointVector2<T> const& position) noexcept;

    static void
    CreateScale(T scale, FloatingPointMatrix3x3 & result) noexcept;

    static FloatingPointMatrix3x3
    CreateScale(T scale) noexcept;

    static void
    CreateScale(FloatingPointVector3<T> const& scale, FloatingPointMatrix3x3 & result) noexcept;

    static FloatingPointMatrix3x3
    CreateScale(FloatingPointVector3<T> const& scale) noexcept;

    static void
    CreateRotationX(Radian<T> const& angle, FloatingPointMatrix3x3 & result);

    static FloatingPointMatrix3x3
    CreateRotationX(Radian<T> const& angle);

    static void
    CreateRotationY(Radian<T> const& angle, FloatingPointMatrix3x3 & result);

    static FloatingPointMatrix3x3
    CreateRotationY(Radian<T> const& angle);

    static void
    CreateRotationZ(Radian<T> const& angle, FloatingPointMatrix3x3 & result);

    static FloatingPointMatrix3x3
    CreateRotationZ(Radian<T> const& angle);

    static void
    CreateFromQuaternion(FloatingPointQuaternion<T> const& quaternion, FloatingPointMatrix3x3 & result);

    static FloatingPointMatrix3x3
    CreateFromQuaternion(FloatingPointQuaternion<T> const& quaternion);

    static void
    CreateFromAxisAngle(FloatingPointVector3<T> const& axis, Radian<T> const& angle, FloatingPointMatrix3x3 & result);

    static FloatingPointMatrix3x3
    CreateFromAxisAngle(FloatingPointVector3<T> const& axis, Radian<T> const& angle);

    ///@brief Returns pointer to the first element.
    T const* Data() const noexcept;

    ///@brief Returns pointer to the first element.
    T* Data() noexcept;

    static FloatingPointMatrix3x3 const Identity;
};

template <typename T>
FloatingPointMatrix3x3<T> POMDOG_EXPORT
operator*(T scaleFactor, FloatingPointMatrix3x3<T> const& matrix) noexcept;

} // namespace Detail
} // namespace Pomdog
