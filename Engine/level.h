#pragma once
#include <vector>
#include <type_traits>
#include "Graphics.h"
#include "Vec2.h"
#include "brickManager.h"
#include "wall.h"
#include "enemyCore.h"
#include "ball.h"
#include "paddle.h"
#include "Soundbank.h"
#include "levelParams.h"
#include "ticker.h"

/// <summary>
/// Store for level-related data, to be loaded in by game.cpp and such.
/// </summary>

class level
{
public:
	level(Graphics& gfx);
	level(Graphics& gfx, levelParams& params);
	void update(std::list<ball>& balls, paddle& p, Soundbank& soundbank, const float dt);
	void draw(Graphics& gfx);
	bool isGoalsDone() const;
	bool isComplete() const;
	bool isCoreExploding() const;
	bool isCoreHoldingArmedBall() const;
	Vec2 getBallSpawnPos() const;
	Vec2 getBallSpawnVel() const;
	wall getWalls() const;
	Vec2 getTopLeft() const;

private:
	void initBallSpawnPos();
	levelParams lvlParams;
	wall lvlWalls;
	enemyCore lvlCore;
	brickManager brickMan;
	ticker tLevelCompleteWait = ticker(3.0f);
};

