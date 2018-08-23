#include "CMap.h"
#include "Value.h"

#include <cstdio>

int CMap::ArrMap[30][60] = { 0 };

void CMap::InitMap() {
	FullScreen();
	ShowCursor(false);
	for (int m = 0; m < 30; m++) {
		for (int n = 0; n < 60; n++) {
			if (m == 0 || n == 0 || m == 29 || n == 59) {
				ArrMap[m][n] = IronWall;
				PrintChar(n, m, "█");
			}
			else ArrMap[m][n] = Ground;
		}
	}
}


void CMap::ShowCursor(bool isShow) {
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = isShow;
	SetConsoleCursorInfo(hOutStd, &cci);
}

void CMap::FullScreen() {
	HWND hwnd = GetForegroundWindow();
	int x = GetSystemMetrics(SM_CXSCREEN) + 300;
	int y = GetSystemMetrics(SM_CYSCREEN) + 300;
	char setting[30];
	sprintf(setting, "mode con:cols=%d lines=%d", x, y);
	system(setting);
}

void CMap::PrintChar(int Wide, int High, char *Str,int color) {
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	COORD loc;
	loc.X = Wide * 2;
	loc.Y = High;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	puts(Str);
}

void CMap::InitHome() {
	for (int i = 26; i <= 28; i++) {
		for (int j = 25; j < 28; j++) {
			ArrMap[i][j] = Home;
			PrintChar(j, i, "#");
		}
	}
}

void CMap::MapDIY() {
	PrintChar(66, 13, "1、清除地图");
	PrintChar(66, 14, "2、保存地图");
	PrintChar(66, 15, "3、砖墙");
	PrintChar(66, 16, "4、铁墙");
	PrintChar(66, 17, "5、河流");
	PrintChar(66, 18, "6、森林");
	PrintChar(66, 19, "7、雪地");
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD stcRecode = { 0 };
	DWORD dwRead;
	int m_select = 3;
	int maptype = 0;

	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	while (1) {
		ReadConsoleInput(hStdin, &stcRecode, 1, &dwRead);
		if (stcRecode.EventType == KEY_EVENT) {
			m_select = stcRecode.Event.KeyEvent.uChar.AsciiChar;
			switch (m_select)
			{
			case '1':
				system("cls");
				InitMap();
				InitHome();
				PrintChar(66, 13, "1、清除地图");
				PrintChar(66, 14, "2、保存地图");
				PrintChar(66, 15, "3、砖墙");
				PrintChar(66, 16, "4、铁墙");
				PrintChar(66, 17, "5、河流");
				PrintChar(66, 18, "6、森林");
				PrintChar(66, 19, "7、雪地");
				SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
				break;
			case '2':
				return;
			case '3':
				maptype = Wall;
				break;
			case '4':
				maptype = IronWall;
				break;
			case '5':
				maptype = River;
				break;
			case '6':
				maptype = Forest;
				break;
			case '7':
				maptype = IceGround;
				break;
			default:
				break;
			}
		}
		if (stcRecode.EventType == MOUSE_EVENT) {
			MouseEventProc(stcRecode.Event.MouseEvent,maptype);
		}
	}
}

