#include "brick.h"

brick::brick()
	: hitbox(rect(0, 0, 0, 0)), pos(-1, -1)
{
}

brick::brick(Vec2 b_pos)
	: pos(b_pos)
{
	hitbox = rect(b_pos, width, height);
}

brick::brick(Vec2 b_pos, const Color c)
	: brick(b_pos)
{
	col = c;
}

void brick::draw(Graphics& gfx)
{
	gfx.DrawRect(hitbox, col);
}
