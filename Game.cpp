#include "Game.h"
#include <graphics.h>
#include <conio.h>

Lei L;
MOUSEMSG mouse;
IMAGE replace, re;
int positionx = 0, positiony = 0;

Game::Game()
{
	
}

Game::~Game()
{
	
}

void Game::GameStart()
{
	initgraph(Picture_Width * Floor_Row, Picture_Width * Floor_Col);    // ��ʼ����ͼ����
	L.Draw_Floor();
	L.Set_Mine();
	L.Lei_Travel();
}

void Game::GameRun()                                                     //��Ϸ����
{
	mouse = GetMouseMsg();
	while (1) {
		if (mouse.uMsg == WM_RBUTTONDOWN)                      //�Ҽ��˳�
		{
			break;
		}
		if (mouse.uMsg == WM_LBUTTONDOWN)                         //���ѡ��
		{                                                      
			positionx = mouse.x / Picture_Width;
			positiony = mouse.y / Picture_Width;
			Judge(positionx, positiony);
			if (9 == L.point[positionx][positiony])
				GameOver();
		}
		mouse = GetMouseMsg();
	}
}

void Game::GameOver()
{
	for (int row = 0; row < 16; row++)
	{
		for (int col = 0; col < 16; col++)
			Judge(row, col);
	}
	Sleep(3000);
	cleardevice();
	IMAGE end;
	loadimage(&end, _T("./IMAGE/icon.jpg"));
	putimage(5 * Picture_Width, 5 * Picture_Width, &end);
	
	_getch();               // �����������
	closegraph();           // �ر�ͼ�ν���
}

void Game::Judge(int row, int col)
{
	switch (L.point[row][col])
	{
	case 1:loadimage(&replace, _T("./IMAGE/1.jpg"));
		break;
	case 2:loadimage(&replace, _T("./IMAGE/2.jpg"));
		break;
	case 3:loadimage(&replace, _T("./IMAGE/3.jpg"));
		break;
	case 4:loadimage(&replace, _T("./IMAGE/4.jpg"));
		break;
	case 5:loadimage(&replace, _T("./IMAGE/5.jpg"));
		break;
	case 6:loadimage(&replace, _T("./IMAGE/6.jpg"));
		break;
	case 7:loadimage(&replace, _T("./IMAGE/7.jpg"));
		break;
	case 8:loadimage(&replace, _T("./IMAGE/8.jpg"));
		break;
	case 9:loadimage(&replace, _T("./IMAGE/bomb.jpg"));
		break;
	}
	loadimage(&re, _T("./IMAGE/cell.jpg"));
	putimage(row * Picture_Width, col * Picture_Width, &re);
	putimage(row * Picture_Width, col * Picture_Width, &replace);
}