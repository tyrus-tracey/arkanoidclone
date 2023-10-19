#include "Flag.h"

Flag::Flag(const bool b)
    : flagStatus(b)
{}

void Flag::raise()
{
    flagStatus = true;
}

void Flag::clear()
{
    flagStatus = false;
}

bool Flag::update()
{
    if (isRaised()) {
        clear();
        return true;
    }
    return false;
}

bool Flag::isRaised() const
{
    return flagStatus;
}
