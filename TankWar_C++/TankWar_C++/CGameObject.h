#pragma once
#include "CMapObject.h"
#include "CTankObject.h"
#include "CBullet.h"
#include <vector>
using namespace std;
class CGameObject
{
public:
	CGameObject();
	~CGameObject();

	//欢迎界面
	bool Welcome();
	//初始化坦克信息
	bool InitTankInfo();
	//开始游戏
	bool StartGame();
	//通过键盘移动坦克
	bool MoveSelfAndALLY();
	//敌方坦克移动
	bool MoveNPC();
private:
	//地图对象
	CMapObject MapObject;
	//坦克向量
	vector<CTankObject> vecTankObject;
	//子弹向量
	vector<CBullet> vecBulletObject;
};

