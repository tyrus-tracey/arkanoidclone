#pragma once

#include "Graphics.h"
#include "Vec2.h"

class SpriteCodex
{
public:
	// centered drawing of 14x14 sprite
	static void DrawBall( const Vec2& center,Graphics& gfx, int plusRed );
	static void DrawCore(const Vec2& topLeft, Graphics& gfx);
};