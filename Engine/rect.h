#pragma once
#include "Vec2.h"

class rect
{
public:
	rect();
	rect(const float in_t, const float in_l, const float in_b, const float in_r);
	rect(const Vec2& topLeft, const float width, const float height);
	rect(const Vec2& topLeft, const Vec2& bottomRight);
	Vec2 getMidpoint() const;
	rect getResizeUniform(const float amt) const;
	bool isOverlapping(const rect& other) const;

	float top;
	float left;
	float bottom;
	float right;
};

