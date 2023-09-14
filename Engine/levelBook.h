#pragma once
#include <vector>
#include "level.h"
#include "Graphics.h"

class levelBook
{
public:
	levelBook(Graphics& _gfx);
	levelParams readLevelData() const;
	bool advanceLevel();

private:
	Graphics& gfx;
	std::vector<level> levels;
	std::vector<level>::const_iterator lvIter;
	const wall WALL_DEFAULT;

	levelParams lvl1;
};

