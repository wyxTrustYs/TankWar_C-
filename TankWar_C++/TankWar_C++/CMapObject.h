#pragma once
#include <windows.h>
class CMapObject
{
public:
	CMapObject();
	~CMapObject();
	//���õ�ͼ�б��ƶ�Ϊֵ����
	bool setMapValue(int PosX, int PosY, int nValue);
	int getMapValue(int PosX, int PosY);
	bool DrawMap();
private:
	int ArrMap[40][40] = {};
};
