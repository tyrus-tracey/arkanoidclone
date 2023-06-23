#include "ball.h"

ball::ball()
	: pos(0,0)
{
	updateHitbox();
}

ball::ball(Vec2 spawnPos)
	: pos(spawnPos)
{
	updateHitbox();
}

ball::ball(Vec2 spawnPos, Vec2 ballSpeed)
	: pos(spawnPos), vel(ballSpeed)
{
	updateHitbox();
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
	updateHitbox();
	clamp(walls);
	if (collisionWalls(walls)) {
		sndRebound.StopOne();
		sndRebound.Play();
	}
}

void ball::clamp(const rect& walls)
{
	if (hitbox.left < walls.left) 
		{ pos.x = walls.left; }
	if (hitbox.right > walls.right) 
		{ pos.x = walls.right - (rad * 2.0f); }
	if (hitbox.top < walls.top) 
		{ pos.y = walls.top; }
	if (hitbox.bottom > walls.bottom) 
		{ pos.y = walls.bottom - (rad * 2.0f); }
}

void ball::updateHitbox()
{
	hitbox = rect(pos, rad * 2.0f, rad * 2.0f);
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
