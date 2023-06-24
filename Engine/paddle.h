#pragma once
#include "Keyboard.h"
#include "Graphics.h"
#include "Vec2.h"
#include "Colors.h"
#include "rect.h"
#include "ball.h"

class paddle
{
public:
	paddle();
	paddle(const Graphics& gfx);
	void update(const Keyboard& kbd, const rect& walls, float dt);
	void draw(Graphics& gfx) const;
	rect hitbox() const;

private:
	void moveKbd(const Keyboard& kbd, float dt);
	void clamp(const rect& walls);

	Vec2 pos; //top-left
	float width = 75.0f;
	float height = 20.0f;
	float speed = 500.0f;
	Color c = Colors::White;
};

