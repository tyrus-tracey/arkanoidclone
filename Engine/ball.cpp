#include "ball.h"

ball::ball()
	: pos(0,0)
{
}

ball::ball(Vec2 spawnPos)
	: pos(spawnPos)
{
}

ball::ball(Vec2 spawnPos, Vec2 ballSpeed)
	: pos(spawnPos), vel(ballSpeed.GetNormalized())
{
}

void ball::slap(const Vec2 force)
{
	vel += force;
	vel.Normalize();
}

void ball::pushOut(const rect& bounds)
{
	if (!hitbox().isOverlapping(bounds)) {
		return;
	}
	Vec2 left(bounds.left - hitbox().right, 0.0f);
	Vec2 right(bounds.right - hitbox().left, 0.0f);
	Vec2 up(0.0f, bounds.top - hitbox().bottom);
	Vec2 down(0.0f, bounds.bottom - hitbox().top);
	Vec2 minPush = left;
	Vec2 dirs[4] = { left, right, up, down };

	for (int i = 1; i < 4; i++) {
		if (dirs[i].GetLengthSq() < minPush.GetLengthSq()) {
			minPush = dirs[i];
		}
	}
	pos += minPush;
}

void ball::reboundX()
{
	vel.x *= -1.0f;
}

void ball::reboundY()
{
	vel.y *= -1.0f;
}

void ball::update(const wall& lvlWalls, float dt)
{
	if (!live) { return; }	
	if (locked) { return; }

	if (onLockCooldown()) { tickLockCooldown(dt); }
	move(dt);
	clamp(lvlWalls);
	if (collisionWalls(lvlWalls)) {
		sndRebound.StopOne();
		sndRebound.Play();
	}
}

void ball::move(const float dt)
{
	pos += vel * dt * speed;
}

void ball::clamp(const wall& lvlWalls)
{
	rect walls = lvlWalls.getBounds();
	if (hitbox().left < walls.left)
		{ pos.x = walls.left; }
	if (hitbox().right > walls.right)
		{ pos.x = walls.right - (rad * 2.0f); }
	if (hitbox().top < walls.top)
		{ pos.y = walls.top; }
	if (hitbox().bottom > walls.bottom)
		{ pos.y = walls.bottom - (rad * 2.0f); }
}

void ball::tickLockCooldown(const float dt)
{
	if (lockCooldown < 0.0001f) {
		locked = false;
		return;
	}
	lockCooldown -= dt;
}

bool ball::collisionWalls(const wall& lvlWalls)
{
	bool rebounded = false;
	rect walls = lvlWalls.getBounds();
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

rect ball::hitbox() const
{
	return rect(pos, rad * 2.0f, rad * 2.0f);
}

void ball::setVelocity(Vec2 newVel)
{
	newVel.Normalize();
	vel = newVel;
}

Vec2 ball::getVelocity() const
{
	return vel;
}


void ball::lock(const Vec2 lockPos)
{
	if (locked) { return; }
	locked = true;
	Vec2 centerOffset(lockPos.x - rad, lockPos.y - rad);
	pos = centerOffset;
}

void ball::unlock()
{
	if (!locked) { return; }
	locked = false;
	lockCooldown = LOCK_COOLDOWN_DEFAULT;
}

bool ball::onLockCooldown() const
{
	return lockCooldown > 0.0001f;
}

void ball::kill()
{
	live = false;
}

void ball::fuelAdd(unsigned int amt)
{
	if (!fuelFull()) {
		fuel += amt;
	}
}

bool ball::fuelFull() const
{
	return fuel > FUEL_MAX;
}

void ball::operator=(const ball& other)
{
	pos = other.pos;
	vel = other.vel;
	speed = other.speed;
	live = other.live;
}

void ball::draw(Graphics& gfx)
{
	if (!live) { return; }
	if (fuelFull()) {
		SpriteCodex::DrawBall(pos + Vec2(rad, rad), gfx, 20);
	}
	else {
		SpriteCodex::DrawBall(pos + Vec2(rad, rad), gfx, 0);
	}
}

void ball::speedSet(float spd)
{
	speed = spd;
}

void ball::speedReset()
{
	speed = SPEED_DEFAULT;
}
