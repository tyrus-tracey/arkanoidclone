#include "brickManager.h"
using std::vector;

brickManager::brickManager()
{
}

// Checks which bricks are in contact with ball. Of those bricks, finds 
// the closest one and initiates a collision with it.
void brickManager::update(std::list<ball>& balls, paddle& p)
{
    for (ball& b : balls) {
        vector<vector<brick>::iterator> overlappingBricks = runOverlapChecks(b);
        if (!overlappingBricks.empty()) {
            chooseCollidingBrick(overlappingBricks, b);
            if (collidedBrick != bricks.end()) {
                p.addFuel((*collidedBrick).getFuelAmt());
                (*collidedBrick).collideBall(b);
                if (!(*collidedBrick).isLive()) { // If brick dead from colliding
                    bricks.erase(collidedBrick);
                }
            }
        }
    }
}

void brickManager::draw(Graphics& gfx)
{
    for (vector<brick>::const_iterator i = bricks.begin(); i != bricks.end(); ++i) {
        (*i).draw(gfx);
    }
}

template <typename T>
void brickManager::addBrick(T b, const wall& lvlWalls)
{
    b.setPos(lvlWalls);
    if (b.isLive() && b.hitbox().isWithin(lvlWalls.getBounds())) {
        bricks.push_back(b);
    }
}
template void brickManager::addBrick<brick>(brick b, const wall& lvlWalls);

void brickManager::addBricks(const vector<brick>& bVec, const wall& lvlWalls)
{
    for (vector<brick>::const_iterator it = bVec.begin(); it != bVec.end(); ++it) {
        addBrick(*it, lvlWalls);
    }
}

// Returns null if none exists. TODO: Consider converting to iters.
//brick brickManager::getLastCollidedBrickCopy() const
//{
//    if (collidedBrick != bricks.end()) {
//        return *collidedBrick;
//    }
//    return bricks.end();
//}

vector<brick>& brickManager::getBricks()
{
    return bricks;
}

unsigned int brickManager::getNbricks() const
{
    return unsigned int(bricks.size());
}

// Returns iters pointing to bricks that collided with the ball.
vector<vector<brick>::iterator> brickManager::runOverlapChecks(ball& b)
{
    vector<vector<brick>::iterator> output;
    int index = 0;
    vector<brick>::iterator i = bricks.begin();
    for (vector<brick>::iterator i = bricks.begin(); i != bricks.end(); ++i) {
        if ((*i).overlapCheck(b)) {
            output.push_back(i);
        }
        index++;
    }
    return output;
}

// Finds the brick closest to the ball, and writes the corresponding iterator to collidedBrick.
void brickManager::chooseCollidingBrick(vector<vector<brick>::iterator> overlappingBricks, ball& b)
{
    collidedBrick = bricks.end();
    float minDist = 99999.9f;
    float curDist;

    for (vector<vector<brick>::iterator>::iterator i = overlappingBricks.begin(); i != overlappingBricks.end(); ++i) {
        curDist = (*(*i)).getDistBall(b);
        if (curDist < minDist) {
            minDist = curDist;
            collidedBrick = *i;
        }
    }
}
