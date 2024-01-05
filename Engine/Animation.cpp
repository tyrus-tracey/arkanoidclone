#include "Animation.h"

Animation::Animation(Soundbank& _soundbank, const Vec2 _pos, const float _lifetime)
	: soundbank(_soundbank), pos(_pos), lifetime(_lifetime)
{
	lifetime.wake();
}

animBrickExplode::animBrickExplode(Soundbank& _soundbank, const Vec2 _pos, const Color _c)
	: Animation(_soundbank, _pos, LIFETIME), c(_c),
		SIDE_RAND(sideDist(rng))
{
	flash.wake();
	chunks[0] = _pos;
	chunks[1] = _pos;
	chunks[2] = _pos;
	chunks[3] = _pos;
}

void animBrickExplode::update(const float dt)
{
	lifetime.tick(dt);
	flash.tick(dt);

	yVel += (GRAVITY * dt);
	for (int i = 0; i < 4; i++) {
		chunks[i].y += yVel;
	}

	float sideforceRand = SIDEFORCE + SIDE_RAND;
	chunks[0].x += (-sideforceRand			* dt);
	chunks[1].x += (-sideforceRand /2.0f	* dt);
	chunks[2].x += ( sideforceRand /2.0f	* dt);
	chunks[3].x += ( sideforceRand			* dt);
}

void animBrickExplode::draw(Graphics& gfx) const
{
	if (flash.isOn()) {
		for (const Vec2 chunk : chunks) { SpriteCodex::DrawBrickChunk(chunk, c, gfx); }
	}
}

animBrickCrush::animBrickCrush(Soundbank& _soundbank, const Vec2 _pos, const Color _c)
	: Animation(_soundbank, _pos, LIFETIME), c(_c)
{
	flash.wake();
	chunks[0] = _pos;
	chunks[1] = _pos;
	chunks[2] = _pos;
	chunks[3] = _pos;
}

void animBrickCrush::update(const float dt)
{
	lifetime.tick(dt);
	flash.tick(dt);
	if (lifetime.getTimeElapsed() < MOVETIME) {
		chunks[0] += (Vec2(-FORCE, -FORCE) * dt);
		chunks[1] += (Vec2(	FORCE, -FORCE) * dt);
		chunks[2] += (Vec2(-FORCE,	FORCE) * dt);
		chunks[3] += (Vec2(	FORCE,	FORCE) * dt);
	}
}

void animBrickCrush::draw(Graphics& gfx) const
{
	if (lifetime.getTimeElapsed() < MOVETIME || flash.isOn()) {
		for (const Vec2& chunk : chunks) { SpriteCodex::DrawBrickChunk(chunk, c, gfx); }
	}
}

animCoreExplode::animCoreExplode(Soundbank& _soundbank, const Vec2 _pos, const float _rad)
	: Animation(_soundbank, _pos, LIFETIME), RAD_BIG(_rad), RAD_SMALL(RAD_BIG * 0.9f)
{
	pulse.wake();
}

void animCoreExplode::update(const float dt)
{
	lifetime.tick(dt);
	pulse.tick(dt);
}

void animCoreExplode::draw(Graphics& gfx) const
{
	float drawRad = pulse.isOn() ? RAD_BIG : RAD_SMALL;
	gfx.DrawCircle(pos.x, pos.y, drawRad, cInner, false);
	gfx.DrawRing(pos.x, pos.y, drawRad, cOuter, INNER_MARGIN, false);
}

animTitleScreen::animTitleScreen(Soundbank& _soundbank, const Graphics& gfx)
	: Animation(_soundbank, Vec2(gfx.ScreenWidth/2.0, gfx.ScreenHeight/2.0) - Vec2(80.0f, 35.0f), LIFETIME),
		POS_SHADOW_1(pos + SHADOW_OFFSET),
		POS_SHADOW_2(pos + (SHADOW_OFFSET * 2.0f)),
		POS_ENTER(pos + Vec2(-15.0f, 100.0f))
{
	tTitleFadeIn.wake();
	oTitleFlicker.wake();
	soundbank.titleCreep();
}

void animTitleScreen::update(const float dt)
{
	lifetime.tick(dt);
	if (tTitleFadeIn.isActive()) {
		tTitleFadeIn.tick(dt);
		oTitleFlicker.tick(dt);
		if (tTitleFadeIn.ended()) {
			tTitleShadows.wake();
			tShadowInterval.wake();
		}
	}
	else if (tTitleShadows.isActive()) {
		tTitleShadows.tick(dt);
		tShadowInterval.tick(dt);
		if (tShadowInterval.ended()) {
			if (indexColShadow == 0) {
				soundbank.thunder();
			}
			incrementShadow();
			tShadowInterval.restart();
		}
		if (tTitleShadows.ended()) {
			tTitleFlash.wake();
			oTitleFlash.wake();
			soundbank.twinkle();
		}
	} 
	else if (tTitleFlash.isActive()) {
		tTitleFlash.tick(dt);
		oTitleFlash.tick(dt);
		if (tTitleFlash.ended()) {
			tMusicPause.wake();
		}
	}
	else if (tMusicPause.isActive()){
		tMusicPause.tick(dt);
		if (tMusicPause.ended()) {
			oEnterPrompt.wake();
			soundbank.titleMusic();
		}
	}
	else {
		oEnterPrompt.tick(dt);
	}
}

void animTitleScreen::draw(Graphics& gfx) const
{
	if (tTitleFadeIn.isActive()) {
		Vec2 xDist = {START_DIST * tTitleFadeIn.getPercentageRemaining(), 0};
		if (oTitleFlicker.isOn()) {
			SpriteCodex::DrawTitleMain(pos + xDist, COL_DIM, gfx);
		}
		else {
			SpriteCodex::DrawTitleMain(pos - xDist, COL_DIM, gfx);
		}
	}
	else if (tTitleShadows.isActive()) {
			if (indexColShadow >= 2) {
				SpriteCodex::DrawTitleMain(POS_SHADOW_2, COL_SHADOW_2, gfx);
			}
			if (indexColShadow >= 1) {
				SpriteCodex::DrawTitleMain(POS_SHADOW_1, COL_SHADOW_1, gfx);
			}
		SpriteCodex::DrawTitleMain(pos, COL_MAIN, gfx);
	}
	else if (tTitleFlash.isActive()) {
		if (oTitleFlash.isOn()) {
			SpriteCodex::DrawTitleMain(pos, COL_FLASH, gfx);
		}
		else {
			SpriteCodex::DrawTitleMain(pos, COL_DIM, gfx);
		}
	}
	else {
		if (lifetime.getTimeRemaining() < 3.0f) {
			return;
		}
		else if (lifetime.getTimeRemaining() < 4.0f) {
			SpriteCodex::DrawTitleMain(pos, Colors::Gray, gfx);
			SpriteCodex::DrawEnterPrompt(POS_ENTER, Colors::Gray, gfx);
		}
		else if (lifetime.getTimeRemaining() < 5.0f) {
			SpriteCodex::DrawTitleMain(pos, COL_DIM, gfx);
			SpriteCodex::DrawEnterPrompt(POS_ENTER, Colors::LightGray, gfx);
		}
		else {
			SpriteCodex::DrawTitleMain(pos, COL_MAIN, gfx);
			if (oEnterPrompt.isActive() && oEnterPrompt.isOn()) {
				SpriteCodex::DrawEnterPrompt(POS_ENTER, Colors::White, gfx);
			}
		}
	}
}

void animTitleScreen::incrementShadow()
{
	if (indexColShadow >= 2) {
		indexColShadow = 0;
	}
	else {
		indexColShadow++;
	}
}
