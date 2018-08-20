#pragma once
#include "CBase.h"
#include "CTankObject.h"
#include <vector>
using namespace std;
class CBullet:virtual public CBaseObject
{
public:
	CBullet();
	~CBullet();

	bool DrawObject(); //画子弹
	bool DrawObject(int PosX, int PosY, int nType);
	bool ClsObject();//擦子弹
	bool ClsObject(int PosX, int PosY, int nType);
	//创建子弹（传入保存坦克的向量，主要用于子弹与坦克的碰撞）
	CBullet CreatBullet(CTankObject TankObject, //发子弹的坦克
		vector<CTankObject>& vecTankObject);

	//移动子弹
	bool MoveBullet(vector<CTankObject>& vecTankObject);

	//子弹碰撞检测
	bool BulletCollision(CBaseObject& BulletObject, //子弹对象
		vector<CTankObject>& vecTankObject);

	//重载=运算(创建子弹时，坦克对象对子弹对象赋值)
	bool operator=(CTankObject TankObject);
	//重载==运算符（子弹与坦克碰撞，子弹对象与坦克对象坐标的比较）
	bool operator==(CTankObject TankObject);
	//获取子弹属性
	bool getBulletIsDead();
	int getBulletPosX();
	int getBulletPosY();
	int getBulletDir();
	int getBulletType();
	int getBulletATK();

private:
	bool IsDead;	//子弹是否存活
	int Alignment;	//所属阵营
	int PosX;		//子弹的X坐标
	int PosY;		//子弹的Y坐标
	int Dir;		//子弹的方向
	int Type;		//子弹的类型
	int ATK;		//子弹攻击力

	CMapObject* pMapObject;
};