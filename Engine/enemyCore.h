#pragma once
#include "SpriteCodex.h"
#include "Vec2.h"
#include "ball.h"
#include "rect.h"
#include "ticker.h"
#include <random>

class enemyCore
{
public:
	enemyCore() = default;
	enemyCore(Vec2 corePos);
	rect hitbox() const;
	rect hitboxCore() const;
	void update(ball* b, const float dt);
	void lockBall(ball* b);
	void releaseBall();
	void eatBall();
	void explode();
	void kill();
	bool isLive() const;
	bool hasBall() const;
	void draw(Graphics& gfx);
	void operator=(enemyCore& other);
private:
	Vec2 getRandDiagonal();

private:
	Vec2 pos;
	ball* heldBall = nullptr;
	const float SPAN = 40.0f;
	const float COREMARGIN = -1.0f;
	bool live = true;

	ticker tBallHoldTime = ticker(0.75f);
	ticker tDeathAnimTime = ticker(2.0f);
	std::mt19937 rng;
	std::uniform_int_distribution<int> dirDist = std::uniform_int_distribution<int>(0, 3);
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;
};

