#include "levelBook.h"

/*
WALLSIZE TEMPLATES:
MICRO:
	7x13 bricks		= 420x600
LIGHT:
	9x20 bricks		= 540x700
GENERAL:
	11x25 bricks	= 660x800
BIG:
	15x30 bricks	= 900x900
*/

// TODO: make ballspawn relative to walls

levelBook::levelBook(Graphics& _gfx)
	: gfx(_gfx)
{
	levels.push_back(genLv1());
	levels.push_back(genLv2());
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
	out.wallWidth = 420;
	out.wallHeight = 600;
	out.ballPos = { 500, 500};
	out.ballVel = { 0, 1 };
	out.coreLoc = { 3, 1};


	for (int y = 4; y < 13; ++y) {
		for (int x = 0; x < 7; ++x) {
			if (y % 4 == 0) {
				if ((y / 2) % 2 == 0) {
					out.brickInitList.push_back({ RED_BRICK, {x,y} });
				}
				else {
					out.brickInitList.push_back({ BLUE_BRICK, {x,y} });
				}
				
			}
		}
	}
	return out;
}

levelParams levelBook::genLv2()
{
	levelParams out;
	out.wallWidth = 600;
	out.wallHeight = 800;
	out.ballPos = { 300, 300 };
	out.ballVel = { 0, 1 };
	out.coreLoc = { 5, 3};

	for (int y = 0; y < 10; ++y) {
		for (int x = 4; x <= 6; ++x) {
			if (x == 1) {
				out.brickInitList.push_back({ RED_BRICK, {x,y} });
			}
			else if (x == 5) {
				if (y == 0 || y == 9) {
					out.brickInitList.push_back({ BLUE_BRICK, {x,y} });
				}
			}
			else {
				out.brickInitList.push_back({ BLUE_BRICK, {x,y} });
			}
		}
	}
	return out;
}

