#include "ticker.h"

ticker::ticker(const float startTime)
	: START_TIME(startTime)
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
	if (isActive()) { return; }
	time -= dt;
	if (time < 0.0001f) { stop(); }
}

bool ticker::isActive() const
{
	return !active;
}
