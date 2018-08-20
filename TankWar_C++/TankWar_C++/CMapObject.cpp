#include "CMapObject.h"
#include "CDrawObject.h"
#include "Value.h"

#include <iostream>
using namespace std;

bool CMapObject::setMapValue(int PosX, int PosY, int nValue) {
	ArrMap[PosY][PosX] = nValue;
}
int CMapObject::getMapValue(int PosX, int PosY) {
	return ArrMap[PosY][PosX];
}
bool CMapObject::DrawMap() {
	CDrawObject drawObject;
	for (int m = 0; m < 40; m++) {
		for (int n = 0; n < 40; n++) {
			switch (ArrMap[m][n])
			{
			case Ground:
				drawObject.DrawPatterning(n, m, ArrMap[m][n]);
				break;
			case Wall:
				drawObject.DrawPatterning(n, m, ArrMap[m][n]);
				break;
			case IronWall:
				drawObject.DrawPatterning(n, m, ArrMap[m][n]);
				break;
			case Forest:
				drawObject.DrawPatterning(n, m, ArrMap[m][n]);
				break;
			case River:
				drawObject.DrawPatterning(n, m, ArrMap[m][n]);
				break;
			case IceGround:
				drawObject.DrawPatterning(n, m, ArrMap[m][n]);
				break;
			default:
				break;
			}
		}
	}
}