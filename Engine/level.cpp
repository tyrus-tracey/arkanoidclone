#include "level.h"

level::level(Graphics& gfx, levelParams& params)
	:	lvlParams(params),
		lvlWalls(gfx, params.wallWidth, params.wallHeight),
		lvlCore(lvlWalls.getTopLeft() + params.corePos)
{
	for (auto it = params.bricks.begin(); it != params.bricks.end(); it++) {
		redBrick b({1,1});
		brickMan.addBrick(b, lvlWalls);
	}
}

//level::level(const wall walls, std::vector<brick *> bricks, Vec2 corePos, Vec2 ballPos, Vec2 ballVel)
//	: lvlWalls(walls), lvlCore(walls.getTopLeft() + corePos), 
//		ballSpawnPos(walls.getTopLeft() + ballPos), ballSpawnVel(ballVel)
//{
//	// Translate local into window coords.
//	for (brick* b : bricks) {
//		b->setPos(b->getPos() + walls.getTopLeft());
//	}
//	brickMan.addBricks(bricks, walls);
//
//	if (!lvlCore.hitbox().isWithin(lvlWalls.getBounds())) {
//		lvlCore = enemyCore(lvlWalls.getTopLeft());
//	}
//	if (!lvlWalls.getBounds().isOverlapping(ballSpawnPos) ||
//		lvlCore.hitbox().isOverlapping(ballSpawnPos)) {
//		ballSpawnPos = lvlWalls.getBounds().getMidpoint();
//	}
//}

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

//template <class brickType>
//void level::addBrick(const gridLocation loc)
//{
//	if (!std::is_base_of_v<brick, brickType>) {
//		return;
//	}
//	Vec2 pos = loc2pos(loc);
//	brickType* b = new brickType;
//	b->setPos(pos);
//	brickMan.addBrick(b, lvlWalls);
//}
//template void level::addBrick<redBrick>(const gridLocation loc);
//template void level::addBrick<blueBrick>(const gridLocation loc);

template <class brickType>
void level::addBrick(brick b)
{
	b.setPos(lvlWalls);
	brickMan.addBrick(b, lvlWalls);
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

// Note: Possible UB with getTopLeft()? Kept returning garbage until it stopped.
//Vec2 level::loc2pos(const gridLocation loc) const
//{
//	Vec2 out = getTopLeft();
//	out.x += (brick::getWidth() * loc.x);
//	out.y += (brick::getHeight() * loc.y);
//
//	return out;
//}
