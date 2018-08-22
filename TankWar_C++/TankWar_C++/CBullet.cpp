#include "CBullet.h"
#include "Value.h"

void CBullet::InitBullet(CTank tank) {
	this->Alliance = tank.getAlliance();
	this->Speed = 50;
	if (tank.getType() == MyTank_1 || tank.getType() == MyTank_2) {
		this->Type = MyTankBullet;
	}
	else
	{
		this->Type = EnemyBullet;
	}
	
	this->PreType = Ground;
	Exist = false;
}
void CBullet::DrawBullet() {
	PreType = map.getMapValue(PosX, PosY);
	map.setMapValue(PosX, PosY, Type);
	map.PrintChar(PosX, PosY, "*");
}

void CBullet::ClsBullet() {
	map.setMapValue(PosX, PosY, PreType);
	map.PrintChar(PosX, PosY, " ");
}


//Ground, MyTank_1, MyTank_2, EnemyTank_1, EnemyTank_2, EnemyTank_3, EnemyTank_4,
//Wall, IronWall, Forest, River, IceGround,
//MyTankBullet, EnemyBullet,
//Home
void CBullet::Move() {
	int tmpx = 0, tmpy = 0;
		
	switch (dir)
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
	ClsBullet();
	PosX += tmpx;
	PosY += tmpy;
	DrawBullet();
}


void CBullet::Fire(CTank tank) {
	this->dir = tank.getDir();
	Exist = true;
	switch (dir)
	{
	case UP:
		this->PosX = tank.getPosX();
		this->PosY = tank.getPosY() - 2;
		break;
	case DOWN:
		this->PosX = tank.getPosX();
		this->PosY = tank.getPosY() + 2;
		break;
	case LEFT:
		this->PosX = tank.getPosX() - 2;
		this->PosY = tank.getPosY();
		break;
	case RIGHT:
		this->PosX = tank.getPosX() + 2;
		this->PosY = tank.getPosY();
		break;
	default:
		break;
	}
 	if (map.getMapValue(PosX, PosY) == IronWall ) {
 		Exist = false;
 		return;
 	}
 	if (map.getMapValue(PosX, PosY) == Wall) {
 		Exist = false;
 		map.ClsMap(PosX, PosY, Ground);
 		ClsBullet();
 		return ;
 	}
//	map.setMapValue(PosX, PosY, Type);
}


int CBullet::getPosX() {
	return PosX;
}

int CBullet::getPosY() {
	return PosY;
}

bool CBullet::IsExist() {
	return Exist;
}

int CBullet::getType() {
	return Type;
}

int CBullet::getAlliance() {
	return Alliance;
}
int CBullet::getPreType() {
	return PreType;
}