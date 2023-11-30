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

void AnimationManager::testCreateAnim(const Vec2 pos, const Color c)
{
	animBrickExplode* newAnim = new animBrickExplode(pos, c, 5.0f);
	animations.push_back(newAnim);
}

void AnimationManager::clearAnims()
{
	std::list<Animation*>::const_iterator aIt = animations.begin();
	while (aIt != animations.end()) {
		delete (*aIt);
		aIt = animations.erase(aIt);
	}
}

animBrickExplode::animBrickExplode(const Vec2 _pos, const Color _c, const float _lifetime)
	: Animation(_pos, _lifetime), c(_c)
{
	lifetime.wake();
}

void animBrickExplode::update(const float dt)
{
	lifetime.tick(dt);
	vel += (GRAVITY * dt);
	pos += vel;
}

void animBrickExplode::draw(Graphics& gfx) const
{
	SpriteCodex::DrawBrickChunk(pos, c, gfx);
}

Animation::Animation(const Vec2 _pos, const float _lifetime)
	: pos(_pos), lifetime(_lifetime)
{
}


