#pragma once
#include "Graphics.h"
#include "rect.h"


class wall
{
public:
	wall();
	wall(const Graphics& gfx);
	wall(const Graphics& gfx, const rect wallBounds);
	wall(const Graphics& gfx, float width, float height);
	rect getBounds() const;
	Vec2 getTopLeft() const;
	float getWidthVisual() const;
	float getHeightVisual() const;
	void draw(Graphics& gfx) const;
private:
	void ensureWallsWithinGfx(const Graphics& gfx);

	rect bounds;

	static constexpr float MARGIN = 50.0f;
	static constexpr float THICKNESS = 10.0f;
	static constexpr float DEF_WIDTH = 300.0f;
	static constexpr float DEF_HEIGHT = 500.0f;
	static constexpr Color WALLCOLOR = Colors::LightGray;

	float visualWidth = 0.0f;
	float visualHeight = 0.0f;
};

