#pragma once

class Lei
{
public: 
	int mine[3][3] = { 0 };			//3X3ɨ�׵���
	int the_mine = 1;				//ը��
	
	void Set_Mine();				//����ը������
	void Draw_Floor();				//�����κ���
	void Draw_Num();				//���Բ�������ը�������Ƿ���ʵĺ���
	void Draw_Text();				//����������ֱ���ȵĺ���
	
	Lei();							//���캯��
	~Lei();							//��������


};


