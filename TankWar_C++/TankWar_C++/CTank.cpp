#include "CTank.h"
#include "Value.h"
#include <conio.h>
#include <windows.h>
int CTank::TankShape[4][3][3] = {
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

void CTank::InitTank(int type) {
	switch (type)
	{
	case MyTank_1:
		dir = UP;
		PosX = 20;
		PosY = 20;
		Type = type;
		Alliance = 1;
		Score = 0;
		Blood = 3;
		IsDead = false;
		TankColor = 7;
//		map.setMapValue(PosX, PosY, type);
		DrawTank();
		break;
	case EnemyTank_1:
		dir = DOWN;
		PosX = 2;
		PosY = 2;
		Type = type;
		Alliance = 2;
		Score = 0;
		Blood = 3;
		IsDead = false;
		TankColor = 1;
//		map.setMapValue(PosX, PosY, type);
		DrawTank();
		break;
	case EnemyTank_2:
		dir = DOWN;
		PosX = 10;
		PosY = 2;
		Type = type;
		Score = 0;
		Blood = 3;
		Alliance = 2;
		IsDead = false;
		TankColor = 2;
//		map.setMapValue(PosX, PosY, type);
		DrawTank();
		break;
	case EnemyTank_3:
		dir = DOWN;
		PosX = 20;
		PosY = 2;
		Type = type;
		Score = 0;
		Blood = 3;
		Alliance = 2;
		IsDead = false;		
		TankColor = 4;
//		map.setMapValue(PosX, PosY, type);
		DrawTank();
		break;
	case EnemyTank_4:
		dir = DOWN;
		PosX = 30;
		PosY = 2;
		Type = type;
		Score = 0;
		Blood = 3;
		Alliance = 2;
		IsDead = false;
		TankColor = 6;
//		map.setMapValue(PosX, PosY, type);
		DrawTank();
		break;
	default:
		break;
	}
}


void CTank::Move(int ForwardDir) {
	int tmpx = 0, tmpy = 0;
	if (Collsion(ForwardDir) != 0) {
		if (this->dir != ForwardDir) {
			this->dir = ForwardDir;
			ClsObject();
			DrawTank();
		}
		return;
	}


	switch (ForwardDir)
	{
	case UP:
		tmpx = 0;
		tmpy = -1;
		dir = UP;
		break;
	case DOWN:
		tmpx = 0;
		tmpy = 1;
		dir = DOWN;
		break;
	case LEFT:
		tmpx = -1;
		tmpy = 0;
		dir = LEFT;
		break;
	case RIGHT:
		tmpx = 1;
		tmpy = 0;
		dir = RIGHT;
		break;
	default:
		break;
	}

	
	ClsObject();
	PosX += tmpx;
	PosY += tmpy;
	DrawTank();
}
void CTank::DrawTank() {
	for (int tmpPosY = PosY - 1,Y = 0; tmpPosY < PosY + 2; tmpPosY++,Y++) {
		for (int tmpPosX = PosX - 1,X = 0; tmpPosX < PosX + 2; tmpPosX++,X++) {
			if (map.getMapValue(tmpPosX, tmpPosY) < MyTank_1) {
				PreType[Y][X] = map.getMapValue(tmpPosX, tmpPosY);
			}
			map.setMapValue(tmpPosX, tmpPosY, Type);

			switch (PreType[Y][X])
			{
			case Ground:
				if (TankShape[dir][Y][X] == 1) {
					map.PrintChar(tmpPosX, tmpPosY, "¨€", TankColor);
				}
				break;
			case Forest:
				map.PrintChar(tmpPosX, tmpPosY, "¡ù", 2);
				break;
			
			case IceGround:
				if (TankShape[dir][Y][X] == 1) {
					map.PrintChar(tmpPosX, tmpPosY, "¨€", TankColor);
				}
				break;
			default:
				break;
			}

			
		}
	}
}

void CTank::ClsObject() {
	for (int tmpPosY = PosY - 1,Y = 0; tmpPosY < PosY + 2; tmpPosY++,Y++) {
		for (int tmpPosX = PosX - 1,X = 0; tmpPosX < PosX + 2; tmpPosX++,X++) {
			map.setMapValue(tmpPosX, tmpPosY, PreType[Y][X]);
			switch (PreType[Y][X])
			{
			case Ground:
				map.PrintChar(tmpPosX, tmpPosY, " ");
				break;				   
			case Forest:			   
				map.PrintChar(tmpPosX, tmpPosY, "¡ù", 2);
				break;		  		   
			case River:		  		   
				map.PrintChar(tmpPosX, tmpPosY, "¡Ö", 1);
				break;		  		   
			case IceGround:	  		   
				map.PrintChar(tmpPosX, tmpPosY, "¨ˆ", 15);
				break;		  		   
			default:		  		   
				break;
			}
		}
	}
}

int CTank::Collsion(int ForwardDir) {
	int tmpx = 0, tmpy = 0;
	CTank TmpTank;
	int isedge = 0;
	TmpTank.PosX = this->PosX;
	TmpTank.PosY = this->PosY; 
	switch (ForwardDir)
	{
	case UP:
		tmpx = 0;
		tmpy = -1;
		TmpTank.PosX += tmpx * 2;
		TmpTank.PosY += tmpy * 2;
		if (map.getMapValue(TmpTank.PosX, TmpTank.PosY) >= MyTank_1 ||
			map.getMapValue(TmpTank.PosX - 1, TmpTank.PosY) >= MyTank_1 ||
			map.getMapValue(TmpTank.PosX + 1, TmpTank.PosY) >= MyTank_1) {
			return 1;
		}
		else return 0;
		
	case DOWN:
		tmpx = 0;
		tmpy = 1;
		TmpTank.PosX += tmpx * 2;
		TmpTank.PosY += tmpy * 2;
		if (map.getMapValue(TmpTank.PosX, TmpTank.PosY) >= MyTank_1 ||
			map.getMapValue(TmpTank.PosX - 1, TmpTank.PosY) >= MyTank_1 ||
			map.getMapValue(TmpTank.PosX + 1, TmpTank.PosY) >= MyTank_1) {
			return 1;
		}
		else return 0;
	case LEFT:
		tmpx = -1;
		tmpy = 0;
		TmpTank.PosX += tmpx * 2;
		TmpTank.PosY += tmpy * 2;
		if (map.getMapValue(TmpTank.PosX, TmpTank.PosY) >= MyTank_1 ||
			map.getMapValue(TmpTank.PosX , TmpTank.PosY - 1) >= MyTank_1 ||
			map.getMapValue(TmpTank.PosX , TmpTank.PosY + 1) >= MyTank_1) {
			return 1;
		}
		else return 0;
	case RIGHT:
		tmpx = 1;
		tmpy = 0;
		TmpTank.PosX += tmpx * 2;
		TmpTank.PosY += tmpy * 2;
		if (map.getMapValue(TmpTank.PosX, TmpTank.PosY) >= MyTank_1 ||
			map.getMapValue(TmpTank.PosX, TmpTank.PosY - 1) >= MyTank_1 ||
			map.getMapValue(TmpTank.PosX, TmpTank.PosY + 1) >= MyTank_1) {
			return 1;
		}
		else return 0;
	default:
		break;
	}
}

void CTank::setScore(int newScore) {
	this->Score += newScore;
}

void CTank::setIsFire(bool flat) {
	IsFire = flat;
}

int CTank::getPosX() {
	return PosX;
}
int CTank::getPosY() {
	return PosY;

}
int CTank::getScore() {
	return Score;

}
int CTank::getBlood() {
	return Blood;

}
int CTank::getType() {
	return Type;

}
int CTank::getAlliance() {
	return Alliance;

}
int CTank::getDir() {
	return this->dir;
}
bool CTank::getIsFire() {
	return IsFire;
}