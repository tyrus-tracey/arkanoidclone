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

Vec2 rect::getMidpoint() const
{
	float heightMid = (bottom - top)/2.0f;
	float widthMid = (right - left)/2.0f;
	return Vec2(left+widthMid, top+heightMid);
}

// Returns a rect whose bounds have been uniformly added/subtracted.
// Positive values enlarges rect, negative values shrink rect.
rect rect::getResizeUniform(const float amt) const
{
	return rect(top-amt, left-amt, bottom+amt, right+amt);
}

// Uniformly adds/subtracts rect bounds.
// Positive values enlarges rect, negative values shrink rect.
rect& rect::resizeUniform(const float amt)
{
	return *this = getResizeUniform(amt);
}

rect::rect(const Vec2& topLeft, const float width, const float height)
	: rect(topLeft, Vec2(topLeft.x + width, topLeft.y + height))
{
}

// Non-inclusive overlap check. (should be inclusive?)
bool rect::isOverlapping(const rect& other) const
{
	return right > other.left && other.right > left
		&& bottom > other.top && other.bottom > top;
}

// Inclusive overlap check
bool rect::isOverlapping(const Vec2 vec) const
{
	return
		left	<= vec.x &&
		right	>= vec.x &&
		top		<= vec.y &&
		bottom	>= vec.y;
}

// Whether rect is within (inclusive) supplied rect.
bool rect::isWithin(const rect& other) const
{
	return
		left >= other.left &&
		right <= other.right &&
		top >= other.top &&
		bottom <= other.bottom;
}

// Returns a rect whose bounds do not exceed supplied rect.
// Positive padding enlarges rect relative to supplied.
// Negative padding shrinks rect relative to supplied.
rect rect::getFittedRect(const rect& other, const float padding) const
{
	rect out = *this;
	rect bounds = other.getResizeUniform(padding*-1.0f);
	
	out.left = out.left		< bounds.left	?	bounds.left	  : out.left;
	out.top	= out.top		< bounds.top	?	bounds.top	  : out.top;
	out.right = out.right	> bounds.right	?	bounds.right  : out.right;
	out.bottom = out.bottom	> bounds.bottom	?	bounds.bottom : out.bottom;
	return out;
}

// Fits rect to within (inclusive) supplied rect bounds.
// Positive padding enlarges rect relative to supplied.
// Negative padding shrinks rect relative to supplied.
rect& rect::fitTo(const rect& other, const float padding)
{
	return *this = getFittedRect(other, padding);
}
