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
	if (b.isExploding() || hits-- <= 0) { kill(); }
}

void rock::draw(Graphics& gfx) const
{
	SpriteCodex::DrawBrickRock(getPos(), gfx);
	if (hits <= 15) {
		if (hits > 11)		{ SpriteCodex::DrawBrickCracks1(getPos(), gfx); }
		else if (hits > 7)	{ SpriteCodex::DrawBrickCracks2(getPos(), gfx); }
		else if (hits > 3)	{ SpriteCodex::DrawBrickCracks3(getPos(), gfx); }
		else if (hits >= 0)	{ SpriteCodex::DrawBrickCracks4(getPos(), gfx); }
	}	
}

ballBrick::ballBrick(const gridLocation _loc) 
{
	loc = _loc;
}

void ballBrick::draw(Graphics& gfx) const
{
	SpriteCodex::DrawBrickBall(getPos(), gfx);
}

bool brick::overlapCheck(ball& b) const
{
	return b.hitbox().isOverlapping(hitbox());
}

//NOTE: returns squared length to save calcs
float brick::getDistBall(ball& b) const
{
	Vec2 impactVec = hitbox().getMidpoint() - b.getPos();
	return impactVec.GetLengthSq();
}

void brick::collideBall(ball& b)
{
	assert(b.hitbox().isOverlapping(this->hitbox()));
	Vec2 ballMid = b.getPos();
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

colorBrick::colorBrick(const gridLocation _loc, const Color _c)
	: brick(_loc), c(_c)
{
}
