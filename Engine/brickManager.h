#pragma once
#include <vector>
#include "Graphics.h"
#include "brick.h"
#include "ball.h"
#include "wall.h"

	/// <summary>
	/// Overlooks all brick collision and draw operations for a given level.
	/// </summary>

class brickManager
{
public:
	brickManager();
	void update(ball& b);
	void draw(Graphics& gfx);
	void addBrick(const brick brik, const wall& lvlWalls);
	void addBricks(const std::vector<brick> brikVec, const wall& lvlWalls);
	brick getLastCollidedBrickCopy() const;
	std::vector<brick>& getBricks();
	unsigned int getNbricks() const;

private:
	std::vector<std::vector<brick>::iterator> runOverlapChecks(ball& b);
	void chooseCollidingBrick(std::vector<std::vector<brick>::iterator> overlappingBricks, ball& b);

	std::vector<brick> bricks;
	std::vector<brick>::iterator collidedBrick;
};

