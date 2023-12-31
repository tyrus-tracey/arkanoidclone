#pragma once

namespace Helpy
{
	template <typename T> 
	static T clamp(const T val, T _min, T _max)
	{
		if (_min > _max) {
			std::swap(_min, _max);
		}
		if (val < _min) { return _min; }
		else if (val > _max) { return _max; }
		else { return val; }
	}
};