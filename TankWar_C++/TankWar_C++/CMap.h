#pragma once
#include <windows.h>
class CMap
{
public:
	void InitMap();
	void ShowCursor(bool isShow);
	void FullScreen();
	void PrintChar(int Wide, int High, char *Str);
	void InitHome();
	void MapDIY();
	void MouseEventProc(MOUSE_EVENT_RECORD mer);
	void OutputPos(int nX, int nY, int flat);
	void MapToFile(char name[]);
	void FileToMap(char name[]);
	void NewMap();
	void LoadMap();
	void EditMap();

	void setMapValue(int x, int y, int value);
	int getMapValue(int x, int y);
private:
	static int ArrMap[30][60];
};