#include "floor.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include <conio.h>


using namespace std;

Lei::Lei()														//构造函数
{
	
}

Lei::~Lei()														//析构函数
{
	
}

void Lei::Set_Mine(Cell map[Floor_Row][Floor_Col],int X_Start,int Y_Start)
{
	for(int i = 0; i < Floor_Row; i++)
	{
		for (int j = 0; j < Floor_Col; j++)
		{
			map[i][j].Mine_Num = 0;
			map[i][j].Has_Mine = false;
			map[i][j].Is_Dug = false;
		}

	}

	srand((unsigned)time(NULL));										//设置随机数种子
	int count = 0;														//设置当前地雷数量
	int Mine[Mine_Number];												//设置地雷集（40个地雷）
	while(count < Mine_Number)
	{
		if (0 == count)												
			Mine[0] = rand() % (Floor_Row * Floor_Col);					//设置0-256的随机数，公式百度有
		else
		{
			Mine[count] = Mine[count] = rand() % (Floor_Row * Floor_Col);
		}
		count++;
	}

	for(int i = 0; i < Mine_Number; i++)
	{
		map[Mine[i] / Floor_Row == 0 ? 0 : Mine[i] / Floor_Row - 1][Mine[i] - 1].Has_Mine = true;		//使用三目运算符，将地雷位置对应到地图中
	}
						

	
}


void Lei::Draw_Floor()											
{
	IMAGE cell, none, mine, number;
	loadimage(&cell,_T("./IMAGE/cell.jpg"));
	loadimage(&none, _T("./IMAGE/s.jpg"));
	for(int i = 0;i < Floor_Row; i++)
	{
		for (int j = 0; j < Floor_Col; j++)
		{
			putimage(i * Picture_Width, j * Picture_Width, &cell);
			putimage(i * Picture_Width, j * Picture_Width, &none);
		}
			
	}


}


void Lei::Draw_Text()
{
	TCHAR message[] = _T("This is a game about Mine");						//要输出的内容
	RECT rect = { 250,100,550,200 };										//输出矩阵范围
	LOGFONT font;															//设置字体（结构体）
	COLORREF color = RGB(200,128,37);										//设置当前字体颜色
	setcolor(color);														//修改当前字体颜色
	gettextstyle(&font);													//获取当前字体信息
	font.lfHeight = 22;														//设置当前字体高度为16
	font.lfWidth = 0;														//设置当前字体宽度自适应
	font.lfWeight = 400;													//设置当前字体笔画纤细
	font.lfItalic = true;													//设置当前字体为斜体
	wcscpy_s(font.lfFaceName, _T("黑体"));									//设置当前字体为宋体
	settextstyle(&font);													//完成字体修改设置
	drawtext(message, &rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);		//在指定矩形范围内居中输出
}




