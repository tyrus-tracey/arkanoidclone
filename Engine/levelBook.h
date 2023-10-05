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
	levelParams genLv3();


	void initBrickRect(levelParams& params, const gridLocation topLeft, const gridLocation botRight, const brickTypeEnum brickType);
	void initBrickHori(levelParams& params, const int row, const int x1, const int x2, const brickTypeEnum brickType);
	void initBrickVert(levelParams& params, const int col, const int y1, const int y2, const brickTypeEnum brickType);

	Graphics& gfx;
	std::vector<levelParams> levels;
	std::vector<levelParams>::const_iterator lvIter;
};

