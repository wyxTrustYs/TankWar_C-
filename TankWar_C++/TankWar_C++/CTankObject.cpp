#include "CTankObject.h"
#include "CDrawObject.h"
#include "Value.h"
bool CTankObject::DrawObject() {

	for (int tmpPosY = PosY - 1; tmpPosY < PosY + 2; tmpPosY++) {
		for (int tmpPosX = PosX - 1; tmpPosX < PosX + 2; tmpPosX++) {
			if (TankShape[Dir][tmpPosY][tmpPosX] == 1) {
				PreType = pMapObject->getMapValue(tmpPosX, tmpPosY);
				pMapObject->setMapValue(tmpPosX, tmpPosY, Type);
				CDrawObject objDraw;
				objDraw.DrawPatterning(tmpPosX, tmpPosY, Type);
			}
		}
	}
}

bool CTankObject::ClsObject() {
	int TmpType;
	for (int tmpPosY = PosY - 1; tmpPosY < PosY + 2; tmpPosY++) {
		for (int tmpPosX = PosX - 1; tmpPosX < PosX + 2; tmpPosX++) {
			pMapObject->setMapValue(tmpPosX, tmpPosY, PreType);
			CDrawObject objDraw;
			objDraw.DrawPatterning(tmpPosX, tmpPosY, PreType);
		}
	}
}

CTankObject CTankObject::getTankBirthPlace(int nType) {
	switch (nType)
	{
	case MyTank_1:

		break;
	case MyTank_2:
		//����Draw����
		break;
	case EnemyTank_1:
		//����Draw����
		break;
	case EnemyTank_2:
		//����Draw����
		break;
	case EnemyTank_3:
		//����Draw����
		break;
	case EnemyTank_4:
		//����Draw����
		break;
	default:
		break;
	}
}

bool CTankObject::MoveTank(int Dir) {
	static int preDir = 9;
	CTankObject TmpTankObject;
	if (preDir == 9) {
		//ֱ���ƶ�̹��
	}
	else
	{
		if (preDir == Dir) {
			//�ƶ�̹��
		}
		else
		{
			//�޸ķ���
		}
	}
	//��ײ��⣬�ܹ��ƶ���ô��ԭ����̹�˲���������ʱ������ֵ��������󣬻���̹��
	if (TankCollision(TmpTankObject)) {
		ClsObject();
//		*this = TmpTankObject;
		DrawObject();
	}

	preDir = Dir;
}



bool CTankObject::TankCollision(CTankObject TankObject) {

}

void CTankObject::setMapObject(CMapObject* pMapObject) {

	for (int tmpPosY = PosY - 1; tmpPosY < PosY + 2; tmpPosY++) {
		for (int tmpPosX = PosX - 1; tmpPosX < PosX + 2; tmpPosX++) {
			if (TankShape[Dir][tmpPosY][tmpPosX] == 1) {
				pMapObject->setMapValue(PosX, PosY, Type);
			}
		}
	}
}


CMapObject* CTankObject::getMapObj() {
	return pMapObject;
}


bool CTankObject::getTankIsDead() {
	return IsDead;
}
int CTankObject::getAlignment() {
	return Alignment;
}
int CTankObject::getTankPosX() {
	return PosX;
}
int CTankObject::getTankPosY() {
	return PosY;
}
int CTankObject::getTankDir() {
	return Dir;
}
int CTankObject::getTankType() {
	return Type;
}
int CTankObject::getTankBlood() {
	return Blood;
}
int CTankObject::getTankScores() {
	return Score;
}
int CTankObject::getPreType() {
	return PreType;
}