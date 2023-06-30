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

void enemyCore::update(ball* b)
{
    if (!live) { return; }
    if (hitbox().isOverlapping(b->hitbox()) && !b->onLockCooldown()) {
        lockBall(b);
    }
}

void enemyCore::lockBall(ball* b)
{
    b->lock(hitbox().getMidpoint());
    heldBall = b;
}

void enemyCore::releaseBall()
{
    if (!hasBall()) { return; }
    heldBall->unlock();
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
    SpriteCodex::DrawCore(pos, gfx);
}

void enemyCore::operator=(enemyCore& other)
{
    pos = other.pos;
    heldBall = other.heldBall;
    live = other.live;
}
