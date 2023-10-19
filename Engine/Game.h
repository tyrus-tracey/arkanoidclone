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
#include "ball.h"
#include "Vec2.h"
#include "rect.h"
#include "paddle.h"
#include "wall.h"
#include "level.h"
#include "brick.h"
#include "enemyCore.h"
#include "levelBook.h"
#include "scoreboard.h"
#include <list>
#include "Hud.h"
#include "EventManager.h"

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
	void spawnBall(Vec2 spawnLoc, Vec2 velocity);
	void spawnBall(const level& lvl);
	void respawn();
	inline bool outOfLives() { return lives > 0; }
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	Hud hud;
	/********************************/
	/*  User Variables              */
	/********************************/
	bool gameRunning = true;
	FrameTimer ft;
	float dt;
	paddle pad;
	levelBook lvlBook;
	level lvl;
	int lives = 4;
	std::list<ball> balls;
	
	Soundbank soundbank;
	EventManager eventManager;
	
	float speedslow = 25.0f;
};