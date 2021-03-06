// Copyright (c) 2013-2017 mogemimi. Distributed under the MIT license.

#pragma once

#include <fstream>
#include <cstddef>

namespace Pomdog {
namespace Detail {

struct BinaryFileStream {
    std::ifstream Stream;
    std::size_t SizeInBytes;
};

} // namespace Detail
} // namespace Pomdog
