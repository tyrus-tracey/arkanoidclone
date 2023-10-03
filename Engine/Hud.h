#pragma once
#include "Graphics.h"
#include "rect.h"
#include "Colors.h"
#include "HudFuelMeter.h"

class Hud
{
public:
	Hud(Graphics& gfx);
	void draw(Graphics& gfx) const;

private:
	Vec2 getWorldVec(const Vec2 localVec) const;

private:
	const float THICKNESS = 10.0f;
	const float WIDTH = 300.0f;
	const float HEIGHT;

	const Color c = Colors::Yellow;
	Vec2 pos;

private:
	HudFuelMeter fuelMeter;



};

