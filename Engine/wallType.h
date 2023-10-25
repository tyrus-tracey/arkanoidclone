#pragma once
#include <utility>
#include "Vec2.h"
#include "gridLocation.h"
#include "gameVals.h"

/*
MICRO:
7x13 bricks = 420x600
LIGHT :
9x20 bricks = 540x700
NORMAL :
11x25 bricks = 660x800
BIG :
15x30 bricks = 900x900
*/

enum wallSizeEnum {
	MICRO, LIGHT, NORMAL, BIG
};

struct wallType {
	static gridLocation getGridDims(const wallSizeEnum e) {
		switch (e) {
		case MICRO:		return gridLocation(7, 30);
		case LIGHT:		return gridLocation(9, 35);
		case NORMAL:	return gridLocation(11, 40);
		case BIG:		return gridLocation(15, 45);
		default:		return gridLocation(0, 0);
		}
	};

	static Vec2 getSize(const wallSizeEnum e) {
		gridLocation grid = getGridDims(e);
		float x = grid.x * BRICK_WIDTH;
		float y = grid.y * BRICK_HEIGHT;
		return Vec2(grid.x * BRICK_WIDTH, grid.y * BRICK_HEIGHT);
	}
};
