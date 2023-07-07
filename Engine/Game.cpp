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
	gfx(wnd)
{
	wall lvl1Wall(gfx, rect(Vec2(200, 50), Vec2(600, 750)));

	Vec2 start(lvl1Wall.getTopLeft().x+50, lvl1Wall.getTopLeft().y + 50);
	std::vector<brick> breks;
	for (unsigned int y = 0; y < 4; ++y) {
		for (unsigned int x = 0; x < 10; ++x) {
			Vec2 bib(start);
			bib.x += x * brick::getWidth();
			bib.y += y * brick::getHeight();
			breks.push_back(brick(bib, cArr[y]));
		}
	}
	lvl1 = level(lvl1Wall, breks, Vec2(100, 100), Vec2(100,100));
	b = ball(lvl1.getBallSpawnPos());
	pad = paddle(lvl1.getWalls());
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
	if (wnd.kbd.KeyIsPressed(VK_TAB)) {
		b.reset();
	}
	dt = ft.Mark();
	pad.update(wnd.kbd, lvl1.getWalls(), b, dt);
	lvl1.update(b, pad, dt);
	b.update(lvl1.getWalls(), wnd.kbd, dt);
}

void Game::ComposeFrame()
{
	lvl1.draw(gfx);
	pad.draw(gfx);
	b.draw(gfx);
}
