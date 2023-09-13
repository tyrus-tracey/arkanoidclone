#pragma once
#include "brick.h"
#include "Vec2.h"
#include "gridLocation.h"

typedef std::pair<brick, gridLocation> brickData;

struct levelParams {
	int wallHeight;
	int wallWidth;
	Vec2 corePos;
	Vec2 ballPos;
	Vec2 ballVec;

	std::vector<brickData> bricks;
};