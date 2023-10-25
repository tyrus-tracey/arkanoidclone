#pragma once
#include <vector>
#include "Graphics.h"
#include "brick.h"
#include "ball.h"
#include "wall.h"
#include "paddle.h"
#include "levelParams.h"
#include "Soundbank.h"

	/// <summary>
	/// Overlooks all brick collision and draw operations for a given level.
	/// </summary>

class brickManager
{
public:
	brickManager(const std::vector<brickInitInstruction>& _initInstructionList, const wall& lvlWalls );
	brickManager(const brickManager& copy);
	brickManager& operator=(brickManager other);
	~brickManager();
	void initializeBricks();
	void update(std::list<ball>& balls, paddle& p, Soundbank& soundbank);
	void draw(Graphics& gfx);
	bool createBrick(brickInitInstruction initInstr);
	brick* getLastCollidedBrickRef() const;
	std::vector<brick*>& getBricks();
	unsigned int getNbricks() const;

private:
	wall wallCache;
	void deleteBricks();
	std::vector<brickInitInstruction> initInstructionList;
	brick* allocateBrick(brickInitInstruction initInstr);
	std::vector<std::vector<brick*>::iterator> runOverlapChecks(ball& b);
	void chooseCollidingBrick(std::vector<std::vector<brick*>::iterator> overlappingBricks, ball& b);

	void playBrickHit(Soundbank& soundbank, brickTypeEnum bType) const;

	std::vector<brick*> bricks;
	std::vector<brick*>::iterator collidedBrick;
};

