#include "Hud.h"

Hud::Hud(Graphics& gfx)
	: 
	HEIGHT(gfx.ScreenHeight - (THICKNESS*2.0f)),
	pos(gfx.ScreenWidth - WIDTH - (THICKNESS), THICKNESS),
	fuelGauge(getWorldVec({ 0, HEIGHT - HudFuelGauge::HEIGHT }), WIDTH)
{
}

void Hud::draw(Graphics& gfx) const
{
	gfx.DrawRectBorder({ pos,WIDTH, HEIGHT }, c, THICKNESS, true);
	fuelGauge.draw(gfx);
}

void Hud::update(const float _playerFuel, EventManager& eventmanager, const float dt)
{
	fuelGauge.update(_playerFuel, eventmanager, dt);
}

Vec2 Hud::getPos() const
{
	return pos;
}

Vec2 Hud::getWorldVec(const Vec2 localVec) const
{
	return localVec + pos;
}
