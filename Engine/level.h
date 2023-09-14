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
//#include "gridLocation.h"
//#include "brick.h"
#include "levelParams.h"

/// <summary>
/// Store for level-related data, to be loaded in by game.cpp and such.
/// </summary>

class level
{
public:
	level(Graphics& gfx, levelParams& params);
	//level(const wall walls, std::vector<brick *> bricks, Vec2 corePos, Vec2 ballPos, Vec2 ballVel);
	void update(std::list<ball>& balls, paddle& p, const float dt);
	void draw(Graphics& gfx);
	bool isGoalsDone() const;
	bool isComplete() const;
	//template <class brickType> void addBrick(const gridLocation loc);
	template <class brickType> void addBrick(brick b);
	Vec2 getBallSpawnPos() const;
	Vec2 getBallSpawnVel() const;
	wall getWalls() const;
	Vec2 getTopLeft() const;

private:
	//Vec2 loc2pos(const gridLocation loc) const;
	brickManager brickMan;
	wall lvlWalls;
	enemyCore lvlCore;
	levelParams lvlParams;

	//Vec2 ballSpawnPos;
	//Vec2 ballSpawnVel;
};

