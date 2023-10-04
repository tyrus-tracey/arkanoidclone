#include "level.h"

level::level(Graphics& gfx)
	: level(gfx, levelParams())
{
}

level::level(Graphics& gfx, levelParams& params)
	:	lvlParams(params),
		lvlWalls(gfx, params.wallSize),
		brickMan(lvlParams.brickInitList, lvlWalls)
{
	Vec2 corePos = lvlWalls.getTopLeft();
	corePos.x += (params.coreLoc.x * brick::getWidth());
	corePos.y += (params.coreLoc.y * brick::getHeight());
	
	corePos.x += (brick::getWidth()/2 - enemyCore::SPAN/2); // Centering core
	
	if ( rect(corePos, enemyCore::SPAN, enemyCore::SPAN).isWithin(lvlWalls.getBounds()) ) {
		lvlCore = enemyCore(corePos);
	}

	initBallSpawnPos();
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

bool level::isCoreExploding() const
{
	return lvlCore.isExploding();
}

bool level::isCoreHoldingArmedBall() const
{
	if (lvlCore.hasBall()) {
		return lvlCore.getBall()->isArmed();
	} 
	return false;
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


// Adjusts ballspawn Vec2 to be relative to lvlWalls.
// If Vec2 not within walls, defaults to lvlWall midpoint.
void level::initBallSpawnPos()
{
	lvlParams.ballPos += lvlWalls.getTopLeft(); // Set ballspawn relative to walls
	if (!lvlWalls.getBounds().isOverlapping(lvlParams.ballPos)) { // if ball is outside walls
		lvlParams.ballPos = lvlWalls.getBounds().getMidpoint();
	}
}
