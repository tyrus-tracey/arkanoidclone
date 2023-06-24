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
	void draw(Graphics& gfx);
	rect hitbox() const;

private:
	void clamp(const rect& walls);
	bool collisionWalls(const rect& walls);

	Vec2 pos; //top-left
	Vec2 vel = Vec2(10, 10);
	float speed = 30.0f;
	float rad = 7.0f;
	Sound sndRebound = Sound(L"Sounds\\arkbrick.wav");
};

