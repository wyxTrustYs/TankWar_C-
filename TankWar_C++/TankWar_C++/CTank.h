#pragma once
#include "CMap.h"
class CTank
{
public:

	void Move();
	void InitTank(int type);
	void DrawTank();
	void ClsObject();
	int getPosX();
	int getPosY();
	int getScore();
	int getBlood();
	int getType();
	int getAlliance();
private:
	bool IsDead;
	int PosX;
	int PosY;
	int dir;
	int Score;
	int Blood;
	int Type;
	int Alliance;
	int PreType;
	static int TankShape[4][3][3];
	CMap map;

};