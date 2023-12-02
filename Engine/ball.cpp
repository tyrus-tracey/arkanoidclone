#include "ball.h"

ball::ball()
	: ball({0,0})
{
}

ball::ball(const ball& other)
{
	pos = other.pos;
	vel = other.vel;
	tSpawnGrace = other.tSpawnGrace;
}

ball::ball(const Vec2 spawnPos, const float spawnGracePeriod)
	: ball(spawnPos, Vec2(1,1), spawnGracePeriod)
{
}

ball::ball(const Vec2 spawnPos, const Vec2 velocity, const float spawnGracePeriod)
	: pos(spawnPos), 
		vel(velocity.GetNormalized()),
		tSpawnGrace(spawnGracePeriod)
{
	tBallExplode.sleep();
}

void ball::slap(const Vec2 force)
{
	vel += force;
	vel.Normalize();
}

void ball::pushOut(const rect& bounds)
{
	if (!hitbox().isOverlapping(bounds) || tBallExplode.isActive()) {
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

void ball::update(const wall& lvlWalls, const Keyboard& kbd, EventManager& eventmanager, float dt)
{
	if (!live) { return; }

	if (!armed && eventmanager.flag_ClearAllBalls.isRaised()) {
		dissipate(eventmanager);
	}

	if (tBallDissipate.isActive()) {
		tBallDissipate.tick(dt);
		if (tBallDissipate.ended()) { kill(); }
		return;
	}

	if (!tSpawnGrace.ended()) {
		tSpawnGrace.wake();
		oSpawnFlash.wake();
		tSpawnGrace.tick(dt);
		oSpawnFlash.tick(dt);
		return;
	}

	updateTrail();
	if (tBallExplode.isActive()) {
		tBallExplode.tick(dt);
		if (tBallExplode.ended()) { kill(); }
		return;
	}

	if (armed && kbd.KeyIsPressed(VK_RETURN)) {
		detonate(eventmanager);
	} 
	
	if (locked) { return; }

	tBallLockCooldown.tick(dt);
	move(dt);
	clamp(lvlWalls);
	if (collisionWalls(lvlWalls)) {
		eventmanager.ballWallRebound();
	}
}

void ball::reset()
{
	speedReset();
	armed = false;
	locked = false;
	live = true;
	tSpawnGrace.resetTime();
}

void ball::move(const float dt)
{
	pos += vel * dt * speed;
}

void ball::clamp(const wall& lvlWalls)
{
	rect walls = lvlWalls.getBounds();
	if (hitbox().left < walls.left)
		{ pos.x = walls.left	+ rad; }
	if (hitbox().right > walls.right)
		{ pos.x = walls.right	- rad; }
	if (hitbox().top < walls.top)
		{ pos.y = walls.top		+ rad; }
	if (hitbox().bottom > walls.bottom) 
		{ pos.y = walls.bottom	- rad;}
}

bool ball::collisionWalls(const wall& lvlWalls)
{
	bool rebounded = false;
	rect walls = lvlWalls.getBounds();
	if (hitbox().left <= walls.left || hitbox().right >= walls.right) {
		reboundX();
		rebounded = true;
	}
	if (hitbox().top <= walls.top) {
		reboundY();
		rebounded = true;
	}
	if (hitbox().bottom >= walls.bottom) {
		kill();
	}
	return rebounded;
}

void ball::dissipate(EventManager& eventmanager)
{
	eventmanager.ballDissipate();
	tBallDissipate.wake();
}

void ball::detonate(EventManager& eventmanager)
{
	eventmanager.ballDetonate();
	tBallExplode.wake();
	if (!locked) { rad *= radBlastFactor; }	
}

void ball::updateTrail()
{
	for (int i = NUM_TRAILS-1; i > 0; i--) {
		trail[i] = trail[i - 1];
	}
	trail[0] = this->hitbox().getMidpoint();
}

void ball::drawTrail(Graphics& gfx) const
{
	for (int i = 0; i < NUM_TRAILS; i++) {
		gfx.DrawRing(int(trail[i].x), int(trail[i].y), 5, Colors::Yellow, 2, false);
	}
}

void ball::drawSpawnTimer(Graphics& gfx) const
{
	Vec2 barPos(pos.x - rad, pos.y - rad);
	barPos.y -= 4.0f;

	float p = tSpawnGrace.getPercentageRemaining();
	float timelineWidth = rad * 2.0f * p;
	rect timeline(barPos, timelineWidth, 2);

	gfx.DrawRect(timeline, Colors::White, false);
}

midRect ball::hitbox() const
{
	return midRect(pos, rad * 2.0f, rad * 2.0f);
	//return rect(pos, rad * 2.0f, rad * 2.0f);
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

Vec2 ball::getPos() const
{
	return pos;
}


void ball::lock(const Vec2 lockPos)
{
	if (locked) { return; }
	pos = lockPos;
	locked = true;
}

void ball::unlock()
{
	if (!locked) { return; }
	locked = false;
	tBallLockCooldown.restart();
}

bool ball::onLockCooldown() const
{
	return tBallLockCooldown.isActive();
}

bool ball::isLockable() const
{
	return !onLockCooldown() && !isExploding() && live;
}

void ball::kill()
{
	live = false;
	vel = { 0,0 };
}

void ball::arm(EventManager& eventmanager)
{
	if (armed) { return; }
	eventmanager.ballArmed();
	armed = true;
}

void ball::disarm()
{
	armed = false;
}

bool ball::isArmed() const
{
	return armed;
}

bool ball::isExploding() const
{
	return tBallExplode.isActive();
}

bool ball::isLive() const
{
	return live;
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
	if (tBallExplode.isActive() && locked == false) {
		gfx.DrawRing(int(pos.x), int(pos.y), rad, Colors::Red, 3, false);
		return;
	}

	if (tBallDissipate.isActive()) {
		gfx.DrawCircle(int(pos.x), int(pos.y), int(rad--), Colors::White, false);
		return;
	}

	if (live) {
		if (armed) {
			drawTrail(gfx);
			SpriteCodex::DrawBall(pos, gfx, 20);
		}
		else {
			if (!tSpawnGrace.ended()) {
				drawSpawnTimer(gfx);
				if (oSpawnFlash.isOn()) {
					SpriteCodex::DrawBall(pos, gfx, 0);
				}
			}
			else {
				SpriteCodex::DrawBall(pos, gfx, 0);
			}
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
