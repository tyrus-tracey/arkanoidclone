#include "SpriteNumbers.h"

void SpriteNumbers::drawNum(unsigned int num, Vec2 pos, const Color c, Graphics& gfx)
{
	unsigned int temp = num;
	while (temp > 9) {
		pos.x += CHARWIDTH;
		temp /= 10;
	}

	unsigned char i;

	while (num >= 0) {
		i = num % 10;
		num /= 10;
		drawDigit(i, pos, c, gfx);
		pos.x -= CHARWIDTH;
		if (num <= 0) { return; }
	}
}

void SpriteNumbers::drawDigit(const unsigned char i, const Vec2 pos, const Color c, Graphics& gfx)
{
	switch (i) {
	case 0:
		draw0(pos, c, gfx); break;
	case 1:
		draw1(pos, c, gfx); break;
	case 2:
		draw2(pos, c, gfx); break;
	case 3:
		draw3(pos, c, gfx); break;
	case 4:
		draw4(pos, c, gfx); break;
	case 5:
		draw5(pos, c, gfx); break;
	case 6:
		draw6(pos, c, gfx); break;
	case 7:
		draw7(pos, c, gfx); break;
	case 8:
		draw8(pos, c, gfx); break;
	case 9:
		draw9(pos, c, gfx); break;
	default:
		return;
	}
	return;
}

void SpriteNumbers::draw0(const Vec2 pos, const Color c, Graphics& gfx)
{
	int x = int(pos.x);
	int y = int(pos.y);
	gfx.PutPixel(3 + x, 2 + y, c, false);
	gfx.PutPixel(2 + x, 2 + y, c, false);
	gfx.PutPixel(4 + x, 2 + y, c, false);
	gfx.PutPixel(5 + x, 2 + y, c, false);
	gfx.PutPixel(6 + x, 2 + y, c, false);
	gfx.PutPixel(7 + x, 2 + y, c, false);
	gfx.PutPixel(8 + x, 2 + y, c, false);
	gfx.PutPixel(0 + x, 3 + y, c, false);
	gfx.PutPixel(1 + x, 3 + y, c, false);
	gfx.PutPixel(2 + x, 3 + y, c, false);
	gfx.PutPixel(3 + x, 3 + y, c, false);
	gfx.PutPixel(4 + x, 3 + y, c, false);
	gfx.PutPixel(5 + x, 3 + y, c, false);
	gfx.PutPixel(6 + x, 3 + y, c, false);
	gfx.PutPixel(7 + x, 3 + y, c, false);
	gfx.PutPixel(8 + x, 3 + y, c, false);
	gfx.PutPixel(9 + x, 3 + y, c, false);
	gfx.PutPixel(0 + x, 4 + y, c, false);
	gfx.PutPixel(1 + x, 4 + y, c, false);
	gfx.PutPixel(2 + x, 4 + y, c, false);
	gfx.PutPixel(7 + x, 4 + y, c, false);
	gfx.PutPixel(8 + x, 4 + y, c, false);
	gfx.PutPixel(9 + x, 4 + y, c, false);
	gfx.PutPixel(0 + x, 5 + y, c, false);
	gfx.PutPixel(1 + x, 5 + y, c, false);
	gfx.PutPixel(8 + x, 5 + y, c, false);
	gfx.PutPixel(9 + x, 5 + y, c, false);
	gfx.PutPixel(0 + x, 6 + y, c, false);
	gfx.PutPixel(1 + x, 6 + y, c, false);
	gfx.PutPixel(8 + x, 6 + y, c, false);
	gfx.PutPixel(9 + x, 6 + y, c, false);
	gfx.PutPixel(0 + x, 7 + y, c, false);
	gfx.PutPixel(1 + x, 7 + y, c, false);
	gfx.PutPixel(8 + x, 7 + y, c, false);
	gfx.PutPixel(9 + x, 7 + y, c, false);
	gfx.PutPixel(0 + x, 8 + y, c, false);
	gfx.PutPixel(1 + x, 8 + y, c, false);
	gfx.PutPixel(8 + x, 8 + y, c, false);
	gfx.PutPixel(9 + x, 8 + y, c, false);
	gfx.PutPixel(0 + x, 9 + y, c, false);
	gfx.PutPixel(1 + x, 9 + y, c, false);
	gfx.PutPixel(2 + x, 9 + y, c, false);
	gfx.PutPixel(7 + x, 9 + y, c, false);
	gfx.PutPixel(8 + x, 9 + y, c, false);
	gfx.PutPixel(9 + x, 9 + y, c, false);
	gfx.PutPixel(0 + x, 10 + y, c, false);
	gfx.PutPixel(1 + x, 10 + y, c, false);
	gfx.PutPixel(2 + x, 10 + y, c, false);
	gfx.PutPixel(3 + x, 10 + y, c, false);
	gfx.PutPixel(4 + x, 10 + y, c, false);
	gfx.PutPixel(5 + x, 10 + y, c, false);
	gfx.PutPixel(6 + x, 10 + y, c, false);
	gfx.PutPixel(7 + x, 10 + y, c, false);
	gfx.PutPixel(8 + x, 10 + y, c, false);
	gfx.PutPixel(9 + x, 10 + y, c, false);
	gfx.PutPixel(2 + x, 11 + y, c, false);
	gfx.PutPixel(3 + x, 11 + y, c, false);
	gfx.PutPixel(4 + x, 11 + y, c, false);
	gfx.PutPixel(5 + x, 11 + y, c, false);
	gfx.PutPixel(6 + x, 11 + y, c, false);
	gfx.PutPixel(7 + x, 11 + y, c, false);

}

