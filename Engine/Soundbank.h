#pragma once
#include "Sound.h"

class Soundbank
{
public:
	void brickSpawn();
	void brickHit();
	void rockHit();
	void wallRebound();
	void paddleRebound();
	void ballExplosion();
	void coreExplosionMini();
	void coreExplosionFinal();
	void glassPlonk();
	void glassBreak();
	void lockBeep();
	void metalHit();
	void pkeeuuun();


private:
	Sound sBrickHit = Sound(L"Sounds\\arkbrick.wav");
	Sound sRockHit = Sound(L"Sounds\\rockHit.wav");
	Sound sWallRebound = Sound(L"Sounds\\arkbrick.wav");
	Sound sPaddleRebound = Sound(L"Sounds\\arkpad.wav");
	Sound sBallExplosion = Sound(L"Sounds\\ballExplosion.wav");
	Sound sBounce = Sound(L"Sounds\\bounce.wav");
	Sound sCoreExplosionMini = Sound(L"Sounds\\coreExplosionMini.wav");
	Sound sCoreExplosionFinal = Sound(L"Sounds\\coreExplosionFinal.wav");
	Sound sGlassPlonk = Sound(L"Sounds\\glassPlonk.wav");
	Sound sGlassBreak = Sound(L"Sounds\\glassBreak.wav");
	Sound sLockBeep = Sound(L"Sounds\\lockBeep.wav");
	Sound sMetalHit = Sound(L"Sounds\\metalHit.wav");
	Sound sPkeeuuun = Sound(L"Sounds\\pkeeuuun.wav");

};