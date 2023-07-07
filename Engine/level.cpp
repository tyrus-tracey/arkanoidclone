#include "level.h"

level::level()
{
}

// Input vec2s should be relative.
level::level(const wall walls, const std::vector<brick> bricks, Vec2 corePos, Vec2 ballPos)
	: lvlWalls(walls), lvlCore(walls.getTopLeft() + corePos), ballSpawnPos(walls.getTopLeft() + ballPos)
{
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

Vec2 level::getBallSpawnPos() const
{
	return ballSpawnPos;
}

wall level::getWalls() const
{
	return lvlWalls;
}
