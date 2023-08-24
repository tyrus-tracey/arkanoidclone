#include "ticker.h"

ticker::ticker(const float startTime)
	: START_TIME(startTime), time(startTime)
{
}

void ticker::reset()
{
	time = START_TIME;
	active = true;
}

void ticker::stop()
{
	active = false;
}

void ticker::tick(float dt)
{
	if (!isActive()) { return; }
	time -= dt;
	if (time < 0.00001f) { stop(); }
}

bool ticker::isActive() const
{
	return active;
}

bool ticker::ended() const
{
	return time < 0.00001f;
	return false;
}
