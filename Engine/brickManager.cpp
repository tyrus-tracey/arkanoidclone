#include "brickManager.h"
using std::vector;

brickManager::brickManager(const std::vector<brickInitInstruction>& _initInstructionList, const wall& lvlWalls)
    : initInstructionList(_initInstructionList), wallCache(lvlWalls)
{
    initializeBricks();
}

brickManager::brickManager(const brickManager& copy)
    : initInstructionList(copy.initInstructionList), wallCache(copy.wallCache)
{
    deleteBricks();
    wallCache = copy.wallCache;
    initializeBricks();
}

brickManager& brickManager::operator=(brickManager other)
{
    deleteBricks();
    initInstructionList = other.initInstructionList;
    wallCache = other.wallCache;
    initializeBricks();
    return *this;
}

brickManager::~brickManager()
{
    deleteBricks();
}

// Clears and allocates new bricks from brickMan's initList.
void brickManager::initializeBricks()
{
    deleteBricks();
    for (auto it = initInstructionList.begin(); it != initInstructionList.end(); it++) {
        createBrick(*it);
    }
}

// Checks which bricks are in contact with ball. Of those bricks, finds 
// the closest one and initiates a collision with it.
void brickManager::update(std::list<ball>& balls, paddle& p)
{
    for (ball& b : balls) {
        vector<vector<brick*>::iterator> overlappingBricks = runOverlapChecks(b);
        if (!overlappingBricks.empty()) {
            chooseCollidingBrick(overlappingBricks, b);
            if (collidedBrick != bricks.end()) {
                p.addFuel((*collidedBrick)->getFuelAmt());
                (*collidedBrick)->collideBall(b);
                if (!(*collidedBrick)->isLive()) { // If brick dead from colliding
                    delete *collidedBrick;
                    bricks.erase(collidedBrick);
                }
            }
        }
    }
}

void brickManager::draw(Graphics& gfx)
{
    for (vector<brick*>::const_iterator i = bricks.begin(); i != bricks.end(); ++i) {
        if ((*i) != nullptr) {
            (*i)->draw(gfx);
        }
    }
}

// Allocates and adds a brick to brick vector.
void brickManager::createBrick(brickInitInstruction initInstr)
{
    brick* b = allocateBrick(initInstr);
    if (b == nullptr) {
        return;
    }
    b->setPos(wallCache);
    if (b->isLive() && b->hitbox().isWithin(wallCache.getBounds())) {
        bricks.push_back(b);
    }
    else {
        delete b;
    }
}

// Returns null if none exists.
brick* brickManager::getLastCollidedBrickRef() const
{
    if (collidedBrick != bricks.end()) {
        return *collidedBrick;
    }
    return nullptr;
}

vector<brick*>& brickManager::getBricks()
{
    return bricks;
}

unsigned int brickManager::getNbricks() const
{
    return unsigned int(bricks.size());
}

void brickManager::deleteBricks()
{
    while (!bricks.empty()) {
        delete bricks.front();
        bricks.erase(bricks.begin());
    }
    collidedBrick = bricks.end();
}

// Dynamic allocation of a brick from brickType enum.
brick* brickManager::allocateBrick(brickInitInstruction initInstr)
{
    brick* b = nullptr;
    switch (initInstr.brickType) {
    case RED_BRICK:
        b = new redBrick(initInstr.loc);
        break;
    case BLUE_BRICK:
        b = new blueBrick(initInstr.loc);
        break;
    default:
        break;
    }
    return b;
}

// Returns iters pointing to bricks that collided with the ball.
vector<vector<brick*>::iterator> brickManager::runOverlapChecks(ball& b)
{
    vector<vector<brick*>::iterator> output;
    for (vector<brick*>::iterator i = bricks.begin(); i != bricks.end(); ++i) {
        if ((*i) != nullptr && (*i)->overlapCheck(b)) {
            output.push_back(i);
        }
    }
    return output;
}

// Finds the brick closest to the ball, and writes the corresponding iterator to collidedBrick.
void brickManager::chooseCollidingBrick(vector<vector<brick*>::iterator> overlappingBricks, ball& b)
{
    collidedBrick = bricks.end();
    float minDist = 99999.9f;
    float curDist;

    for (vector<vector<brick*>::iterator>::iterator i = overlappingBricks.begin(); i != overlappingBricks.end(); ++i) {
        if ((*(*i)) != nullptr) {
            curDist = (*(*i))->getDistBall(b);
            if (curDist < minDist) {
                minDist = curDist;
                collidedBrick = *i;
            }
        }
    }
}
