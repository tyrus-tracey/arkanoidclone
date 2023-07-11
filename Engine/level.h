#pragma once
#include <vector>
#include "Graphics.h"
#include "Vec2.h"
#include "brickManager.h"
#include "wall.h"
#include "enemyCore.h"
#include "ball.h"
#include "paddle.h"

/// <summary>
/// Store for level-related data, to be loaded in by game.cpp and such.
/// </summary>
class level
{
public:
	level();
	level(const wall walls, Vec2 corePos);
	level(const wall walls, Vec2 corePos, Vec2 ballPos, Vec2 ballVel);
	void update(ball& b, paddle& p, const float dt);
	void draw(Graphics& gfx);
	bool isComplete() const;
	void addBrick(const brick& b);
	Vec2 getBallSpawnPos() const;
	Vec2 getBallSpawnVel() const;
	wall getWalls() const;
	Vec2 getTopLeft() const;

private:
	enemyCore lvlCore;
	brickManager brickMngr;
	wall lvlWalls;
	Vec2 ballSpawnPos;
	Vec2 ballSpawnVel;
};

