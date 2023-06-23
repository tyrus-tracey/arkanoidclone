#include "ball.h"

ball::ball()
	: pos(0,0), hitbox(rect(pos, rad * 2.0f, rad * 2.0f))
{
}

ball::ball(Vec2 spawnPos)
	: pos(spawnPos), hitbox(rect(pos, rad * 2.0f, rad * 2.0f))
{
}

ball::ball(Vec2 spawnPos, Vec2 ballSpeed)
	: pos(spawnPos), vel(ballSpeed), hitbox(rect(pos, rad * 2.0f, rad * 2.0f))
{
}

void ball::slap(const Vec2 force)
{
	vel += force;
}

void ball::reboundX()
{
	vel.x *= -1.0f;
}

void ball::reboundY()
{
	vel.y *= -1.0f;
}

void ball::update(const rect& walls, float dt)
{
	pos += vel * dt * speed;
	clamp(walls);
	if (collisionWalls(walls)) {
		sndRebound.StopOne();
		sndRebound.Play();
	}
}

void ball::clamp(const rect& walls)
{
	if (pos.x < walls.left) 
		{ pos.x = walls.left; }
	if (pos.x + (rad * 2.0f) > walls.right) 
		{ pos.x = walls.right - (rad * 2.0f); }
	if (pos.y < walls.top) 
		{ pos.y = walls.top; }
	if (pos.y + (rad * 2.0f) > walls.bottom) 
		{ pos.y = walls.bottom - (rad * 2.0f); }
}

bool ball::collisionWalls(const rect& walls)
{
	bool rebounded = false;
	if (pos.x <= walls.left || pos.x + (rad * 2.0f) >= walls.right) {
		reboundX();
		rebounded = true;
	}
	if (pos.y <= walls.top || pos.y + (rad * 2.0f) >= walls.bottom) {
		reboundY();
		rebounded = true;
	}
	return rebounded;
}

void ball::draw(Graphics& gfx)
{
	SpriteCodex::DrawBall(pos + Vec2(rad,rad), gfx);
}

rect ball::getHitbox() const
{
	return hitbox;
}
