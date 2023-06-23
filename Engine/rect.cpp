#include "rect.h"

rect::rect()
	: left(0), right(0), top(0), bottom(0)
{
}

rect::rect(const float in_l, const float in_r, const float in_t, const float in_b)
	: left(in_l), right(in_r), top(in_t), bottom(in_b)
{
}

rect::rect(const Vec2& topLeft, const float width, const float height)
	: rect(topLeft, Vec2(topLeft.x + width, topLeft.y + height))
{
}

rect::rect(const Vec2& topLeft, const Vec2& bottomRight)
	: left(topLeft.x), right(bottomRight.x), top(topLeft.y), bottom(bottomRight.y)
{
}