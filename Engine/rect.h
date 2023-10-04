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
	rect& resizeUniform(const float amt);
	void centerOnto(const rect& parent);
	void move(const Vec2 vec);
	bool isOverlapping(const rect& other) const;
	bool isOverlapping(const Vec2 other) const;
	bool isWithin(const rect& other) const;
	rect getFittedRect(const rect& other, const float padding) const;
	rect& fitTo(const rect& other, const float padding);

	float top;
	float left;
	float bottom;
	float right;
};

