#pragma once
#include <list>
#include "Keyboard.h"
#include "Graphics.h"
#include "Vec2.h"
#include "EventManager.h"
#include "Colors.h"
#include "Shape.h"
#include "ball.h"
#include "wall.h"

class paddle
{
public:
	paddle();
	paddle(const wall& lvlWalls);
	void update(const Keyboard& kbd, const wall& lvlWalls, std::list<ball>& balls, EventManager& eventManager, float dt);
	void draw(Graphics& gfx) const;
	void reset(const wall& lvlWalls);
	void addFuel(const float amt);
	float getFuel() const;
	bool isFuelFull() const;
	rect hitbox() const;

private:
	bool collisionBall(std::list<ball>& balls, EventManager& eventManager);
	void resetPosition(const wall& lvlWalls);
	void moveKbd(const Keyboard& kbd, float dt);
	void clamp(const wall& lvlWalls);

	Vec2 pos; //top-left
	float width = 75.0f;
	float height = 20.0f;
	float wing = 10.0f;
	float speed = 500.0f;

	float fuel = 0.0f;
	const float FUEL_MAX = 100.0f;

	Color cCore = Colors::White;
	Color cFuel = Colors::Yellow;
	Color cWing = Colors::Red;
};

