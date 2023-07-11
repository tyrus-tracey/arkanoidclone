#include "level.h"

level::level()
{
}

level::level(const wall walls, Vec2 corePos, Vec2 ballPos)
	: level(walls, std::vector<brick>(0), corePos, ballPos)
{
}


level::level(const wall walls, std::vector<brick> bricks, Vec2 corePos, Vec2 ballPos)
	: lvlWalls(walls), lvlCore(walls.getTopLeft() + corePos), ballSpawnPos(walls.getTopLeft() + ballPos)
{
	// Translate local into window coords.
	for (brick& b : bricks) {
		b.setPos(b.getPos() + walls.getTopLeft());
	}
	brickMngr.addBricks(bricks, walls);

	if (!lvlCore.hitbox().isWithin(lvlWalls.getBounds())) {
		lvlCore = enemyCore(lvlWalls.getTopLeft());
	}
	if (!lvlWalls.getBounds().isOverlapping(ballSpawnPos) ||
		lvlCore.hitbox().isOverlapping(ballSpawnPos)) {
		ballSpawnPos = lvlWalls.getBounds().getMidpoint();
	}
}

void level::update(ball& b, paddle& p, const float dt)
{
	brickMngr.update(b, p);
	lvlCore.update(&b, dt);
}

void level::draw(Graphics& gfx)
{
	lvlWalls.draw(gfx);
	brickMngr.draw(gfx);
	lvlCore.draw(gfx);
}

bool level::isComplete() const
{
	return !lvlCore.isLive();
}

void level::addBrick(const brick& b)
{
	brickMngr.addBrick(b, lvlWalls);
}

Vec2 level::getBallSpawnPos() const
{
	return ballSpawnPos;
}

wall level::getWalls() const
{
	return lvlWalls;
}

Vec2 level::getTopLeft() const
{
	return getWalls().getTopLeft();
}
