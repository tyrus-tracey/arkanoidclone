#include "paddle.h"

paddle::paddle()
	: pos(300,50)
{
}

paddle::paddle(const wall& lvlWalls)
{
	resetPosition(lvlWalls);
}

void paddle::update(const Keyboard& kbd, const wall& lvlWalls, std::list<ball>& balls, ticker& tGameStale, EventManager& eventManager, float dt)
{
	moveKbd(kbd, dt);
	clamp(lvlWalls);
	if (collisionBall(balls, eventManager)) {
		eventManager.paddleHit();
		tGameStale.restart();
	}
}

void paddle::draw(Graphics& gfx) const
{
	Color padColor = isFuelFull() ? cFuel : cCore;
	rect rectCore(hitbox().top, hitbox().left + wing, hitbox().bottom, hitbox().right - wing);
	gfx.DrawRect(hitbox(), cWing, true);
	gfx.DrawRect(rectCore, padColor, true);
}

void paddle::reset(const wall& lvlWalls)
{
	fuel = 0;
	resetPosition(lvlWalls);
}

void paddle::addFuel(const float amt)
{
	if (!isFuelFull()) {
		fuel += amt;
	}
}

float paddle::getFuel() const
{
	return fuel;
}

bool paddle::isFuelFull() const
{
	return fuel >= FUEL_MAX;
}

rect paddle::hitbox() const
{
	return rect(pos, width, height);
}

bool paddle::collisionBall(std::list<ball>& balls, EventManager& eventManager)
{
	for (ball& b : balls) {
		if (hitbox().isOverlapping(b.hitbox()) && b.getVelocity().y > 0) {
			Vec2 impactVec = (b.hitbox().getMidpoint() - hitbox().getMidpoint()).Normalize();
			b.reboundY();
			b.slap(impactVec); //consider also applying the current velocity of paddle
			if (isFuelFull()) {
				b.arm(eventManager);
			}
			return true;
		}
	}
	return false;
}

void paddle::resetPosition(const wall& lvlWalls)
{
	pos = Vec2(lvlWalls.getBounds().getMidpoint().x - (width / 2), lvlWalls.getBounds().bottom - 50);
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