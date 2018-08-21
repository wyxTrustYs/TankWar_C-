#include <iostream>
#include "CMap.h"
#include "CTank.h"
#include "Value.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main(){

	CMap map;
	map.InitMap();
	CTank tank;
	tank.InitTank(MyTank_1);
	while (true)
	{
		if (GetKeyState('W') < 0)tank.Move(UP);
		if (GetKeyState('S') < 0)tank.Move(DOWN);
		if (GetKeyState('A') < 0)tank.Move(LEFT);
		if (GetKeyState('D') < 0)tank.Move(RIGHT);
		Sleep(100);
	}
	return 0;
}