#pragma once
#include <assert.h>
#include "Shape.h"
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
	virtual void draw(Graphics& gfx) const;
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
	void draw(Graphics& gfx) const;
	Color getColor() const { return Colors::Gray; }
	brickTypeEnum getType() const { return ROCK; }
private:
	int hits = 19;
};

class ballBrick : public brick {
public:
	ballBrick(const gridLocation _loc);
	void takeHit(const ball& b) { kill(); }
	void draw(Graphics& gfx) const;
	Color getColor() const { return Colors::MakeRGB(165, 201, 255); }
	brickTypeEnum getType() const { return BALL; }
};


class colorBrick : public brick
{
public:
	colorBrick(const gridLocation _loc, const Color _c);
	void takeHit(const ball& b) { kill(); }
	Color getColor() const { return c; }
	brickTypeEnum getType() const { return COLOR; }
private:
	Color c;
};

