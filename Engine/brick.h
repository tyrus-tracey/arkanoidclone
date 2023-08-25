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
	brick(const brick& b);
	brick(Vec2 b_pos);
	bool overlapCheck(ball& b) const;
	float getDistBall(ball& b) const;
	void collideBall(ball& b);
	void kill();
	void draw(Graphics& gfx) const;
	bool isLive() const;
	rect hitbox() const;
	Vec2 getPos() const;
	void setPos(const Vec2 newPos);
	static float getWidth();
	static float getHeight();
	unsigned int getFuelAmt() const;
	void operator=(const brick& b);

private:
	virtual Color getColor() const = 0;
	virtual void takeHit() = 0;
	Vec2 pos;
	static constexpr float MARGIN = -1.0f;
	static constexpr float WIDTH = 60.0f;
	static constexpr float HEIGHT = 20.0f;
	bool live = true;
	unsigned int fuelAmt = 10;
	Sound sndBrick = Sound(L"Sounds\\arkbrick.wav");

};



class colorBrick : public brick
{
	void takeHit() { kill(); }
};

class redBrick : public colorBrick {
	Color getColor() const { return Colors::Red; }
};

class blueBrick : public colorBrick {
	Color getColor() const { return Colors::Blue; }
};