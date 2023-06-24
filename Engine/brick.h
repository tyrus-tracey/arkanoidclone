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

private:
	Vec2 pos;
	float width = 60.0f;
	float height = 20.0f;
	Color col = Colors::Red;
	Sound sndBrick = Sound(L"Sounds\\arkbrick.wav");

	bool live = true;
};

