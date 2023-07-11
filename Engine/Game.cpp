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
	lvlBook(gfx)
{
	lvl = lvlBook.getCurrentLvl();
	b = ball(lvl.getBallSpawnPos());
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
	if (lvl.isComplete()) {
		if (lvlBook.advanceLevel()) {
			lvl = lvlBook.getCurrentLvl();
			pad.reset(lvl.getWalls());
			b.reset();
		}
		else {
			// NO MORE LEVELS. END OF GAME
		}	
	}

	if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
		b.speedSet(speedslow);
	}
	else {
		b.speedReset();
	}
	if (wnd.kbd.KeyIsPressed(VK_TAB)) {
		b.reset();
	}
	dt = ft.Mark();
	pad.update(wnd.kbd, lvl.getWalls(), b, dt);
	lvl.update(b, pad, dt);
	b.update(lvl.getWalls(), wnd.kbd, dt);
}

void Game::ComposeFrame()
{
	lvl.draw(gfx);
	pad.draw(gfx);
	b.draw(gfx);
}
