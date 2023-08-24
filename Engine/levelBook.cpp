#include "levelBook.h"


levelBook::levelBook(Graphics& _gfx)
	: gfx(_gfx), WALL_DEFAULT(_gfx, 600, 800)
{
	levels.push_back(genLv1());
	levels.push_back(genLv2());
	lvIter = levels.begin();
}

level levelBook::getCurrentLvl() const
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

level levelBook::genLv1()
{
	Vec2 coreSpawn(100, 100);
	Vec2 ballSpawn(100, 100);
	level lvl1(WALL_DEFAULT, coreSpawn);

	Vec2 test = lvl1.getTopLeft();
	for (int y = 0; y < 4; ++y) {
		for (int x = 0; x < 8; ++x) {
			lvl1.addBrick<brick>({x,y});
		}
	}
	return lvl1;
}

level levelBook::genLv2()
{
	Vec2 coreSpawn(100, 100);
	Vec2 ballSpawn(100, 100);
	wall lv2wall(gfx, 1000,600);
	level lvl2(lv2wall, coreSpawn);

	Vec2 start(50, 50);
	for (int y = 0; y < 3; ++y) {
		for (int x = 0; x < 12; ++x) {
			lvl2.addBrick<brick>({x,y});
		}
	}

	return lvl2;
}

