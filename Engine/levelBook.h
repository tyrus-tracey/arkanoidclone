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
	levelParams genLv1();
	levelParams genLv2();

	Graphics& gfx;
	std::vector<levelParams> levels;
	std::vector<levelParams>::const_iterator lvIter;
};