void SpriteNumbers::draw1(const Vec2 pos, const Color c, Graphics& gfx)
{
	int x = int(pos.x);
	int y = int(pos.y);
	gfx.PutPixel(2 + x, 2 + y, c, false);
	gfx.PutPixel(3 + x, 2 + y, c, false);
	gfx.PutPixel(4 + x, 2 + y, c, false);
	gfx.PutPixel(2 + x, 3 + y, c, false);
	gfx.PutPixel(3 + x, 3 + y, c, false);
	gfx.PutPixel(4 + x, 3 + y, c, false);
	gfx.PutPixel(5 + x, 3 + y, c, false);
	gfx.PutPixel(4 + x, 4 + y, c, false);
	gfx.PutPixel(5 + x, 4 + y, c, false);
	gfx.PutPixel(6 + x, 4 + y, c, false);
	gfx.PutPixel(4 + x, 5 + y, c, false);
	gfx.PutPixel(5 + x, 5 + y, c, false);
	gfx.PutPixel(6 + x, 5 + y, c, false);
	gfx.PutPixel(4 + x, 6 + y, c, false);
	gfx.PutPixel(5 + x, 6 + y, c, false);
	gfx.PutPixel(6 + x, 6 + y, c, false);
	gfx.PutPixel(4 + x, 7 + y, c, false);
	gfx.PutPixel(5 + x, 7 + y, c, false);
	gfx.PutPixel(6 + x, 7 + y, c, false);
	gfx.PutPixel(4 + x, 8 + y, c, false);
	gfx.PutPixel(5 + x, 8 + y, c, false);
	gfx.PutPixel(6 + x, 8 + y, c, false);
	gfx.PutPixel(4 + x, 9 + y, c, false);
	gfx.PutPixel(5 + x, 9 + y, c, false);
	gfx.PutPixel(6 + x, 9 + y, c, false);
	gfx.PutPixel(4 + x, 10 + y, c, false);
	gfx.PutPixel(5 + x, 10 + y, c, false);
	gfx.PutPixel(6 + x, 10 + y, c, false);
	gfx.PutPixel(4 + x, 11 + y, c, false);
	gfx.PutPixel(5 + x, 11 + y, c, false);
	gfx.PutPixel(6 + x, 11 + y, c, false);

}

void SpriteNumbers::draw2(const Vec2 pos, const Color c, Graphics& gfx)
{
	int x = int(pos.x);
	int y = int(pos.y);
	gfx.PutPixel(0 + x, 2 + y, c, false);
	gfx.PutPixel(1 + x, 2 + y, c, false);
	gfx.PutPixel(2 + x, 2 + y, c, false);
	gfx.PutPixel(3 + x, 2 + y, c, false);
	gfx.PutPixel(4 + x, 2 + y, c, false);
	gfx.PutPixel(5 + x, 2 + y, c, false);
	gfx.PutPixel(6 + x, 2 + y, c, false);
	gfx.PutPixel(7 + x, 2 + y, c, false);
	gfx.PutPixel(8 + x, 2 + y, c, false);
	gfx.PutPixel(0 + x, 3 + y, c, false);
	gfx.PutPixel(1 + x, 3 + y, c, false);
	gfx.PutPixel(2 + x, 3 + y, c, false);
	gfx.PutPixel(3 + x, 3 + y, c, false);
	gfx.PutPixel(4 + x, 3 + y, c, false);
	gfx.PutPixel(5 + x, 3 + y, c, false);
	gfx.PutPixel(6 + x, 3 + y, c, false);
	gfx.PutPixel(7 + x, 3 + y, c, false);
	gfx.PutPixel(8 + x, 3 + y, c, false);
	gfx.PutPixel(9 + x, 3 + y, c, false);
	gfx.PutPixel(7 + x, 4 + y, c, false);
	gfx.PutPixel(8 + x, 4 + y, c, false);
	gfx.PutPixel(9 + x, 4 + y, c, false);
	gfx.PutPixel(7 + x, 5 + y, c, false);
	gfx.PutPixel(8 + x, 5 + y, c, false);
	gfx.PutPixel(9 + x, 5 + y, c, false);
	gfx.PutPixel(1 + x, 6 + y, c, false);
	gfx.PutPixel(2 + x, 6 + y, c, false);
	gfx.PutPixel(3 + x, 6 + y, c, false);
	gfx.PutPixel(4 + x, 6 + y, c, false);
	gfx.PutPixel(5 + x, 6 + y, c, false);
	gfx.PutPixel(6 + x, 6 + y, c, false);
	gfx.PutPixel(7 + x, 6 + y, c, false);
	gfx.PutPixel(8 + x, 6 + y, c, false);
	gfx.PutPixel(9 + x, 6 + y, c, false);
	gfx.PutPixel(0 + x, 7 + y, c, false);
	gfx.PutPixel(1 + x, 7 + y, c, false);
	gfx.PutPixel(2 + x, 7 + y, c, false);
	gfx.PutPixel(3 + x, 7 + y, c, false);
	gfx.PutPixel(4 + x, 7 + y, c, false);
	gfx.PutPixel(5 + x, 7 + y, c, false);
	gfx.PutPixel(6 + x, 7 + y, c, false);
	gfx.PutPixel(7 + x, 7 + y, c, false);
	gfx.PutPixel(0 + x, 8 + y, c, false);
	gfx.PutPixel(1 + x, 8 + y, c, false);
	gfx.PutPixel(0 + x, 9 + y, c, false);
	gfx.PutPixel(1 + x, 9 + y, c, false);
	gfx.PutPixel(2 + x, 9 + y, c, false);
	gfx.PutPixel(0 + x, 10 + y, c, false);
	gfx.PutPixel(1 + x, 10 + y, c, false);
	gfx.PutPixel(2 + x, 10 + y, c, false);
	gfx.PutPixel(3 + x, 10 + y, c, false);
	gfx.PutPixel(4 + x, 10 + y, c, false);
	gfx.PutPixel(5 + x, 10 + y, c, false);
	gfx.PutPixel(6 + x, 10 + y, c, false);
	gfx.PutPixel(7 + x, 10 + y, c, false);
	gfx.PutPixel(8 + x, 10 + y, c, false);
	gfx.PutPixel(9 + x, 10 + y, c, false);
	gfx.PutPixel(1 + x, 11 + y, c, false);
	gfx.PutPixel(2 + x, 11 + y, c, false);
	gfx.PutPixel(3 + x, 11 + y, c, false);
	gfx.PutPixel(4 + x, 11 + y, c, false);
	gfx.PutPixel(5 + x, 11 + y, c, false);
	gfx.PutPixel(6 + x, 11 + y, c, false);
	gfx.PutPixel(7 + x, 11 + y, c, false);
	gfx.PutPixel(8 + x, 11 + y, c, false);
	gfx.PutPixel(9 + x, 11 + y, c, false);

}

