#include "floor.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

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
	for(int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout <<   "��";
			if (2 == j)
				cout << endl;
		}
	}
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

