#pragma once

#include "Graphics.h"
#include "Vec2.h"

class SpriteCodex
{
public:
	// centered drawing of 14x14 sprite
	static void DrawBall( const Vec2& center,Graphics& gfx, int plusRed );
	static void DrawCore(const Vec2& topLeft, Graphics& gfx);
	static void DrawCoreTL(const Vec2& topLeft, Graphics& gfx);
	static void DrawCoreTR(const Vec2& topLeft, Graphics& gfx);
	static void DrawCoreBR(const Vec2& topLeft, Graphics& gfx);
	static void DrawCoreBL(const Vec2& topLeft, Graphics& gfx);
	static void DrawCoreFaint(const Vec2& topLeft, Graphics& gfx);
	static void DrawCoreHusk(const Vec2& topLeft, Graphics& gfx);
	static void DrawFuelSign(const Vec2& topLeft, Graphics& gfx);
	static void DrawEnterOn(const Vec2& topLeft, Graphics& gfx);
	static void DrawBrickChunk(const Vec2& midPoint, const Color& c, Graphics& gfx);
	static void DrawBrickBall(const Vec2& topLeft, Graphics& gfx);
	static void DrawBrickRock(const Vec2& topLeft, Graphics& gfx);
};