void SpriteNumbers::draw3(const Vec2 pos, const Color c, Graphics& gfx)
{
	int x = int(pos.x);
	int y = int(pos.y);
	gfx.PutPixel(0 + x, 2 + y, c, false);
	gfx.PutPixel(1 + x, 2 + y, c, false);
	gfx.PutPixel(2 + x, 2 + y, c, false);
	gfx.PutPixel(3 + x, 2 + y, c, false);
	gfx.PutPixel(4 + x, 2 + y, c, false);
	gfx.PutPixel(5 + x, 2 + y, c, false);
	gfx.PutPixel(6 + x, 2 + y, c, false);
	gfx.PutPixel(7 + x, 2 + y, c, false);
	gfx.PutPixel(0 + x, 3 + y, c, false);
	gfx.PutPixel(1 + x, 3 + y, c, false);
	gfx.PutPixel(2 + x, 3 + y, c, false);
	gfx.PutPixel(3 + x, 3 + y, c, false);
	gfx.PutPixel(4 + x, 3 + y, c, false);
	gfx.PutPixel(5 + x, 3 + y, c, false);
	gfx.PutPixel(6 + x, 3 + y, c, false);
	gfx.PutPixel(7 + x, 3 + y, c, false);
	gfx.PutPixel(8 + x, 3 + y, c, false);
	gfx.PutPixel(7 + x, 4 + y, c, false);
	gfx.PutPixel(8 + x, 4 + y, c, false);
	gfx.PutPixel(9 + x, 4 + y, c, false);
	gfx.PutPixel(7 + x, 5 + y, c, false);
	gfx.PutPixel(8 + x, 5 + y, c, false);
	gfx.PutPixel(9 + x, 5 + y, c, false);
	gfx.PutPixel(1 + x, 6 + y, c, false);
	gfx.PutPixel(2 + x, 6 + y, c, false);
	gfx.PutPixel(3 + x, 6 + y, c, false);
	gfx.PutPixel(4 + x, 6 + y, c, false);
	gfx.PutPixel(5 + x, 6 + y, c, false);
	gfx.PutPixel(6 + x, 6 + y, c, false);
	gfx.PutPixel(7 + x, 6 + y, c, false);
	gfx.PutPixel(8 + x, 6 + y, c, false);
	gfx.PutPixel(1 + x, 7 + y, c, false);
	gfx.PutPixel(2 + x, 7 + y, c, false);
	gfx.PutPixel(3 + x, 7 + y, c, false);
	gfx.PutPixel(4 + x, 7 + y, c, false);
	gfx.PutPixel(5 + x, 7 + y, c, false);
	gfx.PutPixel(6 + x, 7 + y, c, false);
	gfx.PutPixel(7 + x, 7 + y, c, false);
	gfx.PutPixel(8 + x, 7 + y, c, false);
	gfx.PutPixel(9 + x, 7 + y, c, false);
	gfx.PutPixel(8 + x, 8 + y, c, false);
	gfx.PutPixel(9 + x, 8 + y, c, false);
	gfx.PutPixel(7 + x, 9 + y, c, false);
	gfx.PutPixel(8 + x, 9 + y, c, false);
	gfx.PutPixel(9 + x, 9 + y, c, false);
	gfx.PutPixel(0 + x, 10 + y, c, false);
	gfx.PutPixel(1 + x, 10 + y, c, false);
	gfx.PutPixel(2 + x, 10 + y, c, false);
	gfx.PutPixel(3 + x, 10 + y, c, false);
	gfx.PutPixel(4 + x, 10 + y, c, false);
	gfx.PutPixel(5 + x, 10 + y, c, false);
	gfx.PutPixel(6 + x, 10 + y, c, false);
	gfx.PutPixel(7 + x, 10 + y, c, false);
	gfx.PutPixel(8 + x, 10 + y, c, false);
	gfx.PutPixel(9 + x, 10 + y, c, false);
	gfx.PutPixel(0 + x, 11 + y, c, false);
	gfx.PutPixel(1 + x, 11 + y, c, false);
	gfx.PutPixel(2 + x, 11 + y, c, false);
	gfx.PutPixel(3 + x, 11 + y, c, false);
	gfx.PutPixel(4 + x, 11 + y, c, false);
	gfx.PutPixel(5 + x, 11 + y, c, false);
	gfx.PutPixel(6 + x, 11 + y, c, false);
	gfx.PutPixel(7 + x, 11 + y, c, false);
	gfx.PutPixel(8 + x, 11 + y, c, false);

}

