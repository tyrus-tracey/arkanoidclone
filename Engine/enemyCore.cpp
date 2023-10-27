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

void enemyCore::update(std::list<ball>& balls, EventManager& eventmanager, const float dt)
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
        if (hitbox().isOverlapping(b.hitbox()) && !b.onLockCooldown()) {
            lockBall(&b, eventmanager);
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
    eventmanager.coreExplodeFinal();
    kill();
}

void enemyCore::kill()
{
    live = false;
}

bool enemyCore::isLive()   
{
    return live;
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
            x = int(hitbox().left) + xdeviation;
            y = int(hitbox().top) + ydeviation;

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