#include "ticker.h"

ticker::ticker()
	: START_TIME(0.0f), time(0.0f)
{
}

ticker::ticker(const float startTime)
	: START_TIME(startTime), time(startTime)
{
}

void ticker::restart()
{
	resetTime();
	wake();
}

void ticker::resetTime()
{
	time = START_TIME;
}

void ticker::wake()
{
	active = true;
}

void ticker::sleep()
{
	active = false;
}

void ticker::tick(float dt)
{
	if (!isActive()) { return; }
	time -= dt;
	if (time < 0.00001f) { sleep(); }
}

void ticker::forceEnd()
{
	time = -1.0f;
}

bool ticker::isActive() const
{
	return active;
}

bool ticker::ended() const
{
	return time < 0.00001f;
}