void SpriteNumbers::draw4(const Vec2 pos, const Color c, Graphics& gfx)
{
	int x = int(pos.x);
	int y = int(pos.y);
	gfx.PutPixel(4 + x, 2 + y, c, false);
	gfx.PutPixel(5 + x, 2 + y, c, false);
	gfx.PutPixel(6 + x, 2 + y, c, false);
	gfx.PutPixel(3 + x, 3 + y, c, false);
	gfx.PutPixel(4 + x, 3 + y, c, false);
	gfx.PutPixel(5 + x, 3 + y, c, false);
	gfx.PutPixel(6 + x, 3 + y, c, false);
	gfx.PutPixel(7 + x, 3 + y, c, false);
	gfx.PutPixel(2 + x, 4 + y, c, false);
	gfx.PutPixel(3 + x, 4 + y, c, false);
	gfx.PutPixel(4 + x, 4 + y, c, false);
	gfx.PutPixel(5 + x, 4 + y, c, false);
	gfx.PutPixel(6 + x, 4 + y, c, false);
	gfx.PutPixel(7 + x, 4 + y, c, false);
	gfx.PutPixel(1 + x, 5 + y, c, false);
	gfx.PutPixel(2 + x, 5 + y, c, false);
	gfx.PutPixel(3 + x, 5 + y, c, false);
	gfx.PutPixel(6 + x, 5 + y, c, false);
	gfx.PutPixel(7 + x, 5 + y, c, false);
	gfx.PutPixel(1 + x, 6 + y, c, false);
	gfx.PutPixel(2 + x, 6 + y, c, false);
	gfx.PutPixel(3 + x, 6 + y, c, false);
	gfx.PutPixel(4 + x, 6 + y, c, false);
	gfx.PutPixel(5 + x, 6 + y, c, false);
	gfx.PutPixel(6 + x, 6 + y, c, false);
	gfx.PutPixel(7 + x, 6 + y, c, false);
	gfx.PutPixel(8 + x, 6 + y, c, false);
	gfx.PutPixel(9 + x, 6 + y, c, false);
	gfx.PutPixel(1 + x, 7 + y, c, false);
	gfx.PutPixel(2 + x, 7 + y, c, false);
	gfx.PutPixel(3 + x, 7 + y, c, false);
	gfx.PutPixel(4 + x, 7 + y, c, false);
	gfx.PutPixel(5 + x, 7 + y, c, false);
	gfx.PutPixel(6 + x, 7 + y, c, false);
	gfx.PutPixel(7 + x, 7 + y, c, false);
	gfx.PutPixel(8 + x, 7 + y, c, false);
	gfx.PutPixel(9 + x, 7 + y, c, false);
	gfx.PutPixel(6 + x, 8 + y, c, false);
	gfx.PutPixel(7 + x, 8 + y, c, false);
	gfx.PutPixel(6 + x, 9 + y, c, false);
	gfx.PutPixel(7 + x, 9 + y, c, false);
	gfx.PutPixel(6 + x, 10 + y, c, false);
	gfx.PutPixel(7 + x, 10 + y, c, false);
	gfx.PutPixel(6 + x, 11 + y, c, false);
	gfx.PutPixel(7 + x, 11 + y, c, false);

}

