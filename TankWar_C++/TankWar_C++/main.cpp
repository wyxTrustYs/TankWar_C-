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
	CGame game;
	game.Welcome();
// 	game.InitTankInfo();
// 	while (true)
// 	{
// 		game.MoveSelfAndAlly();
// 		game.MoveNPC();
// 		Sleep(50);
// 	}
	return 0;
}