#pragma once
#include "Vec2.h"
#include "Helpy.h"
#include <limits>
#include <vector>

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
	float getWidth() const;
	float getHeight() const;
	void centerOnto(const rect& parent);
	void move(const Vec2 vec);
	bool isOverlapping(const rect& other) const;
	bool isOverlapping(const Vec2 other) const;
	bool isWithin(const rect& other) const;
	rect getFittedRect(const rect& other, const float padding) const;
	rect& fitTo(const rect& other, const float padding);
	Vec2 getClosestVecTo(const Vec2 other) const;
	Vec2 getClosestCornerTo(const Vec2 other) const;

	float top;
	float left;
	float bottom;
	float right;
};

class midRect : public rect {
public:
	midRect(const Vec2& _midPoint, const float width, const float height);
	Vec2 getMidpoint() const;

	Vec2 midPoint;
};

class circle {
public:
	circle() = default;
	circle(const Vec2 _point, const float _radius);
	Vec2 getPoint() const;
	float getRadius() const;
	void move(const Vec2 vec);
	void scale(const float amt);
	bool isOverlapping(const rect& other) const;

private:
	Vec2 point;
	float radius;
};