#pragma once
#include "rect.h"
#include "Vec2.h"
#include "Graphics.h"
#include "SpriteCodex.h"
#include "EventManager.h"
#include "wall.h"
#include "oscillator.h"
#include "Keyboard.h"

class ball
{
public:
	ball();
	ball(const ball& other);
	ball(const Vec2 spawnPos, const float spawnGracePeriod = 2.0f);
	ball(const Vec2 spawnPos, const Vec2 velocity, const float spawnGracePeriod = 2.0f);
	void update(const wall& lvlWalls, const Keyboard& kbd, EventManager& eventmanager, float dt);
	void reset();
	void reboundX();
	void reboundY();
	void slap(const Vec2 force);
	void pushOut(const rect& bounds);
	void draw(Graphics& gfx);
	void speedSet(float spd);
	void speedReset();
	midRect hitbox() const;
	void setVelocity(Vec2 newVel);
	Vec2 getVelocity() const;
	Vec2 getPos() const;
	void lock(const Vec2 lockPos);
	void unlock();
	bool onLockCooldown() const;
	bool isLockable() const;
	void kill();
	void arm(EventManager& eventmanager);
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
	void dissipate(EventManager& eventmanager);
	void detonate(EventManager& eventmanager);
	void updateTrail();
	void drawTrail(Graphics& gfx) const;
	void drawSpawnTimer(Graphics& gfx) const;

	float rad = 7.0f;
	float radBlastFactor = 10.0f;
	Vec2 pos; //midpoint
	Vec2 vel = Vec2(1, 1).Normalize();
	bool locked = false;
	const float SPEED_DEFAULT = 500.0f;
	float speed = 500.0f;
	bool live = true;
	bool armed = false;
	static const int NUM_TRAILS = 4;
	Vec2 trail[NUM_TRAILS];

	ticker tSpawnGrace;
	oscillator oSpawnFlash = oscillator(0.1f);
	ticker tBallLockCooldown = ticker(0.25f);
	ticker tBallDissipate = ticker(0.5f);
	ticker tBallExplode = ticker(1.0f);
};

