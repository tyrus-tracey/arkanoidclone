#include "BallManager.h"

void BallManager::update(const level& lvl, EventManager& eventManager, const Keyboard& kbd, const float dt)
{
	std::list<ball>::iterator bIt = balls.begin();

	while (bIt != balls.end()) {
		if ((*bIt).isLive()) {
			(*bIt++).update(lvl.getWalls(), kbd, eventManager, dt);
		}
		else {
			bIt = balls.erase(bIt);
		}
	}
}

void BallManager::draw(Graphics& gfx) const
{
}

void BallManager::spawnBall(const level& lvl)
{
	spawnBall(lvl.getBallSpawnPos(), lvl.getBallSpawnVel());
}

void BallManager::spawnBall(const Vec2& loc, const Vec2& vel)
{
	balls.push_back(ball(loc, vel));
}

void BallManager::respawn(const level& lvl, int& lives)
{
	if (lives-- < 0) { return; }
	spawnBall(lvl);
}

bool BallManager::noBalls() const
{
	return false;
}
