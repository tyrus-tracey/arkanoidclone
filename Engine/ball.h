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
	void update(const rect& walls, float dt);
	void slap(const Vec2 force);
	void draw(Graphics& gfx);

private:
	void clamp(const rect& walls);
	bool collisionWalls(const rect& walls);
	void reboundX();
	void reboundY();

	Vec2 pos; //top-left
	Vec2 vel;
	float speed = 30.0f;
	float rad = 7.0f;
	rect hitbox;
	Sound sndRebound = Sound(L"Sounds\\arkbrick.wav");
};

