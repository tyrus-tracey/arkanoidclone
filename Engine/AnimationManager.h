#pragma once
#include <list>
#include "Animation.h"
#include "Soundbank.h"


class AnimationManager
{
public:
	AnimationManager(Soundbank& _soundbank);
	AnimationManager(const AnimationManager& other);
	AnimationManager& operator=(const AnimationManager& other);
	~AnimationManager();
	void update(float dt);
	void draw(Graphics& gfx) const;
	void createAnimTitleScreen(const Graphics& gfx);
	void createAnimBrickExplode(const Vec2 pos, const Color c);
	void createAnimBrickCrush(const Vec2 pos, const Color c);
	void createAnimCoreExplode(const Vec2 pos, const float rad);
	bool noAnimsRunning() const;
	void clearAnims();

private:
	std::list<Animation*> animations;
	Soundbank& soundbank;
};

