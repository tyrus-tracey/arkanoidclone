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

void enemyCore::update(std::list<ball>& balls, const float dt)
{
    if (!live) { return; }
    if (tDeathAnimTime.isActive()) {
        tDeathAnimTime.tick(dt);
        if (tDeathAnimTime.ended()) { kill(); }
        return;
    }

    if (hasBall()) { 
        if (heldBall->isExploding()) {
            explode();
        }
        tBallHoldTime.tick(dt);
        if (!tBallHoldTime.isActive()) {
            releaseBall();
        }
        return;
    }
    for (ball& b : balls) {
        if (hitbox().isOverlapping(b.hitbox()) && !b.onLockCooldown()) {
            lockBall(&b);
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
    heldBall = nullptr;
}

void enemyCore::explode()
{
    tDeathAnimTime.reset();
    eatBall();
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

void enemyCore::draw(Graphics& gfx)
{
    if (!live) { return; }
    SpriteCodex::DrawCore(pos, gfx);
    if (tDeathAnimTime.isActive()) {
        int left = int(hitbox().left);
        int right = int(hitbox().right);
        int top = int(hitbox().top);
        int bot = int(hitbox().bottom);
        xDist = std::uniform_int_distribution<int>(left, right);
        yDist = std::uniform_int_distribution<int>(top, bot);
        gfx.DrawRing(xDist(rng), yDist(rng), 10, Colors::Yellow, 3, false);
    }
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