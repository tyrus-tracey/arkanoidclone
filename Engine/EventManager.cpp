#include "EventManager.h"

EventManager::EventManager(Soundbank& _soundbank)
	: soundbank(_soundbank)
{
}

void EventManager::brickHit(brickTypeEnum bType) const
{
    switch (bType) {
    case RED_BRICK:
        soundbank.brickHit();
        break;
    case BLUE_BRICK:
        soundbank.brickHit();
        break;
    case ROCK:
        soundbank.rockHit();
        break;
    default:
        return;
    }
}

void EventManager::brickKill(brickTypeEnum bType) const
{
    switch (bType) {
    case RED_BRICK:
        soundbank.brickHit();
        break;
    case BLUE_BRICK:
        soundbank.brickHit();
        break;
    case ROCK:
        soundbank.rockHit();
        break;
    default:
        return;
    }
}

void EventManager::paddleHit() const
{
    soundbank.paddleRebound();
}

void EventManager::ballWallRebound() const
{
    soundbank.wallRebound();
}

void EventManager::ballDetonate() const
{
    soundbank.ballExplosion();
}

void EventManager::ballLockBeep() const
{
    soundbank.lockBeep();
}

void EventManager::coreExplodeStart()
{
    flag_ballHoldSpawn.raise();
}

void EventManager::coreExplodeMini() const
{
    soundbank.coreExplosionMini();
}

void EventManager::coreExplodeFinal() const
{
    soundbank.coreExplosionFinal();
}

void EventManager::levelNewLoaded()
{
    flag_ballHoldSpawn.clear();
}
