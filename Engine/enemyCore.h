#pragma once
#include <list>
#include "SpriteCodex.h"
#include "Soundbank.h"
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
	void update(std::list<ball>& balls, Soundbank& soundbank, const float dt);
	void draw(Graphics& gfx);
	void releaseBall();
	void startExplode();
	bool isLive() const;
	bool isExploding() const;
	bool hasBall() const;
	ball* getBall() const;
	void operator=(enemyCore& other);
	static constexpr float SPAN = 40.0f;
	static constexpr float COREMARGIN = -1.0f;

private:
	void eatBall();
	void lockBall(ball* b);
	void explode(Soundbank& soundbank);
	void kill();
	Vec2 getRandDiagonal();

private:
	Vec2 pos;
	ball* heldBall = nullptr;
	bool live = true;

	ticker tBallHoldTime = ticker(0.75f);
	ticker tDeathAnimTime = ticker(2.0f);
	ticker tMiniExplosionTime = ticker(0.05f);
	std::mt19937 rng;
	std::uniform_int_distribution<int> dirDist = std::uniform_int_distribution<int>(0, 3);
	std::uniform_int_distribution<int> boomX = std::uniform_int_distribution<int>(0, int(SPAN));
	std::uniform_int_distribution<int> boomY = std::uniform_int_distribution<int>(0, int(SPAN));
	int xdeviation = 0;
	int ydeviation = 0;
};

