#include "EventManager.h"

EventManager::EventManager(Soundbank& _soundbank, Scoreboard& _scoreboard, AnimationManager& _animManager)
	: soundbank(_soundbank), scoreboard(_scoreboard), animManager(_animManager)
{
}

void EventManager::resetFlags()
{
    flag_LevelGoalsComplete.clear();
    flag_LevelOver.clear();
    flag_ArmedBallLocked.clear();
    
    flag_ballLost.clear();
    flag_ballHoldSpawn.raise();
    flag_ClearAllBalls.clear();
    soundbank.twinkle();
}

void EventManager::brickSpawn(const brickTypeEnum bType) const
{
    soundbank.brickSpawn();
}

void EventManager::brickHit(brickTypeEnum bType) const
{
    scoreboard.scoreBrickHit(bType);
    switch (bType) {
    case COLOR:
        soundbank.brickHit();
        break;
    case BALL:
        soundbank.glassBreak();
        break;
    case ROCK:
        soundbank.rockHit();
        break;
    default:
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
        break;
    case BALL:
        soundbank.glassBreak();
        break;
    case ROCK:
        soundbank.rockHit();
        break;
    default:
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
        break;
    case BALL:
        soundbank.glassBreak();
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

void EventManager::ballLost()
{
    soundbank.ballLost();
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
}

void EventManager::coreBallRelease()
{
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
    flag_LevelGoalsComplete.clear();
    flag_LevelOver.clear();
}

void EventManager::levelReady()
{
    flag_LevelSpawnBall.raise();
    flag_ballHoldSpawn.clear();
    soundbank.levelStart();
}
