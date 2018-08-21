#pragma once
class CMap
{
public:
	void setValue(int x,int y,int type);
	void InitMap();
	void ShowCursor(bool isShow);
	void FullScreen();
	void PrintChar(int Wide, int High, char *Str);
	void setMapValue(int x, int y, int value);
	int getMapValue(int x, int y);

private:
	static int ArrMap[30][60];
};