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
	if (collisionBall(b)) {
		kill();
		sndBrick.StopOne();
		sndBrick.Play();
	}
}

rect brick::hitbox() const
{
	return rect(pos, WIDTH, HEIGHT);
}

void brick::kill()
{
	live = false;
}

bool brick::collisionBall(ball& b) const
{
	if (!live) { return false; }
	if (hitbox().isOverlapping(b.hitbox())) {
		float ballMidX = b.hitbox().getMidpoint().x;
		if (ballMidX > hitbox().left && ballMidX < hitbox().right) {
			b.reboundY();
		}
		else {
			b.reboundX();
		}
		return true;
	}
	return false;
}

void brick::draw(Graphics& gfx)
{
	rect visualBrick = hitbox().getResizeUniform(MARGIN);
	if (live) { 
		gfx.DrawRect(visualBrick, col); 
	}
}

float brick::getWidth()
{
	return WIDTH;
}

float brick::getHeight()
{
	return HEIGHT;
}
