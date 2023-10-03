#pragma once
#include "Graphics.h"
#include "Colors.h"
#include "rect.h"

class HudFuelGauge
{
public:
	HudFuelGauge(Vec2 _pos, const float hudWidth);
	void update(const float _playerFuel);
	void draw(Graphics& gfx) const;

	const float WIDTH;
	static constexpr float HEIGHT = 300.0f;
	static constexpr float THICKNESS = 5.0f;

	static const unsigned int FUEL_MAX = 100;

private:
	Vec2 pos;
	const int BAR_WIDTH = 250;
	const int BAR_HEIGHT = 25;

	float playerFuel = 0.0f;

	void drawGauge(Graphics& gfx) const;
	void drawFuel(Graphics& gfx, const float amount) const;

	rect rectFuelBar;
	Color cWindow = Colors::Red;
	Color cGauge = Colors::Yellow;
	Color cFuel = Colors::White;
};

