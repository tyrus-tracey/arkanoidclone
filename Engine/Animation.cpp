#include "Animation.h"

animBrickExplode::animBrickExplode(const Vec2 _pos, const Color _c, const float _lifetime)
	: Animation(_pos, _lifetime), c(_c)
{
	lifetime.wake();
}

void animBrickExplode::update(const float dt)
{
	lifetime.tick(dt);
	vel += (GRAVITY * dt);
	pos += vel;
}

void animBrickExplode::draw(Graphics& gfx) const
{
	SpriteCodex::DrawBrickChunk(pos, c, gfx);
}

Animation::Animation(const Vec2 _pos, const float _lifetime)
	: pos(_pos), lifetime(_lifetime)
{
}