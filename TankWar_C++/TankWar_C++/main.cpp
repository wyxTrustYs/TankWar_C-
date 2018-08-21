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
		tank.Move();
		Sleep(200);
	}
	return 0;
}