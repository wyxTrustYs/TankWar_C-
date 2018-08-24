#pragma once
#include "CMap.h"
#include "CTank.h"
#include "CBullet.h"
#include <vector>
#include <time.h>
using namespace std;
class CGame
{
public:
	void Welcome();
	void InitTankInfo();
	void StartGame(int level,int num,char name[]);
	void MoveSelf();
	void MoveAlly();
	void MoveNPC(int i);
	int BulletCollsion(CBullet& bullet);
	int BulletToTank(CBullet bullet);
	void SaveData(char name[], vector<CTank> &vectank,vector<CBullet> vecbullet,
		char mapname[], char num, char level);
	char* Reading(char name[]);

private:
	CMap MapObj;
	vector<CTank> vecTankObj;
	vector<CBullet> vecBullet;
	char Score[5];
	int TmpSpeed[5];
	
};

