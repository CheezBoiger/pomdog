﻿//
//  Copyright (C) 2013-2014 mogemimi.
//
//  Distributed under the MIT License.
//  See accompanying file LICENSE.md or copy at
//  http://enginetrouble.net/pomdog/LICENSE.md for details.
//

#ifndef POMDOG_SUBSCRIBEREQUESTDISPATCHER_B5E9A001_3318_45C5_B257_51344C2E2F36_HPP
#define POMDOG_SUBSCRIBEREQUESTDISPATCHER_B5E9A001_3318_45C5_B257_51344C2E2F36_HPP

#if (_MSC_VER > 1000)
#	pragma once
#endif

#include <memory>
#include <vector>
#include <utility>

namespace Pomdog {
namespace UI {

class UIElement;

namespace Details {

class SubscribeRequestDispatcher {
public:
	void AddChild(std::shared_ptr<UIElement> const& child)
	{
		Added.push_back(child);
	}
	
	void AddChild(std::shared_ptr<UIElement> && child)
	{
		Added.push_back(std::move(child));
	}

	void RemoveChild(std::weak_ptr<UIElement> const& child)
	{
		POMDOG_ASSERT(!child.expired());
		Removed.push_back(child);
	}

	std::vector<std::shared_ptr<UIElement>> Added;
	std::vector<std::weak_ptr<UIElement>> Removed;
};

}// namespace Details
}// namespace UI
}// namespace Pomdog

#endif // !defined(POMDOG_SUBSCRIBEREQUESTDISPATCHER_B5E9A001_3318_45C5_B257_51344C2E2F36_HPP)