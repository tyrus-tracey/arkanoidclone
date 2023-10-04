#include "oscillator.h"

oscillator::oscillator(const float interval)
	: tOn(interval), tOff(interval)
{
}

oscillator::oscillator(const float timeOn, const float timeOff)
	: tOn(timeOn), tOff(timeOff)
{
}

void oscillator::tick(const float dt)
{
	if (!isActive()) { return; }
	tOn.tick(dt);
	if (tOn.ended()) {
		tOff.tick(dt);
		if (tOff.ended()) {
			restart();
		}
	}
}

void oscillator::restart()
{
	tOn.restart();
	tOff.restart();
}

void oscillator::resetInterval()
{
	tOn.resetTime();
	tOff.resetTime();
}

void oscillator::wake()
{
	tOn.wake();
	tOff.wake();
}

void oscillator::sleep()
{
	tOn.sleep();
	tOff.sleep();
}

// If the "On" portion of the oscillator is currently active.
bool oscillator::isOn() const
{
	return tOn.isActive();
}

// If the oscillator as a whole is active.
bool oscillator::isActive() const
{
	return tOn.isActive() || tOff.isActive();
}
