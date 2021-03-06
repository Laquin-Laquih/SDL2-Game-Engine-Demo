#ifndef ANIMATIONCOMPONENT_HPP
#define ANIMATIONCOMPONENT_HPP

#include <string>
#include <map>
#include <memory>
#include <string>

#include "VisibleComponent.hpp"

struct Rectangle;

class AnimationComponent : public VisibleComponent, public std::enable_shared_from_this<AnimationComponent>
{
	struct Animation
	{
		int index;
		int frames;
		int speed;

		Animation() = default;
		Animation(int index, int frames, int speed);
	};

public:
	AnimationComponent() = default;
	AnimationComponent(const std::string& path, const Rectangle& srcRect);

	AnimationComponent& update() override;
	AnimationComponent& play(const std::string& str) override;
	AnimationComponent& add_animation(const std::string& str, const Animation& anim);

private:

	int animationIndex;
	int speed;
	int frames;

	std::map<const std::string, Animation> animations;
};

#endif