void CMap::MouseEventProc(MOUSE_EVENT_RECORD mer,int MapType) {

	if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
		if (mer.dwEventFlags == MOUSE_MOVED) {
			switch (MapType)
			{
			case Wall:
				OutputPos(mer.dwMousePosition.X, mer.dwMousePosition.Y, Wall);
				PrintChar(mer.dwMousePosition.X / 2, mer.dwMousePosition.Y, "卐", 12);
				break;
			case IronWall:
				OutputPos(mer.dwMousePosition.X, mer.dwMousePosition.Y, IronWall);
				PrintChar(mer.dwMousePosition.X / 2, mer.dwMousePosition.Y, "█");
				break;
			case River:
				OutputPos(mer.dwMousePosition.X, mer.dwMousePosition.Y, River);
				PrintChar(mer.dwMousePosition.X / 2, mer.dwMousePosition.Y, "≈", 1);
				break;
			case Forest:
				OutputPos(mer.dwMousePosition.X, mer.dwMousePosition.Y, Forest);
				PrintChar(mer.dwMousePosition.X / 2, mer.dwMousePosition.Y, "※", 2);
				break;
			case IceGround:
				OutputPos(mer.dwMousePosition.X, mer.dwMousePosition.Y, IceGround);
				PrintChar(mer.dwMousePosition.X / 2, mer.dwMousePosition.Y, "▓", 15);
				break;
			default:
				break;
			}
			
		}
	}
	else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {
		if (mer.dwEventFlags == MOUSE_MOVED) {
			OutputPos(mer.dwMousePosition.X, mer.dwMousePosition.Y, 0);
			PrintChar(mer.dwMousePosition.X / 2, mer.dwMousePosition.Y, " ");
		}
	}

}

void CMap::MapToFile(char name[]) {
	FILE *file = NULL;
	char FilePath[20] = "./map/";
	strcat(FilePath, name);
	strcat(FilePath, ".map");
	if ((file = fopen(FilePath, "wb")) == NULL) {
		printf("open map fail\n");
		exit(0);
	}
	fwrite(ArrMap, sizeof(ArrMap), 1, file);
	fclose(file);

}
//从map文件夹中读取.map文件类型的地图 
void CMap::FileToMap(char name[]) {
	FILE *file = NULL;
	char FilePath[20] = "./map/";

	strcat(FilePath, name);
	strcat(FilePath, ".map");
	if ((file = fopen(FilePath, "rb")) == NULL) {
		printf("open map file fail\n");
		exit(0);
	}
	fread(ArrMap, sizeof(ArrMap), 1, file);
	fclose(file);
}

void CMap::NewMap() {
	FullScreen();
	InitMap();
	InitHome();
	MapDIY();
}

void CMap::LoadMap() {
	system("cls");
	FullScreen();
	for (int m = 0; m < 30; m++) {
		for (int n = 0; n < 60; n++) {
			if (ArrMap[m][n] == IronWall) PrintChar(n, m, "█");
			else if (ArrMap[m][n] == Home) PrintChar(n, m, "*",6);
			else if (ArrMap[m][n] == Wall) PrintChar(n, m, "卐",12);
			else if (ArrMap[m][n] == Forest)PrintChar(n, m, "※",2);
			else if (ArrMap[m][n] == River)PrintChar(n, m, "≈", 1);
			else if (ArrMap[m][n] == IceGround)PrintChar(n, m, "▓", 15);
		}
	}

}

void CMap::EditMap() {
	system("cls");
	FullScreen();
	for (int m = 0; m < 30; m++) {
		for (int n = 0; n < 60; n++) {
			if (ArrMap[m][n] == IronWall) PrintChar(n, m, "█");
			else if (ArrMap[m][n] == Home) PrintChar(n, m, "*", 6);
			else if (ArrMap[m][n] == Wall) PrintChar(n, m, "卐", 12);
			else if (ArrMap[m][n] == Forest)PrintChar(n, m, "※", 2);
			else if (ArrMap[m][n] == River)PrintChar(n, m, "≈", 1);
			else if (ArrMap[m][n] == IceGround)PrintChar(n, m, "▓", 15);
		}
	}
	MapDIY();
}

void CMap::ClsMap(int x,int y, int Type) {
	setMapValue(x, y, Type);
	PrintChar(x, y, "  ",0);
}

void CMap::OutputPos(int nX, int nY, int flat) {
	ArrMap[nY][nX / 2] = flat;
}

void CMap::setMapValue(int x, int y, int value) {
	ArrMap[y][x] = value;
}

int CMap::getMapValue(int x, int y) {
	return ArrMap[y][x];
}
