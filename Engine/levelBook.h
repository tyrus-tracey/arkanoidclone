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


	void initBrickRect(std::vector<brickInitInstruction>& initVec, const gridLocation topLeft, const gridLocation botRight, const brickTypeEnum brickType);
	void initBrickHori(std::vector<brickInitInstruction>& initVec, const int row, const int x1, const int x2, const brickTypeEnum brickType);
	void initBrickVert(std::vector<brickInitInstruction>& initVec, const int col, const int y1, const int y2, const brickTypeEnum brickType);

	Graphics& gfx;
	std::vector<levelParams> levels;
	std::vector<levelParams>::const_iterator lvIter;
};

