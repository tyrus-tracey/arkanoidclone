#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Colors.h"
#include <string>


// 10x14 sprites
class SpriteNumbers
{
public:
	static void drawNum(unsigned int num, Vec2 pos, const Color c, Graphics& gfx);

private:
	static void drawDigit(const unsigned char i, const Vec2 pos, const Color c, Graphics& gfx);

	static void draw0(const Vec2 pos, const Color c, Graphics& gfx);
	static void draw1(const Vec2 pos, const Color c, Graphics& gfx);
	static void draw2(const Vec2 pos, const Color c, Graphics& gfx);
	static void draw3(const Vec2 pos, const Color c, Graphics& gfx);
	static void draw4(const Vec2 pos, const Color c, Graphics& gfx);
	static void draw5(const Vec2 pos, const Color c, Graphics& gfx);
	static void draw6(const Vec2 pos, const Color c, Graphics& gfx);
	static void draw7(const Vec2 pos, const Color c, Graphics& gfx);
	static void draw8(const Vec2 pos, const Color c, Graphics& gfx);
	static void draw9(const Vec2 pos, const Color c, Graphics& gfx);

	static const int CHARWIDTH = 10;
};

