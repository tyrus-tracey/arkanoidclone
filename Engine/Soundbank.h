#pragma once
#include "Sound.h"

class Soundbank
{
public:
	void squelch();

	void brickHit();
	void wallRebound();
	void paddleRebound();

	void ballExplosion();
	void ballLost();
	void pkeeuuun();

	void brickSpawn();
	void rockHit();
	void glassPlonk();
	void glassBreak();
	void metalHit();

	void coreExplosionMini();
	void coreExplosionFinal();

	void lockBeep();
	void twinkle();

	void thunder();
	void titleCreep();
	void titleMusic();
	void levelStart();
	void gameOver();


private:
	Sound sBrickHit = Sound(L"Sounds\\reboundA.wav");
	Sound sWallRebound = Sound(L"Sounds\\reboundB.wav");
	Sound sPaddleRebound = Sound(L"Sounds\\hit.wav");

	Sound sBallExplosion = Sound(L"Sounds\\ballExplosion.wav");
	Sound sBallLost = Sound(L"Sounds\\doof.wav");
	Sound sBounce = Sound(L"Sounds\\bounce.wav");
	Sound sPkeeuuun = Sound(L"Sounds\\pkeeuuun.wav");

	Sound sBrickSpawn = Sound(L"Sounds\\pit.wav");
	Sound sRockHit = Sound(L"Sounds\\rockHit.wav");
	Sound sGlassPlonk = Sound(L"Sounds\\glassPlonk.wav");
	Sound sGlassBreak = Sound(L"Sounds\\glassBreak.wav");
	Sound sMetalHit = Sound(L"Sounds\\metalHit.wav");

	Sound sCoreExplosionMini = Sound(L"Sounds\\coreExplosionMini.wav");
	Sound sCoreExplosionFinal = Sound(L"Sounds\\coreExplosionFinal.wav");

	Sound sLockBeep = Sound(L"Sounds\\lockBeep.wav");
	Sound sTwinkle = Sound(L"Sounds\\twinkle.wav");

	Sound sTitleCreep = Sound(L"Sounds\\titlecreep.wav");
	Sound sThunder = Sound(L"Sounds\\shadow.wav");
	Sound sTitleMusic = Sound(L"Sounds\\pumped.wav");
	Sound sLevelStart = Sound(L"Sounds\\dundunduun.wav");
	Sound sGameOver = Sound(L"Sounds\\robo.wav");
};