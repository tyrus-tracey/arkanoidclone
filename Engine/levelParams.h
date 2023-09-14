#pragma once
#include "brick.h"
#include "Vec2.h"
#include "gridLocation.h"

struct levelParams {
	int wallHeight;
	int wallWidth;
	Vec2 corePos;
	Vec2 ballPos;
	Vec2 ballVel;

	std::vector<brick> bricks;
};