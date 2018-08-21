#include "CGame.h"
#include "Value.h"
#include <windows.h>
#include <time.h>
void CGame::Welcome() {

}
void CGame::InitTankInfo() {
	CTank TmpTank[5];
	TmpTank[0].InitTank(MyTank_1);
	vecTankObj.push_back(TmpTank[0]);
	TmpTank[1].InitTank(EnemyTank_1);
	vecTankObj.push_back(TmpTank[1]);
	TmpTank[2].InitTank(EnemyTank_2);
	vecTankObj.push_back(TmpTank[2]);
	TmpTank[3].InitTank(EnemyTank_3);
	vecTankObj.push_back(TmpTank[3]);
	TmpTank[4].InitTank(EnemyTank_4);
	vecTankObj.push_back(TmpTank[4]);
}
void CGame::StartGame() {

}
void CGame::MoveSelfAndAlly() {
	CBullet TmpBullet;
	if (GetKeyState('W') < 0)vecTankObj[0].Move(UP);
	else if (GetKeyState('S') < 0)vecTankObj[0].Move(DOWN);
	else if (GetKeyState('A') < 0)vecTankObj[0].Move(LEFT);
	else if (GetKeyState('D') < 0)vecTankObj[0].Move(RIGHT);
	
	if (GetKeyState(VK_SPACE) < 0) {
		vecTankObj[0].setIsFire(true);
		TmpBullet.InitBullet(vecTankObj[0]);
		vecBullet.push_back(TmpBullet);

	}
	if (vecTankObj[0].getIsFire() && vecBullet[0].IsExist()) {
		vecBullet[0].Move();
	}
}
void CGame::MoveNPC() {
	int NpcDir = 1;
	for (int i = 1; i < 5; i++) {
		NpcDir = rand() % 4;
		if (NpcDir == 0)vecTankObj[i].Move(UP);
		else if (NpcDir == 1)vecTankObj[i].Move(DOWN);
		else if (NpcDir == 2)vecTankObj[i].Move(LEFT);
		else if (NpcDir == 3)vecTankObj[i].Move(RIGHT);
	}

}
void CGame::Fire(CTank tank) {
	CBullet TmpBullet;
	TmpBullet.InitBullet(tank);
	vecBullet.push_back(TmpBullet);
	TmpBullet.Move();
}