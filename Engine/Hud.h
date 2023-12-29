#pragma once
#include "Graphics.h"
#include "Shape.h"
#include "Colors.h"
#include "HudFuelGauge.h"
#include "SpriteNumbers.h"
#include "EventManager.h"

class Hud
{
public:
	Hud(Graphics& gfx);
	void draw(Graphics& gfx) const;
	void update(const float _playerFuel, EventManager& eventmanager, const float dt);
	Vec2 getPos() const;


private:
	Vec2 getWorldVec(const Vec2 localVec) const;

private:
	const float THICKNESS = 10.0f;
	const float WIDTH = 300.0f;
	const float HEIGHT;

	const Color c = Colors::White;
	Vec2 pos;

private:
	HudFuelGauge fuelGauge;

};

