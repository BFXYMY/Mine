#pragma once

class Lei
{
public: 
	int mine[3][3] = { 0 };			//3X3扫雷地形
	int the_mine = 1;				//炸弹
	
	void Set_Mine();				//设置炸弹函数
	void Draw_Floor();				//描绘地形函数
	void Draw_Num();				//用以测试设置炸弹函数是否合适的函数
	void Draw_Text();				//用来输出文字标题等的函数
	
	Lei();							//构造函数
	~Lei();							//析构函数


};


