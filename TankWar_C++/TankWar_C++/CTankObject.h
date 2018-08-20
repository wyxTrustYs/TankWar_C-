#pragma once
#include "CBase.h"
#include "CMapObject.h"


/*  
	坦克类里面有
	（变量）：
	坦克的位置
	坦克的血量
	坦克的方向
	坦克的分数
	坦克的阵营
	坦克是否死亡
	（方法）：
	获取坦克的位置

*/

class CTankObject:virtual public CBaseObject
{
public:
	CTankObject();
	~CTankObject();
	//画坦克
	bool DrawObject();
	//擦坦克
	bool ClsObject();

	//根据类型获取坦克的出生地，返回对应的坦克（用于重生）
	CTankObject getTankBirthPlace(int nType);
	//移动坦克
	bool MoveTank(int Dir);
	//坦克碰撞
	bool TankCollision(CTankObject TankObject);
	//设置地图对象（创建的每一个坦克对象中都记录地图的地址）
	void setMapObject(CMapObject* pMapObject);
	//返回地图对象
	CMapObject *getMapObj();
	//设置坦克形状
	void setTankShape();
	bool getTankIsDead();
	int getAlignment();
	int getTankPosX();
	int getTankPosY();
	int getTankDir();
	int getTankType();
	int getTankBlood();
	int getTankScores();
	int getPreType();

private:
	int IsDead;		//坦克是否死亡
	int Alignment;	//所属阵营
	int PosX;		//坦克X坐标
	int PosY;		//坦克Y坐标
	int Dir;		//坦克当前方向
	int Type ;		//坦克类型
	int Blood;		//坦克血量
	int Score;		//坦克杀敌分数
	int PreType;		//坦克之前走过的地形
	CMapObject* pMapObject;
	const int TankShape[4][3][3] = {
		{
			{ 0,1,0 },
			{ 1,1,1 },
			{ 1,0,1 },
		},
		{
			{ 1,0,1 },
			{ 1,1,1 },
			{ 0,1,0 },
		},
		{
			{ 0,1,1 },
			{ 1,1,0 },
			{ 0,1,1 },
		},
		{
			{ 1,1,0 },
			{ 0,1,1 },
			{ 1,1,0 },
		},
	};
};

