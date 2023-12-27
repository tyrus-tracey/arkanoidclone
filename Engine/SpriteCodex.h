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
	static void DrawBrickCracks1(const Vec2& topLeft, Graphics& gfx);
	static void DrawBrickCracks2(const Vec2& topLeft, Graphics& gfx);
	static void DrawBrickCracks3(const Vec2& topLeft, Graphics& gfx);
	static void DrawBrickCracks4(const Vec2& topLeft, Graphics& gfx);
	static void DrawTitleMain(const Vec2& topLeft, const Color c, Graphics& gfx);
	static void DrawEnterPrompt(const Vec2& topLeft, const Color c, Graphics& gfx);
	static void DrawGameOver(Graphics& gfx);
	static void DrawGameWon(Graphics& gfx);
};