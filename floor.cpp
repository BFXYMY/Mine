#include "floor.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include <conio.h>

using namespace std;

Lei::Lei()														//���캯��
{
	
}

Lei::~Lei()														//��������
{
	
}

void Lei::Set_Mine()
{
	srand((unsigned)time(NULL));								//�������������
	int Mine_Num = ( rand() % 9 ) + 1;							//����1-9�����������ʽ�ٶ���
	cout << Mine_Num << endl;									//����������Ƿ����Ҫ�󣬺���Ҫ����һ�д���ע�͵�

	int quotient = Mine_Num / 3;								//���������3�������������������
	int remainder = Mine_Num % 3;								//���������3�������������������

	if (0 == remainder)											//3�ı����� 3��6��9
		mine[quotient - 1][2] = 1;
	else
		mine[quotient][remainder - 1] = 1;
	
}


void Lei::Draw_Floor()											//��ӡ�Ź���
{
	/*for(int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout <<   "��";
			if (2 == j)
				cout << endl;
		}
	}*/

	

	//��һ��
	fillrectangle(50, 50, 100, 100);
	fillrectangle(105, 50, 155, 100);
	fillrectangle(160, 50, 210, 100);

	//�ڶ���
	fillrectangle(50,105,100,155);
	fillrectangle(105, 105, 155, 155);
	fillrectangle(160, 105, 210, 155);

	//������
	fillrectangle(50, 160, 100, 210);
	fillrectangle(105, 160, 155,210);
	fillrectangle(160, 160, 210,210);


}


void Lei::Draw_Text()
{
	TCHAR message[] = _T("This is a game about Mine");						//Ҫ���������
	RECT rect = { 250,100,550,200 };										//�������Χ
	LOGFONT font;															//�������壨�ṹ�壩
	COLORREF color = RGB(200,128,37);										//���õ�ǰ������ɫ
	setcolor(color);														//�޸ĵ�ǰ������ɫ
	gettextstyle(&font);													//��ȡ��ǰ������Ϣ
	font.lfHeight = 22;														//���õ�ǰ����߶�Ϊ16
	font.lfWidth = 0;														//���õ�ǰ����������Ӧ
	font.lfWeight = 400;													//���õ�ǰ����ʻ���ϸ
	font.lfItalic = true;													//���õ�ǰ����Ϊб��
	wcscpy_s(font.lfFaceName, _T("����"));									//���õ�ǰ����Ϊ����
	settextstyle(&font);													//��������޸�����
	drawtext(message, &rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);		//��ָ�����η�Χ�ھ������
}



void Lei::Draw_Num()											//��ӡ�Ź������֣��ɿ���ը������λ�ã����Բ��Եĺ�����������ע�ͣ��������������ģʽ
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

