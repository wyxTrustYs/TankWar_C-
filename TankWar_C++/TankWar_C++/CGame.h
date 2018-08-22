#pragma once
#include "CMap.h"
#include "CTank.h"
#include "CBullet.h"
#include <vector>
using namespace std;
class CGame
{
public:
	void Welcome();
	void InitTankInfo();
	void StartGame();
	void MoveSelfAndAlly();
	void MoveNPC();
	int BulletCollsion(CBullet& bullet);
private:
	CMap MapObj;
	vector<CTank> vecTankObj;
	vector<CBullet> vecBullet;
};

