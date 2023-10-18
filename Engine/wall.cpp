#include "wall.h"

wall::wall(const Graphics& gfx, wallSizeEnum wallSize)
	: bounds(rect(Vec2(MARGIN, MARGIN), wallType::getSize(wallSize)))
{
	ensureWallsWithinGfx(gfx);
	rows = wallType::getGridDims(wallSize).x;
	cols = wallType::getGridDims(wallSize).y;
	visualWidth = bounds.getWidth() + (THICKNESS * 2.0f);
	visualHeight = bounds.getHeight() + (THICKNESS * 2.0f);
}

rect wall::getBounds() const
{
	return bounds;
}

Vec2 wall::getTopLeft() const
{
	return Vec2(bounds.left, bounds.top);
}

float wall::getWidthVisual() const
{
	return visualWidth;
}

float wall::getHeightVisual() const
{
	return visualHeight;
}

unsigned int wall::getRows() const
{
	return rows;
}

unsigned int wall::getCols() const
{
	return cols;
}

void wall::draw(Graphics& gfx) const 
{
	gfx.DrawRectBorder(bounds, WALLCOLOR, THICKNESS, true);
}

void wall::ensureWallsWithinGfx(const Graphics& gfx)
{
	rect gfxBounds(0, 0, gfx.ScreenHeight, gfx.ScreenWidth);
	if (!bounds.getResizeUniform(THICKNESS).isWithin(gfxBounds)) {
		bounds.fitTo(gfxBounds, THICKNESS);
	}
}