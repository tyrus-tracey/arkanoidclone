#include "wall.h"

wall::wall()
{
}

wall::wall(const Graphics& gfx)
	: wall(gfx, rect(Vec2((gfx.ScreenWidth / 2) - (DEF_WIDTH / 2), 0), DEF_WIDTH, DEF_HEIGHT))
{
}

wall::wall(const Graphics& gfx, const rect wallBounds)
	: bounds(wallBounds)
{
	ensureWallsWithinGfx(gfx);
	width = (bounds.right - bounds.left) + (THICKNESS * 2.0f);
	height = (bounds.bottom - bounds.top) + (THICKNESS * 2.0f);
}

wall::wall(const Graphics& gfx, int width, int height)
	: wall(gfx, rect(
			Vec2(gfx.ScreenWidth/2 - width/2, gfx.ScreenHeight/2 - height/2), 
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

float wall::getWidth() const
{
	return width;
}

float wall::getHeight() const
{
	return height;
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
