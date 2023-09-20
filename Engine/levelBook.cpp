#include "levelBook.h"


levelBook::levelBook(Graphics& _gfx)
	: gfx(_gfx)
{
	levels.push_back(genLv1());
	lvIter = levels.begin();
}

levelParams levelBook::readLevelData() const
{
	return *lvIter;
}

bool levelBook::advanceLevel()
{
	if (lvIter == levels.end()) {
		return false;
	}
	if (++lvIter == levels.end()) {
		return false;
	}
	return true;
}

levelParams levelBook::genLv1()
{
	levelParams out;
	out.wallWidth = 600;
	out.wallHeight = 800;
	out.ballPos = { 300, 400 };
	out.ballVel = { 0, 1 };
	out.corePos = { 300, 0};


	for (int y = 2; y < 4; ++y) {
		for (int x = 0; x < 10; ++x) {
			if (y < 3) {
				out.brickInitList.push_back({ RED_BRICK, {x,y} });
			}
			else {
				out.brickInitList.push_back({ BLUE_BRICK, {x,y} });
			}
		}
	}
	return out;
}

//levelParams levelBook::genLv2()
//{
//	
//}

