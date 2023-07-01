#include "enemyCore.h"

enemyCore::enemyCore(Vec2 corePos)
    : pos(corePos)
{
}

rect enemyCore::hitbox() const
{
    return rect(pos, SPAN, SPAN);
}

rect enemyCore::hitboxCore() const
{
    return hitbox().getResizeUniform(COREMARGIN);
}

void enemyCore::update(ball* b, const float dt)
{
    if (!live) { return; }
    if (hasBall()) { 
        tBallHoldTime.tick(dt);
        if (!tBallHoldTime.isActive()) {
            releaseBall();
        }
        return;
    }

    if (hitbox().isOverlapping(b->hitbox()) && !b->onLockCooldown()) {
        if (b->fuelFull()) {
            kill();
        }
        else {
            lockBall(b);
        }
    }
}

void enemyCore::lockBall(ball* b)
{
    b->lock(hitbox().getMidpoint());
    heldBall = b;
    tBallHoldTime.reset();
}

void enemyCore::releaseBall()
{
    if (!hasBall()) { return; }
    heldBall->setVelocity(getRandDiagonal());
    heldBall->unlock();
    heldBall = nullptr;
}

void enemyCore::eatBall()
{
    if (!hasBall()) { return; }
    heldBall->kill();
}

void enemyCore::kill()
{
    live = false;
}

bool enemyCore::isLive() const
{
    return live;
}

bool enemyCore::hasBall() const
{
    return heldBall != nullptr;
}

void enemyCore::draw(Graphics& gfx) const
{
    if (!live) { return; }
    SpriteCodex::DrawCore(pos, gfx);
}

void enemyCore::operator=(enemyCore& other)
{
    pos = other.pos;
    heldBall = other.heldBall;
    live = other.live;
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
    case 0: out = { negDiag, negDiag }; break;  // North
    case 1: out = { posDiag, negDiag }; break;  // East
    case 2: out = { posDiag, posDiag }; break;  // South
    case 3: out = { negDiag, posDiag }; break; // West
    default: break;
    }
    return out;
}