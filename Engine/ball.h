#pragma once
#include "rect.h"
#include "Vec2.h"
#include "Graphics.h"
#include "SpriteCodex.h"
#include "Sound.h"
#include "wall.h"

class ball
{
public:
	ball();
	ball(Vec2 spawnPos);
	ball(Vec2 spawnPos, Vec2 ballSpeed);
	void update(const wall& lvlWalls, float dt);
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
	void lock(const Vec2 lockPos);
	void unlock();
	bool onLockCooldown() const;
	void kill();
	void fuelAdd(unsigned int amt);
	bool fuelFull() const;
public:
	void operator=(const ball& other);

private:
	void move(const float dt);
	void clamp(const wall& lvlWalls);
	void tickLockCooldown(const float dt);
	bool collisionWalls(const wall& lvlWalls);

	Vec2 pos; //top-left
	Vec2 vel = Vec2(1, 1).Normalize();
	bool locked = false;
	const float SPEED_DEFAULT = 500.0f;
	float speed = 500.0f;
	float rad = 7.0f;
	bool live = true;

	unsigned int fuel = 0;
	const unsigned int FUEL_MAX = 100;

	float lockCooldown = 0.0f;
	const float LOCK_COOLDOWN_DEFAULT = 0.25f;
	Sound sndRebound = Sound(L"Sounds\\arkbrick.wav");
};

