#include "level.h"

level::level(Graphics& gfx)
	: level(gfx, levelParams())
{
}

level::level(Graphics& gfx, levelParams& params)
	:	lvlParams(params),
		lvlWalls(gfx, params.wallWidth, params.wallHeight),
		lvlCore(lvlWalls.getTopLeft() + params.corePos),
		brickMan(lvlParams.brickInitList, lvlWalls)
{
}

void level::update(std::list<ball>& balls, paddle& p, const float dt)
{
	brickMan.update(balls, p);
	lvlCore.update(balls, dt);
}

void level::draw(Graphics& gfx)
{
	lvlWalls.draw(gfx);
	brickMan.draw(gfx);
	lvlCore.draw(gfx);
}

bool level::isGoalsDone() const
{
	return lvlCore.isExploding();
}

bool level::isComplete() const
{
	return !lvlCore.isLive();
}

Vec2 level::getBallSpawnPos() const
{
	return lvlParams.ballPos;
}

Vec2 level::getBallSpawnVel() const
{
	return lvlParams.ballVel;
}

wall level::getWalls() const
{
	return lvlWalls;
}

Vec2 level::getTopLeft() const
{
	return getWalls().getTopLeft();
}