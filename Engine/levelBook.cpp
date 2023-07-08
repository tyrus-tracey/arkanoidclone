#include "levelBook.h"

levelBook::levelBook(Graphics& _gfx)
	: gfx(_gfx)
{
	wall lvl1Wall(_gfx, rect(Vec2(200, 50), Vec2(600, 750)));

	Vec2 start(50, 50);
	std::vector<brick> breks;
	for (unsigned int y = 0; y < 4; ++y) {
		for (unsigned int x = 0; x < 10; ++x) {
			Vec2 bib(start);
			bib.x += x * brick::getWidth();
			bib.y += y * brick::getHeight();
			breks.push_back(brick(bib, cArr[y]));
		}
	}
	lvl1 = level(lvl1Wall, breks, Vec2(100, 100), Vec2(100, 100));
}
