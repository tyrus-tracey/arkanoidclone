#include "ball.h"

ball::ball()
	: ball({0,0})
{
}

ball::ball(Vec2 spawnPos)
	: ball(spawnPos, Vec2(1,1))
{
}

ball::ball(Vec2 spawnPos, Vec2 ballSpeed)
	: pos(spawnPos), spawn_pos(pos), vel(ballSpeed.GetNormalized()), 
		spawn_vel(vel), tSpawnGrace(2.0f), tBallLockCooldown(0.25f)
{
	tSpawnGrace.reset();
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

void ball::update(const wall& lvlWalls, const Keyboard& kbd, float dt)
{
	tBallExplode.tick(dt);
	if (!live) { return; }	
	if (tSpawnGrace.isActive()) {
		tSpawnGrace.tick(dt);
		return;
	}

	if (fuelFull() && kbd.KeyIsPressed(VK_RETURN)) {
		detonate();
	}
	
	if (locked) { return; }

	tBallLockCooldown.tick(dt);
	move(dt);
	clamp(lvlWalls);
	if (collisionWalls(lvlWalls)) {
		sndRebound.StopOne();
		sndRebound.Play();
	}
}

void ball::reset()
{
	pos = spawn_pos;
	vel = spawn_vel;
	speedReset();
	locked = false;
	live = true;
	tSpawnGrace.reset();
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
		{ pos.y = walls.bottom - (rad * 2.0f);}
}

bool ball::collisionWalls(const wall& lvlWalls)
{
	bool rebounded = false;
	rect walls = lvlWalls.getBounds();
	if (pos.x <= walls.left || pos.x + (rad * 2.0f) >= walls.right) {
		reboundX();
		rebounded = true;
	}
	if (pos.y <= walls.top) {
		reboundY();
		rebounded = true;
	}
	if (pos.y + (rad * 2.0f) >= walls.bottom) {
		kill();
	}
	return rebounded;
}

void ball::detonate()
{
	tBallExplode.reset();
	kill();
}

rect ball::hitbox() const
{
	return rect(pos, rad * 2.0f, rad * 2.0f);
}

void ball::setVelocity(Vec2 newVel)
{
	if (tSpawnGrace.isActive()) { return; }
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
	tBallLockCooldown.reset();
}

bool ball::onLockCooldown() const
{
	return tBallLockCooldown.isActive();
}

void ball::kill()
{
	live = false;
	vel = { 0,0 };
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

bool ball::isExploding() const
{
	return tBallExplode.isActive();
}

void ball::operator=(const ball& other)
{
	pos = other.pos;
	spawn_pos = other.spawn_pos;
	vel = other.vel;
	spawn_vel = other.spawn_vel;
	speed = other.speed;
	live = other.live;
}

void ball::draw(Graphics& gfx)
{
	if (tBallExplode.isActive() && locked == false) {
		gfx.DrawRing(int(hitbox().getMidpoint().x), int(hitbox().getMidpoint().y), 20, Colors::Red, 3, false);
	}
	if (live) {
		if (fuelFull()) {
			SpriteCodex::DrawBall(pos + Vec2(rad, rad), gfx, 20);
		}
		else {
			SpriteCodex::DrawBall(pos + Vec2(rad, rad), gfx, 0);
		}
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