void SpriteNumbers::draw5(const Vec2 pos, const Color c, Graphics& gfx)
{
	int x = int(pos.x);
	int y = int(pos.y);
	gfx.PutPixel(0 + x, 2 + y, c, false);
	gfx.PutPixel(1 + x, 2 + y, c, false);
	gfx.PutPixel(2 + x, 2 + y, c, false);
	gfx.PutPixel(3 + x, 2 + y, c, false);
	gfx.PutPixel(4 + x, 2 + y, c, false);
	gfx.PutPixel(5 + x, 2 + y, c, false);
	gfx.PutPixel(6 + x, 2 + y, c, false);
	gfx.PutPixel(7 + x, 2 + y, c, false);
	gfx.PutPixel(8 + x, 2 + y, c, false);
	gfx.PutPixel(9 + x, 2 + y, c, false);
	gfx.PutPixel(0 + x, 3 + y, c, false);
	gfx.PutPixel(1 + x, 3 + y, c, false);
	gfx.PutPixel(2 + x, 3 + y, c, false);
	gfx.PutPixel(3 + x, 3 + y, c, false);
	gfx.PutPixel(4 + x, 3 + y, c, false);
	gfx.PutPixel(5 + x, 3 + y, c, false);
	gfx.PutPixel(6 + x, 3 + y, c, false);
	gfx.PutPixel(7 + x, 3 + y, c, false);
	gfx.PutPixel(8 + x, 3 + y, c, false);
	gfx.PutPixel(9 + x, 3 + y, c, false);
	gfx.PutPixel(0 + x, 4 + y, c, false);
	gfx.PutPixel(1 + x, 4 + y, c, false);
	gfx.PutPixel(0 + x, 5 + y, c, false);
	gfx.PutPixel(1 + x, 5 + y, c, false);
	gfx.PutPixel(0 + x, 6 + y, c, false);
	gfx.PutPixel(1 + x, 6 + y, c, false);
	gfx.PutPixel(2 + x, 6 + y, c, false);
	gfx.PutPixel(3 + x, 6 + y, c, false);
	gfx.PutPixel(4 + x, 6 + y, c, false);
	gfx.PutPixel(5 + x, 6 + y, c, false);
	gfx.PutPixel(6 + x, 6 + y, c, false);
	gfx.PutPixel(7 + x, 6 + y, c, false);
	gfx.PutPixel(8 + x, 6 + y, c, false);
	gfx.PutPixel(0 + x, 7 + y, c, false);
	gfx.PutPixel(1 + x, 7 + y, c, false);
	gfx.PutPixel(2 + x, 7 + y, c, false);
	gfx.PutPixel(3 + x, 7 + y, c, false);
	gfx.PutPixel(4 + x, 7 + y, c, false);
	gfx.PutPixel(5 + x, 7 + y, c, false);
	gfx.PutPixel(6 + x, 7 + y, c, false);
	gfx.PutPixel(7 + x, 7 + y, c, false);
	gfx.PutPixel(8 + x, 7 + y, c, false);
	gfx.PutPixel(9 + x, 7 + y, c, false);
	gfx.PutPixel(8 + x, 8 + y, c, false);
	gfx.PutPixel(9 + x, 8 + y, c, false);
	gfx.PutPixel(7 + x, 9 + y, c, false);
	gfx.PutPixel(8 + x, 9 + y, c, false);
	gfx.PutPixel(9 + x, 9 + y, c, false);
	gfx.PutPixel(0 + x, 10 + y, c, false);
	gfx.PutPixel(1 + x, 10 + y, c, false);
	gfx.PutPixel(2 + x, 10 + y, c, false);
	gfx.PutPixel(3 + x, 10 + y, c, false);
	gfx.PutPixel(4 + x, 10 + y, c, false);
	gfx.PutPixel(5 + x, 10 + y, c, false);
	gfx.PutPixel(6 + x, 10 + y, c, false);
	gfx.PutPixel(7 + x, 10 + y, c, false);
	gfx.PutPixel(8 + x, 10 + y, c, false);
	gfx.PutPixel(9 + x, 10 + y, c, false);
	gfx.PutPixel(0 + x, 11 + y, c, false);
	gfx.PutPixel(1 + x, 11 + y, c, false);
	gfx.PutPixel(2 + x, 11 + y, c, false);
	gfx.PutPixel(3 + x, 11 + y, c, false);
	gfx.PutPixel(4 + x, 11 + y, c, false);
	gfx.PutPixel(5 + x, 11 + y, c, false);
	gfx.PutPixel(6 + x, 11 + y, c, false);
	gfx.PutPixel(7 + x, 11 + y, c, false);
	gfx.PutPixel(8 + x, 11 + y, c, false);

}

