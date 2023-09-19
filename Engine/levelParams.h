#pragma once
#include "brick.h"
#include "Vec2.h"
#include "gridLocation.h"


// Enum representing all concrete brick classes.
enum brickTypeEnum {
	RED_BRICK, BLUE_BRICK
};

/*
	Struct is sent to level's brickManager, which then allocates
	a brick based on supplied instructions.
*/
struct brickInitInstruction {
	brickTypeEnum brickType;
	gridLocation loc;
};

struct levelParams {
	int wallHeight;
	int wallWidth;
	Vec2 corePos;
	Vec2 ballPos;
	Vec2 ballVel;

	std::vector<brickInitInstruction> brickInitList;
};