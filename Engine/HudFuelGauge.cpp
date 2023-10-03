#include "HudFuelGauge.h"

HudFuelGauge::HudFuelGauge(Vec2 _pos, const float hudWidth)
	: WIDTH(hudWidth), pos(_pos),
	rectFuelBar({0,0}, BAR_WIDTH, BAR_HEIGHT)
{
	rectFuelBar.centerOnto(rect(pos, WIDTH, HEIGHT));
}

void HudFuelGauge::draw(Graphics& gfx) const
{
	gfx.DrawRectBorder(rect(pos, WIDTH, HEIGHT), cWindow, THICKNESS, true);
	drawGauge(gfx);
}

void HudFuelGauge::drawGauge(Graphics& gfx) const
{
	//draw border
	gfx.DrawRectBorder(rectFuelBar, cGauge, THICKNESS, true);
	for (int i = 0; i < 3; i++) {
		drawFuelUnit(gfx, i);
	}
}

void HudFuelGauge::drawFuelUnit(Graphics& gfx, unsigned int index) const
{
	Vec2 drawPos = { rectFuelBar.left + (index*BAR_HEIGHT), rectFuelBar.top};
	gfx.DrawRect(rect(drawPos, BAR_HEIGHT, BAR_HEIGHT).resizeUniform(-2.0f), cFuel, true);
}
