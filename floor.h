#pragma once
#define Picture_Width 20
#define Mine_Number 40
#define Floor_Row 16
#define Floor_Col 16

typedef struct Mine
{
	int Mine_Num;
	bool Has_Mine;
	bool Is_Dug;
}Cell;

class Lei
{
public: 

	void Set_Mine(Cell map[Floor_Row][Floor_Col], int X_Start, int Y_Start);				//����ը������
	void Draw_Floor();				//�����κ���
	void Draw_Text();				//����������ֱ���ȵĺ���
	
	Lei();							//���캯��
	~Lei();							//��������


};




