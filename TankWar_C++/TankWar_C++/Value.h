#pragma once
enum Dir { UP, DOWN, LEFT, RIGHT };
enum MapValue
{
	Ground, MyTank_1, MyTank_2, EnemyTank_1, EnemyTank_2, EnemyTank_3, EnemyTank_4,
	Wall, IronWall, Forest, River, IceGround,
	MyTankBullet, EnemyBullet,
	Home
};