#pragma once
#include "Graphics.h"
#include "Colors.h"
#include "Vec2.h"
#include "brick.h"
#include "ball.h"

class brickArray
{
public:
	brickArray();
	brickArray(Vec2 spawnPos);
	~brickArray();
	//brickArray(Vec2 spawnPos, unsigned int numRows, unsigned int numCols);
	void update(ball& b);
	void draw(Graphics& gfx);
private:
	Vec2 pos;
	unsigned int rows;
	unsigned int cols;
	brick* bricks;

	static const unsigned int N_COLORS = 5;
	Color cArr[N_COLORS] = { Colors::Red, Colors::Cyan, Colors::Yellow, Colors::Green, Colors::Gray };
};

