#include "HudFuelMeter.h"

HudFuelMeter::HudFuelMeter(Vec2 _pos, const float hudWidth)
	: WIDTH(hudWidth), pos(_pos)
{
}

void HudFuelMeter::draw(Graphics& gfx) const
{
	gfx.DrawRectBorder(rect(pos, WIDTH, HEIGHT), c, THICKNESS, true);
}
