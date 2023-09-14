#pragma once
#include <vector>
#include "Graphics.h"
#include "brick.h"
#include "ball.h"
#include "wall.h"
#include "paddle.h"
#include "levelParams.h"

	/// <summary>
	/// Overlooks all brick collision and draw operations for a given level.
	/// </summary>

class brickManager
{
public:
	brickManager();
	void update(std::list<ball>& balls, paddle& p);
	void draw(Graphics& gfx);
	template <typename T> void addBrick(T b, const wall& lvlWalls);
	void addBricks(const std::vector<brick>& bVec, const wall& lvlWalls);
	//brick getLastCollidedBrickCopy() const;
	std::vector<brick>& getBricks();
	unsigned int getNbricks() const;

private:
	std::vector<std::vector<brick>::iterator> runOverlapChecks(ball& b);
	void chooseCollidingBrick(std::vector<std::vector<brick>::iterator> overlappingBricks, ball& b);

	std::vector<brick> bricks;
	std::vector<brick>::iterator collidedBrick;
};

