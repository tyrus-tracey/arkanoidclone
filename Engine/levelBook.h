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
	levelParams lvl_Spires();
	levelParams lvl_Babby();

	bool withinBounds(const levelParams& params, const gridLocation loc) const;
	int getNumCols(const levelParams& params) const;
	int getNumRows(const levelParams& params) const;

	void initBrick(levelParams& params, const gridLocation loc, const brickTypeEnum brickType);
	void initRect(levelParams& params, const gridLocation topLeft, const gridLocation botRight, const brickTypeEnum brickType);
	void initLineHori(levelParams& params, const int row, const int x1, const int x2, const brickTypeEnum brickType);
	void initLineVert(levelParams& params, const int col, const int y1, const int y2, const brickTypeEnum brickType);
	void initRow(levelParams& params, const int row, const brickTypeEnum brickType);
	void initCol(levelParams& params, const int col, const brickTypeEnum brickType);


	const int COL_MARGIN = 15;
	Graphics& gfx;
	std::vector<levelParams> levels;
	std::vector<levelParams>::const_iterator lvIter;
};

