#include "level.h"

level::level()
	: ballSpawnPos({0,0}), ballSpawnVel{0,0}
{
}

level::level(const wall walls, Vec2 corePos)
	: level(walls, corePos, Vec2(walls.getWidth()/2, walls.getHeight()/2), Vec2(1, 1))
{
}

level::level(const wall walls, Vec2 corePos, Vec2 ballPos, Vec2 ballVel)
	: level(walls, std::vector<brick>(0), corePos, ballPos, ballVel)
{
}


level::level(const wall walls, std::vector<brick> bricks, Vec2 corePos, Vec2 ballPos, Vec2 ballVel)
	: lvlWalls(walls), lvlCore(walls.getTopLeft() + corePos), 
		ballSpawnPos(walls.getTopLeft() + ballPos), ballSpawnVel(ballVel)
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

void level::update(std::vector<ball>& balls, paddle& p, const float dt)
{
	brickMngr.update(balls, p);
	lvlCore.update(balls, dt);
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

Vec2 level::getBallSpawnVel() const
{
	return ballSpawnVel;
}

wall level::getWalls() const
{
	return lvlWalls;
}

Vec2 level::getTopLeft() const
{
	return getWalls().getTopLeft();
}
