#include "CMap.h"
#include "CTank.h"
#include "Value.h"
#include "CGame.h"
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

int main(){
	srand((unsigned)time(NULL));
	CMap map;
	map.InitMap();
	CGame game;
	game.InitTankInfo();
	while (true)
	{
		game.MoveSelfAndAlly();
		game.MoveNPC();
		Sleep(100);
	}
	return 0;
}