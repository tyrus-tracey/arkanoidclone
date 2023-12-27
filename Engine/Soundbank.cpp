#include "Soundbank.h"

void Soundbank::brickSpawn()
{
	//sBrickSpawn.StopAll();
	sBrickSpawn.Play(1.25f, 0.25f);
}

void Soundbank::brickHit()
{
	sBrickHit.StopAll();
	sBrickHit.Play();
}

void Soundbank::rockHit()
{
	sRockHit.StopAll();
	sRockHit.Play();
}

void Soundbank::wallRebound()
{
	sWallRebound.StopAll();
	sWallRebound.Play();
}

void Soundbank::paddleRebound()
{
	sPaddleRebound.StopAll();
	sPaddleRebound.Play();
}

void Soundbank::ballExplosion()
{
	sBallExplosion.StopAll();
	sBallExplosion.Play(1.0f, 0.75f);
}

void Soundbank::coreExplosionMini()
{
	sCoreExplosionMini.StopAll();
	sCoreExplosionMini.Play(3.0f, 0.3f);
}

void Soundbank::coreExplosionFinal()
{
	sCoreExplosionFinal.StopAll();
	sCoreExplosionFinal.Play();
}

void Soundbank::glassPlonk()
{
	sGlassPlonk.StopAll();
	sGlassPlonk.Play();
}

void Soundbank::glassBreak()
{
	sGlassBreak.StopAll();
	sGlassBreak.Play(1.5f, 0.5f);
}

void Soundbank::lockBeep()
{
	sLockBeep.StopAll();
	sLockBeep.Play(0.75f, 0.25f);
}

void Soundbank::metalHit()
{
	sMetalHit.StopAll();
	sMetalHit.Play();
}

void Soundbank::pkeeuuun()
{
	sPkeeuuun.StopAll();
	sPkeeuuun.Play();
}

void Soundbank::twinkle()
{
	sTwinkle.StopAll();
	sTwinkle.Play();
}

void Soundbank::ballLost()
{
	sBallLost.StopAll();
	sBallLost.Play();
}

void Soundbank::titleMusic()
{
	sTitleMusic.StopAll();
	sTitleMusic.Play();
}

void Soundbank::levelStart()
{
	sLevelStart.StopAll();
	sLevelStart.Play(1.0f, 0.75f);
}

void Soundbank::gameOver()
{
	sGameOver.StopAll();
	sGameOver.Play();
}
