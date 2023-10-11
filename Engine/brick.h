#pragma once
#include <assert.h>
#include "rect.h"
#include "Vec2.h"
#include "Colors.h"
#include "Graphics.h"
#include "ball.h"
#include "gridLocation.h"


class brick
{
public:
	bool overlapCheck(ball& b) const;
	float getDistBall(ball& b) const;
	void collideBall(ball& b);
	void kill();
	void draw(Graphics& gfx) const;
	bool isLive() const;
	rect hitbox() const;
	Vec2 getPos() const;
	void setPos(const wall& walls);
	static float getWidth();
	static float getHeight();
	unsigned int getFuelAmt() const;
	void operator=(const brick& b);

protected:
	gridLocation loc;

private:
	Vec2 pos;
	virtual Color getColor() const = 0;
	virtual void takeHit() = 0;
	static constexpr float MARGIN = -1.0f;
	static constexpr float WIDTH = 60.0f;
	static constexpr float HEIGHT = 20.0f;
	bool live = true;
	unsigned int fuelAmt = 10;
};



class colorBrick : public brick
{
	void takeHit() { kill(); }
};

class redBrick : public colorBrick {
public:
	redBrick(gridLocation _loc);
	redBrick(const redBrick& other);
	Color getColor() const { return Colors::Red; }
	
};

class blueBrick : public colorBrick {
public:
	blueBrick(gridLocation _loc);
	Color getColor() const { return Colors::Blue; }
};