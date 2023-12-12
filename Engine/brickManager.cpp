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
    //vector<vector<bool>> occupied(wallCache.getRows(), vector<bool>(wallCache.getCols()));
    //vector<vector<bool>> occupied(wallCache.getCols(), vector<bool>(wallCache.getRows()));
    vector<vector<bool>> occupied(wallCache.getRows(), vector<bool>(wallCache.getCols()));
    for (vector<brickInitInstruction>::const_iterator it = initInstructionList.begin(); it != initInstructionList.end(); it++) {
        int x = (*it).loc.x;
        int y = (*it).loc.y;
        if (!occupied[x][y]) {
            occupied[x][y] = createBrick(*it);
        }
    }
}

// Checks which bricks are in contact with ball. Of those bricks, finds 
// the closest one and initiates a collision with it.
void brickManager::update(std::list<ball>& balls, paddle& p, EventManager& eventManager)
{
    for (ball& b : balls) {
        vector<vector<brick*>::iterator> overlappingBricks = runOverlapChecks(b);
        if (!overlappingBricks.empty()) {
            chooseCollidingBrick(overlappingBricks, b);
            if (collidedBrick != bricks.end()) {
                (*collidedBrick)->collideBall(b);

                if (!(*collidedBrick)->isLive()) {
                    if (b.isExploding()) {
                        event_brickExplode(balls, p, eventManager);
                    }
                    else {
                        event_brickKill(balls, p, eventManager);
                    }   
                }
                else {
                    event_brickHit(balls, p, eventManager);
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
bool brickManager::createBrick(brickInitInstruction initInstr)
{
    brick* b = allocateBrick(initInstr);
    if (b == nullptr) {
        return false;
    }
    b->setPos(wallCache);
    if (b->isLive() && b->hitbox().isWithin(wallCache.getBounds())) {
        bricks.push_back(b);
    }
    else {
        delete b;
        return false;
    }
    return true;
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
    case BALL:
        b = new ballBrick(initInstr.loc);
        break;
    case ROCK:
        b = new rock(initInstr.loc);
        break;
    default:
        b = new colorBrick(initInstr.loc, getColorVal(initInstr.brickType));
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

void brickManager::event_brickHit(std::list<ball>& balls, paddle& pad, EventManager& eventMan)
{
    if ((*collidedBrick) == nullptr) { return; }
    brickTypeEnum bType = (*collidedBrick)->getType();

    switch (bType) {
    default: 
        break;
    }

    eventMan.brickHit(bType);
}

void brickManager::event_brickKill(std::list<ball>& balls, paddle& pad, EventManager& eventMan)
{
    if ((*collidedBrick) == nullptr) { return; }
    brickTypeEnum bType = (*collidedBrick)->getType();

    switch (bType) {
    case BALL:
        if (!eventMan.flag_LevelGoalsComplete.isRaised()) {
            event_BrickSpawnBall(balls);
        }
    default:
        break;
    }

    pad.addFuel(float((*collidedBrick)->getFuelAmt()));
    eventMan.brickKill(bType, (*collidedBrick)->getColor(), (*collidedBrick)->hitbox().getMidpoint());

    delete* collidedBrick;
    bricks.erase(collidedBrick);
}

void brickManager::event_brickExplode(std::list<ball>& balls, paddle& pad, EventManager& eventMan)
{
    if ((*collidedBrick) == nullptr) { return; }
    brickTypeEnum bType = (*collidedBrick)->getType();

    switch (bType) {
    case BALL:
        if (!eventMan.flag_LevelGoalsComplete.isRaised()) {
            event_BrickSpawnBall(balls);
        }
    default:
        break;
    }

    pad.addFuel(float((*collidedBrick)->getFuelAmt()));
    eventMan.brickExplode(bType, (*collidedBrick)->getColor(), (*collidedBrick)->hitbox().getMidpoint());

    delete* collidedBrick;
    bricks.erase(collidedBrick);
}

void brickManager::event_BrickSpawnBall(std::list<ball>& balls)
{
    if ((*collidedBrick) == nullptr) { return; }

    Vec2 spawnVector = { 0,1 };
    float spawnTime = 0.75f;

    balls.push_back(ball((*collidedBrick)->hitbox().getMidpoint(), spawnVector, spawnTime));
}

Color brickManager::getColorVal(const brickTypeEnum colB)
{
    switch (colB) {
    case RED:
        return Colors::Red;
    case BLUE:
        return Colors::Blue;
    case YELLOW:
        return Colors::Yellow;
    case GREEN:
        return Colors::Green;
    default:
        return Colors::White;
    }
}
