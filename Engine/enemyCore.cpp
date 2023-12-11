#include "enemyCore.h"

enemyCore::enemyCore(const enemyCore& other)
    : pos(other.pos), heldBall(other.heldBall), live(other.live), tIdleAnimInterval(other.tIdleAnimInterval)
{
}

enemyCore::enemyCore(Vec2 corePos)
    : pos(corePos)
{
    tDeathAnimTime.sleep();
    tMiniExplosionTime.sleep();
    tIdleAnimInterval.wake();
}

rect enemyCore::hitbox() const
{
    return rect(pos, SPAN, SPAN);
}

rect enemyCore::hitboxCore() const
{
    return hitbox().getResizeUniform(COREMARGIN);
}

void enemyCore::update(std::list<ball>& balls, ticker& tGameStale, EventManager& eventmanager, const float dt)
{
    if (!live) { return; }
    
    if (tDeathAnimTime.isActive()) {
        tDeathAnimTime.tick(dt);
        tMiniExplosionTime.tick(dt);

        if (tDeathAnimTime.ended()) { explode(eventmanager); }
        
        if (!tMiniExplosionTime.isActive()) {
            eventmanager.coreExplodeMini();
            xdeviation = boomX(rng);
            ydeviation = boomY(rng);
            tMiniExplosionTime.restart();
        }

        return;
    }

    if (hasBall()) {
        tIdleAnimInterval.tick(dt * 20.0f);
    }
    else {
        tIdleAnimInterval.tick(dt);
    }
    
    if (tIdleAnimInterval.ended()) {
        incrementDiagonal();
        tIdleAnimInterval.restart();
    }

    if (hasBall()) { 
        if (heldBall->isArmed()) {
            eventmanager.flag_ArmedBallLocked.raise();
        }

        if (heldBall->isExploding()) {
            eventmanager.flag_ArmedBallLocked.clear();
            startExplode(eventmanager);
        }
              
        tBallHoldTime.tick(dt);
        if (!tBallHoldTime.isActive()) {
            eventmanager.flag_ArmedBallLocked.clear();
            releaseBall(eventmanager);
        }
        return;
    }
    for (ball& b : balls) {
        if (hitbox().isOverlapping(b.hitbox()) && b.isLockable()) {
            lockBall(&b, eventmanager);
            tGameStale.restart();
        }
    }
}

void enemyCore::lockBall(ball* b, EventManager& eventmanager)
{
    b->lock(hitbox().getMidpoint());
    heldBall = b;
    tBallHoldTime.restart();
    eventmanager.coreBallHold();
}

void enemyCore::releaseBall(EventManager& eventmanager)
{
    if (!hasBall()) { return; }
    heldBall->setVelocity(getRandDiagonal());
    heldBall->unlock();
    heldBall = nullptr;
    eventmanager.coreBallRelease();
}

void enemyCore::eatBall()
{
    if (!hasBall()) { return; }
    heldBall->kill();
    heldBall = nullptr;
}

void enemyCore::startExplode(EventManager& eventmanager)
{
    eventmanager.coreExplodeStart();
    tDeathAnimTime.restart();
    eatBall();
}

void enemyCore::explode(EventManager& eventmanager)
{
    eventmanager.coreExplodeFinal(hitbox().getMidpoint());
    kill();
}

void enemyCore::kill()
{
    live = false;
}

bool enemyCore::isLive() const
{
    return live;
}

bool enemyCore::isExploding() const
{
    return tDeathAnimTime.isActive();
}

bool enemyCore::hasBall() const
{
    return heldBall != nullptr;
}

ball* enemyCore::getBall() const
{
    return heldBall;
}

void enemyCore::draw(Graphics& gfx)
{
    if (!live) { 
        SpriteCodex::DrawCoreHusk(pos, gfx);
        return; 
    }

    int x, y;

    if (tDeathAnimTime.isActive()) {
        SpriteCodex::DrawCoreFaint(pos, gfx);
        if (tMiniExplosionTime.isActive()) {
            x = int(hitbox().left) + xdeviation;
            y = int(hitbox().top) + ydeviation;

            gfx.DrawRing(x, y, 10, Colors::Yellow, 3, false);
        }
    }
    else {
        switch (diagonal) {
        case TL: SpriteCodex::DrawCoreTL(pos, gfx); return;
        case TR: SpriteCodex::DrawCoreTR(pos, gfx); return;
        case BR: SpriteCodex::DrawCoreBR(pos, gfx); return;
        case BL: SpriteCodex::DrawCoreBL(pos, gfx); return;
        default: SpriteCodex::DrawCore(pos, gfx); return;
        }
    }
}

void enemyCore::operator=(enemyCore& other)
{
    pos = other.pos;
    heldBall = other.heldBall;
    live = other.live;
    tIdleAnimInterval = other.tIdleAnimInterval;
}


Vec2 enemyCore::getRandDiagonal()
{
    /*
       0  1
        \/
        /\
       3  2
    */

    Vec2 out(0, 1);
    int dir = dirDist(rng);
    float posDiag = 0.7071;
    float negDiag = -0.7071;

    switch (dir) {
    case 0: out = { negDiag, negDiag }; diagonal = TL; break;  // North
    case 1: out = { posDiag, negDiag }; diagonal = TR; break;  // East
    case 2: out = { posDiag, posDiag }; diagonal = BR; break;  // South
    case 3: out = { negDiag, posDiag }; diagonal = BL; break; // West
    default: break;
    }
    tIdleAnimInterval.restart();
    return out;
}

void enemyCore::incrementDiagonal()
{
    switch (diagonal) {
    case TL: diagonal = TR; return;
    case TR: diagonal = BR; return;
    case BR: diagonal = BL; return;
    case BL: diagonal = TL; return;
    }
}
