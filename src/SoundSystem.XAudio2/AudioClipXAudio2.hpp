// Copyright (c) 2013-2017 mogemimi. Distributed under the MIT license.

#pragma once

#include "PrerequisitesXAudio2.hpp"
#include "../Utility/Noncopyable.hpp"
#include <cstdint>
#include <cstddef>
#include <vector>

namespace Pomdog {

enum class AudioChannels : std::uint8_t;

namespace Detail {
namespace SoundSystem {
namespace XAudio2 {

class AudioClipXAudio2 final : Noncopyable {
public:
    AudioClipXAudio2(
        std::vector<std::uint8_t> && audioData,
        std::vector<std::uint8_t> && waveFormat);

    const WAVEFORMATEX* WaveFormat() const;

    const std::uint8_t* Data() const;

    std::size_t SizeInBytes() const;

private:
    std::vector<std::uint8_t> audioData;
    std::vector<std::uint8_t> waveFormat;
};

} // namespace XAudio2
} // namespace SoundSystem
} // namespace Detail
} // namespace Pomdog
