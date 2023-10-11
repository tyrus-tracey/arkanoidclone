#pragma once
#include <vector>
#include "Vec2.h"
#include "gridLocation.h"


// Enum representing all concrete brick classes.
enum brickTypeEnum {
	RED_BRICK, BLUE_BRICK, ROCK
};

enum wallSizeEnum {
	MICRO, LIGHT, NORMAL, BIG
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
	wallSizeEnum wallSize;
	gridLocation coreLoc;
	Vec2 ballPos;
	Vec2 ballVel;

	std::vector<brickInitInstruction> brickInitList;
};