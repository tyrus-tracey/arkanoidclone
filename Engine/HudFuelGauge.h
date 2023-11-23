#pragma once
#include "Graphics.h"
#include "Colors.h"
#include "SpriteCodex.h"
#include "rect.h"
#include "oscillator.h"
#include "EventManager.h"

class HudFuelGauge
{
public:
	HudFuelGauge(Vec2 _pos, const float hudWidth);
	void update(const float _playerFuel, EventManager& eventmanager, const float dt);
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
	bool soundBeep = true;


	void drawGauge(Graphics& gfx) const;
	void drawFuel(Graphics& gfx, const float amount) const;
	

	rect rectFuelBar = rect({ 0.0f,0.0f }, BAR_WIDTH, BAR_HEIGHT);
	rect rectDetonateLight = rect({ 0.0f,0.0f }, 200.0f, 50.0f);
	Color cWindow = Colors::Red;
	Color cDetonate = Colors::Red;
	Color cGauge = Colors::MakeRGB(255, 187, 17);
	Color cFuel = Colors::White;
	Color cFuelMax = Colors::Yellow;
};

