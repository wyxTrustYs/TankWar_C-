#include "CGame.h"
#include "Value.h"
#include <windows.h>
#include <time.h>
void CGame::Welcome() {
	int option;
	char name[10];
	int num;
	int flat;

	MapObj.FullScreen();
	//PlaySoundA("Base.wav", NULL, SND_ASYNC | SND_NODEFAULT | SND_LOOP);
	while (true) {
		system("cls");
		MapObj.PrintChar(35, 5, "坦克大战游戏");
		MapObj.PrintChar(20, 10, "1、开始游戏");
		MapObj.PrintChar(30, 10, "2、编辑地图");
		MapObj.PrintChar(40, 10, "3、载入地图");
		MapObj.PrintChar(50, 10, "4、读取存档\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			system("cls");
			MapObj.FileToMap("init");//开始游戏默认加载地图存放在init.map文件中
			MapObj.LoadMap();
			InitTankInfo();

			while (true)
			{
				MoveSelfAndAlly();
				MoveNPC();
				Sleep(50);
			}
			break;
		case 2:
		{
			system("cls");
			MapObj.PrintChar(20, 10, "1、修改地图");
			MapObj.PrintChar(28, 10, "2、新建地图\n");
			scanf("%d", &num);
			switch (num)
			{
			case 1:
				system("cls");
				system("dir .\\map");
				scanf("%s", name);
				MapObj.FileToMap(name);
				MapObj.EditMap();
				MapObj.MapToFile(name);
				break;
			case 2:
				system("cls");
				MapObj.PrintChar(20, 10, "请输入地图名称");
				scanf("%s", name);
				MapObj.NewMap();		//新建地图
				MapObj.MapToFile(name);//从文件中读取地图
				break;
			default:
				break;
			}
			break;
		}
		case 3:
		{
			system("cls");
			system("dir .\\map");
			printf("请选择你要打开的地图\n");
			scanf("%s", name);
			system("cls");
			MapObj.FileToMap(name);
			MapObj.LoadMap();

			InitTankInfo();
			while (true)
			{
				MoveSelfAndAlly();
				MoveNPC();
				Sleep(50);
			}
			break;
		}
		default:
			return;
		}
		
	}
}
void CGame::InitTankInfo() {
	CTank TmpTank[5];
	CBullet TmpBullet[5];
	TmpTank[0].InitTank(MyTank_1);
	TmpBullet[0].InitBullet(TmpTank[0]);
	vecTankObj.push_back(TmpTank[0]);
	vecBullet.push_back(TmpBullet[0]);

	TmpTank[1].InitTank(EnemyTank_1);
	TmpBullet[1].InitBullet(TmpTank[1]);
	vecTankObj.push_back(TmpTank[1]);
	vecBullet.push_back(TmpBullet[1]);

	TmpTank[2].InitTank(EnemyTank_2);
	TmpBullet[2].InitBullet(TmpTank[2]);
	vecTankObj.push_back(TmpTank[2]);
	vecBullet.push_back(TmpBullet[2]);

	TmpTank[3].InitTank(EnemyTank_3);
	TmpBullet[3].InitBullet(TmpTank[3]);
	vecTankObj.push_back(TmpTank[3]);
	vecBullet.push_back(TmpBullet[3]);

	TmpTank[4].InitTank(EnemyTank_4);
	TmpBullet[4].InitBullet(TmpTank[4]);
	vecTankObj.push_back(TmpTank[4]);
	vecBullet.push_back(TmpBullet[4]);
}
void CGame::StartGame() {

}
void CGame::MoveSelfAndAlly() {
	
	sprintf(Score, "%d", vecTankObj[0].getScore());
	MapObj.PrintChar(63, 15, "你的得分为：");
	MapObj.PrintChar(66, 16, Score);
	if (vecTankObj[0].IsDead == false) {
		if (vecTankObj[0].PreType[2][0] == IceGround &&
			vecTankObj[0].PreType[2][1] == IceGround &&
			vecTankObj[0].PreType[2][2] == IceGround) {
			vecTankObj[0].Move(vecTankObj[0].DirInIce);
		}
		else
		{
			if (GetKeyState('W') < 0)	{	vecTankObj[0].DirInIce = UP; vecTankObj[0].Move(UP); }
			else if (GetKeyState('S') < 0){ vecTankObj[0].DirInIce = DOWN; vecTankObj[0].Move(DOWN); }
			else if (GetKeyState('A') < 0){ vecTankObj[0].DirInIce = LEFT; vecTankObj[0].Move(LEFT); }
			else if (GetKeyState('D') < 0){ vecTankObj[0].DirInIce = RIGHT; vecTankObj[0].Move(RIGHT); }
		}

		if ((GetKeyState(VK_SPACE) < 0) && vecBullet[0].IsExist() == false) {
			vecTankObj[0].setIsFire(true);
			vecBullet[0].Fire(vecTankObj[0]);
		}

	}
	if (vecTankObj[0].getIsFire() && vecBullet[0].IsExist()) {
		if (BulletCollsion(vecBullet[0]) >= MyTank_1)
		{
			if (BulletCollsion(vecBullet[0]) != River)
				return;
		}
		vecBullet[0].Move();
	}
}
void CGame::MoveNPC() {
	int NpcDir = 1;
	for (int i = 1; i < 5; i++) {
		if (vecTankObj[i].IsDead == false) {
			if (vecTankObj[i].PreType[2][0] == IceGround &&
				vecTankObj[i].PreType[2][1] == IceGround &&
				vecTankObj[i].PreType[2][2] == IceGround) {
				vecTankObj[i].Move(vecTankObj[i].DirInIce);
			}
			else
			{
				NpcDir = rand() % 4;
				vecTankObj[i].DirInIce = NpcDir;
				if (NpcDir == 0)vecTankObj[i].Move(UP);
				else if (NpcDir == 1)vecTankObj[i].Move(DOWN);
				else if (NpcDir == 2)vecTankObj[i].Move(LEFT);
				else if (NpcDir == 3)vecTankObj[i].Move(RIGHT);
			}
			if (vecBullet[i].IsExist() == false) {
				//vecTankObj[i].setIsFire(true);
				//vecBullet[i].Fire(vecTankObj[i]);
			}

		}
		else if (vecTankObj[i].IsDead == true) {
			vecTankObj[i].InitTank(vecTankObj[i].getType());
		}
		if (vecTankObj[i].getIsFire() && vecBullet[i].IsExist()) {
			if (BulletCollsion(vecBullet[i]) >= MyTank_1)
			{
				if (BulletCollsion(vecBullet[i]) != River)
					break;
			}
			vecBullet[i].Move();
		}
	}
}

