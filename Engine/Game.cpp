/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	lvl(gfx),
	lvlBook(gfx)
{
	loadLevel(lvlBook.readLevelData());
	balls.push_back(ball(lvl.getBallSpawnPos(), lvl.getBallSpawnVel()));
	pad = paddle(lvl.getWalls());
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	/*if (!outOfLives()) {
		GAME OVER
	}*/
	if (!gameRunning) {
		return;
	}

	if (lvl.isComplete()) {
		if (lvlBook.advanceLevel()) {
			loadLevel(lvlBook.readLevelData());
			pad.reset(lvl.getWalls());
			balls.clear();
			spawnBall(lvl);
		} else { // NO MORE LEVELS. END OF GAME
			//gameRunning = false;
			//return;
		}	
	}

	if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
		for (ball& b : balls) {
			b.speedSet(speedslow);
		}
	}
	else {
		for (ball& b : balls) {
			b.speedReset();
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_TAB)) {
		spawnBall(lvl);
	}
	dt = ft.Mark();
	
	pad.update(wnd.kbd, lvl.getWalls(), balls, dt);
	lvl.update(balls, pad, dt);

	std::list<ball>::iterator bIt = balls.begin();
	while (bIt != balls.end()) {
		if ((*bIt).isLive() ) {
			(*bIt++).update(lvl.getWalls(), wnd.kbd, dt);
		}
		else {
			bIt = balls.erase(bIt);
		}
	}
	if (balls.empty() && !lvl.isCoreExploding()) {
		respawn();
	}
}

void Game::loadLevel(levelParams params)
{
	lvl = level(gfx, params);
}

void Game::spawnBall(Vec2 spawnLoc, Vec2 velocity)
{
	balls.push_back(ball(spawnLoc, velocity));
}

void Game::spawnBall(const level& lvl)
{
	spawnBall(lvl.getBallSpawnPos(), lvl.getBallSpawnVel());
}

void Game::respawn()
{
	if ( !outOfLives() ) { return; }
	spawnBall(lvl);
	lives--;
}

void Game::ComposeFrame()
{
	if (gameRunning) {
		lvl.draw(gfx);
		pad.draw(gfx);
		for (ball& b : balls) {
			b.draw(gfx);
		}
		scoreboard::drawLives(gfx, lives);
	}
	else {

	}
}
