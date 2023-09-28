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

wall::wall(const Graphics& gfx, int width, int height)
	: wall(gfx, rect(
			Vec2(MARGIN, MARGIN), 
			float(width), 
			float(height)
			)
		)
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
