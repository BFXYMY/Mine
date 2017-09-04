#include "floor.h"
#include <iostream>
#include <string>
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

void Lei::Set_Mine()
{
	srand((unsigned)time(NULL));								//设置随机数种子
	int Mine_Num = ( rand() % 9 ) + 1;							//设置1-9的随机数，公式百度有
	cout << Mine_Num << endl;									//测试随机数是否符合要求，后续要把这一行代码注释掉

	int quotient = Mine_Num / 3;								//随机数除以3的商数，用来设计行数
	int remainder = Mine_Num % 3;								//随机数除以3的余数，用来设计列数

	if (0 == remainder)											//3的倍数： 3，6，9
		mine[quotient - 1][2] = 1;
	else
		mine[quotient][remainder - 1] = 1;
	
}


void Lei::Draw_Floor()											//打印九宫格
{
	/*for(int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout <<   "■";
			if (2 == j)
				cout << endl;
		}
	}*/

	

	//第一行
	fillrectangle(50, 50, 100, 100);
	fillrectangle(105, 50, 155, 100);
	fillrectangle(160, 50, 210, 100);

	//第二行
	fillrectangle(50,105,100,155);
	fillrectangle(105, 105, 155, 155);
	fillrectangle(160, 105, 210, 155);

	//第三行
	fillrectangle(50, 160, 100, 210);
	fillrectangle(105, 160, 155,210);
	fillrectangle(160, 160, 210,210);


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



void Lei::Draw_Num()											//打印九宫格数字，可看到炸弹所处位置，用以测试的函数，后期需注释，或用于设计作弊模式
{
	cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << mine[i][j];
			if (2 == j)
				cout << endl;
		}
	}
}

