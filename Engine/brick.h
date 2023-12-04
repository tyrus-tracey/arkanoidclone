#pragma once
#include <assert.h>
#include "rect.h"
#include "Vec2.h"
#include "Colors.h"
#include "Graphics.h"
#include "ball.h"
#include "gridLocation.h"
#include "brickType.h"
#include "gameVals.h"


class brick
{
public:
	brick();
	brick(const gridLocation& _loc);
	brick(const brick& other);
	bool overlapCheck(ball& b) const;
	float getDistBall(ball& b) const;
	void collideBall(ball& b);
	void kill();
	void draw(Graphics& gfx) const;
	bool isLive() const;
	rect hitbox() const;
	Vec2 getPos() const;
	void setPos(const wall& walls);
	virtual brickTypeEnum getType() const = 0;
	static float getWidth();
	static float getHeight();
	virtual Color getColor() const = 0;
	unsigned int getFuelAmt() const;
	void operator=(const brick& b);

protected:
	gridLocation loc;

private:
	Vec2 pos;
	virtual void takeHit(const ball& b) = 0;
	static constexpr float MARGIN = -1.0f;
	bool live = true;
	unsigned int fuelAmt = 10;
};


class rock : public brick
{
public:
	rock(const gridLocation _loc);
	void takeHit(const ball& b);
	Color getColor() const { return Colors::Gray; }
	brickTypeEnum getType() const { return ROCK; }
};

class ballBrick : public brick {
public:
	ballBrick(const gridLocation _loc);
	void takeHit(const ball& b) { kill(); }
	Color getColor() const { return Colors::Blue; }
	brickTypeEnum getType() const { return BALL; }
};


class colorBrick : public brick
{
public:
	colorBrick(const gridLocation _loc);
	void takeHit(const ball& b) { kill(); }
};

class redBrick : public colorBrick {
public:
	redBrick(const gridLocation _loc);
	Color getColor() const { return Colors::Red; }
	brickTypeEnum getType() const { return RED_BRICK; }
};

