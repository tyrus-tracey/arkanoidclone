#include "brick.h"

brick::brick()
	: loc({-1,-1})
{
}

brick::brick(const gridLocation& _loc)
	: loc(_loc)
{
}

brick::brick(const brick& other)
{
	loc = other.loc;
}

rock::rock(const gridLocation _loc)
	: brick(_loc)
{
}

void rock::takeHit(const ball& b)
{
	if (b.isExploding()) { kill(); }
}

ballBrick::ballBrick(const gridLocation _loc) 
{
	loc = _loc;
}

colorBrick::colorBrick(const gridLocation _loc)
	: brick(_loc)
{
}

bool brick::overlapCheck(ball& b) const
{
	return hitbox().isOverlapping(b.hitbox());
}

//NOTE: returns squared length to save calcs
float brick::getDistBall(ball& b) const
{
	Vec2 impactVec = hitbox().getMidpoint() - b.hitbox().getMidpoint();
	return impactVec.GetLengthSq();
}

void brick::collideBall(ball& b)
{
	assert(hitbox().isOverlapping(b.hitbox()));
	Vec2 ballMid = b.hitbox().getMidpoint();
	Vec2 impactVec = ballMid - hitbox().getMidpoint();

	if (std::signbit(b.getVelocity().x) == std::signbit(impactVec.x)) {
		b.reboundY();
	}
   	else if (ballMid.x > hitbox().left && ballMid.x < hitbox().right) {
		b.reboundY();
	}
	else {
		b.reboundX();
	}
	b.pushOut(hitbox());
	takeHit(b);
}

rect brick::hitbox() const
{
	return rect(pos, getWidth(), getHeight());
}

Vec2 brick::getPos() const
{
	return pos;
}

// Calculates brick position from location value, relative to walls
void brick::setPos(const wall& walls)
{
	pos = walls.getTopLeft() + Vec2(getWidth() * loc.x, getHeight() * loc.y);
}

void brick::kill()
{
	live = false;
}

void brick::draw(Graphics& gfx) const
{
	rect visualBrick = hitbox().getResizeUniform(MARGIN);
	if (live) { 
		gfx.DrawRect(visualBrick, getColor(), true);
	}
}

bool brick::isLive() const
{
	return live;
}

float brick::getWidth()
{
	return BRICK_WIDTH;
}

float brick::getHeight()
{
	return BRICK_HEIGHT;
}

unsigned int brick::getFuelAmt() const
{
	return fuelAmt;
}

void brick::operator=(const brick& b)
{
	pos = b.pos;
	live = b.live;
}

redBrick::redBrick(const gridLocation _loc)
	: colorBrick(_loc)
{
}
