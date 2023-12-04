#include "Scoreboard.h"

void Scoreboard::draw(const int lives, const Vec2 scorePos, Graphics& gfx) const
{
	drawLives(lives, gfx);
	drawScore(scorePos, gfx);
}

void Scoreboard::scoreBrickHit(const brickTypeEnum bType)
{
	switch (bType) {
	case RED:
		addScore(100);
		break;
	case BALL:
		addScore(100);
		break;
	case ROCK:
		addScore(1);
		break;
	default:
		break;
	}
}

void Scoreboard::scoreBrickKill(const brickTypeEnum bType)
{
	switch (bType) {
	case RED:
		addScore(500);
		break;
	case BALL:
		addScore(500);
		break;
	case ROCK:
		addScore(1750);
		break;
	default:
		break;
	}
}

void Scoreboard::scoreCoreExplodeMini()
{
	addScore(randScoreDist(rng));
}

void Scoreboard::scoreCoreKill()
{
	addScore(2500);
}

void Scoreboard::drawLives(const int lives, Graphics& gfx) const
{
	const float ballSize = 14.0f;
	const float ballRad = 7.0f;
	Vec2 origin(ballRad, ballRad);
	for (int i = 0; i < lives; i++) {
		SpriteCodex::DrawBall(origin, gfx, 0);
		origin.x += ballSize;
	}
}

void Scoreboard::addScore(const int amt)
{
	if (SCORE_MAX - amt < playerScore) {
		playerScore = SCORE_MAX; return;
	}
	else if (SCORE_MIN - amt > playerScore) {
		playerScore = SCORE_MIN; return;
	}
	playerScore += amt;
}

void Scoreboard::drawScore(const Vec2 pos, Graphics& gfx) const
{
	SpriteNumbers::drawNum(playerScore, pos, Colors::Cyan, gfx);
}
