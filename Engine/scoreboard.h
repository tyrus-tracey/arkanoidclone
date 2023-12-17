#pragma once

#include <limits.h>
#include <random>
#include "Graphics.h"
#include "SpriteCodex.h"
#include "SpriteNumbers.h"
#include "rect.h"
#include "Vec2.h"
#include "brickType.h"

class Scoreboard
{
public:
	void draw(const int lives, const Vec2 scorePos, Graphics& gfx) const;
	void scoreBrickHit(const brickTypeEnum bType);
	void scoreBrickKill(const brickTypeEnum bType);
	void scorePaddleHit() { addScore(5); }
	void scoreCoreExplodeMini();
	void scoreCoreKill();
	void reset();

private:
	void drawLives(const int lives, Graphics& gfx) const;
	void drawScore(const Vec2 pos, Graphics& gfx) const;
	void addScore(const int amt);

	long playerScore = 0;
	const long SCORE_MAX = (std::numeric_limits<long>::max)();
	const long SCORE_MIN = 0;

	std::mt19937 rng;
	std::uniform_int_distribution<int> randScoreDist = std::uniform_int_distribution<int>(1, 99);
};

