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
	animManager(soundbank),
	eventManager(soundbank, scoreboard, animManager)
{
	reset();
}

void Game::Go()
{
	gfx.BeginFrame();
	float elapsed = ft.Mark();
	while (elapsed > 0.0f) {
		const float dt = std::min(0.0025f, elapsed);
		UpdateModel(dt);
		elapsed -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(const float _dt)
{
	float dt = _dt;
	if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
		dt /= 4.0f;
	}

	if (gameOver || gameWon) {
		tGameOver.tick(dt);
		if (tGameOver.ended()) {
			reset();
		}
		return;
	}

	if (!titleScreen()) {
		if (eventManager.flag_LevelOver.update() || wnd.kbd.KeyIsPressed(VK_DELETE)) {
			if (lvlBook.advanceLevel()) {
				loadLevel(lvlBook.readLevelData());
			}
			else {
				gameWon = true;
				tGameOver.wake();
				eventManager.gameOver();
				return;
			}
		}

		if (eventManager.flag_LevelSpawnBall.update()) {
			ballManager.spawnBall(lvl);
		}

		if (wnd.kbd.KeyIsPressed(VK_TAB)) {
			reset();
		}

		if (!eventManager.flag_ballHoldSpawn.isRaised() &&
			ballManager.awaitingRespawn()) {
			ballManager.respawn(lvl, lives);
		}

		updateElements(dt);
		if (lives < 0) { 
			gameOver = true; 
			tGameOver.wake();
			eventManager.gameOver(); 
		}
	}
	else {
		animManager.update(dt);
		if (animManager.noAnimsRunning()) {
			reset();
		}
	}
}

void Game::updateElements(const float dt)
{	
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
	eventManager.levelNewLoaded();
}

void Game::reset()
{
	showTitle = true;
	gameOver = false;
	gameWon = false;
	lvlBook.reset();
	ballManager.clearBalls();
	lives = DEF_LIVES;
	eventManager.gameReset(gfx);
	loadLevel(lvlBook.readLevelData());

	pad.addFuel(100);
}

bool Game::titleScreen()
{
	if (showTitle == false) { return false; }
	if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
		eventManager.gameStart();
		showTitle = false;
	}
	return showTitle;
}

void Game::ComposeFrame()
{
	if (showTitle) {
		animManager.draw(gfx);
	}
	else {
		lvl.draw(gfx);
		pad.draw(gfx);
		ballManager.draw(gfx);
		animManager.draw(gfx);
		hud.draw(gfx);
		scoreboard.draw(lives, hud.getPos(), gfx);
		if (gameOver) {
			SpriteCodex::DrawGameOver(gfx);
		}
		else if (gameWon) {
			SpriteCodex::DrawGameWon(gfx);
		}
	}
}
