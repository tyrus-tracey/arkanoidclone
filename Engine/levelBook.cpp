#include "levelBook.h"


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
	out.wallWidth = 600;
	out.wallHeight = 800;
	out.ballPos = { 300, 300 };
	out.ballVel = { 0, 1 };
	out.corePos = { 300, 0};


	for (int y = 3; y < 5; ++y) {
		for (int x = 1; x < 9; ++x) {
			if (y == 3) {
				out.brickInitList.push_back({ RED_BRICK, {x,y} });
			}
			else {
				out.brickInitList.push_back({ BLUE_BRICK, {x,y} });
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
	out.corePos = { 300, 100 };

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

