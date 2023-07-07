#pragma once
#include "Graphics.h"
#include "rect.h"


class wall
{
public:
	wall();
	wall(const Graphics& gfx);
	wall(const Graphics& gfx, const rect wallBounds);
	rect getBounds() const;
	Vec2 getTopLeft() const;
	void draw(Graphics& gfx) const;
private:
	void ensureWallsWithinGfx(const Graphics& gfx);

	rect bounds;
	float width = 0.0f;
	float height = 0.0f;

	static constexpr float THICKNESS = 10.0f;
	static constexpr float DEF_WIDTH = 300.0f;
	static constexpr float DEF_HEIGHT = 500.0f;
	static constexpr Color WALLCOLOR = Colors::LightGray;
};

