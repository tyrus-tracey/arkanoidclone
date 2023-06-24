#include "paddle.h"

paddle::paddle()
	: pos(300,50)
{
}

paddle::paddle(const Graphics& gfx)
	: pos(gfx.ScreenWidth/2 - (width/2), gfx.ScreenHeight - 50)
{
}

void paddle::update(const Keyboard& kbd, const rect& walls, ball& b, float dt)
{
	moveKbd(kbd, dt);
	clamp(walls);
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
	if (hitbox().isOverlapping(b.hitbox())) {
		b.reboundY();
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
//todo: delete hitbox as a member and make gethitbox return a rect using pos as input.
//			that way pos and hitbox are always linked.
void paddle::clamp(const rect& walls)
{
	if (hitbox().left < walls.left)
		{ pos.x = walls.left; }
	if (hitbox().right > walls.right)
		{ pos.x = walls.right - width; }
}