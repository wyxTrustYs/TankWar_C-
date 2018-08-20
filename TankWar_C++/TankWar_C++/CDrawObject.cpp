#include "CDrawObject.h"
#include "Value.h"
#include <iostream>
using namespace std;

//Ground, Wall, IronWall, Forest, River, IceGround,
//MyTank_1, MyTank_2, EnemyTank_1, EnemyTank_2, EnemyTank_3, EnemyTank_4,
//MyTankBullet, EnemyBullet

bool CDrawObject::DrawPatterning(int PosX, int PosY, int Type) {
	switch (Type)
	{
	case Ground:
		WriteChar(PosX, PosY, "  ", 0);
		break;
	case Wall:
		WriteChar(PosX, PosY, "0", 124);
		break;
	case IronWall:
		WriteChar(PosX, PosY, "¨€", 0);
		break;
	case Home:
		WriteChar(PosX, PosY, "*", 0);
		break;
	case Forest:
//		WriteChar(PosX, PosY, "¨€", 0);
		break;
	case River:
//		WriteChar(PosX, PosY, "¨€", 0);
		break;
	case IceGround:
//		WriteChar(PosX, PosY, "¨€", 0);
		break;
	case MyTank_1:
//		WriteChar(PosX, PosY, "¨€", 0);
		break;
	case MyTank_2:
//		WriteChar(PosX, PosY, "¨€", 0);
		break;
	case EnemyTank_1:
//		WriteChar(PosX, PosY, "¨€", 0);
		break;
	case EnemyTank_2:
//		WriteChar(PosX, PosY, "¨€", 0);
		break;
	case EnemyTank_3:
//		WriteChar(PosX, PosY, "¨€", 0);
		break;
	case EnemyTank_4:
//		WriteChar(PosX, PosY, "¨€", 0);
		break;
	case MyTankBullet:case EnemyBullet:
//		WriteChar(PosX, PosY, "¨€", 0);
		break;
	default:
		break;
	}
}
void CDrawObject::WriteChar(int Wide, int High, char* pszChar, WORD wArr) {
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	COORD loc;
	loc.X = Wide * 2;
	loc.Y = High;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wArr);
	puts(pszChar);
}