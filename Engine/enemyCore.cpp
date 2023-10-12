#include "enemyCore.h"

enemyCore::enemyCore(Vec2 corePos)
    : pos(corePos)
{
    tDeathAnimTime.sleep();
    tMiniExplosionTime.sleep();
}

rect enemyCore::hitbox() const
{
    return rect(pos, SPAN, SPAN);
}

rect enemyCore::hitboxCore() const
{
    return hitbox().getResizeUniform(COREMARGIN);
}

void enemyCore::update(std::list<ball>& balls, Soundbank& soundbank, const float dt)
{
    if (!live) { return; }
    if (tDeathAnimTime.isActive()) {
        tDeathAnimTime.tick(dt);
        tMiniExplosionTime.tick(dt);

        if (tDeathAnimTime.ended()) { explode(soundbank); }
        
        if (!tMiniExplosionTime.isActive()) {
            soundbank.coreExplosionMini();
            xdeviation = boomX(rng);
            ydeviation = boomY(rng);
            tMiniExplosionTime.restart();
        }

        return;
    }

    if (hasBall()) { 
        if (heldBall->isExploding()) {
            startExplode();
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
    tBallHoldTime.restart();
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

void enemyCore::startExplode()
{
    tDeathAnimTime.restart();
    eatBall();
}

void enemyCore::explode(Soundbank& soundbank)
{
    soundbank.coreExplosionFinal();
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
    if (!live) { return; }

    int x, y;

    SpriteCodex::DrawCore(pos, gfx);
    if (tDeathAnimTime.isActive()) {
        if (tMiniExplosionTime.isActive()) {
            x = hitbox().left + xdeviation;
            y = hitbox().top + ydeviation;

            gfx.DrawRing(x, y, 10, Colors::Yellow, 3, false);
        }
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