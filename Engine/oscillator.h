#pragma once
#include "ticker.h"

// Two tickers, one active while the other is off, and vice versa.
class oscillator
{
public:
    oscillator(const float interval);
    oscillator(const float timeOn, const float timeOff);
    void tick(const float dt);
    void restart();
    void resetInterval();
    void sleep();
    void wake();
    bool isOn() const;
    bool isActive() const;

private:
    ticker tOn;
    ticker tOff;
    bool on = true;
};

