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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	b = ball(Vec2(300, 300));
	walls = rect(0, 0, gfx.ScreenHeight, gfx.ScreenWidth);
	pad = paddle(gfx);
	b1 = brick(Vec2(100, 100));
	b2 = brick(Vec2(100, 200));
	b3 = brick(Vec2(100, 300));
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
	dt = ft.Mark();
	pad.update(wnd.kbd, walls, b, dt);
	b1.update(b);
	b2.update(b);
	b3.update(b);
	b.update(walls, dt);
}

void Game::ComposeFrame()
{
	b1.draw(gfx);
	b2.draw(gfx);
	b3.draw(gfx);
	pad.draw(gfx);
	b.draw(gfx);
}
