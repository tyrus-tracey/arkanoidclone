#include "brickArray.h"

brickArray::brickArray()
	: pos(-1,-1), rows(0), cols(0)
{
}

brickArray::brickArray(Vec2 spawnPos)
	: pos(spawnPos), rows(N_COLORS), cols(8)
{
	//index = y*cols + x
	float xCoor;
	float yCoor;
	bricks = new brick[rows * cols];
	//bricks = (brick*)malloc(sizeof(brick) * rows * cols);
	for (unsigned int y = 0; y < rows; ++y) {
		for (unsigned int x = 0; x < cols; ++x) {
			xCoor = float(x) * brick::getWidth();
			yCoor = float(y) * brick::getHeight();
			bricks[(y * cols) + x] = brick(Vec2(xCoor, yCoor), y);
		}
	}
}

brickArray::~brickArray()
{
	if (bricks != NULL) {
		delete bricks;
	}
}

void brickArray::update(ball& b)
{
	if (bricks != NULL) {
		for (unsigned int i = 0; i < rows * cols; i++) {
			bricks[i].update(b);
		}
	}
}

void brickArray::draw(Graphics& gfx)
{
	if (bricks != NULL) {
		for (unsigned int i = 0; i < rows * cols; i++) {
			bricks[i].draw(gfx);
		}
	}
}

//brickArray::brickArray(Vec2 spawnPos, unsigned int numRows, unsigned int numCols)
//	: pos(spawnPos), rows(numRows), cols(numCols)
//{
//	bricks = (brick*) malloc(sizeof(brick) * (numRows * numCols));
//}
