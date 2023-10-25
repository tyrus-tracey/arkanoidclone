#pragma once
#include <vector>
#include "Vec2.h"
#include "gridLocation.h"
#include "brickType.h"
#include "wallType.h"

/*
	Struct is sent to level's brickManager, which then allocates
	a brick based on supplied instructions.
*/
struct brickInitInstruction {
	brickTypeEnum brickType;
	gridLocation loc;
};

struct levelParams {
	wallSizeEnum wallSize;
	gridLocation coreLoc;
	Vec2 ballPos;
	Vec2 ballVel;

	std::vector<brickInitInstruction> brickInitList;
};