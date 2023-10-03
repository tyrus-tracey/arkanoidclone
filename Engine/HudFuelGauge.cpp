#include "HudFuelGauge.h"

HudFuelGauge::HudFuelGauge(Vec2 _pos, const float hudWidth)
	: WIDTH(hudWidth), pos(_pos),
	rectFuelBar({0,0}, BAR_WIDTH, BAR_HEIGHT)
{
	rectFuelBar.centerOnto(rect(pos, WIDTH, HEIGHT));
}

void HudFuelGauge::update(const float _playerFuel)
{
	playerFuel = _playerFuel;
}

void HudFuelGauge::draw(Graphics& gfx) const
{
	gfx.DrawRectBorder(rect(pos, WIDTH, HEIGHT), cWindow, THICKNESS, true);
	drawGauge(gfx);
}

void HudFuelGauge::drawGauge(Graphics& gfx) const
{
	gfx.DrawRectBorder(rectFuelBar, cGauge, THICKNESS, true);
	drawFuel(gfx, playerFuel);
}

void HudFuelGauge::drawFuel(Graphics& gfx, const float amount) const
{
	Vec2 drawPos = { rectFuelBar.left, rectFuelBar.top };
	float fuelPercentage = amount / FUEL_MAX;
	if (fuelPercentage < 0.0f) {
		fuelPercentage = 0.0f;
	} else if (fuelPercentage > 1.0f) {
		fuelPercentage = 1.0f;
	}
	int fuelWidth = int(float(BAR_WIDTH) * fuelPercentage);
	rect fuelRect(drawPos, fuelWidth, BAR_HEIGHT);
	gfx.DrawRect(fuelRect, cFuel, true);
}
