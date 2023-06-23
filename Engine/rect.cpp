#include "rect.h"

rect::rect()
	: top(0), left(0), bottom(0), right(0)
{
}

rect::rect(const float in_t, const float in_l, const float in_b, const float in_r)
	: top(in_t), left(in_l), bottom(in_b), right(in_r)
{
}

rect::rect(const Vec2& topLeft, const Vec2& bottomRight)
	: top(topLeft.y), left(topLeft.x), bottom(bottomRight.y), right(bottomRight.y)
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