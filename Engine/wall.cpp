#include "wall.h"

wall::wall()
{
}

wall::wall(const Graphics& gfx)
	: wall(gfx, rect(Vec2(MARGIN, MARGIN), DEF_WIDTH, DEF_HEIGHT))
{
}

wall::wall(const Graphics& gfx, const rect wallBounds)
	: bounds(wallBounds)
{
	ensureWallsWithinGfx(gfx);
	visualWidth = (bounds.right - bounds.left) + (THICKNESS * 2.0f);
	visualHeight = (bounds.bottom - bounds.top) + (THICKNESS * 2.0f);
}

wall::wall(const Graphics& gfx, float width, float height)
	: wall(gfx, rect(Vec2(MARGIN, MARGIN), width, height))
{
}

wall::wall(const Graphics& gfx, wallSizeEnum wallSize)
	: wall(gfx, getWallSize(wallSize).x, getWallSize(wallSize).y)
{
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

Vec2 wall::getWallSize(wallSizeEnum wallSize)
{
	switch (wallSize) {
		case MICRO:
			return Vec2(420.0f, 600.0f);
		case LIGHT:
			return Vec2(540.0f, 700.0f);
		case NORMAL:
			return Vec2(660.0f, 800.0f);
		case BIG:
			return Vec2(900.0f, 900.0f);
		default:
			break;
	}
	return Vec2(0.0f, 0.0f);
}
