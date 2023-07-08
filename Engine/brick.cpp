#include "brick.h"

brick::brick()
	: pos(-1, -1), live(false)
{
}

brick::brick(const brick& b)
	: pos(b.pos), col(b.col)
{
}

brick::brick(Vec2 b_pos)
	: pos(b_pos)
{
}

brick::brick(Vec2 b_pos, const Color c)
	: brick(b_pos)
{
	col = c;
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
	sndBrick.StopOne();
	sndBrick.Play();
	kill();
}

rect brick::hitbox() const
{
	return rect(pos, WIDTH, HEIGHT);
}

Vec2 brick::getPos() const
{
	return pos;
}

void brick::setPos(const Vec2 newPos)
{
	pos = newPos;
}

void brick::kill()
{
	live = false;
}

void brick::draw(Graphics& gfx) const
{
	rect visualBrick = hitbox().getResizeUniform(MARGIN);
	if (live) { 
		gfx.DrawRect(visualBrick, col, true); 
	}
}

bool brick::isLive() const
{
	return live;
}

float brick::getWidth()
{
	return WIDTH;
}

float brick::getHeight()
{
	return HEIGHT;
}

unsigned int brick::getFuelAmt() const
{
	return fuelAmt;
}

void brick::operator=(const brick& b)
{
	pos = b.pos;
	col = b.col;
	live = b.live;
}
