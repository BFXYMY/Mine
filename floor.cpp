#include "floor.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

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
	for(int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout <<   "■";
			if (2 == j)
				cout << endl;
		}
	}
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

