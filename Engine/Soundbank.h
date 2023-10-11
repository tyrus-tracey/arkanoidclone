#pragma once
#include "Sound.h"

class Soundbank
{
public:
	void brickHit();
	void wallRebound();
	void paddleRebound();


private:
	Sound sBrickHit = Sound(L"Sounds\\arkbrick.wav");
	Sound sWallRebound = Sound(L"Sounds\\arkbrick.wav");
	Sound sPaddleRebound = Sound(L"Sounds\\arkpad.wav");
};