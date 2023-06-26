#pragma once
#include "rect.h"
#include "Vec2.h"
#include "Graphics.h"
#include "SpriteCodex.h"
#include "Sound.h"

class ball
{
public:
	ball();
	ball(Vec2 spawnPos);
	ball(Vec2 spawnPos, Vec2 ballSpeed);
	void update(const rect& walls, float dt);
	void reboundX();
	void reboundY();
	void slap(const Vec2 force);
	void pushOut(const rect& bounds);
	void draw(Graphics& gfx);
	void speedSet(float spd);
	void speedReset();
	rect hitbox() const;
	Vec2 getVelocity() const;

private:
	void clamp(const rect& walls);
	bool collisionWalls(const rect& walls);

	Vec2 pos; //top-left
	Vec2 vel = Vec2(1, 1).Normalize();
	float SPEED_DEFAULT = 500.0f;
	float speed = 500.0f;
	float rad = 7.0f;
	Sound sndRebound = Sound(L"Sounds\\arkbrick.wav");
};

