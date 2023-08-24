#pragma once

struct gridLocation {
	gridLocation(int in_x, int in_y);
	int x;
	int y;
	gridLocation operator+(const gridLocation& rhs) const;
	gridLocation& operator+=(const gridLocation& rhs);
	gridLocation operator-(const gridLocation& rhs) const;
	gridLocation& operator-=(const gridLocation& rhs);
};
