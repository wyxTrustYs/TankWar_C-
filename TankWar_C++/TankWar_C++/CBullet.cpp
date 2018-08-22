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


//Ground, MyTank_1, MyTank_2, EnemyTank_1, EnemyTank_2, EnemyTank_3, EnemyTank_4,
//Wall, IronWall, Forest, River, IceGround,
//MyTankBullet, EnemyBullet,
//Home
void CBullet::Move() {
	int tmpx = 0, tmpy = 0;
		switch (Collsion(dir))
		{
		case Ground:
			break;
		case MyTank_1:
			return;

		case MyTank_2:
			return;

		case EnemyTank_1:
			return;

		case EnemyTank_2:
			return;

		case EnemyTank_3:
			return;

		case EnemyTank_4:
			return;

		case Wall:
			return;

		case IronWall:
			return;

		case Forest:
			break;
		case River:
			break;
		case IceGround:
			break;
		case MyTankBullet:
			return;

		case EnemyBullet:
			return;

		case Home:
			return;

		default:
			break;
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
	int MapType = map.getMapValue(tmpBullet.PosX, tmpBullet.PosY);
	switch (MapType)
	{
	case Ground:
		break;
	case MyTank_1:
		Exist = false;
		ClsBullet();
		break;

	case MyTank_2:
		Exist = false;
		ClsBullet();
		break;

	case EnemyTank_1:
		Exist = false;
		ClsBullet();
		break;

	case EnemyTank_2:
		Exist = false;
		ClsBullet();
		break;

	case EnemyTank_3:
		Exist = false;
		ClsBullet();
		break;

	case EnemyTank_4:
		Exist = false;
		ClsBullet();
		break;
	case Wall:
		Exist = false;
		map.ClsMap(tmpBullet.PosX, tmpBullet.PosY, Ground);
		ClsBullet();
		break;
	case IronWall:
		Exist = false;
		ClsBullet();

		break;
	case Forest:
		break;
	case River:
		break;
	case IceGround:
		break;
	case MyTankBullet:
		Exist = false;
		ClsBullet();
		break;

	case EnemyBullet:
		Exist = false;
		ClsBullet();
		break;

	case Home:
		Exist = false;
		ClsBullet();
		break;

	default:
		break;
	}
	return MapType;

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
	if (map.getMapValue(PosX, PosY) != Ground) {
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