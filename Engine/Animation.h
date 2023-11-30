#pragma once
#include "Graphics.h"
#include "SpriteCodex.h"
#include "Vec2.h"
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
	animBrickExplode(const Vec2 _pos, const Color _c);
	void update(const float dt);
	void draw(Graphics& gfx) const;
private:
	float yVel = -15.0f;
	const float GRAVITY = 100.0f;
	const float SIDEFORCE = 150.0f;
	const Color c;
	Vec2 chunks[4];
};

class animBrickCrush : public Animation
{
public:
	animBrickCrush(const Vec2 _pos, const Color _c);
	void update(const float dt);
	void draw(Graphics& gfx) const;
private:
	const Color c;
	const float FORCE = 300.0f;
	Vec2 chunks[4]; // [0] topLeft, [1] topRight, [2] botLeft, [3] botRight
};