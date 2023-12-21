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
	levels.push_back(lvl_Babby());
	levels.push_back(lvl_Spires());
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

void levelBook::reset()
{
	lvIter = levels.begin();
}

levelParams levelBook::lvl_Spires()
{
	levelParams out;
	out.wallSize = MICRO;
	out.ballPos = { -1,-1 };
	out.ballVel = { 0,1 };
	out.coreLoc = { 3, 0 };

	initLineVert(out, 2, 0, 2, ROCK);
	initLineVert(out, 4, 0, 2, ROCK);
	initBrick(out, { 3, 2 }, ROCK);

	initBrick(out, { 0, 13 }, BALL);
	initBrick(out, { 2, 13 }, BALL);
	initBrick(out, { 4, 13 }, BALL);
	initBrick(out, { 6, 13 }, BALL);

	initBrick(out, { 0, 14 }, ROCK);
	initBrick(out, { 2, 14 }, ROCK);
	initBrick(out, { 4, 14 }, ROCK);
	initBrick(out, { 6, 14 }, ROCK);

	initCol(out, 0, COLOR);
	initCol(out, 2, COLOR);
	initCol(out, 4, COLOR);
	initCol(out, 6, COLOR);
	
	return out;
}

levelParams levelBook::lvl_Babby()
{
	levelParams out;
	out.wallSize = MICRO; //7x13
	out.ballPos = { -1,-1 };
	out.ballVel = { 0,1 };
	out.coreLoc = { 3, 1 };

	initRow(out, 4, RED);
	initRow(out, 5, BLUE);
	return out;
}

void levelBook::initBrick(levelParams& params, const gridLocation loc, const brickTypeEnum brickType)
{
	if (withinBounds(params, loc)) {
		params.brickInitList.push_back({ brickType, loc });
	}
}

// Create initInstructions for a rectangle of bricks to a given brickInit vector.
void levelBook::initRect(levelParams& params, const gridLocation topLeft, const gridLocation botRight, const brickTypeEnum brickType)
{
	for (int y = topLeft.y; y <= botRight.y; y++) {
		for (int x = topLeft.x; x <= botRight.x; x++) {
			initBrick(params, { x,y }, brickType);
		}
	}
}

// Create initInstructions for a horizontal line of bricks to a given brickInit vector.
void levelBook::initLineHori(levelParams& params, const int row, const int x1, const int x2, const brickTypeEnum brickType)
{
	initRect(params, { x1, row }, { x2,row }, brickType);
}

// Create initInstructions for a vertical line of bricks to a given brickInit vector.
void levelBook::initLineVert(levelParams& params, const int col, const int y1, const int y2, const brickTypeEnum brickType)
{
	initRect(params, { col, y1 }, { col, y2 }, brickType);
}

void levelBook::initRow(levelParams& params, const int row, const brickTypeEnum brickType)
{
	initLineHori(params, row, 0, getNumCols(params), brickType);
}

void levelBook::initCol(levelParams& params, const int col, const brickTypeEnum brickType)
{
	initLineVert(params, col, 0, getNumRows(params) - COL_MARGIN, brickType);
}


bool levelBook::withinBounds(const levelParams& params, const gridLocation loc) const
{
	const int MAX_ROWS = getNumRows(params);
	const int MAX_COLS = getNumCols(params);
	return	loc.x >= 0 && loc.x <= MAX_COLS &&
			loc.y >= 0 && loc.y <= MAX_ROWS;
}

int levelBook::getNumCols(const levelParams& params) const
{
	switch (params.wallSize) {
	case MICRO:		return 6;
	case LIGHT:		return 8;
	case NORMAL:	return 10;
	case BIG:		return 14;
	default:		return -1;
	}
}

int levelBook::getNumRows(const levelParams& params) const
{
	switch (params.wallSize) {
	case MICRO:		return 29;
	case LIGHT:		return 34;
	case NORMAL:	return 39;
	case BIG:		return 44;
	default:		return -1;
	}
}