int CGame::BulletCollsion(CBullet& bullet) {
	int tmpx = 0, tmpy = 0;
	CBullet tmpBullet;

	tmpBullet.PosX = bullet.PosX;
	tmpBullet.PosY = bullet.PosY;
	tmpBullet.dir = bullet.dir;

	int MapType = MapObj.getMapValue(tmpBullet.PosX, tmpBullet.PosY);

	switch (tmpBullet.dir)
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
	MapType = MapObj.getMapValue(tmpBullet.PosX, tmpBullet.PosY);
	switch (MapType)
	{
	case MyTank_1:
		bullet.Exist = false;
		bullet.ClsBullet();
		bullet.PreType = Ground;
		if (bullet.Type == EnemyBullet) {
			vecTankObj[0].IsDead = true;
			vecTankObj[0].ClsObject();
		}
		break;
	case MyTank_2:

	case EnemyTank_1:
		vecTankObj[0].setScore(10);
		bullet.Exist = false;
		bullet.ClsBullet();
		bullet.PreType = Ground;
		if (bullet.Type == MyTankBullet) {
			vecTankObj[1].IsDead = true;
			vecTankObj[1].ClsObject();
		}
		break;
	case EnemyTank_2:
		vecTankObj[0].setScore(20);
		bullet.Exist = false;
		bullet.ClsBullet();
		bullet.PreType = Ground;
		if (bullet.Type == MyTankBullet) {
			vecTankObj[2].IsDead = true;
			vecTankObj[2].ClsObject();
		}
		break;
	case EnemyTank_3:
		vecTankObj[0].setScore(30);
		bullet.Exist = false;
		bullet.ClsBullet();
		bullet.PreType = Ground;
		if (bullet.Type == MyTankBullet) {
			vecTankObj[3].IsDead = true;
			vecTankObj[3].ClsObject();
		}
		break;
	case EnemyTank_4:
		vecTankObj[0].setScore(40);
		bullet.Exist = false;
		bullet.ClsBullet();
		bullet.PreType = Ground;
		if (bullet.Type == MyTankBullet) {
			vecTankObj[4].IsDead = true;
			vecTankObj[4].ClsObject();
		}
		break;
	case MyTankBullet:
	case EnemyBullet:
	case IronWall:
		bullet.Exist = false;
		bullet.ClsBullet();
		break;
	case Wall:
		bullet.Exist = false;
		MapObj.ClsMap(tmpBullet.PosX, tmpBullet.PosY, Ground);
		bullet.ClsBullet();
		break;
	case Ground:
	case Forest:
	case River:
	case IceGround: break;
	case Home:
		bullet.Exist = false;
		bullet.ClsBullet();
		bullet.PreType = Ground;
		MapObj.PrintChar(17, 15, "          Game Over           ");
		Sleep(2000);
		exit(0);
		break;
	default:
		break;
	}
	return MapType;
}