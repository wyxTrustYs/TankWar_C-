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
			break;
			/*	InitMap();
			InitHome();*/
			//Move();
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
			break;
		}
		default:
			break;
		}
		return;
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
	if (GetKeyState('W') < 0)vecTankObj[0].Move(UP);
	else if (GetKeyState('S') < 0)vecTankObj[0].Move(DOWN);
	else if (GetKeyState('A') < 0)vecTankObj[0].Move(LEFT);
	else if (GetKeyState('D') < 0)vecTankObj[0].Move(RIGHT);
	
	if ((GetKeyState(VK_SPACE) < 0)&&vecBullet[0].IsExist() == false) {
		vecTankObj[0].setIsFire(true);
		vecBullet[0].Fire(vecTankObj[0]);
	}
	if (vecTankObj[0].getIsFire() && vecBullet[0].IsExist()) {
		vecBullet[0].Move();
	}
}
void CGame::MoveNPC() {
	int NpcDir = 1;
	for (int i = 1; i < 5; i++) {
		NpcDir = rand() % 4;
		if (NpcDir == 0)vecTankObj[i].Move(UP);
		else if (NpcDir == 1)vecTankObj[i].Move(DOWN);
		else if (NpcDir == 2)vecTankObj[i].Move(LEFT);
		else if (NpcDir == 3)vecTankObj[i].Move(RIGHT);

		if (vecBullet[i].IsExist() == false) {
			vecTankObj[i].setIsFire(true);
			vecBullet[i].Fire(vecTankObj[i]);
		}
		if (vecTankObj[i].getIsFire() && vecBullet[i].IsExist()) {
			vecBullet[i].Move();
		}
	}

}
