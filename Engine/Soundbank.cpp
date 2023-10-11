#include "Soundbank.h"

void Soundbank::brickHit()
{
	sBrickHit.StopAll();
	sBrickHit.Play();
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
