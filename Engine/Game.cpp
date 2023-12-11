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
	hud(gfx),
	lvl(gfx),
	lvlBook(gfx),
	pad(lvl.getWalls()),
	eventManager(tGameStale, soundbank, scoreboard, animManager)
{
	loadLevel(lvlBook.readLevelData());
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

	if (eventManager.flag_LevelOver.update() || wnd.kbd.KeyIsPressed(VK_DELETE)) {
		if (lvlBook.advanceLevel()) {
			loadLevel(lvlBook.readLevelData());
		} else { // NO MORE LEVELS. END OF GAME
			//gameRunning = false;
			//return;
		}	
	}

	if (wnd.kbd.KeyIsPressed(VK_TAB)) {
		ballManager.spawnBall(lvl);
	}

	dt = ft.Mark();
	updateElements(dt);

	if ((ballManager.noBalls() && !eventManager.flag_ballHoldSpawn.isRaised()) 
		|| gameIsStale()) {
		ballManager.respawn(lvl, lives);
		tGameStale.restart();
	}
}

void Game::updateElements(const float dt)
{
	tGameStale.tick(dt);
	pad.update(wnd.kbd, lvl.getWalls(), ballManager.getBalls(), eventManager, dt);
	lvl.update(ballManager.getBalls(), pad, eventManager, dt);
	ballManager.update(lvl, eventManager, wnd.kbd, dt);

	eventManager.flag_ClearAllBalls.update();
	animManager.update(dt);
	hud.update(pad.getFuel(), eventManager, dt);
}

void Game::loadLevel(levelParams params)
{
	lvl = level(gfx, params);
	pad.reset(lvl.getWalls());
	ballManager.clearBalls();
	ballManager.spawnBall(lvl);
	eventManager.levelNewLoaded();
	tGameStale.restart();
}

bool Game::gameIsStale() const
{
	return !tGameStale.isActive();
}


void Game::ComposeFrame()
{
	lvl.draw(gfx);
	pad.draw(gfx);
	ballManager.draw(gfx);
	animManager.draw(gfx);
	hud.draw(gfx);
	scoreboard.draw(lives, hud.getPos(), gfx);
}
