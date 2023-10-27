#include "Scoreboard.h"

void Scoreboard::draw(const int lives, const Vec2 scorePos, Graphics& gfx) const
{
	drawLives(lives, gfx);
	drawScore(scorePos, gfx);
}

void Scoreboard::scoreBrickHit(const brickTypeEnum bType)
{
	switch (bType) {
	case RED_BRICK:
		addScore(100);
		break;
	case BLUE_BRICK:
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
	case RED_BRICK:
		addScore(500);
		break;
	case BLUE_BRICK:
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
	Vec2 origin(7.0, 7.0);
	const float ballSize = 14.0f;
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
