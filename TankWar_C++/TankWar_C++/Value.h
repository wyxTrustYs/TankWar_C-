#pragma once
enum Dir { UP, DOWN, LEFT, RIGHT };
enum MapValue
{
	Ground, Forest, IceGround,
	MyTank_1, MyTank_2, EnemyTank_1, EnemyTank_2, EnemyTank_3, EnemyTank_4,
	River,
	MyTank_1Bullet, MyTank_2Bullet, EnemyTank_1Bullet, EnemyTank_2Bullet, EnemyTank_3Bullet, EnemyTank_4Bullet,
	Home,Wall, IronWall, BorderWall
};