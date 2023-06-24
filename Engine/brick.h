#pragma once
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
	void update(ball& b);
	rect hitbox() const;
	bool collisionBall(ball& b) const;
	void kill();
	void draw(Graphics& gfx);
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

