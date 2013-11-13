//
//  Copyright (C) 2013 mogemimi.
//
//  Distributed under the MIT License.
//  See accompanying file LICENSE.md or copy at
//  http://enginetrouble.net/pomdog/LICENSE.md for details.
//

#include "GameObject.hpp"

namespace Pomdog {

GameObject::GameObject(std::int32_t instanceID)
	: instanceID(instanceID)
{}
//-----------------------------------------------------------------------
GameObject::GameObject(std::int32_t instanceID, std::size_t minimumCapacity)
	: instanceID(instanceID)
{
	components.reserve(minimumCapacity);
}
//-----------------------------------------------------------------------
std::int32_t GameObject::GetInstanceID() const {
	return instanceID;
}

}// namespace Pomdog