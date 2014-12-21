﻿//
//  Copyright (C) 2013-2014 mogemimi.
//  Distributed under the MIT License. See LICENSE.md or
//  http://enginetrouble.net/pomdog/license for details.
//

#include "Pomdog/Platform/Win32/BootstrapperWin32.hpp"
#include "GameHostWin32.hpp"
#include "GameWindowWin32.hpp"
#include "../InputSystem.DirectInput/DeviceContextDirectInput.hpp"
#include "../InputSystem.DirectInput/KeyboardCreatorDirectInput.hpp"
#include "../InputSystem.DirectInput/MouseCreatorDirectInput.hpp"
#include "../InputSystem/InputDeviceFactory.hpp"
#include "../RenderSystem/PresentationParameters.hpp"
#include "Pomdog/Application/GameHost.hpp"
#include "Pomdog/Logging/Log.hpp"

namespace Pomdog {
namespace Details {
namespace Win32 {
//-----------------------------------------------------------------------
BootstrapperWin32::BootstrapperWin32(BootstrapSettingsWin32 const& settingsIn)
	: settings(settingsIn)
{}
//-----------------------------------------------------------------------
void BootstrapperWin32::Run(std::function<void(std::shared_ptr<GameHost> const& gameHost)> const& runGame)
{
	Details::RenderSystem::PresentationParameters presentationParameters;
	presentationParameters.BackBufferHeight = settings.Height;
	presentationParameters.BackBufferWidth = settings.Width;
	presentationParameters.DepthFormat = DepthFormat::Depth24Stencil8;
	presentationParameters.IsFullScreen = settings.IsFullscreen;

	auto systemEventDispatcher = std::make_shared<SystemEventDispatcher>();

	auto gameWindow = std::make_shared<GameWindowWin32>(settings.HInstance, settings.CmdShow, settings.Icon, settings.IconSmall,
		systemEventDispatcher, presentationParameters);

	auto inputDeviceFactory = std::make_unique<Details::InputSystem::InputDeviceFactory>();
	
	{
		using namespace Details::InputSystem::DirectInput;
		auto deviceContext = std::make_shared<DeviceContextDirectInput>(
			settings.HInstance, gameWindow->NativeWindowHandle());

		auto keyboardCreator = std::make_unique<KeyboardCreatorDirectInput>(deviceContext);
		inputDeviceFactory->AddCreator(std::move(keyboardCreator));

		auto mouseCreator = std::make_unique<MouseCreatorDirectInput>(deviceContext);
		inputDeviceFactory->AddCreator(std::move(mouseCreator));
	}

	auto gameHost = std::make_shared<GameHostWin32>(gameWindow,
		systemEventDispatcher, presentationParameters, std::move(inputDeviceFactory));

	POMDOG_ASSERT(runGame);
	runGame(gameHost);

	gameHost.reset();
	gameWindow.reset();
}
//-----------------------------------------------------------------------
}// namespace Win32
}// namespace Details
}// namespace Pomdog