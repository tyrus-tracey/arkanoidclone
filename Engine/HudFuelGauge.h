#pragma once
#include "Graphics.h"
#include "Colors.h"
#include "rect.h"
#include "oscillator.h"

class HudFuelGauge
{
public:
	HudFuelGauge(Vec2 _pos, const float hudWidth);
	void update(const float _playerFuel, const bool armedBallLocked, const float dt);
	void draw(Graphics& gfx) const;

	const float WIDTH;
	static constexpr float HEIGHT = 300.0f;
	static constexpr float THICKNESS = 5.0f;
	static const unsigned int FUEL_MAX = 100;

private:
	Vec2 pos;
	const float BAR_WIDTH = 250.0f;
	const float BAR_HEIGHT = 25.0f;

	float playerFuel = 0.0f;
	oscillator lightFlasher = oscillator(0.05f);

	void drawGauge(Graphics& gfx) const;
	void drawFuel(Graphics& gfx, const float amount) const;

	rect rectFuelBar = rect({ 0.0f,0.0f }, BAR_WIDTH, BAR_HEIGHT);
	rect rectDetonateLight = rect({ 0.0f,0.0f }, 200.0f, 50.0f);
	Color cWindow = Colors::Red;
	Color cDetonate = Colors::Red;
	Color cGauge = Colors::Yellow;
	Color cFuel = Colors::White;
};
