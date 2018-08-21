#include "CBullet.h"
#include "Value.h"

void CBullet::InitBullet(CTank tank) {

	this->dir = tank.getDir();
	this->Alliance = tank.getAlliance();
	IsDead = false;
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
	map.setMapValue(PosX, PosY, Type);
}
void CBullet::DrawBullet() {
	PreType = map.getMapValue(PosX, PosY);
	map.setMapValue(PosX, PosY, Type);
	map.PrintChar(PosX, PosY, "*");
}

void CBullet::ClsBullet() {
	map.setMapValue(PosX, PosY, PreType);
	map.PrintChar(PosY, PosY, "  ");
}

void CBullet::Move() {
	int tmpx = 0, tmpy = 0;
	if (IsEdge(dir) != 0) return;
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

int CBullet::IsEdge(int ForwardDir) {
	int tmpx = 0, tmpy = 0;

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

	PosX += tmpx;
	PosY += tmpy;
	if (map.getMapValue(PosX, PosY) != Ground) {
		return 1;
	}
	else return 0;

}



int CBullet::getPosX() {
	return PosX;
}

int CBullet::getPosY() {
	return PosY;
}

bool CBullet::IsExist() {
	return IsDead;
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