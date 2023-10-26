#include "HudFuelGauge.h"

HudFuelGauge::HudFuelGauge(Vec2 _pos, const float hudWidth)
	: WIDTH(hudWidth), pos(_pos)
{
	rectFuelBar.centerOnto(rect(pos, WIDTH, HEIGHT));
	rectDetonateLight.centerOnto(rect(pos, WIDTH, HEIGHT));
	rectDetonateLight.move({0, -100});
}

void HudFuelGauge::update(const float _playerFuel, EventManager& eventmanager, const float dt)
{
	playerFuel = _playerFuel;

	if (eventmanager.flag_ArmedBallLocked.isRaised()) {
 		lightFlasher.wake();
		lightFlasher.tick(dt);

		if (soundBeep) {
			eventmanager.ballLockBeep();
			soundBeep = false;
		}
		if (!lightFlasher.isOn()) {
			soundBeep = true;
		}
	}
	else {
		lightFlasher.sleep();
		lightFlasher.resetInterval();
	}

}

void HudFuelGauge::draw(Graphics& gfx) const
{
	gfx.DrawRectBorder(rect(pos, WIDTH, HEIGHT), cWindow, THICKNESS, true);
	drawGauge(gfx);
	if (lightFlasher.isOn()) {
		gfx.DrawRect(rectDetonateLight, cDetonate, true);
	}
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
	int fuelWidth = int(BAR_WIDTH * fuelPercentage);
	rect fuelRect(drawPos, float(fuelWidth), BAR_HEIGHT);
	gfx.DrawRect(fuelRect, cFuel, true);
}
