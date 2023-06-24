#include "brick.h"

brick::brick()
	: pos(-1, -1)
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

void brick::update(ball& b)
{
	/*
		could improve by comparing midpoint?
		|====|
		|====|
		   o		<- midpoint of ball between brick.left and brick.right
						reboundY

						else reboundX
	*/
	if (collisionBall(b)) {
		kill();
		sndBrick.StopOne();
		sndBrick.Play();
	}
}

rect brick::hitbox() const
{
	return rect(pos, width, height);
}

void brick::kill()
{
	live = false;
}

bool brick::collisionBall(ball& b) const
{
	if (!live) { return false; }
	if (hitbox().isOverlapping(b.hitbox())) {
		b.reboundY();
		return true;
	}
	return false;
}

void brick::draw(Graphics& gfx)
{
	if (live) { gfx.DrawRect(hitbox(), col); }
}