#pragma once
#include "Graphics.h"
#include "SpriteCodex.h"
#include "Vec2.h"
#include "oscillator.h"

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
	static constexpr float LIFETIME = 1.0f;
	static constexpr float GRAVITY = 100.0f;
	static constexpr float SIDEFORCE = 200.0f;
	float yVel = -15.0f;
	const Color c;
	Vec2 chunks[4];
	oscillator flash = oscillator(0.05f);
};

class animBrickCrush : public Animation
{
public:
	animBrickCrush(const Vec2 _pos, const Color _c);
	void update(const float dt);
	void draw(Graphics& gfx) const;
private:
	static constexpr float LIFETIME = 0.3f;
	static constexpr float MOVETIME = 0.2f;
	static constexpr float FORCE = 300.0f;
	const Color c;
	Vec2 chunks[4]; // [0] topLeft, [1] topRight, [2] botLeft, [3] botRight
	oscillator flash = oscillator(0.05f);
};