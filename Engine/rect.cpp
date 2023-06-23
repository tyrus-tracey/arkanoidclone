#include "rect.h"

rect::rect()
	: top(0), left(0), bottom(0), right(0)
{
}

rect::rect(const float in_t, const float in_l, const float in_b, const float in_r)
{
	if (in_t < in_b) {
		top = in_t;
		bottom = in_b;
	}
	else {
		top = in_b;
		bottom = in_t;
	}
	if (in_l < in_r) {
		left = in_l;
		right = in_r;
	}
	else {
		left = in_r;
		right = in_l;
	}
}

rect::rect(const Vec2& topLeft, const Vec2& bottomRight)
	: top(topLeft.y), left(topLeft.x), bottom(bottomRight.y), right(bottomRight.x)
{
}

rect::rect(const Vec2& topLeft, const float width, const float height)
	: rect(topLeft, Vec2(topLeft.x + width, topLeft.y + height))
{
}

bool rect::isOverlapping(const rect& other) const
{
	return right > other.left && other.right > left
		&& bottom > other.top && other.bottom > top;
}
