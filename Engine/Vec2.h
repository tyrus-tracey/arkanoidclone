#pragma once
#include <cmath>

class Vec2
{
public:
	Vec2() = default;
	Vec2( float x_in,float y_in );
	Vec2 operator+( const Vec2& rhs ) const;
	Vec2& operator+=( const Vec2& rhs );
	Vec2 operator*( float rhs ) const;
	Vec2& operator*=( float rhs );
	Vec2 operator-( const Vec2& rhs ) const;
	Vec2& operator-=( const Vec2& rhs );
	bool operator==(const Vec2& rhs) const;
	bool operator!=(const Vec2& rhs) const;
	float GetLength() const;
	float GetLengthSq() const;
	Vec2& Normalize();
	Vec2 GetNormalized() const;
	Vec2 GetAbsolute() const;
	Vec2 GetProjectionOnto(const Vec2& other) const;
	float GetDotProduct(const Vec2& other) const;
	float getDistance(const Vec2& other) const;
	Vec2 getReverse() const;

public:
	float x;
	float y;
};