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
	initgraph(Picture_Width * Floor_Row, Picture_Width * Floor_Col);    // ��ʼ����ͼ����
	L.Draw_Floor();
//	L.Draw_Text();
}

void Game::GameOver()
{
	_getch();               // �����������
	closegraph();           // �ر�ͼ�ν���
}
