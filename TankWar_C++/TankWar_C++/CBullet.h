#pragma once
#include "CMap.h"
#include "CTank.h"
class CBullet
{

public:
	void Move();		//�ӵ��ƶ�����
	void InitBullet(CTank tank);	//�ӵ���ʼ��
	void DrawBullet();				//���ӵ�
	void ClsBullet();				//�����ӵ�
	int Collsion(int ForwardDir);		//�жϱ߽�
	void Fire(CTank tank);					//����

	//��ȡ�ӵ��ĸ�������
	bool IsExist();
	int getPosX();					
	int getPosY();							
	int getType();					
	int getAlliance();				
	int getPreType();
	
private:
	bool Exist;
	int PosX;
	int PosY;
	int dir;
	int Type;
	int Alliance;
	int PreType;
	int Speed;
	CMap map;
};

