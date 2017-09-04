#include "Game.h"
#include <graphics.h>
#include <conio.h>


Game::Game()
{
	
}

Game::~Game()
{
	
}


void Game::GameStart()
{
	Lei L;
	initgraph(Picture_Width * Floor_Row, Picture_Width * Floor_Col);    // 初始化绘图窗口
	L.Draw_Floor();
//	L.Draw_Text();
}

void Game::GameOver()
{
	_getch();               // 按任意键继续
	closegraph();           // 关闭图形界面
}
