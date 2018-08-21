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
		map.setMapValue(PosX, PosY, type);
		DrawTank();
	default:
		break;
	}
}


void CTank::Move(int ForwardDir) {
	int tmpx = 0, tmpy = 0;

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
// 	if (GetKeyState('W') < 0)
// 	{
// 		dir = UP;
// 		tmpx = 0;
// 		tmpy = -1;
// 	}
// 	if (GetKeyState('S') < 0)
// 	{
// 		tmpx = 0;
// 		tmpy = 1;
// 		dir = DOWN;
// 	}
// 	if (GetKeyState('A') < 0)
// 	{
// 		tmpx = -1;
// 		tmpy = 0;
// 		dir = LEFT;
// 	}
// 
// 	if (GetKeyState('D') < 0)
// 	{
// 		tmpx = 1;
// 		tmpy = 0;
// 		dir = RIGHT;
// 	}
	
	ClsObject();
	PosX += tmpx;
	PosY += tmpy;
	DrawTank();
}
void CTank::DrawTank() {
	for (int tmpPosY = PosY - 1,Y = 0; tmpPosY < PosY + 2; tmpPosY++,Y++) {
		for (int tmpPosX = PosX - 1,X = 0; tmpPosX < PosX + 2; tmpPosX++,X++) {
			if (TankShape[dir][Y][X] == 1) {
				PreType = map.getMapValue(tmpPosX, tmpPosY);
				map.setMapValue(tmpPosX, tmpPosY, Type);
				map.PrintChar(tmpPosX, tmpPosY, "¨€");
			}
		}
	}
}

void CTank::ClsObject() {
	int TmpType;
	for (int tmpPosY = PosY - 1; tmpPosY < PosY + 2; tmpPosY++) {
		for (int tmpPosX = PosX - 1; tmpPosX < PosX + 2; tmpPosX++) {
			map.setMapValue(tmpPosX, tmpPosY, PreType);
			map.PrintChar(tmpPosX, tmpPosY, " ");
		}
	}
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