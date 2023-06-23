#pragma once
#include "rect.h"
#include "Vec2.h"
#include "Colors.h"
#include "Graphics.h"

class brick
{
public:
	brick();
	brick(Vec2 b_pos);
	brick(Vec2 b_pos, const Color c);
	void draw(Graphics& gfx);

private:
	Vec2 pos;
	rect hitbox;
	float width = 60.0f;
	float height = 20.0f;
	Color col = Colors::Red;
};