void SpriteNumbers::draw6(const Vec2 pos, const Color c, Graphics& gfx)
{
	int x = int(pos.x);
	int y = int(pos.y);
	gfx.PutPixel(1 + x, 2 + y, c, false);
	gfx.PutPixel(2 + x, 2 + y, c, false);
	gfx.PutPixel(3 + x, 2 + y, c, false);
	gfx.PutPixel(4 + x, 2 + y, c, false);
	gfx.PutPixel(5 + x, 2 + y, c, false);
	gfx.PutPixel(6 + x, 2 + y, c, false);
	gfx.PutPixel(7 + x, 2 + y, c, false);
	gfx.PutPixel(8 + x, 2 + y, c, false);
	gfx.PutPixel(0 + x, 3 + y, c, false);
	gfx.PutPixel(1 + x, 3 + y, c, false);
	gfx.PutPixel(2 + x, 3 + y, c, false);
	gfx.PutPixel(3 + x, 3 + y, c, false);
	gfx.PutPixel(4 + x, 3 + y, c, false);
	gfx.PutPixel(5 + x, 3 + y, c, false);
	gfx.PutPixel(6 + x, 3 + y, c, false);
	gfx.PutPixel(7 + x, 3 + y, c, false);
	gfx.PutPixel(8 + x, 3 + y, c, false);
	gfx.PutPixel(0 + x, 4 + y, c, false);
	gfx.PutPixel(1 + x, 4 + y, c, false);
	gfx.PutPixel(2 + x, 4 + y, c, false);
	gfx.PutPixel(0 + x, 5 + y, c, false);
	gfx.PutPixel(1 + x, 5 + y, c, false);
	gfx.PutPixel(0 + x, 6 + y, c, false);
	gfx.PutPixel(1 + x, 6 + y, c, false);
	gfx.PutPixel(4 + x, 6 + y, c, false);
	gfx.PutPixel(5 + x, 6 + y, c, false);
	gfx.PutPixel(6 + x, 6 + y, c, false);
	gfx.PutPixel(7 + x, 6 + y, c, false);
	gfx.PutPixel(8 + x, 6 + y, c, false);
	gfx.PutPixel(0 + x, 7 + y, c, false);
	gfx.PutPixel(1 + x, 7 + y, c, false);
	gfx.PutPixel(4 + x, 7 + y, c, false);
	gfx.PutPixel(5 + x, 7 + y, c, false);
	gfx.PutPixel(6 + x, 7 + y, c, false);
	gfx.PutPixel(7 + x, 7 + y, c, false);
	gfx.PutPixel(8 + x, 7 + y, c, false);
	gfx.PutPixel(9 + x, 7 + y, c, false);
	gfx.PutPixel(0 + x, 8 + y, c, false);
	gfx.PutPixel(1 + x, 8 + y, c, false);
	gfx.PutPixel(8 + x, 8 + y, c, false);
	gfx.PutPixel(9 + x, 8 + y, c, false);
	gfx.PutPixel(0 + x, 9 + y, c, false);
	gfx.PutPixel(1 + x, 9 + y, c, false);
	gfx.PutPixel(2 + x, 9 + y, c, false);
	gfx.PutPixel(7 + x, 9 + y, c, false);
	gfx.PutPixel(8 + x, 9 + y, c, false);
	gfx.PutPixel(9 + x, 9 + y, c, false);
	gfx.PutPixel(0 + x, 10 + y, c, false);
	gfx.PutPixel(1 + x, 10 + y, c, false);
	gfx.PutPixel(2 + x, 10 + y, c, false);
	gfx.PutPixel(3 + x, 10 + y, c, false);
	gfx.PutPixel(4 + x, 10 + y, c, false);
	gfx.PutPixel(5 + x, 10 + y, c, false);
	gfx.PutPixel(6 + x, 10 + y, c, false);
	gfx.PutPixel(7 + x, 10 + y, c, false);
	gfx.PutPixel(8 + x, 10 + y, c, false);
	gfx.PutPixel(2 + x, 11 + y, c, false);
	gfx.PutPixel(3 + x, 11 + y, c, false);
	gfx.PutPixel(4 + x, 11 + y, c, false);
	gfx.PutPixel(5 + x, 11 + y, c, false);
	gfx.PutPixel(6 + x, 11 + y, c, false);
	gfx.PutPixel(7 + x, 11 + y, c, false);

}

void SpriteNumbers::draw7(const Vec2 pos, const Color c, Graphics& gfx)
{
	int x = int(pos.x);
	int y = int(pos.y);
	gfx.PutPixel(0 + x, 2 + y, c, false);
	gfx.PutPixel(1 + x, 2 + y, c, false);
	gfx.PutPixel(2 + x, 2 + y, c, false);
	gfx.PutPixel(3 + x, 2 + y, c, false);
	gfx.PutPixel(4 + x, 2 + y, c, false);
	gfx.PutPixel(5 + x, 2 + y, c, false);
	gfx.PutPixel(6 + x, 2 + y, c, false);
	gfx.PutPixel(7 + x, 2 + y, c, false);
	gfx.PutPixel(8 + x, 2 + y, c, false);
	gfx.PutPixel(0 + x, 3 + y, c, false);
	gfx.PutPixel(1 + x, 3 + y, c, false);
	gfx.PutPixel(2 + x, 3 + y, c, false);
	gfx.PutPixel(3 + x, 3 + y, c, false);
	gfx.PutPixel(4 + x, 3 + y, c, false);
	gfx.PutPixel(5 + x, 3 + y, c, false);
	gfx.PutPixel(6 + x, 3 + y, c, false);
	gfx.PutPixel(7 + x, 3 + y, c, false);
	gfx.PutPixel(8 + x, 3 + y, c, false);
	gfx.PutPixel(9 + x, 3 + y, c, false);
	gfx.PutPixel(7 + x, 4 + y, c, false);
	gfx.PutPixel(8 + x, 4 + y, c, false);
	gfx.PutPixel(9 + x, 4 + y, c, false);
	gfx.PutPixel(8 + x, 5 + y, c, false);
	gfx.PutPixel(9 + x, 5 + y, c, false);
	gfx.PutPixel(8 + x, 6 + y, c, false);
	gfx.PutPixel(9 + x, 6 + y, c, false);
	gfx.PutPixel(8 + x, 7 + y, c, false);
	gfx.PutPixel(9 + x, 7 + y, c, false);
	gfx.PutPixel(8 + x, 8 + y, c, false);
	gfx.PutPixel(9 + x, 8 + y, c, false);
	gfx.PutPixel(8 + x, 9 + y, c, false);
	gfx.PutPixel(9 + x, 9 + y, c, false);
	gfx.PutPixel(8 + x, 10 + y, c, false);
	gfx.PutPixel(9 + x, 10 + y, c, false);
	gfx.PutPixel(8 + x, 11 + y, c, false);
	gfx.PutPixel(9 + x, 11 + y, c, false);

}

