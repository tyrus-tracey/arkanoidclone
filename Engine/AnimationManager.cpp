#include "AnimationManager.h"

AnimationManager::AnimationManager()
{
}

AnimationManager::AnimationManager(const AnimationManager& other)
{
	std::list<Animation*>::const_iterator aIt = other.animations.begin();

	while (aIt != other.animations.end()) {
		animations.push_back(*aIt);
	}
}

AnimationManager& AnimationManager::operator=(const AnimationManager& other)
{
	clearAnims();
	std::list<Animation*>::const_iterator aIt = other.animations.begin();
	while (aIt != other.animations.end()) {
		animations.push_back(*aIt);
	}
	return *this;
}

AnimationManager::~AnimationManager()
{
	clearAnims();
}

void AnimationManager::update(float dt)
{
	std::list<Animation*>::iterator aIt = animations.begin();

	while (aIt != animations.end()) {
		if ((*aIt)->isLive()) {
			(*aIt++)->update(dt);
		}
		else {
			delete (*aIt);
			aIt = animations.erase(aIt);
		}
	}
}

void AnimationManager::draw(Graphics& gfx) const
{
	for (auto it = animations.begin(); it != animations.end(); it++) {
		(*it)->draw(gfx);
	}
}

void AnimationManager::createAnimTitleScreen(const Graphics& gfx)
{
	animTitleScreen* newAnim = new animTitleScreen(gfx);
	animations.push_back(newAnim);
}

void AnimationManager::createAnimBrickExplode(const Vec2 pos, const Color c)
{
	animBrickExplode* newAnim = new animBrickExplode(pos, c);
	animations.push_back(newAnim);
}

void AnimationManager::createAnimBrickCrush(const Vec2 pos, const Color c)
{
	animBrickCrush* newAnim = new animBrickCrush(pos, c);
	animations.push_back(newAnim);
}

void AnimationManager::createAnimCoreExplode(const Vec2 pos, const float rad)
{
	animCoreExplode* newAnim = new animCoreExplode(pos, rad);
	animations.push_back(newAnim);
}

bool AnimationManager::noAnimsRunning() const
{
	return animations.empty();
}

void AnimationManager::clearAnims()
{
	std::list<Animation*>::const_iterator aIt = animations.begin();
	while (aIt != animations.end()) {
		delete (*aIt);
		aIt = animations.erase(aIt);
	}
}