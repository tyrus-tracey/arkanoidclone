#pragma once
#include "Vec2.h"
#include "Graphics.h"

class rect
{
public:
	rect();
	rect(const float in_l, const float in_r, const float in_t, const float in_b);
	rect(const Vec2& topLeft, const float width, const float height);
	rect(const Vec2& topLeft, const Vec2& bottomRight);
	
	float top;
	float left;
	float bottom;
	float right;
};

