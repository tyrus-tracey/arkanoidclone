#include "Shape.h"


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
	float heightMid = (bottom - top) / 2.0f;
	float widthMid = (right - left) / 2.0f;
	return Vec2(left + widthMid, top + heightMid);
}

// Returns a rect whose bounds have been uniformly added/subtracted.
// Positive values enlarges rect, negative values shrink rect.
rect rect::getResizeUniform(const float amt) const
{
	return rect(top - amt, left - amt, bottom + amt, right + amt);
}

// Uniformly adds/subtracts rect bounds.
// Positive values enlarges rect, negative values shrink rect.
rect& rect::resizeUniform(const float amt)
{
	return *this = getResizeUniform(amt);
}

float rect::getWidth() const
{
	return right - left;
}

float rect::getHeight() const
{
	return bottom - top;
}

void rect::centerOnto(const rect& parent)
{
	float width = right - left;
	float height = bottom - top;
	float p_width = parent.right - parent.left;
	float p_height = parent.bottom - parent.top;

	top = parent.bottom - (p_height / 2.0f) - (height / 2.0f);
	bottom = top + height;
	left = parent.right - (p_width / 2.0f) - (width / 2.0f);
	right = left + width;
}

void rect::move(const Vec2 vec)
{
	top += vec.y;
	bottom += vec.y;
	left += vec.x;
	right += vec.x;
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
		left <= vec.x &&
		right >= vec.x &&
		top <= vec.y &&
		bottom >= vec.y;
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
	rect bounds = other.getResizeUniform(padding * -1.0f);

	out.left = out.left < bounds.left ? bounds.left : out.left;
	out.top = out.top < bounds.top ? bounds.top : out.top;
	out.right = out.right > bounds.right ? bounds.right : out.right;
	out.bottom = out.bottom > bounds.bottom ? bounds.bottom : out.bottom;
	return out;
}

// Fits rect to within (inclusive) supplied rect bounds.
// Positive padding enlarges rect relative to supplied.
// Negative padding shrinks rect relative to supplied.
rect& rect::fitTo(const rect& other, const float padding)
{
	return *this = getFittedRect(other, padding);
}

midRect::midRect(const Vec2& _midPoint, const float width, const float height)
	: midPoint(_midPoint)
{
	top = midPoint.y - (height / 2);
	bottom = midPoint.y + (height / 2);
	left = midPoint.x - (width / 2);
	right = midPoint.x + (width / 2);
}

Vec2 midRect::getMidpoint() const
{
	return midPoint;
}


circle::circle(const Vec2 _point, const float _radius)
	: point(_point)
{
	radius = _radius < 0.0f ? 0.0f : _radius;
}

Vec2 circle::getPoint() const
{
	return point;
}

float circle::getRadius() const
{
	return radius;
}

void circle::move(const Vec2 vec)
{
	point += vec;
}

void circle::scale(const float amt)
{
	constexpr float F_MIN = std::numeric_limits<float>::min();
	constexpr float F_MAX = std::numeric_limits<float>::max();
	if (F_MIN - amt > radius) {
		radius = F_MIN;
	}
	else if (F_MAX - amt < radius) {
		radius = F_MAX;
	}
	if (radius < 0.0f) { radius = 0.0f; }
	return;
}

bool circle::isOverlapping(const rect& other) const
{
	const Vec2 OTHER_MIDPOINT = other.getMidpoint();
	const Vec2 V_MIDPOINTS = OTHER_MIDPOINT - point;
	const float DIST_MIDPOINTS = V_MIDPOINTS.GetLength();

	Vec2 closestPoint;
	closestPoint.x = clamp(point.x, other.left, other.right);
	closestPoint.y = clamp(point.y, other.top, other.bottom);

	const float DIST_CLOSEST_FROM_RECT = closestPoint.getDistance(other.getMidpoint());

	if (DIST_MIDPOINTS - radius <= DIST_CLOSEST_FROM_RECT) {
		return true;
	}
	return false;
}

float circle::clamp(const float f, float _min, float _max) const 
{
	if (_min > _max) {
		std::swap(_min, _max);
	}
	if (f < _min) { return _min; }
	else if (f > _max) { return _max; }
	else return f;
}