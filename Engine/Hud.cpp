#include "Hud.h"

Hud::Hud(Graphics& gfx)
	: 
	HEIGHT(gfx.ScreenHeight - (THICKNESS*2.0f)),
	pos(gfx.ScreenWidth - WIDTH - (THICKNESS), THICKNESS),
	fuelMeter(getWorldVec({ 0, HEIGHT - HudFuelMeter::HEIGHT }), WIDTH)
{
}

void Hud::draw(Graphics& gfx) const
{
	gfx.DrawRectBorder({ pos,WIDTH, HEIGHT }, c, THICKNESS, true);
	fuelMeter.draw(gfx);
}

Vec2 Hud::getWorldVec(const Vec2 localVec) const
{
	return localVec + pos;
}
