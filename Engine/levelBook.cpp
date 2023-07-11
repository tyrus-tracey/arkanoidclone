#include "levelBook.h"

levelBook::levelBook(Graphics& _gfx)
	: gfx(_gfx), WALL_DEFAULT(_gfx, 400, 800)
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

	Vec2 start = lvl1.getTopLeft() + Vec2(50,50);
	std::vector<brick> breks;
	for (unsigned int y = 0; y < 4; ++y) {
		for (unsigned int x = 0; x < 10; ++x) {
			Vec2 bib(start);
			bib.x += x * brick::getWidth();
			bib.y += y * brick::getHeight();
			lvl1.addBrick(brick(bib, cArr[y]));
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
	for (unsigned int y = 0; y < 3; ++y) {
		for (unsigned int x = 0; x < 12; ++x) {
			Vec2 bib(start);
			bib.x += x * brick::getWidth();
			bib.y += y * brick::getHeight();
			lvl2.addBrick(brick(bib, cArr[y]));
		}
	}

	return lvl2;
}

