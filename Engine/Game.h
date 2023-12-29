/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "FrameTimer.h"
#include "Vec2.h"
#include "Shape.h"
#include "paddle.h"
#include "wall.h"
#include "level.h"
#include "brick.h"
#include "enemyCore.h"
#include "levelBook.h"
#include "Scoreboard.h"
#include <list>
#include "Hud.h"
#include "EventManager.h"
#include "AnimationManager.h"
#include "BallManager.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void updateElements(const float dt);
	void loadLevel(levelParams params);
	void reset();
	bool titleScreen();
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
	Hud hud;
	level lvl;
	levelBook lvlBook;
	paddle pad;
	Soundbank soundbank;
	Scoreboard scoreboard;
	AnimationManager animManager;
	EventManager eventManager;
	BallManager ballManager;

	ticker tGameOver = ticker(13.0f);
	const int DEF_LIVES = 4;

	bool showTitle = true;
	bool gameOver = false;
	bool gameWon = false;
	FrameTimer ft;
	float dt;
	int lives = DEF_LIVES;
};