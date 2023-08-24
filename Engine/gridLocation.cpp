#include "gridLocation.h"

gridLocation::gridLocation(int in_x, int in_y)
	: x(in_x), y(in_y)
{
}

gridLocation gridLocation::operator+(const gridLocation& rhs) const
{
	return gridLocation(x + rhs.x, y + rhs.y);
}

gridLocation& gridLocation::operator+=(const gridLocation& rhs)
{
	return *this = *this + rhs;
}

gridLocation gridLocation::operator-(const gridLocation& rhs) const
{
	return gridLocation(x - rhs.x, y - rhs.y);
}

gridLocation& gridLocation::operator-=(const gridLocation& rhs)
{
	return *this = *this - rhs;
}