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
	void setScore(int newScore);

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
	int Score = 0;
	int Blood;
	int Type;
	int Alliance;
	int PreType[3][3];
	int Speed;
	bool IsFire = false;
	int DirInIce = 0;
	int TankColor = 7;
	static int TankShape[4][3][3];
	CMap map;
	
};