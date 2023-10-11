#include "levelBook.h"

/*
WALLSIZE TEMPLATES:
MICRO:
	7x13 bricks		= 420x600
LIGHT:
	9x20 bricks		= 540x700
NORMAL:
	11x25 bricks	= 660x800
BIG:
	15x30 bricks	= 900x900
*/


levelBook::levelBook(Graphics& _gfx)
	: gfx(_gfx)
{
	levels.push_back(genLv1());
	levels.push_back(genLv2());
	levels.push_back(genLv3());
	lvIter = levels.begin();
}

levelParams levelBook::readLevelData() const
{
	return *lvIter;
}

bool levelBook::advanceLevel()
{
	if (lvIter == levels.end()) { //If already past level vector, somehow
		return false;
	}
	if (++lvIter == levels.end()) { // If at last level
		return false;
	}
	return true;
}

levelParams levelBook::genLv1()
{
	levelParams out;
	out.wallSize = MICRO; //7x13
	out.ballPos = { -1,-1 };
	out.ballVel = { 0,1 };
	out.coreLoc = { 3, 1 };

	initBrickHori(out, 4, 0, 13, RED_BRICK);
	initBrickHori(out, 5, 0, 13, ROCK);
	return out;
}

levelParams levelBook::genLv2()
{
	levelParams out;
	out.wallSize = NORMAL; // 11x25
	out.ballPos = { 300, 300 };
	out.ballVel = { 0, 1 };
	out.coreLoc = { 5, 3};

	initBrickHori(out, 0, 3, 7, BLUE_BRICK);
	initBrickHori(out, 10, 3, 7, BLUE_BRICK);
	initBrickVert(out, 3, 0, 10, BLUE_BRICK);
	initBrickVert(out, 7, 0, 10, BLUE_BRICK);

	return out;
}

levelParams levelBook::genLv3()
{
	levelParams out;
	out.wallSize = BIG;
	out.ballPos = { -1, -1 };
	out.ballVel = { 0, 1 };
	out.coreLoc = { 3, 1 };

	initBrickHori(out, 4, 0, 19, RED_BRICK);
	initBrickHori(out, 5, 0, 19, BLUE_BRICK);
	initBrickHori(out, 6, 0, 30, RED_BRICK);

	return out;
}

// Create initInstructions for a rectangle of bricks to a given brickInit vector.
void levelBook::initBrickRect(levelParams& params, const gridLocation topLeft, const gridLocation botRight, const brickTypeEnum brickType)
{
	for (int y = topLeft.y; y <= botRight.y; y++) {
		for (int x = topLeft.x; x <= botRight.x; x++) {
			params.brickInitList.push_back({brickType, {x,y} });
		}
	}
}

// Create initInstructions for a horizontal line of bricks to a given brickInit vector.
void levelBook::initBrickHori(levelParams& params, const int row, const int x1, const int x2, const brickTypeEnum brickType)
{
	initBrickRect(params, { x1, row }, { x2,row }, brickType);
}

// Create initInstructions for a vertical line of bricks to a given brickInit vector.
void levelBook::initBrickVert(levelParams& params, const int col, const int y1, const int y2, const brickTypeEnum brickType)
{
	initBrickRect(params, { col, y1 }, { col, y2 }, brickType);
}
