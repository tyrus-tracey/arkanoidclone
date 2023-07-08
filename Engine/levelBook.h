#pragma once
#include "level.h"
#include "Graphics.h"

class levelBook
{
public:
	levelBook(Graphics& _gfx);
public:
	Graphics& gfx;
	level lvl1;

	Color cArr[5] = { Colors::Red, Colors::Cyan, Colors::Yellow, Colors::Green, Colors::Gray };

};