void SpriteNumbers::draw8(const Vec2 pos, const Color c, Graphics& gfx)
{
	int x = int(pos.x);
	int y = int(pos.y);
	gfx.PutPixel(2 + x, 2 + y, c, false);
	gfx.PutPixel(3 + x, 2 + y, c, false);
	gfx.PutPixel(4 + x, 2 + y, c, false);
	gfx.PutPixel(5 + x, 2 + y, c, false);
	gfx.PutPixel(6 + x, 2 + y, c, false);
	gfx.PutPixel(7 + x, 2 + y, c, false);
	gfx.PutPixel(1 + x, 3 + y, c, false);
	gfx.PutPixel(2 + x, 3 + y, c, false);
	gfx.PutPixel(3 + x, 3 + y, c, false);
	gfx.PutPixel(4 + x, 3 + y, c, false);
	gfx.PutPixel(5 + x, 3 + y, c, false);
	gfx.PutPixel(6 + x, 3 + y, c, false);
	gfx.PutPixel(7 + x, 3 + y, c, false);
	gfx.PutPixel(8 + x, 3 + y, c, false);
	gfx.PutPixel(0 + x, 4 + y, c, false);
	gfx.PutPixel(1 + x, 4 + y, c, false);
	gfx.PutPixel(2 + x, 4 + y, c, false);
	gfx.PutPixel(7 + x, 4 + y, c, false);
	gfx.PutPixel(8 + x, 4 + y, c, false);
	gfx.PutPixel(9 + x, 4 + y, c, false);
	gfx.PutPixel(0 + x, 5 + y, c, false);
	gfx.PutPixel(1 + x, 5 + y, c, false);
	gfx.PutPixel(2 + x, 5 + y, c, false);
	gfx.PutPixel(7 + x, 5 + y, c, false);
	gfx.PutPixel(8 + x, 5 + y, c, false);
	gfx.PutPixel(9 + x, 5 + y, c, false);
	gfx.PutPixel(1 + x, 6 + y, c, false);
	gfx.PutPixel(2 + x, 6 + y, c, false);
	gfx.PutPixel(3 + x, 6 + y, c, false);
	gfx.PutPixel(4 + x, 6 + y, c, false);
	gfx.PutPixel(5 + x, 6 + y, c, false);
	gfx.PutPixel(6 + x, 6 + y, c, false);
	gfx.PutPixel(7 + x, 6 + y, c, false);
	gfx.PutPixel(8 + x, 6 + y, c, false);
	gfx.PutPixel(0 + x, 7 + y, c, false);
	gfx.PutPixel(1 + x, 7 + y, c, false);
	gfx.PutPixel(2 + x, 7 + y, c, false);
	gfx.PutPixel(3 + x, 7 + y, c, false);
	gfx.PutPixel(4 + x, 7 + y, c, false);
	gfx.PutPixel(5 + x, 7 + y, c, false);
	gfx.PutPixel(6 + x, 7 + y, c, false);
	gfx.PutPixel(7 + x, 7 + y, c, false);
	gfx.PutPixel(8 + x, 7 + y, c, false);
	gfx.PutPixel(9 + x, 7 + y, c, false);
	gfx.PutPixel(0 + x, 8 + y, c, false);
	gfx.PutPixel(1 + x, 8 + y, c, false);
	gfx.PutPixel(2 + x, 8 + y, c, false);
	gfx.PutPixel(8 + x, 8 + y, c, false);
	gfx.PutPixel(9 + x, 8 + y, c, false);
	gfx.PutPixel(0 + x, 9 + y, c, false);
	gfx.PutPixel(1 + x, 9 + y, c, false);
	gfx.PutPixel(2 + x, 9 + y, c, false);
	gfx.PutPixel(7 + x, 9 + y, c, false);
	gfx.PutPixel(8 + x, 9 + y, c, false);
	gfx.PutPixel(9 + x, 9 + y, c, false);
	gfx.PutPixel(0 + x, 10 + y, c, false);
	gfx.PutPixel(1 + x, 10 + y, c, false);
	gfx.PutPixel(2 + x, 10 + y, c, false);
	gfx.PutPixel(3 + x, 10 + y, c, false);
	gfx.PutPixel(4 + x, 10 + y, c, false);
	gfx.PutPixel(5 + x, 10 + y, c, false);
	gfx.PutPixel(6 + x, 10 + y, c, false);
	gfx.PutPixel(7 + x, 10 + y, c, false);
	gfx.PutPixel(8 + x, 10 + y, c, false);
	gfx.PutPixel(9 + x, 10 + y, c, false);
	gfx.PutPixel(2 + x, 11 + y, c, false);
	gfx.PutPixel(3 + x, 11 + y, c, false);
	gfx.PutPixel(4 + x, 11 + y, c, false);
	gfx.PutPixel(5 + x, 11 + y, c, false);
	gfx.PutPixel(6 + x, 11 + y, c, false);
	gfx.PutPixel(7 + x, 11 + y, c, false);
	gfx.PutPixel(8 + x, 11 + y, c, false);

}

