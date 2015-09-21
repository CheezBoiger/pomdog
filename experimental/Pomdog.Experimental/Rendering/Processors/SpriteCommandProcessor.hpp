// Copyright (c) 2013-2015 mogemimi. Distributed under the MIT license.

#pragma once

#include "Pomdog.Experimental/Graphics/SpriteBatchRenderer.hpp"
#include "Pomdog.Experimental/Rendering/RenderCommandProcessor.hpp"
#include <Pomdog/Pomdog.hpp>

namespace Pomdog {

class SpriteCommandProcessor final: public RenderCommandProcessor {
public:
    SpriteCommandProcessor(
        std::shared_ptr<GraphicsDevice> const& graphicsDevice,
        AssetManager & assets);

    void Begin(GraphicsCommandQueue & commandQueue) override;

    void Draw(GraphicsCommandQueue & commandQueue, RenderCommand & command) override;

    void End(GraphicsCommandQueue & commandQueue) override;

    int DrawCallCount() const override;

    void SetViewProjection(Matrix4x4 const& view, Matrix4x4 const& projection) override;

public:
    Detail::Rendering::SpriteBatchRenderer spriteBatch;
    std::uint32_t drawCallCount;
};

} // namespace Pomdog
