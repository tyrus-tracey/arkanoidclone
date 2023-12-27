#include "BallManager.h"

BallManager::BallManager()
{
	tRespawnWait.sleep();
}

void BallManager::update(const level& lvl, EventManager& eventManager, const Keyboard& kbd, const float dt)
{
	std::list<ball>::iterator bIt = balls.begin();

	while (bIt != balls.end()) {
		if ((*bIt).isLive()) {
			(*bIt++).update(lvl.getWalls(), kbd, eventManager, dt);
		}
		else {
			if ((*bIt).isLost()) {
				eventManager.ballLost();
				respawnReady = false;
				tRespawnWait.restart();
			}
			else {
				tRespawnWait.resetTime();
				tRespawnWait.sleep();
				respawnReady = true;
			}
			bIt = balls.erase(bIt);
		}
	}
	tRespawnWait.tick(dt);
	if (tRespawnWait.ended()) {
		respawnReady = true;
		tRespawnWait.resetTime();
		tRespawnWait.sleep();
	}
}

void BallManager::draw(Graphics& gfx) const
{
	for (ball b : balls) { b.draw(gfx); }
}

std::list<ball>& BallManager::getBalls()
{
	return balls;
}

void BallManager::clearBalls()
{
	balls.clear();
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
	if (lives-- <= 0) { return; }
	spawnBall(lvl);
	respawnReady = false;
}

bool BallManager::awaitingRespawn() const
{
	return noBalls() && respawnReady;
}

bool BallManager::noBalls() const
{
	return balls.empty();
}
