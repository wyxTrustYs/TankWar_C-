#include "CGameObject.h"
#include "Value.h"
#include <conio.h>
#include <time.h>
bool CGameObject::InitTankInfo() {
	CTankObject TmpTankObject;
	TmpTankObject = TmpTankObject.getTankBirthPlace(MyTank_1);
	vecTankObject.push_back(TmpTankObject);
	for (unsigned int i = 0; i < vecTankObject.size(); i++) {
		vecTankObject[i].setMapObject(&MapObject);
	}
}

bool CGameObject::MoveSelfAndALLY() {
	Dir m_dir;
	if (GetKeyState('W') < 0) {
		m_dir = UP;
		vecTankObject[0].MoveTank(UP);
	}
	if (GetKeyState('S') < 0) {
		m_dir = DOWN;
		vecTankObject[0].MoveTank(DOWN);
	}
	if (GetKeyState('A') < 0) {
		m_dir = LEFT;
		vecTankObject[0].MoveTank(LEFT);
	}
	if (GetKeyState('D') < 0) {
		m_dir = RIGHT;
		vecTankObject[0].MoveTank(RIGHT);
	}
	if (GetKeyState(VK_SPACE) < 0) {
		CBullet TmpBullet;
		TmpBullet = TmpBullet.CreatBullet(vecTankObject[0], vecTankObject);
		vecBulletObject.push_back(TmpBullet);
	}
}

bool CGameObject::MoveNPC() {
	Dir m_dir;
	int TmpDir = 1;
	srand((unsigned)time(NULL));
	TmpDir = rand() % 4;
	if (TmpDir == 0) {
		m_dir = UP;
		vecTankObject[0].MoveTank(UP);
	}
	if (TmpDir == 1) {
		m_dir = DOWN;
		vecTankObject[0].MoveTank(DOWN);
	}
	if (TmpDir == 2) {
		m_dir = LEFT;
		vecTankObject[0].MoveTank(LEFT);
	}
	if (TmpDir == 3) {
		m_dir = RIGHT;
		vecTankObject[0].MoveTank(RIGHT);
	}
// 	if (GetKeyState(VK_SPACE) < 0) {
// 		CBullet TmpBullet;
// 		TmpBullet = TmpBullet.CreatBullet(vecTankObject[0], vecTankObject);
// 		vecBulletObject.push_back(TmpBullet);
// 	}
}

