#pragma once
#include "CMap.h"
class CTank
{

	friend class CGame;
public:

	void Move(int ForwardDir);
	void InitTank(int type);
	void DrawTank();
	void ClsObject();
	int Collsion(int ForwardDir);
	void setIsFire(bool flat);

	int getPosX();
	int getPosY();
	int getScore();
	int getBlood();
	int getType();
	int getAlliance();
	int getDir();
	bool getIsFire();
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
	int Speed;
	bool IsFire = false;
	static int TankShape[4][3][3];
	CMap map;
	
};