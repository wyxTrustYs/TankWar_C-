#include "CBullet.h"
#include "Value.h"

void CBullet::InitBullet(CTank tank) {
	this->Alliance = tank.getAlliance();
	this->Speed = 50;
	this->Type = tank.getType();
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

void CBullet::Move() {
	int tmpx = 0, tmpy = 0;
	if (Collsion(dir) != 0) {
		Exist = false;
		ClsBullet();
		return;
	}
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

int CBullet::Collsion(int ForwardDir) {
	int tmpx = 0, tmpy = 0;
	CBullet tmpBullet;
	tmpBullet.PosX = this->PosX;
	tmpBullet.PosY = this->PosY;
	tmpBullet.dir = this->dir;
	switch (ForwardDir)
	{
	case UP:
		tmpx = 0;
		tmpy = -1;
		break;
	case DOWN:
		tmpx = 0;
		tmpy = 1;
		break;
	case LEFT:
		tmpx = -1;
		tmpy = 0;
		break;
	case RIGHT:
		tmpx = 1;
		tmpy = 0;
		break;
	default:
		break;
	}

	tmpBullet.PosX += tmpx;
	tmpBullet.PosY += tmpy;
	return map.getMapValue(tmpBullet.PosX, tmpBullet.PosY);

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
	if (map.getMapValue(PosX,PosY) != Ground) {
		Exist = false;
		return;
	}
	map.setMapValue(PosX, PosY, Type);
	
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