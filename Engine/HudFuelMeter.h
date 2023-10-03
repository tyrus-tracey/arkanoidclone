#pragma once
#include "Graphics.h"
#include "Colors.h"
#include "rect.h"

class HudFuelMeter
{
public:
	HudFuelMeter(Vec2 _pos, const float hudWidth);
	void draw(Graphics& gfx) const;

	const float WIDTH;
	static constexpr float HEIGHT = 300.0f;
	static constexpr float THICKNESS = 5.0f;

private:
	Vec2 pos;
	Color c = Colors::Red;
};

