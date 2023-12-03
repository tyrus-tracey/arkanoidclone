#pragma once
#include <list>
#include "Animation.h"


class AnimationManager
{
public:
	AnimationManager();
	AnimationManager(const AnimationManager& other);
	AnimationManager& operator=(const AnimationManager& other);
	~AnimationManager();
	void update(float dt);
	void draw(Graphics& gfx) const;
	void createAnimBrickExplode(const Vec2 pos, const Color c);
	void createAnimBrickCrush(const Vec2 pos, const Color c);
	void createAnimCoreExplode(const Vec2 pos, const float rad);

private:
	void clearAnims();
	std::list<Animation*> animations;
};

