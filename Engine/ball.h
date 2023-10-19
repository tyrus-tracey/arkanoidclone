#pragma once
#include "rect.h"
#include "Vec2.h"
#include "Graphics.h"
#include "SpriteCodex.h"
#include "EventManager.h"
#include "wall.h"
#include "ticker.h"
#include "Keyboard.h"

class ball
{
public:
	ball();
	ball(const ball& other);
	ball(Vec2 spawnPos);
	ball(Vec2 spawnPos, Vec2 velocity);
	void update(const wall& lvlWalls, const Keyboard& kbd, EventManager& eventmanager, float dt);
	void reset();
	void reboundX();
	void reboundY();
	void slap(const Vec2 force);
	void pushOut(const rect& bounds);
	void draw(Graphics& gfx);
	void speedSet(float spd);
	void speedReset();
	rect hitbox() const;
	void setVelocity(Vec2 newVel);
	Vec2 getVelocity() const;
	Vec2 getPos() const;
	void lock(const Vec2 lockPos);
	void unlock();
	bool onLockCooldown() const;
	void kill();
	void arm();
	void disarm();
	bool isArmed() const;
	bool isExploding() const;
	bool isLive() const;
public:
	void operator=(const ball& other);

private:
	void move(const float dt);
	void clamp(const wall& lvlWalls);
	bool collisionWalls(const wall& lvlWalls);
	void detonate(EventManager& eventmanager);

	Vec2 pos; //top-left
	Vec2 vel = Vec2(1, 1).Normalize();
	bool locked = false;
	const float SPEED_DEFAULT = 500.0f;
	float speed = 500.0f;
	float rad = 7.0f;
	bool live = true;
	bool armed = false;

	ticker tSpawnGrace = ticker(2.0f);
	ticker tBallLockCooldown = ticker(0.25f);
	ticker tBallExplode = ticker(1.0f);
};

