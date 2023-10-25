#pragma once
#include "Graphics.h"
#include "rect.h"
#include "wallType.h"

class wall
{
public:
	wall(const Graphics& gfx, wallSizeEnum wallSize);
	rect getBounds() const;
	Vec2 getTopLeft() const;
	float getWidthVisual() const;
	float getHeightVisual() const;
	unsigned int getRows() const;
	unsigned int getCols() const;
	void draw(Graphics& gfx) const;

private:
	void ensureWallsWithinGfx(const Graphics& gfx);

	rect bounds;

	static constexpr float MARGIN = 30.0f;
	static constexpr float THICKNESS = 10.0f;
	static constexpr Color WALLCOLOR = Colors::LightGray;

	unsigned int rows;
	unsigned int cols;

	float visualWidth = 0.0f;
	float visualHeight = 0.0f;
};

