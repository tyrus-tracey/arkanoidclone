#pragma once
#include <utility>
#include "Vec2.h"
#include "brick.h"

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
		case MICRO:		return gridLocation(7, 13);
		case LIGHT:		return gridLocation(9, 20);
		case NORMAL:	return gridLocation(11, 25);
		case BIG:		return gridLocation(15, 30);
		default:		return gridLocation(0, 0);
		}
	};

	static Vec2 getSize(const wallSizeEnum e) {
		gridLocation grid = getGridDims(e);
		return Vec2(grid.x * brick::getWidth(), grid.y * brick::getHeight());
	}
};
