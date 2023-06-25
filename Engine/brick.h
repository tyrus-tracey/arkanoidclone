#pragma once
#include <assert.h>
#include "rect.h"
#include "Vec2.h"
#include "Colors.h"
#include "Graphics.h"
#include "Sound.h"
#include "ball.h"

class brick
{
public:
	brick();
	brick(Vec2 b_pos);
	brick(Vec2 b_pos, const Color c);
	bool overlapCheck(ball& b) const;
	float getDistBall(ball& b) const;
	void collideBall(ball& b);
	void kill();
	void draw(Graphics& gfx);
	bool isLive() const;
	rect hitbox() const;
	static float getWidth();
	static float getHeight();

private:
	Vec2 pos;
	static constexpr float MARGIN = -1.0f;
	static constexpr float WIDTH = 60.0f;
	static constexpr float HEIGHT = 20.0f;
	Color col = Colors::Red;
	Sound sndBrick = Sound(L"Sounds\\arkbrick.wav");

	bool live = true;
};

