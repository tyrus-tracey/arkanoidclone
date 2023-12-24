#pragma once
#include <list>
#include "EventManager.h"
#include "level.h"
#include "ball.h"

class BallManager
{
public:
	BallManager();
	void update(const level& lvl, EventManager& eventManager, const Keyboard& kbd, const float dt);
	void draw(Graphics& gfx) const;
	std::list<ball>& getBalls();
	void clearBalls();
	void spawnBall(const level& lvl);
	void spawnBall(const Vec2& loc, const Vec2& vel);
	void respawn(const level& lvl, int& lives);
	bool noBalls() const;

private:
	std::list<ball> balls;
	ticker tRespawnWait = ticker(1.0f);
};

