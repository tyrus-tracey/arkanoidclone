#include "EventManager.h"

EventManager::EventManager(ticker& _tGameStale, Soundbank& _soundbank, Scoreboard& _scoreboard, AnimationManager& _animManager)
	:   tGameStale(_tGameStale), 
        soundbank(_soundbank), 
        scoreboard(_scoreboard), 
        animManager(_animManager)
{
}

void EventManager::brickHit(brickTypeEnum bType) const
{
    scoreboard.scoreBrickHit(bType);
    switch (bType) {
    case COLOR:
        soundbank.brickHit();
        tGameStale.restart();
        break;
    case BALL:
        soundbank.glassBreak();
        tGameStale.restart();
        break;
    case ROCK:
        soundbank.rockHit();
        break;
    default:
        tGameStale.restart();
        return;
    }
}

void EventManager::brickKill(const brickTypeEnum bType, const Color bCol, const Vec2 bPos) const
{
    scoreboard.scoreBrickKill(bType);
    animManager.createAnimBrickCrush(bPos, bCol);

    switch (bType) {
    case COLOR:
        soundbank.brickHit();
        tGameStale.restart();
        break;
    case BALL:
        soundbank.glassBreak();
        tGameStale.restart();
        break;
    case ROCK:
        soundbank.rockHit();
        break;
    default:
        tGameStale.restart();
        return;
    }
}

void EventManager::brickExplode(const brickTypeEnum bType, const Color bCol, const Vec2 bPos) const
{
    scoreboard.scoreBrickKill(bType);
    animManager.createAnimBrickExplode(bPos, bCol);

    switch (bType) {
    case COLOR:
        soundbank.brickHit();
        tGameStale.restart();
        break;
    case BALL:
        soundbank.glassBreak();
        tGameStale.restart();
        break;
    case ROCK:
        soundbank.rockHit();
        break;
    default:
        tGameStale.restart();
        return;
    }
}

void EventManager::paddleHit() const
{
    scoreboard.scorePaddleHit();
    soundbank.paddleRebound();
    tGameStale.restart();
}

void EventManager::ballWallRebound() const
{
    soundbank.wallRebound();
}

void EventManager::ballDissipate() const
{
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
    tGameStale.restart();
}

void EventManager::coreBallRelease()
{
    tGameStale.restart();
}

void EventManager::coreExplodeStart()
{
    flag_ballHoldSpawn.raise();
    flag_ClearAllBalls.raise();
}

void EventManager::coreExplodeMini() const
{
    scoreboard.scoreCoreExplodeMini();
    soundbank.coreExplosionMini();
}

void EventManager::coreExplodeFinal(const Vec2 pos) const
{
    scoreboard.scoreCoreKill();
    soundbank.coreExplosionFinal();
    animManager.createAnimCoreExplode(pos, 75.0f);
}

void EventManager::levelNewLoaded()
{
    flag_ballHoldSpawn.clear();
    flag_LevelGoalsComplete.clear();
    flag_LevelOver.clear();
    tGameStale.restart();
}
