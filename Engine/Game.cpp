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
	lvlWall(gfx, rect(Vec2(200, 50), Vec2(600, 750)))
{
	b = ball(Vec2(250, 250));
	walls = rect(0, 0, gfx.ScreenHeight, gfx.ScreenWidth);
	pad = paddle(gfx);
	core = enemyCore(Vec2(400, 200));

	Vec2 start(-100, -40);
	
	for (unsigned int y = 0; y < 5; ++y) {
		for (unsigned int x = 0; x < 10; ++x) {
			Vec2 bib(start);
			bib.x += x * brick::getWidth();
			bib.y += y * brick::getHeight();
			brekMngr.addBrick(brick(bib, cArr[y]), walls);
		}
	}
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
	if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
		b.speedSet(speedslow);
	}
	else {
		b.speedReset();
	}
	if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
		core.releaseBall();
	}
	dt = ft.Mark();
	pad.update(wnd.kbd, walls, b, dt);
	brekMngr.update(b);
	b.update(walls, dt);
	core.update(&b);
}

void Game::ComposeFrame()
{
	lvlWall.draw(gfx);
	brekMngr.draw(gfx);
	core.draw(gfx);
	pad.draw(gfx);
	b.draw(gfx);
	
}
