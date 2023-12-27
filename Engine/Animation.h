#pragma once
#include "Graphics.h"
#include "SpriteCodex.h"
#include "Vec2.h"
#include "oscillator.h"
#include "Soundbank.h"

class Animation
{
public:
	Animation(Soundbank& _soundbank, const Vec2 _pos, const float _lifetime);
	virtual void update(const float dt) = 0;
	virtual void draw(Graphics& gfx) const = 0;
	bool isLive() const { return !lifetime.ended(); }

protected:
	Soundbank& soundbank;
	Vec2 pos;
	ticker lifetime;
};

class animTitleScreen : public Animation
{
public:
	animTitleScreen(Soundbank& _soundbank, const Graphics& gfx);
	void update(const float dt);
	void draw(Graphics& gfx) const;
private:
	void incrementShadow();

	static constexpr float LIFETIME = 21.0f;

	ticker tTitleFadeIn = ticker(2.0f);
	ticker tTitleShadows = ticker(1.0f);
	ticker tShadowInterval = ticker(0.1f);
	ticker tTitleFlash = ticker(1.0f);
	ticker tMusicPause = ticker(1.0f);
	oscillator oTitleFlicker = oscillator(0.0125f);
	oscillator oTitleFlash = oscillator(0.025f);
	oscillator oEnterPrompt = oscillator(0.1f);

	const float START_DIST = 500.0f;
	const Vec2 SHADOW_OFFSET{ 5.0f, 5.0f };
	const Vec2 POS_SHADOW_1;
	const Vec2 POS_SHADOW_2;
	const Vec2 POS_ENTER;

	const Color COL_MAIN		= Colors::MakeRGB(255, 216,   0);
	const Color COL_DIM			= Colors::MakeRGB(216, 194,  82);
	const Color COL_FLASH		= Colors::White;

	const Color COL_SHADOW_1	= Colors::MakeRGB(255, 102, 170);
	const Color COL_SHADOW_2	= Colors::MakeRGB( 25, 255,  48);

	int indexColShadow = 0;
};

class animBrickExplode : public Animation
{
public:
	animBrickExplode(Soundbank& _soundbank, const Vec2 _pos, const Color _c);
	void update(const float dt);
	void draw(Graphics& gfx) const;
private:
	static constexpr float LIFETIME = 1.0f;
	static constexpr float GRAVITY = 100.0f;
	static constexpr float SIDEFORCE = 200.0f;
	float yVel = -15.0f;
	const Color c;
	Vec2 chunks[4];
	oscillator flash = oscillator(0.05f);
};

class animBrickCrush : public Animation
{
public:
	animBrickCrush(Soundbank& _soundbank, const Vec2 _pos, const Color _c);
	void update(const float dt);
	void draw(Graphics& gfx) const;
private:
	static constexpr float LIFETIME = 0.3f;
	static constexpr float MOVETIME = 0.2f;
	static constexpr float FORCE = 300.0f;
	const Color c;
	Vec2 chunks[4]; // [0] topLeft, [1] topRight, [2] botLeft, [3] botRight
	oscillator flash = oscillator(0.025f);
};

class animCoreExplode : public Animation
{
public:
	animCoreExplode(Soundbank& _soundbank, const Vec2 _pos, const float _rad);
	void update(const float dt);
	void draw(Graphics& gfx) const;
private:
	static constexpr float LIFETIME = 2.0f;
	const int INNER_MARGIN = 5;

	const float RAD_BIG;
	const float RAD_SMALL;
	
	const Color cOuter = Colors::Red;
	const Color cInner = Colors::Yellow;
	oscillator pulse = oscillator(0.05f);
};