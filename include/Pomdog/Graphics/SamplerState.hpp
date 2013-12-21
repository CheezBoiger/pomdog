﻿//
//  Copyright (C) 2013 mogemimi.
//
//  Distributed under the MIT License.
//  See accompanying file LICENSE.md or copy at
//  http://enginetrouble.net/pomdog/LICENSE.md for details.
//

#ifndef POMDOG_SAMPLERSTATE_87568CD5_37AB_4449_B4A1_3AB24A59A849_HPP
#define POMDOG_SAMPLERSTATE_87568CD5_37AB_4449_B4A1_3AB24A59A849_HPP

#if (_MSC_VER > 1000)
#	pragma once
#endif

#include <memory>
#include "../Config/Export.hpp"
#include "../Utility/Noncopyable.hpp"
#include "detail/ForwardDeclarations.hpp"
#include "SamplerDescription.hpp"

namespace Pomdog {
namespace Details {
namespace RenderSystem {

class NativeSamplerState;

}// namespace RenderSystem
}// namespace Details

class GraphicsDevice;

/// @addtogroup Framework
/// @{
/// @addtogroup Graphics
/// @{

///@~Japanese
/// @brief テクスチャのサンプリング方法を指定するサンプラーステートです。
class POMDOG_EXPORT SamplerState: Noncopyable
{
public:
	SamplerState() = delete;

	SamplerState(std::shared_ptr<GraphicsDevice> const& graphicsDevice, SamplerDescription const& description);
	
	~SamplerState();

	///@~Japanese
	/// @brief サンプラーステートを作成するために記述したサンプラーステートの設定内容を取得します。
	SamplerDescription GetDescription() const;

	///@~Japanese
	/// @brief 異方性フィルタリングを有効にするサンプラステートを作成します。
	/// 範囲外テクスチャ座標のアドレッシング方法は TextureAddressMode::Clamp を使用します。
	static std::shared_ptr<SamplerState>
	CreateAnisotropicClamp(std::shared_ptr<GraphicsDevice> const& graphicsDevice);

	///@~Japanese
	/// @brief 異方性フィルタリングを有効にするサンプラステートを作成します。
	/// 範囲外テクスチャ座標のアドレッシング方法は TextureAddressMode::Wrap を使用します。
	static std::shared_ptr<SamplerState>
	CreateAnisotropicWrap(std::shared_ptr<GraphicsDevice> const& graphicsDevice);

	///@~Japanese
	/// @brief 線形フィルタリングを有効にするサンプラステートを作成します。
	/// 範囲外テクスチャ座標のアドレッシング方法は TextureAddressMode::Clamp を使用します。
	static std::shared_ptr<SamplerState>
	CreateLinearClamp(std::shared_ptr<GraphicsDevice> const& graphicsDevice);

	///@~Japanese
	/// @brief 線形フィルタリングを有効にするサンプラステートを作成します。
	/// 範囲外テクスチャ座標のアドレッシング方法は TextureAddressMode::Wrap を使用します。
	static std::shared_ptr<SamplerState>
	CreateLinearWrap(std::shared_ptr<GraphicsDevice> const& graphicsDevice);

	///@~Japanese
	/// @brief ポイントフィルタリングを有効にするサンプラステートを作成します。
	/// 範囲外テクスチャ座標のアドレッシング方法は TextureAddressMode::Clamp を使用します。
	static std::shared_ptr<SamplerState>
	CreatePointClamp(std::shared_ptr<GraphicsDevice> const& graphicsDevice);

	///@~Japanese
	/// @brief ポイントフィルタリングを有効にするサンプラステートを作成します。
	/// 範囲外テクスチャ座標のアドレッシング方法は TextureAddressMode::Wrap を使用します。
	static std::shared_ptr<SamplerState>
	CreatePointWrap(std::shared_ptr<GraphicsDevice> const& graphicsDevice);
	
public:
	Details::RenderSystem::NativeSamplerState* GetNativeSamplerState();
	
private:
	std::unique_ptr<Details::RenderSystem::NativeSamplerState> nativeSamplerState;
	SamplerDescription description;
};

///	@}
/// @}

}// namespace Pomdog

#endif // !defined(POMDOG_SAMPLERSTATE_87568CD5_37AB_4449_B4A1_3AB24A59A849_HPP)