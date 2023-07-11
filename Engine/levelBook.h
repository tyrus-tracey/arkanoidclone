#pragma once
#include <vector>
#include "level.h"
#include "Graphics.h"

class levelBook
{
public:
	levelBook(Graphics& _gfx);
	level getCurrentLvl() const;
	bool advanceLevel();

private:
	level genLv1();
	level genLv2();

private:
	Graphics& gfx;
	std::vector<level> levels;
	std::vector<level>::const_iterator lvIter;
	const wall WALL_DEFAULT;

	Color cArr[5] = { Colors::Red, Colors::Cyan, Colors::Yellow, Colors::Green, Colors::Gray };

};

