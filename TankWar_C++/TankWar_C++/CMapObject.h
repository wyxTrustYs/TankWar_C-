#pragma once
#include <windows.h>
class CMapObject
{
public:
	CMapObject();
	~CMapObject();
	//设置地图中标制定为值数据
	bool setMapValue(int PosX, int PosY, int nValue);
	int getMapValue(int PosX, int PosY);
	bool DrawMap();
private:
	int ArrMap[40][40] = {};
};
