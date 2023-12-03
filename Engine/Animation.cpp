#include "Animation.h"

Animation::Animation(const Vec2 _pos, const float _lifetime)
	: pos(_pos), lifetime(_lifetime)
{
	lifetime.wake();
}

animBrickExplode::animBrickExplode(const Vec2 _pos, const Color _c)
	: Animation(_pos, LIFETIME), c(_c)
{
	flash.wake();
	chunks[0] = _pos;
	chunks[1] = _pos;
	chunks[2] = _pos;
	chunks[3] = _pos;
}

void animBrickExplode::update(const float dt)
{
	lifetime.tick(dt);
	flash.tick(dt);

	yVel += (GRAVITY * dt);
	for (int i = 0; i < 4; i++) {
		chunks[i].y += yVel;
	}

	chunks[0].x += (-SIDEFORCE		* dt);
	chunks[1].x += (-SIDEFORCE/2.0f * dt);
	chunks[2].x += (SIDEFORCE/2.0f	* dt);
	chunks[3].x += (SIDEFORCE		* dt);
}

void animBrickExplode::draw(Graphics& gfx) const
{
	if (flash.isOn()) {
		for (const Vec2 chunk : chunks) { SpriteCodex::DrawBrickChunk(chunk, c, gfx); }
	}
}

animBrickCrush::animBrickCrush(const Vec2 _pos, const Color _c)
	: Animation(_pos, LIFETIME), c(_c)
{
	flash.wake();
	chunks[0] = _pos;
	chunks[1] = _pos;
	chunks[2] = _pos;
	chunks[3] = _pos;
}

void animBrickCrush::update(const float dt)
{
	lifetime.tick(dt);
	flash.tick(dt);
	if (lifetime.getTimeElapsed() < MOVETIME) {
		chunks[0] += (Vec2(-FORCE, -FORCE) * dt);
		chunks[1] += (Vec2(	FORCE, -FORCE) * dt);
		chunks[2] += (Vec2(-FORCE,	FORCE) * dt);
		chunks[3] += (Vec2(	FORCE,	FORCE) * dt);
	}
}

void animBrickCrush::draw(Graphics& gfx) const
{
	if (lifetime.getTimeElapsed() < MOVETIME || flash.isOn()) {
		for (const Vec2& chunk : chunks) { SpriteCodex::DrawBrickChunk(chunk, c, gfx); }
	}
}

animCoreExplode::animCoreExplode(const Vec2 _pos, const float _rad)
	: Animation(_pos, LIFETIME), RAD_BIG(_rad), RAD_SMALL(RAD_BIG * 0.9f)
{
	pulse.wake();
}

void animCoreExplode::update(const float dt)
{
	lifetime.tick(dt);
	pulse.tick(dt);
}

void animCoreExplode::draw(Graphics& gfx) const
{
	float drawRad = pulse.isOn() ? RAD_BIG : RAD_SMALL;
	gfx.DrawCircle(pos.x, pos.y, drawRad, cInner, false);
	gfx.DrawRing(pos.x, pos.y, drawRad, cOuter, INNER_MARGIN, false);
}
