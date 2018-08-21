#pragma once
#include "CMap.h"
#include "CTank.h"
class CBullet
{

public:
	void Move();		//子弹移动函数
	void InitBullet(CTank tank);	//子弹初始化
	void DrawBullet();				//画子弹
	void ClsBullet();				//擦除子弹
	int IsEdge(int ForwardDir);		//判断边界

	//获取子弹的各种属性
	bool IsExist();
	int getPosX();					
	int getPosY();							
	int getType();					
	int getAlliance();				
	int getPreType();

private:
	bool IsDead;
	int PosX;
	int PosY;
	int dir;
	int Type;
	int Alliance;
	int PreType;
	CMap map;
};