void SpriteNumbers::draw9(const Vec2 pos, const Color c, Graphics& gfx)
{
	int x = int(pos.x);
	int y = int(pos.y);
	gfx.PutPixel(2 + x, 2 + y, c, false);
	gfx.PutPixel(3 + x, 2 + y, c, false);
	gfx.PutPixel(4 + x, 2 + y, c, false);
	gfx.PutPixel(5 + x, 2 + y, c, false);
	gfx.PutPixel(6 + x, 2 + y, c, false);
	gfx.PutPixel(7 + x, 2 + y, c, false);
	gfx.PutPixel(8 + x, 2 + y, c, false);
	gfx.PutPixel(1 + x, 3 + y, c, false);
	gfx.PutPixel(2 + x, 3 + y, c, false);
	gfx.PutPixel(3 + x, 3 + y, c, false);
	gfx.PutPixel(4 + x, 3 + y, c, false);
	gfx.PutPixel(5 + x, 3 + y, c, false);
	gfx.PutPixel(6 + x, 3 + y, c, false);
	gfx.PutPixel(7 + x, 3 + y, c, false);
	gfx.PutPixel(8 + x, 3 + y, c, false);
	gfx.PutPixel(9 + x, 3 + y, c, false);
	gfx.PutPixel(1 + x, 4 + y, c, false);
	gfx.PutPixel(2 + x, 4 + y, c, false);
	gfx.PutPixel(3 + x, 4 + y, c, false);
	gfx.PutPixel(7 + x, 4 + y, c, false);
	gfx.PutPixel(8 + x, 4 + y, c, false);
	gfx.PutPixel(9 + x, 4 + y, c, false);
	gfx.PutPixel(1 + x, 5 + y, c, false);
	gfx.PutPixel(2 + x, 5 + y, c, false);
	gfx.PutPixel(3 + x, 5 + y, c, false);
	gfx.PutPixel(8 + x, 5 + y, c, false);
	gfx.PutPixel(9 + x, 5 + y, c, false);
	gfx.PutPixel(1 + x, 6 + y, c, false);
	gfx.PutPixel(2 + x, 6 + y, c, false);
	gfx.PutPixel(3 + x, 6 + y, c, false);
	gfx.PutPixel(4 + x, 6 + y, c, false);
	gfx.PutPixel(5 + x, 6 + y, c, false);
	gfx.PutPixel(6 + x, 6 + y, c, false);
	gfx.PutPixel(8 + x, 6 + y, c, false);
	gfx.PutPixel(9 + x, 6 + y, c, false);
	gfx.PutPixel(2 + x, 7 + y, c, false);
	gfx.PutPixel(3 + x, 7 + y, c, false);
	gfx.PutPixel(4 + x, 7 + y, c, false);
	gfx.PutPixel(5 + x, 7 + y, c, false);
	gfx.PutPixel(6 + x, 7 + y, c, false);
	gfx.PutPixel(8 + x, 7 + y, c, false);
	gfx.PutPixel(9 + x, 7 + y, c, false);
	gfx.PutPixel(8 + x, 8 + y, c, false);
	gfx.PutPixel(9 + x, 8 + y, c, false);
	gfx.PutPixel(7 + x, 9 + y, c, false);
	gfx.PutPixel(8 + x, 9 + y, c, false);
	gfx.PutPixel(9 + x, 9 + y, c, false);
	gfx.PutPixel(1 + x, 10 + y, c, false);
	gfx.PutPixel(2 + x, 10 + y, c, false);
	gfx.PutPixel(3 + x, 10 + y, c, false);
	gfx.PutPixel(4 + x, 10 + y, c, false);
	gfx.PutPixel(5 + x, 10 + y, c, false);
	gfx.PutPixel(6 + x, 10 + y, c, false);
	gfx.PutPixel(7 + x, 10 + y, c, false);
	gfx.PutPixel(8 + x, 10 + y, c, false);
	gfx.PutPixel(9 + x, 10 + y, c, false);
	gfx.PutPixel(1 + x, 11 + y, c, false);
	gfx.PutPixel(2 + x, 11 + y, c, false);
	gfx.PutPixel(3 + x, 11 + y, c, false);
	gfx.PutPixel(4 + x, 11 + y, c, false);
	gfx.PutPixel(5 + x, 11 + y, c, false);
	gfx.PutPixel(6 + x, 11 + y, c, false);
	gfx.PutPixel(7 + x, 11 + y, c, false);
	gfx.PutPixel(8 + x, 11 + y, c, false);

}
