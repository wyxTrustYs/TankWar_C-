#include "CGame.h"
#include "Value.h"
#include <windows.h>
#include <time.h>
#include <iostream>
#pragma comment(lib,"winmm.lib")
using namespace std;

void CGame::Welcome() {
	int option;
	char name[10] = "init";
	int num;
	int level = 1;
	MapObj.FullScreen();
	
	while (true) {
		system("cls");
		MapObj.PrintChar(35, 5, "坦克大战游戏");
		MapObj.PrintChar(10, 10, "1、单人游戏");
		MapObj.PrintChar(20, 10, "2、双人游戏");

		MapObj.PrintChar(30, 10, "3、编辑地图");
		MapObj.PrintChar(40, 10, "4、载入地图");
		MapObj.PrintChar(50, 10, "5、读取存档\n");
		cin >> option;
		switch (option) {
		case 1:
			while (true)
			{
				system("cls");
				switch (level)
				{
				case 1:
					MapObj.PrintChar(30, 10, "第一关");
					Sleep(2000);
					system("cls");
					vecTankObj.clear();
					vecBullet.clear();
					MapObj.FileToMap(name);//开始游戏默认加载地图存放在init.map文件中
					MapObj.LoadMap();
					break;
				case 2:
					MapObj.PrintChar(30, 10, "第二关");
					strcpy(name, "level2");
					Sleep(2000);
					system("cls");
					vecTankObj.clear();
					vecBullet.clear();
					MapObj.FileToMap("level2");//开始游戏默认加载地图存放在init.map文件中
					MapObj.LoadMap();
					break;
				case 3:
					MapObj.PrintChar(30, 10, "第三关");
					strcpy(name, "level3");
					Sleep(2000);
					system("cls");
					vecTankObj.clear();
					vecBullet.clear();
					MapObj.FileToMap(name);//开始游戏默认加载地图存放在init.map文件中
					MapObj.LoadMap();
					break;
				default:
					level = 0;
					strcpy(name, "init");
					MapObj.PrintChar(30, 10, "第一关");
					
					Sleep(2000);
					system("cls");
					vecTankObj.clear();
					vecBullet.clear();
					MapObj.FileToMap("init");//开始游戏默认加载地图存放在init.map文件中
					MapObj.LoadMap();
					break;
				}
				InitTankInfo();
				StartGame(level, 1,name);
				level++;
			}
			break;
		case 2:
			while (true)
			{
				system("cls");
				switch (level)
				{
				case 1:
					MapObj.PrintChar(30, 10, "第一关");
					Sleep(2000);
					system("cls");
					vecTankObj.clear();
					vecBullet.clear();
					MapObj.FileToMap("init");//开始游戏默认加载地图存放在init.map文件中
					MapObj.LoadMap();
					break;
				case 2:
					MapObj.PrintChar(30, 10, "第二关");
					Sleep(2000);
					system("cls");
					vecTankObj.clear();
					vecBullet.clear();
					MapObj.FileToMap("level2");//开始游戏默认加载地图存放在init.map文件中
					MapObj.LoadMap();
					break;
				case 3:
					MapObj.PrintChar(30, 10, "第三关");
					Sleep(2000);
					system("cls");
					vecTankObj.clear();
					vecBullet.clear();
					MapObj.FileToMap("level3");//开始游戏默认加载地图存放在init.map文件中
					MapObj.LoadMap();
					break;
				default:
					level = 0;
					MapObj.PrintChar(30, 10, "第一关");
					Sleep(2000);
					system("cls");
					vecTankObj.clear();
					vecBullet.clear();
					MapObj.FileToMap("init");//开始游戏默认加载地图存放在init.map文件中
					MapObj.LoadMap();
					break;
				}
				InitTankInfo();
				StartGame(level, 2,name);
				level++;
			}
			break;

		case 3: {
			system("cls");
			MapObj.PrintChar(20, 10, "1、修改地图");
			MapObj.PrintChar(28, 10, "2、新建地图\n");
			scanf("%d", &num);
			switch (num) {
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
		case 4: {
			int loadoption;
			system("cls");
			system("dir .\\map");
			cout << "请选择你要打开的地图" << endl;
			cin >> name;
			system("cls");
			MapObj.PrintChar(10, 10, "1、单人游戏");
			MapObj.PrintChar(20, 10, "2、双人游戏");
			cin >> loadoption;
			switch (loadoption)
			{
			case 1:
				while (true)
				{
					system("cls");
					switch (level)
					{
					case 1:
						MapObj.PrintChar(30, 10, "第一关");
						Sleep(2000);
						system("cls");
						vecTankObj.clear();
						vecBullet.clear();
						MapObj.FileToMap(name);//开始游戏默认加载地图存放在init.map文件中
						MapObj.LoadMap();
						break;
					case 2:
						MapObj.PrintChar(30, 10, "第二关");
						strcpy(name, "level2");
						Sleep(2000);
						system("cls");
						vecTankObj.clear();
						vecBullet.clear();
						MapObj.FileToMap(name);//开始游戏默认加载地图存放在init.map文件中
						MapObj.LoadMap();
						break;
					case 3:
						MapObj.PrintChar(30, 10, "第三关");
						strcpy(name, "level3");
						Sleep(2000);
						system("cls");
						vecTankObj.clear();
						vecBullet.clear();
						MapObj.FileToMap(name);//开始游戏默认加载地图存放在init.map文件中
						MapObj.LoadMap();
						break;
					default:
						level = 0;
						MapObj.PrintChar(30, 10, "第一关");
						strcpy(name, "init");
						Sleep(2000);
						system("cls");
						vecTankObj.clear();
						vecBullet.clear();
						MapObj.FileToMap(name);//开始游戏默认加载地图存放在init.map文件中
						MapObj.LoadMap();
						break;
					}
					InitTankInfo();
					StartGame(level, 1,name);
					level++;
				}
				break;
			case 2:
				while (true)
				{
					system("cls");
					switch (level)
					{
					case 1:
						MapObj.PrintChar(30, 10, "第一关");
						strcpy(name, "init");
						Sleep(2000);
						system("cls");
						vecTankObj.clear();
						vecBullet.clear();
						MapObj.FileToMap(name);//开始游戏默认加载地图存放在init.map文件中
						MapObj.LoadMap();
						break;
					case 2:
						MapObj.PrintChar(30, 10, "第二关");
						strcpy(name, "level2");
						Sleep(2000);
						system("cls");
						vecTankObj.clear();
						vecBullet.clear();
						MapObj.FileToMap(name);//开始游戏默认加载地图存放在init.map文件中
						MapObj.LoadMap();
						break;
					case 3:
						MapObj.PrintChar(30, 10, "第三关");
						strcpy(name, "level3");
						Sleep(2000);
						system("cls");
						vecTankObj.clear();
						vecBullet.clear();
						MapObj.FileToMap(name);//开始游戏默认加载地图存放在init.map文件中
						MapObj.LoadMap();
						break;
					default:
						level = 0;
						MapObj.PrintChar(30, 10, "第一关");
						Sleep(2000);
						system("cls");
						vecTankObj.clear();
						vecBullet.clear();
						MapObj.FileToMap("init");//开始游戏默认加载地图存放在init.map文件中
						MapObj.LoadMap();
						break;
					}
					InitTankInfo();
					StartGame(level, 2,name);
					level++;
				}
				break;

			default:
				break;
			}
			MapObj.FileToMap(name);
			MapObj.LoadMap();

			InitTankInfo();
			StartGame(1, 1,name);
			break;
		}
		case 5:
		{
			int flat = 0;
			char *tmpname = NULL;
			char number;
			char level;
			system("cls");
			system("dir .\\data");
			cin >> name;

			tmpname = Reading(name);
			flat = 1;
			level = tmpname[strlen(tmpname) - 1];
			tmpname[strlen(tmpname) - 1] = '\0';
			number = tmpname[strlen(tmpname) - 1];
			tmpname[strlen(tmpname) - 1] = '\0';
			//tmpname[strlen(tmpname) - 1] = '\0';
			memset(name, 0, 10 * sizeof(char));
			strcpy(name, tmpname);

			system("cls");

			//			SetSnake(snake);
			switch (number)
			{
			case 1:
				while (true)
				{
					system("cls");
					switch (level)
					{
					case 1:
						if (flat == 0) {
							vecBullet.clear();
							vecTankObj.clear();
						}
						MapObj.PrintChar(30, 10, "第一关");
						Sleep(2000);
						system("cls");
						MapObj.FileToMap(name);
						MapObj.LoadMap();
						flat = 0;
						break;
					case 2:
						if (flat == 0) {
							vecBullet.clear();
							vecTankObj.clear();
						}
						MapObj.PrintChar(30, 10, "第二关");
						Sleep(2000);
						system("cls");

						MapObj.FileToMap(name);
						MapObj.LoadMap();
						flat = 0;
						break;
					case 3:
						if (flat == 0) {
							vecBullet.clear();
							vecTankObj.clear();
						}
						MapObj.PrintChar(30, 10, "第三关");
						Sleep(2000);
						system("cls");

						MapObj.FileToMap(name);
						MapObj.LoadMap();
						flat = 0;
						break;
					default:
						if (flat == 0) {
							vecBullet.clear();
							vecTankObj.clear();
						}
						level = 0;
						MapObj.PrintChar(30, 10, "第一关");
						Sleep(2000);
						system("cls");

						MapObj.FileToMap("init");//开始游戏默认加载地图存放在init.map文件中
						MapObj.LoadMap();
						flat = 0;
						break;
					}
					//					InitTankInfo();
					StartGame(level, 1,name);
					level++;
				}
				break;
			case 2:
				while (true)
				{
					system("cls");
					switch (level)
					{
					case 1:
						MapObj.PrintChar(30, 10, "第一关");
						Sleep(2000);
						system("cls");

						MapObj.FileToMap(name);
						MapObj.LoadMap();
						break;
					case 2:
						MapObj.PrintChar(30, 10, "第二关");
						Sleep(2000);
						system("cls");

						MapObj.FileToMap(name);
						MapObj.LoadMap();
						break;
					case 3:
						MapObj.PrintChar(30, 10, "第三关");
						Sleep(2000);
						system("cls");

						MapObj.FileToMap(name);
						MapObj.LoadMap();
						break;
					default:
						level = 0;
						MapObj.PrintChar(30, 10, "第一关");
						Sleep(2000);
						system("cls");

						MapObj.FileToMap("init");//开始游戏默认加载地图存放在init.map文件中
						MapObj.LoadMap();
						break;
					}
					//					InitTankInfo();
					StartGame(level, 2,name);
					level++;
				}
				break;
			default:
				break;
			}
			break;
		}
		default:
			return;
		}

	}
}
void CGame::InitTankInfo() {
	CTank TmpTank[6];
	CBullet TmpBullet[6];
	TmpTank[0].InitTank(MyTank_1);
	TmpBullet[0].InitBullet(TmpTank[0]);
	vecTankObj.push_back(TmpTank[0]);
	vecBullet.push_back(TmpBullet[0]);

	TmpTank[1].InitTank(MyTank_2);
	TmpBullet[1].InitBullet(TmpTank[1]);
	vecTankObj.push_back(TmpTank[1]);
	vecBullet.push_back(TmpBullet[1]);

	TmpTank[2].InitTank(EnemyTank_1);
	TmpBullet[2].InitBullet(TmpTank[2]);
	vecTankObj.push_back(TmpTank[2]);
	vecBullet.push_back(TmpBullet[2]);

	TmpTank[3].InitTank(EnemyTank_2);
	TmpBullet[3].InitBullet(TmpTank[3]);
	vecTankObj.push_back(TmpTank[3]);
	vecBullet.push_back(TmpBullet[3]);

	TmpTank[4].InitTank(EnemyTank_3);
	TmpBullet[4].InitBullet(TmpTank[4]);
	vecTankObj.push_back(TmpTank[4]);
	vecBullet.push_back(TmpBullet[4]);

	TmpTank[5].InitTank(EnemyTank_4);
	TmpBullet[5].InitBullet(TmpTank[5]);
	vecTankObj.push_back(TmpTank[5]);
	vecBullet.push_back(TmpBullet[5]);
}
void CGame::StartGame(int level, int num,char name[]) {
	vector<clock_t> tank_start(6, clock());
	vector<clock_t> bullet_start(6, clock());
	//	int preScore = vecTankObj[0].getScore();
	// 	MapObj.PrintChar(30, 10, "第一关");
	// 	Sleep(2000);
	// 	system("cls");
	PlaySoundA("BattleCity.wav", NULL, SND_ASYNC | SND_NODEFAULT );
	if (num == 1) {
		vecTankObj[0].DrawTank();
		vecTankObj[2].DrawTank();
		vecTankObj[3].DrawTank();
		vecTankObj[4].DrawTank();
		vecTankObj[5].DrawTank();

		while (true) {
			//void CGame::Save(char name[], vector<CTank> &vectank, vector<CBullet> vecbullet,
			//char mapname[], char num, char level)
			if (GetKeyState('P') < 0) {
				MapObj.PrintChar(30, 10, "      正在存档.......      ");
				SaveData("BattleCity", vecTankObj, vecBullet, name, num, level);
				Sleep(2000);
			}
			if (clock() - tank_start[0] > vecTankObj[0].Speed) {
				MoveSelf();
				tank_start[0] = clock();
			}
			for (int i = 2; i <= 5; i++) {
				if (clock() - tank_start[i] > vecTankObj[i].Speed) {
					MoveNPC(i);
					tank_start[i] = clock();
				}
				if (clock() - bullet_start[i] > vecBullet[i].Speed) {
					if (vecTankObj[i].getIsFire() && vecBullet[i].IsExist()) {
						//     	if (clock() - bullet_start[i] > vecBullet[i].Speed) {
						//    			vecBullet[i].Move();
						//     		bullet_start[i] = clock();
						//     	}
						int CollsionType = BulletCollsion(vecBullet[i]);
						if (CollsionType >= MyTank_1) {
							if (CollsionType != River)
								break;
						}
						vecBullet[i].Move();
						bullet_start[i] = clock();
						//vecBullet[i].Move();
					}
				}
			}
			if (vecTankObj[0].getScore() >= 50) {
				vecTankObj[0].Score = 0;
				return;
			}
		}

	}
	else if (num == 2) {
		vecTankObj[0].DrawTank();
		vecTankObj[1].DrawTank();
		vecTankObj[2].DrawTank();
		vecTankObj[3].DrawTank();
		vecTankObj[4].DrawTank();
		vecTankObj[5].DrawTank();

		while (true)
		{
			if (GetKeyState('P') < 0) {
				MapObj.PrintChar(30, 10, "      正在存档.......      ");
				SaveData("BattleCityTwo", vecTankObj, vecBullet, name, num, level);
				Sleep(2000);
			}
			if (clock() - tank_start[0] > vecTankObj[0].Speed) {
				MoveSelf();
				tank_start[0] = clock();
			}
			if (clock() - tank_start[1] > vecTankObj[1].Speed) {
				MoveAlly();
				tank_start[1] = clock();
			}
			for (int i = 2; i <= 5; i++) {
				if (clock() - tank_start[i] > vecTankObj[i].Speed) {
					MoveNPC(i);
					tank_start[i] = clock();
				}
				if (clock() - bullet_start[i] > vecBullet[i].Speed) {
					if (vecTankObj[i].getIsFire() && vecBullet[i].IsExist()) {
						int CollsionType = BulletCollsion(vecBullet[i]);
						if (CollsionType >= MyTank_1) {
							if (CollsionType != River)
								break;
						}
						vecBullet[i].Move();
						bullet_start[i] = clock();
						
					}
				}
			}

			if (vecTankObj[0].getScore() + vecTankObj[1].getScore() == 100) {
				vecTankObj[0].Score = 0;
				vecTankObj[1].Score = 0;
				return;
			}
		}

	}
}
void CGame::MoveSelf() {

	sprintf(Score, "%d", vecTankObj[0].getScore());
	MapObj.PrintChar(63, 15, "Tank1的得分为：");
	MapObj.PrintChar(66, 16, Score);

	if (vecTankObj[0].IsDead == false) {
		if (vecTankObj[0].PreType[2][0] == IceGround &&
			vecTankObj[0].PreType[2][1] == IceGround &&
			vecTankObj[0].PreType[2][2] == IceGround) {
			if (vecTankObj[0].Collsion(vecTankObj[0].DirInIce) == 1) {
				vecTankObj[0].DirInIce = rand() % 4;
			}
			else {
				vecTankObj[0].Move(vecTankObj[0].DirInIce);
			}
		}
		else {
			if (GetKeyState('W') < 0) { vecTankObj[0].DirInIce = UP; vecTankObj[0].Move(UP); }
			else if (GetKeyState('S') < 0) { vecTankObj[0].DirInIce = DOWN; vecTankObj[0].Move(DOWN); }
			else if (GetKeyState('A') < 0) { vecTankObj[0].DirInIce = LEFT; vecTankObj[0].Move(LEFT); }
			else if (GetKeyState('D') < 0) { vecTankObj[0].DirInIce = RIGHT; vecTankObj[0].Move(RIGHT); }
		}

		if ((GetKeyState(VK_SPACE) < 0) && vecBullet[0].IsExist() == false) {
			PlaySoundA("bang.wav", NULL, SND_ASYNC | SND_NODEFAULT );
			vecTankObj[0].setIsFire(true);
			vecBullet[0].Fire(vecTankObj[0]);
		}

	}
	else if (vecTankObj[0].IsDead == true) {
		vecTankObj[0].InitTank(vecTankObj[0].getType());
		vecTankObj[0].DrawTank();
	}
	if (vecTankObj[0].getIsFire() && vecBullet[0].IsExist()) {
		int CollsionType = BulletCollsion(vecBullet[0]);
		if (CollsionType >= MyTank_1) {
			if (CollsionType != River)
			{
				PlaySoundA("Gunfire.wav", NULL, SND_ASYNC | SND_NODEFAULT);
				return;
			}
		}
		vecBullet[0].Move();
	}
}

void CGame::MoveAlly() {

	sprintf(Score, "%d", vecTankObj[1].getScore());
	MapObj.PrintChar(63, 17, "Tank2的得分为：");
	MapObj.PrintChar(66, 18, Score);

	if (vecTankObj[1].IsDead == false) {
		if (vecTankObj[1].PreType[2][0] == IceGround &&
			vecTankObj[1].PreType[2][1] == IceGround &&
			vecTankObj[1].PreType[2][2] == IceGround) {
			if (vecTankObj[1].Collsion(vecTankObj[1].DirInIce) == 1) {
				vecTankObj[1].DirInIce = rand() % 4;
			}
			else {
				vecTankObj[1].Move(vecTankObj[1].DirInIce);
			}
		}
		else {
			if (GetKeyState(VK_UP) < 0) { vecTankObj[1].DirInIce = UP; vecTankObj[1].Move(UP); }
			else if (GetKeyState(VK_DOWN) < 0) { vecTankObj[1].DirInIce = DOWN; vecTankObj[1].Move(DOWN); }
			else if (GetKeyState(VK_LEFT) < 0) { vecTankObj[1].DirInIce = LEFT; vecTankObj[1].Move(LEFT); }
			else if (GetKeyState(VK_RIGHT) < 0) { vecTankObj[1].DirInIce = RIGHT; vecTankObj[1].Move(RIGHT); }
		}

		if ((GetKeyState('L') < 0) && vecBullet[1].IsExist() == false) {
			PlaySoundA("bang.wav", NULL, SND_ASYNC | SND_NODEFAULT );
			vecTankObj[1].setIsFire(true);
			vecBullet[1].Fire(vecTankObj[1]);
		}

	}
	else if (vecTankObj[1].IsDead == true) {
		vecTankObj[1].InitTank(vecTankObj[1].getType());
		vecTankObj[1].DrawTank();
	}
	if (vecTankObj[1].getIsFire() && vecBullet[1].IsExist()) {
		int CollsionType = BulletCollsion(vecBullet[1]);
		if (CollsionType >= MyTank_1) {
			if (CollsionType != River)
			{
				PlaySoundA("Gunfire.wav", NULL, SND_ASYNC | SND_NODEFAULT);
				return;
			}
		}
		vecBullet[1].Move();
	}
}

void CGame::MoveNPC(int i) {
	//vector<clock_t> bullet_start(6, clock());
	if (vecTankObj[i].IsDead == false) {
		if (vecTankObj[i].PreType[2][0] == IceGround &&
			vecTankObj[i].PreType[2][1] == IceGround &&
			vecTankObj[i].PreType[2][2] == IceGround) {
			if (vecTankObj[i].Collsion(vecTankObj[i].DirInIce) == 1) {
				vecTankObj[i].DirInIce = rand() % 4;
			}
			else {
				vecTankObj[i].Move(vecTankObj[i].DirInIce);
			}
			//vecTankObj[i].Move(vecTankObj[i].DirInIce);
		}
		else {
			//NpcDir = rand() % 4;
			if (vecTankObj[i].Collsion(vecTankObj[i].dir) == 1) {
				vecTankObj[i].dir = rand() % 4;
			}
			vecTankObj[i].DirInIce = vecTankObj[i].dir;
			if (vecTankObj[i].dir == 0)vecTankObj[i].Move(UP);
			else if (vecTankObj[i].dir == 1)vecTankObj[i].Move(DOWN);
			else if (vecTankObj[i].dir == 2)vecTankObj[i].Move(LEFT);
			else if (vecTankObj[i].dir == 3)vecTankObj[i].Move(RIGHT);
		}
		if (vecBullet[i].IsExist() == false) {
// 			vecTankObj[i].setIsFire(true);
// 			vecBullet[i].Fire(vecTankObj[i]);
		}

	}
	else if (vecTankObj[i].IsDead == true) {
 		vecTankObj[i].InitTank(vecTankObj[i].getType());
 		vecTankObj[i].DrawTank();
	}
// 	if (vecTankObj[i].getIsFire() && vecBullet[i].IsExist()) {
// //     	if (clock() - bullet_start[i] > vecBullet[i].Speed) {
// //    			vecBullet[i].Move();
// //     		bullet_start[i] = clock();
// //     	}
// 		int CollsionType = BulletCollsion(vecBullet[i]);
// 		if (CollsionType >= MyTank_1) {
// 			if (CollsionType != River)
// 				return;
// 		}
// 		//vecBullet[i].Move();
// 	}
}

int CGame::BulletCollsion(CBullet& bullet) {
	int tmpx = 0, tmpy = 0;
	CBullet tmpBullet;
	int tanknum;

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
		if (bullet.Alliance == 2) {
			vecTankObj[0].Blood--;
			if (vecTankObj[0].Blood == 0) {
				vecTankObj[0].IsDead = true;
				vecTankObj[0].ClsObject();
			}
		}
		break;
	case MyTank_2:
		bullet.Exist = false;
		bullet.ClsBullet();
		bullet.PreType = Ground;
		if (bullet.Alliance == 2) {
			vecTankObj[1].Blood--;
			if (vecTankObj[1].Blood == 0) {
				vecTankObj[1].IsDead = true;
				vecTankObj[1].ClsObject();
			}
		}
		break;
	case EnemyTank_1:

		bullet.Exist = false;
		bullet.ClsBullet();
		bullet.PreType = Ground;
		if (bullet.getAlliance() == 1)
			vecTankObj[2].Blood--;
		if (vecTankObj[2].Blood == 0) {
			if (bullet.getType() == MyTank_1Bullet)
				vecTankObj[0].setScore(10);
			else if (bullet.getType() == MyTank_2Bullet)
				vecTankObj[1].setScore(10);
			vecTankObj[2].IsDead = true;
			vecTankObj[2].ClsObject();
		}
		break;
	case EnemyTank_2:

		bullet.Exist = false;
		bullet.ClsBullet();
		bullet.PreType = Ground;
		if (bullet.getAlliance() == 1)
			vecTankObj[3].Blood--;

		if (vecTankObj[3].Blood == 0) {
			if (bullet.getType() == MyTank_1Bullet)
				vecTankObj[0].setScore(20);
			else if (bullet.getType() == MyTank_2Bullet)
				vecTankObj[1].setScore(20);
			vecTankObj[3].IsDead = true;
			vecTankObj[3].ClsObject();
		}
		break;
	case EnemyTank_3:

		bullet.Exist = false;
		bullet.ClsBullet();
		bullet.PreType = Ground;
		if (bullet.getAlliance() == 1)
			vecTankObj[4].Blood--;
		if (vecTankObj[4].Blood == 0) {
			if (bullet.getType() == MyTank_1Bullet)
				vecTankObj[0].setScore(30);
			else if (bullet.getType() == MyTank_2Bullet)
				vecTankObj[1].setScore(30);
			vecTankObj[4].IsDead = true;
			vecTankObj[4].ClsObject();
		}
		break;
	case EnemyTank_4:

		bullet.Exist = false;
		bullet.ClsBullet();
		bullet.PreType = Ground;
		if (bullet.getAlliance() == 1)
			vecTankObj[5].Blood--;
		if (vecTankObj[5].Blood == 0) {
			if (bullet.getType() == MyTank_1Bullet)
				vecTankObj[0].setScore(40);
			else if (bullet.getType() == MyTank_2Bullet)
				vecTankObj[1].setScore(40);
			vecTankObj[5].IsDead = true;
			vecTankObj[5].ClsObject();
		}
		break;
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
	case MyTank_1Bullet:
		vecBullet[0].Exist = false;
		bullet.Exist = false;
		bullet.ClsBullet();
		vecBullet[0].ClsBullet();
		break;
	case MyTank_2Bullet:
		bullet.Exist = false;
		bullet.ClsBullet();
		vecBullet[1].Exist = false;
		vecBullet[1].ClsBullet();
		break;
	case EnemyTank_1Bullet:
		bullet.Exist = false;
		bullet.ClsBullet();
		vecBullet[2].Exist = false;
		vecBullet[2].ClsBullet();
		break;
	case EnemyTank_2Bullet:
		bullet.Exist = false;
		bullet.ClsBullet();
		vecBullet[3].Exist = false;
		vecBullet[3].ClsBullet();
		break;
	case EnemyTank_3Bullet:
		bullet.Exist = false;
		bullet.ClsBullet();
		vecBullet[4].Exist = false;
		vecBullet[4].ClsBullet();
		break;
	case EnemyTank_4Bullet:
		bullet.Exist = false;
		bullet.ClsBullet();
		vecBullet[5].Exist = false;
		vecBullet[5].ClsBullet();
		break;
	default:
		break;

	}
	return MapType;
}

int CGame::BulletToTank(CBullet bullet) {
	switch (bullet.getType())
	{
	case MyTank_1Bullet:
		return 0;
	case MyTank_2Bullet:
		return 1;
	case EnemyTank_1Bullet:
		return 2;
	case EnemyTank_2Bullet:
		return 3;
	case EnemyTank_3Bullet:
		return 4;
	case EnemyTank_4Bullet:
		return 5;
	default:
		break;
	}

}

void CGame::SaveData(char name[], vector<CTank> &vectank, vector<CBullet> vecbullet,
	char mapname[], char num, char level) {
	FILE *file = NULL;
	char TankFilePath[30] = "./data/";
	char OtherFilePath[30] = "./data/";
	char BulletFilePath[30] = "./data/";
	strcat(TankFilePath, name);
	strcat(TankFilePath, ".tank");
	strcat(BulletFilePath, name);
	strcat(BulletFilePath, ".bullet");
	strcat(OtherFilePath, name);
	strcat(OtherFilePath, ".other");
	if ((file = fopen(TankFilePath, "wb+")) == NULL) {
		cout << "open file fail" << endl;
		exit(0);
	}
	// fwrite(&snake, sizeof(Snake), 1, file);
	int Tanksize = vectank.size();
	fwrite(&vectank[0], sizeof(CTank), Tanksize, file);
	fclose(file);

	if ((file = fopen(BulletFilePath, "wb+")) == NULL) {
		cout << "open file fail" << endl;
		exit(0);
	}
	// fwrite(&snake, sizeof(Snake), 1, file);
	int Bulletsize = vecbullet.size();
	fwrite(&vecbullet[0], sizeof(CBullet), Bulletsize, file);
	fclose(file);

	if ((file = fopen(OtherFilePath, "wb+")) == NULL) {
		cout << "open file fail" << endl;
		exit(0);
	}
	fputs(mapname, file);
	fputc(num, file);
	fputc(level, file);
	fclose(file);
}

char* CGame::Reading(char name[]) {
	FILE *file = NULL;
	char TankFilePath[30] = "./data/";
	char OtherFilePath[30] = "./data/";
	char BulletFilePath[30] = "./data/";
	char dataname[30];

	memset(dataname, 0, 30 * sizeof(char));
	vecBullet.clear();
	vecTankObj.clear();

	strcat(TankFilePath, name);
	strcat(TankFilePath, ".tank");
	strcat(BulletFilePath, name);
	strcat(BulletFilePath, ".bullet");
	strcat(OtherFilePath, name);
	strcat(OtherFilePath, ".other");
	if ((file = fopen(TankFilePath, "rb")) == NULL) {
		cout << "open data file fail" << endl;
		exit(0);
	}
	CTank tmptank;
	CBullet tmpBullet;
	for (int i = 0; i < 6; ++i)
	{
		if (fread(&tmptank, sizeof(CTank), 1, file) == 1)
			vecTankObj.push_back(tmptank);
	}
	fclose(file);

	if ((file = fopen(BulletFilePath, "rb")) == NULL) {
		cout << "open data file fail" << endl;
		exit(0);
	}
	for (int i = 0; i < 6; ++i)
	{
		if (fread(&tmpBullet, sizeof(CBullet), 1, file) == 1)
			vecBullet.push_back(tmpBullet);
	}
	fclose(file);

	if ((file = fopen(OtherFilePath, "rb")) == NULL) {
		cout << "open data file fail" << endl;
		exit(0);
	}
	fgets(dataname, 20, file);

	fclose(file);
	return dataname;
}