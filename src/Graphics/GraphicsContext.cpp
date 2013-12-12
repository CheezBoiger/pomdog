//
//  Copyright (C) 2013 mogemimi.
//
//  Distributed under the MIT License.
//  See accompanying file LICENSE.md or copy at
//  http://enginetrouble.net/pomdog/LICENSE.md for details.
//

#include <Pomdog/Graphics/GraphicsContext.hpp>
#include <Pomdog/Utility/Assert.hpp>
#include <Pomdog/Utility/Exception.hpp>
#include <Pomdog/Graphics/BlendState.hpp>
#include <Pomdog/Graphics/DepthStencilState.hpp>
#include <Pomdog/Graphics/RasterizerState.hpp>
#include <Pomdog/Graphics/SamplerState.hpp>
#include <Pomdog/Graphics/Viewport.hpp>
#include <array>
#include <utility>
#include "../RenderSystem/NativeGraphicsContext.hpp"
#include "../RenderSystem/NativeBlendState.hpp"
#include "../RenderSystem/NativeDepthStencilState.hpp"
#include "../RenderSystem/NativeRasterizerState.hpp"
#include "../RenderSystem/NativeSamplerState.hpp"

namespace Pomdog {

using Details::RenderSystem::NativeGraphicsContext;

//-----------------------------------------------------------------------
#if defined(POMDOG_COMPILER_CLANG)
#pragma mark -
#pragma mark GraphicsContext::Impl class
#endif
//-----------------------------------------------------------------------
class GraphicsContext::Impl final
{
public:
	Impl() = delete;
	Impl(Impl const&) = delete;
	Impl(Impl &&) = default;
	
	explicit Impl(std::unique_ptr<NativeGraphicsContext> nativeContext);
	
public:
	std::unique_ptr<NativeGraphicsContext> nativeContext;
	Viewport viewport;
	std::shared_ptr<BlendState> blendState;
	std::shared_ptr<DepthStencilState> depthStencilState;
	std::shared_ptr<RasterizerState> rasterizerState;
	std::array<std::shared_ptr<SamplerState>, 16> samplerStates;
};
//-----------------------------------------------------------------------
GraphicsContext::Impl::Impl(std::unique_ptr<NativeGraphicsContext> nativeContext)
	: nativeContext(std::move(nativeContext))
{}
//-----------------------------------------------------------------------
#if defined(POMDOG_COMPILER_CLANG)
#pragma mark -
#pragma mark GraphicsContext class
#endif
//-----------------------------------------------------------------------
GraphicsContext::GraphicsContext(std::unique_ptr<NativeGraphicsContext> nativeContext)
	: impl(new Impl(std::move(nativeContext)))
{}
//-----------------------------------------------------------------------
GraphicsContext::~GraphicsContext()
{}
//-----------------------------------------------------------------------
void GraphicsContext::Clear(Color const& color)
{
	POMDOG_ASSERT(impl);
	POMDOG_ASSERT(impl->nativeContext);

	impl->nativeContext->Clear(color);
}
//-----------------------------------------------------------------------
void GraphicsContext::Clear(ClearOptions options, Color const& color, float depth, std::int32_t stencil)
{
	POMDOG_ASSERT(impl);
	POMDOG_ASSERT(impl->nativeContext);

	impl->nativeContext->Clear(options, color, depth, stencil);
}
//-----------------------------------------------------------------------
void GraphicsContext::Present()
{
	POMDOG_ASSERT(impl);
	POMDOG_ASSERT(impl->nativeContext);

	impl->nativeContext->Present();
}
//-----------------------------------------------------------------------
Viewport const& GraphicsContext::GetViewport() const
{
	POMDOG_ASSERT(impl);
	POMDOG_ASSERT(impl->nativeContext);

	return impl->viewport;
}
//-----------------------------------------------------------------------
void GraphicsContext::SetViewport(Viewport const& viewport)
{
	POMDOG_ASSERT(impl);
	POMDOG_ASSERT(impl->nativeContext);
	POMDOG_ASSERT(viewport.GetWidth() > 0);
	POMDOG_ASSERT(viewport.GetHeight() > 0);

	impl->viewport = viewport;
	impl->nativeContext->SetViewport(viewport);
}
//-----------------------------------------------------------------------
Rectangle GraphicsContext::GetScissorRectangle() const
{
	POMDOG_ASSERT(impl);
	POMDOG_ASSERT(impl->nativeContext);
	return impl->nativeContext->GetScissorRectangle();
}
//-----------------------------------------------------------------------
void GraphicsContext::SetScissorRectangle(Pomdog::Rectangle const& rectangle)
{
	POMDOG_ASSERT(impl);
	POMDOG_ASSERT(impl->nativeContext);
	impl->nativeContext->SetScissorRectangle(rectangle);
}
//-----------------------------------------------------------------------
void GraphicsContext::SetBlendState(std::shared_ptr<BlendState> const& blendState)
{
	POMDOG_ASSERT(impl);
	POMDOG_ASSERT(blendState);
	impl->blendState = blendState;
	impl->blendState->GetNativeBlendState()->Apply();
}
//-----------------------------------------------------------------------
void GraphicsContext::SetDepthStencilState(std::shared_ptr<DepthStencilState> const& depthStencilState)
{
	POMDOG_ASSERT(impl);
	POMDOG_ASSERT(depthStencilState);
	impl->depthStencilState = depthStencilState;
	impl->depthStencilState->GetNativeDepthStencilState()->Apply();
}
//-----------------------------------------------------------------------
void GraphicsContext::SetRasterizerState(std::shared_ptr<RasterizerState> const& rasterizerState)
{
	POMDOG_ASSERT(impl);
	POMDOG_ASSERT(rasterizerState);
	impl->rasterizerState = rasterizerState;
	impl->rasterizerState->GetNativeRasterizerState()->Apply();
}
//-----------------------------------------------------------------------
void GraphicsContext::SetSamplerState(std::size_t index, std::shared_ptr<SamplerState> const& samplerState)
{
	POMDOG_ASSERT(impl);
	POMDOG_ASSERT(samplerState);
	
	POMDOG_ASSERT(impl->samplerStates.size() > index);
	
	impl->samplerStates[index] = samplerState;
	impl->samplerStates[index]->GetNativeSamplerState()->Apply(index);
}
//-----------------------------------------------------------------------
}// namespace Pomdog
