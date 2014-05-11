//
//  Copyright (C) 2013-2014 mogemimi.
//
//  Distributed under the MIT License.
//  See accompanying file LICENSE.md or copy at
//  http://enginetrouble.net/pomdog/LICENSE.md for details.
//

#include "AnimationState.hpp"
#include <Pomdog/Utility/Assert.hpp>
#include "AnimationClip.hpp"

namespace Pomdog {
//-----------------------------------------------------------------------
AnimationState::AnimationState(std::shared_ptr<AnimationClip> const& animationClipIn)
	: AnimationState(animationClipIn, 1, false)
{}
//-----------------------------------------------------------------------
AnimationState::AnimationState(std::shared_ptr<AnimationClip> const& animationClipIn, float playbackRateIn, bool loopIn)
	: clip(animationClipIn)
	, playbackRate(playbackRateIn)
	, enabled(true)
	, loop(loopIn)
{
}
//-----------------------------------------------------------------------
std::shared_ptr<AnimationClip> const& AnimationState::Clip() const
{
	return clip;
}
//-----------------------------------------------------------------------
DurationSeconds AnimationState::Time() const
{
	return time;
}
//-----------------------------------------------------------------------
void AnimationState::Time(DurationSeconds const& timeIn)
{
	POMDOG_ASSERT(timeIn.count() >= 0);
	this->time = timeIn;
}
//-----------------------------------------------------------------------
DurationSeconds AnimationState::Length() const
{
	return clip->Length();
}
//-----------------------------------------------------------------------
float AnimationState::PlaybackRate() const
{
	return playbackRate;
}
//-----------------------------------------------------------------------
void AnimationState::PlaybackRate(float playbackRateIn)
{
	this->playbackRate = playbackRateIn;
}
//-----------------------------------------------------------------------
bool AnimationState::Enabled() const
{
	return enabled;
}
//-----------------------------------------------------------------------
void AnimationState::Enabled(bool enabledIn)
{
	this->enabled = enabledIn;
}
//-----------------------------------------------------------------------
bool AnimationState::Loop() const
{
	return loop;
}
//-----------------------------------------------------------------------
void AnimationState::Loop(bool LoopIn)
{
	this->loop = LoopIn;
}
//-----------------------------------------------------------------------
}// namespace Pomdog
