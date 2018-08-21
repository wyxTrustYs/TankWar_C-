#include "CMap.h"
#include "Value.h"
#include <windows.h>
#include <cstdio>
int CMap::ArrMap[30][60] = { 0 };

void CMap::InitMap() {
	FullScreen();
	ShowCursor(false);
	for (int m = 0; m < 30; m++) {
		for (int n = 0; n < 60; n++) {
			if (m == 0 || n == 0 || m == 29 || n == 59) {
				ArrMap[m][n] = Wall;
				PrintChar(n, m, "¨€");
			}
			else ArrMap[m][n] = Ground;
		}
	}
}

void CMap::setValue(int x, int y, int type) {
	ArrMap[y][x] = type;
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

void CMap::PrintChar(int Wide, int High, char *Str) {
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	COORD loc;
	loc.X = Wide * 2;
	loc.Y = High;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
	puts(Str);
}

void CMap::setMapValue(int x, int y, int value) {
	ArrMap[y][x] = value;
}

int CMap::getMapValue(int x, int y) {
	return ArrMap[y][x];
}
