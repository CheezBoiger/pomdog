// Copyright (c) 2013-2017 mogemimi. Distributed under the MIT license.

#pragma once

#include "Pomdog/Graphics/detail/ForwardDeclarations.hpp"
#include "Pomdog/Basic/Export.hpp"
#include <memory>
#include <cstdlib>

namespace Pomdog {

class GraphicsCommandList;

class POMDOG_EXPORT GraphicsCommandQueue final {
public:
    GraphicsCommandQueue() = delete;
    GraphicsCommandQueue(const GraphicsCommandQueue&) = delete;
    GraphicsCommandQueue & operator=(const GraphicsCommandQueue&) = delete;

    explicit GraphicsCommandQueue(
        std::unique_ptr<Detail::NativeGraphicsCommandQueue> && nativeCommandQueue);

    std::size_t GetCommandCount() const noexcept;

    void Reset();

    void PushbackCommandList(const std::shared_ptr<GraphicsCommandList>& commandList);

    void ExecuteCommandLists();

    void Present();

private:
    std::unique_ptr<Detail::NativeGraphicsCommandQueue> nativeCommandQueue;
};

} // namespace Pomdog
