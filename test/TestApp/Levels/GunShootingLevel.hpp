//
//  Copyright (C) 2013-2014 mogemimi.
//
//  Distributed under the MIT License.
//  See accompanying file LICENSE.md or copy at
//  http://enginetrouble.net/pomdog/LICENSE.md for details.
//

#ifndef POMDOG_GUNSHOOTINGLEVEL_2CB60E26_E685_4FB0_9BCE_E28C699DE2AE_HPP
#define POMDOG_GUNSHOOTINGLEVEL_2CB60E26_E685_4FB0_9BCE_E28C699DE2AE_HPP

#if (_MSC_VER > 1000)
#	pragma once
#endif

#include <Pomdog/Pomdog.hpp>
#include "../2D/GameLevel.hpp"
#include "../Skeletal2D/Skeleton.hpp"
#include "../Skeletal2D/AnimationGraph.hpp"
#include "../Skeletal2D/SkinnedMesh.hpp"

namespace TestApp {

using namespace Pomdog;

class GunShootingLevel final: public GameLevel {
public:
	GunShootingLevel(GameHost & gameHost, GameWorld & world);
	
	void Update(GameHost & gameHost, GameWorld & world) override;
	
private:
	GameObject mainCamera;
	GameObject maid;
	GameObject lightningBeam;
	DurationSeconds spawnTime;
	
	std::shared_ptr<Skeleton> ghostSkeleton;
	std::shared_ptr<AnimationGraph> ghostAnimGraph;
	std::shared_ptr<Texture2D> ghostTexture;
	std::shared_ptr<SkinnedMesh> ghostMesh;
};

}// namespace TestApp

#endif // !defined(POMDOG_GUNSHOOTINGLEVEL_2CB60E26_E685_4FB0_9BCE_E28C699DE2AE_HPP)