#include "paddle.h"

paddle::paddle()
	: pos(300,50)
{
}

paddle::paddle(const wall& lvlWalls)
	: pos(lvlWalls.getBounds().right - (width / 2), lvlWalls.getBounds().bottom - 50)
{
}

void paddle::update(const Keyboard& kbd, const wall& lvlWalls, ball& b, float dt)
{
	moveKbd(kbd, dt);
	clamp(lvlWalls);
	if (collisionBall(b)) {
		sndPaddle.StopOne();
		sndPaddle.Play();
	}
}

void paddle::draw(Graphics& gfx) const
{
	rect rectCore(hitbox().top, hitbox().left + wing, hitbox().bottom, hitbox().right - wing);
	gfx.DrawRect(hitbox(), cWing);
	gfx.DrawRect(rectCore, cCore);
}

rect paddle::hitbox() const
{
	return rect(pos, width, height);
}

bool paddle::collisionBall(ball& b)
{
	if (hitbox().isOverlapping(b.hitbox()) && b.getVelocity().y > 0) {
		Vec2 impactVec = (b.hitbox().getMidpoint() - hitbox().getMidpoint()).Normalize();
		b.reboundY();
		b.slap(impactVec); //consider also applying the current velocity of paddle
		return true;
	}
	return false;
}

void paddle::moveKbd(const Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT)) {
		pos.x -= speed * dt;
	}
	if (kbd.KeyIsPressed(VK_RIGHT)) {
		pos.x += speed * dt;
	}
}

void paddle::clamp(const wall& lvlWalls)
{
	if (hitbox().left < lvlWalls.getBounds().left)
		{ pos.x = lvlWalls.getBounds().left; }
	if (hitbox().right > lvlWalls.getBounds().right)
		{ pos.x = lvlWalls.getBounds().right - width; }
}