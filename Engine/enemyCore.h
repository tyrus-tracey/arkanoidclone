#pragma once
#include <list>
#include "SpriteCodex.h"
#include "EventManager.h"
#include "Vec2.h"
#include "ball.h"
#include "rect.h"
#include "ticker.h"
#include <random>

const enum Diagonal { TL, TR, BR, BL };

class enemyCore
{
public:
	enemyCore() = default;
	enemyCore(const enemyCore& other);
	enemyCore(Vec2 corePos);
	rect hitbox() const;
	rect hitboxCore() const;
	void update(std::list<ball>& balls, EventManager& eventmanager, const float dt);
	void draw(Graphics& gfx);
	void releaseBall(EventManager& eventmanager);
	void startExplode(EventManager& eventmanager);
	bool isLive() const;
	bool isExploding() const;
	bool hasBall() const;
	ball* getBall() const;
	void operator=(enemyCore& other);
	static constexpr float SPAN = 40.0f;
	static constexpr float COREMARGIN = -1.0f;

private:
	void eatBall();
	void lockBall(ball* b, EventManager& eventmanager);
	void explode(EventManager& eventManager);
	void kill();
	Vec2 getRandDiagonal();
	void incrementDiagonal();

private:
	Vec2 pos;
	Diagonal diagonal = TL;
	ball* heldBall = nullptr;
	bool live = true;

	ticker tIdleAnimInterval = ticker(1.0f);
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



//int pos2index(const Position p) {
//	switch (p) {
//	case TL: return 0;
//	case TR: return 1;
//	case BR: return 2;
//	case BL: return 3;
//	default: return 0;
//	}
//}
//
//Position index2pos(const int i) {
//	switch (i) {
//	case 0: return TL;
//	case 1: return TR;
//	case 2: return BR;
//	case 3: return BL;
//	default: return TL;
//	}
//}