#pragma once
#include <list>
#include "SpriteCodex.h"
#include "ticker.h"

class Animation
{
public:
	Animation(const Vec2 _pos, const float _lifetime);
	virtual void update(const float dt) = 0;
	virtual void draw(Graphics& gfx) const = 0;
	bool isLive() const { return !lifetime.ended(); }

protected:
	Vec2 pos;
	ticker lifetime;
};

class animBrickExplode : public Animation
{
public:
	animBrickExplode(const Vec2 _pos, const Color _c, const float _lifetime);
	void update(const float dt);
	void draw(Graphics& gfx) const;
private:
	Vec2 vel{ 0.0f, -10.0f };
	const Vec2 GRAVITY = { 0, 50.0f };
	const Color c;
};

class AnimationManager
{
public:
	AnimationManager();
	AnimationManager(const AnimationManager& other);
	AnimationManager& operator=(const AnimationManager& other);
	~AnimationManager();
	void update(float dt);
	void draw(Graphics& gfx) const;
	void testCreateAnim(const Vec2 pos, const Color c);

private:
	void clearAnims();
	std::list<Animation*> animations;
};

