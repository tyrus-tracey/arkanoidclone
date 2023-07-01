#pragma once
#include "Keyboard.h"
#include "Graphics.h"
#include "Vec2.h"
#include "Sound.h"
#include "Colors.h"
#include "rect.h"
#include "ball.h"
#include "wall.h"

class paddle
{
public:
	paddle();
	paddle(const wall& lvlWalls);
	void update(const Keyboard& kbd, const wall& lvlWalls, ball& b, float dt);
	void draw(Graphics& gfx) const;
	rect hitbox() const;

private:
	bool collisionBall(ball& b);
	void moveKbd(const Keyboard& kbd, float dt);
	void clamp(const wall& lvlWalls);

	Vec2 pos; //top-left
	float width = 75.0f;
	float height = 20.0f;
	float wing = 10.0f;
	float speed = 500.0f;
	Color cCore = Colors::White;
	Color cWing = Colors::Red;
	Sound sndPaddle = Sound(L"Sounds\\arkpad.wav");
};

