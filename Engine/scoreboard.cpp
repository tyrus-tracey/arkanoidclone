#include "scoreboard.h"

void scoreboard::drawLives(Graphics& gfx, const int lives)
{
	Vec2 origin(7.0, 7.0);
	const float ballSize = 14.0f;
	for (int i = 0; i < lives; i++) {
		SpriteCodex::DrawBall(origin, gfx, 0);
		origin.x += ballSize;
	}
}
