#include "EventManager.h"

EventManager::EventManager(Soundbank& _soundbank, Scoreboard& _scoreboard)
	: soundbank(_soundbank), scoreboard(_scoreboard)
{
}

void EventManager::brickHit(brickTypeEnum bType) const
{
    scoreboard.scoreBrickHit(bType);
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
    scoreboard.scoreBrickKill(bType);
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
    scoreboard.scorePaddleHit();
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

void EventManager::ballArmed() const
{
    soundbank.pkeeuuun();
}

void EventManager::coreBallHold()
{
}

void EventManager::coreBallRelease()
{
}

void EventManager::coreExplodeStart()
{
    flag_ballHoldSpawn.raise();
}

void EventManager::coreExplodeMini() const
{
    scoreboard.scoreCoreExplodeMini();
    soundbank.coreExplosionMini();
}

void EventManager::coreExplodeFinal() const
{
    scoreboard.scoreCoreKill();
    soundbank.coreExplosionFinal();
}

void EventManager::levelNewLoaded()
{
    flag_ballHoldSpawn.clear();
}
